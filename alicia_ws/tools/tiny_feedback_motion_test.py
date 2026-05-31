#!/usr/bin/env python3
"""Send a tiny arm joint move and record feedback before/during/after.

Run this while real_robot.launch.py is already active. The script sends one
FollowJointTrajectory goal to Alicia_controller and logs /joint_states plus
controller actual/desired/error for later comparison.
"""

from __future__ import annotations

import argparse
import csv
import json
import math
import time
from datetime import datetime
from pathlib import Path
from typing import Any

import rclpy
from control_msgs.action import FollowJointTrajectory
from control_msgs.msg import JointTrajectoryControllerState
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.utilities import remove_ros_args
from sensor_msgs.msg import JointState
from trajectory_msgs.msg import JointTrajectoryPoint


ARM_JOINTS = ["Joint1", "Joint2", "Joint3", "Joint4", "Joint5", "Joint6"]


class TinyFeedbackMotionTest(Node):
    def __init__(self, args: argparse.Namespace):
        super().__init__("tiny_feedback_motion_test")
        self.args = args
        self.joint_state: JointState | None = None
        self.controller_state: JointTrajectoryControllerState | None = None
        self.samples: list[dict[str, Any]] = []

        self.create_subscription(JointState, args.joint_state_topic, self._on_joint_state, 20)
        self.create_subscription(
            JointTrajectoryControllerState,
            args.controller_state_topic,
            self._on_controller_state,
            20,
        )
        self.action_client = ActionClient(
            self,
            FollowJointTrajectory,
            args.action_name,
        )

    def _on_joint_state(self, msg: JointState) -> None:
        self.joint_state = msg

    def _on_controller_state(self, msg: JointTrajectoryControllerState) -> None:
        self.controller_state = msg

    def wait_until_ready(self) -> None:
        self.get_logger().info("Waiting for /joint_states and controller action server...")
        start = time.time()
        while rclpy.ok() and time.time() - start < self.args.timeout:
            rclpy.spin_once(self, timeout_sec=0.1)
            if self._current_arm_positions() is not None and self.action_client.server_is_ready():
                return
        if not self.action_client.server_is_ready():
            self.action_client.wait_for_server(timeout_sec=1.0)
        if self._current_arm_positions() is None:
            raise RuntimeError("No complete arm joint state received")
        if not self.action_client.server_is_ready():
            raise RuntimeError(f"Action server not ready: {self.args.action_name}")

    def _current_arm_positions(self) -> list[float] | None:
        if self.joint_state is None:
            return None
        by_name = dict(zip(self.joint_state.name, self.joint_state.position))
        if not all(name in by_name for name in ARM_JOINTS):
            return None
        return [float(by_name[name]) for name in ARM_JOINTS]

    def _controller_value(self, field_name: str, joint_name: str) -> float | None:
        if self.controller_state is None:
            return None
        try:
            idx = list(self.controller_state.joint_names).index(joint_name)
        except ValueError:
            return None
        field = getattr(self.controller_state, field_name)
        if idx >= len(field.positions):
            return None
        return float(field.positions[idx])

    def sample(self, phase: str) -> None:
        positions = self._current_arm_positions()
        if positions is None:
            return
        by_name = dict(zip(ARM_JOINTS, positions))
        joint = self.args.joint
        record = {
            "time": time.time(),
            "phase": phase,
            "joint": joint,
            "joint_state_position": by_name[joint],
            "controller_actual": self._controller_value("actual", joint),
            "controller_desired": self._controller_value("desired", joint),
            "controller_error": self._controller_value("error", joint),
            "arm_positions": dict(zip(ARM_JOINTS, positions)),
        }
        self.samples.append(record)

    def spin_and_sample(self, seconds: float, phase: str) -> None:
        end_time = time.time() + seconds
        next_sample = 0.0
        while rclpy.ok() and time.time() < end_time:
            rclpy.spin_once(self, timeout_sec=0.02)
            now = time.time()
            if now >= next_sample:
                self.sample(phase)
                next_sample = now + self.args.sample_period

    def send_goal(self, target_positions: list[float]) -> None:
        goal = FollowJointTrajectory.Goal()
        goal.trajectory.joint_names = list(ARM_JOINTS)
        point = JointTrajectoryPoint()
        point.positions = [float(value) for value in target_positions]
        point.velocities = [0.0] * len(ARM_JOINTS)
        point.time_from_start.sec = int(self.args.duration)
        point.time_from_start.nanosec = int((self.args.duration % 1.0) * 1e9)
        goal.trajectory.points.append(point)

        future = self.action_client.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, future, timeout_sec=self.args.timeout)
        if not future.done() or not future.result().accepted:
            raise RuntimeError("FollowJointTrajectory goal was rejected")

        result_future = future.result().get_result_async()
        deadline = time.time() + self.args.duration + self.args.timeout
        while rclpy.ok() and time.time() < deadline:
            rclpy.spin_once(self, timeout_sec=0.02)
            self.sample("moving")
            if result_future.done():
                break
            time.sleep(self.args.sample_period)

        if not result_future.done():
            raise RuntimeError("FollowJointTrajectory result timed out")
        result = result_future.result().result
        if result.error_code != FollowJointTrajectory.Result.SUCCESSFUL:
            raise RuntimeError(f"FollowJointTrajectory failed with code {result.error_code}")

    def run(self) -> dict[str, Any]:
        self.wait_until_ready()
        self.spin_and_sample(self.args.pre_sample_seconds, "before")

        current_positions = self._current_arm_positions()
        if current_positions is None:
            raise RuntimeError("Lost complete arm joint state before sending goal")
        joint_index = ARM_JOINTS.index(self.args.joint)
        target_positions = list(current_positions)
        target_positions[joint_index] += self.args.delta

        self.get_logger().info(f"Current {self.args.joint}: {current_positions[joint_index]:.6f} rad")
        self.get_logger().info(f"Target  {self.args.joint}: {target_positions[joint_index]:.6f} rad")
        self.get_logger().info(f"Delta: {self.args.delta:.6f} rad, duration: {self.args.duration:.2f} s")

        if self.args.dry_run:
            self.get_logger().info("dry_run=true; not sending trajectory")
        else:
            self.send_goal(target_positions)

        self.spin_and_sample(self.args.post_sample_seconds, "after")

        return self.summary(current_positions, target_positions)

    def summary(self, start_positions: list[float], target_positions: list[float]) -> dict[str, Any]:
        joint = self.args.joint
        joint_values = [sample["joint_state_position"] for sample in self.samples]
        actual_values = [
            sample["controller_actual"]
            for sample in self.samples
            if sample["controller_actual"] is not None and math.isfinite(sample["controller_actual"])
        ]
        desired_values = [
            sample["controller_desired"]
            for sample in self.samples
            if sample["controller_desired"] is not None and math.isfinite(sample["controller_desired"])
        ]
        error_values = [
            sample["controller_error"]
            for sample in self.samples
            if sample["controller_error"] is not None and math.isfinite(sample["controller_error"])
        ]
        start = start_positions[ARM_JOINTS.index(joint)]
        target = target_positions[ARM_JOINTS.index(joint)]
        end = joint_values[-1] if joint_values else None
        return {
            "label": self.args.label,
            "joint": joint,
            "requested_delta_rad": self.args.delta,
            "start_rad": start,
            "target_rad": target,
            "end_rad": end,
            "observed_delta_rad": None if end is None else end - start,
            "joint_state_min_rad": min(joint_values) if joint_values else None,
            "joint_state_max_rad": max(joint_values) if joint_values else None,
            "controller_actual_min_rad": min(actual_values) if actual_values else None,
            "controller_actual_max_rad": max(actual_values) if actual_values else None,
            "controller_desired_min_rad": min(desired_values) if desired_values else None,
            "controller_desired_max_rad": max(desired_values) if desired_values else None,
            "controller_error_abs_max_rad": max(abs(value) for value in error_values) if error_values else None,
            "sample_count": len(self.samples),
        }

    def write_logs(self, summary: dict[str, Any]) -> Path:
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        log_dir = Path(self.args.log_dir) / f"tiny_feedback_motion_{timestamp}_{self.args.label}"
        log_dir.mkdir(parents=True, exist_ok=True)
        (log_dir / "summary.json").write_text(json.dumps(summary, indent=2), encoding="utf-8")

        with (log_dir / "samples.csv").open("w", newline="", encoding="utf-8") as csv_file:
            writer = csv.writer(csv_file)
            writer.writerow(
                [
                    "time",
                    "phase",
                    "joint",
                    "joint_state_position",
                    "controller_actual",
                    "controller_desired",
                    "controller_error",
                    *ARM_JOINTS,
                ]
            )
            for sample in self.samples:
                arm = sample["arm_positions"]
                writer.writerow(
                    [
                        sample["time"],
                        sample["phase"],
                        sample["joint"],
                        sample["joint_state_position"],
                        sample["controller_actual"],
                        sample["controller_desired"],
                        sample["controller_error"],
                        *(arm[name] for name in ARM_JOINTS),
                    ]
                )
        return log_dir


