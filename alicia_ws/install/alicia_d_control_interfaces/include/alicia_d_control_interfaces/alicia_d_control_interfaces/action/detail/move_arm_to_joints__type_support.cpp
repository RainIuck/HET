// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from alicia_d_control_interfaces:action/MoveArmToJoints.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveArmToJoints_Goal_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveArmToJoints_Goal(_init);
}

void MoveArmToJoints_Goal_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveArmToJoints_Goal *>(message_memory);
  typed_message->~MoveArmToJoints_Goal();
}

size_t size_function__MoveArmToJoints_Goal__joint_names(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MoveArmToJoints_Goal__joint_names(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__MoveArmToJoints_Goal__joint_names(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__MoveArmToJoints_Goal__joint_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__MoveArmToJoints_Goal__joint_names(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__MoveArmToJoints_Goal__joint_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__MoveArmToJoints_Goal__joint_names(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__MoveArmToJoints_Goal__joint_names(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MoveArmToJoints_Goal__joint_positions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MoveArmToJoints_Goal__joint_positions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__MoveArmToJoints_Goal__joint_positions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__MoveArmToJoints_Goal__joint_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__MoveArmToJoints_Goal__joint_positions(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__MoveArmToJoints_Goal__joint_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__MoveArmToJoints_Goal__joint_positions(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__MoveArmToJoints_Goal__joint_positions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveArmToJoints_Goal_message_member_array[5] = {
  {
    "joint_names",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_Goal, joint_names),  // bytes offset in struct
    nullptr,  // default value
    size_function__MoveArmToJoints_Goal__joint_names,  // size() function pointer
    get_const_function__MoveArmToJoints_Goal__joint_names,  // get_const(index) function pointer
    get_function__MoveArmToJoints_Goal__joint_names,  // get(index) function pointer
    fetch_function__MoveArmToJoints_Goal__joint_names,  // fetch(index, &value) function pointer
    assign_function__MoveArmToJoints_Goal__joint_names,  // assign(index, value) function pointer
    resize_function__MoveArmToJoints_Goal__joint_names  // resize(index) function pointer
  },
  {
    "joint_positions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_Goal, joint_positions),  // bytes offset in struct
    nullptr,  // default value
    size_function__MoveArmToJoints_Goal__joint_positions,  // size() function pointer
    get_const_function__MoveArmToJoints_Goal__joint_positions,  // get_const(index) function pointer
    get_function__MoveArmToJoints_Goal__joint_positions,  // get(index) function pointer
    fetch_function__MoveArmToJoints_Goal__joint_positions,  // fetch(index, &value) function pointer
    assign_function__MoveArmToJoints_Goal__joint_positions,  // assign(index, value) function pointer
    resize_function__MoveArmToJoints_Goal__joint_positions  // resize(index) function pointer
  },
  {
    "max_velocity_scaling",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_Goal, max_velocity_scaling),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "max_acceleration_scaling",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_Goal, max_acceleration_scaling),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "execute",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_Goal, execute),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveArmToJoints_Goal_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveArmToJoints_Goal",  // message name
  5,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveArmToJoints_Goal),
  MoveArmToJoints_Goal_message_member_array,  // message members
  MoveArmToJoints_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveArmToJoints_Goal_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveArmToJoints_Goal_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveArmToJoints_Goal_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace alicia_d_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_Goal>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_Goal_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveArmToJoints_Goal)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveArmToJoints_Result_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveArmToJoints_Result(_init);
}

void MoveArmToJoints_Result_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveArmToJoints_Result *>(message_memory);
  typed_message->~MoveArmToJoints_Result();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveArmToJoints_Result_message_member_array[3] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_Result, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "moveit_error_code",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_Result, moveit_error_code),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "message",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_Result, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveArmToJoints_Result_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveArmToJoints_Result",  // message name
  3,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveArmToJoints_Result),
  MoveArmToJoints_Result_message_member_array,  // message members
  MoveArmToJoints_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveArmToJoints_Result_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveArmToJoints_Result_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveArmToJoints_Result_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace alicia_d_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_Result>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_Result_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveArmToJoints_Result)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveArmToJoints_Feedback_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveArmToJoints_Feedback(_init);
}

