// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:srv/SetGoal.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_GOAL__BUILDER_HPP_
#define HRIC_MSGS__SRV__DETAIL__SET_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/srv/detail/set_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_SetGoal_Request_goal
{
public:
  Init_SetGoal_Request_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hric_msgs::srv::SetGoal_Request goal(::hric_msgs::srv::SetGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::SetGoal_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::SetGoal_Request>()
{
  return hric_msgs::srv::builder::Init_SetGoal_Request_goal();
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_SetGoal_Response_error_code
{
public:
  explicit Init_SetGoal_Response_error_code(::hric_msgs::srv::SetGoal_Response & msg)
  : msg_(msg)
  {}
  ::hric_msgs::srv::SetGoal_Response error_code(::hric_msgs::srv::SetGoal_Response::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::SetGoal_Response msg_;
};

class Init_SetGoal_Response_message
{
public:
  explicit Init_SetGoal_Response_message(::hric_msgs::srv::SetGoal_Response & msg)
  : msg_(msg)
  {}
  Init_SetGoal_Response_error_code message(::hric_msgs::srv::SetGoal_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_SetGoal_Response_error_code(msg_);
  }

private:
  ::hric_msgs::srv::SetGoal_Response msg_;
};

class Init_SetGoal_Response_success
{
public:
  Init_SetGoal_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetGoal_Response_message success(::hric_msgs::srv::SetGoal_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetGoal_Response_message(msg_);
  }

private:
  ::hric_msgs::srv::SetGoal_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::SetGoal_Response>()
{
  return hric_msgs::srv::builder::Init_SetGoal_Response_success();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__SET_GOAL__BUILDER_HPP_
