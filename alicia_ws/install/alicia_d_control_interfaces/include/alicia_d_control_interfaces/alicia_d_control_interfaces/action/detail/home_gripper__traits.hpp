// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from alicia_d_control_interfaces:action/HomeGripper.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__HOME_GRIPPER__TRAITS_HPP_
#define ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__HOME_GRIPPER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "alicia_d_control_interfaces/action/detail/home_gripper__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace alicia_d_control_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const HomeGripper_Goal & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HomeGripper_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HomeGripper_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace alicia_d_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use alicia_d_control_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const alicia_d_control_interfaces::action::HomeGripper_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  alicia_d_control_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use alicia_d_control_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const alicia_d_control_interfaces::action::HomeGripper_Goal & msg)
{
  return alicia_d_control_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<alicia_d_control_interfaces::action::HomeGripper_Goal>()
{
  return "alicia_d_control_interfaces::action::HomeGripper_Goal";
}

template<>
inline const char * name<alicia_d_control_interfaces::action::HomeGripper_Goal>()
{
  return "alicia_d_control_interfaces/action/HomeGripper_Goal";
}

template<>
struct has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<alicia_d_control_interfaces::action::HomeGripper_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace alicia_d_control_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const HomeGripper_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HomeGripper_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HomeGripper_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace alicia_d_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use alicia_d_control_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const alicia_d_control_interfaces::action::HomeGripper_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  alicia_d_control_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use alicia_d_control_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const alicia_d_control_interfaces::action::HomeGripper_Result & msg)
{
  return alicia_d_control_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<alicia_d_control_interfaces::action::HomeGripper_Result>()
{
  return "alicia_d_control_interfaces::action::HomeGripper_Result";
}

template<>
inline const char * name<alicia_d_control_interfaces::action::HomeGripper_Result>()
{
  return "alicia_d_control_interfaces/action/HomeGripper_Result";
}

template<>
struct has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<alicia_d_control_interfaces::action::HomeGripper_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace alicia_d_control_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const HomeGripper_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: raw_position
  {
    out << "raw_position: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_position, out);
    out << ", ";
  }

