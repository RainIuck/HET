import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    pkg_share = get_package_share_directory("alicia_d_pick_coordinator")
    config_file = os.path.join(pkg_share, "config", "pick_coordinator.yaml")
    waypoints_file = os.path.join(pkg_share, "config", "waypoints.yaml")
    place_path_file = os.path.join(pkg_share, "config", "place_path.yaml")
    return LaunchDescription([
        Node(
            package="alicia_d_pick_coordinator",
            executable="pick_coordinator.py",
            name="pick_coordinator",
            namespace="pick_coordinator",
            output="screen",
            parameters=[
                config_file,
                waypoints_file,
                {"place_path_file": place_path_file},
            ],
        ),
    ])
