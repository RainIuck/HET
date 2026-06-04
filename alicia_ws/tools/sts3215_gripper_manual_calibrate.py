#!/usr/bin/env python3
import argparse
import os
import select
import sys
import termios
import time
import tty
from pathlib import Path

import yaml


SCRIPT_PATH = Path(__file__).resolve()
ALICIA_WS = SCRIPT_PATH.parents[1]
PACKAGE_SRC = ALICIA_WS / "src" / "alicia_d_sts_gripper"
DEFAULT_CONFIG = PACKAGE_SRC / "config" / "sts3215_gripper.yaml"
DEFAULT_GRIPPER_PORT = "/dev/serial/by-id/usb-1a86_USB_Single_Serial_5B79032424-if00"
DEFAULT_SCAN_BAUDRATES = "1000000,115200,500000,250000"
sys.path.insert(0, str(PACKAGE_SRC))

from alicia_d_sts_gripper.sts3215_bus import Sts3215Bus, Sts3215Error  # noqa: E402

try:
    from serial.tools import list_ports
except ImportError:  # pragma: no cover - handled at runtime on robot
    list_ports = None


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

        # Arrow keys may arrive as ESC [ D or longer variants like ESC [ 1 ; 5 D.
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


def print_status(args, current_raw, step, message):
    clear_screen()
    print("STS3215 gripper manual jog")
    print()
    print(f"port: {args.port}")
    print(f"servo_id: {args.servo_id}")
    print(f"config: {args.config}")
    print()
    print(f"current_raw: {current_raw if current_raw is not None else 'unknown'}")
    print(f"step:        {step} ticks")
    print()
    print("Keys:")
    print("  Left/Right : move by one step (also a/d)")
    print("  Up/Down    : increase/decrease step (also +/-)")
    print("  r          : read current raw")
    print("  t          : torque on")
    print("  x          : torque off")
    print("  q          : quit")
    print()
    print(message)
    sys.stdout.flush()


def read_position(bus, servo_id):
    state = bus.read_state(servo_id)
    return state.raw_position


def get_gripper_params(data, create=False):
    for key in ("/**", "/new_gripper/sts3215_gripper", "sts3215_gripper"):
        if key in data and isinstance(data[key], dict):
            params = data[key].get("ros__parameters")
            if isinstance(params, dict):
                return params

    if create:
        return data.setdefault("/**", {}).setdefault("ros__parameters", {})
    return {}


def load_yaml_defaults(config_path):
    defaults = {
        "port": DEFAULT_GRIPPER_PORT,
        "baudrate": 1000000,
        "servo_id": 1,
    }
    try:
        with Path(config_path).open("r", encoding="utf-8") as f:
            data = yaml.safe_load(f) or {}
        params = get_gripper_params(data)
        for key in defaults:
            if key in params:
                defaults[key] = params[key]
    except Exception:
        pass
    return defaults


def parse_baudrates(value):
    baudrates = []
    for item in value.split(","):
        item = item.strip()
        if item:
            baudrates.append(int(item))
    return baudrates


def list_serial_ports():
    if list_ports is None:
        print("pyserial list_ports is unavailable.")
        return

    ports = list(list_ports.comports())
    if not ports:
        print("No serial ports found.")
        return

    for port in ports:
        description = port.description or ""
        hwid = port.hwid or ""
        print(f"{port.device}\t{description}\t{hwid}")


def visible_serial_devices():
    devices = []
    for base, pattern in (
        (Path("/dev/serial/by-id"), "*"),
        (Path("/dev"), "ttyACM*"),
        (Path("/dev"), "ttyUSB*"),
    ):
        if not base.exists():
            continue
        for path in sorted(base.glob(pattern)):
            devices.append(str(path))
    return devices


def print_missing_port_help(port):
    print(f"Configured port does not exist: {port}")
    print()
    print("First attach the gripper USB adapter to WSL, then check the Linux port:")
    print("  tools/attach_alicia_usb_to_wsl.sh 2-3")
    print("  ls -l /dev/serial/by-id /dev/ttyACM* /dev/ttyUSB* 2>/dev/null")
    print()
    print("Visible serial devices now:")
    devices = visible_serial_devices()
    if devices:
        for device in devices:
            print(f"  {device}")
        print()
        print("If the gripper appears under a different by-id name, update sts3215_gripper.yaml.")
        print("For one-off testing, pass it with --port <device>.")
    else:
        print("  none")