def build_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Tiny Alicia-D feedback motion test.")
    parser.add_argument("--joint", choices=ARM_JOINTS, default="Joint6")
    parser.add_argument("--delta", type=float, default=0.03, help="Small relative move in radians.")
    parser.add_argument("--duration", type=float, default=3.0, help="Trajectory duration in seconds.")
    parser.add_argument("--label", default="test", help="Log label, e.g. with_gripper or no_gripper.")
    parser.add_argument("--dry-run", action="store_true")
    parser.add_argument("--timeout", type=float, default=8.0)
    parser.add_argument("--pre-sample-seconds", type=float, default=1.0)
    parser.add_argument("--post-sample-seconds", type=float, default=1.5)
    parser.add_argument("--sample-period", type=float, default=0.05)
    parser.add_argument("--joint-state-topic", default="/joint_states")
    parser.add_argument("--controller-state-topic", default="/Alicia_controller/controller_state")
    parser.add_argument("--action-name", default="/Alicia_controller/follow_joint_trajectory")
    parser.add_argument(
        "--log-dir",
        default=str(Path(__file__).resolve().parents[1] / "experiment_logs" / "feedback_motion"),
    )
    return parser


def main() -> int:
    parser = build_arg_parser()
    args = parser.parse_args(remove_ros_args()[1:])

    rclpy.init()
    node = TinyFeedbackMotionTest(args)
    try:
        summary = node.run()
        log_dir = node.write_logs(summary)
        print(json.dumps(summary, indent=2))
        print(f"log_dir: {log_dir}")
        return 0
    except Exception as exc:
        node.get_logger().error(str(exc))
        return 1
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    raise SystemExit(main())
