"""Launch file for controlling real Alicia-D robot with MoveIt."""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from moveit_configs_utils.launches import generate_move_group_launch, generate_moveit_rviz_launch
from ament_index_python.packages import get_package_share_directory
import sys
import os
import subprocess
sys.path.append(os.path.dirname(__file__))
from moveit_config_builder import get_versioned_moveit_config


def load_hardware_defaults():
    """Load flat defaults from config/hardware_defaults.yaml without extra deps."""
    defaults = {
        "gripper_type": "50mm",
        "port": "",
        "speed_deg_s": "20",
        "debug_mode": "false",
        "use_open_loop_state": "false",
        "feedback_timeout_s": "0.5",
    }

    try:
        config_path = os.path.join(
            get_package_share_directory("alicia_d_moveit"),
            "config",
            "hardware_defaults.yaml",
        )
        in_section = False
        with open(config_path, "r", encoding="utf-8") as config_file:
            for raw_line in config_file:
                line = raw_line.split("#", 1)[0].rstrip()
                if not line.strip():
                    continue
                if line.strip() == "hardware_defaults:":
                    in_section = True
                    continue
                if not in_section or ":" not in line:
                    continue
                key, value = line.strip().split(":", 1)
                value = value.strip().strip('"').strip("'")
                if key in defaults:
                    defaults[key] = value
    except Exception as exc:
        print(f'\033[1;33m[WARN] Failed to load hardware_defaults.yaml: {exc}\033[0m')

    return defaults


def launch_setup(context, *args, **kwargs):
    """Setup real robot launch with versioned config."""
    # Get launch configuration values
    gripper_type = LaunchConfiguration('gripper_type').perform(context)
    port = LaunchConfiguration('port').perform(context)
    speed_deg_s = float(LaunchConfiguration('speed_deg_s').perform(context))
    debug_mode = LaunchConfiguration('debug_mode').perform(context)
    use_open_loop_state = LaunchConfiguration('use_open_loop_state').perform(context)
    feedback_timeout_s = float(LaunchConfiguration('feedback_timeout_s').perform(context))
    
    # Validate gripper type
    if gripper_type not in ["50mm", "100mm"]:
        print(f'\033[1;33m[WARN] Invalid gripper_type: {gripper_type}, using default: 50mm\033[0m')
        gripper_type = "50mm"
    
    print(f'\033[1;32m[INFO] Serial port: {port if port else "(auto-detect)"}\033[0m')
    print(f'\033[1;32m[INFO] Gripper type: {gripper_type}\033[0m')
    print(f'\033[1;32m[INFO] Speed: {speed_deg_s} deg/s\033[0m')
    print(f'\033[1;32m[INFO] Debug mode: {debug_mode}\033[0m')
    print(f'\033[1;32m[INFO] Open-loop state mirror: {use_open_loop_state}\033[0m')
    print(f'\033[1;32m[INFO] Feedback timeout: {feedback_timeout_s} s\033[0m')
    print(f'\033[1;33m[INFO] Real robot mode: Hardware connection required\033[0m')
    
    # Get versioned MoveIt config with specified gripper type, port, and speed
    moveit_config = get_versioned_moveit_config(
        gripper_type,
        port,
        use_fake_hardware=False,
        speed_deg_s=speed_deg_s,
        debug_mode=debug_mode,
        use_open_loop_state=use_open_loop_state,
        feedback_timeout_s=feedback_timeout_s,
    )
    
    # Update robot description with hardware interface parameters
    robot_description = moveit_config.robot_description
    
    # Controller manager node
    controller_manager_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[
            robot_description,
            PathJoinSubstitution([
                FindPackageShare("alicia_d_moveit"),
                "config",
                "ros2_controllers.yaml"
            ]),
        ],
        output="screen",
    )
    
    # Spawner for joint_state_broadcaster
    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster", "-c", "/controller_manager"],
        output="screen",
    )
    
    # Spawner for Alicia_controller (arm)
    arm_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["Alicia_controller", "-c", "/controller_manager"],
        output="screen",
    )
    
    # Spawner for Gripper_controller
    gripper_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["Gripper_controller", "-c", "/controller_manager"],
        output="screen",
    )
    
    # Generate move_group launch (with fake_execution=false for real robot)
    move_group_params = {
        "allow_trajectory_execution": True,
        "fake_execution": False,
        "capabilities": "",
        "disable_capabilities": "",
        "monitor_dynamics": False,
    }
    
    move_group_node = Node(
        package="moveit_ros_move_group",
        executable="move_group",
        output="screen",
        parameters=[
            moveit_config.to_dict(),
            move_group_params,
        ],
    )
    
    # RViz node
    rviz_config_file = PathJoinSubstitution([
        FindPackageShare("alicia_d_moveit"),
        "config",
        "moveit.rviz"
    ])
    
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config_file],
        parameters=[
            moveit_config.robot_description,
            moveit_config.robot_description_semantic,
            moveit_config.robot_description_kinematics,
            moveit_config.planning_pipelines,
            moveit_config.joint_limits,
        ],
    )
    
    # Robot state publisher
    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        output="screen",
        parameters=[robot_description],
    )
    
    # Delay arm and gripper controller spawners until joint_state_broadcaster is loaded
    delay_arm_controller_spawner = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=joint_state_broadcaster_spawner,
            on_exit=[arm_controller_spawner],
        )
    )
    
    delay_gripper_controller_spawner = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=arm_controller_spawner,
            on_exit=[gripper_controller_spawner],
        )
    )
    
    # Delay move_group until controllers are loaded
    delay_move_group = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=gripper_controller_spawner,
            on_exit=[move_group_node],
        )
    )
    
    nodes_to_start = [
        robot_state_publisher,
        controller_manager_node,
        joint_state_broadcaster_spawner,
        delay_arm_controller_spawner,
        delay_gripper_controller_spawner,
        delay_move_group,
        rviz_node,
    ]
    
    return nodes_to_start


def generate_launch_description():
    """Generate launch description for real robot control."""
    defaults = load_hardware_defaults()

    return LaunchDescription([

        DeclareLaunchArgument(
            'gripper_type',
            default_value=defaults['gripper_type'],
            description='Gripper type: "50mm" or "100mm"'
        ),
        DeclareLaunchArgument(
            'port',
            default_value=defaults['port'],
            description='Serial port for robot connection. Set in config/hardware_defaults.yaml or override here.'
        ),
        DeclareLaunchArgument(
            'speed_deg_s',
            default_value=defaults['speed_deg_s'],
            description='Default speed in degrees per second for joint movements.'
        ),
        DeclareLaunchArgument(
            'debug_mode',
            default_value=defaults['debug_mode'],
            description='Enable verbose hardware parser diagnostics.'
        ),
        DeclareLaunchArgument(
            'use_open_loop_state',
            default_value=defaults['use_open_loop_state'],
            description='Mirror commands as state instead of using Alicia-D hardware feedback.'
        ),
        DeclareLaunchArgument(
            'feedback_timeout_s',
            default_value=defaults['feedback_timeout_s'],
            description='Maximum age in seconds for Alicia-D joint feedback before it is treated as invalid.'
        ),
        OpaqueFunction(function=launch_setup)
    ])
