// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from alicia_d_control_interfaces:action/HomeGripper.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__HOME_GRIPPER__STRUCT_H_
#define ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__HOME_GRIPPER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/HomeGripper in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__HomeGripper_Goal
{
  uint8_t structure_needs_at_least_one_member;
} alicia_d_control_interfaces__action__HomeGripper_Goal;

// Struct for a sequence of alicia_d_control_interfaces__action__HomeGripper_Goal.
typedef struct alicia_d_control_interfaces__action__HomeGripper_Goal__Sequence
{
  alicia_d_control_interfaces__action__HomeGripper_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__HomeGripper_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/HomeGripper in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__HomeGripper_Result
{
  bool success;
  rosidl_runtime_c__String message;
  int32_t raw_position;
  int32_t relative_ticks;
} alicia_d_control_interfaces__action__HomeGripper_Result;

// Struct for a sequence of alicia_d_control_interfaces__action__HomeGripper_Result.
typedef struct alicia_d_control_interfaces__action__HomeGripper_Result__Sequence
{
  alicia_d_control_interfaces__action__HomeGripper_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__HomeGripper_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/HomeGripper in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__HomeGripper_Feedback
{
  int32_t raw_position;
  bool moving;
} alicia_d_control_interfaces__action__HomeGripper_Feedback;

// Struct for a sequence of alicia_d_control_interfaces__action__HomeGripper_Feedback.
typedef struct alicia_d_control_interfaces__action__HomeGripper_Feedback__Sequence
{
  alicia_d_control_interfaces__action__HomeGripper_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__HomeGripper_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "alicia_d_control_interfaces/action/detail/home_gripper__struct.h"

/// Struct defined in action/HomeGripper in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  alicia_d_control_interfaces__action__HomeGripper_Goal goal;
} alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request;

// Struct for a sequence of alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request.
typedef struct alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request__Sequence
{
  alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/HomeGripper in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response;

// Struct for a sequence of alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response.
typedef struct alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response__Sequence
{
  alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/HomeGripper in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__HomeGripper_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} alicia_d_control_interfaces__action__HomeGripper_GetResult_Request;

// Struct for a sequence of alicia_d_control_interfaces__action__HomeGripper_GetResult_Request.
typedef struct alicia_d_control_interfaces__action__HomeGripper_GetResult_Request__Sequence
{
  alicia_d_control_interfaces__action__HomeGripper_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__HomeGripper_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "alicia_d_control_interfaces/action/detail/home_gripper__struct.h"

/// Struct defined in action/HomeGripper in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__HomeGripper_GetResult_Response
{
  int8_t status;
  alicia_d_control_interfaces__action__HomeGripper_Result result;
} alicia_d_control_interfaces__action__HomeGripper_GetResult_Response;

// Struct for a sequence of alicia_d_control_interfaces__action__HomeGripper_GetResult_Response.
typedef struct alicia_d_control_interfaces__action__HomeGripper_GetResult_Response__Sequence
{
  alicia_d_control_interfaces__action__HomeGripper_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__HomeGripper_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "alicia_d_control_interfaces/action/detail/home_gripper__struct.h"

/// Struct defined in action/HomeGripper in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  alicia_d_control_interfaces__action__HomeGripper_Feedback feedback;
} alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage;

// Struct for a sequence of alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage.
typedef struct alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage__Sequence
{
  alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__HOME_GRIPPER__STRUCT_H_
