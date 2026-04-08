// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:msg/FloatBaseRPYZ.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__BUILDER_HPP_
#define HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/msg/detail/float_base_rpyz__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace msg
{

namespace builder
{

class Init_FloatBaseRPYZ_z
{
public:
  explicit Init_FloatBaseRPYZ_z(::hric_msgs::msg::FloatBaseRPYZ & msg)
  : msg_(msg)
  {}
  ::hric_msgs::msg::FloatBaseRPYZ z(::hric_msgs::msg::FloatBaseRPYZ::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::msg::FloatBaseRPYZ msg_;
};

class Init_FloatBaseRPYZ_yaw
{
public:
  explicit Init_FloatBaseRPYZ_yaw(::hric_msgs::msg::FloatBaseRPYZ & msg)
  : msg_(msg)
  {}
  Init_FloatBaseRPYZ_z yaw(::hric_msgs::msg::FloatBaseRPYZ::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_FloatBaseRPYZ_z(msg_);
  }

private:
  ::hric_msgs::msg::FloatBaseRPYZ msg_;
};

class Init_FloatBaseRPYZ_pitch
{
public:
  explicit Init_FloatBaseRPYZ_pitch(::hric_msgs::msg::FloatBaseRPYZ & msg)
  : msg_(msg)
  {}
  Init_FloatBaseRPYZ_yaw pitch(::hric_msgs::msg::FloatBaseRPYZ::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_FloatBaseRPYZ_yaw(msg_);
  }

private:
  ::hric_msgs::msg::FloatBaseRPYZ msg_;
};

class Init_FloatBaseRPYZ_roll
{
public:
  Init_FloatBaseRPYZ_roll()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FloatBaseRPYZ_pitch roll(::hric_msgs::msg::FloatBaseRPYZ::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_FloatBaseRPYZ_pitch(msg_);
  }

private:
  ::hric_msgs::msg::FloatBaseRPYZ msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::msg::FloatBaseRPYZ>()
{
  return hric_msgs::msg::builder::Init_FloatBaseRPYZ_roll();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__BUILDER_HPP_
