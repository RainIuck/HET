#!/usr/bin/env python3
import time

import rclpy
from moveit_msgs.action import ExecuteTrajectory
from moveit_msgs.msg import Constraints, JointConstraint
from moveit_msgs.srv import GetMotionPlan, GetPositionFK
from rclpy.action import ActionClient
from rclpy.node import Node
from sensor_msgs.msg import JointState


class SafeJointRaise(Node):
    def __init__(self):
        super().__init__("safe_joint_raise")

        self.declare_parameter("base_frame", "base_link")
        self.declare_parameter("ik_link_name", "gripper_center")
        self.declare_parameter("planning_group", "Alicia")
        self.declare_parameter("execute_motion", False)
        self.declare_parameter("min_raise_z", 0.03)
        self.declare_parameter("max_velocity_scaling", 0.05)
        self.declare_parameter("max_acceleration_scaling", 0.05)
        self.declare_parameter("keep_joint1", True)
        self.declare_parameter("keep_joint4", True)
        self.declare_parameter("keep_joint6", True)

        self.arm_joint_names = ["Joint1", "Joint2", "Joint3", "Joint4", "Joint5", "Joint6"]
        # Reference "home" from cube_sorting.yaml/material.
        self.reference_home = [0.0, 0.1089, 0.6703, 0.0, -1.4174, 0.0]

        self.base_frame = self.get_parameter("base_frame").value
        self.ik_link_name = self.get_parameter("ik_link_name").value
        self.planning_group = self.get_parameter("planning_group").value

        self.current_joint_state = None
        self.create_subscription(JointState, "/joint_states", self._on_joint_state, 10)

        self.fk_client = self.create_client(GetPositionFK, "/compute_fk")
        self.plan_client = self.create_client(GetMotionPlan, "/plan_kinematic_path")
        self.execute_client = ActionClient(self, ExecuteTrajectory, "/execute_trajectory")

    def _on_joint_state(self, msg):
        self.current_joint_state = msg

    def wait_until_ready(self):
        self.get_logger().info("Waiting for joint state, FK, planner, and executor...")
        self.fk_client.wait_for_service()
        self.plan_client.wait_for_service()
        self.execute_client.wait_for_server()

        start = time.time()
        while rclpy.ok() and time.time() - start < 5.0:
            rclpy.spin_once(self, timeout_sec=0.1)
            if self._current_arm_positions() is not None:
                return
        raise RuntimeError("No complete arm joint state received from /joint_states")

    def _current_arm_positions(self):
        if self.current_joint_state is None:
            return None
        by_name = dict(zip(self.current_joint_state.name, self.current_joint_state.position))
        if not all(name in by_name for name in self.arm_joint_names):
            return None
        return [float(by_name[name]) for name in self.arm_joint_names]

    def _joint_state_for(self, positions):
        msg = JointState()
        msg.header.frame_id = self.base_frame
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.name = list(self.arm_joint_names)
        msg.position = [float(v) for v in positions]
        return msg

    def tcp_z_for(self, joint_state):
        request = GetPositionFK.Request()
        request.header.frame_id = self.base_frame
        request.fk_link_names = [self.ik_link_name]
        request.robot_state.joint_state = joint_state

        future = self.fk_client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=3.0)
        if not future.done() or future.result().error_code.val != 1:
            raise RuntimeError("Could not compute TCP pose with /compute_fk")
        pose = future.result().pose_stamped[0].pose
        return pose.position.z

    def build_target_positions(self, current):
        target = list(self.reference_home)
        if bool(self.get_parameter("keep_joint1").value):
            target[0] = current[0]
        if bool(self.get_parameter("keep_joint4").value):
            target[3] = current[3]
        if bool(self.get_parameter("keep_joint6").value):
            target[5] = current[5]
        return target

    def plan_to_joints(self, current_joint_state, target_positions):
        request = GetMotionPlan.Request()
        req = request.motion_plan_request
        req.group_name = self.planning_group
        req.num_planning_attempts = 5
        req.allowed_planning_time = 5.0
        req.max_velocity_scaling_factor = float(self.get_parameter("max_velocity_scaling").value)
        req.max_acceleration_scaling_factor = float(self.get_parameter("max_acceleration_scaling").value)
        req.start_state.joint_state = current_joint_state

        constraints = Constraints()
        constraints.name = "safe_joint_raise_goal"
        for name, position in zip(self.arm_joint_names, target_positions):
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
            self.get_logger().info("execute_motion=false; planned raise but did not execute")
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
        current_positions = self._current_arm_positions()
        current_arm_state = self._joint_state_for(current_positions)
        target_positions = self.build_target_positions(current_positions)
        target_arm_state = self._joint_state_for(target_positions)

        current_z = self.tcp_z_for(current_arm_state)
        target_z = self.tcp_z_for(target_arm_state)
        min_raise_z = float(self.get_parameter("min_raise_z").value)

        self.get_logger().info(f"Current joints: {[round(v, 4) for v in current_positions]}")
        self.get_logger().info(f"Target joints:  {[round(v, 4) for v in target_positions]}")
        self.get_logger().info(f"Current TCP z={current_z:.4f}, target TCP z={target_z:.4f}")

        if target_z < current_z + min_raise_z:
            raise RuntimeError(
                f"Refusing target: TCP z raise {target_z - current_z:.4f} m "
                f"is smaller than min_raise_z={min_raise_z:.4f} m"
            )

        trajectory = self.plan_to_joints(self.current_joint_state, target_positions)
        self.execute_trajectory(trajectory)
        self.get_logger().info("Safe joint raise finished")


def main():
    rclpy.init()
    node = SafeJointRaise()
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
