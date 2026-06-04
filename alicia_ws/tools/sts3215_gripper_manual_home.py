#!/usr/bin/env python3
import argparse
import select
import sys
import termios
import time
import tty
from pathlib import Path

import rclpy
import yaml
from alicia_d_control_interfaces.action import HomeGripper, MoveGripperStep
from alicia_d_control_interfaces.msg import GripperState
from rclpy.action import ActionClient
from rclpy.node import Node


SCRIPT_PATH = Path(__file__).resolve()
ALICIA_WS = SCRIPT_PATH.parents[1]
DEFAULT_CONFIG = (
    ALICIA_WS / "src" / "alicia_d_sts_gripper" / "config" / "sts3215_gripper.yaml"
)
DEFAULT_INSTALL_CONFIG = (
    ALICIA_WS
    / "install"
    / "alicia_d_sts_gripper"
    / "share"
    / "alicia_d_sts_gripper"
    / "config"
    / "sts3215_gripper.yaml"
)


class RawTerminal:
    def __enter__(self):
        self.fd = sys.stdin.fileno()
        self.old_settings = termios.tcgetattr(self.fd)
        tty.setcbreak(self.fd)
        return self

    def __exit__(self, exc_type, exc, tb):
        termios.tcsetattr(self.fd, termios.TCSADRAIN, self.old_settings)

    def read_key(self):
        ch = sys.stdin.read(1)
        if ch != "\x1b":
            return ch
        seq = ch
        deadline = time.monotonic() + 0.2
        while time.monotonic() < deadline:
            timeout = max(0.0, deadline - time.monotonic())
            if not select.select([sys.stdin], [], [], timeout)[0]:
                break
            seq += sys.stdin.read(1)
            if seq.startswith(("\x1b[", "\x1bO")) and seq[-1] in "ABCD~":
                break
        if seq.startswith(("\x1b[", "\x1bO")) and seq[-1] in "ABCD":
            return {
                "D": "left",
                "C": "right",
                "A": "up",
                "B": "down",
            }[seq[-1]]
        return seq


def clear_screen():
    sys.stdout.write("\033[2J\033[H")
    sys.stdout.flush()


def get_gripper_params(data, create=False):
    for key in ("/**", "/new_gripper/sts3215_gripper", "sts3215_gripper"):
        if key in data and isinstance(data[key], dict):
            params = data[key].get("ros__parameters")
            if isinstance(params, dict):
                return params

    if create:
        return data.setdefault("/**", {}).setdefault("ros__parameters", {})
    return {}


def estimate_current_position(state):
    target = int(state.target_position)
    error = int(state.position_error_ticks or 0)
    if bool(state.position_error_direction):
        return target + error
    return target - error


def write_manual_home_config(paths, zero_feedback_position, zero_target_position):
    updated = []
    for path in paths:
        path = Path(path)
        if not path.exists():
            continue
        with path.open("r", encoding="utf-8") as f:
            data = yaml.safe_load(f) or {}
        params = get_gripper_params(data, create=True)
        params["manual_home_valid"] = True
        params["zero_feedback_position"] = int(zero_feedback_position)
        params["zero_target_position"] = int(zero_target_position)
        with path.open("w", encoding="utf-8") as f:
            yaml.safe_dump(data, f, sort_keys=False)
        updated.append(path)
    return updated


class ManualHomeNode(Node):
    def __init__(self, namespace):
        super().__init__("sts3215_manual_home_tool")
        base = namespace.rstrip("/")
        self.home_client = ActionClient(self, HomeGripper, f"{base}/home")
        self.move_step_client = ActionClient(
            self,
            MoveGripperStep,
            f"{base}/move_step",
        )
        self.state = None
        self.create_subscription(
            GripperState,
            f"{base}/state",
            self._on_state,
            10,
        )

    def _on_state(self, msg):
        self.state = msg

    def wait_for_interfaces(self, timeout_s):
        return (
            self.home_client.wait_for_server(timeout_sec=timeout_s)
            and self.move_step_client.wait_for_server(timeout_sec=timeout_s)
        )

    def _wait_future(self, future, timeout_s):
        deadline = time.monotonic() + timeout_s
        while rclpy.ok() and not future.done() and time.monotonic() < deadline:
            rclpy.spin_once(self, timeout_sec=0.02)
        return future.done()

    def send_home(self, timeout_s):
        send_future = self.home_client.send_goal_async(HomeGripper.Goal())
        if not self._wait_future(send_future, timeout_s):
            return False, "home goal send timed out"
        goal_handle = send_future.result()
        if not goal_handle.accepted:
            return False, "home goal rejected"
        result_future = goal_handle.get_result_async()
        if not self._wait_future(result_future, timeout_s):
            return False, "home result timed out"
        result = result_future.result().result
        return bool(result.success), result.message

    def send_step(self, delta_ticks, speed, timeout_s):
        goal = MoveGripperStep.Goal()
        goal.delta_ticks = int(delta_ticks)
        goal.speed = int(speed)
        send_future = self.move_step_client.send_goal_async(goal)
        if not self._wait_future(send_future, timeout_s):
            return False, "move_step goal send timed out"
        goal_handle = send_future.result()
        if not goal_handle.accepted:
            return False, "move_step goal rejected"
        result_future = goal_handle.get_result_async()
        if not self._wait_future(result_future, timeout_s):
            cancel_future = goal_handle.cancel_goal_async()
            self._wait_future(cancel_future, 1.0)
            return False, "move_step result timed out"
        result = result_future.result().result
        return bool(result.success), result.message


