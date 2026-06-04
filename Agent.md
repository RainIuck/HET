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
- 2026-06-01：多物体比赛模拟抓取的流程先按任务闭环设计：连续识别场景，输出多个候选物体/抓取点；筛选可达、可规划、符合任务目标的候选；执行单物体 `pre_grasp -> grasp -> lift -> place`；抓完更新/重新识别场景，再选择第二个物体。不要在第一次识别时预先固定两个物体的抓取点并盲目连续执行。
- 2026-06-02：反馈再次异常。直接绕过 ROS 运行 `alicia_feedback_diag.py` 能读到版本 `ADFX2604145YH2KT` 和 self-check `0x01FF bit_9 fault`，但连续 joint 帧全部为 `raw=[0,0,0,0,0,0]`；温度和速度查询 timeout。已做单因素恢复：确认 `/dev/serial/by-id/usb-1a86_USB_Single_Serial_5B14041395-if00 -> /dev/ttyACM0` 存在、串口无进程占用、`usbipd` 设备 `2-5` attached；执行 USBIPD detach/attach 后复测仍全 0；只发送正常启动使用的 `torque_on` 帧后复测仍全 0。结论：当前不是 by-id 路径、WSL USB 会话或未 torque_on 单独导致；更像 Alicia-D 主控在线但未从关节/末端链路拿到真实关节反馈。历史对照中 `20260530_235550` 同样有 `bit_9 fault` 但关节 raw 非 0，因此 bit_9 不是单独充分原因。当前 ROS 图只剩 MoveIt/RViz，`controller_manager` 不在；重启 ROS 控制栈前应先恢复硬件直接诊断的非零 joint raw。
- 2026-06-02：16:54 左右用户重新启动 `real_robot.launch.py debug_mode:=true` 后反馈恢复。当前 `/dev/ttyACM0` 被 `ros2_control_node` 占用，说明不能同时跑只读诊断脚本；从 ROS 侧读取到 `/joint_states` 已为真实非初始值，`Alicia_controller/controller_state.actual` 也有真实反馈。当前 `ros2_control_node` 日志显示连续 joint 帧 raw 为 `[354, 2123, 2233, 2023, 1326, 3746]`，约 `[-148.89, 6.59, 16.26, -2.20, -63.46, 149.24] deg`，gripper raw `995`，status `0x00 idle`。阶段性分析：恢复更可能来自重新启动真机控制栈/重新打开串口/硬件控制状态重新初始化，而不是代码修改；之前全 0 是 Alicia-D 主控在线但内部关节反馈链未返回有效位置。
- 2026-06-02：`alicia_ws/tools/attach_alicia_usb_to_wsl.sh` 默认候选 busid 改为依次尝试 `2-3`、`2-5`。仍支持命令行显式传 busid，例如 `attach_alicia_usb_to_wsl.sh 2-5`；也支持 `ALICIA_USB_BUSID="2-3 2-5"` 覆盖。
- 2026-06-02：新增第一版独立 STS3215 新夹爪包 `alicia_ws/src/alicia_d_sts_gripper`，不接入 Alicia-D 主控 driver，不改 MoveIt 结构。该第一版曾提供标准 `GripperCommand` action 和 open/close 服务，已在 2026-06-03 的结构重构中被三个专用夹爪 Action 替代。
- 2026-06-02：新增交互式夹爪工具 `alicia_ws/tools/sts3215_gripper_manual_calibrate.py`。它直接连接 STS3215 串口，左右方向键按固定 step 移动舵机并显示当前 raw。2026-06-03 起不再写入旧 `open_raw/closed_raw` 标定字段，只用于低速点动、读取 raw 和确认方向。
- 2026-06-02：当前串口区分：Alicia-D 机械臂主控为 `/dev/serial/by-id/usb-1a86_USB_Single_Serial_5B14041395-if00 -> /dev/ttyACM0`；STS3215 新夹爪当前为 `/dev/serial/by-id/usb-1a86_USB_Single_Serial_5B79032424-if00 -> /dev/ttyACM1`。已把新夹爪 by-id 路径写入交互式标定脚本默认值、`alicia_d_sts_gripper` 源码配置/launch 默认值，以及当前 install 配置/launch 副本。
- 2026-06-02：串口配置约定改为“launch 的 port 跟 YAML 走”。机械臂真机 launch `alicia_d_moveit/launch/real_robot.launch.py` 已移除 `port` launch 参数，启动时从 `alicia_d_moveit/config/hardware_defaults.yaml` 读取机械臂主控串口；夹爪 launch `alicia_d_sts_gripper/launch/sts3215_gripper.launch.py` 已移除 `port/baudrate/servo_id` launch 参数覆盖，只加载 `alicia_d_sts_gripper/config/sts3215_gripper.yaml`。因此长期改串口只改对应 YAML；改 source YAML 后需重编/安装，或使用标定脚本同步当前 install 配置。
- 2026-06-02：用户运行 `sts3215_gripper_manual_calibrate.py` 时初始读位置超时：`Timed out waiting for STS3215 packet header`。这表示串口文件能打开，但没有收到 STS3215 协议响应；优先排查 WSL USB attach、夹爪舵机供电、GND/TX/RX 或单线总线接法、baudrate、servo_id。标定脚本已增强：终端显示从 raw 改为 cbreak，修复输出“楼梯状”；启动时先读位置、读通后再 torque-on；新增 `--list-ports` 和 `--scan`，默认扫描 baudrate `1000000,115200,500000,250000` 与 id `1..10`。
- 2026-06-02：Windows 侧夹爪 USB 显示为 `2-3 1a86:55d3 USB-Enhanced-SERIAL CH343 (COM7)`。项目配置不使用 Windows COM 号；WSL attach 使用 busid `2-3`，ROS/标定使用 Linux by-id 串口。`attach_alicia_usb_to_wsl.sh` 已默认尝试 `2-3`，无需因 COM4/COM7 变化而修改。标定脚本默认 `port/baudrate/id` 已改为读取 `alicia_d_sts_gripper/config/sts3215_gripper.yaml`。
- 2026-06-02：标定脚本报 `[Errno 2] could not open port ... No such file or directory` 时，含义是 WSL 中没有配置的 Linux 串口文件，优先执行 `tools/attach_alicia_usb_to_wsl.sh 2-3` 并检查 `/dev/serial/by-id`，不要先排查 STS3215 协议或标定值。脚本已增强：若配置端口不存在，会直接打印 attach/ls 提示和当前可见串口，然后退出；`--scan` 在端口不存在时也会先报端口问题。
- 2026-06-02：用户确认夹爪串口当前为 `/dev/serial/by-id/usb-1a86_USB_Single_Serial_5B79032424-if00 -> ../../ttyACM1`，已同步更新 `sts3215_gripper.yaml` 源码配置、当前 install 配置副本和标定脚本 fallback 默认值。用户已确认新夹爪 `baudrate=1000000`、`servo_id=1`，后续标定不需要扫描。新增工具文档 `alicia_ws/tools/launch.md`，记录编译、source、USB attach、真机/仿真/夹爪 launch 和诊断工具命令。
- 2026-06-02：标定脚本方向键在 WSL 终端中被拆成 `ESC`、`[`、`D/C` 三个按键，导致左右移动无效。已修复 `RawTerminal.read_key()`，等待完整 escape sequence；主循环改用该函数；新增备用键 `a/d` 左右微调，`+/-` 调整 step，并同步更新 `tools/launch.md` 键位说明。
- 2026-06-02：新夹爪策略从一圈 position raw 标定改为 STS3215 step/multi-turn。用户指定 `home_raw=0` 为可靠的最大打开机械参考，回零后将该位置作为软件 `ticks=0`，随后切到 step mode；夹爪节点 YAML 只放硬件参考、动作默认值和安全限制，当前 `max_closed_ticks=4700`、`min_safe_ticks=0`、`max_safe_ticks=4700`。2026-06-03 起回零由主控启动时调用夹爪 home Action，不再由夹爪节点自动执行。
- 2026-06-02：夹爪 launch 运行时仍尝试 `/dev/ttyUSB0`，原因不是端口没更新，而是 ROS2 参数 YAML 顶层 `sts3215_gripper:` 没匹配带 namespace 的节点 `/new_gripper/sts3215_gripper`，导致参数被忽略并回退代码默认值。已将 source 和 install 的 `sts3215_gripper.yaml` 顶层改为 `/**:`，并更新标定脚本读写逻辑兼容 `/**`、`/new_gripper/sts3215_gripper` 和旧 `sts3215_gripper` 三种结构。
- 2026-06-03：控制层结构调整为“主控节点统一调度，机械臂节点与夹爪节点独立”。先从旧 `thinkgrasp_mock_pick.py` 删除了夹爪直接控制，随后在同日完整重构中删除该执行器，拆为纯数据 ThinkGrasp Bridge、独立机械臂动作节点和主控节点。
- 2026-06-03：删除会同时启动、订阅机械臂和夹爪的临时联调工具 `tools/record_integration_topics.py`、`tools/run_pick_integration_capture.sh`，避免在主控节点设计完成前保留第二套隐式调度入口。夹爪 step action 通过 `moving=true -> moving=false` 确认完成的底层逻辑仍保留在独立夹爪节点中。
- 2026-06-03：确认后续节点职责：ThinkGrasp Bridge 只转换并发布抓取结果；主控节点负责初始化夹爪、生成 `pre_grasp/grasp/lift` 任务策略并调度机械臂与夹爪 action；独立机械臂动作节点接收任意目标位姿并封装 MoveIt 规划/执行；独立夹爪节点负责回零、相对位置、力矩夹取和持续状态发布。ThinkGrasp `/grasp_pose` 返回的 `dep` 来自 GraspNet `GraspGroup.depths`，表示沿夹爪接近轴的抓取插入深度，不是相机深度图中的像素深度；桥接层应保留并明确命名为 `grasp_depth_m`。
- 2026-06-03：开始按上述职责重构。新增公共接口包 `alicia_d_control_interfaces`，定义 `GraspCandidate`、`GripperState`、`MoveArmToPose`、`HomeGripper`、`MoveGripper`、`ForceGrasp`；新增独立机械臂动作包 `alicia_d_arm_motion` 和主控包 `alicia_d_pick_coordinator`；删除旧 `thinkgrasp_mock_pick.py`，新增纯数据 `thinkgrasp_bridge_node.py`。项目根目录新增 `structure.md` 记录结构框架和配置归属。
- 2026-06-03：新夹爪节点改为三个 Action：`/new_gripper/home`、`/new_gripper/move_relative`、`/new_gripper/force_grasp`；持续发布 `/new_gripper/state`，包含 raw 编码器位置、回零后的实际相对 ticks、load/current、moving、电压、温度和故障。节点启动后不自动运动，主控启动时调用 home；home 到 `home_raw=0` 后将该位置定义为相对 0，并切入 step/multi-turn 模式。
- 2026-06-03：新结构编译验证通过：`colcon build --packages-up-to alicia_d_thinkgrasp_bridge alicia_d_arm_motion alicia_d_sts_gripper alicia_d_pick_coordinator` 完成 5 个包。实际启动 mock ThinkGrasp Bridge 后，`/thinkgrasp/request_grasp` 成功发布标准 `GraspCandidate`。更新后的 `tools/run_control_layer_smoke_test.sh` 仿真通过，Arm Motion Action 完成 `computing_ik -> planning -> executing -> complete`，MoveIt 返回 `success=true`、错误码 `1`。夹爪三个 Action、力矩阈值和完整主控抓取顺序仍需真机验证。
- 2026-06-03：首次真机测试 `/new_gripper/home` Action 返回 `Position response too short`。原因是回零前会连续发送切模式、扭矩和目标位置写命令，STS3215 可能为这些写命令返回空参数 ACK；原 `read_registers()` 把下一个状态包直接当作寄存器查询结果，因此会把残留 ACK 误认为位置数据。已修改 `sts3215_bus.py`：寄存器读取会跳过参数长度不足的状态包，直到收到请求长度的数据。

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

