// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from alicia_d_control_interfaces:msg/GripperState.idl
// generated code does not contain a copyright notice
#include "alicia_d_control_interfaces/msg/detail/gripper_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `fault`
#include "rosidl_runtime_c/string_functions.h"

bool
alicia_d_control_interfaces__msg__GripperState__init(alicia_d_control_interfaces__msg__GripperState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    alicia_d_control_interfaces__msg__GripperState__fini(msg);
    return false;
  }
  // connected
  // homed
  // raw_position
  // relative_ticks
  // target_position
  // position_error_direction
  // position_error_ticks
  // estimated_position_minus
  // estimated_position_plus
  // load_raw
  // current_raw
  // moving
  // voltage_v
  // temperature_c
  // fault
  if (!rosidl_runtime_c__String__init(&msg->fault)) {
    alicia_d_control_interfaces__msg__GripperState__fini(msg);
    return false;
  }
  return true;
}

void
alicia_d_control_interfaces__msg__GripperState__fini(alicia_d_control_interfaces__msg__GripperState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // connected
  // homed
  // raw_position
  // relative_ticks
  // target_position
  // position_error_direction
  // position_error_ticks
  // estimated_position_minus
  // estimated_position_plus
  // load_raw
  // current_raw
  // moving
  // voltage_v
  // temperature_c
  // fault
  rosidl_runtime_c__String__fini(&msg->fault);
}

bool
alicia_d_control_interfaces__msg__GripperState__are_equal(const alicia_d_control_interfaces__msg__GripperState * lhs, const alicia_d_control_interfaces__msg__GripperState * rhs)
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
  // connected
  if (lhs->connected != rhs->connected) {
    return false;
  }
  // homed
  if (lhs->homed != rhs->homed) {
    return false;
  }
  // raw_position
  if (lhs->raw_position != rhs->raw_position) {
    return false;
  }
  // relative_ticks
  if (lhs->relative_ticks != rhs->relative_ticks) {
    return false;
  }
  // target_position
  if (lhs->target_position != rhs->target_position) {
    return false;
  }
  // position_error_direction
  if (lhs->position_error_direction != rhs->position_error_direction) {
    return false;
  }
  // position_error_ticks
  if (lhs->position_error_ticks != rhs->position_error_ticks) {
    return false;
  }
  // estimated_position_minus
  if (lhs->estimated_position_minus != rhs->estimated_position_minus) {
    return false;
  }
  // estimated_position_plus
  if (lhs->estimated_position_plus != rhs->estimated_position_plus) {
    return false;
  }
  // load_raw
  if (lhs->load_raw != rhs->load_raw) {
    return false;
  }
  // current_raw
  if (lhs->current_raw != rhs->current_raw) {
    return false;
  }
  // moving
  if (lhs->moving != rhs->moving) {
    return false;
  }
  // voltage_v
  if (lhs->voltage_v != rhs->voltage_v) {
    return false;
  }
  // temperature_c
  if (lhs->temperature_c != rhs->temperature_c) {
    return false;
  }
  // fault
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->fault), &(rhs->fault)))
  {
    return false;
  }
  return true;
}

bool
alicia_d_control_interfaces__msg__GripperState__copy(
  const alicia_d_control_interfaces__msg__GripperState * input,
  alicia_d_control_interfaces__msg__GripperState * output)
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
  // connected
  output->connected = input->connected;
  // homed
  output->homed = input->homed;
  // raw_position
  output->raw_position = input->raw_position;
  // relative_ticks
  output->relative_ticks = input->relative_ticks;
  // target_position
  output->target_position = input->target_position;
  // position_error_direction
  output->position_error_direction = input->position_error_direction;
  // position_error_ticks
  output->position_error_ticks = input->position_error_ticks;
  // estimated_position_minus
  output->estimated_position_minus = input->estimated_position_minus;
  // estimated_position_plus
  output->estimated_position_plus = input->estimated_position_plus;
  // load_raw
  output->load_raw = input->load_raw;
  // current_raw
  output->current_raw = input->current_raw;
  // moving
  output->moving = input->moving;
  // voltage_v
  output->voltage_v = input->voltage_v;
  // temperature_c
  output->temperature_c = input->temperature_c;
  // fault
  if (!rosidl_runtime_c__String__copy(
      &(input->fault), &(output->fault)))
  {
    return false;
  }
  return true;
}

alicia_d_control_interfaces__msg__GripperState *
alicia_d_control_interfaces__msg__GripperState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__msg__GripperState * msg = (alicia_d_control_interfaces__msg__GripperState *)allocator.allocate(sizeof(alicia_d_control_interfaces__msg__GripperState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(alicia_d_control_interfaces__msg__GripperState));
  bool success = alicia_d_control_interfaces__msg__GripperState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
alicia_d_control_interfaces__msg__GripperState__destroy(alicia_d_control_interfaces__msg__GripperState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    alicia_d_control_interfaces__msg__GripperState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
alicia_d_control_interfaces__msg__GripperState__Sequence__init(alicia_d_control_interfaces__msg__GripperState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__msg__GripperState * data = NULL;

  if (size) {
    data = (alicia_d_control_interfaces__msg__GripperState *)allocator.zero_allocate(size, sizeof(alicia_d_control_interfaces__msg__GripperState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = alicia_d_control_interfaces__msg__GripperState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        alicia_d_control_interfaces__msg__GripperState__fini(&data[i - 1]);
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
alicia_d_control_interfaces__msg__GripperState__Sequence__fini(alicia_d_control_interfaces__msg__GripperState__Sequence * array)
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
      alicia_d_control_interfaces__msg__GripperState__fini(&array->data[i]);
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

alicia_d_control_interfaces__msg__GripperState__Sequence *
alicia_d_control_interfaces__msg__GripperState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__msg__GripperState__Sequence * array = (alicia_d_control_interfaces__msg__GripperState__Sequence *)allocator.allocate(sizeof(alicia_d_control_interfaces__msg__GripperState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = alicia_d_control_interfaces__msg__GripperState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
alicia_d_control_interfaces__msg__GripperState__Sequence__destroy(alicia_d_control_interfaces__msg__GripperState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    alicia_d_control_interfaces__msg__GripperState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
alicia_d_control_interfaces__msg__GripperState__Sequence__are_equal(const alicia_d_control_interfaces__msg__GripperState__Sequence * lhs, const alicia_d_control_interfaces__msg__GripperState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!alicia_d_control_interfaces__msg__GripperState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
alicia_d_control_interfaces__msg__GripperState__Sequence__copy(
  const alicia_d_control_interfaces__msg__GripperState__Sequence * input,
  alicia_d_control_interfaces__msg__GripperState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(alicia_d_control_interfaces__msg__GripperState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    alicia_d_control_interfaces__msg__GripperState * data =
      (alicia_d_control_interfaces__msg__GripperState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!alicia_d_control_interfaces__msg__GripperState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          alicia_d_control_interfaces__msg__GripperState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!alicia_d_control_interfaces__msg__GripperState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
