import os
from random import random

import ray
from PIL import Image
from langsam import langsamutils

# Configure logging for Ray and other components
import logging


logging.basicConfig(level=logging.INFO)


import groundingdino.datasets.transforms as T
import numpy as np
import torch
from groundingdino.models import build_model
from groundingdino.util import box_ops
from groundingdino.util.inference import predict
from groundingdino.util.slconfig import SLConfig
from groundingdino.util.utils import clean_state_dict
from huggingface_hub import hf_hub_download
from segment_anything import sam_model_registry
from segment_anything import SamPredictor

from compat import torch_load

SAM_MODELS = {
    "vit_h": "https://dl.fbaipublicfiles.com/segment_anything/sam_vit_h_4b8939.pth",
    "vit_l": "https://dl.fbaipublicfiles.com/segment_anything/sam_vit_l_0b3195.pth",
    "vit_b": "https://dl.fbaipublicfiles.com/segment_anything/sam_vit_b_01ec64.pth"
}

SAM_CHECKPOINTS = {
    "vit_h": "sam_vit_h_4b8939.pth",
    "vit_l": "sam_vit_l_0b3195.pth",
    "vit_b": "sam_vit_b_01ec64.pth",
}

CACHE_PATH = os.environ.get("TORCH_HOME", os.path.expanduser("~/.cache/torch/hub/checkpoints"))


def env_flag(name, default=False):
    value = os.environ.get(name)
    if value is None:
        return default
    return value.strip().lower() in {"1", "true", "yes", "on"}


def cached_sam_checkpoint(sam_type):
    checkpoint_name = SAM_CHECKPOINTS.get(sam_type)
    if not checkpoint_name:
        return None
    checkpoint_path = os.path.join(CACHE_PATH, checkpoint_name)
    return checkpoint_path if os.path.exists(checkpoint_path) else None


def load_model_hf(repo_id, filename, ckpt_config_filename, device='cpu'):
    local_files_only = env_flag("LANGSAM_HF_LOCAL_FILES_ONLY", True) or env_flag("HF_HUB_OFFLINE", False)
    cache_config_file = hf_hub_download(
        repo_id=repo_id,
        filename=ckpt_config_filename,
        local_files_only=local_files_only,
    )

    args = SLConfig.fromfile(cache_config_file)
    args.device = device
    model = build_model(args)

    cache_file = hf_hub_download(
        repo_id=repo_id,
        filename=filename,
        local_files_only=local_files_only,
    )
    checkpoint = torch_load(cache_file, map_location='cpu')
    log = model.load_state_dict(clean_state_dict(checkpoint['model']), strict=False)
    model.to(device)
    print(f"Model loaded from {cache_file} \n => {log}")
    model.eval()
    return model


def transform_image(image, resize=800) -> torch.Tensor:
    transform = T.Compose([
        T.RandomResize([resize], max_size=1333),
        T.ToTensor(),
        T.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225]),
    ])

    image_transformed, _ = transform(image, None)
    return image_transformed


