cmake_minimum_required(VERSION 3.8)
project(alicia_d_sts_gripper)

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclpy REQUIRED)

ament_python_install_package(${PROJECT_NAME})

install(PROGRAMS
  scripts/gripper_action_node.py
  scripts/sts3215_raw_tool.py
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  config
  launch
  DESTINATION share/${PROJECT_NAME}
)

install(FILES
  gripper_readme.md
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
