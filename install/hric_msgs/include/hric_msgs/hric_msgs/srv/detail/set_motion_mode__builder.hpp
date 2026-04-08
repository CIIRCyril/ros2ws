// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:srv/SetMotionMode.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_MOTION_MODE__BUILDER_HPP_
#define HRIC_MSGS__SRV__DETAIL__SET_MOTION_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/srv/detail/set_motion_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_SetMotionMode_Request_is_need_swing_arm
{
public:
  explicit Init_SetMotionMode_Request_is_need_swing_arm(::hric_msgs::srv::SetMotionMode_Request & msg)
  : msg_(msg)
  {}
  ::hric_msgs::srv::SetMotionMode_Request is_need_swing_arm(::hric_msgs::srv::SetMotionMode_Request::_is_need_swing_arm_type arg)
  {
    msg_.is_need_swing_arm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::SetMotionMode_Request msg_;
};

class Init_SetMotionMode_Request_walk_mode_request
{
public:
  Init_SetMotionMode_Request_walk_mode_request()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetMotionMode_Request_is_need_swing_arm walk_mode_request(::hric_msgs::srv::SetMotionMode_Request::_walk_mode_request_type arg)
  {
    msg_.walk_mode_request = std::move(arg);
    return Init_SetMotionMode_Request_is_need_swing_arm(msg_);
  }

private:
  ::hric_msgs::srv::SetMotionMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::SetMotionMode_Request>()
{
  return hric_msgs::srv::builder::Init_SetMotionMode_Request_walk_mode_request();
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_SetMotionMode_Response_error_code
{
public:
  explicit Init_SetMotionMode_Response_error_code(::hric_msgs::srv::SetMotionMode_Response & msg)
  : msg_(msg)
  {}
  ::hric_msgs::srv::SetMotionMode_Response error_code(::hric_msgs::srv::SetMotionMode_Response::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::SetMotionMode_Response msg_;
};

class Init_SetMotionMode_Response_success
{
public:
  Init_SetMotionMode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetMotionMode_Response_error_code success(::hric_msgs::srv::SetMotionMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetMotionMode_Response_error_code(msg_);
  }

private:
  ::hric_msgs::srv::SetMotionMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::SetMotionMode_Response>()
{
  return hric_msgs::srv::builder::Init_SetMotionMode_Response_success();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__SET_MOTION_MODE__BUILDER_HPP_
