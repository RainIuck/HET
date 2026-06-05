// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from alicia_d_control_interfaces:msg/GraspCandidate.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "alicia_d_control_interfaces/msg/detail/grasp_candidate__rosidl_typesupport_introspection_c.h"
#include "alicia_d_control_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "alicia_d_control_interfaces/msg/detail/grasp_candidate__functions.h"
#include "alicia_d_control_interfaces/msg/detail/grasp_candidate__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `grasp_pose`
#include "geometry_msgs/msg/pose.h"
// Member `grasp_pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `source`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  alicia_d_control_interfaces__msg__GraspCandidate__init(message_memory);
}

void alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_fini_function(void * message_memory)
{
  alicia_d_control_interfaces__msg__GraspCandidate__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces__msg__GraspCandidate, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "grasp_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces__msg__GraspCandidate, grasp_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "grasp_depth_m",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces__msg__GraspCandidate, grasp_depth_m),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "source",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(alicia_d_control_interfaces__msg__GraspCandidate, source),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_message_members = {
  "alicia_d_control_interfaces__msg",  // message namespace
  "GraspCandidate",  // message name
  4,  // number of fields
  sizeof(alicia_d_control_interfaces__msg__GraspCandidate),
  alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_message_member_array,  // message members
  alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_init_function,  // function to initialize message memory (memory has to be allocated)
  alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_message_type_support_handle = {
  0,
  &alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_alicia_d_control_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, alicia_d_control_interfaces, msg, GraspCandidate)() {
  alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_message_type_support_handle.typesupport_identifier) {
    alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &alicia_d_control_interfaces__msg__GraspCandidate__rosidl_typesupport_introspection_c__GraspCandidate_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
