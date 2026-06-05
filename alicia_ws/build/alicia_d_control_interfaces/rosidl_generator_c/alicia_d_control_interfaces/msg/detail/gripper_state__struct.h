// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from alicia_d_control_interfaces:msg/GripperState.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRIPPER_STATE__STRUCT_H_
#define ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRIPPER_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'fault'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/GripperState in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__msg__GripperState
{
  std_msgs__msg__Header header;
  bool connected;
  bool homed;
  int32_t raw_position;
  int32_t relative_ticks;
  int32_t target_position;
  bool position_error_direction;
  int32_t position_error_ticks;
  int32_t estimated_position_minus;
  int32_t estimated_position_plus;
  int32_t load_raw;
  int32_t current_raw;
  bool moving;
  float voltage_v;
  int32_t temperature_c;
  rosidl_runtime_c__String fault;
} alicia_d_control_interfaces__msg__GripperState;

// Struct for a sequence of alicia_d_control_interfaces__msg__GripperState.
typedef struct alicia_d_control_interfaces__msg__GripperState__Sequence
{
  alicia_d_control_interfaces__msg__GripperState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__msg__GripperState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRIPPER_STATE__STRUCT_H_
