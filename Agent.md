# HET 项目上下文记录

这个文件用于新对话快速接上当前进度。

## 当前状态

- 仓库路径：`/home/Projects/HET`
- 当前分支：`control2`
- `control2` 是从最新可用的 `origin/control-layer` 创建的。
- 当前目标：先优化 Alicia-D 真机状态反馈 / open-loop 问题，再新建 ROS2 节点控制 STS3215 新夹爪。
- 已完成：控制层环境已搭建；MoveIt 仿真 + mock ThinkGrasp 抓取链路已经完成一次规划和执行验证。
- 当前最高优先级：继续真机验证 `alicia_d_driver` 的真实反馈闭环状态路径。代码已从默认 open-loop 改为默认使用 Alicia-D 主控真实 6 轴关节反馈；旧夹爪缺失只让夹爪状态降级为 command mirror，不应阻断 6 轴关节反馈。
- 后续第二优先级：新夹爪为飞特 STS3215 总线舵机，需要独立 ROS2 节点控制，不应混入 Alicia-D 原主控协议。

## 记录维护规则

- 之后每次出现新的关键历史，都要同步更新本文件。
- 需要记录的关键历史包括：实验结果、失败原因、已验证命令、代码结构决策、安全限制、真机状态、分支/构建方式变化。
- 不需要记录临时过程噪声，例如普通命令输出、一次性调试尝试、可由日志目录追溯的重复信息。
- 新记录优先追加到“近期历史”或对应主题段落，保持这个文件能作为新对话的项目交接入口。

## 近期历史

