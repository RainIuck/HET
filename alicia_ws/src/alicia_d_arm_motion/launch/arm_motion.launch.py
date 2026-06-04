import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    pkg_share = get_package_share_directory("alicia_d_arm_motion")
    config_file = os.path.join(pkg_share, "config", "arm_motion.yaml")
    return LaunchDescription([
        Node(
            package="alicia_d_arm_motion",
            executable="arm_motion_server.py",
            name="arm_motion_server",
            namespace="arm_motion",
            output="screen",
            parameters=[config_file],
        ),
    ])
