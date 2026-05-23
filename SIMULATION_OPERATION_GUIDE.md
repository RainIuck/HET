# ThinkGrasp 仿真运行与任务修改指南

本文档从项目根目录 `/home/rainluck/桌面/HET` 讲如何运行 ThinkGrasp 仿真，以及如何修改仿真场景和目标抓取物体。

项目目录：

```text
/home/rainluck/桌面/HET
└── ThinkGrasp-main
```

## 1. 进入项目和环境

```bash
cd /home/rainluck/桌面/HET/ThinkGrasp-main
conda activate thinkgrasp
```

如果 `ray` 命令找不到，用完整路径：

```bash
/home/rainluck/miniconda3/envs/thinkgrasp/bin/ray stop --force
```

## 2. 推荐运行前清理

如果之前仿真卡住或中断过，先清理 Ray：

```bash
/home/rainluck/miniconda3/envs/thinkgrasp/bin/ray stop --force
pkill -f "simulation_main.py" || true
```

## 3. 推荐运行环境变量

每次运行仿真建议带上这些变量：

```bash
export WANDB_MODE=offline
export HF_HUB_OFFLINE=1
export LANGSAM_HF_LOCAL_FILES_ONLY=1
export LANGSAM_SKIP_SAM=1
export LANGSAM_DINO_RESIZE=512
export LANGSAM_PREDICT_TIMEOUT=90
```

GPT 接口配置放在：

```text
ThinkGrasp-main/.env.local
```

格式：

```bash
OPENAI_API_KEY="你的key"
OPENAI_BASE_URL="https://第三方OpenAI兼容地址/v1"
OPENAI_MODEL="gpt-5.5"
```

不需要每次手动 `export OPENAI_API_KEY`。

## 4. 最小仿真运行

不带 GUI，最快验证：

```bash
cd /home/rainluck/桌面/HET/ThinkGrasp-main

WANDB_MODE=offline \
HF_HUB_OFFLINE=1 \
LANGSAM_HF_LOCAL_FILES_ONLY=1 \
LANGSAM_SKIP_SAM=1 \
LANGSAM_DINO_RESIZE=512 \
LANGSAM_PREDICT_TIMEOUT=90 \
/home/rainluck/miniconda3/envs/thinkgrasp/bin/python simulation_main.py \
  --num_episode 1 \
  --max_episode_step 1 \
  --testing_case_dir testing_cases \
  --testing_case case00-round.txt
```

## 5. 带 GUI 运行

```bash
cd /home/rainluck/桌面/HET/ThinkGrasp-main

WANDB_MODE=offline \
HF_HUB_OFFLINE=1 \
LANGSAM_HF_LOCAL_FILES_ONLY=1 \
LANGSAM_SKIP_SAM=1 \
LANGSAM_DINO_RESIZE=512 \
LANGSAM_PREDICT_TIMEOUT=90 \
/home/rainluck/miniconda3/envs/thinkgrasp/bin/python simulation_main.py \
  --gui \
  --num_episode 1 \
  --max_episode_step 5 \
  --testing_case_dir testing_cases \
  --testing_case case00-round.txt
```

如果窗口一闪而过，说明 episode 很快结束了。可以增大：

```bash
--max_episode_step 10
```

或者运行更多 episode：

```bash
--num_episode 3
```

## 6. 仿真任务是什么

一次仿真大致做这些事：

1. 读取一个 `testing_cases/*.txt` 场景文件。
2. 在 PyBullet 里加载多个物体。
3. 读取场景文件第一行作为语言目标，例如 `grasp a round object`。
4. GPT 根据当前 RGB 图像和语言目标选择目标物体。
5. LangSAM/GroundingDINO 根据目标文本定位 bbox。
6. GraspNet 在 bbox 对应的点云区域生成抓取姿态。
7. 机械臂执行抓取。
8. 环境根据 case 文件第二行的目标物体索引判断 success。

成功输出通常类似：

```text
Episode: 0, step: 3, reward: 2
Episode: 0, episode steps: 3, episode reward: 0, success: True
average success: 1.0
```

## 7. 切换已有目标任务

已有测试 case：

```text
case00-round.txt      抓圆形物体
case01-eat.txt        抓可以吃的东西
case02-container.txt  抓可以装东西的容器
case03-round.txt      抓圆形物体
case04-cup.txt        抓杯子
case05-cup.txt        抓杯子
case06-fruit.txt      抓水果
case07-drink.txt      抓可以喝的东西
case08-thera_med.txt  抓 thera_med
case09-pear.txt       抓梨
```

例如抓杯子：

```bash
WANDB_MODE=offline \
HF_HUB_OFFLINE=1 \
LANGSAM_HF_LOCAL_FILES_ONLY=1 \
LANGSAM_SKIP_SAM=1 \
LANGSAM_DINO_RESIZE=512 \
LANGSAM_PREDICT_TIMEOUT=90 \
/home/rainluck/miniconda3/envs/thinkgrasp/bin/python simulation_main.py \
  --gui \
  --num_episode 1 \
  --max_episode_step 5 \
  --testing_case_dir testing_cases \
  --testing_case case04-cup.txt
```

