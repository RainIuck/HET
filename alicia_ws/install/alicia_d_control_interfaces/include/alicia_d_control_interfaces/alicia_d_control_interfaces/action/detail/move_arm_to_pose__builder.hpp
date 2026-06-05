// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from alicia_d_control_interfaces:action/MoveArmToPose.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_ARM_TO_POSE__BUILDER_HPP_
#define ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_ARM_TO_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToPose_Goal_execute
{
public:
  explicit Init_MoveArmToPose_Goal_execute(::alicia_d_control_interfaces::action::MoveArmToPose_Goal & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToPose_Goal execute(::alicia_d_control_interfaces::action::MoveArmToPose_Goal::_execute_type arg)
  {
    msg_.execute = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_Goal msg_;
};

class Init_MoveArmToPose_Goal_avoid_collisions
{
public:
  explicit Init_MoveArmToPose_Goal_avoid_collisions(::alicia_d_control_interfaces::action::MoveArmToPose_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveArmToPose_Goal_execute avoid_collisions(::alicia_d_control_interfaces::action::MoveArmToPose_Goal::_avoid_collisions_type arg)
  {
    msg_.avoid_collisions = std::move(arg);
    return Init_MoveArmToPose_Goal_execute(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_Goal msg_;
};

class Init_MoveArmToPose_Goal_max_acceleration_scaling
{
public:
  explicit Init_MoveArmToPose_Goal_max_acceleration_scaling(::alicia_d_control_interfaces::action::MoveArmToPose_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveArmToPose_Goal_avoid_collisions max_acceleration_scaling(::alicia_d_control_interfaces::action::MoveArmToPose_Goal::_max_acceleration_scaling_type arg)
  {
    msg_.max_acceleration_scaling = std::move(arg);
    return Init_MoveArmToPose_Goal_avoid_collisions(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_Goal msg_;
};

class Init_MoveArmToPose_Goal_max_velocity_scaling
{
public:
  explicit Init_MoveArmToPose_Goal_max_velocity_scaling(::alicia_d_control_interfaces::action::MoveArmToPose_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveArmToPose_Goal_max_acceleration_scaling max_velocity_scaling(::alicia_d_control_interfaces::action::MoveArmToPose_Goal::_max_velocity_scaling_type arg)
  {
    msg_.max_velocity_scaling = std::move(arg);
    return Init_MoveArmToPose_Goal_max_acceleration_scaling(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_Goal msg_;
};

class Init_MoveArmToPose_Goal_ik_link_name
{
public:
  explicit Init_MoveArmToPose_Goal_ik_link_name(::alicia_d_control_interfaces::action::MoveArmToPose_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveArmToPose_Goal_max_velocity_scaling ik_link_name(::alicia_d_control_interfaces::action::MoveArmToPose_Goal::_ik_link_name_type arg)
  {
    msg_.ik_link_name = std::move(arg);
    return Init_MoveArmToPose_Goal_max_velocity_scaling(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_Goal msg_;
};

class Init_MoveArmToPose_Goal_target_pose
{
public:
  Init_MoveArmToPose_Goal_target_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArmToPose_Goal_ik_link_name target_pose(::alicia_d_control_interfaces::action::MoveArmToPose_Goal::_target_pose_type arg)
  {
    msg_.target_pose = std::move(arg);
    return Init_MoveArmToPose_Goal_ik_link_name(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToPose_Goal>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToPose_Goal_target_pose();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToPose_Result_message
{
public:
  explicit Init_MoveArmToPose_Result_message(::alicia_d_control_interfaces::action::MoveArmToPose_Result & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToPose_Result message(::alicia_d_control_interfaces::action::MoveArmToPose_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_Result msg_;
};

class Init_MoveArmToPose_Result_moveit_error_code
{
public:
  explicit Init_MoveArmToPose_Result_moveit_error_code(::alicia_d_control_interfaces::action::MoveArmToPose_Result & msg)
  : msg_(msg)
  {}
  Init_MoveArmToPose_Result_message moveit_error_code(::alicia_d_control_interfaces::action::MoveArmToPose_Result::_moveit_error_code_type arg)
  {
    msg_.moveit_error_code = std::move(arg);
    return Init_MoveArmToPose_Result_message(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_Result msg_;
};

class Init_MoveArmToPose_Result_success
{
public:
  Init_MoveArmToPose_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArmToPose_Result_moveit_error_code success(::alicia_d_control_interfaces::action::MoveArmToPose_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveArmToPose_Result_moveit_error_code(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToPose_Result>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToPose_Result_success();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToPose_Feedback_stage
{
public:
  Init_MoveArmToPose_Feedback_stage()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToPose_Feedback stage(::alicia_d_control_interfaces::action::MoveArmToPose_Feedback::_stage_type arg)
  {
    msg_.stage = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToPose_Feedback>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToPose_Feedback_stage();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToPose_SendGoal_Request_goal
{
public:
  explicit Init_MoveArmToPose_SendGoal_Request_goal(::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Request goal(::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Request msg_;
};

class Init_MoveArmToPose_SendGoal_Request_goal_id
{
public:
  Init_MoveArmToPose_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArmToPose_SendGoal_Request_goal goal_id(::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveArmToPose_SendGoal_Request_goal(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Request>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToPose_SendGoal_Request_goal_id();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToPose_SendGoal_Response_stamp
{
public:
  explicit Init_MoveArmToPose_SendGoal_Response_stamp(::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Response stamp(::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Response msg_;
};

class Init_MoveArmToPose_SendGoal_Response_accepted
{
public:
  Init_MoveArmToPose_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArmToPose_SendGoal_Response_stamp accepted(::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveArmToPose_SendGoal_Response_stamp(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToPose_SendGoal_Response>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToPose_SendGoal_Response_accepted();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToPose_GetResult_Request_goal_id
{
public:
  Init_MoveArmToPose_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToPose_GetResult_Request goal_id(::alicia_d_control_interfaces::action::MoveArmToPose_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToPose_GetResult_Request>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToPose_GetResult_Request_goal_id();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToPose_GetResult_Response_result
{
public:
  explicit Init_MoveArmToPose_GetResult_Response_result(::alicia_d_control_interfaces::action::MoveArmToPose_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToPose_GetResult_Response result(::alicia_d_control_interfaces::action::MoveArmToPose_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_GetResult_Response msg_;
};

class Init_MoveArmToPose_GetResult_Response_status
{
public:
  Init_MoveArmToPose_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArmToPose_GetResult_Response_result status(::alicia_d_control_interfaces::action::MoveArmToPose_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveArmToPose_GetResult_Response_result(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToPose_GetResult_Response>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToPose_GetResult_Response_status();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToPose_FeedbackMessage_feedback
{
public:
  explicit Init_MoveArmToPose_FeedbackMessage_feedback(::alicia_d_control_interfaces::action::MoveArmToPose_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToPose_FeedbackMessage feedback(::alicia_d_control_interfaces::action::MoveArmToPose_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_FeedbackMessage msg_;
};

class Init_MoveArmToPose_FeedbackMessage_goal_id
{
public:
  Init_MoveArmToPose_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArmToPose_FeedbackMessage_feedback goal_id(::alicia_d_control_interfaces::action::MoveArmToPose_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveArmToPose_FeedbackMessage_feedback(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToPose_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToPose_FeedbackMessage>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToPose_FeedbackMessage_goal_id();
}

}  // namespace alicia_d_control_interfaces

#endif  // ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_ARM_TO_POSE__BUILDER_HPP_
