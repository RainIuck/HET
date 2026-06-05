import argparse
import json
import sys
import time
from datetime import datetime
from pathlib import Path

import cv2
import numpy as np
import pyrealsense2 as rs
import requests


def parse_args():
    parser = argparse.ArgumentParser(
        description="Capture aligned RealSense RGB-D frames and send text commands to a grasp server."
    )
    parser.add_argument(
        "--server-url",
        required=True,
        help="Server upload endpoint, for example http://10.x.x.x:5000/grasp_pose_upload.",
    )
    parser.add_argument("--width", type=int, default=640, help="Stream width.")
    parser.add_argument("--height", type=int, default=480, help="Stream height.")
    parser.add_argument("--fps", type=int, default=30, help="Stream FPS.")
    parser.add_argument(
        "--save-dir",
        type=Path,
        default=Path("captures") / "client_requests",
        help="Directory used to save captured request frames.",
    )
    parser.add_argument(
        "--timeout",
        type=float,
        default=180.0,
        help="HTTP request timeout in seconds.",
    )
    parser.add_argument(
        "--warmup-frames",
        type=int,
        default=15,
        help="Frames to discard after starting the camera.",
    )
    parser.add_argument(
        "--command",
        help="Text command to send once; if omitted, commands are read interactively.",
    )
    parser.add_argument(
        "--simulate-control-delay",
        type=float,
        default=10.0,
        help="Seconds to wait after each response to simulate robot execution.",
    )
    return parser.parse_args()


def print_realsense_info():
    print(f"Python executable: {sys.executable}")
    print(f"Python version: {sys.version.split()[0]}")
    print(f"pyrealsense2 path: {getattr(rs, '__file__', 'unknown')}")
    print(f"pyrealsense2 version: {getattr(rs, '__version__', 'unknown')}")

    context = rs.context()
    devices = context.query_devices()
    if len(devices) == 0:
        raise RuntimeError(
            "No RealSense device was found. Replug the camera, check USB 3.x, "
            "and close any other app using the camera."
        )

    print("Detected RealSense devices:")
    for device in devices:
        name = device.get_info(rs.camera_info.name)
        serial = device.get_info(rs.camera_info.serial_number)
        firmware = device.get_info(rs.camera_info.firmware_version)
        print(f"- {name}, serial={serial}, firmware={firmware}")


def start_camera(width, height, fps):
    pipeline = rs.pipeline()
    config = rs.config()
    config.enable_stream(rs.stream.depth, width, height, rs.format.z16, fps)
    config.enable_stream(rs.stream.color, width, height, rs.format.bgr8, fps)

    try:
        profile = pipeline.start(config)
    except RuntimeError as exc:
        raise RuntimeError(
            f"Failed to start RealSense streams: {exc}\n"
            "Try lower settings, for example --width 424 --height 240 --fps 30."
        ) from exc

    depth_sensor = profile.get_device().first_depth_sensor()
    depth_scale = depth_sensor.get_depth_scale()
    print(f"Depth scale: {depth_scale:.8f} meters per raw depth unit")
    return pipeline, rs.align(rs.stream.color)


def capture_aligned_frame(pipeline, align_to_color, warmup_frames=0):
    for _ in range(max(0, warmup_frames)):
        pipeline.wait_for_frames()

    frames = pipeline.wait_for_frames()
    aligned_frames = align_to_color.process(frames)
    depth_frame = aligned_frames.get_depth_frame()
    color_frame = aligned_frames.get_color_frame()
    if not depth_frame or not color_frame:
        raise RuntimeError("RealSense did not return a complete RGB-D frame.")

    color_image = np.asanyarray(color_frame.get_data())
    depth_raw = np.asanyarray(depth_frame.get_data())
    return color_image, depth_raw


def save_frame_pair(save_dir, color_image, depth_raw):
    save_dir.mkdir(parents=True, exist_ok=True)
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S_%f")
    rgb_path = save_dir / f"rgb_{timestamp}.png"
    depth_path = save_dir / f"depth_raw_{timestamp}.png"

    if not cv2.imwrite(str(rgb_path), color_image):
        raise RuntimeError(f"Failed to save RGB image: {rgb_path}")
    if not cv2.imwrite(str(depth_path), depth_raw):
        raise RuntimeError(f"Failed to save depth image: {depth_path}")

    return rgb_path, depth_path


def send_request(server_url, rgb_path, depth_path, text, timeout):
    started_at = time.perf_counter()
    with open(rgb_path, "rb") as rgb_file, open(depth_path, "rb") as depth_file:
        response = requests.post(
            server_url,
            files={
                "rgb": ("rgb.png", rgb_file, "image/png"),
                "depth": ("depth_raw.png", depth_file, "image/png"),
            },
            data={"text": text},
            timeout=timeout,
        )
    elapsed = time.perf_counter() - started_at
    return response, elapsed


def print_response(response, elapsed):
    print(f"Send-to-response elapsed time: {elapsed:.2f}s")
    print(f"Server responded with HTTP {response.status_code}")
    try:
        payload = response.json()
    except ValueError:
        print(response.text)
        return

    print(json.dumps(payload, ensure_ascii=False, indent=2))


def capture_save_and_send(args, pipeline, align_to_color, command, warmup_frames):
    color_image, depth_raw = capture_aligned_frame(pipeline, align_to_color, warmup_frames)
    rgb_path, depth_path = save_frame_pair(args.save_dir, color_image, depth_raw)
    print(f"Saved RGB: {rgb_path}")
    print(f"Saved depth: {depth_path}")
    print(f"Sending command to {args.server_url!r}: {command}")
    response, elapsed = send_request(args.server_url, rgb_path, depth_path, command, args.timeout)
    print_response(response, elapsed)
    return response


def main():
    args = parse_args()
    print_realsense_info()
    pipeline, align_to_color = start_camera(args.width, args.height, args.fps)

    if args.command:
        try:
            capture_save_and_send(
                args,
                pipeline,
                align_to_color,
                args.command,
                args.warmup_frames,
            )
        except requests.RequestException as exc:
            print(f"Network error: {exc}")
        except RuntimeError as exc:
            print(f"Capture/upload error: {exc}")
        finally:
            pipeline.stop()
            print("Camera stopped.")
        return

    print("Camera is ready. Type a text command and press Enter.")
    print("Use q, quit, or exit to stop.")
    print(
        "Each round will capture RGB-D, send it to the server, print the response, "
        f"then wait {args.simulate_control_delay:.1f}s to simulate robot execution."
    )

    try:
        first_capture = True
        while True:
            try:
                command = input("> ").strip()
            except EOFError:
                print(
                    "No interactive input stream is available. "
                    "For the loop mode, activate the HET environment first and run "
                    "python directly instead of using conda run."
                )
                break
            if command.lower() in {"q", "quit", "exit"}:
                break
            if not command:
                continue

            try:
                warmup = args.warmup_frames if first_capture else 0
                capture_save_and_send(args, pipeline, align_to_color, command, warmup)
                first_capture = False
                if args.simulate_control_delay > 0.0:
                    print(
                        "Simulating robot grasp execution for "
                        f"{args.simulate_control_delay:.1f}s..."
                    )
                    time.sleep(args.simulate_control_delay)
                    print("Simulation finished. Ready for the next command.")
            except requests.RequestException as exc:
                print(f"Network error: {exc}")
            except RuntimeError as exc:
                print(f"Capture/upload error: {exc}")
    finally:
        pipeline.stop()
        print("Camera stopped.")


if __name__ == "__main__":
    main()
