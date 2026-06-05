// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from alicia_d_control_interfaces:msg/GraspCandidate.idl
// generated code does not contain a copyright notice
#include "alicia_d_control_interfaces/msg/detail/grasp_candidate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `grasp_pose`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `source`
#include "rosidl_runtime_c/string_functions.h"

bool
alicia_d_control_interfaces__msg__GraspCandidate__init(alicia_d_control_interfaces__msg__GraspCandidate * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    alicia_d_control_interfaces__msg__GraspCandidate__fini(msg);
    return false;
  }
  // grasp_pose
  if (!geometry_msgs__msg__Pose__init(&msg->grasp_pose)) {
    alicia_d_control_interfaces__msg__GraspCandidate__fini(msg);
    return false;
  }
  // grasp_depth_m
  // source
  if (!rosidl_runtime_c__String__init(&msg->source)) {
    alicia_d_control_interfaces__msg__GraspCandidate__fini(msg);
    return false;
  }
  return true;
}

void
alicia_d_control_interfaces__msg__GraspCandidate__fini(alicia_d_control_interfaces__msg__GraspCandidate * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // grasp_pose
  geometry_msgs__msg__Pose__fini(&msg->grasp_pose);
  // grasp_depth_m
  // source
  rosidl_runtime_c__String__fini(&msg->source);
}

bool
alicia_d_control_interfaces__msg__GraspCandidate__are_equal(const alicia_d_control_interfaces__msg__GraspCandidate * lhs, const alicia_d_control_interfaces__msg__GraspCandidate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // grasp_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->grasp_pose), &(rhs->grasp_pose)))
  {
    return false;
  }
  // grasp_depth_m
  if (lhs->grasp_depth_m != rhs->grasp_depth_m) {
    return false;
  }
  // source
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->source), &(rhs->source)))
  {
    return false;
  }
  return true;
}

bool
alicia_d_control_interfaces__msg__GraspCandidate__copy(
  const alicia_d_control_interfaces__msg__GraspCandidate * input,
  alicia_d_control_interfaces__msg__GraspCandidate * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // grasp_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->grasp_pose), &(output->grasp_pose)))
  {
    return false;
  }
  // grasp_depth_m
  output->grasp_depth_m = input->grasp_depth_m;
  // source
  if (!rosidl_runtime_c__String__copy(
      &(input->source), &(output->source)))
  {
    return false;
  }
  return true;
}

alicia_d_control_interfaces__msg__GraspCandidate *
alicia_d_control_interfaces__msg__GraspCandidate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__msg__GraspCandidate * msg = (alicia_d_control_interfaces__msg__GraspCandidate *)allocator.allocate(sizeof(alicia_d_control_interfaces__msg__GraspCandidate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(alicia_d_control_interfaces__msg__GraspCandidate));
  bool success = alicia_d_control_interfaces__msg__GraspCandidate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
alicia_d_control_interfaces__msg__GraspCandidate__destroy(alicia_d_control_interfaces__msg__GraspCandidate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    alicia_d_control_interfaces__msg__GraspCandidate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
alicia_d_control_interfaces__msg__GraspCandidate__Sequence__init(alicia_d_control_interfaces__msg__GraspCandidate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__msg__GraspCandidate * data = NULL;

  if (size) {
    data = (alicia_d_control_interfaces__msg__GraspCandidate *)allocator.zero_allocate(size, sizeof(alicia_d_control_interfaces__msg__GraspCandidate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = alicia_d_control_interfaces__msg__GraspCandidate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        alicia_d_control_interfaces__msg__GraspCandidate__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
alicia_d_control_interfaces__msg__GraspCandidate__Sequence__fini(alicia_d_control_interfaces__msg__GraspCandidate__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      alicia_d_control_interfaces__msg__GraspCandidate__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

alicia_d_control_interfaces__msg__GraspCandidate__Sequence *
alicia_d_control_interfaces__msg__GraspCandidate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__msg__GraspCandidate__Sequence * array = (alicia_d_control_interfaces__msg__GraspCandidate__Sequence *)allocator.allocate(sizeof(alicia_d_control_interfaces__msg__GraspCandidate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = alicia_d_control_interfaces__msg__GraspCandidate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
alicia_d_control_interfaces__msg__GraspCandidate__Sequence__destroy(alicia_d_control_interfaces__msg__GraspCandidate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    alicia_d_control_interfaces__msg__GraspCandidate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
alicia_d_control_interfaces__msg__GraspCandidate__Sequence__are_equal(const alicia_d_control_interfaces__msg__GraspCandidate__Sequence * lhs, const alicia_d_control_interfaces__msg__GraspCandidate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!alicia_d_control_interfaces__msg__GraspCandidate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
alicia_d_control_interfaces__msg__GraspCandidate__Sequence__copy(
  const alicia_d_control_interfaces__msg__GraspCandidate__Sequence * input,
  alicia_d_control_interfaces__msg__GraspCandidate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(alicia_d_control_interfaces__msg__GraspCandidate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    alicia_d_control_interfaces__msg__GraspCandidate * data =
      (alicia_d_control_interfaces__msg__GraspCandidate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!alicia_d_control_interfaces__msg__GraspCandidate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          alicia_d_control_interfaces__msg__GraspCandidate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!alicia_d_control_interfaces__msg__GraspCandidate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
