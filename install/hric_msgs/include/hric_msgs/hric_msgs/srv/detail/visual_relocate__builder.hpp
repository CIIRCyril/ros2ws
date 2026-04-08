// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:srv/VisualRelocate.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__VISUAL_RELOCATE__BUILDER_HPP_
#define HRIC_MSGS__SRV__DETAIL__VISUAL_RELOCATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/srv/detail/visual_relocate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_VisualRelocate_Request_match_type
{
public:
  explicit Init_VisualRelocate_Request_match_type(::hric_msgs::srv::VisualRelocate_Request & msg)
  : msg_(msg)
  {}
  ::hric_msgs::srv::VisualRelocate_Request match_type(::hric_msgs::srv::VisualRelocate_Request::_match_type_type arg)
  {
    msg_.match_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::VisualRelocate_Request msg_;
};

class Init_VisualRelocate_Request_pose_ref
{
public:
  Init_VisualRelocate_Request_pose_ref()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VisualRelocate_Request_match_type pose_ref(::hric_msgs::srv::VisualRelocate_Request::_pose_ref_type arg)
  {
    msg_.pose_ref = std::move(arg);
    return Init_VisualRelocate_Request_match_type(msg_);
  }

private:
  ::hric_msgs::srv::VisualRelocate_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::VisualRelocate_Request>()
{
  return hric_msgs::srv::builder::Init_VisualRelocate_Request_pose_ref();
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_VisualRelocate_Response_message
{
public:
  explicit Init_VisualRelocate_Response_message(::hric_msgs::srv::VisualRelocate_Response & msg)
  : msg_(msg)
  {}
  ::hric_msgs::srv::VisualRelocate_Response message(::hric_msgs::srv::VisualRelocate_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::VisualRelocate_Response msg_;
};

class Init_VisualRelocate_Response_error_code
{
public:
  explicit Init_VisualRelocate_Response_error_code(::hric_msgs::srv::VisualRelocate_Response & msg)
  : msg_(msg)
  {}
  Init_VisualRelocate_Response_message error_code(::hric_msgs::srv::VisualRelocate_Response::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_VisualRelocate_Response_message(msg_);
  }

private:
  ::hric_msgs::srv::VisualRelocate_Response msg_;
};

class Init_VisualRelocate_Response_success
{
public:
  explicit Init_VisualRelocate_Response_success(::hric_msgs::srv::VisualRelocate_Response & msg)
  : msg_(msg)
  {}
  Init_VisualRelocate_Response_error_code success(::hric_msgs::srv::VisualRelocate_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_VisualRelocate_Response_error_code(msg_);
  }

private:
  ::hric_msgs::srv::VisualRelocate_Response msg_;
};

class Init_VisualRelocate_Response_pose_robot
{
public:
  Init_VisualRelocate_Response_pose_robot()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VisualRelocate_Response_success pose_robot(::hric_msgs::srv::VisualRelocate_Response::_pose_robot_type arg)
  {
    msg_.pose_robot = std::move(arg);
    return Init_VisualRelocate_Response_success(msg_);
  }

private:
  ::hric_msgs::srv::VisualRelocate_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::VisualRelocate_Response>()
{
  return hric_msgs::srv::builder::Init_VisualRelocate_Response_pose_robot();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__VISUAL_RELOCATE__BUILDER_HPP_
