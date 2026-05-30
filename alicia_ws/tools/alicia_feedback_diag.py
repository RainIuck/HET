#!/usr/bin/env python3
"""Alicia-D serial feedback diagnostic tool.

This tool only sends read-only query frames. It does not enable torque and does
not send joint/gripper motion commands.
"""

from __future__ import annotations

import argparse
import glob
import json
import math
import os
import sys
import time
import zlib
from datetime import datetime
from pathlib import Path
from typing import Any

try:
    import serial
except ImportError as exc:  # pragma: no cover - depends on host environment
    print("pyserial is required: python3 -m pip install pyserial", file=sys.stderr)
    raise SystemExit(2) from exc


COMMANDS = {
    "version": bytes.fromhex("AA 01 00 01 FE 23 FF"),
    "joint": bytes.fromhex("AA 06 00 01 FE 9A FF"),
    "temperature": bytes.fromhex("AA 06 01 01 FE AD FF"),
    "velocity": bytes.fromhex("AA 06 02 01 FE F4 FF"),
    "self_check": bytes.fromhex("AA FE 00 00 FE 93 FF"),
}

RUN_STATUS = {
    0x00: "idle",
    0x01: "locked",
    0x10: "sync",
    0x11: "sync_locked",
    0xE1: "overheat",
    0xE2: "overheat_protect",
}

SELF_CHECK_LABELS = [f"bit_{idx}" for idx in range(10)]


def hex_bytes(data: bytes | bytearray) -> str:
    return " ".join(f"{byte:02X}" for byte in data)


def crc_low(payload: bytes | bytearray) -> int:
    return zlib.crc32(bytes(payload)) & 0xFF


def validate_frame(frame: bytes | bytearray) -> tuple[bool, int | None]:
    if len(frame) < 6:
        return False, None
    if frame[0] != 0xAA or frame[-1] != 0xFF:
        return False, None
    expected_len = frame[3] + 6
    if len(frame) != expected_len:
        return False, None
    calculated = crc_low(frame[1:-2])
    return calculated == frame[-2], calculated


def decimal_to_version_string(decimal_value: int) -> str:
    major = decimal_value // 1_000_000
    minor = (decimal_value % 1_000_000) // 1_000
    patch = decimal_value % 1_000
    return f"{major}.{minor}.{patch}"


def raw_to_rad(raw_value: int) -> float:
    raw_value = max(0, min(4095, raw_value))
    return (raw_value / 4096.0) * 2.0 * math.pi - math.pi


def raw_velocity_to_deg_s(raw_value: int) -> float:
    raw_value = max(0, min(5000, raw_value))
    return raw_value * (360.0 / 4096.0)


