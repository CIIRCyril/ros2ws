// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:msg/MarkerInfo.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__MARKER_INFO__BUILDER_HPP_
#define HRIC_MSGS__MSG__DETAIL__MARKER_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/msg/detail/marker_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace msg
{

namespace builder
{

class Init_MarkerInfo_pose
{
public:
  explicit Init_MarkerInfo_pose(::hric_msgs::msg::MarkerInfo & msg)
  : msg_(msg)
  {}
  ::hric_msgs::msg::MarkerInfo pose(::hric_msgs::msg::MarkerInfo::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::msg::MarkerInfo msg_;
};

class Init_MarkerInfo_floor
{
public:
  explicit Init_MarkerInfo_floor(::hric_msgs::msg::MarkerInfo & msg)
  : msg_(msg)
  {}
  Init_MarkerInfo_pose floor(::hric_msgs::msg::MarkerInfo::_floor_type arg)
  {
    msg_.floor = std::move(arg);
    return Init_MarkerInfo_pose(msg_);
  }

private:
  ::hric_msgs::msg::MarkerInfo msg_;
};

class Init_MarkerInfo_map_id
{
public:
  explicit Init_MarkerInfo_map_id(::hric_msgs::msg::MarkerInfo & msg)
  : msg_(msg)
  {}
  Init_MarkerInfo_floor map_id(::hric_msgs::msg::MarkerInfo::_map_id_type arg)
  {
    msg_.map_id = std::move(arg);
    return Init_MarkerInfo_floor(msg_);
  }

private:
  ::hric_msgs::msg::MarkerInfo msg_;
};

class Init_MarkerInfo_name
{
public:
  Init_MarkerInfo_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MarkerInfo_map_id name(::hric_msgs::msg::MarkerInfo::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_MarkerInfo_map_id(msg_);
  }

private:
  ::hric_msgs::msg::MarkerInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::msg::MarkerInfo>()
{
  return hric_msgs::msg::builder::Init_MarkerInfo_name();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__MARKER_INFO__BUILDER_HPP_
