#!/usr/bin/env python3
import argparse
import csv
import json
import sys
from datetime import datetime
from pathlib import Path

import rclpy
from alicia_d_control_interfaces.msg import GripperState
from rclpy.node import Node


SCRIPT_PATH = Path(__file__).resolve()
ALICIA_WS = SCRIPT_PATH.parents[1]
DEFAULT_LOG_ROOT = ALICIA_WS / "experiment_logs" / "gripper_debug_state"


def signed16(value):
    value = int(value) & 0xFFFF
    return value - 0x10000 if value & 0x8000 else value


def wrap_delta(current, previous, modulus=4096):
    delta = int(current) - int(previous)
    half = modulus // 2
    if delta > half:
        delta -= modulus
    elif delta < -half:
        delta += modulus
    return delta


class GripperDebugRecorder(Node):
    def __init__(self, args, csv_writer):
        super().__init__("gripper_debug_state_recorder")
        self.args = args
        self.csv_writer = csv_writer
        self.start_ns = self.get_clock().now().nanoseconds
        self.last_in_turn = None
        self.turn_delta_total = 0
        self.sample_count = 0
        self.create_subscription(GripperState, args.topic, self.on_state, 50)

    def on_state(self, msg):
        now = self.get_clock().now()
        elapsed_s = (now.nanoseconds - self.start_ns) / 1e9

        raw_i32 = int(msg.raw_position)
        raw_u16 = raw_i32 & 0xFFFF
        in_turn_12bit = raw_u16 & 0x0FFF
        delta_in_turn = 0
        if self.last_in_turn is not None:
            delta_in_turn = wrap_delta(in_turn_12bit, self.last_in_turn)
            self.turn_delta_total += delta_in_turn
        self.last_in_turn = in_turn_12bit

        row = {
            "sample": self.sample_count,
            "elapsed_s": f"{elapsed_s:.6f}",
            "ros_stamp_sec": int(msg.header.stamp.sec),
            "ros_stamp_nanosec": int(msg.header.stamp.nanosec),
            "connected": bool(msg.connected),
            "homed": bool(msg.homed),
            "raw_position_i32": raw_i32,
            "raw_position_u16": raw_u16,
            "raw_position_hex": f"0x{raw_u16:04X}",
            "position_in_turn_12bit": in_turn_12bit,
            "raw_signed16": signed16(raw_u16),
            "delta_in_turn": delta_in_turn,
            "turn_delta_total": self.turn_delta_total,
            "node_relative_ticks": int(msg.relative_ticks),
            "target_position": int(getattr(msg, "target_position", 0)),
            "position_error_direction": bool(
                getattr(msg, "position_error_direction", False)
            ),
            "position_error_ticks": int(getattr(msg, "position_error_ticks", 0)),
            "estimated_position_minus": int(
                getattr(msg, "estimated_position_minus", 0)
            ),
            "estimated_position_plus": int(
                getattr(msg, "estimated_position_plus", 0)
            ),
            "moving": bool(msg.moving),
            "load_raw": int(msg.load_raw),
            "current_raw": int(msg.current_raw),
            "voltage_v": f"{float(msg.voltage_v):.3f}",
            "temperature_c": int(msg.temperature_c),
            "fault": msg.fault,
        }
        self.csv_writer.writerow(row)
        self.sample_count += 1

        if self.args.print_every > 0 and self.sample_count % self.args.print_every == 0:
            print(
                "t={elapsed_s}s raw={raw_position_hex} "
                "u16={raw_position_u16} in_turn={position_in_turn_12bit} "
                "d={delta_in_turn:+d} total={turn_delta_total:+d} "
                "node_rel={node_relative_ticks} moving={moving} "
                "load={load_raw} current={current_raw} fault={fault}".format(**row),
                flush=True,
            )


def make_run_dir(root):
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    run_dir = Path(root) / f"gripper_debug_{timestamp}"
    run_dir.mkdir(parents=True, exist_ok=False)
    return run_dir


def main():
    parser = argparse.ArgumentParser(
        description="Record derived STS3215 gripper state for multi-turn feedback debugging."
    )
    parser.add_argument("--topic", default="/new_gripper/state")
    parser.add_argument("--log-root", default=str(DEFAULT_LOG_ROOT))
    parser.add_argument(
        "--print-every",
        type=int,
        default=1,
        help="Print every N samples. Use 0 to only write CSV.",
    )
    parser.add_argument(
        "--duration",
        type=float,
        default=0.0,
        help="Seconds to record. 0 means record until Ctrl-C.",
    )
    args = parser.parse_args()

    run_dir = make_run_dir(args.log_root)
    csv_path = run_dir / "gripper_state_debug.csv"
    meta_path = run_dir / "metadata.json"

    fields = [
        "sample",
        "elapsed_s",
        "ros_stamp_sec",
        "ros_stamp_nanosec",
        "connected",
        "homed",
        "raw_position_i32",
        "raw_position_u16",
        "raw_position_hex",
        "position_in_turn_12bit",
        "raw_signed16",
        "delta_in_turn",
        "turn_delta_total",
        "node_relative_ticks",
        "target_position",
        "position_error_direction",
        "position_error_ticks",
        "estimated_position_minus",
        "estimated_position_plus",
        "moving",
        "load_raw",
        "current_raw",
        "voltage_v",
        "temperature_c",
        "fault",
    ]

    metadata = {
        "created_at": datetime.now().isoformat(timespec="seconds"),
        "topic": args.topic,
        "csv": str(csv_path),
        "notes": [
            "position_in_turn_12bit is raw_position_u16 & 0x0FFF.",
            "turn_delta_total is derived by wrapping low-12-bit deltas across 0/4095.",
            "node_relative_ticks is the value currently published by the gripper node.",
        ],
    }
    meta_path.write_text(json.dumps(metadata, indent=2), encoding="utf-8")

    print(f"Recording gripper debug state to: {run_dir}")
    print(f"CSV: {csv_path}")
    print("Press Ctrl-C to stop.")

    rclpy.init()
    with csv_path.open("w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=fields)
        writer.writeheader()
        node = GripperDebugRecorder(args, writer)
        try:
            if args.duration > 0:
                deadline = node.get_clock().now().nanoseconds + int(args.duration * 1e9)
                while rclpy.ok() and node.get_clock().now().nanoseconds < deadline:
                    rclpy.spin_once(node, timeout_sec=0.1)
                    f.flush()
            else:
                while rclpy.ok():
                    rclpy.spin_once(node, timeout_sec=0.1)
                    f.flush()
        except KeyboardInterrupt:
            pass
        finally:
            samples = node.sample_count
            node.destroy_node()
            if rclpy.ok():
                rclpy.shutdown()

    metadata["samples"] = samples
    metadata["finished_at"] = datetime.now().isoformat(timespec="seconds")
    meta_path.write_text(json.dumps(metadata, indent=2), encoding="utf-8")
    print(f"Saved {samples} samples in {run_dir}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
