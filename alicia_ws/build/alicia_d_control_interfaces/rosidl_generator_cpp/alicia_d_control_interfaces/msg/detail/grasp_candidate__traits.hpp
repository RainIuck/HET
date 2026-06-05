// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from alicia_d_control_interfaces:msg/GraspCandidate.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__TRAITS_HPP_
#define ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "alicia_d_control_interfaces/msg/detail/grasp_candidate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'grasp_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace alicia_d_control_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GraspCandidate & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: grasp_pose
  {
    out << "grasp_pose: ";
    to_flow_style_yaml(msg.grasp_pose, out);
    out << ", ";
  }

  // member: grasp_depth_m
  {
    out << "grasp_depth_m: ";
    rosidl_generator_traits::value_to_yaml(msg.grasp_depth_m, out);
    out << ", ";
  }

  // member: source
  {
    out << "source: ";
    rosidl_generator_traits::value_to_yaml(msg.source, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GraspCandidate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: grasp_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "grasp_pose:\n";
    to_block_style_yaml(msg.grasp_pose, out, indentation + 2);
  }

  // member: grasp_depth_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "grasp_depth_m: ";
    rosidl_generator_traits::value_to_yaml(msg.grasp_depth_m, out);
    out << "\n";
  }

  // member: source
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "source: ";
    rosidl_generator_traits::value_to_yaml(msg.source, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GraspCandidate & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace alicia_d_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use alicia_d_control_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const alicia_d_control_interfaces::msg::GraspCandidate & msg,
  std::ostream & out, size_t indentation = 0)
{
  alicia_d_control_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use alicia_d_control_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const alicia_d_control_interfaces::msg::GraspCandidate & msg)
{
  return alicia_d_control_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<alicia_d_control_interfaces::msg::GraspCandidate>()
{
  return "alicia_d_control_interfaces::msg::GraspCandidate";
}

template<>
inline const char * name<alicia_d_control_interfaces::msg::GraspCandidate>()
{
  return "alicia_d_control_interfaces/msg/GraspCandidate";
}

template<>
struct has_fixed_size<alicia_d_control_interfaces::msg::GraspCandidate>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<alicia_d_control_interfaces::msg::GraspCandidate>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<alicia_d_control_interfaces::msg::GraspCandidate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__TRAITS_HPP_
