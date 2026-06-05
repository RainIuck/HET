// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from alicia_d_control_interfaces:action/MoveArmToJoints.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_ARM_TO_JOINTS__BUILDER_HPP_
#define ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_ARM_TO_JOINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "alicia_d_control_interfaces/action/detail/move_arm_to_joints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToJoints_Goal_execute
{
public:
  explicit Init_MoveArmToJoints_Goal_execute(::alicia_d_control_interfaces::action::MoveArmToJoints_Goal & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToJoints_Goal execute(::alicia_d_control_interfaces::action::MoveArmToJoints_Goal::_execute_type arg)
  {
    msg_.execute = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_Goal msg_;
};

class Init_MoveArmToJoints_Goal_max_acceleration_scaling
{
public:
  explicit Init_MoveArmToJoints_Goal_max_acceleration_scaling(::alicia_d_control_interfaces::action::MoveArmToJoints_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveArmToJoints_Goal_execute max_acceleration_scaling(::alicia_d_control_interfaces::action::MoveArmToJoints_Goal::_max_acceleration_scaling_type arg)
  {
    msg_.max_acceleration_scaling = std::move(arg);
    return Init_MoveArmToJoints_Goal_execute(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_Goal msg_;
};

class Init_MoveArmToJoints_Goal_max_velocity_scaling
{
public:
  explicit Init_MoveArmToJoints_Goal_max_velocity_scaling(::alicia_d_control_interfaces::action::MoveArmToJoints_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveArmToJoints_Goal_max_acceleration_scaling max_velocity_scaling(::alicia_d_control_interfaces::action::MoveArmToJoints_Goal::_max_velocity_scaling_type arg)
  {
    msg_.max_velocity_scaling = std::move(arg);
    return Init_MoveArmToJoints_Goal_max_acceleration_scaling(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_Goal msg_;
};

class Init_MoveArmToJoints_Goal_joint_positions
{
public:
  explicit Init_MoveArmToJoints_Goal_joint_positions(::alicia_d_control_interfaces::action::MoveArmToJoints_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveArmToJoints_Goal_max_velocity_scaling joint_positions(::alicia_d_control_interfaces::action::MoveArmToJoints_Goal::_joint_positions_type arg)
  {
    msg_.joint_positions = std::move(arg);
    return Init_MoveArmToJoints_Goal_max_velocity_scaling(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_Goal msg_;
};

class Init_MoveArmToJoints_Goal_joint_names
{
public:
  Init_MoveArmToJoints_Goal_joint_names()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArmToJoints_Goal_joint_positions joint_names(::alicia_d_control_interfaces::action::MoveArmToJoints_Goal::_joint_names_type arg)
  {
    msg_.joint_names = std::move(arg);
    return Init_MoveArmToJoints_Goal_joint_positions(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToJoints_Goal>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToJoints_Goal_joint_names();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToJoints_Result_message
{
public:
  explicit Init_MoveArmToJoints_Result_message(::alicia_d_control_interfaces::action::MoveArmToJoints_Result & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToJoints_Result message(::alicia_d_control_interfaces::action::MoveArmToJoints_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_Result msg_;
};

class Init_MoveArmToJoints_Result_moveit_error_code
{
public:
  explicit Init_MoveArmToJoints_Result_moveit_error_code(::alicia_d_control_interfaces::action::MoveArmToJoints_Result & msg)
  : msg_(msg)
  {}
  Init_MoveArmToJoints_Result_message moveit_error_code(::alicia_d_control_interfaces::action::MoveArmToJoints_Result::_moveit_error_code_type arg)
  {
    msg_.moveit_error_code = std::move(arg);
    return Init_MoveArmToJoints_Result_message(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_Result msg_;
};

class Init_MoveArmToJoints_Result_success
{
public:
  Init_MoveArmToJoints_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArmToJoints_Result_moveit_error_code success(::alicia_d_control_interfaces::action::MoveArmToJoints_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveArmToJoints_Result_moveit_error_code(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToJoints_Result>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToJoints_Result_success();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToJoints_Feedback_stage
{
public:
  Init_MoveArmToJoints_Feedback_stage()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToJoints_Feedback stage(::alicia_d_control_interfaces::action::MoveArmToJoints_Feedback::_stage_type arg)
  {
    msg_.stage = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToJoints_Feedback>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToJoints_Feedback_stage();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToJoints_SendGoal_Request_goal
{
public:
  explicit Init_MoveArmToJoints_SendGoal_Request_goal(::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request goal(::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request msg_;
};

class Init_MoveArmToJoints_SendGoal_Request_goal_id
{
public:
  Init_MoveArmToJoints_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArmToJoints_SendGoal_Request_goal goal_id(::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveArmToJoints_SendGoal_Request_goal(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Request>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToJoints_SendGoal_Request_goal_id();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToJoints_SendGoal_Response_stamp
{
public:
  explicit Init_MoveArmToJoints_SendGoal_Response_stamp(::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response stamp(::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response msg_;
};

class Init_MoveArmToJoints_SendGoal_Response_accepted
{
public:
  Init_MoveArmToJoints_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArmToJoints_SendGoal_Response_stamp accepted(::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveArmToJoints_SendGoal_Response_stamp(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToJoints_SendGoal_Response>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToJoints_SendGoal_Response_accepted();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToJoints_GetResult_Request_goal_id
{
public:
  Init_MoveArmToJoints_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Request goal_id(::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Request>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToJoints_GetResult_Request_goal_id();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToJoints_GetResult_Response_result
{
public:
  explicit Init_MoveArmToJoints_GetResult_Response_result(::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response result(::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response msg_;
};

class Init_MoveArmToJoints_GetResult_Response_status
{
public:
  Init_MoveArmToJoints_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArmToJoints_GetResult_Response_result status(::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveArmToJoints_GetResult_Response_result(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToJoints_GetResult_Response>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToJoints_GetResult_Response_status();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArmToJoints_FeedbackMessage_feedback
{
public:
  explicit Init_MoveArmToJoints_FeedbackMessage_feedback(::alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage feedback(::alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage msg_;
};

class Init_MoveArmToJoints_FeedbackMessage_goal_id
{
public:
  Init_MoveArmToJoints_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArmToJoints_FeedbackMessage_feedback goal_id(::alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveArmToJoints_FeedbackMessage_feedback(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveArmToJoints_FeedbackMessage>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveArmToJoints_FeedbackMessage_goal_id();
}

}  // namespace alicia_d_control_interfaces

#endif  // ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_ARM_TO_JOINTS__BUILDER_HPP_
