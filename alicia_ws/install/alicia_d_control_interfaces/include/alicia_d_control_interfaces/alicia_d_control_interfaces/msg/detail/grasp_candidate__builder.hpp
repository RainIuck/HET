// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from alicia_d_control_interfaces:msg/GraspCandidate.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__BUILDER_HPP_
#define ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "alicia_d_control_interfaces/msg/detail/grasp_candidate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace alicia_d_control_interfaces
{

namespace msg
{

namespace builder
{

class Init_GraspCandidate_source
{
public:
  explicit Init_GraspCandidate_source(::alicia_d_control_interfaces::msg::GraspCandidate & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::msg::GraspCandidate source(::alicia_d_control_interfaces::msg::GraspCandidate::_source_type arg)
  {
    msg_.source = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GraspCandidate msg_;
};

class Init_GraspCandidate_grasp_depth_m
{
public:
  explicit Init_GraspCandidate_grasp_depth_m(::alicia_d_control_interfaces::msg::GraspCandidate & msg)
  : msg_(msg)
  {}
  Init_GraspCandidate_source grasp_depth_m(::alicia_d_control_interfaces::msg::GraspCandidate::_grasp_depth_m_type arg)
  {
    msg_.grasp_depth_m = std::move(arg);
    return Init_GraspCandidate_source(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GraspCandidate msg_;
};

class Init_GraspCandidate_grasp_pose
{
public:
  explicit Init_GraspCandidate_grasp_pose(::alicia_d_control_interfaces::msg::GraspCandidate & msg)
  : msg_(msg)
  {}
  Init_GraspCandidate_grasp_depth_m grasp_pose(::alicia_d_control_interfaces::msg::GraspCandidate::_grasp_pose_type arg)
  {
    msg_.grasp_pose = std::move(arg);
    return Init_GraspCandidate_grasp_depth_m(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GraspCandidate msg_;
};

class Init_GraspCandidate_header
{
public:
  Init_GraspCandidate_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GraspCandidate_grasp_pose header(::alicia_d_control_interfaces::msg::GraspCandidate::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GraspCandidate_grasp_pose(msg_);
  }

private:
  ::alicia_d_control_interfaces::msg::GraspCandidate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::msg::GraspCandidate>()
{
  return alicia_d_control_interfaces::msg::builder::Init_GraspCandidate_header();
}

}  // namespace alicia_d_control_interfaces

#endif  // ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__BUILDER_HPP_
