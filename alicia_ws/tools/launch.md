# Alicia-D Control Layer Launch Notes

本文档记录当前 `control2` 分支下常用编译、启动、真机串口和工具命令。默认工作目录是：

```bash
cd /home/Projects/HET/alicia_ws
```

## 1. 编译和环境

首次或改了源码后编译整个工作区：

```bash
source /opt/ros/humble/setup.bash
colcon build
source install/setup.bash
```

只改了 Alicia-D driver / MoveIt 控制层时：

```bash
source /opt/ros/humble/setup.bash
colcon build --packages-up-to alicia_d_driver alicia_d_moveit
source install/setup.bash
```

只改了新夹爪包时：

```bash
source /opt/ros/humble/setup.bash
colcon build --packages-up-to alicia_d_sts_gripper
source install/setup.bash
```

只改了新控制层结构时：

```bash
source /opt/ros/humble/setup.bash
colcon build --packages-up-to \
  alicia_d_thinkgrasp_bridge \
  alicia_d_arm_motion \
  alicia_d_sts_gripper \
  alicia_d_pick_coordinator
source install/setup.bash
```

每个新终端运行 ROS 命令前都要 source：

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash
```

## 2. 串口约定

机械臂主控和新夹爪是两个独立 USB 串口：

```text
机械臂主控: /dev/serial/by-id/usb-1a86_USB_Single_Serial_5B14041395-if00
新夹爪:     /dev/serial/by-id/usb-1a86_USB_Single_Serial_5B79032424-if00
```

Windows 侧 `COM4`、`COM7` 只是 Windows 设备名，ROS 不使用它。WSL attach 使用 `BUSID`，ROS 和工具使用 Linux 的 `/dev/serial/by-id/...`。

当前常用 busid：

```text
2-3: 新夹爪 CH343 USB 串口
2-5: Alicia-D 机械臂主控 USB 串口
```

attach 到 WSL：

```bash
tools/attach_alicia_usb_to_wsl.sh 2-3
tools/attach_alicia_usb_to_wsl.sh 2-5
```

确认 WSL 串口：

```bash
ls -l /dev/serial/by-id /dev/ttyACM* /dev/ttyUSB* 2>/dev/null
```

取消 attach：

```bash
usbipd.exe detach --busid 2-3
usbipd.exe detach --busid 2-5
```

如果夹爪 Action 报 `Write timeout`，并且 `/dev/serial/by-id` 中的夹爪设备已经
消失，通常是 usbipd USB 连接断开，而不是舵机协议错误。先停止持有旧串口句柄
的夹爪 launch，再重新挂载 `2-3`：

```bash
usbipd.exe detach --busid 2-3
tools/attach_alicia_usb_to_wsl.sh 2-3
```

确认夹爪 by-id 串口重新出现后，再启动夹爪 launch。

如果串口仍存在但 Action 报 `Write timeout`，检查夹爪 YAML 中的写超时配置：

```yaml
serial_timeout_s: 0.20
serial_write_timeout_s: 1.0
```

读写超时已分开。不要自动重发 Step 相对运动指令，因为无法确认第一次写入是否
已经到达舵机，重发可能导致夹爪重复移动。

## 3. 端口配置文件

长期改串口只改 YAML。

机械臂主控端口：

```bash
src/alicia_d_moveit/config/hardware_defaults.yaml
```

新夹爪端口、波特率、舵机 ID、标定值：

```bash
src/alicia_d_sts_gripper/config/sts3215_gripper.yaml
```

夹爪 YAML 顶层使用 `/**`，这是为了让参数在 `/new_gripper/sts3215_gripper` 这种带 namespace 的节点名下也能生效。

注意：ROS launch 默认读 `install/...` 中安装后的配置。改 source YAML 后需要重新编译对应包。

## 4. 真机机械臂启动

真机 MoveIt + ros2_control：

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 launch alicia_d_moveit real_robot.launch.py gripper_type:=50mm
```

调试反馈帧时打开 debug：

```bash
ros2 launch alicia_d_moveit real_robot.launch.py gripper_type:=50mm debug_mode:=true
```

这个 launch 不再接收 `port:=...`。端口来自 `hardware_defaults.yaml`。

检查控制器：

```bash
ros2 control list_controllers
```

读取一次关节状态：

```bash
ros2 topic echo /joint_states --once
```

## 5. 新 STS3215 夹爪

当前夹爪控制策略：

```text
节点启动后只连接设备并发布状态，不自动运动
home Action 不自动移动夹爪
home Action 只切换到 STS3215 step / multi-turn 模式
并把当前物理位置定义为相对 ticks=0
open_ticks=0
max_closed_ticks=4700
```

`max_closed_ticks=4700` 是夹爪允许的最大闭合限制，不是每次抓取都要走到的位置。具体抓取目标应由后续主控节点按任务下发，不放在机械臂桥配置中。

如果实测方向相反，优先把 YAML 中的安全范围改成负方向，例如 `min_safe_ticks=-4700`、`max_safe_ticks=0`。

先确认夹爪 USB 已 attach，且 YAML 中的 by-id 存在：

```bash
tools/attach_alicia_usb_to_wsl.sh 2-3
ls -l /dev/serial/by-id /dev/ttyACM* /dev/ttyUSB* 2>/dev/null
```

手动点动和方向检查：

```bash
python3 tools/sts3215_gripper_manual_calibrate.py
```

点动键位：

```text
Left/Right : 按 step 微调 raw 位置，也可用 a/d
Up/Down    : 增大/减小 step，也可用 +/-
r          : 读取当前 raw
t          : torque on
x          : torque off
q          : 退出
```

如果只想列出当前可见串口：

```bash
python3 tools/sts3215_gripper_manual_calibrate.py --list-ports
```

已确认当前夹爪为 `baudrate=1000000`、`servo_id=1`，正常使用不需要扫描。当前策略不依赖 open/closed raw 标定；这个工具只用于低速点动、读取 raw 和确认方向。

启动夹爪 ROS 节点：

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 launch alicia_d_sts_gripper sts3215_gripper.launch.py
```

查看夹爪持续状态：

```bash
ros2 topic echo /new_gripper/state
```

手动确认最大打开零点：

```bash
python3 tools/sts3215_gripper_manual_home.py
```

该工具通过已经启动的夹爪 ROS 节点控制舵机，不直接占用串口。启动后会先让
`/new_gripper/home` 切换到 Step 模式；使用左右方向键或 `a/d` 点动夹爪到真实
最大打开角度，然后按 `z` 或回车确认当前位置为相对 `0 ticks`。确认后工具会用
地址 67 的 `target_position`、地址 56 的 `position_error_ticks` 和方向位推算
当前反馈位置，并写入夹爪 YAML 的 `zero_feedback_position`；同时保留
`zero_target_position` 作为调试/兼容字段。`manual_home_valid` 会设为 `true`，
后续重启夹爪节点后会直接使用这个零点，不需要重新手动 home。运行中的夹爪节点也会
立即收到本次 home 结果。

如果只想把当前物理位置直接设为 0，也可以手动调用：

```bash
ros2 action send_goal /new_gripper/home \
  alicia_d_control_interfaces/action/HomeGripper "{}"
```

`home` 现在表示“确认当前物理位置就是最大打开零点”，不再自动跑到 `home_raw`。
直接调用该 Action 只会更新当前运行节点，不会写回 YAML；需要持久保存零点时用
`tools/sts3215_gripper_manual_home.py`。默认配置 `torque_off_after_home: true`
会在确认后关闭保持力矩；下一条移动或夹取 Action 会重新打开力矩。

测试移动到相对位置：

```bash
ros2 action send_goal /new_gripper/move_relative \
  alicia_d_control_interfaces/action/MoveGripper \
  "{target_ticks: 2000, speed: 0}"
```

`move_relative` 的 `target_ticks` 是以真实最大打开位置为 `0` 的绝对软件坐标。
当前位置先按 Step 模式反馈推算：

```text
position_error_direction=True  -> current_position = target_position + position_error_ticks
position_error_direction=False -> current_position = target_position - position_error_ticks
relative_ticks = current_position - zero_feedback_position
```

其中 `target_position` 来自 STS3215 地址 67，`position_error_ticks` 和方向位来自地址
56。动作完成不靠固定等待时间，而是同时满足：`relative_ticks` 接近目标、地址 56 的
`position_error_ticks` 小于容差、且 `moving=false`。运动停止后误差很小时，
`target_position` 才可以近似看作当前位置。
已成功 home 后，从闭合位置张开夹爪应发送：

```bash
ros2 action send_goal /new_gripper/move_relative \
  alicia_d_control_interfaces/action/MoveGripper \
  "{target_ticks: 0, speed: 0}"
```

不要用 `home` 代替张开动作。`home` 现在表示“确认当前物理位置就是最大打开零点”。

未建立 home 时，可以在舵机已经处于 Step 模式的前提下执行相对增量动作：

```bash
ros2 action send_goal /new_gripper/move_step \
  alicia_d_control_interfaces/action/MoveGripperStep \
  "{delta_ticks: -100, speed: 200}"
```

`delta_ticks` 表示从当前位置再移动多少 ticks，负数为当前配置下的张开方向。
`move_step` 会使 `homed=false`，执行后不能直接使用绝对软件坐标或力矩夹取。

如果相对零点丢失，可以先用低速 `move_step` 或手动 home 工具找回真实最大打开
位置：

```bash
ros2 action send_goal /new_gripper/move_step \
  alicia_d_control_interfaces/action/MoveGripperStep \
  "{delta_ticks: -4096, speed: 200}"
```

执行前确认张开方向确实为负数，并把手放在电源开关或急停附近。到达真实最大
打开位置后，用 `tools/sts3215_gripper_manual_home.py` 或 `/new_gripper/home`
确认正确的软件零点。

测试力矩反馈夹取。`0` 表示使用夹爪 YAML 中的默认阈值、最大闭合位置和速度：

```bash
ros2 action send_goal /new_gripper/force_grasp \
  alicia_d_control_interfaces/action/ForceGrasp \
  "{current_threshold_raw: 0, max_ticks: 0, speed: 0}"
```

## 6. 新控制层节点

MoveIt demo 仿真：

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 launch alicia_d_moveit demo.launch.py gripper_type:=50mm
```

启动 mock ThinkGrasp Bridge：

```bash
ros2 launch alicia_d_thinkgrasp_bridge mock_thinkgrasp_bridge.launch.py
```

查看一条抓取候选时，先在一个终端等待 topic：

```bash
ros2 topic echo /thinkgrasp/grasp_candidate --once
```

再在另一个终端请求 Bridge 发布候选：

```bash
ros2 service call /thinkgrasp/request_grasp std_srvs/srv/Trigger "{}"
```

候选 topic 使用 `VOLATILE` QoS，不保留历史消息，因此不能在候选发布完成后再
启动 `ros2 topic echo`。

启动独立机械臂动作节点：

```bash
ros2 launch alicia_d_arm_motion arm_motion.launch.py
```

启动主控节点：

```bash
ros2 launch alicia_d_pick_coordinator pick_coordinator.launch.py
```

主控启动时不会自动 home。夹爪零点应先用
`tools/sts3215_gripper_manual_home.py` 手动标定并写入 YAML；之后每当
`/thinkgrasp/grasp_candidate` 发布一条新候选，主控会直接执行一次完整抓取。
抓取流程中，机械臂先到 `pre_grasp`，然后主控向夹爪发送 `move_relative 0`
确认回到最大打开位，再进入 `grasp`、力反馈夹取、`lift` 和抓取后中间位姿。
抓取执行中收到的后续候选会被忽略。

如果 MoveIt、机械臂、夹爪 USB 都已准备好，也可以一次启动 mock Bridge、机械臂动作节点、夹爪节点和主控节点：

```bash
ros2 launch alicia_d_pick_coordinator mock_pick_control.launch.py
```

注意：这个 launch 不启动 MoveIt。真机需要先启动 `real_robot.launch.py`，仿真需要先启动 `demo.launch.py`。

使用 mock Bridge 触发一次完整抓取：

```bash
ros2 service call /thinkgrasp/request_grasp std_srvs/srv/Trigger "{}"
```

该服务只负责让 Bridge 发布一条 mock 候选；候选发布后，主控会自动开始抓取。
不再需要 `/pick_coordinator/execute_pick` Action。

## 7. 抓取后中间位姿

抓取完成后的固定中间位姿使用独立配置文件：

```text
src/alicia_d_pick_coordinator/config/waypoints.yaml
```

把 `/joint_states.position` 中记录到的弧度值填入
`post_grasp_intermediate_joint_positions`。顺序已经固定为：

```text
Joint2
Joint3
Joint1
Joint4
Joint6
Joint5
```

示例：

```yaml
post_grasp_intermediate_joint_positions:
  - 0.0  # Joint2
  - 0.0  # Joint3
  - 0.0  # Joint1
  - 0.0  # Joint4
  - 0.0  # Joint6
  - 0.0  # Joint5
```

填完源码配置后重新编译主控包并重新启动主控：

```bash
colcon build --packages-up-to alicia_d_pick_coordinator
source install/setup.bash
```

主控会在开始抓取前检查 6 个角度是否已填写。配置仍包含 `.nan` 时不会开始抓取。
完整动作顺序为：

```text
pre_grasp -> open -> grasp -> force_grasp -> lift -> post_grasp_intermediate
```

完整结构和各节点职责见项目根目录：

```text
structure.md
```

自动 smoke test，记录仿真实验日志：

```bash
tools/run_control_layer_smoke_test.sh
```

日志目录：

```bash
experiment_logs/simulation/
```

## 8. 反馈诊断工具

独立 Alicia-D 主控反馈诊断，不经过 MoveIt / ros2_control：

```bash
python3 tools/alicia_feedback_diag.py --port /dev/serial/by-id/usb-1a86_USB_Single_Serial_5B14041395-if00 --samples 30
```

包含额外温度/速度查询：

```bash
python3 tools/alicia_feedback_diag.py --port /dev/serial/by-id/usb-1a86_USB_Single_Serial_5B14041395-if00 --samples 30 --include-extra
```

注意：`real_robot.launch.py` 运行时，`ros2_control_node` 会占用机械臂串口，此时不能同时运行独立反馈诊断脚本。

小幅运动反馈测试：

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash
python3 tools/tiny_feedback_motion_test.py
```

反馈诊断日志目录：

```bash
experiment_logs/feedback_diagnostics/
experiment_logs/feedback_motion/
```

夹爪多圈反馈调试记录，不直接占用串口，只订阅 `/new_gripper/state`：

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash
python3 tools/record_gripper_debug_state.py
```

日志目录：

```bash
experiment_logs/gripper_debug_state/
```

记录内容包括：

```text
raw_position_i32
raw_position_u16
raw_position_hex
position_in_turn_12bit
raw_signed16
delta_in_turn
turn_delta_total
node_relative_ticks
target_position
position_error_direction
position_error_ticks
estimated_position_minus
estimated_position_plus
moving
load_raw
current_raw
fault
```

其中 `target_position` 来自 STS3215 地址 `67` 的目标位置；`position_error_ticks`
来自地址 `56` 去掉 BIT15 方向位后的差值。`estimated_position_minus` 和
`estimated_position_plus` 分别是 `target_position - position_error_ticks` 与
`target_position + position_error_ticks`，用于通过日志判断方向位到底应该对应加
还是减。

测试时可同时运行手动 home 工具并用 `a/d` 点动；不要同时运行直接串口标定脚本，
否则会和夹爪节点抢同一个 STS3215 串口。

## 9. 常见问题

端口文件不存在：

```text
could not open port ... No such file or directory
```

先 attach USB，再检查 `/dev/serial/by-id`。这不是 baudrate/id 问题。

能打开端口但等待 STS3215 帧头超时：

```text
Timed out waiting for STS3215 packet header
```

这说明串口文件存在，但舵机没有返回协议包。优先检查夹爪舵机供电、GND、TX/RX 或单线总线接法。

真机反馈诊断和真机 launch 不能同时占用同一个机械臂主控串口。先停止 `real_robot.launch.py`，再运行 `alicia_feedback_diag.py`。
