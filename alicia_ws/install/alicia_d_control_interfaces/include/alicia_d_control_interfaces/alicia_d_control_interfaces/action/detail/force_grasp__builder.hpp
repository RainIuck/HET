// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from alicia_d_control_interfaces:action/ForceGrasp.idl
// generated code does not contain a copyright notice

#ifndef ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__FORCE_GRASP__BUILDER_HPP_
#define ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__FORCE_GRASP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "alicia_d_control_interfaces/action/detail/force_grasp__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_ForceGrasp_Goal_speed
{
public:
  explicit Init_ForceGrasp_Goal_speed(::alicia_d_control_interfaces::action::ForceGrasp_Goal & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::ForceGrasp_Goal speed(::alicia_d_control_interfaces::action::ForceGrasp_Goal::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Goal msg_;
};

class Init_ForceGrasp_Goal_max_ticks
{
public:
  explicit Init_ForceGrasp_Goal_max_ticks(::alicia_d_control_interfaces::action::ForceGrasp_Goal & msg)
  : msg_(msg)
  {}
  Init_ForceGrasp_Goal_speed max_ticks(::alicia_d_control_interfaces::action::ForceGrasp_Goal::_max_ticks_type arg)
  {
    msg_.max_ticks = std::move(arg);
    return Init_ForceGrasp_Goal_speed(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Goal msg_;
};

class Init_ForceGrasp_Goal_current_threshold_raw
{
public:
  Init_ForceGrasp_Goal_current_threshold_raw()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ForceGrasp_Goal_max_ticks current_threshold_raw(::alicia_d_control_interfaces::action::ForceGrasp_Goal::_current_threshold_raw_type arg)
  {
    msg_.current_threshold_raw = std::move(arg);
    return Init_ForceGrasp_Goal_max_ticks(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::ForceGrasp_Goal>()
{
  return alicia_d_control_interfaces::action::builder::Init_ForceGrasp_Goal_current_threshold_raw();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_ForceGrasp_Result_current_raw
{
public:
  explicit Init_ForceGrasp_Result_current_raw(::alicia_d_control_interfaces::action::ForceGrasp_Result & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::ForceGrasp_Result current_raw(::alicia_d_control_interfaces::action::ForceGrasp_Result::_current_raw_type arg)
  {
    msg_.current_raw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Result msg_;
};

class Init_ForceGrasp_Result_load_raw
{
public:
  explicit Init_ForceGrasp_Result_load_raw(::alicia_d_control_interfaces::action::ForceGrasp_Result & msg)
  : msg_(msg)
  {}
  Init_ForceGrasp_Result_current_raw load_raw(::alicia_d_control_interfaces::action::ForceGrasp_Result::_load_raw_type arg)
  {
    msg_.load_raw = std::move(arg);
    return Init_ForceGrasp_Result_current_raw(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Result msg_;
};

class Init_ForceGrasp_Result_relative_ticks
{
public:
  explicit Init_ForceGrasp_Result_relative_ticks(::alicia_d_control_interfaces::action::ForceGrasp_Result & msg)
  : msg_(msg)
  {}
  Init_ForceGrasp_Result_load_raw relative_ticks(::alicia_d_control_interfaces::action::ForceGrasp_Result::_relative_ticks_type arg)
  {
    msg_.relative_ticks = std::move(arg);
    return Init_ForceGrasp_Result_load_raw(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Result msg_;
};

class Init_ForceGrasp_Result_raw_position
{
public:
  explicit Init_ForceGrasp_Result_raw_position(::alicia_d_control_interfaces::action::ForceGrasp_Result & msg)
  : msg_(msg)
  {}
  Init_ForceGrasp_Result_relative_ticks raw_position(::alicia_d_control_interfaces::action::ForceGrasp_Result::_raw_position_type arg)
  {
    msg_.raw_position = std::move(arg);
    return Init_ForceGrasp_Result_relative_ticks(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Result msg_;
};

class Init_ForceGrasp_Result_message
{
public:
  explicit Init_ForceGrasp_Result_message(::alicia_d_control_interfaces::action::ForceGrasp_Result & msg)
  : msg_(msg)
  {}
  Init_ForceGrasp_Result_raw_position message(::alicia_d_control_interfaces::action::ForceGrasp_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_ForceGrasp_Result_raw_position(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Result msg_;
};

class Init_ForceGrasp_Result_contact_detected
{
public:
  explicit Init_ForceGrasp_Result_contact_detected(::alicia_d_control_interfaces::action::ForceGrasp_Result & msg)
  : msg_(msg)
  {}
  Init_ForceGrasp_Result_message contact_detected(::alicia_d_control_interfaces::action::ForceGrasp_Result::_contact_detected_type arg)
  {
    msg_.contact_detected = std::move(arg);
    return Init_ForceGrasp_Result_message(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Result msg_;
};

class Init_ForceGrasp_Result_success
{
public:
  Init_ForceGrasp_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ForceGrasp_Result_contact_detected success(::alicia_d_control_interfaces::action::ForceGrasp_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ForceGrasp_Result_contact_detected(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::ForceGrasp_Result>()
{
  return alicia_d_control_interfaces::action::builder::Init_ForceGrasp_Result_success();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_ForceGrasp_Feedback_moving
{
public:
  explicit Init_ForceGrasp_Feedback_moving(::alicia_d_control_interfaces::action::ForceGrasp_Feedback & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::ForceGrasp_Feedback moving(::alicia_d_control_interfaces::action::ForceGrasp_Feedback::_moving_type arg)
  {
    msg_.moving = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Feedback msg_;
};

class Init_ForceGrasp_Feedback_current_raw
{
public:
  explicit Init_ForceGrasp_Feedback_current_raw(::alicia_d_control_interfaces::action::ForceGrasp_Feedback & msg)
  : msg_(msg)
  {}
  Init_ForceGrasp_Feedback_moving current_raw(::alicia_d_control_interfaces::action::ForceGrasp_Feedback::_current_raw_type arg)
  {
    msg_.current_raw = std::move(arg);
    return Init_ForceGrasp_Feedback_moving(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Feedback msg_;
};

class Init_ForceGrasp_Feedback_load_raw
{
public:
  explicit Init_ForceGrasp_Feedback_load_raw(::alicia_d_control_interfaces::action::ForceGrasp_Feedback & msg)
  : msg_(msg)
  {}
  Init_ForceGrasp_Feedback_current_raw load_raw(::alicia_d_control_interfaces::action::ForceGrasp_Feedback::_load_raw_type arg)
  {
    msg_.load_raw = std::move(arg);
    return Init_ForceGrasp_Feedback_current_raw(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Feedback msg_;
};

class Init_ForceGrasp_Feedback_relative_ticks
{
public:
  explicit Init_ForceGrasp_Feedback_relative_ticks(::alicia_d_control_interfaces::action::ForceGrasp_Feedback & msg)
  : msg_(msg)
  {}
  Init_ForceGrasp_Feedback_load_raw relative_ticks(::alicia_d_control_interfaces::action::ForceGrasp_Feedback::_relative_ticks_type arg)
  {
    msg_.relative_ticks = std::move(arg);
    return Init_ForceGrasp_Feedback_load_raw(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Feedback msg_;
};

class Init_ForceGrasp_Feedback_raw_position
{
public:
  Init_ForceGrasp_Feedback_raw_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ForceGrasp_Feedback_relative_ticks raw_position(::alicia_d_control_interfaces::action::ForceGrasp_Feedback::_raw_position_type arg)
  {
    msg_.raw_position = std::move(arg);
    return Init_ForceGrasp_Feedback_relative_ticks(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::ForceGrasp_Feedback>()
{
  return alicia_d_control_interfaces::action::builder::Init_ForceGrasp_Feedback_raw_position();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_ForceGrasp_SendGoal_Request_goal
{
public:
  explicit Init_ForceGrasp_SendGoal_Request_goal(::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request goal(::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request msg_;
};

class Init_ForceGrasp_SendGoal_Request_goal_id
{
public:
  Init_ForceGrasp_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ForceGrasp_SendGoal_Request_goal goal_id(::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ForceGrasp_SendGoal_Request_goal(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Request>()
{
  return alicia_d_control_interfaces::action::builder::Init_ForceGrasp_SendGoal_Request_goal_id();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_ForceGrasp_SendGoal_Response_stamp
{
public:
  explicit Init_ForceGrasp_SendGoal_Response_stamp(::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response stamp(::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response msg_;
};

class Init_ForceGrasp_SendGoal_Response_accepted
{
public:
  Init_ForceGrasp_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ForceGrasp_SendGoal_Response_stamp accepted(::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ForceGrasp_SendGoal_Response_stamp(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::ForceGrasp_SendGoal_Response>()
{
  return alicia_d_control_interfaces::action::builder::Init_ForceGrasp_SendGoal_Response_accepted();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_ForceGrasp_GetResult_Request_goal_id
{
public:
  Init_ForceGrasp_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request goal_id(::alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::ForceGrasp_GetResult_Request>()
{
  return alicia_d_control_interfaces::action::builder::Init_ForceGrasp_GetResult_Request_goal_id();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_ForceGrasp_GetResult_Response_result
{
public:
  explicit Init_ForceGrasp_GetResult_Response_result(::alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response result(::alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response msg_;
};

class Init_ForceGrasp_GetResult_Response_status
{
public:
  Init_ForceGrasp_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ForceGrasp_GetResult_Response_result status(::alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ForceGrasp_GetResult_Response_result(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::ForceGrasp_GetResult_Response>()
{
  return alicia_d_control_interfaces::action::builder::Init_ForceGrasp_GetResult_Response_status();
}

}  // namespace alicia_d_control_interfaces


namespace alicia_d_control_interfaces
{

namespace action
{

namespace builder
{

class Init_ForceGrasp_FeedbackMessage_feedback
{
public:
  explicit Init_ForceGrasp_FeedbackMessage_feedback(::alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage feedback(::alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage msg_;
};

class Init_ForceGrasp_FeedbackMessage_goal_id
{
public:
  Init_ForceGrasp_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ForceGrasp_FeedbackMessage_feedback goal_id(::alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ForceGrasp_FeedbackMessage_feedback(msg_);
  }

private:
  ::alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::alicia_d_control_interfaces::action::ForceGrasp_FeedbackMessage>()
{
  return alicia_d_control_interfaces::action::builder::Init_ForceGrasp_FeedbackMessage_goal_id();
}

}  // namespace alicia_d_control_interfaces

#endif  // ALICIA_D_CONTROL_INTERFACES__ACTION__DETAIL__FORCE_GRASP__BUILDER_HPP_
