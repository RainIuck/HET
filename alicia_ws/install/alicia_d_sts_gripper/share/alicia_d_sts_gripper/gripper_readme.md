# Alicia-D STS3215 夹爪说明

这个包负责新 STS3215 夹爪的 ROS 2 控制。夹爪节点独立占用串口，持续发布夹爪状态，并提供回零标定、相对位置移动、点动和力反馈夹取 Action。

## 当前配置

配置文件：

```text
src/alicia_d_sts_gripper/config/sts3215_gripper.yaml
```

当前关键参数：

```yaml
port: /dev/serial/by-id/usb-1a86_USB_Single_Serial_5B79032424-if00
baudrate: 1000000
servo_id: 1

manual_home_valid: true
zero_feedback_position: 3823
zero_target_position: 3823

open_ticks: 0
max_closed_ticks: 4600
max_safe_ticks: 4700

force_grasp_speed: 300
force_current_threshold_raw: 0
force_load_threshold_raw: 100
force_contact_confirm_samples: 2

force_require_slowdown: true
force_slow_window_samples: 6
force_slow_max_delta_ticks: 25
force_emergency_load_threshold_raw: 125
force_emergency_current_threshold_raw: 0

force_min_valid_voltage_v: 1.0
force_min_valid_temperature_c: 1
force_max_load_jump_raw: 0
force_max_current_jump_raw: 0

goal_timeout_s: 25.0
poll_period_s: 0.05
serial_timeout_s: 0.20
```

`manual_home_valid` 和 `zero_feedback_position` 是标定结果。机械结构、夹爪安装位置或最大打开参考变化后，需要重新标定。

## 抓取测试流程

下面流程包含启动节点、手动标定、回到打开位和执行夹取测试。第一次测试、重新装夹爪、手动改变夹爪位置后，都按这个完整流程来。

终端 1：启动夹爪节点。

```bash
cd /home/Projects/HET/alicia_ws
source install/setup.bash
ros2 launch alicia_d_sts_gripper sts3215_gripper.launch.py
```

终端 2：手动标定最大打开零点。

```bash
cd /home/Projects/HET/alicia_ws
source install/setup.bash
python3 tools/sts3215_gripper_manual_home.py
```

标定工具按键：

```text
a / d       左右点动夹爪
+ / -       增大/减小点动步长
z 或回车    确认当前最大打开位置为相对 0
h           切到 Step 模式，并把当前位置设为临时 0
q           退出
```

用 `a/d` 把夹爪点动到真实最大打开位置后，按 `z` 或回车。工具会把标定结果写入源码 YAML 和当前 install YAML：

```yaml
manual_home_valid: true
zero_feedback_position: <当前反馈估计位置>
zero_target_position: <当前 target_position，仅用于调试/兼容>
```

标定完成后，让夹爪回到相对打开位 `0 ticks`。

```bash
ros2 action send_goal /new_gripper/move_relative \
  alicia_d_control_interfaces/action/MoveGripper \
  "{target_ticks: 0, speed: 0}" \
  --feedback
```

执行夹取测试。

```bash
ros2 action send_goal /new_gripper/force_grasp \
  alicia_d_control_interfaces/action/ForceGrasp \
  "{current_threshold_raw: 0, max_ticks: 0, speed: 0}" \
  --feedback
```

Action 请求里的 `0` 表示使用 YAML 默认值：

```text
current_threshold_raw: 0 -> force_current_threshold_raw
max_ticks: 0             -> max_closed_ticks
speed: 0                 -> force_grasp_speed
```

按当前 YAML，夹取测试实际使用：

```text
current_raw 条件关闭
load_raw >= 100
推进变慢条件开启
连续 2 个有效样本
最大闭合目标 = 4600 ticks
夹取速度 = 300
超时时间 = 25 s
```

如果需要单独测试相对位置，可以用：

