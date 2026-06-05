// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from alicia_d_control_interfaces:action/MoveGripperStep.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_GRIPPER_STEP__BUILDER_HPP_
#define ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_GRIPPER_STEP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "alicia_d_control_interfaces/action/detail/move_gripper_step__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveGripperStep_Goal_speed
{
public:
  explicit Init_MoveGripperStep_Goal_speed(::alicia_d_control_interfaces::action::MoveGripperStep_Goal & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveGripperStep_Goal speed(::alicia_d_control_interfaces::action::MoveGripperStep_Goal::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_Goal msg_;
};

class Init_MoveGripperStep_Goal_delta_ticks
{
public:
  Init_MoveGripperStep_Goal_delta_ticks()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripperStep_Goal_speed delta_ticks(::alicia_d_control_interfaces::action::MoveGripperStep_Goal::_delta_ticks_type arg)
  {
    msg_.delta_ticks = std::move(arg);
    return Init_MoveGripperStep_Goal_speed(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveGripperStep_Goal>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveGripperStep_Goal_delta_ticks();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveGripperStep_Result_moved_ticks
{
public:
  explicit Init_MoveGripperStep_Result_moved_ticks(::alicia_d_control_interfaces::action::MoveGripperStep_Result & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveGripperStep_Result moved_ticks(::alicia_d_control_interfaces::action::MoveGripperStep_Result::_moved_ticks_type arg)
  {
    msg_.moved_ticks = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_Result msg_;
};

class Init_MoveGripperStep_Result_raw_position
{
public:
  explicit Init_MoveGripperStep_Result_raw_position(::alicia_d_control_interfaces::action::MoveGripperStep_Result & msg)
  : msg_(msg)
  {}
  Init_MoveGripperStep_Result_moved_ticks raw_position(::alicia_d_control_interfaces::action::MoveGripperStep_Result::_raw_position_type arg)
  {
    msg_.raw_position = std::move(arg);
    return Init_MoveGripperStep_Result_moved_ticks(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_Result msg_;
};

class Init_MoveGripperStep_Result_message
{
public:
  explicit Init_MoveGripperStep_Result_message(::alicia_d_control_interfaces::action::MoveGripperStep_Result & msg)
  : msg_(msg)
  {}
  Init_MoveGripperStep_Result_raw_position message(::alicia_d_control_interfaces::action::MoveGripperStep_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_MoveGripperStep_Result_raw_position(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_Result msg_;
};

class Init_MoveGripperStep_Result_success
{
public:
  Init_MoveGripperStep_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripperStep_Result_message success(::alicia_d_control_interfaces::action::MoveGripperStep_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveGripperStep_Result_message(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveGripperStep_Result>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveGripperStep_Result_success();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveGripperStep_Feedback_moving
{
public:
  explicit Init_MoveGripperStep_Feedback_moving(::alicia_d_control_interfaces::action::MoveGripperStep_Feedback & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveGripperStep_Feedback moving(::alicia_d_control_interfaces::action::MoveGripperStep_Feedback::_moving_type arg)
  {
    msg_.moving = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_Feedback msg_;
};

class Init_MoveGripperStep_Feedback_moved_ticks
{
public:
  explicit Init_MoveGripperStep_Feedback_moved_ticks(::alicia_d_control_interfaces::action::MoveGripperStep_Feedback & msg)
  : msg_(msg)
  {}
  Init_MoveGripperStep_Feedback_moving moved_ticks(::alicia_d_control_interfaces::action::MoveGripperStep_Feedback::_moved_ticks_type arg)
  {
    msg_.moved_ticks = std::move(arg);
    return Init_MoveGripperStep_Feedback_moving(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_Feedback msg_;
};

class Init_MoveGripperStep_Feedback_raw_position
{
public:
  Init_MoveGripperStep_Feedback_raw_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripperStep_Feedback_moved_ticks raw_position(::alicia_d_control_interfaces::action::MoveGripperStep_Feedback::_raw_position_type arg)
  {
    msg_.raw_position = std::move(arg);
    return Init_MoveGripperStep_Feedback_moved_ticks(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveGripperStep_Feedback>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveGripperStep_Feedback_raw_position();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveGripperStep_SendGoal_Request_goal
{
public:
  explicit Init_MoveGripperStep_SendGoal_Request_goal(::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request goal(::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request msg_;
};

class Init_MoveGripperStep_SendGoal_Request_goal_id
{
public:
  Init_MoveGripperStep_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripperStep_SendGoal_Request_goal goal_id(::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveGripperStep_SendGoal_Request_goal(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Request>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveGripperStep_SendGoal_Request_goal_id();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveGripperStep_SendGoal_Response_stamp
{
public:
  explicit Init_MoveGripperStep_SendGoal_Response_stamp(::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response stamp(::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response msg_;
};

class Init_MoveGripperStep_SendGoal_Response_accepted
{
public:
  Init_MoveGripperStep_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripperStep_SendGoal_Response_stamp accepted(::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveGripperStep_SendGoal_Response_stamp(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveGripperStep_SendGoal_Response>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveGripperStep_SendGoal_Response_accepted();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveGripperStep_GetResult_Request_goal_id
{
public:
  Init_MoveGripperStep_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Request goal_id(::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Request>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveGripperStep_GetResult_Request_goal_id();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveGripperStep_GetResult_Response_result
{
public:
  explicit Init_MoveGripperStep_GetResult_Response_result(::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response result(::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response msg_;
};

class Init_MoveGripperStep_GetResult_Response_status
{
public:
  Init_MoveGripperStep_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripperStep_GetResult_Response_result status(::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveGripperStep_GetResult_Response_result(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveGripperStep_GetResult_Response>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveGripperStep_GetResult_Response_status();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveGripperStep_FeedbackMessage_feedback
{
public:
  explicit Init_MoveGripperStep_FeedbackMessage_feedback(::alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage feedback(::alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage msg_;
};

class Init_MoveGripperStep_FeedbackMessage_goal_id
{
public:
  Init_MoveGripperStep_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripperStep_FeedbackMessage_feedback goal_id(::alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveGripperStep_FeedbackMessage_feedback(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::MoveGripperStep_FeedbackMessage>()
{
  return alicia_d_control_interfaces::action::builder::Init_MoveGripperStep_FeedbackMessage_goal_id();
}

}  // namespace alicia_d_control_interfaces

#endif  // ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__MOVE_GRIPPER_STEP__BUILDER_HPP_
