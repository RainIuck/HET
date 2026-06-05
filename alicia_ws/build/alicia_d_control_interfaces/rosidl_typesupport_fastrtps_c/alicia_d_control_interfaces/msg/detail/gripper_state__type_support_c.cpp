// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from alicia_d_control_interfaces:msg/GripperState.idl
// generated code does not contain a copyright notice
#include "alicia_d_control_interfaces/msg/detail/gripper_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "alicia_d_control_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "alicia_d_control_interfaces/msg/detail/gripper_state__struct.h"
#include "alicia_d_control_interfaces/msg/detail/gripper_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // fault
#include "rosidl_runtime_c/string_functions.h"  // fault
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_alicia_d_control_interfaces
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_alicia_d_control_interfaces
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_alicia_d_control_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _GripperState__ros_msg_type = alicia_d_control_interfaces__msg__GripperState;

static bool _GripperState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GripperState__ros_msg_type * ros_message = static_cast<const _GripperState__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: connected
  {
    cdr << (ros_message->connected ? true : false);
  }

  // Field name: homed
  {
    cdr << (ros_message->homed ? true : false);
  }

  // Field name: raw_position
  {
    cdr << ros_message->raw_position;
  }

  // Field name: relative_ticks
  {
    cdr << ros_message->relative_ticks;
  }

  // Field name: target_position
  {
    cdr << ros_message->target_position;
  }

  // Field name: position_error_direction
  {
    cdr << (ros_message->position_error_direction ? true : false);
  }

  // Field name: position_error_ticks
  {
    cdr << ros_message->position_error_ticks;
  }

  // Field name: estimated_position_minus
  {
    cdr << ros_message->estimated_position_minus;
  }

  // Field name: estimated_position_plus
  {
    cdr << ros_message->estimated_position_plus;
  }

  // Field name: load_raw
  {
    cdr << ros_message->load_raw;
  }

  // Field name: current_raw
  {
    cdr << ros_message->current_raw;
  }

  // Field name: moving
  {
    cdr << (ros_message->moving ? true : false);
  }

  // Field name: voltage_v
  {
    cdr << ros_message->voltage_v;
  }

  // Field name: temperature_c
  {
    cdr << ros_message->temperature_c;
  }

  // Field name: fault
  {
    const rosidl_runtime_c__String * str = &ros_message->fault;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _GripperState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GripperState__ros_msg_type * ros_message = static_cast<_GripperState__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: connected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->connected = tmp ? true : false;
  }

  // Field name: homed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->homed = tmp ? true : false;
  }

  // Field name: raw_position
  {
    cdr >> ros_message->raw_position;
  }

  // Field name: relative_ticks
  {
    cdr >> ros_message->relative_ticks;
  }

  // Field name: target_position
  {
    cdr >> ros_message->target_position;
  }

  // Field name: position_error_direction
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->position_error_direction = tmp ? true : false;
  }

  // Field name: position_error_ticks
  {
    cdr >> ros_message->position_error_ticks;
  }

  // Field name: estimated_position_minus
  {
    cdr >> ros_message->estimated_position_minus;
  }

  // Field name: estimated_position_plus
  {
    cdr >> ros_message->estimated_position_plus;
  }

  // Field name: load_raw
  {
    cdr >> ros_message->load_raw;
  }

  // Field name: current_raw
  {
    cdr >> ros_message->current_raw;
  }

  // Field name: moving
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->moving = tmp ? true : false;
  }

  // Field name: voltage_v
  {
    cdr >> ros_message->voltage_v;
  }

  // Field name: temperature_c
  {
    cdr >> ros_message->temperature_c;
  }

  // Field name: fault
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->fault.data) {
      rosidl_runtime_c__String__init(&ros_message->fault);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->fault,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'fault'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_alicia_d_control_interfaces
size_t get_serialized_size_alicia_d_control_interfaces__msg__GripperState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GripperState__ros_msg_type * ros_message = static_cast<const _GripperState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name connected
  {
    size_t item_size = sizeof(ros_message->connected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name homed
  {
    size_t item_size = sizeof(ros_message->homed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name raw_position
  {
    size_t item_size = sizeof(ros_message->raw_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name relative_ticks
  {
    size_t item_size = sizeof(ros_message->relative_ticks);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_position
  {
    size_t item_size = sizeof(ros_message->target_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name position_error_direction
  {
    size_t item_size = sizeof(ros_message->position_error_direction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name position_error_ticks
  {
    size_t item_size = sizeof(ros_message->position_error_ticks);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name estimated_position_minus
  {
    size_t item_size = sizeof(ros_message->estimated_position_minus);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name estimated_position_plus
  {
    size_t item_size = sizeof(ros_message->estimated_position_plus);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name load_raw
  {
    size_t item_size = sizeof(ros_message->load_raw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_raw
  {
    size_t item_size = sizeof(ros_message->current_raw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name moving
  {
    size_t item_size = sizeof(ros_message->moving);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name voltage_v
  {
    size_t item_size = sizeof(ros_message->voltage_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temperature_c
  {
    size_t item_size = sizeof(ros_message->temperature_c);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fault
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->fault.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _GripperState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_alicia_d_control_interfaces__msg__GripperState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_alicia_d_control_interfaces
size_t max_serialized_size_alicia_d_control_interfaces__msg__GripperState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: connected
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: homed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: raw_position
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: relative_ticks
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: target_position
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: position_error_direction
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: position_error_ticks
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: estimated_position_minus
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: estimated_position_plus
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: load_raw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current_raw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: moving
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: voltage_v
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: temperature_c
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: fault
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = alicia_d_control_interfaces__msg__GripperState;
    is_plain =
      (
      offsetof(DataType, fault) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _GripperState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_alicia_d_control_interfaces__msg__GripperState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GripperState = {
  "alicia_d_control_interfaces::msg",
  "GripperState",
  _GripperState__cdr_serialize,
  _GripperState__cdr_deserialize,
  _GripperState__get_serialized_size,
  _GripperState__max_serialized_size
};

static rosidl_message_type_support_t _GripperState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GripperState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, alicia_d_control_interfaces, msg, GripperState)() {
  return &_GripperState__type_support;
}

#if defined(__cplusplus)
}
#endif
