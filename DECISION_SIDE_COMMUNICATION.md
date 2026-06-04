# 决策服务端通信说明

本文面向运行 `ThinkGrasp-main` 的决策服务端。决策端通过 Flask 暴露 HTTP 接口，接收机械臂控制端经 ZeroTier 上传的 RGB-D 图像和任务文本，返回抓取结果 `xyz + rot + dep`。

## 1. 网络与角色

当前 ZeroTier 地址：

```text
决策服务端 Ubuntu Server: 10.246.52.176
机械臂控制端 Windows User: 10.246.52.141
```

决策端需要对 ZeroTier 网段开放：

```text
TCP 5000
```

ThinkGrasp 服务监听配置位于：

```text
ThinkGrasp-main/realarm.py
```

当前启动代码：

```python
app.run(host='0.0.0.0', port=5000)
```

`0.0.0.0` 表示 Flask 会监听本机所有网卡，包括 ZeroTier 虚拟网卡。

## 2. 对外接口

控制端正式使用的接口：

```text
POST /grasp_pose_upload
```

完整地址：

```text
http://10.246.52.176:5000/grasp_pose_upload
```

请求格式为 `multipart/form-data`：

```text
rgb   : RGB PNG 文件
depth : raw depth PNG 文件
text  : 任务文本内容
```

服务端收到上传后，会将文件保存到 `uploads/<job_id>/`，再内部调用 `/grasp_pose`。

内部接口：

```text
POST /grasp_pose
```

该接口接收的是路径 JSON：

```json
{
  "image_path": "/server/local/rgb.png",
  "depth_path": "/server/local/depth_raw.png",
  "text_path": "/server/local/task.txt"
}
```

跨主机联调时不要让控制端直接调用 `/grasp_pose`，因为控制端本机路径在决策端不可见。

## 3. 启动方式

进入决策端目录：

```bash
cd ThinkGrasp-main
```

启动服务：

```bash
python realarm.py
```

启动后应监听：

```text
0.0.0.0:5000
```

控制端将访问：

```text
http://10.246.52.176:5000/grasp_pose_upload
```

## 4. 防火墙检查

如果 Ubuntu 启用了 `ufw`，需要允许 ZeroTier 网段访问 5000 端口。可按实际安全策略选择只放行 ZeroTier 网卡或只放行控制端 IP。

示例：

```bash
sudo ufw allow from 10.246.52.141 to any port 5000 proto tcp
```

查看状态：

```bash
sudo ufw status
```

## 5. 返回格式

成功响应：

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

字段说明：

```text
xyz : ThinkGrasp 输出的抓取点坐标
rot : 3x3 抓取姿态旋转矩阵
dep : 抓取深度参数
```

注意：当前阶段只负责通信打通，不在决策端处理 `xyz` 到机械臂 `base_link` 的外参转换。

## 6. 常见问题

### 控制端无法连接

检查：

```bash
ping 10.246.52.141
```

并确认：

```text
1. 两端 ZeroTier 在线且已授权
2. Flask 正在运行
3. TCP 5000 未被防火墙拦截
4. realarm.py 使用 host='0.0.0.0'
```

### `/grasp_pose_upload` 返回 400

说明请求缺少字段。控制端必须上传：

```text
rgb
depth
text
```

### `/grasp_pose_upload` 返回 500

说明通信已经到达决策端，但推理流程内部失败。查看 `python realarm.py` 所在终端日志，重点排查模型权重、CUDA、OpenAI API、Open3D 可视化和输入图像格式。

### 推理耗时较长

控制端已按远端推理设置较长超时，默认 `300s`。如果模型加载或首次推理更慢，可以在控制端 launch 中增加 `decision_timeout_sec` 参数或修改 `zerotier_grasp.yaml`。