def decode_frame(frame: bytes | bytearray) -> dict[str, Any]:
    valid, calculated_crc = validate_frame(frame)
    decoded: dict[str, Any] = {
        "timestamp": time.time(),
        "frame_hex": hex_bytes(frame),
        "frame_len": len(frame),
        "valid_crc": valid,
        "calculated_crc": calculated_crc,
    }

    if len(frame) < 6:
        decoded["type"] = "short_frame"
        return decoded

    cmd = frame[1]
    func = frame[2]
    data_len = frame[3]
    data = frame[4 : 4 + data_len]

    decoded.update({"cmd": cmd, "func": func, "data_len": data_len})

    if not valid:
        decoded["type"] = "invalid_crc_or_shape"
        return decoded

    if cmd == 0x01:
        decoded["type"] = "version"
        if len(data) >= 24:
            serial_number = bytes(data[:16]).decode("ascii", errors="ignore").strip()
            hardware_decimal = int.from_bytes(data[16:20], "little", signed=False)
            firmware_decimal = int.from_bytes(data[20:24], "little", signed=False)
            decoded.update(
                {
                    "serial_number": serial_number,
                    "hardware_decimal": hardware_decimal,
                    "hardware_version": decimal_to_version_string(hardware_decimal),
                    "firmware_decimal": firmware_decimal,
                    "firmware_version": decimal_to_version_string(firmware_decimal),
                }
            )
        else:
            decoded["warning"] = "version data shorter than 24 bytes"
        return decoded

    if cmd == 0xFE:
        decoded["type"] = "self_check"
        if len(data) >= 2:
            raw_mask = int.from_bytes(data[:2], "little", signed=False)
            bits = []
            for idx, label in enumerate(SELF_CHECK_LABELS):
                ok = bool((raw_mask >> idx) & 0x1)
                bits.append({"index": idx, "label": label, "ok": ok})
            decoded.update(
                {
                    "raw_mask": raw_mask,
                    "raw_mask_hex": f"0x{raw_mask:04X}",
                    "bits": bits,
                    "fault_bits": [bit for bit in bits if not bit["ok"]],
                }
            )
        else:
            decoded["warning"] = "self-check data shorter than 2 bytes"
        return decoded

    if cmd == 0x06 and func == 0x00:
        decoded["type"] = "joint"
        if len(data) >= 15:
            raw = [int.from_bytes(data[idx : idx + 2], "little", signed=False) for idx in range(0, 12, 2)]
            radians = [raw_to_rad(value) for value in raw]
            degrees = [value * 180.0 / math.pi for value in radians]
            gripper_raw = int.from_bytes(data[12:14], "little", signed=False)
            gripper_clamped = max(0, min(1000, gripper_raw))
            run_status_raw = data[14]
            decoded.update(
                {
                    "joint_raw": raw,
                    "joint_rad": radians,
                    "joint_deg": degrees,
                    "all_joint_raw_zero": all(value == 0 for value in raw),
                    "gripper_raw": gripper_raw,
                    "gripper_clamped": gripper_clamped,
                    "run_status_raw": run_status_raw,
                    "run_status_hex": f"0x{run_status_raw:02X}",
                    "run_status": RUN_STATUS.get(run_status_raw, "unknown"),
                }
            )
        else:
            decoded["warning"] = "joint data shorter than 15 bytes"
        return decoded

    if cmd == 0x06 and func == 0x01:
        decoded["type"] = "temperature"
        decoded["temperature_c"] = list(data)
        return decoded

    if cmd == 0x06 and func == 0x02:
        decoded["type"] = "velocity"
        raw_values = [
            int.from_bytes(data[idx : idx + 2], "little", signed=False)
            for idx in range(0, len(data) - 1, 2)
        ]
        decoded["velocity_raw"] = raw_values
        decoded["velocity_deg_s"] = [raw_velocity_to_deg_s(value) for value in raw_values]
        return decoded

    if cmd == 0xEE:
        decoded["type"] = "error"
        decoded["data_hex"] = hex_bytes(data)
        if len(data) >= 2:
            decoded["error_code"] = data[0]
            decoded["error_param"] = data[1]
        return decoded

    decoded["type"] = "unknown"
    decoded["data_hex"] = hex_bytes(data)
    return decoded


def parse_hex_frame(raw: str) -> bytes:
    cleaned = raw.replace("0x", "").replace(",", " ").replace(":", " ").replace("-", " ")
    parts = [part for part in cleaned.split() if part]
    if len(parts) == 1 and len(parts[0]) > 2:
        text = parts[0]
        if len(text) % 2 != 0:
            raise ValueError("hex string must contain an even number of digits")
        return bytes(int(text[idx : idx + 2], 16) for idx in range(0, len(text), 2))
    return bytes(int(part, 16) for part in parts)


def discover_ports() -> list[str]:
    candidates: list[str] = []
    for pattern in ("/dev/ttyACM*", "/dev/ttyUSB*", "/dev/serial/by-id/*"):
        candidates.extend(glob.glob(pattern))
    return sorted(dict.fromkeys(candidates))


def open_serial(port: str, baudrate: int, timeout_s: float) -> serial.Serial:
    ser = serial.Serial(
        port=port,
        baudrate=baudrate,
        bytesize=serial.EIGHTBITS,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        timeout=0.02,
        write_timeout=timeout_s,
        xonxoff=False,
        rtscts=False,
        dsrdtr=False,
    )
    ser.dtr = True
    ser.rts = False
    ser.reset_input_buffer()
    ser.reset_output_buffer()
    return ser


def read_exact_until(ser: serial.Serial, count: int, deadline: float) -> bytes:
    buf = bytearray()
    while len(buf) < count and time.monotonic() < deadline:
        chunk = ser.read(count - len(buf))
        if chunk:
            buf.extend(chunk)
    return bytes(buf)


