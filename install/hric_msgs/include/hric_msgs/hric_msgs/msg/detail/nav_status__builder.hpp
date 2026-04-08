// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:msg/NavStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__NAV_STATUS__BUILDER_HPP_
#define HRIC_MSGS__MSG__DETAIL__NAV_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/msg/detail/nav_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace msg
{

namespace builder
{

class Init_NavStatus_error_code
{
public:
  explicit Init_NavStatus_error_code(::hric_msgs::msg::NavStatus & msg)
  : msg_(msg)
  {}
  ::hric_msgs::msg::NavStatus error_code(::hric_msgs::msg::NavStatus::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::msg::NavStatus msg_;
};

class Init_NavStatus_status
{
public:
  Init_NavStatus_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavStatus_error_code status(::hric_msgs::msg::NavStatus::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_NavStatus_error_code(msg_);
  }

private:
  ::hric_msgs::msg::NavStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::msg::NavStatus>()
{
  return hric_msgs::msg::builder::Init_NavStatus_status();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__NAV_STATUS__BUILDER_HPP_
