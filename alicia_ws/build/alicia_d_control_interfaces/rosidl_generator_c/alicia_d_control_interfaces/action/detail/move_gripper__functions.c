// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from alicia_d_control_interfaces:action/MoveGripper.idl
// generated code does not contain a copyright notice
#include "alicia_d_control_interfaces/action/detail/move_gripper__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
alicia_d_control_interfaces__action__MoveGripper_Goal__init(alicia_d_control_interfaces__action__MoveGripper_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // target_ticks
  // speed
  return true;
}

void
alicia_d_control_interfaces__action__MoveGripper_Goal__fini(alicia_d_control_interfaces__action__MoveGripper_Goal * msg)
{
  if (!msg) {
    return;
  }
  // target_ticks
  // speed
}

bool
alicia_d_control_interfaces__action__MoveGripper_Goal__are_equal(const alicia_d_control_interfaces__action__MoveGripper_Goal * lhs, const alicia_d_control_interfaces__action__MoveGripper_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_ticks
  if (lhs->target_ticks != rhs->target_ticks) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_Goal__copy(
  const alicia_d_control_interfaces__action__MoveGripper_Goal * input,
  alicia_d_control_interfaces__action__MoveGripper_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // target_ticks
  output->target_ticks = input->target_ticks;
  // speed
  output->speed = input->speed;
  return true;
}

alicia_d_control_interfaces__action__MoveGripper_Goal *
alicia_d_control_interfaces__action__MoveGripper_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_Goal * msg = (alicia_d_control_interfaces__action__MoveGripper_Goal *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(alicia_d_control_interfaces__action__MoveGripper_Goal));
  bool success = alicia_d_control_interfaces__action__MoveGripper_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
alicia_d_control_interfaces__action__MoveGripper_Goal__destroy(alicia_d_control_interfaces__action__MoveGripper_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    alicia_d_control_interfaces__action__MoveGripper_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__init(alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_Goal * data = NULL;

  if (size) {
    data = (alicia_d_control_interfaces__action__MoveGripper_Goal *)allocator.zero_allocate(size, sizeof(alicia_d_control_interfaces__action__MoveGripper_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = alicia_d_control_interfaces__action__MoveGripper_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        alicia_d_control_interfaces__action__MoveGripper_Goal__fini(&data[i - 1]);
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
alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__fini(alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence * array)
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
      alicia_d_control_interfaces__action__MoveGripper_Goal__fini(&array->data[i]);
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

alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence *
alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence * array = (alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__destroy(alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence * lhs, const alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence * input,
  alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(alicia_d_control_interfaces__action__MoveGripper_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    alicia_d_control_interfaces__action__MoveGripper_Goal * data =
      (alicia_d_control_interfaces__action__MoveGripper_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!alicia_d_control_interfaces__action__MoveGripper_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          alicia_d_control_interfaces__action__MoveGripper_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
alicia_d_control_interfaces__action__MoveGripper_Result__init(alicia_d_control_interfaces__action__MoveGripper_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    alicia_d_control_interfaces__action__MoveGripper_Result__fini(msg);
    return false;
  }
  // raw_position
  // relative_ticks
  return true;
}

void
alicia_d_control_interfaces__action__MoveGripper_Result__fini(alicia_d_control_interfaces__action__MoveGripper_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // raw_position
  // relative_ticks
}

bool
alicia_d_control_interfaces__action__MoveGripper_Result__are_equal(const alicia_d_control_interfaces__action__MoveGripper_Result * lhs, const alicia_d_control_interfaces__action__MoveGripper_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
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
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_Result__copy(
  const alicia_d_control_interfaces__action__MoveGripper_Result * input,
  alicia_d_control_interfaces__action__MoveGripper_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // raw_position
  output->raw_position = input->raw_position;
  // relative_ticks
  output->relative_ticks = input->relative_ticks;
  return true;
}

alicia_d_control_interfaces__action__MoveGripper_Result *
alicia_d_control_interfaces__action__MoveGripper_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_Result * msg = (alicia_d_control_interfaces__action__MoveGripper_Result *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(alicia_d_control_interfaces__action__MoveGripper_Result));
  bool success = alicia_d_control_interfaces__action__MoveGripper_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
alicia_d_control_interfaces__action__MoveGripper_Result__destroy(alicia_d_control_interfaces__action__MoveGripper_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    alicia_d_control_interfaces__action__MoveGripper_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__init(alicia_d_control_interfaces__action__MoveGripper_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_Result * data = NULL;

  if (size) {
    data = (alicia_d_control_interfaces__action__MoveGripper_Result *)allocator.zero_allocate(size, sizeof(alicia_d_control_interfaces__action__MoveGripper_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = alicia_d_control_interfaces__action__MoveGripper_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        alicia_d_control_interfaces__action__MoveGripper_Result__fini(&data[i - 1]);
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
alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__fini(alicia_d_control_interfaces__action__MoveGripper_Result__Sequence * array)
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
      alicia_d_control_interfaces__action__MoveGripper_Result__fini(&array->data[i]);
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

alicia_d_control_interfaces__action__MoveGripper_Result__Sequence *
alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_Result__Sequence * array = (alicia_d_control_interfaces__action__MoveGripper_Result__Sequence *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__destroy(alicia_d_control_interfaces__action__MoveGripper_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveGripper_Result__Sequence * lhs, const alicia_d_control_interfaces__action__MoveGripper_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveGripper_Result__Sequence * input,
  alicia_d_control_interfaces__action__MoveGripper_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(alicia_d_control_interfaces__action__MoveGripper_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    alicia_d_control_interfaces__action__MoveGripper_Result * data =
      (alicia_d_control_interfaces__action__MoveGripper_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!alicia_d_control_interfaces__action__MoveGripper_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          alicia_d_control_interfaces__action__MoveGripper_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
alicia_d_control_interfaces__action__MoveGripper_Feedback__init(alicia_d_control_interfaces__action__MoveGripper_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // raw_position
  // relative_ticks
  // moving
  return true;
}

void
alicia_d_control_interfaces__action__MoveGripper_Feedback__fini(alicia_d_control_interfaces__action__MoveGripper_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // raw_position
  // relative_ticks
  // moving
}

bool
alicia_d_control_interfaces__action__MoveGripper_Feedback__are_equal(const alicia_d_control_interfaces__action__MoveGripper_Feedback * lhs, const alicia_d_control_interfaces__action__MoveGripper_Feedback * rhs)
{
  if (!lhs || !rhs) {
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
  // moving
  if (lhs->moving != rhs->moving) {
    return false;
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_Feedback__copy(
  const alicia_d_control_interfaces__action__MoveGripper_Feedback * input,
  alicia_d_control_interfaces__action__MoveGripper_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // raw_position
  output->raw_position = input->raw_position;
  // relative_ticks
  output->relative_ticks = input->relative_ticks;
  // moving
  output->moving = input->moving;
  return true;
}

alicia_d_control_interfaces__action__MoveGripper_Feedback *
alicia_d_control_interfaces__action__MoveGripper_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_Feedback * msg = (alicia_d_control_interfaces__action__MoveGripper_Feedback *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(alicia_d_control_interfaces__action__MoveGripper_Feedback));
  bool success = alicia_d_control_interfaces__action__MoveGripper_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
alicia_d_control_interfaces__action__MoveGripper_Feedback__destroy(alicia_d_control_interfaces__action__MoveGripper_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    alicia_d_control_interfaces__action__MoveGripper_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__init(alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_Feedback * data = NULL;

  if (size) {
    data = (alicia_d_control_interfaces__action__MoveGripper_Feedback *)allocator.zero_allocate(size, sizeof(alicia_d_control_interfaces__action__MoveGripper_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = alicia_d_control_interfaces__action__MoveGripper_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        alicia_d_control_interfaces__action__MoveGripper_Feedback__fini(&data[i - 1]);
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
alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__fini(alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence * array)
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
      alicia_d_control_interfaces__action__MoveGripper_Feedback__fini(&array->data[i]);
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

alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence *
alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence * array = (alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__destroy(alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence * lhs, const alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence * input,
  alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(alicia_d_control_interfaces__action__MoveGripper_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    alicia_d_control_interfaces__action__MoveGripper_Feedback * data =
      (alicia_d_control_interfaces__action__MoveGripper_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!alicia_d_control_interfaces__action__MoveGripper_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          alicia_d_control_interfaces__action__MoveGripper_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_gripper__functions.h"

bool
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__init(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!alicia_d_control_interfaces__action__MoveGripper_Goal__init(&msg->goal)) {
    alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__fini(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  alicia_d_control_interfaces__action__MoveGripper_Goal__fini(&msg->goal);
}

bool
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__are_equal(const alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request * lhs, const alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!alicia_d_control_interfaces__action__MoveGripper_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__copy(
  const alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request * input,
  alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!alicia_d_control_interfaces__action__MoveGripper_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request *
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request * msg = (alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request));
  bool success = alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__destroy(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__init(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request * data = NULL;

  if (size) {
    data = (alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request *)allocator.zero_allocate(size, sizeof(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__fini(&data[i - 1]);
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
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__fini(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence * array)
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
      alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__fini(&array->data[i]);
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

alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence *
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence * array = (alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__destroy(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence * lhs, const alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence * input,
  alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request * data =
      (alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__init(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__fini(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__are_equal(const alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response * lhs, const alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__copy(
  const alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response * input,
  alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response *
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response * msg = (alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response));
  bool success = alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__destroy(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__init(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response * data = NULL;

  if (size) {
    data = (alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response *)allocator.zero_allocate(size, sizeof(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__fini(&data[i - 1]);
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
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__fini(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence * array)
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
      alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__fini(&array->data[i]);
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

alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence *
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence * array = (alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__destroy(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence * lhs, const alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence * input,
  alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response * data =
      (alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__init(alicia_d_control_interfaces__action__MoveGripper_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__fini(alicia_d_control_interfaces__action__MoveGripper_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__are_equal(const alicia_d_control_interfaces__action__MoveGripper_GetResult_Request * lhs, const alicia_d_control_interfaces__action__MoveGripper_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__copy(
  const alicia_d_control_interfaces__action__MoveGripper_GetResult_Request * input,
  alicia_d_control_interfaces__action__MoveGripper_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

alicia_d_control_interfaces__action__MoveGripper_GetResult_Request *
alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_GetResult_Request * msg = (alicia_d_control_interfaces__action__MoveGripper_GetResult_Request *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(alicia_d_control_interfaces__action__MoveGripper_GetResult_Request));
  bool success = alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__destroy(alicia_d_control_interfaces__action__MoveGripper_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__init(alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_GetResult_Request * data = NULL;

  if (size) {
    data = (alicia_d_control_interfaces__action__MoveGripper_GetResult_Request *)allocator.zero_allocate(size, sizeof(alicia_d_control_interfaces__action__MoveGripper_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__fini(&data[i - 1]);
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
alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__fini(alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence * array)
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
      alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__fini(&array->data[i]);
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

alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence *
alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence * array = (alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__destroy(alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence * lhs, const alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence * input,
  alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(alicia_d_control_interfaces__action__MoveGripper_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    alicia_d_control_interfaces__action__MoveGripper_GetResult_Request * data =
      (alicia_d_control_interfaces__action__MoveGripper_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_gripper__functions.h"

bool
alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__init(alicia_d_control_interfaces__action__MoveGripper_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!alicia_d_control_interfaces__action__MoveGripper_Result__init(&msg->result)) {
    alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__fini(alicia_d_control_interfaces__action__MoveGripper_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  alicia_d_control_interfaces__action__MoveGripper_Result__fini(&msg->result);
}

bool
alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__are_equal(const alicia_d_control_interfaces__action__MoveGripper_GetResult_Response * lhs, const alicia_d_control_interfaces__action__MoveGripper_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!alicia_d_control_interfaces__action__MoveGripper_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__copy(
  const alicia_d_control_interfaces__action__MoveGripper_GetResult_Response * input,
  alicia_d_control_interfaces__action__MoveGripper_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!alicia_d_control_interfaces__action__MoveGripper_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

alicia_d_control_interfaces__action__MoveGripper_GetResult_Response *
alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_GetResult_Response * msg = (alicia_d_control_interfaces__action__MoveGripper_GetResult_Response *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(alicia_d_control_interfaces__action__MoveGripper_GetResult_Response));
  bool success = alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__destroy(alicia_d_control_interfaces__action__MoveGripper_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__init(alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_GetResult_Response * data = NULL;

  if (size) {
    data = (alicia_d_control_interfaces__action__MoveGripper_GetResult_Response *)allocator.zero_allocate(size, sizeof(alicia_d_control_interfaces__action__MoveGripper_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__fini(&data[i - 1]);
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
alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__fini(alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence * array)
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
      alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__fini(&array->data[i]);
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

alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence *
alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence * array = (alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__destroy(alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence * lhs, const alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence * input,
  alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(alicia_d_control_interfaces__action__MoveGripper_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    alicia_d_control_interfaces__action__MoveGripper_GetResult_Response * data =
      (alicia_d_control_interfaces__action__MoveGripper_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_gripper__functions.h"

bool
alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__init(alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!alicia_d_control_interfaces__action__MoveGripper_Feedback__init(&msg->feedback)) {
    alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__fini(alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  alicia_d_control_interfaces__action__MoveGripper_Feedback__fini(&msg->feedback);
}

bool
alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__are_equal(const alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage * lhs, const alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!alicia_d_control_interfaces__action__MoveGripper_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__copy(
  const alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage * input,
  alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!alicia_d_control_interfaces__action__MoveGripper_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage *
alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage * msg = (alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage));
  bool success = alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__destroy(alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__init(alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage * data = NULL;

  if (size) {
    data = (alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage *)allocator.zero_allocate(size, sizeof(alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__fini(&data[i - 1]);
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
alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__fini(alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence * array)
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
      alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__fini(&array->data[i]);
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

alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence *
alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence * array = (alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence *)allocator.allocate(sizeof(alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__destroy(alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__are_equal(const alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence * lhs, const alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__copy(
  const alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence * input,
  alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage * data =
      (alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
