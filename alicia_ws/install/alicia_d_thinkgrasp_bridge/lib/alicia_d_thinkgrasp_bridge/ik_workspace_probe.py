#!/usr/bin/env python3
import csv
import math
import time

import numpy as np
import rclpy
from geometry_msgs.msg import PoseStamped
from moveit_msgs.srv import GetPositionFK, GetPositionIK
from rclpy.node import Node
from sensor_msgs.msg import JointState


class IKWorkspaceProbe(Node):
    def __init__(self):
        super().__init__("ik_workspace_probe")
        self.declare_parameter("base_frame", "base_link")
        self.declare_parameter("planning_group", "Alicia")
        self.declare_parameter("ik_link_name", "gripper_center")
        self.declare_parameter("ik_timeout_sec", 0.15)
        self.declare_parameter("target_xyz", [0.35, 0.0, 0.22])
        self.declare_parameter("x_values", [-0.25, -0.15, -0.05, 0.05, 0.15, 0.25, 0.35])
        self.declare_parameter("y_values", [-0.20, -0.10, 0.0, 0.10, 0.20])
        self.declare_parameter("z_values", [0.10, 0.15, 0.20, 0.25, 0.30, 0.35])
        self.declare_parameter("csv_path", "/tmp/alicia_d_ik_workspace.csv")
        self.declare_parameter(
            "orientation_quaternions_flat",
            [
                -1.0, 0.0, 0.0, 0.0,
                1.0, 0.0, 0.0, 0.0,
                0.0, 1.0, 0.0, 0.0,
                0.0, 0.0, 1.0, 0.0,
                0.0, 0.0, 0.0, 1.0,
            ],
        )

        self.base_frame = self.get_parameter("base_frame").value
        self.planning_group = self.get_parameter("planning_group").value
        self.ik_link_name = self.get_parameter("ik_link_name").value
        self.ik_timeout_sec = float(self.get_parameter("ik_timeout_sec").value)
        self.target_xyz = np.array([float(v) for v in self.get_parameter("target_xyz").value])
        self.x_values = [float(v) for v in self.get_parameter("x_values").value]
        self.y_values = [float(v) for v in self.get_parameter("y_values").value]
        self.z_values = [float(v) for v in self.get_parameter("z_values").value]
        self.csv_path = self.get_parameter("csv_path").value

        flat = [float(v) for v in self.get_parameter("orientation_quaternions_flat").value]
        if len(flat) % 4 != 0:
            raise ValueError("orientation_quaternions_flat length must be divisible by 4")
        self.orientations = []
        seen = set()
        for i in range(0, len(flat), 4):
            quat = normalize_quaternion(flat[i:i + 4])
            canonical = tuple(round(v, 6) for v in canonical_quaternion(quat))
            if canonical not in seen:
                self.orientations.append(quat)
                seen.add(canonical)

        self.current_joint_state = None
        self.create_subscription(JointState, "/joint_states", self._on_joint_state, 10)
        self.ik_client = self.create_client(GetPositionIK, "/compute_ik")
        self.fk_client = self.create_client(GetPositionFK, "/compute_fk")

    def _on_joint_state(self, msg):
        self.current_joint_state = msg

    def wait_for_services(self):
        self.get_logger().info("Waiting for /compute_ik...")
        self.ik_client.wait_for_service()
        if not self.fk_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().warn("/compute_fk is not available; skipping current TCP pose")
        start = time.time()
        while self.current_joint_state is None and time.time() - start < 3.0:
            rclpy.spin_once(self, timeout_sec=0.1)

    def log_current_state(self):
        if self.current_joint_state is None:
            self.get_logger().warn("No /joint_states received")
            return

        arm_names = ["Joint1", "Joint2", "Joint3", "Joint4", "Joint5", "Joint6"]
        joints = []
        for name in arm_names:
            if name in self.current_joint_state.name:
                index = self.current_joint_state.name.index(name)
                joints.append(self.current_joint_state.position[index])
        if joints:
            self.get_logger().info(f"Current arm joints: {[round(v, 4) for v in joints]}")

        if not self.fk_client.service_is_ready():
            return

        request = GetPositionFK.Request()
        request.header.frame_id = self.base_frame
        request.fk_link_names = [self.ik_link_name]
        request.robot_state.joint_state = self.current_joint_state
        future = self.fk_client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=2.0)
        if not future.done() or future.result().error_code.val != 1:
            self.get_logger().warn("Could not compute current TCP pose with /compute_fk")
            return

        pose = future.result().pose_stamped[0].pose
        self.get_logger().info(
            "Current gripper_center pose in "
            f"{self.base_frame}: "
            f"x={pose.position.x:.4f}, y={pose.position.y:.4f}, z={pose.position.z:.4f}, "
            f"q=({pose.orientation.x:.4f}, {pose.orientation.y:.4f}, "
            f"{pose.orientation.z:.4f}, {pose.orientation.w:.4f})"
        )

    def compute_ik(self, xyz, quat):
        request = GetPositionIK.Request()
        request.ik_request.group_name = self.planning_group
        request.ik_request.ik_link_name = self.ik_link_name
        request.ik_request.avoid_collisions = False
        sec = int(self.ik_timeout_sec)
        request.ik_request.timeout.sec = sec
        request.ik_request.timeout.nanosec = int((self.ik_timeout_sec - sec) * 1e9)
        request.ik_request.pose_stamped = PoseStamped()
        request.ik_request.pose_stamped.header.frame_id = self.base_frame
        request.ik_request.pose_stamped.header.stamp = self.get_clock().now().to_msg()
        request.ik_request.pose_stamped.pose.position.x = float(xyz[0])
        request.ik_request.pose_stamped.pose.position.y = float(xyz[1])
        request.ik_request.pose_stamped.pose.position.z = float(xyz[2])
        request.ik_request.pose_stamped.pose.orientation.x = float(quat[0])
        request.ik_request.pose_stamped.pose.orientation.y = float(quat[1])
        request.ik_request.pose_stamped.pose.orientation.z = float(quat[2])
        request.ik_request.pose_stamped.pose.orientation.w = float(quat[3])
        if self.current_joint_state is not None:
            request.ik_request.robot_state.joint_state = self.current_joint_state

        future = self.ik_client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=self.ik_timeout_sec + 0.3)
        if not future.done():
            return False, None
        response = future.result()
        return response.error_code.val == 1, response.error_code.val

    def run(self):
        self.wait_for_services()
        self.log_current_state()

        total = len(self.x_values) * len(self.y_values) * len(self.z_values)
        self.get_logger().info(
            f"Scanning {total} xyz points with {len(self.orientations)} orientation candidates"
        )

        rows = []
        reachable = []
        for x in self.x_values:
            for y in self.y_values:
                for z in self.z_values:
                    xyz = np.array([x, y, z], dtype=float)
                    success = False
                    winning_quat = None
                    last_error = None
                    for quat in self.orientations:
                        success, last_error = self.compute_ik(xyz, quat)
                        if success:
                            winning_quat = quat
                            break
                    distance = float(np.linalg.norm(xyz - self.target_xyz))
                    rows.append({
                        "x": x,
                        "y": y,
                        "z": z,
                        "reachable": int(success),
                        "distance_to_target": distance,
                        "qx": winning_quat[0] if winning_quat else "",
                        "qy": winning_quat[1] if winning_quat else "",
                        "qz": winning_quat[2] if winning_quat else "",
                        "qw": winning_quat[3] if winning_quat else "",
                        "last_error": "" if success else last_error,
                    })
                    if success:
                        reachable.append((distance, xyz, winning_quat))

        self.write_csv(rows)
        self.print_summary(reachable)

    def write_csv(self, rows):
        with open(self.csv_path, "w", newline="", encoding="utf-8") as csv_file:
            writer = csv.DictWriter(csv_file, fieldnames=list(rows[0].keys()))
            writer.writeheader()
            writer.writerows(rows)
        self.get_logger().info(f"Wrote IK scan CSV: {self.csv_path}")

    def print_summary(self, reachable):
        if not reachable:
            self.get_logger().error("No reachable points found in this scan grid")
            return

        points = np.array([item[1] for item in reachable])
        self.get_logger().info(f"Reachable points: {len(reachable)}")
        self.get_logger().info(
            "Reachable bounds in base_link: "
            f"x=[{points[:, 0].min():.3f}, {points[:, 0].max():.3f}], "
            f"y=[{points[:, 1].min():.3f}, {points[:, 1].max():.3f}], "
            f"z=[{points[:, 2].min():.3f}, {points[:, 2].max():.3f}]"
        )

        reachable.sort(key=lambda item: item[0])
        self.get_logger().info("Nearest reachable points to target:")
        for distance, xyz, quat in reachable[:10]:
            self.get_logger().info(
                f"  xyz={[round(float(v), 3) for v in xyz]}, "
                f"dist={distance:.3f}, quat={[round(float(v), 3) for v in quat]}"
            )


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
    node = IKWorkspaceProbe()
    try:
        node.run()
    except KeyboardInterrupt:
        node.get_logger().warn("Interrupted by user")
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
