// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from alicia_d_control_interfaces:msg/GripperState.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRIPPER_STATE__STRUCT_HPP_
#define ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRIPPER_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__alicia_d_control_interfaces__msg__GripperState __attribute__((deprecated))
#else
# define DEPRECATED__alicia_d_control_interfaces__msg__GripperState __declspec(deprecated)
#endif

namespace alicia_d_control_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GripperState_
{
  using Type = GripperState_<ContainerAllocator>;

  explicit GripperState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->connected = false;
      this->homed = false;
      this->raw_position = 0l;
      this->relative_ticks = 0l;
      this->target_position = 0l;
      this->position_error_direction = false;
      this->position_error_ticks = 0l;
      this->estimated_position_minus = 0l;
      this->estimated_position_plus = 0l;
      this->load_raw = 0l;
      this->current_raw = 0l;
      this->moving = false;
      this->voltage_v = 0.0f;
      this->temperature_c = 0l;
      this->fault = "";
    }
  }

  explicit GripperState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    fault(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->connected = false;
      this->homed = false;
      this->raw_position = 0l;
      this->relative_ticks = 0l;
      this->target_position = 0l;
      this->position_error_direction = false;
      this->position_error_ticks = 0l;
      this->estimated_position_minus = 0l;
      this->estimated_position_plus = 0l;
      this->load_raw = 0l;
      this->current_raw = 0l;
      this->moving = false;
      this->voltage_v = 0.0f;
      this->temperature_c = 0l;
      this->fault = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _connected_type =
    bool;
  _connected_type connected;
  using _homed_type =
    bool;
  _homed_type homed;
  using _raw_position_type =
    int32_t;
  _raw_position_type raw_position;
  using _relative_ticks_type =
    int32_t;
  _relative_ticks_type relative_ticks;
  using _target_position_type =
    int32_t;
  _target_position_type target_position;
  using _position_error_direction_type =
    bool;
  _position_error_direction_type position_error_direction;
  using _position_error_ticks_type =
    int32_t;
  _position_error_ticks_type position_error_ticks;
  using _estimated_position_minus_type =
    int32_t;
  _estimated_position_minus_type estimated_position_minus;
  using _estimated_position_plus_type =
    int32_t;
  _estimated_position_plus_type estimated_position_plus;
  using _load_raw_type =
    int32_t;
  _load_raw_type load_raw;
  using _current_raw_type =
    int32_t;
  _current_raw_type current_raw;
  using _moving_type =
    bool;
  _moving_type moving;
  using _voltage_v_type =
    float;
  _voltage_v_type voltage_v;
  using _temperature_c_type =
    int32_t;
  _temperature_c_type temperature_c;
  using _fault_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _fault_type fault;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__connected(
    const bool & _arg)
  {
    this->connected = _arg;
    return *this;
  }
  Type & set__homed(
    const bool & _arg)
  {
    this->homed = _arg;
    return *this;
  }
  Type & set__raw_position(
    const int32_t & _arg)
  {
    this->raw_position = _arg;
    return *this;
  }
  Type & set__relative_ticks(
    const int32_t & _arg)
  {
    this->relative_ticks = _arg;
    return *this;
  }
  Type & set__target_position(
    const int32_t & _arg)
  {
    this->target_position = _arg;
    return *this;
  }
  Type & set__position_error_direction(
    const bool & _arg)
  {
    this->position_error_direction = _arg;
    return *this;
  }
  Type & set__position_error_ticks(
    const int32_t & _arg)
  {
    this->position_error_ticks = _arg;
    return *this;
  }
  Type & set__estimated_position_minus(
    const int32_t & _arg)
  {
    this->estimated_position_minus = _arg;
    return *this;
  }
  Type & set__estimated_position_plus(
    const int32_t & _arg)
  {
    this->estimated_position_plus = _arg;
    return *this;
  }
  Type & set__load_raw(
    const int32_t & _arg)
  {
    this->load_raw = _arg;
    return *this;
  }
  Type & set__current_raw(
    const int32_t & _arg)
  {
    this->current_raw = _arg;
    return *this;
  }
  Type & set__moving(
    const bool & _arg)
  {
    this->moving = _arg;
    return *this;
  }
  Type & set__voltage_v(
    const float & _arg)
  {
    this->voltage_v = _arg;
    return *this;
  }
  Type & set__temperature_c(
    const int32_t & _arg)
  {
    this->temperature_c = _arg;
    return *this;
  }
  Type & set__fault(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->fault = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    alicia_d_control_interfaces::msg::GripperState_<ContainerAllocator> *;
  using ConstRawPtr =
    const alicia_d_control_interfaces::msg::GripperState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::msg::GripperState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::msg::GripperState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::msg::GripperState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::msg::GripperState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::msg::GripperState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::msg::GripperState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::msg::GripperState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::msg::GripperState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__alicia_d_control_interfaces__msg__GripperState
    std::shared_ptr<alicia_d_control_interfaces::msg::GripperState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__alicia_d_control_interfaces__msg__GripperState
    std::shared_ptr<alicia_d_control_interfaces::msg::GripperState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GripperState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->connected != other.connected) {
      return false;
    }
    if (this->homed != other.homed) {
      return false;
    }
    if (this->raw_position != other.raw_position) {
      return false;
    }
    if (this->relative_ticks != other.relative_ticks) {
      return false;
    }
    if (this->target_position != other.target_position) {
      return false;
    }
    if (this->position_error_direction != other.position_error_direction) {
      return false;
    }
    if (this->position_error_ticks != other.position_error_ticks) {
      return false;
    }
    if (this->estimated_position_minus != other.estimated_position_minus) {
      return false;
    }
    if (this->estimated_position_plus != other.estimated_position_plus) {
      return false;
    }
    if (this->load_raw != other.load_raw) {
      return false;
    }
    if (this->current_raw != other.current_raw) {
      return false;
    }
    if (this->moving != other.moving) {
      return false;
    }
    if (this->voltage_v != other.voltage_v) {
      return false;
    }
    if (this->temperature_c != other.temperature_c) {
      return false;
    }
    if (this->fault != other.fault) {
      return false;
    }
    return true;
  }
  bool operator!=(const GripperState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GripperState_

// alias to use template instance with default allocator
using GripperState =
  alicia_d_control_interfaces::msg::GripperState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace alicia_d_control_interfaces

#endif  // ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRIPPER_STATE__STRUCT_HPP_