void MoveArmToJoints_Feedback_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveArmToJoints_Feedback *>(message_memory);
  typed_message->~MoveArmToJoints_Feedback();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveArmToJoints_Feedback_message_member_array[1] = {
  {
    "stage",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_Feedback, stage),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveArmToJoints_Feedback_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveArmToJoints_Feedback",  // message name
  1,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveArmToJoints_Feedback),
  MoveArmToJoints_Feedback_message_member_array,  // message members
  MoveArmToJoints_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveArmToJoints_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveArmToJoints_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveArmToJoints_Feedback_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace alicia_d_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_Feedback>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_Feedback_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveArmToJoints_Feedback)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveArmToJoints_SendGoal_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request(_init);
}

void MoveArmToJoints_SendGoal_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request *>(message_memory);
  typed_message->~MoveArmToJoints_SendGoal_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveArmToJoints_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "goal",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_Goal>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request, goal),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveArmToJoints_SendGoal_Request_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveArmToJoints_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request),
  MoveArmToJoints_SendGoal_Request_message_member_array,  // message members
  MoveArmToJoints_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveArmToJoints_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveArmToJoints_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveArmToJoints_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace alicia_d_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_SendGoal_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveArmToJoints_SendGoal_Request)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveArmToJoints_SendGoal_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response(_init);
}

void MoveArmToJoints_SendGoal_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response *>(message_memory);
  typed_message->~MoveArmToJoints_SendGoal_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveArmToJoints_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response, accepted),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response, stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveArmToJoints_SendGoal_Response_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveArmToJoints_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response),
  MoveArmToJoints_SendGoal_Response_message_member_array,  // message members
  MoveArmToJoints_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveArmToJoints_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveArmToJoints_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveArmToJoints_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace alicia_d_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_SendGoal_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveArmToJoints_SendGoal_Response)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers MoveArmToJoints_SendGoal_service_members = {
  "alicia_d_control_interfaces::action",  // service namespace
  "MoveArmToJoints_SendGoal",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t MoveArmToJoints_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveArmToJoints_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace alicia_d_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_SendGoal_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveArmToJoints_SendGoal)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveArmToJoints_GetResult_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Request(_init);
}

void MoveArmToJoints_GetResult_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Request *>(message_memory);
  typed_message->~MoveArmToJoints_GetResult_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveArmToJoints_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Request, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveArmToJoints_GetResult_Request_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveArmToJoints_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Request),
  MoveArmToJoints_GetResult_Request_message_member_array,  // message members
  MoveArmToJoints_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveArmToJoints_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveArmToJoints_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveArmToJoints_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace alicia_d_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Request>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_GetResult_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveArmToJoints_GetResult_Request)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveArmToJoints_GetResult_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response(_init);
}

void MoveArmToJoints_GetResult_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response *>(message_memory);
  typed_message->~MoveArmToJoints_GetResult_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveArmToJoints_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response, status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "result",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_Result>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response, result),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveArmToJoints_GetResult_Response_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveArmToJoints_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response),
  MoveArmToJoints_GetResult_Response_message_member_array,  // message members
  MoveArmToJoints_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveArmToJoints_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveArmToJoints_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveArmToJoints_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace alicia_d_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_GetResult_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveArmToJoints_GetResult_Response)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers MoveArmToJoints_GetResult_service_members = {
  "alicia_d_control_interfaces::action",  // service namespace
  "MoveArmToJoints_GetResult",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_GetResult>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t MoveArmToJoints_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveArmToJoints_GetResult_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace alicia_d_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_GetResult>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_GetResult_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveArmToJoints_GetResult)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveArmToJoints_FeedbackMessage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage(_init);
}

void MoveArmToJoints_FeedbackMessage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage *>(message_memory);
  typed_message->~MoveArmToJoints_FeedbackMessage();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveArmToJoints_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "feedback",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_Feedback>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage, feedback),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveArmToJoints_FeedbackMessage_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveArmToJoints_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage),
  MoveArmToJoints_FeedbackMessage_message_member_array,  // message members
  MoveArmToJoints_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveArmToJoints_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveArmToJoints_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveArmToJoints_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace alicia_d_control_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_FeedbackMessage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveArmToJoints_FeedbackMessage)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveArmToJoints_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
