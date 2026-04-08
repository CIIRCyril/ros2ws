// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsys_msgs:srv/GetSerialNumber.idl
// generated code does not contain a copyright notice

#ifndef XSYS_MSGS__SRV__DETAIL__GET_SERIAL_NUMBER__BUILDER_HPP_
#define XSYS_MSGS__SRV__DETAIL__GET_SERIAL_NUMBER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xsys_msgs/srv/detail/get_serial_number__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xsys_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsys_msgs::srv::GetSerialNumber_Request>()
{
  return ::xsys_msgs::srv::GetSerialNumber_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace xsys_msgs


namespace xsys_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSerialNumber_Response_serial_number
{
public:
  Init_GetSerialNumber_Response_serial_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::xsys_msgs::srv::GetSerialNumber_Response serial_number(::xsys_msgs::srv::GetSerialNumber_Response::_serial_number_type arg)
  {
    msg_.serial_number = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsys_msgs::srv::GetSerialNumber_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsys_msgs::srv::GetSerialNumber_Response>()
{
  return xsys_msgs::srv::builder::Init_GetSerialNumber_Response_serial_number();
}

}  // namespace xsys_msgs

#endif  // XSYS_MSGS__SRV__DETAIL__GET_SERIAL_NUMBER__BUILDER_HPP_
