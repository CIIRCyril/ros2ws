// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:action/NavToPose.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__ACTION__DETAIL__NAV_TO_POSE__BUILDER_HPP_
#define HRIC_MSGS__ACTION__DETAIL__NAV_TO_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/action/detail/nav_to_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace action
{

namespace builder
{

class Init_NavToPose_Goal_pose
{
public:
  Init_NavToPose_Goal_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hric_msgs::action::NavToPose_Goal pose(::hric_msgs::action::NavToPose_Goal::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::action::NavToPose_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::action::NavToPose_Goal>()
{
  return hric_msgs::action::builder::Init_NavToPose_Goal_pose();
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace action
{

namespace builder
{

class Init_NavToPose_Result_error_code
{
public:
  Init_NavToPose_Result_error_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hric_msgs::action::NavToPose_Result error_code(::hric_msgs::action::NavToPose_Result::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::action::NavToPose_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::action::NavToPose_Result>()
{
  return hric_msgs::action::builder::Init_NavToPose_Result_error_code();
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace action
{


}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::action::NavToPose_Feedback>()
{
  return ::hric_msgs::action::NavToPose_Feedback(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace action
{

namespace builder
{

class Init_NavToPose_SendGoal_Request_goal
{
public:
  explicit Init_NavToPose_SendGoal_Request_goal(::hric_msgs::action::NavToPose_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::hric_msgs::action::NavToPose_SendGoal_Request goal(::hric_msgs::action::NavToPose_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::action::NavToPose_SendGoal_Request msg_;
};

class Init_NavToPose_SendGoal_Request_goal_id
{
public:
  Init_NavToPose_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavToPose_SendGoal_Request_goal goal_id(::hric_msgs::action::NavToPose_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavToPose_SendGoal_Request_goal(msg_);
  }

private:
  ::hric_msgs::action::NavToPose_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::action::NavToPose_SendGoal_Request>()
{
  return hric_msgs::action::builder::Init_NavToPose_SendGoal_Request_goal_id();
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace action
{

namespace builder
{

class Init_NavToPose_SendGoal_Response_stamp
{
public:
  explicit Init_NavToPose_SendGoal_Response_stamp(::hric_msgs::action::NavToPose_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::hric_msgs::action::NavToPose_SendGoal_Response stamp(::hric_msgs::action::NavToPose_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::action::NavToPose_SendGoal_Response msg_;
};

class Init_NavToPose_SendGoal_Response_accepted
{
public:
  Init_NavToPose_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavToPose_SendGoal_Response_stamp accepted(::hric_msgs::action::NavToPose_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_NavToPose_SendGoal_Response_stamp(msg_);
  }

private:
  ::hric_msgs::action::NavToPose_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::action::NavToPose_SendGoal_Response>()
{
  return hric_msgs::action::builder::Init_NavToPose_SendGoal_Response_accepted();
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace action
{

namespace builder
{

class Init_NavToPose_GetResult_Request_goal_id
{
public:
  Init_NavToPose_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hric_msgs::action::NavToPose_GetResult_Request goal_id(::hric_msgs::action::NavToPose_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::action::NavToPose_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::action::NavToPose_GetResult_Request>()
{
  return hric_msgs::action::builder::Init_NavToPose_GetResult_Request_goal_id();
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace action
{

namespace builder
{

class Init_NavToPose_GetResult_Response_result
{
public:
  explicit Init_NavToPose_GetResult_Response_result(::hric_msgs::action::NavToPose_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::hric_msgs::action::NavToPose_GetResult_Response result(::hric_msgs::action::NavToPose_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::action::NavToPose_GetResult_Response msg_;
};

class Init_NavToPose_GetResult_Response_status
{
public:
  Init_NavToPose_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavToPose_GetResult_Response_result status(::hric_msgs::action::NavToPose_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_NavToPose_GetResult_Response_result(msg_);
  }

private:
  ::hric_msgs::action::NavToPose_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::action::NavToPose_GetResult_Response>()
{
  return hric_msgs::action::builder::Init_NavToPose_GetResult_Response_status();
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace action
{

namespace builder
{

class Init_NavToPose_FeedbackMessage_feedback
{
public:
  explicit Init_NavToPose_FeedbackMessage_feedback(::hric_msgs::action::NavToPose_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::hric_msgs::action::NavToPose_FeedbackMessage feedback(::hric_msgs::action::NavToPose_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::action::NavToPose_FeedbackMessage msg_;
};

class Init_NavToPose_FeedbackMessage_goal_id
{
public:
  Init_NavToPose_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavToPose_FeedbackMessage_feedback goal_id(::hric_msgs::action::NavToPose_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavToPose_FeedbackMessage_feedback(msg_);
  }

private:
  ::hric_msgs::action::NavToPose_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::action::NavToPose_FeedbackMessage>()
{
  return hric_msgs::action::builder::Init_NavToPose_FeedbackMessage_goal_id();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__ACTION__DETAIL__NAV_TO_POSE__BUILDER_HPP_