- 2026-05-30：从 `origin/control-layer` 创建并切换到 `control2`。由于 GitHub 代理 TLS 间歇失败，未能再次 `fetch` 远端确认；本地 `origin/control-layer` 基于刚 clone 得到的提交 `d62650e`。
- 2026-05-30：删除仓库里旧机器残留的 `alicia_ws/build`、`alicia_ws/install`、`alicia_ws/log` 构建产物。这些文件原本被 Git 跟踪，删除后会在 `git status` 中显示大量 `D`。
- 2026-05-30：控制层依赖已安装。`rosdep` 曾因错误引用 `releases-fuerte.yaml` 报 `release-name must be a dictionary`，已从 rosdep source/cache 中移除该错误引用。
- 2026-05-30：`warehouse_ros_mongo` 在当前 ROS Humble 源中无可用包；已安装 `warehouse_ros` / `warehouse_ros_sqlite`。当前 mock 控制链路不依赖 Mongo warehouse。
- 2026-05-30：曾为避免旧 `build/install` 缓存路径污染，使用 `alicia_ws/install_control2` 作为安装空间。
- 2026-05-30：新增实验脚本 `alicia_ws/run_control_layer_smoke_test.sh`。它会启动 MoveIt demo、mock decision server、执行 mock pick，并记录实验日志到 `alicia_ws/experiment_logs/simulation/control_layer_<timestamp>/`。
- 2026-05-30：仿真 smoke test 成功。实验目录：`alicia_ws/experiment_logs/simulation/control_layer_20260530_223401`。`pre_grasp` 规划 44 waypoints 并执行成功，`grasp` 规划 12 waypoints 并执行成功，夹爪 close 到 `0.0200` 成功，`lift` 规划 12 waypoints 并执行成功。
- 2026-05-30：仿真日志发现的主要后续问题：`gripper_center` 只有 visual geometry 没有 collision geometry；`base_link` root link 带 inertia 触发 KDL 警告；未配置 3D sensor plugin 导致 Octomap 不更新；关节 acceleration limit 未定义，MoveIt 使用默认 `1 rad/s^2`。
- 2026-05-30：新增只读真机反馈诊断工具 `alicia_ws/tools/alicia_feedback_diag.py`。它不经过 MoveIt / ros2_control，不发送 torque 或运动命令，只查询版本、自检和连续关节反馈，并把原始帧与解析结果记录到 `alicia_ws/experiment_logs/feedback_diagnostics/alicia_feedback_<timestamp>/`。第一轮诊断不需要连接旧夹爪舵机；若自检或关节反馈异常，再接回旧夹爪做 A/B 对比。
- 2026-05-30：真机反馈诊断日志整理到 `alicia_ws/experiment_logs/`，仿真日志在 `simulation/`，真机反馈诊断日志在 `feedback_diagnostics/`；旧 `alicia_ws/diagnostic_logs` 已删除。
- 2026-05-30：已分析真机反馈诊断 `alicia_ws/experiment_logs/feedback_diagnostics/alicia_feedback_20260530_235550`。结果：版本帧、自检帧、30/30 关节反馈帧 CRC 均有效；关节 raw 非全 0，最后一帧 raw 为 `[2048, 2041, 2040, 2047, 2041, 2047]`，约 `[0.000, -0.615, -0.703, -0.088, -0.615, -0.088] deg`；self-check `0x01FF`，`bit_9` 为 fault；运行状态大多 `idle`，但第 17/18 帧出现 `0xE1 overheat`，第 23 帧出现 `0xE2 overheat_protect`。这说明关节位置反馈链路可用，open-loop 默认策略应改回使用真实反馈并保留异常状态保护。
- 2026-05-31：接回 Alicia-D 旧末端夹爪后重新运行反馈诊断，目录 `alicia_ws/experiment_logs/feedback_diagnostics/alicia_feedback_20260531_000949`。结果：版本仍为同一设备 `ADFX2604145YH2KT`，30/30 关节反馈帧 CRC 有效且非全 0；self-check 从不接旧夹爪时的 `0x01FF bit_9 fault` 变为 `0x03FF`，无 fault；30 帧运行状态全部 `0x00 idle`，未再出现 `0xE1/0xE2`；gripper raw 稳定约 `993`。A/B 结论：`bit_9` 基本可判定为 Alicia-D 原夹爪/末端舵机相关自检位；旧夹爪不影响 6 轴关节位置反馈，但会影响整机 self-check 完整通过。
- 2026-05-31：已开始把 `alicia_d_driver` 从默认 open-loop 改为默认使用真实关节反馈。改动点：`use_open_loop_state` 默认改为 `false`；`JointState` 保存 6 轴 raw 值和 raw run status；hardware interface 会拒绝全 raw 0、反馈超时、非有限角度、未知 run status、`0xE2 overheat_protect` 作为有效闭环状态；`0xE1 overheat` 仍可用于位置反馈但会报警；若 self-check bit_9 fault，则 6 轴继续使用真实反馈，夹爪单独降级为 command mirror。新增 launch 参数 `use_open_loop_state` 和 `feedback_timeout_s`，保留显式 open-loop 调试入口。曾用 `build_control2/install_control2/log_control2` 编译验证通过；用户后续要求不再保留这些后缀目录，改回普通 `build/install/log`。
- 2026-05-31：新增真机硬件默认配置 `alicia_ws/src/alicia_d_moveit/config/hardware_defaults.yaml`，当前默认 port 为 `/dev/serial/by-id/usb-1a86_USB_Single_Serial_5B14041395-if00`，`use_open_loop_state=false`，`feedback_timeout_s=0.5`。`real_robot.launch.py` 默认从该配置读取参数，同时保留命令行覆盖。已重编 `alicia_d_moveit` 并验证 `--show-args` 能显示配置中的默认 port。
- 2026-05-31：用户不需要 Windows attach 脚本，已删除 `alicia_ws/tools/attach_alicia_usb_to_wsl.ps1` 和 `alicia_ws/tools/attach_alicia_usb_to_wsl.sh`；同时已删除 `alicia_ws/build_control2`、`alicia_ws/install_control2`、`alicia_ws/log_control2`。后续编译默认使用普通 `alicia_ws/build`、`alicia_ws/install`、`alicia_ws/log`。
- 2026-05-31：新增小幅动作反馈测试脚本 `alicia_ws/tools/tiny_feedback_motion_test.py`，默认对 Joint6 做 `+0.03 rad / 3s` 的 FollowJointTrajectory，并记录 `/joint_states` 与 `/Alicia_controller/controller_state` 到 `alicia_ws/experiment_logs/feedback_motion/`。首次测试目录 `tiny_feedback_motion_20260531_210724_current_gripper_state` 显示控制器 desired 从 `0` 到 `0.03`，但 controller actual 和 `/joint_states` 仍固定在 `initial_positions.yaml`，说明当前运行中的 driver 没有持续拿到真实反馈。排查发现 `SerialCommunicator::write_packet()` 每次写命令后都会 `FlushIOBuffers()`，在 200Hz 控制写入时可能冲掉反馈帧；已移除该 flush 并用普通 `colcon build --packages-up-to alicia_d_driver alicia_d_moveit` 编译通过。需要重启 `real_robot.launch.py` 后复测。

