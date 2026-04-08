// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:srv/OperateMarker.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__OPERATE_MARKER__BUILDER_HPP_
#define HRIC_MSGS__SRV__DETAIL__OPERATE_MARKER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/srv/detail/operate_marker__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_OperateMarker_Request_name
{
public:
  Init_OperateMarker_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hric_msgs::srv::OperateMarker_Request name(::hric_msgs::srv::OperateMarker_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::OperateMarker_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::OperateMarker_Request>()
{
  return hric_msgs::srv::builder::Init_OperateMarker_Request_name();
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_OperateMarker_Response_marker
{
public:
  explicit Init_OperateMarker_Response_marker(::hric_msgs::srv::OperateMarker_Response & msg)
  : msg_(msg)
  {}
  ::hric_msgs::srv::OperateMarker_Response marker(::hric_msgs::srv::OperateMarker_Response::_marker_type arg)
  {
    msg_.marker = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::OperateMarker_Response msg_;
};

class Init_OperateMarker_Response_message
{
public:
  explicit Init_OperateMarker_Response_message(::hric_msgs::srv::OperateMarker_Response & msg)
  : msg_(msg)
  {}
  Init_OperateMarker_Response_marker message(::hric_msgs::srv::OperateMarker_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_OperateMarker_Response_marker(msg_);
  }

private:
  ::hric_msgs::srv::OperateMarker_Response msg_;
};

class Init_OperateMarker_Response_success
{
public:
  Init_OperateMarker_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OperateMarker_Response_message success(::hric_msgs::srv::OperateMarker_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_OperateMarker_Response_message(msg_);
  }

private:
  ::hric_msgs::srv::OperateMarker_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::OperateMarker_Response>()
{
  return hric_msgs::srv::builder::Init_OperateMarker_Response_success();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__OPERATE_MARKER__BUILDER_HPP_
