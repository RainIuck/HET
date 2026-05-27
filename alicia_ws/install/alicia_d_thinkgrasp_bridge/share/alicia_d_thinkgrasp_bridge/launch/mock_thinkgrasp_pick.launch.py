from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_share = get_package_share_directory('alicia_d_thinkgrasp_bridge')
    config_file = os.path.join(pkg_share, 'config', 'mock_grasp.yaml')

    execute_motion = LaunchConfiguration('execute_motion')

    return LaunchDescription([
        DeclareLaunchArgument(
            'execute_motion',
            default_value='true',
            description='Whether to execute trajectories after IK and planning succeed.',
        ),
        Node(
            package='alicia_d_thinkgrasp_bridge',
            executable='mock_decision_server.py',
            name='mock_decision_server',
            output='screen',
            parameters=[config_file],
        ),
        Node(
            package='alicia_d_thinkgrasp_bridge',
            executable='thinkgrasp_mock_pick.py',
            name='thinkgrasp_mock_pick',
            output='screen',
            parameters=[
                config_file,
                {'execute_motion': execute_motion},
            ],
        ),
    ])