def print_status(args, node, step, message):
    clear_screen()
    state = node.state
    print("STS3215 gripper manual home")
    print()
    print(f"namespace: {args.namespace}")
    print(f"step:      {step} ticks")
    print(f"speed:     {args.speed}")
    print()
    if state is None:
        print("state:     unknown")
    else:
        print(f"connected:      {state.connected}")
        print(f"homed:          {state.homed}")
        print(f"raw_position:   {state.raw_position}")
        print(f"target_position:{state.target_position}")
        print(f"error_ticks:    {state.position_error_ticks}")
        print(f"error_direction:{state.position_error_direction}")
        print(f"current_est:    {estimate_current_position(state)}")
        print(f"relative_ticks: {state.relative_ticks}")
        print(f"moving:         {state.moving}")
        print(f"load_raw:       {state.load_raw}")
        print(f"current_raw:    {state.current_raw}")
        print(f"fault:          {state.fault}")
    print()
    print("Keys:")
    print("  Left/Right : jog by one step (also a/d)")
    print("  Up/Down    : increase/decrease step (also +/-)")
    print("  z or Enter : confirm current max-open position as relative 0")
    print("  h          : switch to Step mode and set current position as temporary 0")
    print("  q          : quit")
    print()
    print(message)
    sys.stdout.flush()


def main():
    parser = argparse.ArgumentParser(
        description="Jog the STS3215 gripper with ROS actions and confirm manual home."
    )
    parser.add_argument("--namespace", default="/new_gripper")
    parser.add_argument("--step", type=int, default=20)
    parser.add_argument("--speed", type=int, default=200)
    parser.add_argument("--timeout", type=float, default=10.0)
    parser.add_argument("--config", default=str(DEFAULT_CONFIG))
    parser.add_argument("--install-config", default=str(DEFAULT_INSTALL_CONFIG))
    args = parser.parse_args()

    rclpy.init()
    node = ManualHomeNode(args.namespace)
    step = max(1, int(args.step))
    message = "Waiting for gripper action servers..."

    try:
        if not node.wait_for_interfaces(args.timeout):
            print("Timed out waiting for gripper actions. Start sts3215_gripper first.")
            return 1
        ok, detail = node.send_home(args.timeout)
        message = (
            "Step mode ready. Jog to the true maximum-open position, then press z."
            if ok
            else f"Initial manual home failed: {detail}"
        )

        with RawTerminal() as terminal:
            while rclpy.ok():
                for _ in range(3):
                    rclpy.spin_once(node, timeout_sec=0.02)
                print_status(args, node, step, message)
                key = terminal.read_key()
                try:
                    if key in ("q", "\x03"):
                        message = "Quit."
                        break
                    if key in ("up", "+", "="):
                        step = min(1000, step * 2)
                        message = f"Step increased to {step}."
                    elif key in ("down", "-", "_"):
                        step = max(1, step // 2)
                        message = f"Step decreased to {step}."
                    elif key in ("left", "right", "a", "d"):
                        delta = -step if key in ("left", "a") else step
                        ok, detail = node.send_step(delta, args.speed, args.timeout)
                        message = (
                            f"Jogged by {delta} ticks."
                            if ok
                            else f"Jog failed: {detail}"
                        )
                    elif key in ("z", "\r", "\n"):
                        ok, detail = node.send_home(args.timeout)
                        if ok:
                            for _ in range(10):
                                rclpy.spin_once(node, timeout_sec=0.05)
                            if node.state is None:
                                message = (
                                    "Manual home confirmed, but no gripper state "
                                    "was received for config persistence."
                                )
                            else:
                                zero_target = int(node.state.target_position)
                                zero_feedback = estimate_current_position(node.state)
                                updated = write_manual_home_config(
                                    [args.config, args.install_config],
                                    zero_feedback,
                                    zero_target,
                                )
                                if updated:
                                    paths = ", ".join(str(path) for path in updated)
                                    message = (
                                        "Manual home confirmed and saved: "
                                        f"zero_feedback_position={zero_feedback}, "
                                        f"zero_target_position={zero_target}; {paths}"
                                    )
                                else:
                                    message = (
                                        "Manual home confirmed, but no config file "
                                        "was found to save zero feedback position."
                                    )
                        else:
                            message = f"Manual home failed: {detail}"
                    elif key == "h":
                        ok, detail = node.send_home(args.timeout)
                        message = (
                            "Step mode ready; current position set as temporary 0."
                            if ok
                            else f"Home failed: {detail}"
                        )
                    else:
                        message = f"Unknown key: {repr(key)}"
                except Exception as exc:
                    message = f"Error: {exc}"
    finally:
        clear_screen()
        print_status(args, node, step, message)
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
    return 0


if __name__ == "__main__":
    sys.exit(main())
