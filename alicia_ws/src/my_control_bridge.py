#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from moveit_msgs.srv import GetMotionPlan
from moveit_msgs.msg import MotionPlanRequest, Constraints, PositionConstraint, OrientationConstraint
#from shapely import geometry # 留作以后箱子碰撞检测，先不用管

class MyControlBridge(Node):
    def __init__(self):
        super().__init__('my_control_bridge')
        self.get_logger().info('====================================')
        self.get_logger().info('🚀 控制层核心骨架节点启动成功！正在初始化...')
        self.get_logger().info('====================================')

        # 1. 创建一个服务客户端，专门向 MoveIt2 索要“运动规划路线”
        # MoveIt2 默认的规划服务名字叫 '/plan_kinematic_path'
        self.planner_client = self.create_client(GetMotionPlan, '/plan_kinematic_path')
        
        # 等待服务上线
        while not self.planner_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn('正在等待 MoveIt2 规划服务 (/plan_kinematic_path) 上线... 请确保 demo.launch.py 正常运行中')

        self.get_logger().info('🎉 成功连接到 MoveIt2 规划服务器！')
        
        # 2. 触发我们的第一次测试：发送一个 Mock（虚拟）抓取点
        self.send_mock_target()

    def send_mock_target(self):
        self.get_logger().info('🚩 正在构建虚拟目标点信息...')

        # 实例化一个规划请求
        request = GetMotionPlan.Request()
        req = request.motion_plan_request
        
        # 【关键配置】告诉 MoveIt2 我们要控制的是哪一部分。玄雅官方默认叫 'arm'
        req.group_name = 'arm' 
        req.num_planning_attempts = 5    # 允许尝试规划5次
        req.allowed_planning_time = 2.0  # 限制计算时间在2秒内

        # 3. 设置我们的 Mock 目标位姿 (正如你方案里规划的)
        # 坐标系基于机械臂底座 'base_link'
        target_pose = PoseStamped()
        target_pose.header.frame_id = 'base_link'
        
        # 空间坐标 (单位：米)
        target_pose.pose.position.x = 0.35  # 前伸 35 厘米
        target_pose.pose.position.y = 0.00  # 正前方，不偏左也不偏右
        target_pose.pose.position.z = 0.25  # 离地高度 25 厘米

        # 姿态（四元数）：这里先设定为一个标准不旋转的正向位姿
        target_pose.pose.orientation.x = 0.0
        target_pose.pose.orientation.y = 0.0
        target_pose.pose.orientation.z = 0.0
        target_pose.pose.orientation.w = 1.0

        # 4. 把这个目标位姿包装成 MoveIt2 认识的“约束条件”
        # 这里使用 MoveIt2 官方推荐的简易目标填充方式
        req.goal_constraints.append(Constraints())
        
        # 将我们设定的目标填充进请求中（这一步是控制层最核心的对齐动作）
        self.get_logger().info(f'🎯 目标发送中: X={target_pose.pose.position.x}, Y={target_pose.pose.position.y}, Z={target_pose.pose.position.z}')
        
        # 发送异步请求，等待 MoveIt2 回复计算结果
        future = self.planner_client.call_async(request)
        future.add_done_callback(self.plan_result_callback)

    def plan_result_callback(self, future):
        try:
            response = future.result()
            # 判断 MoveIt2 返回的错误码，SUCCESS 的代码通常是 1
            error_code = response.motion_plan_response.error_code.val
            
            if error_code == 1:
                self.get_logger().info('🟢 【成功】MoveIt2 成功为你规划出了一条安全的避障路径！')
                # 提取轨迹里一共有多少个插补点
                points_count = len(response.motion_plan_response.trajectory.joint_trajectory.points)
                self.get_logger().info(f'📊 路径插补完成，该轨迹包含 {points_count} 个路点(Waypoints)，可以流畅执行。')
            else:
                self.get_logger().error(f'🔴 【失败】MoveIt2 无法规划到达该位置！错误码: {error_code}。可能是点太远够不着，或姿态无解。')
                
        except Exception as e:
            self.get_logger().error(f'通信发生未知异常: {str(e)}')

def main(args=None):
    rclpy.init(args=args)
    node = MyControlBridge()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()