再启动 mock ThinkGrasp Bridge：

```bash
cd ~/HET/alicia_ws
source install/setup.bash
ros2 launch alicia_d_thinkgrasp_bridge mock_thinkgrasp_bridge.launch.py
```

请求一条抓取候选：

```bash
ros2 service call /thinkgrasp/request_grasp std_srvs/srv/Trigger "{}"
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

项目内也有 WSL 侧 attach 脚本，默认依次尝试夹爪 `2-3` 和机械臂主控 `2-5`：

```bash
alicia_ws/tools/attach_alicia_usb_to_wsl.sh
```

如果 busid 变化：

```bash
alicia_ws/tools/attach_alicia_usb_to_wsl.sh <BUSID>
```

2026-06-02 反馈链路排查记录：

- 现象：真机可由 RViz/MoveIt 下发目标并运动，但 `/joint_states` 和 `/Alicia_controller/controller_state.actual` 保持 `initial_positions.yaml` 的值。
- 已确认：`joint_state_broadcaster`、`Alicia_controller`、`Gripper_controller` 均为 active；`ros2_control_node` 确实打开 `/dev/ttyACM0`。
- 停止 `real_robot.launch.py` 释放串口后，独立运行 `alicia_feedback_diag.py`：
  - `alicia_feedback_20260602_154605`：version/self_check 可读，self_check=`0x01FF` bit_9 fault，joint raw 30/30 全 0。
  - USBIPD detach/attach 后复测 `alicia_feedback_20260602_154702`：joint raw 仍全 0。
  - `--include-extra` 复测 `alicia_feedback_20260602_154723`：temperature/velocity timeout，joint raw 仍全 0。
- 当前判断：这次不是 MoveIt/RViz 显示问题，也不是 ros2_control 过滤 alone；底层主控通信可用，但舵机/关节反馈链路当前没有有效数据。下一步优先做单变量物理恢复：只重启机械臂电源/电机电源，暂不改 USB、夹爪和代码，然后复测同一条诊断命令。

真机 MoveIt 启动示例：

```bash
cd ~/HET/alicia_ws
source install/setup.bash
ros2 launch alicia_d_moveit real_robot.launch.py gripper_type:=50mm speed_deg_s:=5
```

真机安全提醒：

- 第一次执行任何新动作，手要放在急停或电源开关旁。
- `Ctrl+C` 不是硬件急停。
- 当前 open-loop 状态下，断电、急停、手动拖动后，软件状态会和真实状态不一致。
- 顶层 `readme` 里有一个已验证的低速安全抬升 `/joint_commands`，真机测试前优先参考它。

## 当前控制链路摘要

- ThinkGrasp / mock 输出：`xyz + rot + dep`
- ThinkGrasp Bridge：`alicia_d_thinkgrasp_bridge`，只请求、校验并发布 `GraspCandidate`
- 主控节点：`alicia_d_pick_coordinator`，生成 `pre_grasp/grasp/lift` 并调度机械臂与夹爪 Action
- 机械臂动作节点：`alicia_d_arm_motion`，封装 MoveIt 规划和执行
- MoveIt 路径：抓取位姿 -> `/compute_ik` -> `/plan_kinematic_path` -> `/execute_trajectory`
- 机械臂控制器：`Alicia_controller`，控制 `Joint1` 到 `Joint6`
- Alicia-D 原模型夹爪控制器：`Gripper_controller`，控制 `Gripper`；保留在原 MoveIt/ros2_control 模型中，但机械臂桥不再调用它
- 新 STS3215 夹爪节点：`alicia_d_sts_gripper`，独立提供 home、move_relative、move_step、force_grasp Action 和持续状态
- 底层发送：`AliciaDHardwareInterface::write()` -> `AliciaDDataParserControl::set_joint_and_gripper()` -> 串口帧
- 串口协议：`1000000` baud，控制帧大致为 `AA 06 03 1C ... checksum FF`

2026-06-03 STS3215 回零后相对移动排查：

- `/new_gripper/home` 曾因残留写指令空 ACK 被误认为位置响应，报
  `Position response too short`；`read_registers()` 已改为跳过短 ACK。
- 随后 `/new_gripper/move_relative` 报 `STS3215 status error 0x20`。
  `0x20` 是 STS3215 的 overload 告警，最可能由 `home_raw=0` 对应最大打开
  机械止挡、回零后继续保持力矩导致。
- `sts3215_bus.py` 现在会把状态错误码解码为可读名称，并在寄存器读取时跳过
  属于更早写指令的短错误 ACK，避免把旧告警错误归因到下一次读取。
- 夹爪 YAML 新增 `torque_off_after_home: true`：回零完成、切换到 Step 模式后
  默认关闭保持力矩；后续 move/force_grasp Action 会在发送动作前重新开启力矩。
- 用户确认当前硬件策略为只阻断 STS3215 `angle` 状态错误。底层总线现仅在
  状态码包含 `0x10 (angle)` 时抛异常；`overload`、电压、传感器、温度和电流
  状态位不会再让夹爪 Action 失败。
- 随后 `/new_gripper/move_relative` 报 `Write timeout`。这不是舵机状态错误：
  当时 WSL 中 `/dev/serial/by-id` 和 `/dev/ttyACM*` 已消失，`dmesg` 在
  `2026-06-03 18:08:29` 记录多次 `vhci_hcd urb->status -104`，说明 usbipd
  USB 连接被重置。Windows 侧仍显示 `2-3 Attached`，属于假挂载状态；需要停止
  持有旧串口句柄的夹爪 launch，对 `2-3` detach 后再 attach。
- 夹爪节点已增强串口恢复：底层写失败会带上端口路径；任何状态读取或 Action
  串口异常都会关闭失效句柄，设备重新 attach 后后续读取可重新打开 by-id 路径。
- 用户重新 attach 后仍遇到 `Write timeout`。进一步确认原实现把读超时
  `serial_timeout_s=0.12` 同时传给 pyserial `write_timeout`，对 WSL + CH343
  写入过于激进；并且 `vhci_hcd -104` 也可能来自读超时取消 USB 请求，不能单独
  作为断连结论。现已拆分 `serial_write_timeout_s=1.0`，读超时仍为 `0.12s`。
  Step 相对运动命令不做自动重发，避免实际已发送成功时重复移动。
- 夹爪节点启动时曾出现一次 `State read failed: Timed out waiting for STS3215
  packet header`。当时夹爪 by-id 串口存在，且没有重复夹爪节点占用串口；停止
  ROS 节点后直接读取成功，得到 `raw_position=4`、`moving=false`、
  `voltage_v=4.9`、`temperature_c=31`、`current_raw=0`。随后短时启动夹爪节点
  约 12 秒未复现，当前判断为启动瞬间或 USB 调度导致的偶发读超时，而不是持续
  的端口、baudrate、servo_id 或舵机反馈链路故障。若普通 12V ST3215 长期反馈
  约 `4.9V`，应检查供电是否低于其规格范围。
- 用户在夹爪到达 `4700 ticks` 后误用 home 作为张开动作，舵机切回普通位置模式
  后到达第二圈的 `raw=0`。这证明多圈 Step 模式下 `raw=0` 不是全局唯一机械
  参考；home 只能在已知真实最大打开位置附近用于确认和建立软件零点，不能从任意
  多圈位置可靠找回最大打开位置。已知零点时张开应使用 `move_relative` 的
  `target_ticks=0`。
- 新增 `MoveGripperStep` Action 和 `/new_gripper/move_step`：只检查舵机当前
  处于 Step 模式，从当前位置执行 `delta_ticks` 增量运动，不要求 home。该动作
  绕过绝对软件坐标安全范围，因此会将 `homed=false`；之后必须重新确认真实最大
  打开位置并 home，才能继续使用 `move_relative` 绝对目标和 `force_grasp`。
  当前从第二圈 `raw=0` 回到第一圈真实开口的理论恢复命令为低速 `-4096 ticks`，
  执行前必须确认负方向确实是张开方向。
- 主控触发方式改为“候选即任务”：每当 `/thinkgrasp/grasp_candidate` 发布一条
  新候选，`alicia_d_pick_coordinator` 直接执行一次
  `pre_grasp -> open -> grasp -> force_grasp -> lift`。主控不再调用
  `/thinkgrasp/request_grasp`，也删除了旧 `/pick_coordinator/execute_pick`
  Action 和 `ExecutePick` 接口。抓取执行中收到的后续候选会被忽略，不排队。
  Bridge 与主控的候选 QoS 改为 `VOLATILE`，避免主控重启时因历史候选回放而运动。
- 新增固定抓取后中间位姿配置
  `alicia_d_pick_coordinator/config/waypoints.yaml`。用户要求记录顺序为
  `Joint2, Joint3, Joint1, Joint4, Joint6, Joint5`，角度单位为弧度；默认使用
  6 个 `.nan` 占位符，主控在值未填写完整时不会开始抓取。
- 新增 `/arm_motion/move_to_joints` 和 `MoveArmToJoints` Action，关节目标仍由
  独立机械臂动作节点封装 MoveIt 规划和执行。抓取流程现为
  `pre_grasp -> open -> grasp -> force_grasp -> lift -> post_grasp_intermediate`。
- 完整控制层启动后未自动 home 的一次原因是
  `alicia_d_pick_coordinator/config/waypoints.yaml` 填写错误：第一项负数缺少
  YAML 列表项所需的空格，写成了 `-0.007...`；同时把 `Gripper` 的第 7 个位置
  也填入了只应包含 6 个机械臂关节的位置列表。ROS 在加载参数文件阶段直接令
  `pick_coordinator` 退出，自动 home 尚未开始。该配置必须只填写
  `Joint2, Joint3, Joint1, Joint4, Joint6, Joint5` 六个弧度值，负数格式应为
  `- -0.123`。
- Alicia-D 机械臂反馈链路仍有待后续解决的问题：`ros2_control_node` 日志持续
  出现主控返回的 `overheat` / `overheat_protect`。驱动会接受 `0xE1 overheat`
  的位置，但对 `0xE2 overheat_protect` 整帧反馈不更新并保持上一次状态，因此
  `/joint_states`、`Alicia_controller` 和 MoveIt 可能看到旧位置。反馈帧时间戳
  使用 `std::chrono::steady_clock`，硬件接口检查使用 `RCL_STEADY_TIME`，日志中
  出现约 `-80 s` 的负反馈年龄，说明当前超时判断也不可靠。需要后续确认 Alicia-D
  固件状态码、温度/保护原因，并统一反馈时间基准。
- 第二次完整抓取测试中，机械臂成功执行到 `grasp`，但 `force_grasp` 在约
  `12 s` 后因未检测到接触而停止，未执行 `lift` 和中间位姿。用户实测当前夹爪
  在夹取受力方向上 `load_raw` 会从约 `1000` 向上增加，决定使用本机经验原始值
  `load_raw >= 1048` 作为夹取成功条件。夹爪配置现为
  `force_load_threshold_raw: 1048`、`force_current_threshold_raw: 0`，判断逻辑
  直接比较原始 `load_raw`；更换舵机、安装方向、夹爪机构或供电条件后必须重新
  标定。
- 2026-06-04 最新完整抓取日志表明，主控并非未等待夹爪：主控在
  `force_grasp` Action 返回成功后才进入 `moving_lift`。本次夹爪在发送朝
  `4700 ticks` 的闭合命令后约 `59 ms` 就令 Action 成功；由于电流阈值为 `0`，
  该成功只能来自 `load_raw >= 1048`，说明运动起始瞬态或机构自身阻力已提前触发
  当前阈值，夹爪尚未真正夹紧时主控就开始抬升。随后夹爪仍继续到 `4700 ticks`，
  原因是当前 `_stop_motion_locked()` 在 Step 模式发送 `delta_ticks=0`，该命令
  很可能只是“再移动 0 ticks”，不能取消先前已下发的 `4700 ticks` 运动。后续需
  同时解决接触判定去抖/最小闭合行程和真正停止正在执行的 Step 运动。
- 用户用调试软件确认单独依赖扭矩/load 不可靠，先不加最小闭合行程，改为
  `load_raw >= 1100` 且 `abs(current_raw) >= 7` 连续满足 8 次才判定
  `force_grasp` 成功。若效果仍不好，再考虑加入夹爪位置变化速度明显变慢的条件。
- 夹爪 home 逻辑改为手动标定：`/new_gripper/home` 不再自动移动到
  `home_raw=0`，只切换到 Step/Multi-turn 模式并把当前物理位置定义为
  `relative_ticks=0`。新增 `tools/sts3215_gripper_manual_home.py`，通过 ROS
  Action 左右点动 `/new_gripper/move_step`，用户把夹爪调到真实最大打开角度后按
  `z`/回车调用 `/new_gripper/home` 确认零点。`home_raw=0` 不再作为自动回零目标。
- 手动 home 工具方向键点动无效时，优先怀疑终端方向键 ESC 序列解析而不是 WSL
  完全没收到键盘。`tools/sts3215_gripper_manual_home.py` 和旧的
  `tools/sts3215_gripper_manual_calibrate.py` 已改为支持更长的方向键序列，例如
  `ESC [ 1 ; 5 D`；仍保留 `a/d` 作为左右点动备用键，`+/-` 作为步长备用键。
- 手动 home 点动时，用户反馈 `a/d` 能动几下后出现
  `Jog failed: move_step result timed out`，随后 `move_step goal rejected`。
  原因是旧 `/new_gripper/move_step` 会等待反馈累计移动量精确达到每次点动 ticks；
  STS3215 Step/Multi-turn 模式下 `raw_position` 可能带高位编码，例如 `32770`，
  不适合作为手动点动完成判据。已把 `move_step` 改成命令式点动：写入相对 step
  命令并短暂确认通信后立即返回成功，手动工具超时也会主动 cancel 上一个 goal。
  该改动已通过 `colcon build --packages-select alicia_d_sts_gripper`。
- 用户查阅飞特 STS 舵机资料后确认：多圈模式仍应反馈当圈 `0..4095` 位置，
  程序通过跨 `0/4095` 跳变累计圈数。因此不能简单认为 STS3215 多圈反馈不可用；
  当前 `state` 一直读到同一个值需要单独诊断。新增
  `tools/record_gripper_debug_state.py`，只订阅 `/new_gripper/state` 并记录到
  `experiment_logs/gripper_debug_state/`，字段包括原始 16 位、低 12 位当圈位置、
  signed16、低 12 位跳变累计、节点 `relative_ticks`、moving/load/current/fault。
  该工具用于用户点动舵机后分析是反馈寄存器没变、解析错误、旧包干扰还是保护/堵转。
- 2026-06-04 用户采集的夹爪反馈日志
  `experiment_logs/gripper_debug_state/gripper_debug_20260604_143305` 显示：
  326 个样本、约 42 秒；`raw_position` 并非完全固定，主要在 `0x8001..0x801E`
  间变化，高位 `0x8000` 基本一直存在；低 12 位 `position_in_turn_12bit` 范围
  为 `0..30`，点动期间会出现约 `+20` tick 的跳变并伴随 `moving=True`、
  load/current 上升，说明地址 56 的当圈位置反馈有响应。`node_relative_ticks`
  一直为 0 是因为当时 `homed=False`，当前代码在未 home 时故意只更新
  `_last_encoder_mod`，不累计相对位姿。日志中也出现少量异常样本，例如
  current_raw=8313、load_raw=32769、一次 `State read failed: Timed out waiting
  for STS3215 packet header`，提示多寄存器分次读取仍可能受残留包/超时影响，后续需
  加强原始反馈解析和状态读取健壮性。
- 2026-06-04 用户又采集了从最大打开到最大闭合的夹爪日志
  `experiment_logs/gripper_debug_state/gripper_debug_20260604_150713`。该日志 461
  个样本、约 56 秒，`position_in_turn_12bit` 范围 `0..323`，但不是随真实开合
  单调累积；每次 step 命令开始时会跳到约 `321/162/81`，随后在 `moving=True`
  期间按约 `-20 tick/sample` 下降到 `1..3` 并停止。这更像 STS3215 Step 模式下
  地址 56 返回“本次 step 命令的剩余量/执行进度”，不适合作为夹爪绝对开合位置
  或多圈累计控制量。`moving` 可用于判断单次 step 命令是否结束；`load_raw` 在
  夹紧/受力阶段稳定约 `1048..1132`，比 `current_raw` 更适合做接触/夹取判定；
  `current_raw` 大多为 `0..2`，偶发 `8825` 且伴随 `voltage=0/temp=0`，应视为
  错包/无效样本并过滤。
- 用户提供官方寄存器说明：地址 `56` 在普通模式反馈当前位置，BIT15 为方向位；
  在步进模式 3 返回当前位置与目标位置的步进差值，BIT15 为方向位。地址 `67`
  为当前目标位置。因此当前读取地址 56 的小端 2 字节逻辑没有明显问题，但把它在
  Step 模式下当绝对位置使用是错误的。为验证能否用 `target_position ± error`
  推回当前位置，已扩展 `GripperState.msg`：新增 `target_position`、
  `position_error_direction`、`position_error_ticks`、`estimated_position_minus`
  和 `estimated_position_plus`；夹爪节点新增读取地址 `67`，调试记录工具也将这些
  字段写入 `experiment_logs/gripper_debug_state/`。已重编
  `alicia_d_control_interfaces` 和 `alicia_d_sts_gripper`。
- 2026-06-04 用户采集闭合到打开方向日志
  `experiment_logs/gripper_debug_state/gripper_debug_20260604_162128`。`target_position`
  从约 `3995` 逐步降到 `1275`，变化幅度约 `2720 ticks`，与真实开合运动方向和范围
  对得上；每段运动中 `target_position` 连续变化，`position_error_ticks` 从较大值
  降到 `1..6`，`moving` 变为 false 后停止。结论：地址 `67 target_position`
  当前最适合作为夹爪位置反馈/控制量；地址 `56 position_error_ticks` 适合作为本次
  step 命令剩余误差和完成判定。`estimated_position_minus/plus` 不适合作为当前
  位置：在长 step 段里 `minus` 近似最终目标，`plus` 偏离较大。日志中样本 150、151
  出现 `target=0/load=3035`、`raw=0x2079/err=8313/load=32770` 这类明显错包或分次
  读取不一致，后续控制应对 target/load/current/voltage/temp 做有效性过滤。
- 2026-06-04 用户又采集闭合方向日志
  `experiment_logs/gripper_debug_state/gripper_debug_20260604_163028`。本次所有样本
  `position_error_direction=False`，其中 `moving=True` 的 40 个样本也全部为
  `False`；上一条打开方向日志中运动段基本为 `True`。因此地址 56 的 BIT15 方向位
  确实随方向变化：当前硬件上闭合方向为 `False`，打开方向为 `True`。本次
  `target_position` 从 `1755` 经过 `1912`、`2528` 到 `2555`，随闭合方向上升；
  `position_error_ticks` 在运动段从约 `162` 下降到 `2..38`，仍可用作本次 step
  完成误差。后续可把 `target_position` 作为位置反馈主量，结合
  `position_error_direction` 判断方向和 `position_error_ticks + moving` 判断完成。
- 2026-06-04 用户采集完整开合到闭合日志
  `experiment_logs/gripper_debug_state/gripper_debug_20260604_164701`。`target_position`
  从约 `955` 连续上升到 `5360`，正常跨过 `4095` 后没有真实跳变；样本 236/237
  出现 `4735 -> 0 -> 4735` 且 load/current 等字段同步异常，判断为错包或分次读取
  不一致，不作为多圈跳变处理。注意：运动停止且误差很小时
  `target_position ~= current_position`，但运动中不能直接把 target 当 current。
  当前 STS3215 Step/Multi-turn 模式下，夹爪控制位置应先用地址 67 的
  `target_position` 和地址 56 的误差推算当前位置：打开方向
  `position_error_direction=True` 时 `current_position = target_position +
  position_error_ticks`；闭合方向 `False` 时 `current_position =
  target_position - position_error_ticks`。相对位置采用
  `relative_ticks = current_position - zero_feedback_position`。
  `zero_feedback_position` 由手动最大打开标定得到，动作完成判定采用
  `relative_ticks` 接近目标、`position_error_ticks <= tick_tolerance` 且
  `moving=false`，不使用固定秒数等待。
- 夹爪节点已按上述结论改造：新增 YAML 参数 `manual_home_valid`、
  `zero_feedback_position`，并保留 `zero_target_position` 作为兼容/调试字段；启动夹爪节点后不会自动回 0，但若
  `manual_home_valid=true` 会认为已具备持久化零点。`/new_gripper/home` 只把当前
  物理位置确认为相对 `0`，并读取当前反馈估计位置作为零点；直接调用 Action
  不写 YAML。`tools/sts3215_gripper_manual_home.py` 点动到最大打开后按 `z`/回车会
  同时调用 home 并把 `manual_home_valid: true`、`zero_feedback_position: <当前反馈估计位置>`
  写入源码 YAML 和当前 install YAML，同时写入 `zero_target_position` 便于日志对照。`move_relative` 之后可直接用
  `target_ticks`，例如 `target_ticks: 2000`。
- 主控 `pick_coordinator` 也已调整：`initialize_gripper_on_start` 默认和 YAML 都为
  `false`，完整控制层启动时不再自动 home。抓取流程启动后，主控先让机械臂到
  `pre_grasp`，再向夹爪发送 `move_relative 0` 确认最大打开位，然后进入
  `grasp`、`force_grasp`、`lift`、抓取后中间位姿。这样比赛中重启节点时，只要
  之前已手动标定并写入 YAML，就不需要重新手动 home。
- 夹爪 `force_grasp` 成功接触后的停止逻辑已从旧的 `delta_ticks=0` 改为
  stop-and-hold 反向补偿：检测到 `load/current` 连续满足阈值后，节点用当前
  `target_position`、`position_error_ticks` 和方向位推算 `current_position`，
  计算 `remaining_ticks = target_position - current_position`，再发送
  `stop_delta = -remaining_ticks` 的 Step 命令，把旧闭合目标拉回当前位置附近。
  停止后保持 `torque on`，不释放夹爪。日志会输出
  `current_position/target_position/remaining_ticks/stop_delta`，用于判断补偿方向和
  停止命令是否生效。该改动已通过
  `colcon build --packages-select alicia_d_sts_gripper`。
- 用户反馈夹取测试中成功判定总体可用，但偶尔会在未受阻力时停下。已给
  `force_grasp` 增加异常样本过滤和“位置推进变慢”条件。异常过滤包括：
  `voltage_v < force_min_valid_voltage_v`、`temperature_c <
  force_min_valid_temperature_c`、缺少 load/current、以及相邻有效样本中
  `load/current` 跳变超过 `force_max_*_jump_raw`；异常样本不报错，也不计入连续
  夹取成功计数，且不清空已有连续计数。变慢条件使用最近 `force_slow_window_samples` 个有效样本的
  `relative_ticks` 净变化，默认 6 帧、`poll_period_s=0.05`，即约 0.3 秒内推进不超过
  `force_slow_max_delta_ticks=25` 才认为夹爪顶住/变慢。当前源码 YAML 又经用户调参：
  `zero_feedback_position: 3823`、`max_closed_ticks: 4600`、
  `force_grasp_speed: 300`、`force_current_threshold_raw: 1`、
  `force_load_threshold_raw: 1150`、`force_contact_confirm_samples: 5`、
  `force_require_slowdown: false`、`goal_timeout_s: 25.0`，并保留
  `force_max_load_jump_raw: 500`、`force_max_current_jump_raw: 500`。
  已通过 `colcon build --packages-select alicia_d_sts_gripper`。
- 新增夹爪文档：
  `alicia_ws/src/alicia_d_sts_gripper/gripper_readme.md`。文档已改为中文，并按用户要求
  将“抓取测试流程”整理为连续步骤：启动夹爪节点、手动标定最大打开零点、回到
  `move_relative 0`、执行 `force_grasp`；抓取成功判定逻辑紧跟测试抓取命令之后，
  文件结构章节放在工作流程之前。内容还包括当前 YAML 参数、Step 模式位置计算、
  stop-and-hold 反向补偿和调试日志。`CMakeLists.txt` 已增加文档安装规则，重编后安装到
  `install/alicia_d_sts_gripper/share/alicia_d_sts_gripper/gripper_readme.md`。

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
