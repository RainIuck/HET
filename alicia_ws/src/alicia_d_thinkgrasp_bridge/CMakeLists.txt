cmake_minimum_required(VERSION 3.8)
project(alicia_d_thinkgrasp_bridge)

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclpy REQUIRED)

ament_python_install_package(${PROJECT_NAME})

install(PROGRAMS
  scripts/ik_workspace_probe.py
  scripts/mock_decision_server.py
  scripts/safe_joint_raise.py
  scripts/safe_tcp_lift.py
  scripts/thinkgrasp_mock_pick.py
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  config
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
