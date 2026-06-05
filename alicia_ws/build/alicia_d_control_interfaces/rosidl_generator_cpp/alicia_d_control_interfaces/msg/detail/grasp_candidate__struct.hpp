// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from alicia_d_control_interfaces:msg/GraspCandidate.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__STRUCT_HPP_
#define ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__STRUCT_HPP_

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
// Member 'grasp_pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__alicia_d_control_interfaces__msg__GraspCandidate __attribute__((deprecated))
#else
# define DEPRECATED__alicia_d_control_interfaces__msg__GraspCandidate __declspec(deprecated)
#endif

namespace alicia_d_control_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GraspCandidate_
{
  using Type = GraspCandidate_<ContainerAllocator>;

  explicit GraspCandidate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    grasp_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->grasp_depth_m = 0.0;
      this->source = "";
    }
  }

  explicit GraspCandidate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    grasp_pose(_alloc, _init),
    source(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->grasp_depth_m = 0.0;
      this->source = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _grasp_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _grasp_pose_type grasp_pose;
  using _grasp_depth_m_type =
    double;
  _grasp_depth_m_type grasp_depth_m;
  using _source_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _source_type source;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__grasp_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->grasp_pose = _arg;
    return *this;
  }
  Type & set__grasp_depth_m(
    const double & _arg)
  {
    this->grasp_depth_m = _arg;
    return *this;
  }
  Type & set__source(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->source = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    alicia_d_control_interfaces::msg::GraspCandidate_<ContainerAllocator> *;
  using ConstRawPtr =
    const alicia_d_control_interfaces::msg::GraspCandidate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::msg::GraspCandidate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::msg::GraspCandidate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::msg::GraspCandidate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::msg::GraspCandidate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::msg::GraspCandidate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::msg::GraspCandidate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::msg::GraspCandidate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::msg::GraspCandidate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__alicia_d_control_interfaces__msg__GraspCandidate
    std::shared_ptr<alicia_d_control_interfaces::msg::GraspCandidate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__alicia_d_control_interfaces__msg__GraspCandidate
    std::shared_ptr<alicia_d_control_interfaces::msg::GraspCandidate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GraspCandidate_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->grasp_pose != other.grasp_pose) {
      return false;
    }
    if (this->grasp_depth_m != other.grasp_depth_m) {
      return false;
    }
    if (this->source != other.source) {
      return false;
    }
    return true;
  }
  bool operator!=(const GraspCandidate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GraspCandidate_

// alias to use template instance with default allocator
using GraspCandidate =
  alicia_d_control_interfaces::msg::GraspCandidate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace alicia_d_control_interfaces

#endif  // ALICIA_D_CONTROL_INTERFACES__MSG__DETAIL__GRASP_CANDIDATE__STRUCT_HPP_
