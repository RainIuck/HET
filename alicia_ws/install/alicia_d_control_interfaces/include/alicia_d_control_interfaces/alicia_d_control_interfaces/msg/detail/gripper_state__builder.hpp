// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from alicia_d_control_interfaces:msg/GripperState.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRIPPER_STATE__BUILDER_HPP_
#define ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRIPPER_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "alicia_d_control_interfaces/msg/detail/gripper_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace alicia_d_control_interfaces
{

namespace msg
{

namespace builder
{

class Init_GripperState_fault
{
public:
  explicit Init_GripperState_fault(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::msg::GripperState fault(::alicia_d_control_interfaces::msg::GripperState::_fault_type arg)
  {
    msg_.fault = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_temperature_c
{
public:
  explicit Init_GripperState_temperature_c(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_fault temperature_c(::alicia_d_control_interfaces::msg::GripperState::_temperature_c_type arg)
  {
    msg_.temperature_c = std::move(arg);
    return Init_GripperState_fault(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_voltage_v
{
public:
  explicit Init_GripperState_voltage_v(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_temperature_c voltage_v(::alicia_d_control_interfaces::msg::GripperState::_voltage_v_type arg)
  {
    msg_.voltage_v = std::move(arg);
    return Init_GripperState_temperature_c(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_moving
{
public:
  explicit Init_GripperState_moving(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_voltage_v moving(::alicia_d_control_interfaces::msg::GripperState::_moving_type arg)
  {
    msg_.moving = std::move(arg);
    return Init_GripperState_voltage_v(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_current_raw
{
public:
  explicit Init_GripperState_current_raw(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_moving current_raw(::alicia_d_control_interfaces::msg::GripperState::_current_raw_type arg)
  {
    msg_.current_raw = std::move(arg);
    return Init_GripperState_moving(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_load_raw
{
public:
  explicit Init_GripperState_load_raw(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_current_raw load_raw(::alicia_d_control_interfaces::msg::GripperState::_load_raw_type arg)
  {
    msg_.load_raw = std::move(arg);
    return Init_GripperState_current_raw(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_estimated_position_plus
{
public:
  explicit Init_GripperState_estimated_position_plus(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_load_raw estimated_position_plus(::alicia_d_control_interfaces::msg::GripperState::_estimated_position_plus_type arg)
  {
    msg_.estimated_position_plus = std::move(arg);
    return Init_GripperState_load_raw(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_estimated_position_minus
{
public:
  explicit Init_GripperState_estimated_position_minus(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_estimated_position_plus estimated_position_minus(::alicia_d_control_interfaces::msg::GripperState::_estimated_position_minus_type arg)
  {
    msg_.estimated_position_minus = std::move(arg);
    return Init_GripperState_estimated_position_plus(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_position_error_ticks
{
public:
  explicit Init_GripperState_position_error_ticks(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_estimated_position_minus position_error_ticks(::alicia_d_control_interfaces::msg::GripperState::_position_error_ticks_type arg)
  {
    msg_.position_error_ticks = std::move(arg);
    return Init_GripperState_estimated_position_minus(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_position_error_direction
{
public:
  explicit Init_GripperState_position_error_direction(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_position_error_ticks position_error_direction(::alicia_d_control_interfaces::msg::GripperState::_position_error_direction_type arg)
  {
    msg_.position_error_direction = std::move(arg);
    return Init_GripperState_position_error_ticks(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_target_position
{
public:
  explicit Init_GripperState_target_position(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_position_error_direction target_position(::alicia_d_control_interfaces::msg::GripperState::_target_position_type arg)
  {
    msg_.target_position = std::move(arg);
    return Init_GripperState_position_error_direction(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_relative_ticks
{
public:
  explicit Init_GripperState_relative_ticks(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_target_position relative_ticks(::alicia_d_control_interfaces::msg::GripperState::_relative_ticks_type arg)
  {
    msg_.relative_ticks = std::move(arg);
    return Init_GripperState_target_position(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_raw_position
{
public:
  explicit Init_GripperState_raw_position(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_relative_ticks raw_position(::alicia_d_control_interfaces::msg::GripperState::_raw_position_type arg)
  {
    msg_.raw_position = std::move(arg);
    return Init_GripperState_relative_ticks(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_homed
{
public:
  explicit Init_GripperState_homed(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_raw_position homed(::alicia_d_control_interfaces::msg::GripperState::_homed_type arg)
  {
    msg_.homed = std::move(arg);
    return Init_GripperState_raw_position(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_connected
{
public:
  explicit Init_GripperState_connected(::alicia_d_control_interfaces::msg::GripperState & msg)
  : msg_(msg)
  {}
  Init_GripperState_homed connected(::alicia_d_control_interfaces::msg::GripperState::_connected_type arg)
  {
    msg_.connected = std::move(arg);
    return Init_GripperState_homed(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

class Init_GripperState_header
{
public:
  Init_GripperState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GripperState_connected header(::alicia_d_control_interfaces::msg::GripperState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GripperState_connected(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GripperState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::msg::GripperState>()
{
  return alicia_d_control_interfaces::msg::builder::Init_GripperState_header();
}

}  // namespace alicia_d_control_interfaces

#endif  // ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRIPPER_STATE__BUILDER_HPP_