  // member: moving
  {
    out << "moving: ";
    rosidl_generator_traits::value_to_yaml(msg.moving, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HomeGripper_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: raw_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_position: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_position, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HomeGripper_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace alicia_d_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use alicia_d_control_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const alicia_d_control_interfaces::action::HomeGripper_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  alicia_d_control_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use alicia_d_control_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const alicia_d_control_interfaces::action::HomeGripper_Feedback & msg)
{
  return alicia_d_control_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<alicia_d_control_interfaces::action::HomeGripper_Feedback>()
{
  return "alicia_d_control_interfaces::action::HomeGripper_Feedback";
}

template<>
inline const char * name<alicia_d_control_interfaces::action::HomeGripper_Feedback>()
{
  return "alicia_d_control_interfaces/action/HomeGripper_Feedback";
}

template<>
struct has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<alicia_d_control_interfaces::action::HomeGripper_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "alicia_d_control_interfaces/action/detail/home_gripper__traits.hpp"

namespace alicia_d_control_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const HomeGripper_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HomeGripper_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HomeGripper_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace alicia_d_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use alicia_d_control_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const alicia_d_control_interfaces::action::HomeGripper_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  alicia_d_control_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use alicia_d_control_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const alicia_d_control_interfaces::action::HomeGripper_SendGoal_Request & msg)
{
  return alicia_d_control_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Request>()
{
  return "alicia_d_control_interfaces::action::HomeGripper_SendGoal_Request";
}

template<>
inline const char * name<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Request>()
{
  return "alicia_d_control_interfaces/action/HomeGripper_SendGoal_Request";
}

template<>
struct has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace alicia_d_control_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const HomeGripper_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HomeGripper_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HomeGripper_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace alicia_d_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use alicia_d_control_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const alicia_d_control_interfaces::action::HomeGripper_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  alicia_d_control_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use alicia_d_control_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const alicia_d_control_interfaces::action::HomeGripper_SendGoal_Response & msg)
{
  return alicia_d_control_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Response>()
{
  return "alicia_d_control_interfaces::action::HomeGripper_SendGoal_Response";
}

template<>
inline const char * name<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Response>()
{
  return "alicia_d_control_interfaces/action/HomeGripper_SendGoal_Response";
}

template<>
struct has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<alicia_d_control_interfaces::action::HomeGripper_SendGoal>()
{
  return "alicia_d_control_interfaces::action::HomeGripper_SendGoal";
}

template<>
inline const char * name<alicia_d_control_interfaces::action::HomeGripper_SendGoal>()
{
  return "alicia_d_control_interfaces/action/HomeGripper_SendGoal";
}

template<>
struct has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Request>::value &&
    has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Request>::value &&
    has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<alicia_d_control_interfaces::action::HomeGripper_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<alicia_d_control_interfaces::action::HomeGripper_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace alicia_d_control_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const HomeGripper_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HomeGripper_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HomeGripper_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace alicia_d_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use alicia_d_control_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const alicia_d_control_interfaces::action::HomeGripper_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  alicia_d_control_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use alicia_d_control_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const alicia_d_control_interfaces::action::HomeGripper_GetResult_Request & msg)
{
  return alicia_d_control_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<alicia_d_control_interfaces::action::HomeGripper_GetResult_Request>()
{
  return "alicia_d_control_interfaces::action::HomeGripper_GetResult_Request";
}

template<>
inline const char * name<alicia_d_control_interfaces::action::HomeGripper_GetResult_Request>()
{
  return "alicia_d_control_interfaces/action/HomeGripper_GetResult_Request";
}

template<>
struct has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<alicia_d_control_interfaces::action::HomeGripper_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "alicia_d_control_interfaces/action/detail/home_gripper__traits.hpp"

namespace alicia_d_control_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const HomeGripper_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HomeGripper_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HomeGripper_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace alicia_d_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use alicia_d_control_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const alicia_d_control_interfaces::action::HomeGripper_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  alicia_d_control_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use alicia_d_control_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const alicia_d_control_interfaces::action::HomeGripper_GetResult_Response & msg)
{
  return alicia_d_control_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<alicia_d_control_interfaces::action::HomeGripper_GetResult_Response>()
{
  return "alicia_d_control_interfaces::action::HomeGripper_GetResult_Response";
}

template<>
inline const char * name<alicia_d_control_interfaces::action::HomeGripper_GetResult_Response>()
{
  return "alicia_d_control_interfaces/action/HomeGripper_GetResult_Response";
}

template<>
struct has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_Result>::value> {};

template<>
struct has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_Result>::value> {};

template<>
struct is_message<alicia_d_control_interfaces::action::HomeGripper_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<alicia_d_control_interfaces::action::HomeGripper_GetResult>()
{
  return "alicia_d_control_interfaces::action::HomeGripper_GetResult";
}

template<>
inline const char * name<alicia_d_control_interfaces::action::HomeGripper_GetResult>()
{
  return "alicia_d_control_interfaces/action/HomeGripper_GetResult";
}

template<>
struct has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_GetResult_Request>::value &&
    has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_GetResult_Request>::value &&
    has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_GetResult_Response>::value
  >
{
};

template<>
struct is_service<alicia_d_control_interfaces::action::HomeGripper_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<alicia_d_control_interfaces::action::HomeGripper_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<alicia_d_control_interfaces::action::HomeGripper_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "alicia_d_control_interfaces/action/detail/home_gripper__traits.hpp"

namespace alicia_d_control_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const HomeGripper_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HomeGripper_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HomeGripper_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace alicia_d_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use alicia_d_control_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const alicia_d_control_interfaces::action::HomeGripper_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  alicia_d_control_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use alicia_d_control_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const alicia_d_control_interfaces::action::HomeGripper_FeedbackMessage & msg)
{
  return alicia_d_control_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<alicia_d_control_interfaces::action::HomeGripper_FeedbackMessage>()
{
  return "alicia_d_control_interfaces::action::HomeGripper_FeedbackMessage";
}

template<>
inline const char * name<alicia_d_control_interfaces::action::HomeGripper_FeedbackMessage>()
{
  return "alicia_d_control_interfaces/action/HomeGripper_FeedbackMessage";
}

template<>
struct has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<alicia_d_control_interfaces::action::HomeGripper_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<alicia_d_control_interfaces::action::HomeGripper_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<alicia_d_control_interfaces::action::HomeGripper_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<alicia_d_control_interfaces::action::HomeGripper>
  : std::true_type
{
};

template<>
struct is_action_goal<alicia_d_control_interfaces::action::HomeGripper_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<alicia_d_control_interfaces::action::HomeGripper_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<alicia_d_control_interfaces::action::HomeGripper_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__HOME_GRIPPER__TRAITS_HPP_
