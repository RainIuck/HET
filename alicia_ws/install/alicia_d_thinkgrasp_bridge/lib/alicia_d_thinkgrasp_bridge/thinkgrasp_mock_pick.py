#!/usr/bin/env python3
import json
import time
import urllib.error
import urllib.request

import numpy as np
import rclpy
from control_msgs.action import FollowJointTrajectory
from moveit_msgs.action import ExecuteTrajectory
from moveit_msgs.msg import Constraints, JointConstraint
from moveit_msgs.srv import GetMotionPlan, GetPositionIK
from rclpy.action import ActionClient
from rclpy.duration import Duration
from rclpy.node import Node
from sensor_msgs.msg import JointState
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint


class ThinkGraspMockPick(Node):
    def __init__(self):
        super().__init__("thinkgrasp_mock_pick")

        self._declare_parameters()
        self._load_parameters()

        self.current_joint_state = None
        self.create_subscription(JointState, "/joint_states", self._on_joint_state, 10)

        self.ik_client = self.create_client(GetPositionIK, "/compute_ik")
        self.plan_client = self.create_client(GetMotionPlan, "/plan_kinematic_path")
        self.execute_client = ActionClient(self, ExecuteTrajectory, "/execute_trajectory")
        self.gripper_client = ActionClient(
            self,
            FollowJointTrajectory,
            "/Gripper_controller/follow_joint_trajectory",
        )

    def _declare_parameters(self):
        self.declare_parameter("decision_url", "http://127.0.0.1:5000/grasp_pose")
        self.declare_parameter("image_path", "/tmp/mock_rgb.png")
        self.declare_parameter("depth_path", "/tmp/mock_depth.png")
        self.declare_parameter("text_path", "/tmp/mock_task.txt")
        self.declare_parameter("base_frame", "base_link")
        self.declare_parameter("planning_group", "Alicia")
        self.declare_parameter("gripper_group", "Gripper")
        self.declare_parameter("ik_link_name", "gripper_center")
        self.declare_parameter("pre_grasp_offset_z", 0.08)
        self.declare_parameter("lift_offset_z", 0.12)
        self.declare_parameter("gripper_open", 0.0)
        self.declare_parameter("gripper_closed", 0.020)
        self.declare_parameter("execute_motion", True)
        self.declare_parameter("use_decision_orientation", False)
        self.declare_parameter("ik_avoid_collisions", False)
        self.declare_parameter("ik_timeout_sec", 1.0)
        self.declare_parameter("ik_probe_timeout_sec", 0.35)
        self.declare_parameter("fallback_search_enabled", True)
        self.declare_parameter("fallback_x_offsets", [0.0, -0.05, -0.10, -0.15, 0.05, 0.10])
        self.declare_parameter("fallback_y_offsets", [0.0])
        self.declare_parameter("fallback_z_offsets", [0.05, 0.10, 0.15, 0.0, 0.20])
        self.declare_parameter(
            "fallback_quaternions_flat",
            [
                -1.0, 0.0, 0.0, 0.0,
                1.0, 0.0, 0.0, 0.0,
                0.0, 1.0, 0.0, 0.0,
                0.0, 0.0, 1.0, 0.0,
                0.0, 0.0, 0.0, 1.0,
            ],
        )
        self.declare_parameter("max_velocity_scaling", 0.25)
        self.declare_parameter("max_acceleration_scaling", 0.25)

    def _load_parameters(self):
        self.decision_url = self.get_parameter("decision_url").value
        self.image_path = self.get_parameter("image_path").value
        self.depth_path = self.get_parameter("depth_path").value
        self.text_path = self.get_parameter("text_path").value
        self.base_frame = self.get_parameter("base_frame").value
        self.planning_group = self.get_parameter("planning_group").value
        self.ik_link_name = self.get_parameter("ik_link_name").value
        self.pre_grasp_offset_z = float(self.get_parameter("pre_grasp_offset_z").value)
        self.lift_offset_z = float(self.get_parameter("lift_offset_z").value)
        self.gripper_open = float(self.get_parameter("gripper_open").value)
        self.gripper_closed = float(self.get_parameter("gripper_closed").value)
        self.execute_motion = bool(self.get_parameter("execute_motion").value)
        self.use_decision_orientation = bool(self.get_parameter("use_decision_orientation").value)
        self.ik_avoid_collisions = bool(self.get_parameter("ik_avoid_collisions").value)
        self.ik_timeout_sec = float(self.get_parameter("ik_timeout_sec").value)
        self.ik_probe_timeout_sec = float(self.get_parameter("ik_probe_timeout_sec").value)
        self.fallback_search_enabled = bool(self.get_parameter("fallback_search_enabled").value)
        self.fallback_x_offsets = [float(v) for v in self.get_parameter("fallback_x_offsets").value]
        self.fallback_y_offsets = [float(v) for v in self.get_parameter("fallback_y_offsets").value]
        self.fallback_z_offsets = [float(v) for v in self.get_parameter("fallback_z_offsets").value]
        fallback_flat = [float(v) for v in self.get_parameter("fallback_quaternions_flat").value]
        if len(fallback_flat) % 4 != 0:
            raise ValueError("fallback_quaternions_flat length must be divisible by 4")
        self.fallback_quaternions = [
            normalize_quaternion(fallback_flat[i:i + 4])
            for i in range(0, len(fallback_flat), 4)
        ]
        self.max_velocity_scaling = float(self.get_parameter("max_velocity_scaling").value)
        self.max_acceleration_scaling = float(self.get_parameter("max_acceleration_scaling").value)

        self.arm_joint_names = ["Joint1", "Joint2", "Joint3", "Joint4", "Joint5", "Joint6"]
        self.gripper_joint_names = ["Gripper"]

    def _on_joint_state(self, msg):
        self.current_joint_state = msg

    def wait_for_servers(self):
        self.get_logger().info("Waiting for MoveIt and gripper interfaces...")
        self.ik_client.wait_for_service()
        self.plan_client.wait_for_service()
        self.execute_client.wait_for_server()
        self.gripper_client.wait_for_server()
        self.get_logger().info("MoveIt and gripper interfaces are ready")

        start = time.time()
        while self.current_joint_state is None and time.time() - start < 3.0:
            rclpy.spin_once(self, timeout_sec=0.1)
        if self.current_joint_state is None:
            self.get_logger().warn("No /joint_states received yet; IK will run without a seed state")

    def request_decision_pose(self):
        payload = {
            "image_path": self.image_path,
            "depth_path": self.depth_path,
            "text_path": self.text_path,
        }
        data = json.dumps(payload).encode("utf-8")

        request = urllib.request.Request(
            self.decision_url,
            data=data,
            headers={"Content-Type": "application/json"},
            method="POST",
        )

        last_error = None
        for _ in range(20):
            try:
                with urllib.request.urlopen(request, timeout=2.0) as response:
                    result = json.loads(response.read().decode("utf-8"))
                    self.get_logger().info(f"Decision response: {result}")
                    return result
            except (urllib.error.URLError, TimeoutError, json.JSONDecodeError) as exc:
                last_error = exc
                time.sleep(0.5)

        raise RuntimeError(f"Could not call decision endpoint {self.decision_url}: {last_error}")

    def compute_ik(self, position, quaternion, log_failure=True, timeout_sec=None):
        timeout_sec = self.ik_timeout_sec if timeout_sec is None else timeout_sec
        request = GetPositionIK.Request()
        request.ik_request.group_name = self.planning_group
        request.ik_request.ik_link_name = self.ik_link_name
        request.ik_request.avoid_collisions = self.ik_avoid_collisions
        sec = int(timeout_sec)
        request.ik_request.timeout.sec = sec
        request.ik_request.timeout.nanosec = int((timeout_sec - sec) * 1e9)
        request.ik_request.pose_stamped.header.frame_id = self.base_frame
        request.ik_request.pose_stamped.header.stamp = self.get_clock().now().to_msg()
        request.ik_request.pose_stamped.pose.position.x = float(position[0])
        request.ik_request.pose_stamped.pose.position.y = float(position[1])
        request.ik_request.pose_stamped.pose.position.z = float(position[2])
        request.ik_request.pose_stamped.pose.orientation.x = float(quaternion[0])
        request.ik_request.pose_stamped.pose.orientation.y = float(quaternion[1])
        request.ik_request.pose_stamped.pose.orientation.z = float(quaternion[2])
        request.ik_request.pose_stamped.pose.orientation.w = float(quaternion[3])

        if self.current_joint_state is not None:
            request.ik_request.robot_state.joint_state = self.current_joint_state

        future = self.ik_client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=timeout_sec + 0.5)
        if not future.done():
            self.get_logger().error("IK request timed out")
            return None

        response = future.result()
        if response.error_code.val != 1:
            if not log_failure:
                return None
            self.get_logger().error(
                "IK failed for position "
                f"{[round(float(v), 4) for v in position]}, "
                f"quat={[round(float(v), 4) for v in quaternion]}, "
                f"avoid_collisions={self.ik_avoid_collisions}, "
                f"error code: {response.error_code.val}"
            )
            return None

        joint_positions = []
        for name in self.arm_joint_names:
            idx = response.solution.joint_state.name.index(name)
            joint_positions.append(response.solution.joint_state.position[idx])

        self.get_logger().info(f"IK solution: {[round(v, 4) for v in joint_positions]}")
        return joint_positions

    def plan_to_joints(self, joint_positions):
        request = GetMotionPlan.Request()
        req = request.motion_plan_request
        req.group_name = self.planning_group
        req.num_planning_attempts = 5
        req.allowed_planning_time = 5.0
        req.max_velocity_scaling_factor = self.max_velocity_scaling
        req.max_acceleration_scaling_factor = self.max_acceleration_scaling
        req.start_state.is_diff = True

        constraints = Constraints()
        constraints.name = "mock_pick_joint_goal"
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
            self.get_logger().error("Motion planning timed out")
            return None

        response = future.result()
        if response.motion_plan_response.error_code.val != 1:
            self.get_logger().error(
                f"Motion planning failed, error code: {response.motion_plan_response.error_code.val}"
            )
            return None

        trajectory = response.motion_plan_response.trajectory
        point_count = len(trajectory.joint_trajectory.points)
        self.get_logger().info(f"Motion planning succeeded with {point_count} waypoints")
        return trajectory

    def execute_trajectory(self, trajectory):
        if not self.execute_motion:
            self.get_logger().info("execute_motion=false, skipping trajectory execution")
            return True

        goal = ExecuteTrajectory.Goal()
        goal.trajectory = trajectory
        send_goal_future = self.execute_client.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, send_goal_future, timeout_sec=10.0)
        if not send_goal_future.done() or not send_goal_future.result().accepted:
            self.get_logger().error("Trajectory execution goal was not accepted")
            return False

        result_future = send_goal_future.result().get_result_async()
        rclpy.spin_until_future_complete(self, result_future, timeout_sec=30.0)
        if not result_future.done():
            self.get_logger().error("Trajectory execution timed out")
            return False

        error_code = result_future.result().result.error_code.val
        if error_code == 1:
            self.get_logger().info("Trajectory execution succeeded")
            return True

        self.get_logger().error(f"Trajectory execution failed, error code: {error_code}")
        return False

    def move_to_pose(self, label, position, quaternion):
        self.get_logger().info(
            f"Moving to {label}: "
            f"pos={[round(float(v), 4) for v in position]}, "
            f"quat={[round(float(v), 4) for v in quaternion]}"
        )
        joint_positions = self.compute_ik(position, quaternion)
        if joint_positions is None:
            return False
        trajectory = self.plan_to_joints(joint_positions)
        if trajectory is None:
            return False
        return self.execute_trajectory(trajectory)

    def move_gripper(self, target_position):
        if not self.execute_motion:
            self.get_logger().info("execute_motion=false, skipping gripper command")
            return True

        goal = FollowJointTrajectory.Goal()
        trajectory = JointTrajectory()
        trajectory.joint_names = self.gripper_joint_names
        point = JointTrajectoryPoint()
        point.positions = [float(target_position)]
        point.time_from_start = Duration(seconds=1.5).to_msg()
        trajectory.points.append(point)
        goal.trajectory = trajectory

        send_goal_future = self.gripper_client.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, send_goal_future, timeout_sec=5.0)
        if not send_goal_future.done() or not send_goal_future.result().accepted:
            self.get_logger().error("Gripper goal was not accepted")
            return False

        result_future = send_goal_future.result().get_result_async()
        rclpy.spin_until_future_complete(self, result_future, timeout_sec=8.0)
        if not result_future.done():
            self.get_logger().error("Gripper command timed out")
            return False

        if result_future.result().result.error_code == 0:
            self.get_logger().info(f"Gripper moved to {target_position:.4f}")
            return True

        self.get_logger().error(
            f"Gripper command failed, error code: {result_future.result().result.error_code}"
        )
        return False

    def run_once(self):
        self.wait_for_servers()
        decision = self.request_decision_pose()

        xyz = np.array(decision["xyz"], dtype=float)
        rot = np.array(decision["rot"], dtype=float)
        dep = float(decision.get("dep", 0.0))
        decision_quaternion = rotation_matrix_to_quaternion(rot)

        self.get_logger().info(
            "Using grasp pose in "
            f"{self.base_frame}: xyz={xyz.tolist()}, "
            f"decision_quat={decision_quaternion}, dep={dep}"
        )

        selected_xyz, quaternion = self.select_reachable_grasp(xyz, decision_quaternion)
        if selected_xyz is None or quaternion is None:
            self.get_logger().error("No tested pose can reach pre_grasp/grasp/lift")
            return False

        if np.linalg.norm(selected_xyz - xyz) > 1e-6:
            self.get_logger().warn(
                "Original mock xyz is unreachable; using nearest reachable test xyz "
                f"{[round(float(v), 4) for v in selected_xyz]} instead of "
                f"{[round(float(v), 4) for v in xyz]}"
            )

        pre_grasp = selected_xyz + np.array([0.0, 0.0, self.pre_grasp_offset_z])
        grasp = selected_xyz
        lift = selected_xyz + np.array([0.0, 0.0, self.lift_offset_z])

        if not self.move_to_pose("pre_grasp", pre_grasp, quaternion):
            return False
        if not self.move_gripper(self.gripper_open):
            return False
        if not self.move_to_pose("grasp", grasp, quaternion):
            return False
        if not self.move_gripper(self.gripper_closed):
            return False
        if not self.move_to_pose("lift", lift, quaternion):
            return False

        self.get_logger().info("Mock ThinkGrasp pick sequence finished")
        return True

    def select_reachable_grasp(self, xyz, decision_quaternion):
        candidates = self.get_orientation_candidates(decision_quaternion)

        quaternion = self.select_reachable_quaternion(
            self.get_sequence_positions(xyz),
            candidates,
            timeout_sec=self.ik_timeout_sec,
        )
        if quaternion is not None:
            return xyz, quaternion

        if not self.fallback_search_enabled:
            return None, None

        self.get_logger().warn(
            "Original xyz is not reachable; scanning nearby mock points for a control-layer smoke test"
        )

        for candidate_xyz in self.iter_fallback_xyz(xyz):
            quaternion = self.select_reachable_quaternion(
                self.get_sequence_positions(candidate_xyz),
                candidates,
                timeout_sec=self.ik_probe_timeout_sec,
                quiet=True,
            )
            if quaternion is not None:
                return candidate_xyz, quaternion

        return None, None

    def get_sequence_positions(self, xyz):
        return [
            xyz + np.array([0.0, 0.0, self.pre_grasp_offset_z]),
            xyz,
            xyz + np.array([0.0, 0.0, self.lift_offset_z]),
        ]

    def iter_fallback_xyz(self, xyz):
        offsets = []
        for dx in self.fallback_x_offsets:
            for dy in self.fallback_y_offsets:
                for dz in self.fallback_z_offsets:
                    offsets.append(np.array([dx, dy, dz], dtype=float))
        offsets.sort(key=lambda item: float(np.linalg.norm(item)))
        for offset in offsets:
            candidate = xyz + offset
            self.get_logger().info(
                f"Testing nearby xyz: {[round(float(v), 4) for v in candidate]}"
            )
            yield candidate

    def get_orientation_candidates(self, decision_quaternion):
        candidates = []
        if self.use_decision_orientation:
            candidates.append(normalize_quaternion(decision_quaternion))
        candidates.extend(self.fallback_quaternions)

        unique_candidates = []
        seen = set()
        for candidate in candidates:
            canonical = canonical_quaternion(candidate)
            rounded = tuple(round(v, 6) for v in canonical)
            if rounded not in seen:
                unique_candidates.append(candidate)
                seen.add(rounded)
        return unique_candidates

    def select_reachable_quaternion(self, positions, candidates, timeout_sec, quiet=False):
        for index, candidate in enumerate(candidates, start=1):
            if not quiet:
                self.get_logger().info(
                    f"Testing orientation candidate {index}: {[round(v, 4) for v in candidate]}"
                )
            ok = True
            for position in positions:
                if self.compute_ik(
                    position,
                    candidate,
                    log_failure=False,
                    timeout_sec=timeout_sec,
                ) is None:
                    ok = False
                    break
            if ok:
                self.get_logger().info(
                    f"Selected orientation candidate {index}: {[round(v, 4) for v in candidate]}"
                )
                return candidate

        return None


