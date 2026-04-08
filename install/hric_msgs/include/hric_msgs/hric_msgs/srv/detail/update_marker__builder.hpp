// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:srv/UpdateMarker.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__UPDATE_MARKER__BUILDER_HPP_
#define HRIC_MSGS__SRV__DETAIL__UPDATE_MARKER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/srv/detail/update_marker__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_UpdateMarker_Request_pose
{
public:
  explicit Init_UpdateMarker_Request_pose(::hric_msgs::srv::UpdateMarker_Request & msg)
  : msg_(msg)
  {}
  ::hric_msgs::srv::UpdateMarker_Request pose(::hric_msgs::srv::UpdateMarker_Request::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::UpdateMarker_Request msg_;
};

class Init_UpdateMarker_Request_floor
{
public:
  explicit Init_UpdateMarker_Request_floor(::hric_msgs::srv::UpdateMarker_Request & msg)
  : msg_(msg)
  {}
  Init_UpdateMarker_Request_pose floor(::hric_msgs::srv::UpdateMarker_Request::_floor_type arg)
  {
    msg_.floor = std::move(arg);
    return Init_UpdateMarker_Request_pose(msg_);
  }

private:
  ::hric_msgs::srv::UpdateMarker_Request msg_;
};

class Init_UpdateMarker_Request_map_id
{
public:
  explicit Init_UpdateMarker_Request_map_id(::hric_msgs::srv::UpdateMarker_Request & msg)
  : msg_(msg)
  {}
  Init_UpdateMarker_Request_floor map_id(::hric_msgs::srv::UpdateMarker_Request::_map_id_type arg)
  {
    msg_.map_id = std::move(arg);
    return Init_UpdateMarker_Request_floor(msg_);
  }

private:
  ::hric_msgs::srv::UpdateMarker_Request msg_;
};

class Init_UpdateMarker_Request_name
{
public:
  Init_UpdateMarker_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdateMarker_Request_map_id name(::hric_msgs::srv::UpdateMarker_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_UpdateMarker_Request_map_id(msg_);
  }

private:
  ::hric_msgs::srv::UpdateMarker_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::UpdateMarker_Request>()
{
  return hric_msgs::srv::builder::Init_UpdateMarker_Request_name();
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_UpdateMarker_Response_marker_new
{
public:
  explicit Init_UpdateMarker_Response_marker_new(::hric_msgs::srv::UpdateMarker_Response & msg)
  : msg_(msg)
  {}
  ::hric_msgs::srv::UpdateMarker_Response marker_new(::hric_msgs::srv::UpdateMarker_Response::_marker_new_type arg)
  {
    msg_.marker_new = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::UpdateMarker_Response msg_;
};

class Init_UpdateMarker_Response_marker_old
{
public:
  explicit Init_UpdateMarker_Response_marker_old(::hric_msgs::srv::UpdateMarker_Response & msg)
  : msg_(msg)
  {}
  Init_UpdateMarker_Response_marker_new marker_old(::hric_msgs::srv::UpdateMarker_Response::_marker_old_type arg)
  {
    msg_.marker_old = std::move(arg);
    return Init_UpdateMarker_Response_marker_new(msg_);
  }

private:
  ::hric_msgs::srv::UpdateMarker_Response msg_;
};

class Init_UpdateMarker_Response_message
{
public:
  explicit Init_UpdateMarker_Response_message(::hric_msgs::srv::UpdateMarker_Response & msg)
  : msg_(msg)
  {}
  Init_UpdateMarker_Response_marker_old message(::hric_msgs::srv::UpdateMarker_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_UpdateMarker_Response_marker_old(msg_);
  }

private:
  ::hric_msgs::srv::UpdateMarker_Response msg_;
};

class Init_UpdateMarker_Response_success
{
public:
  Init_UpdateMarker_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdateMarker_Response_message success(::hric_msgs::srv::UpdateMarker_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_UpdateMarker_Response_message(msg_);
  }

private:
  ::hric_msgs::srv::UpdateMarker_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::UpdateMarker_Response>()
{
  return hric_msgs::srv::builder::Init_UpdateMarker_Response_success();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__UPDATE_MARKER__BUILDER_HPP_
