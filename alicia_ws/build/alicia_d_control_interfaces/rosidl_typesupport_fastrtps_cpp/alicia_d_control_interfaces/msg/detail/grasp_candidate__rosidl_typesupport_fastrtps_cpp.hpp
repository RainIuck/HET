// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from alicia_d_control_interfaces:msg/GraspCandidate.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "alicia_d_control_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "alicia_d_control_interfaces/msg/detail/grasp_candidate__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace alicia_d_control_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_alicia_d_control_interfaces
cdr_serialize(
  const alicia_d_control_interfaces::msg::GraspCandidate & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_alicia_d_control_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  alicia_d_control_interfaces::msg::GraspCandidate & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_alicia_d_control_interfaces
get_serialized_size(
  const alicia_d_control_interfaces::msg::GraspCandidate & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_alicia_d_control_interfaces
max_serialized_size_GraspCandidate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace alicia_d_control_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_alicia_d_control_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, alicia_d_control_interfaces, msg, GraspCandidate)();

#ifdef __cplusplus
}
#endif

#endif  // ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