def read_frame(ser: serial.Serial, timeout_s: float) -> tuple[bytes | None, str | None]:
    deadline = time.monotonic() + timeout_s
    while time.monotonic() < deadline:
        byte = ser.read(1)
        if not byte:
            continue
        if byte[0] != 0xAA:
            continue

        header_tail = read_exact_until(ser, 3, deadline)
        if len(header_tail) < 3:
            return bytes([0xAA]) + header_tail, "timeout_after_header"

        prefix = bytes([0xAA]) + header_tail
        data_len = prefix[3]
        remaining = data_len + 2
        suffix = read_exact_until(ser, remaining, deadline)
        frame = prefix + suffix
        if len(suffix) < remaining:
            return frame, "timeout_in_frame"
        if frame[-1] != 0xFF:
            return frame, "bad_footer"
        return frame, None

    return None, "timeout"


def query(
    ser: serial.Serial,
    name: str,
    timeout_s: float,
    settle_s: float,
    jsonl_file: Any,
    extra: dict[str, Any] | None = None,
) -> dict[str, Any]:
    command = COMMANDS[name]
    record: dict[str, Any] = {
        "timestamp": time.time(),
        "query": name,
        "tx_hex": hex_bytes(command),
    }
    if extra:
        record.update(extra)

    ser.reset_input_buffer()
    ser.write(command)
    ser.flush()
    if settle_s > 0:
        time.sleep(settle_s)

    frame, error = read_frame(ser, timeout_s)
    if frame is None:
        record.update({"ok": False, "error": error})
    else:
        decoded = decode_frame(frame)
        record.update({"ok": error is None and bool(decoded.get("valid_crc")), "rx_error": error})
        record["decoded"] = decoded

    jsonl_file.write(json.dumps(record, ensure_ascii=False) + "\n")
    jsonl_file.flush()
    return record


def print_record(record: dict[str, Any]) -> None:
    name = record["query"]
    if not record.get("ok"):
        print(f"{name:11s} FAIL {record.get('error') or record.get('rx_error') or ''}")
        decoded = record.get("decoded")
        if decoded:
            print(f"  RX {decoded.get('frame_hex')}")
        return

    decoded = record["decoded"]
    kind = decoded.get("type")
    if kind == "joint":
        raw = decoded.get("joint_raw", [])
        deg = decoded.get("joint_deg", [])
        deg_text = ", ".join(f"{value:7.2f}" for value in deg)
        print(
            f"{name:11s} OK   raw={raw} deg=[{deg_text}] "
            f"gripper={decoded.get('gripper_clamped')} "
            f"status={decoded.get('run_status_hex')}({decoded.get('run_status')}) "
            f"all_zero={decoded.get('all_joint_raw_zero')}"
        )
    elif kind == "self_check":
        faults = decoded.get("fault_bits", [])
        fault_text = ", ".join(f"bit_{item['index']}" for item in faults) or "none"
        print(
            f"{name:11s} OK   mask={decoded.get('raw_mask_hex')} "
            f"fault_bits={fault_text}"
        )
    elif kind == "version":
        print(
            f"{name:11s} OK   sn={decoded.get('serial_number', '')} "
            f"hw={decoded.get('hardware_version', '?')} "
            f"fw={decoded.get('firmware_version', '?')}"
        )
    elif kind == "temperature":
        print(f"{name:11s} OK   temp_c={decoded.get('temperature_c', [])}")
    elif kind == "velocity":
        print(f"{name:11s} OK   velocity_deg_s={decoded.get('velocity_deg_s', [])}")
    else:
        print(f"{name:11s} OK   type={kind} rx={decoded.get('frame_hex')}")


def write_summary(log_dir: Path, records: list[dict[str, Any]]) -> None:
    joint_records = [
        record
        for record in records
        if record.get("ok") and record.get("decoded", {}).get("type") == "joint"
    ]
    zero_joint_records = [
        record
        for record in joint_records
        if record.get("decoded", {}).get("all_joint_raw_zero")
    ]
    self_check_records = [
        record
        for record in records
        if record.get("ok") and record.get("decoded", {}).get("type") == "self_check"
    ]

    lines = [
        "Alicia-D feedback diagnostic summary",
        f"generated_at: {datetime.now().isoformat(timespec='seconds')}",
        f"records: {len(records)}",
        f"joint_frames_ok: {len(joint_records)}",
        f"joint_frames_all_zero: {len(zero_joint_records)}",
    ]

    if self_check_records:
        decoded = self_check_records[-1]["decoded"]
        faults = decoded.get("fault_bits", [])
        fault_text = ", ".join(f"bit_{item['index']}" for item in faults) or "none"
        lines.append(f"self_check_mask: {decoded.get('raw_mask_hex')}")
        lines.append(f"self_check_fault_bits: {fault_text}")

    if joint_records:
        last = joint_records[-1]["decoded"]
        lines.append(f"last_joint_raw: {last.get('joint_raw')}")
        lines.append(
            "last_joint_deg: "
            + ", ".join(f"{value:.3f}" for value in last.get("joint_deg", []))
        )
        lines.append(
            f"last_run_status: {last.get('run_status_hex')}({last.get('run_status')})"
        )

    if not joint_records:
        lines.append("result: no valid joint feedback frame received")
    elif len(zero_joint_records) == len(joint_records):
        lines.append("result: all valid joint feedback frames reported raw zero")
    else:
        lines.append("result: at least one valid joint feedback frame is non-zero")

    (log_dir / "summary.txt").write_text("\n".join(lines) + "\n", encoding="utf-8")


