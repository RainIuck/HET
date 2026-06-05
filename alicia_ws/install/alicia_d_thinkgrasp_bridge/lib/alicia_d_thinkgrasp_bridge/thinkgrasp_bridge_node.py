#!/usr/bin/env python3
import json
import urllib.error
import urllib.request

import numpy as np
import rclpy
from alicia_d_control_interfaces.msg import GraspCandidate
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from std_srvs.srv import Trigger


class ThinkGraspBridge(Node):
    def __init__(self):
        super().__init__("thinkgrasp_bridge")
        self._declare_parameters()
        self._load_parameters()

        qos = QoSProfile(depth=1)
        qos.reliability = ReliabilityPolicy.RELIABLE
        qos.durability = DurabilityPolicy.VOLATILE
        self._candidate_pub = self.create_publisher(GraspCandidate, "grasp_candidate", qos)
        self._request_service = self.create_service(Trigger, "request_grasp", self._handle_request)
        self.get_logger().info(
            f"ThinkGrasp bridge ready: {self.decision_url} -> 'grasp_candidate'"
        )

    def _declare_parameters(self):
        self.declare_parameter("decision_url", "http://127.0.0.1:5000/grasp_pose")
        self.declare_parameter("image_path", "/tmp/mock_rgb.png")
        self.declare_parameter("depth_path", "/tmp/mock_depth.png")
        self.declare_parameter("text_path", "/tmp/mock_task.txt")
        self.declare_parameter("output_frame", "base_link")
        self.declare_parameter("source_name", "thinkgrasp")
        self.declare_parameter("request_timeout_s", 2.0)

    def _load_parameters(self):
        self.decision_url = str(self.get_parameter("decision_url").value)
        self.image_path = str(self.get_parameter("image_path").value)
        self.depth_path = str(self.get_parameter("depth_path").value)
        self.text_path = str(self.get_parameter("text_path").value)
        self.output_frame = str(self.get_parameter("output_frame").value)
        self.source_name = str(self.get_parameter("source_name").value)
        self.request_timeout_s = float(self.get_parameter("request_timeout_s").value)

    def _handle_request(self, _request, response):
        try:
            candidate = self._convert_decision(self._request_decision())
            self._candidate_pub.publish(candidate)
            response.success = True
            response.message = "Published grasp candidate"
            self.get_logger().info(
                "Published grasp candidate: "
                f"frame={candidate.header.frame_id}, "
                f"position=({candidate.grasp_pose.position.x:.4f}, "
                f"{candidate.grasp_pose.position.y:.4f}, "
                f"{candidate.grasp_pose.position.z:.4f})"
            )
        except Exception as exc:
            response.success = False
            response.message = str(exc)
            self.get_logger().error(f"Could not publish grasp candidate: {exc}")
        return response

    def _request_decision(self):
        payload = {
            "image_path": self.image_path,
            "depth_path": self.depth_path,
            "text_path": self.text_path,
        }
        request = urllib.request.Request(
            self.decision_url,
            data=json.dumps(payload).encode("utf-8"),
            headers={"Content-Type": "application/json"},
            method="POST",
        )
        try:
            with urllib.request.urlopen(request, timeout=self.request_timeout_s) as http_response:
                return json.loads(http_response.read().decode("utf-8"))
        except (urllib.error.URLError, TimeoutError, json.JSONDecodeError) as exc:
            raise RuntimeError(f"ThinkGrasp request failed: {exc}") from exc

    def _convert_decision(self, decision):
        if "xyz" not in decision or "rot" not in decision:
            raise ValueError("ThinkGrasp response must contain xyz and rot")
        xyz = np.asarray(decision["xyz"], dtype=float)
        rot = np.asarray(decision["rot"], dtype=float)
        if xyz.shape != (3,) or not np.all(np.isfinite(xyz)):
            raise ValueError("ThinkGrasp xyz must be three finite values")
        if rot.shape != (3, 3) or not np.all(np.isfinite(rot)):
            raise ValueError("ThinkGrasp rot must be a finite 3x3 matrix")

        quaternion = rotation_matrix_to_quaternion(rot)
        candidate = GraspCandidate()
        candidate.header.stamp = self.get_clock().now().to_msg()
        candidate.header.frame_id = self.output_frame
        candidate.grasp_pose.position.x = float(xyz[0])
        candidate.grasp_pose.position.y = float(xyz[1])
        candidate.grasp_pose.position.z = float(xyz[2])
        candidate.grasp_pose.orientation.x = float(quaternion[0])
        candidate.grasp_pose.orientation.y = float(quaternion[1])
        candidate.grasp_pose.orientation.z = float(quaternion[2])
        candidate.grasp_pose.orientation.w = float(quaternion[3])
        candidate.grasp_depth_m = float(decision.get("dep", 0.0))
        candidate.source = self.source_name
        return candidate


def rotation_matrix_to_quaternion(matrix):
    m = np.asarray(matrix, dtype=float)
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
    quaternion = np.array([qx, qy, qz, qw], dtype=float)
    norm = np.linalg.norm(quaternion)
    if norm == 0.0:
        raise ValueError("ThinkGrasp rotation produced a zero quaternion")
    return quaternion / norm


def main(args=None):
    rclpy.init(args=args)
    node = ThinkGraspBridge()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
