#!/usr/bin/env python3
import time

import rclpy
from geometry_msgs.msg import PoseStamped
from moveit_msgs.action import ExecuteTrajectory
from moveit_msgs.msg import Constraints, JointConstraint
from moveit_msgs.srv import GetMotionPlan, GetPositionFK, GetPositionIK
from rclpy.action import ActionClient
from rclpy.node import Node
from sensor_msgs.msg import JointState


class SafeTcpLift(Node):
    def __init__(self):
        super().__init__("safe_tcp_lift")

        self.declare_parameter("base_frame", "base_link")
        self.declare_parameter("planning_group", "Alicia")
        self.declare_parameter("ik_link_name", "gripper_center")
        self.declare_parameter("lift_z", 0.05)
        self.declare_parameter("max_lift_z", 0.20)
        self.declare_parameter("ik_avoid_collisions", False)
        self.declare_parameter("max_velocity_scaling", 0.08)
        self.declare_parameter("max_acceleration_scaling", 0.08)
        self.declare_parameter("execute_motion", True)

        self.base_frame = self.get_parameter("base_frame").value
        self.planning_group = self.get_parameter("planning_group").value
        self.ik_link_name = self.get_parameter("ik_link_name").value
        self.arm_joint_names = ["Joint1", "Joint2", "Joint3", "Joint4", "Joint5", "Joint6"]

        self.current_joint_state = None
        self.create_subscription(JointState, "/joint_states", self._on_joint_state, 10)

        self.fk_client = self.create_client(GetPositionFK, "/compute_fk")
        self.ik_client = self.create_client(GetPositionIK, "/compute_ik")
        self.plan_client = self.create_client(GetMotionPlan, "/plan_kinematic_path")
        self.execute_client = ActionClient(self, ExecuteTrajectory, "/execute_trajectory")

    def _on_joint_state(self, msg):
        self.current_joint_state = msg

    def wait_until_ready(self):
        self.get_logger().info("Waiting for joint state, FK, IK, planner, and executor...")
        self.fk_client.wait_for_service()
        self.ik_client.wait_for_service()
        self.plan_client.wait_for_service()
        self.execute_client.wait_for_server()

        start = time.time()
        while rclpy.ok() and time.time() - start < 5.0:
            rclpy.spin_once(self, timeout_sec=0.1)
            if self._has_arm_joint_state():
                return
        raise RuntimeError("No complete arm joint state received from /joint_states")

    def _has_arm_joint_state(self):
        if self.current_joint_state is None:
            return False
        names = set(self.current_joint_state.name)
        return all(name in names for name in self.arm_joint_names)

    def current_tcp_pose(self):
        request = GetPositionFK.Request()
        request.header.frame_id = self.base_frame
        request.fk_link_names = [self.ik_link_name]
        request.robot_state.joint_state = self.current_joint_state

        future = self.fk_client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=3.0)
        if not future.done() or future.result().error_code.val != 1:
            raise RuntimeError("Could not compute current TCP pose with /compute_fk")

        return future.result().pose_stamped[0]

    def compute_ik(self, pose_stamped):
        request = GetPositionIK.Request()
        request.ik_request.group_name = self.planning_group
        request.ik_request.ik_link_name = self.ik_link_name
        request.ik_request.avoid_collisions = bool(self.get_parameter("ik_avoid_collisions").value)
        request.ik_request.timeout.sec = 2
        request.ik_request.pose_stamped = pose_stamped
        request.ik_request.robot_state.joint_state = self.current_joint_state

        future = self.ik_client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=3.0)
        if not future.done():
            raise RuntimeError("IK request timed out")

        response = future.result()
        if response.error_code.val != 1:
            raise RuntimeError(f"IK failed with error code {response.error_code.val}")

        solution = []
        for name in self.arm_joint_names:
            index = response.solution.joint_state.name.index(name)
            solution.append(response.solution.joint_state.position[index])
        return solution

    def plan_to_joints(self, joint_positions):
        request = GetMotionPlan.Request()
        req = request.motion_plan_request
        req.group_name = self.planning_group
        req.num_planning_attempts = 5
        req.allowed_planning_time = 5.0
        req.max_velocity_scaling_factor = float(self.get_parameter("max_velocity_scaling").value)
        req.max_acceleration_scaling_factor = float(self.get_parameter("max_acceleration_scaling").value)
        req.start_state.joint_state = self.current_joint_state

        constraints = Constraints()
        constraints.name = "safe_tcp_lift_joint_goal"
        for name, position in zip(self.arm_joint_names, joint_positions):
            joint_constraint = JointConstraint()
            joint_constraint.joint_name = name
            joint_constraint.position = float(position)
            joint_constraint.tolerance_above = 0.01
            joint_constraint.tolerance_below = 0.01
            joint_constraint.weight = 1.0
            constraints.joint_constraints.append(joint_constraint)
        req.goal_constraints.append(constraints)

        future = self.plan_client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=10.0)
        if not future.done():
            raise RuntimeError("Motion planning timed out")

        response = future.result()
        if response.motion_plan_response.error_code.val != 1:
            raise RuntimeError(
                f"Motion planning failed with error code {response.motion_plan_response.error_code.val}"
            )
        return response.motion_plan_response.trajectory

    def execute_trajectory(self, trajectory):
        if not bool(self.get_parameter("execute_motion").value):
            self.get_logger().info("execute_motion=false; planned lift but did not execute")
            return

        goal = ExecuteTrajectory.Goal()
        goal.trajectory = trajectory
        future = self.execute_client.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if not future.done() or not future.result().accepted:
            raise RuntimeError("ExecuteTrajectory goal was rejected")

        result_future = future.result().get_result_async()
        rclpy.spin_until_future_complete(self, result_future, timeout_sec=30.0)
        if not result_future.done():
            raise RuntimeError("Trajectory execution timed out")

        error_code = result_future.result().result.error_code.val
        if error_code != 1:
            raise RuntimeError(f"Trajectory execution failed with error code {error_code}")

    def run(self):
        lift_z = float(self.get_parameter("lift_z").value)
        max_lift_z = float(self.get_parameter("max_lift_z").value)
        if lift_z <= 0.0 or lift_z > max_lift_z:
            raise ValueError(f"lift_z must be in (0, {max_lift_z}] meters")

        current = self.current_tcp_pose()
        target = PoseStamped()
        target.header.frame_id = self.base_frame
        target.header.stamp = self.get_clock().now().to_msg()
        target.pose.position.x = current.pose.position.x
        target.pose.position.y = current.pose.position.y
        target.pose.position.z = current.pose.position.z + lift_z
        target.pose.orientation.x = current.pose.orientation.x
        target.pose.orientation.y = current.pose.orientation.y
        target.pose.orientation.z = current.pose.orientation.z
        target.pose.orientation.w = current.pose.orientation.w

        self.get_logger().info(
            "Current TCP: "
            f"x={current.pose.position.x:.4f}, y={current.pose.position.y:.4f}, "
            f"z={current.pose.position.z:.4f}"
        )
        self.get_logger().info(f"Requested lift_z={lift_z:.4f} m")
        self.get_logger().info(
            "Target TCP: "
            f"x={target.pose.position.x:.4f}, y={target.pose.position.y:.4f}, "
            f"z={target.pose.position.z:.4f}"
        )

        joint_positions = self.compute_ik(target)
        trajectory = self.plan_to_joints(joint_positions)
        self.execute_trajectory(trajectory)
        self.get_logger().info("Safe TCP lift finished")


def main():
    rclpy.init()
    node = SafeTcpLift()
    try:
        node.wait_until_ready()
        node.run()
    except Exception as exc:
        node.get_logger().error(str(exc))
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