def scan_servos(args):
    if not os.path.exists(args.port):
        print_missing_port_help(args.port)
        return 2

    found = []
    baudrates = parse_baudrates(args.scan_baudrates)
    print(f"Scanning {args.port}")
    print(f"ids: {args.scan_min_id}..{args.scan_max_id}")
    print(f"baudrates: {', '.join(str(baudrate) for baudrate in baudrates)}")
    print()

    for baudrate in baudrates:
        try:
            bus = Sts3215Bus(args.port, baudrate, timeout=args.timeout)
            bus.open()
        except Exception as exc:
            print(f"{baudrate}: failed to open port: {exc}")
            continue

        try:
            for servo_id in range(args.scan_min_id, args.scan_max_id + 1):
                try:
                    raw = bus.read_position(servo_id)
                except Exception:
                    continue
                print(f"FOUND baudrate={baudrate} id={servo_id} raw={raw}")
                found.append((baudrate, servo_id, raw))
        finally:
            bus.close()

    if not found:
        print("No STS3215 response found.")
        print("Check WSL USB attach, gripper power, GND/TX/RX wiring, baudrate, and servo ID.")
        return 1

    return 0


def main():
    pre_parser = argparse.ArgumentParser(add_help=False)
    pre_parser.add_argument("--config", default=str(DEFAULT_CONFIG))
    pre_args, _ = pre_parser.parse_known_args()
    yaml_defaults = load_yaml_defaults(pre_args.config)

    parser = argparse.ArgumentParser(description="Interactive keyboard jog for the STS3215 gripper.")
    parser.add_argument("--port", default=str(yaml_defaults["port"]))
    parser.add_argument("--baudrate", type=int, default=int(yaml_defaults["baudrate"]))
    parser.add_argument("--id", type=int, default=int(yaml_defaults["servo_id"]), dest="servo_id")
    parser.add_argument("--config", default=str(DEFAULT_CONFIG))
    parser.add_argument("--step", type=int, default=10)
    parser.add_argument("--speed", type=int, default=300)
    parser.add_argument("--acceleration", type=int, default=10)
    parser.add_argument("--timeout", type=float, default=0.12)
    parser.add_argument("--settle", type=float, default=0.15)
    parser.add_argument("--list-ports", action="store_true", help="List visible serial ports and exit.")
    parser.add_argument("--scan", action="store_true", help="Scan baudrates and servo IDs, then exit.")
    parser.add_argument("--scan-min-id", type=int, default=1)
    parser.add_argument("--scan-max-id", type=int, default=10)
    parser.add_argument("--scan-baudrates", default=DEFAULT_SCAN_BAUDRATES)
    parser.add_argument(
        "--no-torque-on-start",
        action="store_true",
        help="Do not enable torque on startup. Press 't' later before moving.",
    )
    args = parser.parse_args()

    if args.list_ports:
        list_serial_ports()
        return 0

    if args.scan:
        return scan_servos(args)

    if not os.path.exists(args.port):
        print_missing_port_help(args.port)
        return 2

    bus = Sts3215Bus(args.port, args.baudrate, timeout=args.timeout)
    current_raw = None
    step = max(1, int(args.step))
    message = "Opening serial port..."

    try:
        bus.open()
        current_raw = read_position(bus, args.servo_id)
        if not args.no_torque_on_start:
            bus.enable_torque(args.servo_id, True)
            message = "Read current raw and enabled torque. Use Left/Right to move slowly."
        else:
            message = "Read current raw. Press 't' before moving if torque is disabled."
    except Exception as exc:
        message = (
            f"Initial read failed: {exc}. "
            "Try: python3 tools/sts3215_gripper_manual_calibrate.py --scan"
        )

    try:
        with RawTerminal() as terminal:
            while True:
                print_status(args, current_raw, step, message)
                key = terminal.read_key()

                try:
                    if key in ("q", "\x03"):
                        message = "Quit."
                        break
                    if key == "r":
                        current_raw = read_position(bus, args.servo_id)
                        message = "Read current raw."
                    elif key == "t":
                        bus.enable_torque(args.servo_id, True)
                        message = "Torque enabled."
                    elif key == "x":
                        bus.enable_torque(args.servo_id, False)
                        message = "Torque disabled."
                    elif key in ("up", "+", "="):
                        step = min(500, step * 2)
                        message = f"Step increased to {step}."
                    elif key in ("down", "-", "_"):
                        step = max(1, step // 2)
                        message = f"Step decreased to {step}."
                    elif key in ("left", "right", "a", "d"):
                        if current_raw is None:
                            current_raw = read_position(bus, args.servo_id)
                        delta = -step if key in ("left", "a") else step
                        target_raw = max(0, min(4095, int(current_raw) + delta))
                        bus.enable_torque(args.servo_id, True)
                        bus.write_goal_position(
                            args.servo_id,
                            target_raw,
                            speed=args.speed,
                            acceleration=args.acceleration,
                        )
                        time.sleep(args.settle)
                        try:
                            current_raw = read_position(bus, args.servo_id)
                        except Sts3215Error:
                            current_raw = target_raw
                        message = f"Moved to raw {current_raw}."
                    else:
                        message = f"Unknown key: {repr(key)}"
                except Exception as exc:
                    message = f"Error: {exc}"
    finally:
        clear_screen()
        print_status(args, current_raw, step, message)
        bus.close()


if __name__ == "__main__":
    sys.exit(main())
