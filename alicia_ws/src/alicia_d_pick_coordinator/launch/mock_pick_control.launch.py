import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource


def include_launch(package_name, launch_name):
    path = os.path.join(
        get_package_share_directory(package_name),
        "launch",
        launch_name,
    )
    return IncludeLaunchDescription(PythonLaunchDescriptionSource(path))


def generate_launch_description():
    return LaunchDescription([
        include_launch("alicia_d_thinkgrasp_bridge", "mock_thinkgrasp_bridge.launch.py"),
        include_launch("alicia_d_arm_motion", "arm_motion.launch.py"),
        include_launch("alicia_d_sts_gripper", "sts3215_gripper.launch.py"),
        include_launch("alicia_d_pick_coordinator", "pick_coordinator.launch.py"),
    ])