## 当前优先优化计划：修复 open-loop 状态问题

目标：让真机 MoveIt 使用可信的真实关节状态，而不是长期依赖“上一条命令位置 = 当前状态”的 open-loop 临时策略。

### 背景

- 当前真机位置查询帧按协议发送后，返回的关节位置数据区为全 0。
- 现有解析逻辑会把 raw `0` 换算成约 `-pi`，导致 `/joint_states` 异常。
- 为避免 MoveIt 认为机械臂在六个 `-pi`，当前代码使用 open-loop command state 临时绕过。
- open-loop 只适合受控调试，不适合自动抓取；断电、急停、手动移动后，软件状态会和真实机械臂状态不一致。

### 排查步骤

1. 梳理代码路径
   - 阅读 `alicia_d_driver` 中串口通信、协议解析、hardware interface、driver node、launch 参数。
   - 明确 read/write 周期里哪些数据来自真机反馈，哪些数据来自 command mirror。
   - 找到 `use_open_loop_state` 的默认值、启动参数、状态覆盖逻辑。

2. 做最小真机状态诊断工具
   - 已新增独立诊断脚本 `alicia_ws/tools/alicia_feedback_diag.py`，只做串口查询，不经过 MoveIt。
   - 连续发送位置查询帧，记录原始 hex、长度、校验、运行状态、解析后的 raw/angle。
   - 同时记录固件版本、自检状态、温度/速度查询结果。
   - 输出 JSON/文本日志，便于发给厂家确认。

3. 验证协议和解析
   - 对照 `material2` 协议确认位置查询帧、返回长度、字段偏移、校验算法。
   - 用协议示例或人工构造帧写单元测试，确认 raw `2048` 约等于 `0 rad`，raw `0` 约等于 `-pi`。
   - 如果真机返回长度/字段和文档不一致，先不要改换算公式，要记录证据。

4. 建立状态质量判断
   - 对返回状态加有效性检查：全关节 raw 全 0、校验失败、长度异常、状态字段异常时标记为 invalid。
   - invalid 时不要把全 0 直接发布成真实 `/joint_states`。
   - 区分三种状态来源：真实反馈、open-loop command mirror、initial safe pose。

5. 改进 open-loop 策略
   - 保留 open-loop 作为显式调试模式，但默认不要让它伪装成可靠闭环。
   - 在 launch 参数、日志、topic/diagnostic 中明确当前状态来源。
   - 真机自动动作前，如果状态来源不是真实反馈，应要求人工确认或禁止自动抓取流程。

6. 尝试恢复真实反馈
   - 根据诊断结果向厂家/群里确认：Firmware 6.1.0 下位置查询为什么返回 15 字节全 0；是否需要初始化、使能、模式切换、扭矩开启、零位同步或处理 self-check fault。
   - 若找到正确查询/初始化流程，再更新 driver read 路径。
   - 恢复后用低速安全姿态、`/joint_states`、MoveIt real_robot 启动进行验证。

### 验收标准

