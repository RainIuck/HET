# ThinkGrasp CUDA 13 / 新 PyTorch 环境配置指南

本文档适用于当前这套新环境：

- Ubuntu 桌面环境
- conda 环境名：`thinkgrasp`
- Python 3.12
- PyTorch 2.x + CUDA 13
- RTX 50 系显卡，GPU capability `(12, 0)`

目标是让 `simulation_main.py` 和 `realarm.py` 在新 CUDA / 新 PyTorch 下能运行，不再依赖 README 里旧的 `torch==1.13.1+cu117` 环境。

## 1. 进入项目

```bash
cd /home/rainluck/桌面/HET/ThinkGrasp-main
conda activate thinkgrasp
```

建议后续都显式使用当前环境里的 Python：

```bash
which python
python --version
```

如果 shell 没有正确激活 conda，也可以直接使用：

```bash
/home/rainluck/miniconda3/envs/thinkgrasp/bin/python
```

## 2. 安装 PyTorch

当前项目不再通过 `requirements.txt` 安装 PyTorch。PyTorch 需要按你的 CUDA 13 环境单独安装。

检查当前 PyTorch / CUDA：

```bash
python -c "import torch; print(torch.__version__, torch.version.cuda, torch.cuda.is_available(), torch.cuda.get_device_capability(0) if torch.cuda.is_available() else None)"
```

期望输出类似：

```text
2.12.0+cu130 13.0 True (12, 0)
```

如果 `torch.cuda.is_available()` 是 `False`，先不要继续安装项目依赖，优先修复 PyTorch/CUDA/驱动。

## 3. 安装项目依赖

```bash
pip install -r requirements.txt
```

`graspnetAPI` 在 Python 3.12 下需要特殊处理，因为它声明依赖 `transforms3d==0.3.1`，但该旧版本在 Python 3.12 上容易构建失败。使用：

```bash
pip install --no-deps graspnetAPI==1.2.10
pip install transforms3d==0.4.2
```

验证关键依赖：

```bash
python -c "import open3d, cv2, pybullet, ray, groundingdino, segment_anything; from graspnetAPI import GraspGroup; print('deps ok')"
```

## 4. 编译自定义 CUDA 扩展

项目里有 4 个自定义 CUDA 扩展，必须在当前 Python / PyTorch / CUDA 环境下重新编译：

```bash
cd /home/rainluck/桌面/HET/ThinkGrasp-main

cd models/graspnet/pointnet2
python setup.py install

cd ../knn
python setup.py install

cd ../../FGC_graspnet/pointnet2
python setup.py install

cd ../knn
python setup.py install

cd /home/rainluck/桌面/HET/ThinkGrasp-main
```

验证扩展：

```bash
python -c "import torch; import pointnet22._ext; import pointnet2._ext; from knn_pytorch import knn_pytorch; print('extensions ok')"
```

如果这里失败，通常是旧编译产物污染或 CUDA 架构不匹配。先清理对应目录下的 `build/`、`*.egg-info`、`*.so` 后重新编译。

## 5. 准备模型权重和资源

GraspNet 默认权重路径：

```text
models/graspnet/logs/log_rs/checkpoint.tar
```

检查：

```bash
ls -lh models/graspnet/logs/log_rs/checkpoint.tar
```

仿真物体资源需要：

```text
assets/simplified_objects
assets/unseen_objects_40
assets/unseen_objects
```

如果有压缩包，先解压：

```bash
cd /home/rainluck/桌面/HET/ThinkGrasp-main/assets
unzip unseen_objects_40.zip
cd ..
```

## 6. 配置 GPT 接口

项目根目录支持本地环境文件：

```text
/home/rainluck/桌面/HET/ThinkGrasp-main/.env.local
```

格式如下，注意不要把真实 key 提交到 git：

