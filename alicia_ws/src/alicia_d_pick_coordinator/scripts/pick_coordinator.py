#!/usr/bin/env python3
import copy
import math
import threading
import time

import rclpy
from alicia_d_control_interfaces.action import (
    ForceGrasp,
    HomeGripper,
    MoveArmToJoints,
    MoveArmToPose,
    MoveGripper,
)
from alicia_d_control_interfaces.msg import GraspCandidate
from geometry_msgs.msg import PoseStamped
from rclpy.action import ActionClient
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy


class PickCoordinator(Node):
    def __init__(self):
        super().__init__("pick_coordinator")
        self._declare_parameters()
        self._load_parameters()

        self._pick_lock = threading.Lock()
        self._pick_busy = False
        self._gripper_initialized = False
        self._initialization_started = False
        self._initialization_lock = threading.Lock()

        qos = QoSProfile(depth=1)
        qos.reliability = ReliabilityPolicy.RELIABLE
        qos.durability = DurabilityPolicy.VOLATILE
        self.create_subscription(
            GraspCandidate,
            "/thinkgrasp/grasp_candidate",
            self._on_candidate,
            qos,
        )
        self._arm_client = ActionClient(self, MoveArmToPose, "/arm_motion/move_to_pose")
        self._arm_joint_client = ActionClient(
            self,
            MoveArmToJoints,
            "/arm_motion/move_to_joints",
        )
        self._home_client = ActionClient(self, HomeGripper, "/new_gripper/home")
        self._move_gripper_client = ActionClient(
            self,
            MoveGripper,
            "/new_gripper/move_relative",
        )
        self._force_grasp_client = ActionClient(
            self,
            ForceGrasp,
            "/new_gripper/force_grasp",
        )
        self._init_timer = self.create_timer(1.0, self._start_initialization)
        self.get_logger().info(
            "Pick coordinator ready: each new '/thinkgrasp/grasp_candidate' "
            "triggers one pick sequence"
        )

    def _declare_parameters(self):
        self.declare_parameter("initialize_gripper_on_start", False)
        self.declare_parameter("interface_wait_timeout_s", 10.0)
        self.declare_parameter("action_timeout_s", 45.0)
        self.declare_parameter("pre_grasp_offset_z", 0.05)
        self.declare_parameter("lift_offset_z", 0.05)
        self.declare_parameter("gripper_open_ticks", 0)
        self.declare_parameter("force_grasp_current_threshold_raw", 0)
        self.declare_parameter("force_grasp_max_ticks", 0)
        self.declare_parameter("force_grasp_speed", 0)
        self.declare_parameter("arm_ik_link_name", "gripper_center")
        self.declare_parameter("arm_max_velocity_scaling", 0.25)
        self.declare_parameter("arm_max_acceleration_scaling", 0.25)
        self.declare_parameter("arm_avoid_collisions", False)
        self.declare_parameter("arm_execute", True)
        self.declare_parameter("post_grasp_intermediate_joint_names", [""])
        self.declare_parameter("post_grasp_intermediate_joint_positions", [float("nan")])

    def _load_parameters(self):
        self.initialize_gripper_on_start = bool(
            self.get_parameter("initialize_gripper_on_start").value
        )
        self.interface_wait_timeout_s = float(
            self.get_parameter("interface_wait_timeout_s").value
        )
        self.action_timeout_s = float(self.get_parameter("action_timeout_s").value)
        self.pre_grasp_offset_z = float(self.get_parameter("pre_grasp_offset_z").value)
        self.lift_offset_z = float(self.get_parameter("lift_offset_z").value)
        self.gripper_open_ticks = int(self.get_parameter("gripper_open_ticks").value)
        self.force_grasp_current_threshold_raw = int(
            self.get_parameter("force_grasp_current_threshold_raw").value
        )
        self.force_grasp_max_ticks = int(self.get_parameter("force_grasp_max_ticks").value)
        self.force_grasp_speed = int(self.get_parameter("force_grasp_speed").value)
        self.arm_ik_link_name = str(self.get_parameter("arm_ik_link_name").value)
        self.arm_max_velocity_scaling = float(
            self.get_parameter("arm_max_velocity_scaling").value
        )
        self.arm_max_acceleration_scaling = float(
            self.get_parameter("arm_max_acceleration_scaling").value
        )
        self.arm_avoid_collisions = bool(self.get_parameter("arm_avoid_collisions").value)
        self.arm_execute = bool(self.get_parameter("arm_execute").value)
        self.post_grasp_intermediate_joint_names = [
            str(value)
            for value in self.get_parameter("post_grasp_intermediate_joint_names").value
        ]
        self.post_grasp_intermediate_joint_positions = [
            float(value)
            for value in self.get_parameter("post_grasp_intermediate_joint_positions").value
        ]

    def _on_candidate(self, msg):
        with self._pick_lock:
            if self._pick_busy:
                self.get_logger().warn(
                    "Ignoring grasp candidate while a pick sequence is active"
                )
                return
            self._pick_busy = True

        candidate = copy.deepcopy(msg)
        self.get_logger().info(
            "Received grasp candidate; starting pick sequence: "
            f"source={candidate.source}, frame={candidate.header.frame_id}, "
            f"position=({candidate.grasp_pose.position.x:.4f}, "
            f"{candidate.grasp_pose.position.y:.4f}, "
            f"{candidate.grasp_pose.position.z:.4f})"
        )
        threading.Thread(
            target=self._execute_candidate,
            args=(candidate,),
            daemon=True,
        ).start()

    def _start_initialization(self):
        if self._initialization_started or not self.initialize_gripper_on_start:
            self._init_timer.cancel()
            return
        self._initialization_started = True
        self._init_timer.cancel()
        threading.Thread(target=self._initialize_gripper, daemon=True).start()

    def _initialize_gripper(self):
        with self._initialization_lock:
            self.get_logger().info("Initializing gripper with home action")
            success, message = self._call_home()
            self._gripper_initialized = success
            if success:
                self.get_logger().info("Gripper initialization complete")
            else:
                self.get_logger().warn(f"Gripper initialization failed: {message}")

    @staticmethod
    def _wait_future(future, timeout_s):
        deadline = time.monotonic() + timeout_s
        while not future.done() and time.monotonic() < deadline:
            time.sleep(0.01)
        return future.done()

    def _publish_stage(self, stage):
        self.get_logger().info(f"Pick stage: {stage}")

    def _execute_candidate(self, candidate):
        try:
            waypoint_error = self._validate_post_grasp_intermediate()
            if waypoint_error:
                self.get_logger().error(waypoint_error)
                return

            self._publish_stage("waiting_for_interfaces")
            if not self._wait_for_interfaces():
                self.get_logger().error("Required control interfaces are unavailable")
                return

            pre_grasp, grasp, lift = self._build_sequence(candidate)

            if not self._move_arm("moving_pre_grasp", pre_grasp):
                self.get_logger().error("Could not reach pre_grasp")
                return
            if not self._move_gripper("opening_gripper", self.gripper_open_ticks):
                self.get_logger().error("Could not open gripper")
                return
            if not self._move_arm("moving_grasp", grasp):
                self.get_logger().error("Could not reach grasp")
                return
            if not self._force_grasp():
                self.get_logger().error("Force grasp did not detect contact")
                return
            if not self._move_arm("moving_lift", lift):
                self.get_logger().error("Could not reach lift")
                return
            if not self._move_arm_to_joints(
                "moving_post_grasp_intermediate",
                self.post_grasp_intermediate_joint_names,
                self.post_grasp_intermediate_joint_positions,
            ):
                self.get_logger().error("Could not reach post-grasp intermediate waypoint")
                return

            self._publish_stage("complete")
            self.get_logger().info("Pick sequence complete")
        except Exception as exc:
            self.get_logger().error(f"Pick sequence failed: {exc}")
        finally:
            with self._pick_lock:
                self._pick_busy = False

    def _wait_for_interfaces(self):
        timeout = self.interface_wait_timeout_s
        return (
            self._arm_client.wait_for_server(timeout_sec=timeout)
            and self._arm_joint_client.wait_for_server(timeout_sec=timeout)
            and self._home_client.wait_for_server(timeout_sec=timeout)
            and self._move_gripper_client.wait_for_server(timeout_sec=timeout)
            and self._force_grasp_client.wait_for_server(timeout_sec=timeout)
        )

    def _call_action(self, client, goal):
        send_future = client.send_goal_async(goal)
        if not self._wait_future(send_future, self.action_timeout_s):
            return None
        goal_handle = send_future.result()
        if not goal_handle.accepted:
            return None
        result_future = goal_handle.get_result_async()
        if not self._wait_future(result_future, self.action_timeout_s):
            return None
        return result_future.result().result

    def _call_home(self):
        if not self._home_client.wait_for_server(timeout_sec=self.interface_wait_timeout_s):
            return False, "Home action is unavailable"
        result = self._call_action(self._home_client, HomeGripper.Goal())
        if result is None:
            return False, "Home action timed out or was rejected"
        return bool(result.success), result.message

    def _build_sequence(self, candidate):
        grasp = PoseStamped()
        grasp.header = candidate.header
        grasp.pose = candidate.grasp_pose
        pre_grasp = copy.deepcopy(grasp)
        pre_grasp.pose.position.z += self.pre_grasp_offset_z
        lift = copy.deepcopy(grasp)
        lift.pose.position.z += self.lift_offset_z
        return pre_grasp, grasp, lift

    def _validate_post_grasp_intermediate(self):
        names = self.post_grasp_intermediate_joint_names
        positions = self.post_grasp_intermediate_joint_positions
        expected_names = {"Joint1", "Joint2", "Joint3", "Joint4", "Joint5", "Joint6"}
        if len(names) != 6 or len(positions) != 6:
            return (
                "Post-grasp intermediate waypoint is not configured: expected "
                "6 joint names and 6 joint positions in waypoints.yaml"
            )
        if len(set(names)) != 6 or set(names) != expected_names:
            return (
                "Post-grasp intermediate waypoint has invalid joint names: "
                f"{names}"
            )
        if not all(math.isfinite(value) for value in positions):
            return (
                "Post-grasp intermediate waypoint still contains non-finite "
                "placeholder values; fill waypoints.yaml before picking"
            )
        return ""

    def _move_arm(self, stage, target_pose):
        self._publish_stage(stage)
        goal = MoveArmToPose.Goal()
        goal.target_pose = target_pose
        goal.ik_link_name = self.arm_ik_link_name
        goal.max_velocity_scaling = self.arm_max_velocity_scaling
        goal.max_acceleration_scaling = self.arm_max_acceleration_scaling
        goal.avoid_collisions = self.arm_avoid_collisions
        goal.execute = self.arm_execute
        result = self._call_action(self._arm_client, goal)
        return result is not None and result.success

    def _move_arm_to_joints(self, stage, joint_names, joint_positions):
        self._publish_stage(stage)
        goal = MoveArmToJoints.Goal()
        goal.joint_names = list(joint_names)
        goal.joint_positions = list(joint_positions)
        goal.max_velocity_scaling = self.arm_max_velocity_scaling
        goal.max_acceleration_scaling = self.arm_max_acceleration_scaling
        goal.execute = self.arm_execute
        result = self._call_action(self._arm_joint_client, goal)
        return result is not None and result.success

    def _move_gripper(self, stage, target_ticks):
        self._publish_stage(stage)
        goal = MoveGripper.Goal()
        goal.target_ticks = int(target_ticks)
        goal.speed = 0
        result = self._call_action(self._move_gripper_client, goal)
        return result is not None and result.success

    def _force_grasp(self):
        self._publish_stage("force_grasp")
        goal = ForceGrasp.Goal()
        goal.current_threshold_raw = self.force_grasp_current_threshold_raw
        goal.max_ticks = self.force_grasp_max_ticks
        goal.speed = self.force_grasp_speed
        result = self._call_action(self._force_grasp_client, goal)
        return result is not None and result.success and result.contact_detected


def main(args=None):
    rclpy.init(args=args)
    node = PickCoordinator()
    executor = MultiThreadedExecutor(num_threads=6)
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
