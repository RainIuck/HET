cmake_minimum_required(VERSION 3.8)
project(alicia_d_control_interfaces)

find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/GraspCandidate.msg"
  "msg/GripperState.msg"
  "action/ForceGrasp.action"
  "action/HomeGripper.action"
  "action/MoveArmToJoints.action"
  "action/MoveArmToPose.action"
  "action/MoveGripper.action"
  "action/MoveGripperStep.action"
  DEPENDENCIES geometry_msgs std_msgs
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
