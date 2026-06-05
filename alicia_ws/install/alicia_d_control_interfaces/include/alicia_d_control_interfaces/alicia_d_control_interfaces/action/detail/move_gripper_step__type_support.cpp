// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from alicia_d_control_interfaces:action/MoveGripperStep.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "alicia_d_control_interfaces/action/detail/move_gripper_step__struct.hpp"
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

void MoveGripperStep_Goal_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveGripperStep_Goal(_init);
}

void MoveGripperStep_Goal_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveGripperStep_Goal *>(message_memory);
  typed_message->~MoveGripperStep_Goal();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveGripperStep_Goal_message_member_array[2] = {
  {
    "delta_ticks",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_Goal, delta_ticks),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_Goal, speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveGripperStep_Goal_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveGripperStep_Goal",  // message name
  2,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveGripperStep_Goal),
  MoveGripperStep_Goal_message_member_array,  // message members
  MoveGripperStep_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveGripperStep_Goal_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveGripperStep_Goal_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveGripperStep_Goal_message_members,
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
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_Goal>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_Goal_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveGripperStep_Goal)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_Goal_message_type_support_handle;
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
// #include "alicia_d_control_interfaces/action/detail/move_gripper_step__struct.hpp"
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

void MoveGripperStep_Result_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveGripperStep_Result(_init);
}

void MoveGripperStep_Result_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveGripperStep_Result *>(message_memory);
  typed_message->~MoveGripperStep_Result();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveGripperStep_Result_message_member_array[4] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_Result, success),  // bytes offset in struct
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
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_Result, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "raw_position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_Result, raw_position),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "moved_ticks",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_Result, moved_ticks),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveGripperStep_Result_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveGripperStep_Result",  // message name
  4,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveGripperStep_Result),
  MoveGripperStep_Result_message_member_array,  // message members
  MoveGripperStep_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveGripperStep_Result_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveGripperStep_Result_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveGripperStep_Result_message_members,
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
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_Result>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_Result_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveGripperStep_Result)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_Result_message_type_support_handle;
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
// #include "alicia_d_control_interfaces/action/detail/move_gripper_step__struct.hpp"
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

void MoveGripperStep_Feedback_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveGripperStep_Feedback(_init);
}

void MoveGripperStep_Feedback_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveGripperStep_Feedback *>(message_memory);
  typed_message->~MoveGripperStep_Feedback();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveGripperStep_Feedback_message_member_array[3] = {
  {
    "raw_position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_Feedback, raw_position),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "moved_ticks",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_Feedback, moved_ticks),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "moving",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_Feedback, moving),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveGripperStep_Feedback_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveGripperStep_Feedback",  // message name
  3,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveGripperStep_Feedback),
  MoveGripperStep_Feedback_message_member_array,  // message members
  MoveGripperStep_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveGripperStep_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveGripperStep_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveGripperStep_Feedback_message_members,
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
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_Feedback>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_Feedback_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveGripperStep_Feedback)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_Feedback_message_type_support_handle;
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
// #include "alicia_d_control_interfaces/action/detail/move_gripper_step__struct.hpp"
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

void MoveGripperStep_SendGoal_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request(_init);
}

void MoveGripperStep_SendGoal_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request *>(message_memory);
  typed_message->~MoveGripperStep_SendGoal_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveGripperStep_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request, goal_id),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_Goal>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request, goal),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveGripperStep_SendGoal_Request_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveGripperStep_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request),
  MoveGripperStep_SendGoal_Request_message_member_array,  // message members
  MoveGripperStep_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveGripperStep_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveGripperStep_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveGripperStep_SendGoal_Request_message_members,
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
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_SendGoal_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveGripperStep_SendGoal_Request)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_SendGoal_Request_message_type_support_handle;
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
// #include "alicia_d_control_interfaces/action/detail/move_gripper_step__struct.hpp"
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

void MoveGripperStep_SendGoal_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response(_init);
}

