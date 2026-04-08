// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hric_msgs:srv/ListMarkers.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__LIST_MARKERS__BUILDER_HPP_
#define HRIC_MSGS__SRV__DETAIL__LIST_MARKERS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hric_msgs/srv/detail/list_markers__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hric_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::ListMarkers_Request>()
{
  return ::hric_msgs::srv::ListMarkers_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace hric_msgs


namespace hric_msgs
{

namespace srv
{

namespace builder
{

class Init_ListMarkers_Response_markers
{
public:
  Init_ListMarkers_Response_markers()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hric_msgs::srv::ListMarkers_Response markers(::hric_msgs::srv::ListMarkers_Response::_markers_type arg)
  {
    msg_.markers = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hric_msgs::srv::ListMarkers_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hric_msgs::srv::ListMarkers_Response>()
{
  return hric_msgs::srv::builder::Init_ListMarkers_Response_markers();
}

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__LIST_MARKERS__BUILDER_HPP_
