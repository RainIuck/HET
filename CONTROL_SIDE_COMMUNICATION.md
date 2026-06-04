# 机械臂控制端通信说明

本文面向运行 `alicia_ws` 的机械臂控制端。控制端通过 ZeroTier 虚拟局域网访问决策服务端 `ThinkGrasp-main`，上传 RGB-D 图像和任务文本，并接收抓取结果 `xyz + rot + dep`。

## 1. 网络与角色

当前 ZeroTier 地址：

```text
决策服务端 Ubuntu Server: 10.246.52.176
机械臂控制端 Windows User: 10.246.52.141
```

控制端访问的 ThinkGrasp 接口：

```text
POST http://10.246.52.176:5000/grasp_pose_upload
```

控制端只通过 HTTP 访问决策端，不跨主机运行 ROS2/DDS。ROS2、MoveIt2、机械臂驱动、IK、规划和执行都保留在控制端本机。

## 2. 通信数据流

```text
控制端本机 RGB 图像 / depth 图像 / 任务文本
        |
        | multipart/form-data over ZeroTier
        v
ThinkGrasp-main /grasp_pose_upload
        |
        | JSON: xyz + rot + dep
        v
alicia_d_thinkgrasp_bridge
        |
        v
MoveIt2 IK / 规划 / 执行
```

上传字段：

```text
rgb   : RGB PNG 文件
depth : raw depth PNG 文件
text  : 任务文本内容
```

返回字段：

```json
{
  "xyz": [0.12, -0.03, 0.18],
  "rot": [
    [1.0, 0.0, 0.0],
    [0.0, 1.0, 0.0],
    [0.0, 0.0, 1.0]
  ],
  "dep": 0.04
}
```

## 3. 启动前检查

确认 ZeroTier 已连通：

```bash
ping 10.246.52.176
```

确认决策服务端 Flask 服务已启动，并且 Ubuntu 防火墙允许 ZeroTier 网段访问 TCP 5000。

如果只验证 HTTP 上传链路，可以先使用顶层客户端脚本：

```bash
python realsense_command_client.py \
  --server-url http://10.246.52.176:5000/grasp_pose_upload \
  --timeout 300
```

该脚本会从 RealSense 采集一帧 RGB-D，输入任务文本后上传到决策端，并打印返回 JSON。

## 4. ROS2 桥接启动方式

进入控制端 ROS2 工作区：

```bash
cd ~/桌面/Robot_Arm/alicia_ws
source install/setup.bash
```

先建议只验证通信、IK 和规划，不执行机械臂运动：

```bash
ros2 launch alicia_d_thinkgrasp_bridge zerotier_thinkgrasp_pick.launch.py \
  execute_motion:=false \
  image_path:=/path/to/rgb.png \
  depth_path:=/path/to/depth_raw.png \
  text_path:=/path/to/task.txt
```

确认日志中出现 ThinkGrasp 返回结果后，再允许执行：

```bash
ros2 launch alicia_d_thinkgrasp_bridge zerotier_thinkgrasp_pick.launch.py \
  execute_motion:=true \
  image_path:=/path/to/rgb.png \
  depth_path:=/path/to/depth_raw.png \
  text_path:=/path/to/task.txt
```

默认配置文件：

```text
alicia_ws/src/alicia_d_thinkgrasp_bridge/config/zerotier_grasp.yaml
```

默认远端地址：

```yaml
decision_url: "http://10.246.52.176:5000/grasp_pose_upload"
decision_request_mode: "multipart_upload"
decision_timeout_sec: 300.0
```

## 5. 常见问题

### ping 不通 `10.246.52.176`

检查两端 ZeroTier 是否在线、是否加入同一个网络、是否在 ZeroTier Central 中授权。

### HTTP 连接失败

检查决策端是否已启动：

```bash
cd ThinkGrasp-main
python realarm.py
```

还要检查 Ubuntu 防火墙是否允许 TCP 5000。

### 返回非 JSON 或 HTTP 500

说明请求已经到达 ThinkGrasp，但决策端内部推理失败。查看决策端终端日志，重点检查模型依赖、OpenAI API、CUDA、Open3D 可视化窗口等。

### bridge 提示本地文件不可读

确认 `image_path`、`depth_path`、`text_path` 是控制端本机存在的文件。现在跨主机上传的是文件内容，不再要求决策端能看到这些路径。

