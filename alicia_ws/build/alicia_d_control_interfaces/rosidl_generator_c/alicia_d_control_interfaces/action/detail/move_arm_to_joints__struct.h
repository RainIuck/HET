// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from alicia_d_control_interfaces:action/MoveArmToJoints.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_ARM_TO_JOINTS__STRUCT_H_
#define ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_ARM_TO_JOINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint_names'
#include "rosidl_runtime_c/string.h"
// Member 'joint_positions'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/MoveArmToJoints in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_Goal
{
  rosidl_runtime_c__String__Sequence joint_names;
  rosidl_runtime_c__double__Sequence joint_positions;
  double max_velocity_scaling;
  double max_acceleration_scaling;
  bool execute;
} alicia_d_control_interfaces__action__MoveArmToJoints_Goal;

// Struct for a sequence of alicia_d_control_interfaces__action__MoveArmToJoints_Goal.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence
{
  alicia_d_control_interfaces__action__MoveArmToJoints_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/MoveArmToJoints in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_Result
{
  bool success;
  int32_t moveit_error_code;
  rosidl_runtime_c__String message;
} alicia_d_control_interfaces__action__MoveArmToJoints_Result;

// Struct for a sequence of alicia_d_control_interfaces__action__MoveArmToJoints_Result.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence
{
  alicia_d_control_interfaces__action__MoveArmToJoints_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stage'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/MoveArmToJoints in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_Feedback
{
  rosidl_runtime_c__String stage;
} alicia_d_control_interfaces__action__MoveArmToJoints_Feedback;

// Struct for a sequence of alicia_d_control_interfaces__action__MoveArmToJoints_Feedback.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence
{
  alicia_d_control_interfaces__action__MoveArmToJoints_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.h"

/// Struct defined in action/MoveArmToJoints in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  alicia_d_control_interfaces__action__MoveArmToJoints_Goal goal;
} alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request;

// Struct for a sequence of alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence
{
  alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/MoveArmToJoints in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response;

// Struct for a sequence of alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence
{
  alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/MoveArmToJoints in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request;

// Struct for a sequence of alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence
{
  alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.h"

/// Struct defined in action/MoveArmToJoints in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response
{
  int8_t status;
  alicia_d_control_interfaces__action__MoveArmToJoints_Result result;
} alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response;

// Struct for a sequence of alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence
{
  alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.h"

/// Struct defined in action/MoveArmToJoints in the package alicia_d_control_interfaces.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  alicia_d_control_interfaces__action__MoveArmToJoints_Feedback feedback;
} alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage;

// Struct for a sequence of alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage.
typedef struct alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence
{
  alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_ARM_TO_JOINTS__STRUCT_H_
