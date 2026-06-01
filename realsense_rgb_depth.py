import argparse
import sys
from pathlib import Path

import cv2
import numpy as np
import pyrealsense2 as rs


def parse_args():
    parser = argparse.ArgumentParser(
        description="Show and optionally save RGB and depth frames from an Intel RealSense camera."
    )
    parser.add_argument("--width", type=int, default=640, help="Stream width.")
    parser.add_argument("--height", type=int, default=480, help="Stream height.")
    parser.add_argument("--fps", type=int, default=30, help="Stream FPS.")
    parser.add_argument(
        "--save-dir",
        type=Path,
        default=Path("captures"),
        help="Directory used when pressing 's' to save frames.",
    )
    return parser.parse_args()


def main():
    args = parse_args()
    args.save_dir.mkdir(parents=True, exist_ok=True)

    print(f"Python executable: {sys.executable}")
    print(f"Python version: {sys.version.split()[0]}")
    print(f"pyrealsense2 path: {getattr(rs, '__file__', 'unknown')}")
    print(f"pyrealsense2 version: {getattr(rs, '__version__', 'unknown')}")

    context = rs.context()
    devices = context.query_devices()
    if len(devices) == 0:
        print(
            "No RealSense device was found by the SDK.\n"
            "Try these checks:\n"
            "1. Replug the camera into a USB 3.x port, preferably without a hub.\n"
            "2. Use the original or a known data-capable USB cable.\n"
            "3. Open RealSense Viewer and confirm it can see the camera.\n"
            "4. In Windows Device Manager, check whether the camera appears without a warning icon.\n"
            "5. Close other apps that may be using the camera, then run this script again."
        )
        return

    print("Detected RealSense devices:")
    for device in devices:
        name = device.get_info(rs.camera_info.name)
        serial = device.get_info(rs.camera_info.serial_number)
        firmware = device.get_info(rs.camera_info.firmware_version)
        print(f"- {name}, serial={serial}, firmware={firmware}")

    pipeline = rs.pipeline()
    config = rs.config()
    config.enable_stream(rs.stream.depth, args.width, args.height, rs.format.z16, args.fps)
    config.enable_stream(rs.stream.color, args.width, args.height, rs.format.bgr8, args.fps)

    align_to_color = rs.align(rs.stream.color)
    colorizer = rs.colorizer()

    print("Starting RealSense camera. Press 's' to save, 'q' or Esc to quit.")
    try:
        profile = pipeline.start(config)
    except RuntimeError as exc:
        print(f"Failed to start RealSense streams: {exc}")
        print("If the camera is detected but streams fail, try a lower setting:")
        print("python realsense_rgb_depth.py --width 424 --height 240 --fps 30")
        return

    depth_sensor = profile.get_device().first_depth_sensor()
    depth_scale = depth_sensor.get_depth_scale()
    print(f"Depth scale: {depth_scale:.8f} meters per raw depth unit")

    frame_index = 0

    try:
        while True:
            frames = pipeline.wait_for_frames()
            aligned_frames = align_to_color.process(frames)

            depth_frame = aligned_frames.get_depth_frame()
            color_frame = aligned_frames.get_color_frame()
            if not depth_frame or not color_frame:
                continue

            color_image = np.asanyarray(color_frame.get_data())
            depth_raw = np.asanyarray(depth_frame.get_data())

            # For viewing only. Keep depth_raw for metric depth values.
            depth_colormap = np.asanyarray(colorizer.colorize(depth_frame).get_data())

            center_x = args.width // 2
            center_y = args.height // 2
            center_distance_m = depth_frame.get_distance(center_x, center_y)

            cv2.circle(color_image, (center_x, center_y), 4, (0, 255, 255), -1)
            cv2.putText(
                color_image,
                f"Center: {center_distance_m:.3f} m",
                (20, 40),
                cv2.FONT_HERSHEY_SIMPLEX,
                1.0,
                (0, 255, 255),
                2,
                cv2.LINE_AA,
            )

            combined = np.hstack((color_image, depth_colormap))
            cv2.imshow("RealSense RGB | Depth", combined)

            key = cv2.waitKey(1) & 0xFF
            if key in (27, ord("q")):
                break
            if key == ord("s"):
                rgb_path = args.save_dir / f"rgb_{frame_index:06d}.png"
                depth_png_path = args.save_dir / f"depth_raw_{frame_index:06d}.png"
                depth_npy_path = args.save_dir / f"depth_meters_{frame_index:06d}.npy"

                cv2.imwrite(str(rgb_path), color_image)
                cv2.imwrite(str(depth_png_path), depth_raw)
                np.save(depth_npy_path, depth_raw.astype(np.float32) * depth_scale)

                print(f"Saved {rgb_path}, {depth_png_path}, {depth_npy_path}")
                frame_index += 1
    finally:
        pipeline.stop()
        cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
