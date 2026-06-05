import logging
import json
import shutil
import subprocess
import sys
from pathlib import Path
from uuid import uuid4


def show_matplotlib_non_blocking(plt_module, pause_seconds=0.001):
    try:
        plt_module.show(block=False)
        if pause_seconds > 0:
            plt_module.pause(pause_seconds)
    except Exception as exc:
        logging.warning("Matplotlib non-blocking display failed: %s", exc)


def draw_open3d_non_blocking(geometries, *args, **kwargs):
    geometry_list = list(geometries)
    try:
        return _draw_open3d_in_subprocess(geometry_list, *args, **kwargs)
    except Exception as exc:
        logging.warning("Open3D subprocess display setup failed: %s", exc)
        return None


def _draw_open3d_in_subprocess(geometries, *args, **kwargs):
    import open3d as o3d

    if args:
        logging.warning("Ignoring positional Open3D viewer args for non-blocking display: %s", args)

    temp_dir = Path("/tmp") / f"thinkgrasp_open3d_{uuid4().hex}"
    temp_dir.mkdir(parents=True, exist_ok=True)

    specs = []
    for index, geometry in enumerate(geometries):
        path = temp_dir / f"geometry_{index}.ply"
        if isinstance(geometry, o3d.geometry.PointCloud):
            if not o3d.io.write_point_cloud(str(path), geometry):
                continue
            specs.append({"kind": "point_cloud", "path": str(path)})
        elif isinstance(geometry, o3d.geometry.TriangleMesh):
            if not o3d.io.write_triangle_mesh(str(path), geometry):
                continue
            specs.append({"kind": "triangle_mesh", "path": str(path)})
        elif isinstance(geometry, o3d.geometry.LineSet):
            if not o3d.io.write_line_set(str(path), geometry):
                continue
            specs.append({"kind": "line_set", "path": str(path)})
        else:
            logging.warning("Skipping unsupported Open3D geometry type: %s", type(geometry).__name__)

    if not specs:
        shutil.rmtree(temp_dir, ignore_errors=True)
        logging.warning("Open3D display skipped because no supported geometries were provided")
        return None

    viewer_options = {
        key: value
        for key, value in kwargs.items()
        if key in {"window_name", "width", "height", "left", "top", "point_show_normal", "duration_seconds"}
    }
    viewer_options.setdefault("duration_seconds", 5.0)

    subprocess.Popen(
        [
            sys.executable,
            "-c",
            _OPEN3D_VIEWER_SCRIPT,
            str(temp_dir),
            json.dumps(specs),
            json.dumps(viewer_options),
        ],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        stdin=subprocess.DEVNULL,
        start_new_session=True,
    )
    return None


_OPEN3D_VIEWER_SCRIPT = r"""
import json
import shutil
import sys
import time
from pathlib import Path

import open3d as o3d

temp_dir = Path(sys.argv[1])
specs = json.loads(sys.argv[2])
viewer_options = json.loads(sys.argv[3])

geometries = []
for spec in specs:
    kind = spec["kind"]
    path = spec["path"]
    if kind == "point_cloud":
        geometry = o3d.io.read_point_cloud(path)
    elif kind == "triangle_mesh":
        geometry = o3d.io.read_triangle_mesh(path)
    elif kind == "line_set":
        geometry = o3d.io.read_line_set(path)
    else:
        continue
    if not geometry.is_empty():
        geometries.append(geometry)

try:
    if geometries:
        duration_seconds = float(viewer_options.pop("duration_seconds", 5.0))
        point_show_normal = bool(viewer_options.pop("point_show_normal", False))
        create_window_options = {
            key: viewer_options[key]
            for key in ("window_name", "width", "height", "left", "top")
            if key in viewer_options
        }
        create_window_options.setdefault("window_name", "ThinkGrasp Open3D")

        visualizer = o3d.visualization.Visualizer()
        visualizer.create_window(**create_window_options)
        for geometry in geometries:
            visualizer.add_geometry(geometry)
        render_option = visualizer.get_render_option()
        if render_option is not None:
            render_option.point_show_normal = point_show_normal

        end_time = time.time() + max(0.0, duration_seconds)
        while time.time() < end_time:
            if not visualizer.poll_events():
                break
            visualizer.update_renderer()
            time.sleep(0.03)
        visualizer.destroy_window()
finally:
    shutil.rmtree(temp_dir, ignore_errors=True)
"""
