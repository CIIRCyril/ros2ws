// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:msg/LocStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__LOC_STATUS__BUILDER_HPP_
#define HRIC_MSGS__MSG__DETAIL__LOC_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/msg/detail/loc_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace msg
{

namespace builder
{

class Init_LocStatus_pose
{
public:
  explicit Init_LocStatus_pose(::hric_msgs::msg::LocStatus & msg)
  : msg_(msg)
  {}
  ::hric_msgs::msg::LocStatus pose(::hric_msgs::msg::LocStatus::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::msg::LocStatus msg_;
};

class Init_LocStatus_error_code
{
public:
  explicit Init_LocStatus_error_code(::hric_msgs::msg::LocStatus & msg)
  : msg_(msg)
  {}
  Init_LocStatus_pose error_code(::hric_msgs::msg::LocStatus::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_LocStatus_pose(msg_);
  }

private:
  ::hric_msgs::msg::LocStatus msg_;
};

class Init_LocStatus_confidence
{
public:
  explicit Init_LocStatus_confidence(::hric_msgs::msg::LocStatus & msg)
  : msg_(msg)
  {}
  Init_LocStatus_error_code confidence(::hric_msgs::msg::LocStatus::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_LocStatus_error_code(msg_);
  }

private:
  ::hric_msgs::msg::LocStatus msg_;
};

class Init_LocStatus_status
{
public:
  Init_LocStatus_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LocStatus_confidence status(::hric_msgs::msg::LocStatus::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_LocStatus_confidence(msg_);
  }

private:
  ::hric_msgs::msg::LocStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::msg::LocStatus>()
{
  return hric_msgs::msg::builder::Init_LocStatus_status();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__LOC_STATUS__BUILDER_HPP_
