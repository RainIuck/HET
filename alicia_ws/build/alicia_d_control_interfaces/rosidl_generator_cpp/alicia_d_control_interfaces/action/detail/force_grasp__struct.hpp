// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from alicia_d_control_interfaces:action/ForceGrasp.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__FORCE_GRASP__STRUCT_HPP_
#define ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__FORCE_GRASP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_Goal __attribute__((deprecated))
#else
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_Goal __declspec(deprecated)
#endif

namespace alicia_d_control_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ForceGrasp_Goal_
{
  using Type = ForceGrasp_Goal_<ContainerAllocator>;

  explicit ForceGrasp_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_threshold_raw = 0l;
      this->max_ticks = 0l;
      this->speed = 0l;
    }
  }

  explicit ForceGrasp_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_threshold_raw = 0l;
      this->max_ticks = 0l;
      this->speed = 0l;
    }
  }

  // field types and members
  using _current_threshold_raw_type =
    int32_t;
  _current_threshold_raw_type current_threshold_raw;
  using _max_ticks_type =
    int32_t;
  _max_ticks_type max_ticks;
  using _speed_type =
    int32_t;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__current_threshold_raw(
    const int32_t & _arg)
  {
    this->current_threshold_raw = _arg;
    return *this;
  }
  Type & set__max_ticks(
    const int32_t & _arg)
  {
    this->max_ticks = _arg;
    return *this;
  }
  Type & set__speed(
    const int32_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_Goal
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_Goal
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ForceGrasp_Goal_ & other) const
  {
    if (this->current_threshold_raw != other.current_threshold_raw) {
      return false;
    }
    if (this->max_ticks != other.max_ticks) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const ForceGrasp_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ForceGrasp_Goal_

// alias to use template instance with default allocator
using ForceGrasp_Goal =
  alicia_d_control_interfaces::action::ForceGrasp_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace alicia_d_control_interfaces


#ifndef _WIN32
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_Result __attribute__((deprecated))
#else
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_Result __declspec(deprecated)
#endif

namespace alicia_d_control_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ForceGrasp_Result_
{
  using Type = ForceGrasp_Result_<ContainerAllocator>;

  explicit ForceGrasp_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->contact_detected = false;
      this->message = "";
      this->raw_position = 0l;
      this->relative_ticks = 0l;
      this->load_raw = 0l;
      this->current_raw = 0l;
    }
  }

  explicit ForceGrasp_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->contact_detected = false;
      this->message = "";
      this->raw_position = 0l;
      this->relative_ticks = 0l;
      this->load_raw = 0l;
      this->current_raw = 0l;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _contact_detected_type =
    bool;
  _contact_detected_type contact_detected;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _raw_position_type =
    int32_t;
  _raw_position_type raw_position;
  using _relative_ticks_type =
    int32_t;
  _relative_ticks_type relative_ticks;
  using _load_raw_type =
    int32_t;
  _load_raw_type load_raw;
  using _current_raw_type =
    int32_t;
  _current_raw_type current_raw;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__contact_detected(
    const bool & _arg)
  {
    this->contact_detected = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
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

  // constant declarations

  // pointer types
  using RawPtr =
    alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_Result
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_Result
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ForceGrasp_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->contact_detected != other.contact_detected) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->raw_position != other.raw_position) {
      return false;
    }
    if (this->relative_ticks != other.relative_ticks) {
      return false;
    }
    if (this->load_raw != other.load_raw) {
      return false;
    }
    if (this->current_raw != other.current_raw) {
      return false;
    }
    return true;
  }
  bool operator!=(const ForceGrasp_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ForceGrasp_Result_

// alias to use template instance with default allocator
using ForceGrasp_Result =
  alicia_d_control_interfaces::action::ForceGrasp_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace alicia_d_control_interfaces


#ifndef _WIN32
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_Feedback __declspec(deprecated)
#endif

namespace alicia_d_control_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ForceGrasp_Feedback_
{
  using Type = ForceGrasp_Feedback_<ContainerAllocator>;

  explicit ForceGrasp_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->raw_position = 0l;
      this->relative_ticks = 0l;
      this->load_raw = 0l;
      this->current_raw = 0l;
      this->moving = false;
    }
  }

  explicit ForceGrasp_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->raw_position = 0l;
      this->relative_ticks = 0l;
      this->load_raw = 0l;
      this->current_raw = 0l;
      this->moving = false;
    }
  }

  // field types and members
  using _raw_position_type =
    int32_t;
  _raw_position_type raw_position;
  using _relative_ticks_type =
    int32_t;
  _relative_ticks_type relative_ticks;
  using _load_raw_type =
    int32_t;
  _load_raw_type load_raw;
  using _current_raw_type =
    int32_t;
  _current_raw_type current_raw;
  using _moving_type =
    bool;
  _moving_type moving;

  // setters for named parameter idiom
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

  // constant declarations

  // pointer types
  using RawPtr =
    alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_Feedback
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_Feedback
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ForceGrasp_Feedback_ & other) const
  {
    if (this->raw_position != other.raw_position) {
      return false;
    }
    if (this->relative_ticks != other.relative_ticks) {
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
    return true;
  }
  bool operator!=(const ForceGrasp_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ForceGrasp_Feedback_

// alias to use template instance with default allocator
using ForceGrasp_Feedback =
  alicia_d_control_interfaces::action::ForceGrasp_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace alicia_d_control_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "alicia_d_control_interfaces/action/detail/force_grasp__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request __declspec(deprecated)
#endif

namespace alicia_d_control_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ForceGrasp_SendGoal_Request_
{
  using Type = ForceGrasp_SendGoal_Request_<ContainerAllocator>;

  explicit ForceGrasp_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit ForceGrasp_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const alicia_d_control_interfaces::action::ForceGrasp_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ForceGrasp_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const ForceGrasp_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ForceGrasp_SendGoal_Request_

// alias to use template instance with default allocator
using ForceGrasp_SendGoal_Request =
  alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace alicia_d_control_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response __declspec(deprecated)
#endif

namespace alicia_d_control_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ForceGrasp_SendGoal_Response_
{
  using Type = ForceGrasp_SendGoal_Response_<ContainerAllocator>;

  explicit ForceGrasp_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit ForceGrasp_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ForceGrasp_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const ForceGrasp_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ForceGrasp_SendGoal_Response_

// alias to use template instance with default allocator
using ForceGrasp_SendGoal_Response =
  alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace alicia_d_control_interfaces

namespace alicia_d_control_interfaces
{

namespace action
{

struct ForceGrasp_SendGoal
{
  using Request = alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request;
  using Response = alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response;
};

}  // namespace action

}  // namespace alicia_d_control_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request __declspec(deprecated)
#endif

namespace alicia_d_control_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ForceGrasp_GetResult_Request_
{
  using Type = ForceGrasp_GetResult_Request_<ContainerAllocator>;

  explicit ForceGrasp_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit ForceGrasp_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ForceGrasp_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const ForceGrasp_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ForceGrasp_GetResult_Request_

// alias to use template instance with default allocator
using ForceGrasp_GetResult_Request =
  alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace alicia_d_control_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "alicia_d_control_interfaces/action/detail/force_grasp__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response __declspec(deprecated)
#endif

namespace alicia_d_control_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ForceGrasp_GetResult_Response_
{
  using Type = ForceGrasp_GetResult_Response_<ContainerAllocator>;

  explicit ForceGrasp_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit ForceGrasp_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const alicia_d_control_interfaces::action::ForceGrasp_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ForceGrasp_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const ForceGrasp_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ForceGrasp_GetResult_Response_

// alias to use template instance with default allocator
using ForceGrasp_GetResult_Response =
  alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace alicia_d_control_interfaces

namespace alicia_d_control_interfaces
{

namespace action
{

struct ForceGrasp_GetResult
{
  using Request = alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request;
  using Response = alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response;
};

}  // namespace action

}  // namespace alicia_d_control_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "alicia_d_control_interfaces/action/detail/force_grasp__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage __declspec(deprecated)
#endif

namespace alicia_d_control_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ForceGrasp_FeedbackMessage_
{
  using Type = ForceGrasp_FeedbackMessage_<ContainerAllocator>;

  explicit ForceGrasp_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit ForceGrasp_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const alicia_d_control_interfaces::action::ForceGrasp_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage
    std::shared_ptr<alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ForceGrasp_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const ForceGrasp_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ForceGrasp_FeedbackMessage_

// alias to use template instance with default allocator
using ForceGrasp_FeedbackMessage =
  alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace alicia_d_control_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace alicia_d_control_interfaces
{

namespace action
{

struct ForceGrasp
{
  /// The goal message defined in the action definition.
  using Goal = alicia_d_control_interfaces::action::ForceGrasp_Goal;
  /// The result message defined in the action definition.
  using Result = alicia_d_control_interfaces::action::ForceGrasp_Result;
  /// The feedback message defined in the action definition.
  using Feedback = alicia_d_control_interfaces::action::ForceGrasp_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = alicia_d_control_interfaces::action::ForceGrasp_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = alicia_d_control_interfaces::action::ForceGrasp_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct ForceGrasp ForceGrasp;

}  // namespace action

}  // namespace alicia_d_control_interfaces

#endif  // ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__FORCE_GRASP__STRUCT_HPP_
