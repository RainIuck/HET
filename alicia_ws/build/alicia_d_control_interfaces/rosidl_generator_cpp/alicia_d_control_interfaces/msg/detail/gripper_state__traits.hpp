// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from alicia_d_control_interfaces:msg/GripperState.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRIPPER_STATE__TRAITS_HPP_
#define ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRIPPER_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "alicia_d_control_interfaces/msg/detail/gripper_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace alicia_d_control_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GripperState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: connected
  {
    out << "connected: ";
    rosidl_generator_traits::value_to_yaml(msg.connected, out);
    out << ", ";
  }

  // member: homed
  {
    out << "homed: ";
    rosidl_generator_traits::value_to_yaml(msg.homed, out);
    out << ", ";
  }

  // member: raw_position
  {
    out << "raw_position: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_position, out);
    out << ", ";
  }

  // member: relative_ticks
  {
    out << "relative_ticks: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_ticks, out);
    out << ", ";
  }

  // member: target_position
  {
    out << "target_position: ";
    rosidl_generator_traits::value_to_yaml(msg.target_position, out);
    out << ", ";
  }

  // member: position_error_direction
  {
    out << "position_error_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.position_error_direction, out);
    out << ", ";
  }

  // member: position_error_ticks
  {
    out << "position_error_ticks: ";
    rosidl_generator_traits::value_to_yaml(msg.position_error_ticks, out);
    out << ", ";
  }

  // member: estimated_position_minus
  {
    out << "estimated_position_minus: ";
    rosidl_generator_traits::value_to_yaml(msg.estimated_position_minus, out);
    out << ", ";
  }

  // member: estimated_position_plus
  {
    out << "estimated_position_plus: ";
    rosidl_generator_traits::value_to_yaml(msg.estimated_position_plus, out);
    out << ", ";
  }

  // member: load_raw
  {
    out << "load_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.load_raw, out);
    out << ", ";
  }

  // member: current_raw
  {
    out << "current_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.current_raw, out);
    out << ", ";
  }

  // member: moving
  {
    out << "moving: ";
    rosidl_generator_traits::value_to_yaml(msg.moving, out);
    out << ", ";
  }

  // member: voltage_v
  {
    out << "voltage_v: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_v, out);
    out << ", ";
  }

  // member: temperature_c
  {
    out << "temperature_c: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature_c, out);
    out << ", ";
  }

  // member: fault
  {
    out << "fault: ";
    rosidl_generator_traits::value_to_yaml(msg.fault, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GripperState & msg,
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

  // member: connected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "connected: ";
    rosidl_generator_traits::value_to_yaml(msg.connected, out);
    out << "\n";
  }

  // member: homed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "homed: ";
    rosidl_generator_traits::value_to_yaml(msg.homed, out);
    out << "\n";
  }

  // member: raw_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_position: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_position, out);
    out << "\n";
  }

  // member: relative_ticks
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "relative_ticks: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_ticks, out);
    out << "\n";
  }

  // member: target_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_position: ";
    rosidl_generator_traits::value_to_yaml(msg.target_position, out);
    out << "\n";
  }

  // member: position_error_direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_error_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.position_error_direction, out);
    out << "\n";
  }

  // member: position_error_ticks
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_error_ticks: ";
    rosidl_generator_traits::value_to_yaml(msg.position_error_ticks, out);
    out << "\n";
  }

  // member: estimated_position_minus
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "estimated_position_minus: ";
    rosidl_generator_traits::value_to_yaml(msg.estimated_position_minus, out);
    out << "\n";
  }

  // member: estimated_position_plus
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "estimated_position_plus: ";
    rosidl_generator_traits::value_to_yaml(msg.estimated_position_plus, out);
    out << "\n";
  }

  // member: load_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "load_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.load_raw, out);
    out << "\n";
  }

  // member: current_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.current_raw, out);
    out << "\n";
  }

  // member: moving
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "moving: ";
    rosidl_generator_traits::value_to_yaml(msg.moving, out);
    out << "\n";
  }

  // member: voltage_v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "voltage_v: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_v, out);
    out << "\n";
  }

  // member: temperature_c
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature_c: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature_c, out);
    out << "\n";
  }

  // member: fault
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fault: ";
    rosidl_generator_traits::value_to_yaml(msg.fault, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GripperState & msg, bool use_flow_style = false)
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
  const alicia_d_control_interfaces::msg::GripperState & msg,
  std::ostream & out, size_t indentation = 0)
{
  alicia_d_control_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use alicia_d_control_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const alicia_d_control_interfaces::msg::GripperState & msg)
{
  return alicia_d_control_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<alicia_d_control_interfaces::msg::GripperState>()
{
  return "alicia_d_control_interfaces::msg::GripperState";
}

template<>
inline const char * name<alicia_d_control_interfaces::msg::GripperState>()
{
  return "alicia_d_control_interfaces/msg/GripperState";
}

template<>
struct has_fixed_size<alicia_d_control_interfaces::msg::GripperState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<alicia_d_control_interfaces::msg::GripperState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<alicia_d_control_interfaces::msg::GripperState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRIPPER_STATE__TRAITS_HPP_
