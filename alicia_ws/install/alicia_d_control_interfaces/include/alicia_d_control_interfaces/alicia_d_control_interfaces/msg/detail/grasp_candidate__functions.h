// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from alicia_d_control_interfaces:msg/GraspCandidate.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__FUNCTIONS_H_
#define ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "alicia_d_control_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "alicia_d_control_interfaces/msg/detail/grasp_candidate__struct.h"

/// Initialize msg/GraspCandidate message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * alicia_d_control_interfaces__msg__GraspCandidate
 * )) before or use
 * alicia_d_control_interfaces__msg__GraspCandidate__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__msg__GraspCandidate__init(alicia_d_control_interfaces__msg__GraspCandidate * msg);

/// Finalize msg/GraspCandidate message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__msg__GraspCandidate__fini(alicia_d_control_interfaces__msg__GraspCandidate * msg);

/// Create msg/GraspCandidate message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * alicia_d_control_interfaces__msg__GraspCandidate__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__msg__GraspCandidate *
alicia_d_control_interfaces__msg__GraspCandidate__create();

/// Destroy msg/GraspCandidate message.
/**
 * It calls
 * alicia_d_control_interfaces__msg__GraspCandidate__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__msg__GraspCandidate__destroy(alicia_d_control_interfaces__msg__GraspCandidate * msg);

/// Check for msg/GraspCandidate message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__msg__GraspCandidate__are_equal(const alicia_d_control_interfaces__msg__GraspCandidate * lhs, const alicia_d_control_interfaces__msg__GraspCandidate * rhs);

/// Copy a msg/GraspCandidate message.
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
alicia_d_control_interfaces__msg__GraspCandidate__copy(
  const alicia_d_control_interfaces__msg__GraspCandidate * input,
  alicia_d_control_interfaces__msg__GraspCandidate * output);

/// Initialize array of msg/GraspCandidate messages.
/**
 * It allocates the memory for the number of elements and calls
 * alicia_d_control_interfaces__msg__GraspCandidate__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__msg__GraspCandidate__Sequence__init(alicia_d_control_interfaces__msg__GraspCandidate__Sequence * array, size_t size);

/// Finalize array of msg/GraspCandidate messages.
/**
 * It calls
 * alicia_d_control_interfaces__msg__GraspCandidate__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__msg__GraspCandidate__Sequence__fini(alicia_d_control_interfaces__msg__GraspCandidate__Sequence * array);

/// Create array of msg/GraspCandidate messages.
/**
 * It allocates the memory for the array and calls
 * alicia_d_control_interfaces__msg__GraspCandidate__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
alicia_d_control_interfaces__msg__GraspCandidate__Sequence *
alicia_d_control_interfaces__msg__GraspCandidate__Sequence__create(size_t size);

/// Destroy array of msg/GraspCandidate messages.
/**
 * It calls
 * alicia_d_control_interfaces__msg__GraspCandidate__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
void
alicia_d_control_interfaces__msg__GraspCandidate__Sequence__destroy(alicia_d_control_interfaces__msg__GraspCandidate__Sequence * array);

/// Check for msg/GraspCandidate message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_alicia_d_control_interfaces
bool
alicia_d_control_interfaces__msg__GraspCandidate__Sequence__are_equal(const alicia_d_control_interfaces__msg__GraspCandidate__Sequence * lhs, const alicia_d_control_interfaces__msg__GraspCandidate__Sequence * rhs);

/// Copy an array of msg/GraspCandidate messages.
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
alicia_d_control_interfaces__msg__GraspCandidate__Sequence__copy(
  const alicia_d_control_interfaces__msg__GraspCandidate__Sequence * input,
  alicia_d_control_interfaces__msg__GraspCandidate__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__FUNCTIONS_H_