```bash
OPENAI_API_KEY="你的key"
OPENAI_BASE_URL="https://第三方OpenAI兼容地址/v1"
OPENAI_MODEL="gpt-5.5"
```

代码启动时会自动读取 `.env.local`。如果 shell 里已经 `export` 了同名变量，shell 变量优先。

确认 `.env.local` 被 git 忽略：

```bash
git check-ignore -v .env.local
```

## 7. 推荐运行时变量

仿真推荐使用下面的稳定配置：

```bash
export WANDB_MODE=offline
export HF_HUB_OFFLINE=1
export LANGSAM_HF_LOCAL_FILES_ONLY=1
export LANGSAM_SKIP_SAM=1
export LANGSAM_DINO_RESIZE=512
export LANGSAM_PREDICT_TIMEOUT=90
```

含义：

- `WANDB_MODE=offline`：不要求登录 WandB。
- `HF_HUB_OFFLINE=1` / `LANGSAM_HF_LOCAL_FILES_ONLY=1`：优先使用本地 HuggingFace cache。
- `LANGSAM_SKIP_SAM=1`：仿真只使用 GroundingDINO bbox，跳过较重的 SAM mask。
- `LANGSAM_DINO_RESIZE=512`：降低 DINO 输入尺寸，减少推理时间。
- `LANGSAM_PREDICT_TIMEOUT=90`：LangSAM 单次预测超过 90 秒时回退到 GPT crop box。

真实机械臂接口 `realarm.py` 会显式启用 SAM，不会被仿真的 `LANGSAM_SKIP_SAM=1` 影响。

## 8. 快速验证

```bash
cd /home/rainluck/桌面/HET/ThinkGrasp-main
conda activate thinkgrasp

python -c "import torch; print(torch.__version__, torch.version.cuda, torch.cuda.is_available())"
python -c "import torch; import pointnet22._ext; import pointnet2._ext; from knn_pytorch import knn_pytorch; print('extensions ok')"
python simulation_main.py --help
```

最小仿真验证：

```bash
WANDB_MODE=offline \
HF_HUB_OFFLINE=1 \
LANGSAM_HF_LOCAL_FILES_ONLY=1 \
LANGSAM_SKIP_SAM=1 \
LANGSAM_DINO_RESIZE=512 \
LANGSAM_PREDICT_TIMEOUT=90 \
python simulation_main.py \
  --num_episode 1 \
  --max_episode_step 1 \
  --testing_case_dir testing_cases \
  --testing_case case00-round.txt
```

带 GUI：

```bash
WANDB_MODE=offline \
HF_HUB_OFFLINE=1 \
LANGSAM_HF_LOCAL_FILES_ONLY=1 \
LANGSAM_SKIP_SAM=1 \
LANGSAM_DINO_RESIZE=512 \
LANGSAM_PREDICT_TIMEOUT=90 \
python simulation_main.py \
  --gui \
  --num_episode 1 \
  --max_episode_step 5 \
  --testing_case_dir testing_cases \
  --testing_case case00-round.txt
```

## 9. 常见问题

### `ray: command not found`

说明当前 shell 没有激活 conda 环境。可以用完整路径：

```bash
/home/rainluck/miniconda3/envs/thinkgrasp/bin/ray stop --force
```

### Ray metrics exporter 报错

类似：

```text
Failed to establish connection to the metrics exporter agent
```

这通常不影响仿真运行，可以先忽略。

### HuggingFace 网络不可用

确保模型已经存在本地 cache，并设置：

```bash
export HF_HUB_OFFLINE=1
export LANGSAM_HF_LOCAL_FILES_ONLY=1
```

### GUI 看起来卡住

旧代码里 matplotlib `plt.show()` 会阻塞。当前代码已改为非阻塞显示，并保存：

```text
cropping_box_visualization.png
```

如需手动阻塞查看图像，可设置：

```bash
export THINKGRASP_BLOCKING_PLOTS=1
```

正常跑仿真不建议设置这个变量。