## 8. 修改目标抓取物体

目标由 `testing_cases/*.txt` 控制。文件结构：

```text
第 1 行：语言目标，给 GPT / LangSAM 用
第 2 行：目标物体索引，用来判断抓取是否成功
第 3 行以后：物体 URDF、位置、姿态
```

示例：

```text
grasp a round object
1 2
assets/simplified_objects/015.urdf 0.57 0.09 0.20 5.21 4.34 4.80
assets/simplified_objects/017.urdf 0.53 -0.00 0.20 3.11 1.71 5.76
assets/simplified_objects/021.urdf 0.59 -0.10 0.20 4.00 5.87 1.28
```

物体索引从第 3 行开始按 `0, 1, 2...` 计算。

如果第二行写：

```text
1 2
```

表示第 3 行之后的第 1 号和第 2 号物体都算正确目标。

只改第一行会改变 GPT 选择目标，但不一定改变最终 success 判定。正式评估时必须同时改第二行。

## 9. 自定义一个新任务

复制一个已有 case：

```bash
cd /home/rainluck/桌面/HET/ThinkGrasp-main
cp testing_cases/case00-round.txt testing_cases/case10-custom.txt
```

编辑：

```bash
gedit testing_cases/case10-custom.txt
```

例如想抓剪刀：

```text
give me the scissors
13
```

这里 `13` 必须是该文件中剪刀那一行对应的物体索引。可以从第 3 行开始数，第一行物体是 `0`。

运行：

```bash
WANDB_MODE=offline \
HF_HUB_OFFLINE=1 \
LANGSAM_HF_LOCAL_FILES_ONLY=1 \
LANGSAM_SKIP_SAM=1 \
LANGSAM_DINO_RESIZE=512 \
LANGSAM_PREDICT_TIMEOUT=90 \
/home/rainluck/miniconda3/envs/thinkgrasp/bin/python simulation_main.py \
  --gui \
  --num_episode 1 \
  --max_episode_step 5 \
  --testing_case_dir testing_cases \
  --testing_case case10-custom.txt
```

## 10. 修改仿真环境中的物体

每个物体行格式：

```text
URDF路径 x y z roll pitch yaw
```

例如：

```text
assets/simplified_objects/015.urdf 0.57 0.09 0.20 5.21 4.34 4.80
```

含义：

- `assets/simplified_objects/015.urdf`：物体模型。
- `x y z`：初始位置。
- `roll pitch yaw`：初始欧拉角，单位是弧度。

可以做的修改：

- 换物体：把 URDF 路径换成 `assets/simplified_objects/其他编号.urdf`。
- 移动物体：改 `x y`，例如 `0.50 0.03`。
- 改初始高度：通常保持 `z=0.20`。
- 改姿态：修改最后 3 个角度。
- 增加物体：追加一行 URDF。
- 删除物体：删除对应物体行，同时记得更新第二行目标索引。

注意：如果修改物体数量或顺序，第二行目标索引也要重新数。

## 11. 查看 GPT 选择结果

每次仿真会写：

```text
grasping_result_log.json
```

里面有：

```json
{
  "selected_object": "...",
  "cropping_box": [...],
  "objects": [...]
}
```

如果你想确认 GPT 是否选对目标，优先看这个文件。

## 12. 常见运行问题

### GUI 卡住

当前代码已把 matplotlib crop box 窗口改成非阻塞，并保存：

```text
cropping_box_visualization.png
```

正常运行不要设置：

```bash
THINKGRASP_BLOCKING_PLOTS=1
```

### Ray metrics 报错

类似：

```text
Failed to establish connection to the metrics exporter agent
```

通常不影响仿真结果。

### LangSAM 加载后长时间等待

确认运行时带了：

```bash
LANGSAM_SKIP_SAM=1
LANGSAM_DINO_RESIZE=512
LANGSAM_PREDICT_TIMEOUT=90
```

### 第三方 GPT 没有调用记录

先用项目自动读取的 `.env.local` 做最小探针：

```bash
cd /home/rainluck/桌面/HET/ThinkGrasp-main
/home/rainluck/miniconda3/envs/thinkgrasp/bin/python - <<'PY'
from compat import load_local_env
from openai import OpenAI
import os

load_local_env()
client = OpenAI(api_key=os.environ["OPENAI_API_KEY"], base_url=os.environ.get("OPENAI_BASE_URL"))
resp = client.chat.completions.create(
    model=os.environ.get("OPENAI_MODEL", "gpt-5.5"),
    messages=[{"role": "user", "content": "Reply with exactly: THINKGRASP_OK"}],
    temperature=0,
    max_tokens=16,
)
print(resp.model)
print(resp.choices[0].message.content)
print(resp.usage)
PY
```