```bash
ros2 action send_goal /new_gripper/move_relative \
  alicia_d_control_interfaces/action/MoveGripper \
  "{target_ticks: 2000, speed: 0}" \
  --feedback
```

`move_relative` 用于普通张开、释放和移动到指定相对位置，不应用
emergency load/current 阈值。这样回到最大打开位 `0 ticks` 时，即使电机在张开方向
短时出力，也不会被误判为夹取接触。emergency 阈值只在 `force_grasp` 闭合夹取流程中
生效。

再回到打开位：

```bash
ros2 action send_goal /new_gripper/move_relative \
  alicia_d_control_interfaces/action/MoveGripper \
  "{target_ticks: 0, speed: 0}" \
  --feedback
```

查看实时状态：

```bash
ros2 topic echo /new_gripper/state
```

关键字段：

```text
homed                 是否已经有有效最大打开零点
relative_ticks        相对最大打开零点的当前位置估计
raw_position          STS 地址 56；Step 模式下是位置误差，不是绝对角度
target_position       STS 地址 67 当前目标位置
position_error_ticks  地址 56 中的当前位置/目标位置误差
load_raw              当前控制输出驱动电机的电压占空比幅值，单位 0.1%；已剥离 STS BIT10 方向位
current_raw           舵机电流反馈
moving                舵机运动标志
fault                 节点最近一次故障信息
```

## 抓取成功判定逻辑

`force_grasp` 会先让夹爪朝 `max_closed_ticks` 闭合，然后持续读取反馈并判断是否夹到物体。

每个反馈样本会先做有效性过滤。以下样本会被忽略：

```text
voltage_v < force_min_valid_voltage_v
temperature_c < force_min_valid_temperature_c
缺少 load/current 反馈
force_max_load_jump_raw > 0 且 load 相对上一个有效样本跳变过大
force_max_current_jump_raw > 0 且 current 相对上一个有效样本跳变过大
```

异常样本只是不计入成功次数，不会清空已经累计的连续成功次数。当前默认将
`force_max_load_jump_raw` 和 `force_max_current_jump_raw` 设为 `0`，即关闭跳变过滤；
对夹爪安全来说，高 load/current 应优先触发早停，而不应因为跳变过快被忽略。

对有效样本，当前接触条件是：

```text
force_current_threshold_raw > 0 且 current_raw >= force_current_threshold_raw
或
force_load_threshold_raw > 0 且 load_raw >= force_load_threshold_raw
```

当前 YAML 中：

```text
force_current_threshold_raw = 0
force_load_threshold_raw = 100
force_contact_confirm_samples = 2
force_require_slowdown = true
force_emergency_load_threshold_raw = 125
```

也就是连续 2 个有效样本满足任一已启用的力反馈阈值，并且夹爪推进明显变慢，才判定夹取成功。
`force_current_threshold_raw` 为 `0` 时，电流条件关闭，仅作为实时观测量；当前默认
使用 load + slowdown 判定。这里的 `load_raw` 是剥离 STS BIT10 方向位后的占空比幅值，
单位是 0.1%，不是牛顿或牛米。夹紧方向原始值如果约为 `1080`，
实际负载幅值约为 `1080 - 1024 = 56`，即约 `5.6%` 驱动占空比。
`force_emergency_load_threshold_raw` 是 `force_grasp` 闭合夹取流程中的高负载保护阈值，
达到后不等待 slowdown 条件，也不等待连续样本确认，直接按接触处理并停止。

代码还支持“位置推进变慢”条件：

```text
relative_ticks 在最近 force_slow_window_samples 个有效样本内的净变化
  <= force_slow_max_delta_ticks
```

例如 `poll_period_s=0.05`、`force_slow_window_samples=6` 时，窗口约为 0.3 秒；`force_slow_max_delta_ticks=25` 表示这 0.3 秒内夹爪推进不超过 25 ticks 才算明显变慢。

当前 YAML 中：

```yaml
force_require_slowdown: true
```

