#!/usr/bin/env python3
import math
import time

import rclpy
from alicia_d_control_interfaces.action import MoveArmToJoints, MoveArmToPose
from moveit_msgs.action import ExecuteTrajectory
from moveit_msgs.msg import Constraints, JointConstraint
from moveit_msgs.srv import GetMotionPlan, GetPositionIK
from rclpy.action import ActionClient, ActionServer, CancelResponse, GoalResponse
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from sensor_msgs.msg import JointState


class ArmMotionServer(Node):
    MOVEIT_SUCCESS = 1

    def __init__(self):
        super().__init__("arm_motion_server")
        self._declare_parameters()
        self._load_parameters()
        self._current_joint_state = None

        self.create_subscription(JointState, "/joint_states", self._on_joint_state, 10)
        self._ik_client = self.create_client(GetPositionIK, "/compute_ik")
        self._plan_client = self.create_client(GetMotionPlan, "/plan_kinematic_path")
        self._execute_client = ActionClient(self, ExecuteTrajectory, "/execute_trajectory")
        self._pose_action_server = ActionServer(
            self,
            MoveArmToPose,
            "move_to_pose",
            execute_callback=self._execute_pose_move,
            goal_callback=self._pose_goal_callback,
            cancel_callback=self._cancel_callback,
        )
        self._joint_action_server = ActionServer(
            self,
            MoveArmToJoints,
            "move_to_joints",
            execute_callback=self._execute_joint_move,
            goal_callback=self._joint_goal_callback,
            cancel_callback=self._cancel_callback,
        )
        self.get_logger().info(
            "Arm motion actions ready at 'move_to_pose' and 'move_to_joints'"
        )

    def _declare_parameters(self):
        self.declare_parameter("planning_group", "Alicia")
        self.declare_parameter("default_ik_link_name", "gripper_center")
        self.declare_parameter(
            "arm_joint_names",
            ["Joint1", "Joint2", "Joint3", "Joint4", "Joint5", "Joint6"],
        )
        self.declare_parameter("default_max_velocity_scaling", 0.25)
        self.declare_parameter("default_max_acceleration_scaling", 0.25)
        self.declare_parameter("default_avoid_collisions", False)
        self.declare_parameter("ik_timeout_s", 1.0)
        self.declare_parameter("planning_timeout_s", 10.0)
        self.declare_parameter("execution_timeout_s", 30.0)
        self.declare_parameter("num_planning_attempts", 5)
        self.declare_parameter("joint_goal_tolerance", 0.01)

    def _load_parameters(self):
        self.planning_group = str(self.get_parameter("planning_group").value)
        self.default_ik_link_name = str(self.get_parameter("default_ik_link_name").value)
        self.arm_joint_names = [
            str(value) for value in self.get_parameter("arm_joint_names").value
        ]
        self.default_max_velocity_scaling = float(
            self.get_parameter("default_max_velocity_scaling").value
        )
        self.default_max_acceleration_scaling = float(
            self.get_parameter("default_max_acceleration_scaling").value
        )
        self.default_avoid_collisions = bool(
            self.get_parameter("default_avoid_collisions").value
        )
        self.ik_timeout_s = float(self.get_parameter("ik_timeout_s").value)
        self.planning_timeout_s = float(self.get_parameter("planning_timeout_s").value)
        self.execution_timeout_s = float(self.get_parameter("execution_timeout_s").value)
        self.num_planning_attempts = int(self.get_parameter("num_planning_attempts").value)
        self.joint_goal_tolerance = float(self.get_parameter("joint_goal_tolerance").value)

    def _on_joint_state(self, msg):
        self._current_joint_state = msg

    def _pose_goal_callback(self, goal_request):
        pose = goal_request.target_pose.pose
        values = [
            pose.position.x,
            pose.position.y,
            pose.position.z,
            pose.orientation.x,
            pose.orientation.y,
            pose.orientation.z,
            pose.orientation.w,
        ]
        if not goal_request.target_pose.header.frame_id or not all(math.isfinite(v) for v in values):
            self.get_logger().warn("Rejecting arm goal with invalid target pose")
            return GoalResponse.REJECT
        return GoalResponse.ACCEPT

    def _joint_goal_callback(self, goal_request):
        names = list(goal_request.joint_names)
        positions = list(goal_request.joint_positions)
        if (
            len(names) != len(self.arm_joint_names)
            or len(positions) != len(self.arm_joint_names)
            or len(set(names)) != len(names)
            or set(names) != set(self.arm_joint_names)
            or not all(math.isfinite(value) for value in positions)
        ):
            self.get_logger().warn(
                "Rejecting arm joint goal; expected one finite position for each "
                f"joint: {self.arm_joint_names}"
            )
            return GoalResponse.REJECT
        return GoalResponse.ACCEPT

    def _cancel_callback(self, _goal_handle):
        return CancelResponse.ACCEPT

    @staticmethod
    def _wait_future(future, timeout_s):
        deadline = time.monotonic() + timeout_s
        while not future.done() and time.monotonic() < deadline:
            time.sleep(0.01)
        return future.done()

    def _publish_stage(self, goal_handle, feedback_type, stage):
        feedback = feedback_type()
        feedback.stage = stage
        goal_handle.publish_feedback(feedback)
        self.get_logger().info(stage)

    def _execute_pose_move(self, goal_handle):
        result = MoveArmToPose.Result()
        request = goal_handle.request
        try:
            if not self._wait_for_moveit():
                return self._abort(goal_handle, result, 0, "MoveIt interfaces are unavailable")
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                return result

            self._publish_stage(goal_handle, MoveArmToPose.Feedback, "computing_ik")
            joint_positions, error_code = self._compute_ik(request)
            if joint_positions is None:
                return self._abort(goal_handle, result, error_code, "IK failed")

            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                return result
            self._publish_stage(goal_handle, MoveArmToPose.Feedback, "planning")
            trajectory, error_code = self._plan_to_joints(request, joint_positions)
            if trajectory is None:
                return self._abort(goal_handle, result, error_code, "Motion planning failed")

            if not request.execute:
                result.success = True
                result.moveit_error_code = self.MOVEIT_SUCCESS
                result.message = "Planning succeeded; execution disabled by request"
                goal_handle.succeed()
                return result

            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                return result
            self._publish_stage(goal_handle, MoveArmToPose.Feedback, "executing")
            success, error_code = self._execute_trajectory(trajectory)
            if not success:
                return self._abort(goal_handle, result, error_code, "Trajectory execution failed")

            self._publish_stage(goal_handle, MoveArmToPose.Feedback, "complete")
            result.success = True
            result.moveit_error_code = self.MOVEIT_SUCCESS
            result.message = "Target pose reached"
            goal_handle.succeed()
            return result
        except Exception as exc:
            return self._abort(goal_handle, result, 0, str(exc))

    def _execute_joint_move(self, goal_handle):
        result = MoveArmToJoints.Result()
        request = goal_handle.request
        try:
            if not self._wait_for_moveit():
                return self._abort(goal_handle, result, 0, "MoveIt interfaces are unavailable")
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                return result

            positions_by_name = dict(zip(request.joint_names, request.joint_positions))
            joint_positions = [
                positions_by_name[name] for name in self.arm_joint_names
            ]

            self._publish_stage(goal_handle, MoveArmToJoints.Feedback, "planning")
            trajectory, error_code = self._plan_to_joints(request, joint_positions)
            if trajectory is None:
                return self._abort(goal_handle, result, error_code, "Motion planning failed")

            if not request.execute:
                result.success = True
                result.moveit_error_code = self.MOVEIT_SUCCESS
                result.message = "Planning succeeded; execution disabled by request"
                goal_handle.succeed()
                return result

            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                return result
            self._publish_stage(goal_handle, MoveArmToJoints.Feedback, "executing")
            success, error_code = self._execute_trajectory(trajectory)
            if not success:
                return self._abort(goal_handle, result, error_code, "Trajectory execution failed")

            self._publish_stage(goal_handle, MoveArmToJoints.Feedback, "complete")
            result.success = True
            result.moveit_error_code = self.MOVEIT_SUCCESS
            result.message = "Target joint position reached"
            goal_handle.succeed()
            return result
        except Exception as exc:
            return self._abort(goal_handle, result, 0, str(exc))

    def _abort(self, goal_handle, result, error_code, message):
        result.success = False
        result.moveit_error_code = int(error_code)
        result.message = str(message)
        self.get_logger().error(result.message)
        goal_handle.abort()
        return result

    def _wait_for_moveit(self):
        return (
            self._ik_client.wait_for_service(timeout_sec=2.0)
            and self._plan_client.wait_for_service(timeout_sec=2.0)
            and self._execute_client.wait_for_server(timeout_sec=2.0)
        )

    def _compute_ik(self, action_request):
        request = GetPositionIK.Request()
        request.ik_request.group_name = self.planning_group
        request.ik_request.ik_link_name = (
            action_request.ik_link_name or self.default_ik_link_name
        )
        request.ik_request.avoid_collisions = (
            action_request.avoid_collisions or self.default_avoid_collisions
        )
        sec = int(self.ik_timeout_s)
        request.ik_request.timeout.sec = sec
        request.ik_request.timeout.nanosec = int((self.ik_timeout_s - sec) * 1e9)
        request.ik_request.pose_stamped = action_request.target_pose
        if self._current_joint_state is not None:
            request.ik_request.robot_state.joint_state = self._current_joint_state

        future = self._ik_client.call_async(request)
        if not self._wait_future(future, self.ik_timeout_s + 1.0):
            return None, 0
        response = future.result()
        error_code = response.error_code.val
        if error_code != self.MOVEIT_SUCCESS:
            return None, error_code

        positions = []
        for name in self.arm_joint_names:
            try:
                index = response.solution.joint_state.name.index(name)
            except ValueError as exc:
                raise RuntimeError(f"IK response is missing joint {name}") from exc
            positions.append(response.solution.joint_state.position[index])
        return positions, error_code

    def _plan_to_joints(self, action_request, joint_positions):
        request = GetMotionPlan.Request()
        req = request.motion_plan_request
        req.group_name = self.planning_group
        req.num_planning_attempts = self.num_planning_attempts
        req.allowed_planning_time = self.planning_timeout_s
        req.max_velocity_scaling_factor = (
            action_request.max_velocity_scaling
            if action_request.max_velocity_scaling > 0.0
            else self.default_max_velocity_scaling
        )
        req.max_acceleration_scaling_factor = (
            action_request.max_acceleration_scaling
            if action_request.max_acceleration_scaling > 0.0
            else self.default_max_acceleration_scaling
        )
        req.start_state.is_diff = True

        constraints = Constraints()
        constraints.name = "arm_motion_joint_goal"
        for name, position in zip(self.arm_joint_names, joint_positions):
            constraint = JointConstraint()
            constraint.joint_name = name
            constraint.position = float(position)
            constraint.tolerance_above = self.joint_goal_tolerance
            constraint.tolerance_below = self.joint_goal_tolerance
            constraint.weight = 1.0
            constraints.joint_constraints.append(constraint)
        req.goal_constraints.append(constraints)

        future = self._plan_client.call_async(request)
        if not self._wait_future(future, self.planning_timeout_s + 1.0):
            return None, 0
        response = future.result().motion_plan_response
        if response.error_code.val != self.MOVEIT_SUCCESS:
            return None, response.error_code.val
        return response.trajectory, response.error_code.val

    def _execute_trajectory(self, trajectory):
        goal = ExecuteTrajectory.Goal()
        goal.trajectory = trajectory
        send_future = self._execute_client.send_goal_async(goal)
        if not self._wait_future(send_future, 5.0):
            return False, 0
        goal_handle = send_future.result()
        if not goal_handle.accepted:
            return False, 0
        result_future = goal_handle.get_result_async()
        if not self._wait_future(result_future, self.execution_timeout_s):
            return False, 0
        error_code = result_future.result().result.error_code.val
        return error_code == self.MOVEIT_SUCCESS, error_code


def main(args=None):
    rclpy.init(args=args)
    node = ArmMotionServer()
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(node)
    try:
        executor.spin()
    finally:
        executor.shutdown()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
