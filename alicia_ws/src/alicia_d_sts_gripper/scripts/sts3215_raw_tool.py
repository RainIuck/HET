#!/usr/bin/env python3
import argparse
import time

from alicia_d_sts_gripper.sts3215_bus import Sts3215Bus


def main():
    parser = argparse.ArgumentParser(description="Raw STS3215 gripper calibration tool.")
    parser.add_argument("--port", default="/dev/ttyUSB0")
    parser.add_argument("--baudrate", type=int, default=1000000)
    parser.add_argument("--id", type=int, default=1, dest="servo_id")
    parser.add_argument("--timeout", type=float, default=0.12)
    parser.add_argument("--read", action="store_true", help="Read current raw position/state.")
    parser.add_argument("--raw", type=int, help="Command raw target tick, usually 0..4095.")
    parser.add_argument("--speed", type=int, default=500)
    parser.add_argument("--acceleration", type=int, default=20)
    parser.add_argument("--torque", choices=["on", "off"], help="Enable or disable torque.")
    parser.add_argument("--wait", type=float, default=0.5, help="Wait after command before reading.")
    args = parser.parse_args()

    bus = Sts3215Bus(args.port, args.baudrate, timeout=args.timeout)
    try:
        bus.open()
        if args.torque:
            bus.enable_torque(args.servo_id, args.torque == "on")
            print(f"torque_{args.torque}: OK")

        if args.raw is not None:
            bus.enable_torque(args.servo_id, True)
            bus.write_goal_position(
                args.servo_id,
                args.raw,
                speed=args.speed,
                acceleration=args.acceleration,
            )
            print(f"sent raw={args.raw} speed={args.speed} acceleration={args.acceleration}")
            time.sleep(args.wait)

        if args.read or args.raw is not None or args.torque:
            state = bus.read_state(args.servo_id)
            print(
                "state: "
                f"raw_position={state.raw_position} "
                f"moving={state.moving} "
                f"voltage_v={state.voltage_v} "
                f"temperature_c={state.temperature_c} "
                f"current_raw={state.current_raw}"
            )
    finally:
        bus.close()


if __name__ == "__main__":
    main()
