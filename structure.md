# Alicia-D Control Layer Structure

本文档描述 `control2` 分支控制层的节点边界、ROS 接口和配置归属。

## 总体结构

```text
RGB-D 图像 + 任务文本
        |
        v
ThinkGrasp / Mock ThinkGrasp
HTTP POST /grasp_pose
        |
        | xyz + rot + dep
        v
ThinkGrasp Bridge
alicia_d_thinkgrasp_bridge
        |
        | /thinkgrasp/grasp_candidate
        v
Pick Coordinator
alicia_d_pick_coordinator
        |
        +-----------------------------+
        |                             |
        | MoveArmToPose Action         | Gripper Actions
        v                             v
Arm Motion Server                STS3215 Gripper Node
alicia_d_arm_motion              alicia_d_sts_gripper
        |                             |
        | MoveIt services/actions      | STS3215 serial protocol
        v                             v
MoveIt + ros2_control            New gripper servo
        |
        v
Alicia-D arm
```

公共消息和 Action 定义放在：

```text
alicia_ws/src/alicia_d_control_interfaces
```

节点之间只通过 ROS 消息、Service 和 Action 通信，不互相导入实现代码。

## 节点职责

### ThinkGrasp / Mock ThinkGrasp

负责生成原始抓取结果：

```text
xyz
rot
dep
```

真实实现位于 `ThinkGrasp-main`。测试时使用：

```text
alicia_d_thinkgrasp_bridge/scripts/mock_decision_server.py
```

它不控制机械臂，也不控制夹爪。

### ThinkGrasp Bridge

包：

```text
alicia_d_thinkgrasp_bridge
```

节点：

```text
/thinkgrasp/thinkgrasp_bridge
```

负责：

- 请求 ThinkGrasp HTTP `/grasp_pose`。
- 校验 `xyz` 和 `rot`。
- 将旋转矩阵转换为 ROS 四元数。
- 将结果发布为标准 `GraspCandidate`。
- 保留 `dep` 为 `grasp_depth_m`，当前不参与位姿计算。

不负责：

- 不生成 `pre_grasp`、`grasp`、`lift` 动作序列。
- 不调用 MoveIt。
- 不控制夹爪。

接口：

```text
Service: /thinkgrasp/request_grasp
Topic:   /thinkgrasp/grasp_candidate
```

### Pick Coordinator

包：

```text
alicia_d_pick_coordinator
```

节点：

```text
/pick_coordinator/pick_coordinator
```

负责：

- 启动时调用夹爪 `home` Action 完成初始化。
- 订阅新的抓取候选，并将每条新候选直接作为一次抓取任务。
- 根据任务策略生成 `pre_grasp`、`grasp`、`lift`。
- 按顺序调度机械臂和夹爪。
- 等待每个 Action 的结果，失败时停止后续动作。
- 抓取执行中忽略后续候选，避免并发控制机械臂和夹爪。

当前单次抓取顺序：

```text
home
  -> receive grasp candidate
  -> move arm to pre_grasp
  -> move gripper to open position
  -> move arm to grasp
  -> force grasp until effort threshold
  -> move arm to lift
  -> move arm to post_grasp_intermediate joint waypoint
```

当前 `pre_grasp` 和 `lift` 使用 `base_link` 的 `+Z` 偏移。以后可以在主控中改为沿抓取接近方向偏移。

不负责：

- 不直接调用 MoveIt。
- 不读写机械臂或夹爪串口。
- 不处理 STS3215 raw 编码器换算。

接口：

```text
Input Topic: /thinkgrasp/grasp_candidate
```

候选 topic 使用 `VOLATILE` durability。主控只响应运行期间新发布的候选，不会
在重启时因历史候选回放而自动运动。

### Arm Motion Server

包：

```text
alicia_d_arm_motion
```

节点：

```text
/arm_motion/arm_motion_server
```

负责：

- 接收任意 `PoseStamped` 目标。
- 使用当前 `/joint_states` 作为 IK seed。
- 调用 MoveIt `/compute_ik`。
- 调用 MoveIt `/plan_kinematic_path`。
- 调用 MoveIt `/execute_trajectory`。
- 返回规划或执行结果。

它只理解“移动到目标位姿”，不理解 `pre_grasp`、`grasp`、`lift` 等任务语义。

接口：

```text
Action: /arm_motion/move_to_pose
Action: /arm_motion/move_to_joints
```

`move_to_pose` 用于抓取候选生成的末端位姿。`move_to_joints` 用于固定、安全、可重复
的关节位姿，例如抓取完成后的中间过渡位姿。

### STS3215 Gripper Node

包：

```text
alicia_d_sts_gripper
```

节点：

