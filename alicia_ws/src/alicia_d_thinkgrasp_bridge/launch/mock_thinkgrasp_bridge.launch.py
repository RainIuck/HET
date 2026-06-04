import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    pkg_share = get_package_share_directory("alicia_d_thinkgrasp_bridge")
    config_file = os.path.join(pkg_share, "config", "mock_grasp.yaml")

    return LaunchDescription([
        Node(
            package="alicia_d_thinkgrasp_bridge",
            executable="mock_decision_server.py",
            name="mock_decision_server",
            output="screen",
            parameters=[config_file],
        ),
        Node(
            package="alicia_d_thinkgrasp_bridge",
            executable="thinkgrasp_bridge_node.py",
            name="thinkgrasp_bridge",
            namespace="thinkgrasp",
            output="screen",
            parameters=[config_file],
        ),
    ])
