import json
import os
from pathlib import Path

import numpy as np


DEFAULT_CONFIG_PATH = Path(__file__).resolve().parent / "calibration_config.json"


def get_calibration_path():
    configured = os.environ.get("THINKGRASP_CALIBRATION_CONFIG")
    return Path(configured) if configured else DEFAULT_CONFIG_PATH


def load_calibration():
    path = get_calibration_path()
    with path.open("r", encoding="utf-8") as file:
        return json.load(file)


def make_camera_info(camera_info_class):
    camera = load_calibration()["camera"]
    return camera_info_class(
        width=int(camera["width"]),
        height=int(camera["height"]),
        fx=float(camera["fx"]),
        fy=float(camera["fy"]),
        cx=float(camera["cx"]),
        cy=float(camera["cy"]),
        scale=float(camera["scale"]),
    )


def _matrix_from_payload(payload, key):
    if not payload or key not in payload:
        return None
    matrix = np.asarray(payload[key], dtype=np.float64)
    if matrix.shape != (4, 4):
        raise ValueError(f"{key} must be a 4x4 transform matrix")
    return matrix


def get_base_to_camera_transform(payload=None):
    direct = _matrix_from_payload(payload, "base_to_camera")
    if direct is not None:
        return direct

    direct = _matrix_from_payload(payload, "T_base_camera")
    if direct is not None:
        return direct

    base_to_end = _matrix_from_payload(payload, "base_to_end")
    if base_to_end is None:
        base_to_end = _matrix_from_payload(payload, "T_base_end")
    if base_to_end is not None:
        end_to_camera = _matrix_from_payload(payload, "end_to_camera")
        if end_to_camera is None:
            end_to_camera = np.asarray(load_calibration()["end_to_camera"], dtype=np.float64)
        return base_to_end @ end_to_camera

    return np.asarray(load_calibration()["base_to_camera"], dtype=np.float64)


def transform_grasp_to_base(xyz_camera, rot_camera, payload=None):
    base_to_camera = get_base_to_camera_transform(payload)
    xyz_camera = np.asarray(xyz_camera, dtype=np.float64).reshape(3)
    rot_camera = np.asarray(rot_camera, dtype=np.float64).reshape(3, 3)

    rot_base_camera = base_to_camera[:3, :3]
    trans_base_camera = base_to_camera[:3, 3]

    xyz_base = rot_base_camera @ xyz_camera + trans_base_camera
    rot_base = rot_base_camera @ rot_camera
    return xyz_base, rot_base