void MoveGripperStep_SendGoal_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response *>(message_memory);
  typed_message->~MoveGripperStep_SendGoal_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveGripperStep_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response, accepted),  // bytes offset in struct
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
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response, stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveGripperStep_SendGoal_Response_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveGripperStep_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response),
  MoveGripperStep_SendGoal_Response_message_member_array,  // message members
  MoveGripperStep_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveGripperStep_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveGripperStep_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveGripperStep_SendGoal_Response_message_members,
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
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_SendGoal_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveGripperStep_SendGoal_Response)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_SendGoal_Response_message_type_support_handle;
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
// #include "alicia_d_control_interfaces/action/detail/move_gripper_step__struct.hpp"
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
static ::rosidl_typesupport_introspection_cpp::ServiceMembers MoveGripperStep_SendGoal_service_members = {
  "alicia_d_control_interfaces::action",  // service namespace
  "MoveGripperStep_SendGoal",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_SendGoal>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t MoveGripperStep_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveGripperStep_SendGoal_service_members,
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
get_service_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_SendGoal>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_SendGoal_service_type_support_handle;
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
        ::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveGripperStep_SendGoal)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_SendGoal>();
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
// #include "alicia_d_control_interfaces/action/detail/move_gripper_step__struct.hpp"
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

void MoveGripperStep_GetResult_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Request(_init);
}

void MoveGripperStep_GetResult_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Request *>(message_memory);
  typed_message->~MoveGripperStep_GetResult_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveGripperStep_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Request, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveGripperStep_GetResult_Request_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveGripperStep_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Request),
  MoveGripperStep_GetResult_Request_message_member_array,  // message members
  MoveGripperStep_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveGripperStep_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveGripperStep_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveGripperStep_GetResult_Request_message_members,
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
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Request>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_GetResult_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveGripperStep_GetResult_Request)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_GetResult_Request_message_type_support_handle;
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
// #include "alicia_d_control_interfaces/action/detail/move_gripper_step__struct.hpp"
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

void MoveGripperStep_GetResult_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response(_init);
}

void MoveGripperStep_GetResult_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response *>(message_memory);
  typed_message->~MoveGripperStep_GetResult_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveGripperStep_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response, status),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_Result>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response, result),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveGripperStep_GetResult_Response_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveGripperStep_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response),
  MoveGripperStep_GetResult_Response_message_member_array,  // message members
  MoveGripperStep_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveGripperStep_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveGripperStep_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveGripperStep_GetResult_Response_message_members,
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
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_GetResult_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveGripperStep_GetResult_Response)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_GetResult_Response_message_type_support_handle;
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
// #include "alicia_d_control_interfaces/action/detail/move_gripper_step__struct.hpp"
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
static ::rosidl_typesupport_introspection_cpp::ServiceMembers MoveGripperStep_GetResult_service_members = {
  "alicia_d_control_interfaces::action",  // service namespace
  "MoveGripperStep_GetResult",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_GetResult>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t MoveGripperStep_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveGripperStep_GetResult_service_members,
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
get_service_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_GetResult>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_GetResult_service_type_support_handle;
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
        ::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveGripperStep_GetResult)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_GetResult>();
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
// #include "alicia_d_control_interfaces/action/detail/move_gripper_step__struct.hpp"
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

void MoveGripperStep_FeedbackMessage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage(_init);
}

void MoveGripperStep_FeedbackMessage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage *>(message_memory);
  typed_message->~MoveGripperStep_FeedbackMessage();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveGripperStep_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage, goal_id),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_Feedback>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage, feedback),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveGripperStep_FeedbackMessage_message_members = {
  "alicia_d_control_interfaces::action",  // message namespace
  "MoveGripperStep_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage),
  MoveGripperStep_FeedbackMessage_message_member_array,  // message members
  MoveGripperStep_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveGripperStep_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveGripperStep_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveGripperStep_FeedbackMessage_message_members,
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
get_message_type_support_handle<alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage>()
{
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_FeedbackMessage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, alicia_d_control_interfaces, action, MoveGripperStep_FeedbackMessage)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_introspection_cpp::MoveGripperStep_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
