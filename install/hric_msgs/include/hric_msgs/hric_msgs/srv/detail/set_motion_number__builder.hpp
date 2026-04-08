// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:srv/SetMotionNumber.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_MOTION_NUMBER__BUILDER_HPP_
#define HRIC_MSGS__SRV__DETAIL__SET_MOTION_NUMBER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/srv/detail/set_motion_number__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_SetMotionNumber_Request_motion_number
{
public:
  explicit Init_SetMotionNumber_Request_motion_number(::hric_msgs::srv::SetMotionNumber_Request & msg)
  : msg_(msg)
  {}
  ::hric_msgs::srv::SetMotionNumber_Request motion_number(::hric_msgs::srv::SetMotionNumber_Request::_motion_number_type arg)
  {
    msg_.motion_number = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::SetMotionNumber_Request msg_;
};

class Init_SetMotionNumber_Request_is_motion
{
public:
  Init_SetMotionNumber_Request_is_motion()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetMotionNumber_Request_motion_number is_motion(::hric_msgs::srv::SetMotionNumber_Request::_is_motion_type arg)
  {
    msg_.is_motion = std::move(arg);
    return Init_SetMotionNumber_Request_motion_number(msg_);
  }

private:
  ::hric_msgs::srv::SetMotionNumber_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::SetMotionNumber_Request>()
{
  return hric_msgs::srv::builder::Init_SetMotionNumber_Request_is_motion();
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_SetMotionNumber_Response_success
{
public:
  Init_SetMotionNumber_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hric_msgs::srv::SetMotionNumber_Response success(::hric_msgs::srv::SetMotionNumber_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::SetMotionNumber_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::SetMotionNumber_Response>()
{
  return hric_msgs::srv::builder::Init_SetMotionNumber_Response_success();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__SET_MOTION_NUMBER__BUILDER_HPP_