- 独立诊断脚本能稳定保存真机原始状态查询日志。
- driver 能明确报告当前 joint state 来源：真实反馈 / open-loop / invalid。
- 当真机反馈无效时，不会静默发布六个 `-pi` 作为真实状态。
- MoveIt real_robot 启动时，用户能从日志或 topic 清楚看到是否仍处于 open-loop。
- 若真实反馈恢复，`/joint_states` 应接近机械臂实际姿态，而不是全 `-3.1416`。

### 暂不做

- 暂不直接接入真实 ThinkGrasp 自动抓取。
- 暂不把 STS3215 新夹爪塞进 Alicia-D 原主控协议。
- 暂不在真实反馈未修复前做无人值守真机抓取。

## 重要文档入口

- 顶层 `readme`：最重要的联调交接记录，包含 mock bridge、真机关节反馈全 0、open-loop 临时策略、安全姿态、STS3215 新夹爪和后续优先级。
- `alicia_ws/src/README.md`：Alicia-D ROS2 控制栈安装和快速启动。
- `alicia_ws/src/docs/Basic_usage.md`：仿真、真机 MoveIt、独立驱动、`/joint_commands` 使用方法。
- `alicia_ws/src/install.sh`：ROS2 / MoveIt / ros2_control 依赖安装脚本。
- `alicia_ws/src/alicia_d_moveit/README.md`：MoveIt 启动和配置。
- `alicia_ws/src/alicia_d_grasp_6d/README.md`：D405/Gemini、SAM2、GraspGen 6D 抓取流程。
- `ThinkGrasp-main/ENVIRONMENT_SETUP_GUIDE_CUDA13.md`：ThinkGrasp 视觉模型 CUDA13 环境配置。

## WSL / Ubuntu 环境要求

控制栈不适合直接在 Windows PowerShell 里跑，需要 Ubuntu 环境。

推荐：

- Ubuntu 22.04
- ROS2 Humble
- MoveIt2
- ros2_control
- colcon
- rosdep
- libserial-dev

WSL 可以先用于编译、MoveIt demo、mock bridge。真机串口、相机、RViz 会比原生 Ubuntu 麻烦；如果要稳定接真机，原生 Ubuntu 最稳。

建议把仓库放在 WSL 的 Linux 文件系统里，例如 `~/HET`，不要长期在 `/mnt/e/...` 下编译，避免 colcon 慢和权限问题。

## WSL 中安装 ROS2 Humble 基础环境

进入 Ubuntu 22.04 后执行：

```bash
sudo apt update
sudo apt install -y locales software-properties-common curl gnupg lsb-release
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8

sudo add-apt-repository universe
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key \
  -o /usr/share/keyrings/ros-archive-keyring.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" \
  | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

sudo apt update
sudo apt install -y \
  ros-humble-desktop \
  python3-colcon-common-extensions \
  python3-rosdep \
  python3-vcstool \
  python3-pip

sudo rosdep init || true
rosdep update

echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

## 编译 Alicia-D 控制栈

如果仓库已经在 WSL 中：

```bash
cd ~/HET/alicia_ws/src
chmod +x install.sh
./install.sh