def rotation_matrix_to_quaternion(matrix):
    m = np.asarray(matrix, dtype=float)
    if m.shape != (3, 3):
        raise ValueError("rot must be a 3x3 matrix")

    trace = np.trace(m)
    if trace > 0.0:
        s = np.sqrt(trace + 1.0) * 2.0
        qw = 0.25 * s
        qx = (m[2, 1] - m[1, 2]) / s
        qy = (m[0, 2] - m[2, 0]) / s
        qz = (m[1, 0] - m[0, 1]) / s
    elif m[0, 0] > m[1, 1] and m[0, 0] > m[2, 2]:
        s = np.sqrt(1.0 + m[0, 0] - m[1, 1] - m[2, 2]) * 2.0
        qw = (m[2, 1] - m[1, 2]) / s
        qx = 0.25 * s
        qy = (m[0, 1] + m[1, 0]) / s
        qz = (m[0, 2] + m[2, 0]) / s
    elif m[1, 1] > m[2, 2]:
        s = np.sqrt(1.0 + m[1, 1] - m[0, 0] - m[2, 2]) * 2.0
        qw = (m[0, 2] - m[2, 0]) / s
        qx = (m[0, 1] + m[1, 0]) / s
        qy = 0.25 * s
        qz = (m[1, 2] + m[2, 1]) / s
    else:
        s = np.sqrt(1.0 + m[2, 2] - m[0, 0] - m[1, 1]) * 2.0
        qw = (m[1, 0] - m[0, 1]) / s
        qx = (m[0, 2] + m[2, 0]) / s
        qy = (m[1, 2] + m[2, 1]) / s
        qz = 0.25 * s

    return normalize_quaternion([qx, qy, qz, qw])


def normalize_quaternion(quaternion):
    quat = np.array(quaternion, dtype=float)
    norm = np.linalg.norm(quat)
    if norm == 0.0:
        raise ValueError("quaternion norm is zero")
    quat /= norm
    return quat.tolist()


def canonical_quaternion(quaternion):
    quat = normalize_quaternion(quaternion)
    for value in quat:
        if abs(value) > 1e-9:
            if value < 0:
                quat = [-v for v in quat]
            break
    return quat


def main(args=None):
    rclpy.init(args=args)
    node = ThinkGraspMockPick()
    try:
        success = node.run_once()
        if not success:
            node.get_logger().error("Mock pick sequence failed")
    except KeyboardInterrupt:
        node.get_logger().warn("Interrupted by user")
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
