from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_share = get_package_share_directory('alicia_d_thinkgrasp_bridge')
    config_file = os.path.join(pkg_share, 'config', 'zerotier_grasp.yaml')

    decision_url = LaunchConfiguration('decision_url')
    execute_motion = LaunchConfiguration('execute_motion')
    image_path = LaunchConfiguration('image_path')
    depth_path = LaunchConfiguration('depth_path')
    text_path = LaunchConfiguration('text_path')

    return LaunchDescription([
        DeclareLaunchArgument(
            'decision_url',
            default_value='http://10.246.52.176:5000/grasp_pose_upload',
            description='ThinkGrasp upload endpoint reachable through ZeroTier.',
        ),
        DeclareLaunchArgument(
            'execute_motion',
            default_value='true',
            description='Whether to execute trajectories after IK and planning succeed.',
        ),
        DeclareLaunchArgument(
            'image_path',
            default_value='/tmp/mock_rgb.png',
            description='Local RGB image path on the Alicia-D control host.',
        ),
        DeclareLaunchArgument(
            'depth_path',
            default_value='/tmp/mock_depth.png',
            description='Local raw depth PNG path on the Alicia-D control host.',
        ),
        DeclareLaunchArgument(
            'text_path',
            default_value='/tmp/mock_task.txt',
            description='Local task text path on the Alicia-D control host.',
        ),
        Node(
            package='alicia_d_thinkgrasp_bridge',
            executable='thinkgrasp_mock_pick.py',
            name='thinkgrasp_mock_pick',
            output='screen',
            parameters=[
                config_file,
                {
                    'decision_url': decision_url,
                    'decision_request_mode': 'multipart_upload',
                    'execute_motion': execute_motion,
                    'image_path': image_path,
                    'depth_path': depth_path,
                    'text_path': text_path,
                },
            ],
        ),
    ])