所以普通接触判断要求 load/current 任一阈值连续满足，并且夹爪推进明显变慢。
若达到 emergency 高负载阈值，则不等待变慢条件。

如果 Action 返回：

```text
success: false
contact_detected: false
message: Force grasp timed out without contact
```

表示在 `goal_timeout_s` 时间内没有满足完整成功条件。例如 load 没有达到
`force_load_threshold_raw`，就不会判定成功。

## 文件结构

```text
alicia_d_sts_gripper/
  config/sts3215_gripper.yaml         运行参数
  launch/sts3215_gripper.launch.py    夹爪节点启动文件
  scripts/gripper_action_node.py      ROS 节点和 Action 逻辑
  alicia_d_sts_gripper/sts3215_bus.py STS3215 串口协议
  gripper_readme.md                   本文档

../../tools/sts3215_gripper_manual_home.py  手动最大打开零点标定工具
../../tools/record_gripper_debug_state.py   夹爪状态日志记录工具
```

修改源码 YAML 或文档安装规则后，重新编译：

```bash
cd /home/Projects/HET/alicia_ws
source /opt/ros/humble/setup.bash
colcon build --packages-select alicia_d_sts_gripper
```

launch 文件加载的是 install 目录中的 YAML。手动标定工具会同时写源码 YAML 和当前 install YAML，所以仅标定零点时不需要重新编译。

## 工作流程

夹爪节点在 ROS 结构中独立于机械臂运行：

```text
STS3215 串口
  -> /new_gripper/sts3215_gripper 节点
    -> /new_gripper/state topic
    -> /new_gripper/joint_states topic
    -> /new_gripper/home action
    -> /new_gripper/move_relative action
    -> /new_gripper/move_step action
    -> /new_gripper/force_grasp action
```

完整抓取流程中，主控节点通常按这个顺序调度：

```text
1. 夹爪节点启动，并加载 YAML 中保存的最大打开零点。
2. 主控收到抓取候选。
3. 机械臂运动到 pre_grasp。
4. 主控发送 move_relative 0，让夹爪确认回到最大打开位。
5. 机械臂运动到 grasp。
6. 主控发送 force_grasp。
7. 夹爪闭合并持续判断 load/current。
8. 判断夹取成功后，夹爪执行 stop-and-hold。
9. 机械臂继续 lift 和后续中间位姿。
```

## 位置反馈逻辑

STS3215 在 Step 模式下，地址 56 不是普通绝对角度。根据官方说明，地址 56 返回的是当前位置与目标位置的步进差值，并带方向位；地址 67 是当前目标位置。

节点用下面的方式估计当前位置：

```text
position_error_direction=True:
  current_position = target_position + position_error_ticks

position_error_direction=False:
  current_position = target_position - position_error_ticks

relative_ticks = current_position - zero_feedback_position
```

运动结束且 `position_error_ticks` 很小时，`target_position` 可以近似看作当前位置。运动过程中不能直接把 `target_position` 当当前位置。

## 停止保持逻辑

`force_grasp` 判定成功后，节点不会关闭力矩，而是执行 stop-and-hold。

停止命令会根据当前反馈计算还剩多少目标距离：

```text
remaining_ticks = target_position - current_position
stop_delta = -remaining_ticks
```

然后发送反向补偿 step，把原来的远处闭合目标拉回到当前位置附近。停止后保持 `torque on`，用于继续夹持物体。

夹爪节点终端会输出：

```text
Stop-and-hold command sent:
current_position=...
target_position=...
remaining_ticks=...
stop_delta=...
```

如果夹取成功后仍继续闭合，优先看这几项，判断补偿方向和幅度是否正确。

## 调试日志

记录 `/new_gripper/state` 到实验日志：

```bash
cd /home/Projects/HET/alicia_ws
source install/setup.bash
python3 tools/record_gripper_debug_state.py
```

日志目录：

```text
experiment_logs/gripper_debug_state/
```

调阈值、分析误判和分析夹取失败时，优先记录这份日志。
