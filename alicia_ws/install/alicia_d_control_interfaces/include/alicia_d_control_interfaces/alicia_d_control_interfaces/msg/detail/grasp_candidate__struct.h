// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from alicia_d_control_interfaces:msg/GraspCandidate.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__STRUCT_H_
#define ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__STRUCT_H_

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
// Member 'grasp_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'source'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/GraspCandidate in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__msg__GraspCandidate
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Pose grasp_pose;
  double grasp_depth_m;
  rosidl_runtime_c__String source;
} alicia_d_control_interfaces__msg__GraspCandidate;

// Struct for a sequence of alicia_d_control_interfaces__msg__GraspCandidate.
typedef struct alicia_d_control_interfaces__msg__GraspCandidate__Sequence
{
  alicia_d_control_interfaces__msg__GraspCandidate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__msg__GraspCandidate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__STRUCT_H_