@ray.remote
class LangSAM():

    def __init__(self, sam_type="vit_h", ckpt_path=None, use_gpu=False, dino_resize=None, skip_sam=None):
        self.sam_type = sam_type
        self.device = "cuda" if use_gpu else "cpu"
        self.dino_resize = int(dino_resize or os.environ.get("LANGSAM_DINO_RESIZE", 800))
        self.skip_sam = env_flag("LANGSAM_SKIP_SAM", False) if skip_sam is None else bool(skip_sam)
        print(
            f"Initializing LangSAM on {self.device}, "
            f"dino_resize={self.dino_resize}, skip_sam={self.skip_sam}",
            flush=True,
        )
        self.build_groundingdino()
        if self.skip_sam:
            self.sam = None
            print("Skipping SAM initialization; only GroundingDINO boxes will be returned.", flush=True)
        else:
            self.build_sam(ckpt_path)

    def build_sam(self, ckpt_path):
        if self.sam_type is None or ckpt_path is None:
            if self.sam_type is None:
                print("No sam type indicated. Using vit_h by default.")
                self.sam_type = "vit_h"
            checkpoint_url = SAM_MODELS[self.sam_type]
            local_checkpoint = cached_sam_checkpoint(self.sam_type)
            try:
                if local_checkpoint:
                    print(f"Loading SAM checkpoint from local cache: {local_checkpoint}")
                    sam = sam_model_registry[self.sam_type](checkpoint=local_checkpoint)
                else:
                    print(f"Loading SAM checkpoint from URL: {checkpoint_url}")
                    sam = sam_model_registry[self.sam_type]()
                    state_dict = torch.hub.load_state_dict_from_url(checkpoint_url)
                    sam.load_state_dict(state_dict, strict=True)
            except Exception as exc:
                raise ValueError(f"Problem loading SAM please make sure you have the right model type: {self.sam_type} \
                    and a working checkpoint: {checkpoint_url}. Recommend deleting the checkpoint and \
                    re-downloading it. Original error: {exc}")
            sam.to(device=self.device)
            self.sam = SamPredictor(sam)
        else:
            try:
                sam = sam_model_registry[self.sam_type](checkpoint=ckpt_path)
            except Exception as exc:
                raise ValueError(f"Problem loading SAM. Your model type: {self.sam_type} \
                should match your checkpoint path: {ckpt_path}. Recommend calling LangSAM \
                using matching model type AND checkpoint path. Original error: {exc}")
            sam.to(device=self.device)
            self.sam = SamPredictor(sam)

    def build_groundingdino(self):
        ckpt_repo_id = "ShilongLiu/GroundingDINO"
        ckpt_filename = "groundingdino_swinb_cogcoor.pth"
        ckpt_config_filename = "GroundingDINO_SwinB.cfg.py"
        self.groundingdino = load_model_hf(
            ckpt_repo_id,
            ckpt_filename,
            ckpt_config_filename,
            device=self.device,
        )

    def predict_dino(self, image_pil, text_prompt, box_threshold, text_threshold):
        print(f"LangSAM DINO start: prompt={text_prompt!r}", flush=True)
        image_trans = transform_image(image_pil, resize=self.dino_resize)
        boxes, logits, phrases = predict(model=self.groundingdino,
                                         image=image_trans,
                                         caption=text_prompt,
                                         box_threshold=box_threshold,
                                         text_threshold=text_threshold,
                                         device=self.device)
        W, H = image_pil.size
        boxes = box_ops.box_cxcywh_to_xyxy(boxes) * torch.Tensor([W, H, W, H])
        print(f"LangSAM DINO done: prompt={text_prompt!r}, boxes={len(boxes)}", flush=True)

        return boxes, logits, phrases

    def predict_sam(self, image_pil, boxes):
        print(f"LangSAM SAM start: boxes={len(boxes)}", flush=True)
        image_array = np.asarray(image_pil)
        self.sam.set_image(image_array)
        transformed_boxes = self.sam.transform.apply_boxes_torch(boxes, image_array.shape[:2])
        masks, _, _ = self.sam.predict_torch(
            point_coords=None,
            point_labels=None,
            boxes=transformed_boxes.to(self.sam.device),
            multimask_output=False,
        )
        print("LangSAM SAM done", flush=True)
        return masks.cpu()

    def predict(self, image_pil, text_prompt, box_threshold=0.3, text_threshold=0.25):
        boxes, logits, phrases = self.predict_dino(image_pil, text_prompt, box_threshold, text_threshold)
        masks = torch.tensor([])
        if len(boxes) > 0 and not self.skip_sam:
            masks = self.predict_sam(image_pil, boxes)
            masks = masks.squeeze(1)
        return masks, boxes, phrases, logits

    def save(self, masks, boxes, phrases, logits, image_pil, gui=False):
        if len(masks) == 0:
            # print(f"No objects of the '{text_prompt}' prompt detected in the image.")
            print(f"No objects of the  prompt detected in the image.")
        else:
            # Convert masks to numpy arrays
            masks_np = [mask.squeeze().cpu().numpy() for mask in masks]

            if gui:
                # Display the original image and masks side by side
                langsamutils.display_image_with_masks(image_pil, masks_np)

                # Display the image with bounding boxes and confidence scores
                langsamutils.display_image_with_boxes(image_pil, boxes, logits, phrases)

            # Save the masks
            for i, mask_np in enumerate(masks_np):
                mask_path = f"image_mask_{i + 1}.png"
                langsamutils.save_mask(mask_np, mask_path)

            # Print the bounding boxes, phrases, and logits
            # langsamutils.print_bounding_boxes(boxes)
            # langsamutils.print_detected_phrases(phrases)
            # langsamutils.print_logits(logits)

            labels = [f"{phrase} {logit:.2f}" for phrase, logit in zip(phrases, logits)]
            image_array = np.asarray(image_pil)
            #fix mask problem

            # if you want to hide masks
            # image = langsamutils.draw_image(image_array, [], boxes, labels)
            # image = langsamutils.draw_image(image_array, masks, boxes, labels)
            # image = Image.fromarray(np.uint8(image)).convert("RGB")
            # image.show()
            # langsamutils.save_image(image, filename=f"image_langsam.png")

if __name__ == "__main__":
    # Initialize Ray, replace with your cluster's address or local setup
    ray.init(num_gpus=1)  # Add arguments as necessary, e.g., address, num_gpus

    # Variable to control GPU usage
    use_gpu = torch.cuda.is_available()

    # Options dictionary for dynamic resource allocation
    actor_options = {"num_gpus": 1} if use_gpu else {}

    # Create an actor instance
    langsam_actor = LangSAM.options(**actor_options).remote(use_gpu=use_gpu)

    # image = "https://static01.nyt.com/images/2020/09/08/well/physed-cycle-walk/physed-cycle-walk-videoSixteenByNineJumbo1600-v2.jpg"

    image =""
    text_prompt = ""    # text_prompt = obj[6]
    image_pil = langsamutils.load_image(image)

    # Predict masks and scores
    masks, boxes, phrases, logits = ray.get(langsam_actor.predict.remote(image_pil, text_prompt))
    print( masks, boxes, phrases, logits)
    ray.get(langsam_actor.save.remote(masks, boxes, phrases, logits,image_pil))
    # print("Scores:", scores)
    # Add your logic here to work with masks and scores

    ray.shutdown()