def build_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Read-only Alicia-D serial feedback diagnostic."
    )
    parser.add_argument("--port", help="Serial port, for example /dev/ttyACM0.")
    parser.add_argument("--baudrate", type=int, default=1_000_000)
    parser.add_argument("--timeout", type=float, default=0.5, help="Per-query RX timeout in seconds.")
    parser.add_argument("--settle", type=float, default=0.02, help="Delay after TX before reading.")
    parser.add_argument("--samples", type=int, default=20, help="Joint query sample count.")
    parser.add_argument(
        "--interval",
        type=float,
        default=0.1,
        help="Delay between joint query samples in seconds.",
    )
    parser.add_argument(
        "--include-extra",
        action="store_true",
        help="Also query temperature and velocity once.",
    )
    parser.add_argument(
        "--log-dir",
        default=str(Path(__file__).resolve().parents[1] / "experiment_logs" / "feedback_diagnostics"),
        help="Base directory for diagnostic logs.",
    )
    parser.add_argument(
        "--decode-frame",
        help="Decode one hex frame and exit. Useful for offline parser checks.",
    )
    parser.add_argument("--list-ports", action="store_true", help="List candidate serial ports and exit.")
    return parser


def main() -> int:
    args = build_arg_parser().parse_args()

    if args.decode_frame:
        frame = parse_hex_frame(args.decode_frame)
        print(json.dumps(decode_frame(frame), indent=2, ensure_ascii=False))
        return 0

    ports = discover_ports()
    if args.list_ports:
        for port in ports:
            print(port)
        return 0

    port = args.port or (ports[0] if ports else None)
    if not port:
        print("No serial port found. Try --port /dev/ttyACM0.", file=sys.stderr)
        return 2

    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    log_dir = Path(args.log_dir) / f"alicia_feedback_{timestamp}"
    log_dir.mkdir(parents=True, exist_ok=True)
    jsonl_path = log_dir / "frames.jsonl"

    records: list[dict[str, Any]] = []
    print(f"log_dir: {log_dir}")
    print(f"port: {port} baudrate: {args.baudrate}")
    print("mode: read-only queries; no torque or motion commands are sent")

    try:
        with open_serial(port, args.baudrate, args.timeout) as ser, jsonl_path.open(
            "w", encoding="utf-8"
        ) as jsonl_file:
            for name in ("version", "self_check"):
                record = query(ser, name, args.timeout, args.settle, jsonl_file)
                records.append(record)
                print_record(record)

            if args.include_extra:
                for name in ("temperature", "velocity"):
                    record = query(ser, name, args.timeout, args.settle, jsonl_file)
                    records.append(record)
                    print_record(record)

            for idx in range(args.samples):
                record = query(
                    ser,
                    "joint",
                    args.timeout,
                    args.settle,
                    jsonl_file,
                    extra={"sample_index": idx},
                )
                records.append(record)
                print_record(record)
                if idx + 1 < args.samples and args.interval > 0:
                    time.sleep(args.interval)
    except serial.SerialException as exc:
        print(f"Failed to open or use serial port {port}: {exc}", file=sys.stderr)
        return 2
    finally:
        if records:
            write_summary(log_dir, records)
            print(f"summary: {log_dir / 'summary.txt'}")
            print(f"frames:  {jsonl_path}")

    joint_ok = [
        record
        for record in records
        if record.get("ok") and record.get("decoded", {}).get("type") == "joint"
    ]
    if not joint_ok:
        return 3
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