```text
/new_gripper/sts3215_gripper
```

持续负责：

- 读取并发布舵机原始编码器位置 `raw_position`。
- 发布相对最大打开位置的 `relative_ticks`。
- 发布 `load_raw`、`current_raw`、`moving`、电压、温度和故障状态。

触发任务全部使用 Action：

```text
/new_gripper/home
/new_gripper/move_relative
/new_gripper/move_step
/new_gripper/force_grasp
```

`home`：

```text
不自动移动夹爪
  -> 切换 step / multi-turn 模式
  -> 将当前物理位置定义为 relative_ticks=0
```

`home` 现在是手动确认零点，不负责寻找最大打开位置。用户应先用
`tools/sts3215_gripper_manual_home.py` 左右点动夹爪到真实最大打开角度，再确认
当前位置为 `relative_ticks=0`。`home_raw=0` 不是多圈范围内的全局唯一位置，
不再作为自动回零目标。

`move_relative`：

```text
移动到相对零点的指定 ticks
  -> 检查 YAML 安全范围
  -> 根据实际编码器反馈确认到位
```

`move_relative` 使用的是以最大打开位置为零点的绝对软件坐标，因此要求先成功
建立 home。已知零点时，从闭合位置张开应发送目标 `target_ticks=0`，不要再次
调用 `home`。

`move_step`：

```text
检查舵机当前处于 Step 模式
  -> 从当前位置移动指定 delta_ticks
  -> 根据动作期间的编码器变化确认移动量
  -> 将 homed 置为 false
```

`move_step` 不依赖 home，适合手动恢复和未建立零点时的相对增量动作。它绕过了
基于最大打开位置的绝对安全坐标，因此执行后必须重新确认机械位置并 home，才能
继续使用 `move_relative` 和 `force_grasp`。

`force_grasp`：

```text
向最大闭合位置运动
  -> 持续读取 current_raw / load_raw
  -> 达到阈值后停止
  -> 返回接触位置和最终反馈
```

夹爪必须先成功 `home`，才能执行 `move_relative` 绝对软件坐标和力矩夹取。
`move_step` 只要求舵机处于 Step 模式。

当前夹爪按本机安装方向的经验原始值判断夹取成功：
`load_raw >= 1100` 且 `abs(current_raw) >= 7`，连续满足
`force_contact_confirm_samples=8` 次。`load_raw/current_raw` 是舵机反馈原始量，
不是已经换算成物理单位的牛顿或牛米；若更换舵机、安装方向、夹爪机构或供电条件，
需要重新标定这些阈值。首次真机测试应低速进行，并验证 step 模式下发送零步长命令
是否能可靠停止并保持夹持。

## 配置归属

### 夹爪硬件配置

```text
alicia_d_sts_gripper/config/sts3215_gripper.yaml
```

只保存：

- 串口、波特率、舵机 ID。
- `home_raw` 最大打开机械参考。
- `open_ticks`、`max_closed_ticks` 和安全范围。
- 回零速度、普通动作速度、力矩夹取默认阈值。
- 串口超时和状态发布频率。

### 机械臂动作配置

```text
alicia_d_arm_motion/config/arm_motion.yaml
```

只保存：

- MoveIt planning group。
- IK link。
- 机械臂关节名。
- 默认速度、加速度、避碰和超时参数。

### 抓取任务策略配置

```text
alicia_d_pick_coordinator/config/pick_coordinator.yaml
```

只保存：

- `pre_grasp` 和 `lift` 偏移。
- 夹爪打开目标。
- 力矩夹取阈值覆盖值。
- 主控等待超时。

### 固定关节位姿配置

```text
alicia_d_pick_coordinator/config/waypoints.yaml
```

当前保存抓取完成后的中间位姿：

```text
post_grasp_intermediate_joint_names
post_grasp_intermediate_joint_positions
```

关节角单位为弧度。默认位置值为 `.nan` 占位符；主控检测到未填写的占位符时，
不会开始抓取。
- 机械臂动作请求的任务级参数。

### ThinkGrasp Bridge 配置

```text
alicia_d_thinkgrasp_bridge/config/mock_grasp.yaml
```

只保存：

- HTTP 服务地址。
- RGB、深度图和任务文本路径。
- 输出坐标系和数据来源名称。
- Mock ThinkGrasp 返回值。

## 后续扩展

多物体连续抓取时，保持同样边界：

```text
识别场景
  -> 选择一个候选
  -> 执行一次抓取
  -> 更新场景
  -> 再选择下一个候选
```

放置动作、失败重试、碰撞恢复和抓取质量判断都应进入主控任务状态机，不应写进 ThinkGrasp Bridge、机械臂动作节点或夹爪驱动节点。
