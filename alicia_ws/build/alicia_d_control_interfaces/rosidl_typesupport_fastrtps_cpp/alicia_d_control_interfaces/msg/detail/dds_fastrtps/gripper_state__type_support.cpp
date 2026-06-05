// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from alicia_d_control_interfaces:msg/GripperState.idl
// generated code does not contain a copyright notice
#include "alicia_d_control_interfaces/msg/detail/gripper_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "alicia_d_control_interfaces/msg/detail/gripper_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace alicia_d_control_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_alicia_d_control_interfaces
cdr_serialize(
  const alicia_d_control_interfaces::msg::GripperState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: connected
  cdr << (ros_message.connected ? true : false);
  // Member: homed
  cdr << (ros_message.homed ? true : false);
  // Member: raw_position
  cdr << ros_message.raw_position;
  // Member: relative_ticks
  cdr << ros_message.relative_ticks;
  // Member: target_position
  cdr << ros_message.target_position;
  // Member: position_error_direction
  cdr << (ros_message.position_error_direction ? true : false);
  // Member: position_error_ticks
  cdr << ros_message.position_error_ticks;
  // Member: estimated_position_minus
  cdr << ros_message.estimated_position_minus;
  // Member: estimated_position_plus
  cdr << ros_message.estimated_position_plus;
  // Member: load_raw
  cdr << ros_message.load_raw;
  // Member: current_raw
  cdr << ros_message.current_raw;
  // Member: moving
  cdr << (ros_message.moving ? true : false);
  // Member: voltage_v
  cdr << ros_message.voltage_v;
  // Member: temperature_c
  cdr << ros_message.temperature_c;
  // Member: fault
  cdr << ros_message.fault;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_alicia_d_control_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  alicia_d_control_interfaces::msg::GripperState & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: connected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.connected = tmp ? true : false;
  }

  // Member: homed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.homed = tmp ? true : false;
  }

  // Member: raw_position
  cdr >> ros_message.raw_position;

  // Member: relative_ticks
  cdr >> ros_message.relative_ticks;

  // Member: target_position
  cdr >> ros_message.target_position;

  // Member: position_error_direction
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.position_error_direction = tmp ? true : false;
  }

  // Member: position_error_ticks
  cdr >> ros_message.position_error_ticks;

  // Member: estimated_position_minus
  cdr >> ros_message.estimated_position_minus;

  // Member: estimated_position_plus
  cdr >> ros_message.estimated_position_plus;

  // Member: load_raw
  cdr >> ros_message.load_raw;

  // Member: current_raw
  cdr >> ros_message.current_raw;

  // Member: moving
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.moving = tmp ? true : false;
  }

  // Member: voltage_v
  cdr >> ros_message.voltage_v;

  // Member: temperature_c
  cdr >> ros_message.temperature_c;

  // Member: fault
  cdr >> ros_message.fault;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_alicia_d_control_interfaces
get_serialized_size(
  const alicia_d_control_interfaces::msg::GripperState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: connected
  {
    size_t item_size = sizeof(ros_message.connected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: homed
  {
    size_t item_size = sizeof(ros_message.homed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: raw_position
  {
    size_t item_size = sizeof(ros_message.raw_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: relative_ticks
  {
    size_t item_size = sizeof(ros_message.relative_ticks);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: target_position
  {
    size_t item_size = sizeof(ros_message.target_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: position_error_direction
  {
    size_t item_size = sizeof(ros_message.position_error_direction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: position_error_ticks
  {
    size_t item_size = sizeof(ros_message.position_error_ticks);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: estimated_position_minus
  {
    size_t item_size = sizeof(ros_message.estimated_position_minus);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: estimated_position_plus
  {
    size_t item_size = sizeof(ros_message.estimated_position_plus);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: load_raw
  {
    size_t item_size = sizeof(ros_message.load_raw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_raw
  {
    size_t item_size = sizeof(ros_message.current_raw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: moving
  {
    size_t item_size = sizeof(ros_message.moving);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: voltage_v
  {
    size_t item_size = sizeof(ros_message.voltage_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temperature_c
  {
    size_t item_size = sizeof(ros_message.temperature_c);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fault
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.fault.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_alicia_d_control_interfaces
max_serialized_size_GripperState(
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


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: connected
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: homed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: raw_position
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: relative_ticks
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: target_position
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: position_error_direction
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: position_error_ticks
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: estimated_position_minus
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: estimated_position_plus
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: load_raw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_raw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: moving
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: voltage_v
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: temperature_c
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: fault
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
    using DataType = alicia_d_control_interfaces::msg::GripperState;
    is_plain =
      (
      offsetof(DataType, fault) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _GripperState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const alicia_d_control_interfaces::msg::GripperState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GripperState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<alicia_d_control_interfaces::msg::GripperState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GripperState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const alicia_d_control_interfaces::msg::GripperState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GripperState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GripperState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GripperState__callbacks = {
  "alicia_d_control_interfaces::msg",
  "GripperState",
  _GripperState__cdr_serialize,
  _GripperState__cdr_deserialize,
  _GripperState__get_serialized_size,
  _GripperState__max_serialized_size
};

static rosidl_message_type_support_t _GripperState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GripperState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace alicia_d_control_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_alicia_d_control_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<alicia_d_control_interfaces::msg::GripperState>()
{
  return &alicia_d_control_interfaces::msg::typesupport_fastrtps_cpp::_GripperState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, alicia_d_control_interfaces, msg, GripperState)() {
  return &alicia_d_control_interfaces::msg::typesupport_fastrtps_cpp::_GripperState__handle;
}

#ifdef __cplusplus
}
#endif
