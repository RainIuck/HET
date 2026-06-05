// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from alicia_d_control_interfaces:action/MoveArmToJoints.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_ARM_TO_JOINTS__FUNCTIONS_H_
#define ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_ARM_TO_JOINTS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "alicia_d_control_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.h"

/// Initialize action/MoveArmToJoints message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * alicia_d_control_interfaces__action__MoveArmToJoints_Goal
 * )) before or use
 * alicia_d_control_interfaces__action__MoveArmToJoints_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__init(alicia_d_control_interfaces__action__MoveArmToJoints_Goal * msg);

/// Finalize action/MoveArmToJoints message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__fini(alicia_d_control_interfaces__action__MoveArmToJoints_Goal * msg);

/// Create action/MoveArmToJoints message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_Goal *
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__create();

/// Destroy action/MoveArmToJoints message.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_Goal * msg);

/// Check for action/MoveArmToJoints message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_Goal * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_Goal * rhs);

/// Copy a action/MoveArmToJoints message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_Goal * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_Goal * output);

/// Initialize array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the number of elements and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__init(alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence * array, size_t size);

/// Finalize array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__fini(alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence * array);

/// Create array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the array and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence *
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__create(size_t size);

/// Destroy array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence * array);

/// Check for action/MoveArmToJoints message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence * rhs);

/// Copy an array of action/MoveArmToJoints messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence * output);

/// Initialize action/MoveArmToJoints message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * alicia_d_control_interfaces__action__MoveArmToJoints_Result
 * )) before or use
 * alicia_d_control_interfaces__action__MoveArmToJoints_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Result__init(alicia_d_control_interfaces__action__MoveArmToJoints_Result * msg);

/// Finalize action/MoveArmToJoints message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_Result__fini(alicia_d_control_interfaces__action__MoveArmToJoints_Result * msg);

/// Create action/MoveArmToJoints message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_Result *
alicia_d_control_interfaces__action__MoveArmToJoints_Result__create();

/// Destroy action/MoveArmToJoints message.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_Result__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_Result * msg);

/// Check for action/MoveArmToJoints message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Result__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_Result * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_Result * rhs);

/// Copy a action/MoveArmToJoints message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Result__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_Result * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_Result * output);

/// Initialize array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the number of elements and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__init(alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence * array, size_t size);

/// Finalize array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__fini(alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence * array);

/// Create array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the array and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence *
alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__create(size_t size);

/// Destroy array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence * array);

/// Check for action/MoveArmToJoints message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence * rhs);

/// Copy an array of action/MoveArmToJoints messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence * output);

/// Initialize action/MoveArmToJoints message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * alicia_d_control_interfaces__action__MoveArmToJoints_Feedback
 * )) before or use
 * alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__init(alicia_d_control_interfaces__action__MoveArmToJoints_Feedback * msg);

/// Finalize action/MoveArmToJoints message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__fini(alicia_d_control_interfaces__action__MoveArmToJoints_Feedback * msg);

/// Create action/MoveArmToJoints message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback *
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__create();

/// Destroy action/MoveArmToJoints message.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_Feedback * msg);

/// Check for action/MoveArmToJoints message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_Feedback * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_Feedback * rhs);

/// Copy a action/MoveArmToJoints message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_Feedback * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_Feedback * output);

/// Initialize array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the number of elements and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__init(alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence * array, size_t size);

/// Finalize array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__fini(alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence * array);

/// Create array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the array and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence *
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__create(size_t size);

/// Destroy array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence * array);

/// Check for action/MoveArmToJoints message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence * rhs);

/// Copy an array of action/MoveArmToJoints messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence * output);

/// Initialize action/MoveArmToJoints message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request
 * )) before or use
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__init(alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request * msg);

/// Finalize action/MoveArmToJoints message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__fini(alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request * msg);

/// Create action/MoveArmToJoints message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request *
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__create();

/// Destroy action/MoveArmToJoints message.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request * msg);

/// Check for action/MoveArmToJoints message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request * rhs);

/// Copy a action/MoveArmToJoints message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request * output);

/// Initialize array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the number of elements and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__init(alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__fini(alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence * array);

/// Create array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the array and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence *
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence * array);

/// Check for action/MoveArmToJoints message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/MoveArmToJoints messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence * output);

/// Initialize action/MoveArmToJoints message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response
 * )) before or use
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__init(alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response * msg);

/// Finalize action/MoveArmToJoints message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__fini(alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response * msg);

/// Create action/MoveArmToJoints message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response *
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__create();

/// Destroy action/MoveArmToJoints message.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response * msg);

/// Check for action/MoveArmToJoints message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response * rhs);

/// Copy a action/MoveArmToJoints message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response * output);

/// Initialize array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the number of elements and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__init(alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__fini(alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence * array);

/// Create array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the array and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence *
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence * array);

/// Check for action/MoveArmToJoints message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/MoveArmToJoints messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence * output);

/// Initialize action/MoveArmToJoints message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request
 * )) before or use
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__init(alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request * msg);

/// Finalize action/MoveArmToJoints message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__fini(alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request * msg);

/// Create action/MoveArmToJoints message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request *
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__create();

/// Destroy action/MoveArmToJoints message.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request * msg);

/// Check for action/MoveArmToJoints message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request * rhs);

/// Copy a action/MoveArmToJoints message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request * output);

/// Initialize array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the number of elements and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__init(alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__fini(alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence * array);

/// Create array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the array and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence *
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence * array);

/// Check for action/MoveArmToJoints message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence * rhs);

/// Copy an array of action/MoveArmToJoints messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence * output);

/// Initialize action/MoveArmToJoints message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response
 * )) before or use
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__init(alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response * msg);

/// Finalize action/MoveArmToJoints message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__fini(alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response * msg);

/// Create action/MoveArmToJoints message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response *
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__create();

/// Destroy action/MoveArmToJoints message.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response * msg);

/// Check for action/MoveArmToJoints message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response * rhs);

/// Copy a action/MoveArmToJoints message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response * output);

/// Initialize array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the number of elements and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__init(alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__fini(alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence * array);

/// Create array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the array and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence *
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence * array);

/// Check for action/MoveArmToJoints message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence * rhs);

/// Copy an array of action/MoveArmToJoints messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence * output);

/// Initialize action/MoveArmToJoints message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage
 * )) before or use
 * alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__init(alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage * msg);

/// Finalize action/MoveArmToJoints message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__fini(alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage * msg);

/// Create action/MoveArmToJoints message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage *
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__create();

/// Destroy action/MoveArmToJoints message.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage * msg);

/// Check for action/MoveArmToJoints message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage * rhs);

/// Copy a action/MoveArmToJoints message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage * output);

/// Initialize array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the number of elements and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__init(alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__fini(alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence * array);

/// Create array of action/MoveArmToJoints messages.
/**
 * It allocates the memory for the array and calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence *
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/MoveArmToJoints messages.
/**
 * It calls
 * alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__destroy(alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence * array);

/// Check for action/MoveArmToJoints message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence * lhs, const alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/MoveArmToJoints messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence * input,
  alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_ARM_TO_JOINTS__FUNCTIONS_H_