cd ~/HET/alicia_ws
rosdep install --from-paths src --ignore-src -r -y
colcon build
source install/setup.bash
```

如果仓库暂时还在 Windows 盘，可以先用：

```bash
cd /mnt/e/Study/HeerTai/HET/alicia_ws
```

但正式编译建议复制到 `~/HET`。

## 优先验证命令

先验证 ROS2 和 demo：

```bash
ros2 --help
cd ~/HET/alicia_ws
source install/setup.bash
ros2 launch alicia_d_moveit demo.launch.py gripper_type:=50mm
```

再验证 mock bridge，只规划不执行：

```bash
cd ~/HET/alicia_ws
source install/setup.bash
ros2 launch alicia_d_thinkgrasp_bridge mock_thinkgrasp_pick.launch.py execute_motion:=false
```

确认能规划后再执行仿真动作：

```bash
ros2 launch alicia_d_thinkgrasp_bridge mock_thinkgrasp_pick.launch.py
```

## 真机串口注意

真机不要一上来就跑自动抓取。先确认串口和权限：

```bash
ls /dev/ttyACM* /dev/ttyUSB* 2>/dev/null
sudo usermod -aG dialout $USER
sudo chmod a+rw /dev/ttyACM0
```

## 真机反馈诊断工具

诊断 Alicia-D 原主控关节反馈时，先不启动 MoveIt，也不启动 ros2_control，直接跑只读串口诊断：

```bash
cd /home/Projects/HET
python3 alicia_ws/tools/alicia_feedback_diag.py --port /dev/ttyACM0 --samples 30
```

如果串口名不确定：

```bash
python3 alicia_ws/tools/alicia_feedback_diag.py --list-ports
```

需要额外查询温度和速度时再加：

```bash
python3 alicia_ws/tools/alicia_feedback_diag.py --port /dev/ttyACM0 --samples 30 --include-extra
```

输出目录形如：

```bash
alicia_ws/experiment_logs/feedback_diagnostics/alicia_feedback_YYYYMMDD_HHMMSS/
```

重点看 `summary.txt` 和 `frames.jsonl`：

- `joint_frames_ok` 是否大于 0。
- `joint_frames_all_zero` 是否等于全部有效关节帧数量。
- `self_check_fault_bits` 是否有故障位。
- `last_joint_raw` / `last_joint_deg` 是否接近实际机械臂姿态。

旧夹爪已拆掉时，第一轮不需要接旧夹爪舵机。若不接旧夹爪时 self-check 有固定故障位、或所有关节反馈长期全 0，再断电后接回旧夹爪舵机重跑同一命令做 A/B 对比。不要把 STS3215 新夹爪接到 Alicia-D 原夹爪总线上。

WSL 访问 USB 串口通常需要 Windows 侧 `usbipd-win` 绑定设备：

```powershell
usbipd list
usbipd bind --busid <BUSID>
usbipd attach --wsl --busid <BUSID>
```

真机 MoveIt 启动示例：

```bash
cd ~/HET/alicia_ws
source install/setup.bash
ros2 launch alicia_d_moveit real_robot.launch.py port:=/dev/ttyACM0 gripper_type:=50mm speed_deg_s:=5
```

真机安全提醒：

- 第一次执行任何新动作，手要放在急停或电源开关旁。
- `Ctrl+C` 不是硬件急停。
- 当前 open-loop 状态下，断电、急停、手动拖动后，软件状态会和真实状态不一致。
- 顶层 `readme` 里有一个已验证的低速安全抬升 `/joint_commands`，真机测试前优先参考它。

## 当前控制链路摘要

- ThinkGrasp / mock 输出：`xyz + rot + dep`
- 控制桥：`alicia_ws/src/alicia_d_thinkgrasp_bridge`
- MoveIt 路径：抓取位姿 -> `/compute_ik` -> `/plan_kinematic_path` -> `/execute_trajectory`
- 机械臂控制器：`Alicia_controller`，控制 `Joint1` 到 `Joint6`
- 夹爪控制器：`Gripper_controller`，控制 `Gripper`
- 底层发送：`AliciaDHardwareInterface::write()` -> `AliciaDDataParserControl::set_joint_and_gripper()` -> 串口帧
- 串口协议：`1000000` baud，控制帧大致为 `AA 06 03 1C ... checksum FF`

## ThinkGrasp 视觉环境

这不是当前第一优先级。先跑控制栈。

后续要跑视觉时看：

```text
ThinkGrasp-main/ENVIRONMENT_SETUP_GUIDE_CUDA13.md
ThinkGrasp-main/README.md
SIMULATION_OPERATION_GUIDE.md
```

视觉环境大致需要：

- conda 环境 `thinkgrasp`
- PyTorch + CUDA，按显卡选择 CUDA13 新方案或原 README 的 CUDA11.8 方案
- `pip install -r requirements.txt`
- 编译 GraspNet / FGC_graspnet 的 PointNet2 和 KNN CUDA 扩展
- 准备 `.env.local` 的 OpenAI-compatible API 配置
- 准备模型权重和 assets
