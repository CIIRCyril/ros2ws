// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:msg/MotionStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__MOTION_STATUS__BUILDER_HPP_
#define HRIC_MSGS__MSG__DETAIL__MOTION_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/msg/detail/motion_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace msg
{

namespace builder
{

class Init_MotionStatus_error_code
{
public:
  explicit Init_MotionStatus_error_code(::hric_msgs::msg::MotionStatus & msg)
  : msg_(msg)
  {}
  ::hric_msgs::msg::MotionStatus error_code(::hric_msgs::msg::MotionStatus::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::msg::MotionStatus msg_;
};

class Init_MotionStatus_is_swing_arm
{
public:
  explicit Init_MotionStatus_is_swing_arm(::hric_msgs::msg::MotionStatus & msg)
  : msg_(msg)
  {}
  Init_MotionStatus_error_code is_swing_arm(::hric_msgs::msg::MotionStatus::_is_swing_arm_type arg)
  {
    msg_.is_swing_arm = std::move(arg);
    return Init_MotionStatus_error_code(msg_);
  }

private:
  ::hric_msgs::msg::MotionStatus msg_;
};

class Init_MotionStatus_is_console_control
{
public:
  explicit Init_MotionStatus_is_console_control(::hric_msgs::msg::MotionStatus & msg)
  : msg_(msg)
  {}
  Init_MotionStatus_is_swing_arm is_console_control(::hric_msgs::msg::MotionStatus::_is_console_control_type arg)
  {
    msg_.is_console_control = std::move(arg);
    return Init_MotionStatus_is_swing_arm(msg_);
  }

private:
  ::hric_msgs::msg::MotionStatus msg_;
};

class Init_MotionStatus_walk_mode
{
public:
  explicit Init_MotionStatus_walk_mode(::hric_msgs::msg::MotionStatus & msg)
  : msg_(msg)
  {}
  Init_MotionStatus_is_console_control walk_mode(::hric_msgs::msg::MotionStatus::_walk_mode_type arg)
  {
    msg_.walk_mode = std::move(arg);
    return Init_MotionStatus_is_console_control(msg_);
  }

private:
  ::hric_msgs::msg::MotionStatus msg_;
};

class Init_MotionStatus_velocity
{
public:
  explicit Init_MotionStatus_velocity(::hric_msgs::msg::MotionStatus & msg)
  : msg_(msg)
  {}
  Init_MotionStatus_walk_mode velocity(::hric_msgs::msg::MotionStatus::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_MotionStatus_walk_mode(msg_);
  }

private:
  ::hric_msgs::msg::MotionStatus msg_;
};

class Init_MotionStatus_header
{
public:
  Init_MotionStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotionStatus_velocity header(::hric_msgs::msg::MotionStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotionStatus_velocity(msg_);
  }

private:
  ::hric_msgs::msg::MotionStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::msg::MotionStatus>()
{
  return hric_msgs::msg::builder::Init_MotionStatus_header();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__MOTION_STATUS__BUILDER_HPP_
