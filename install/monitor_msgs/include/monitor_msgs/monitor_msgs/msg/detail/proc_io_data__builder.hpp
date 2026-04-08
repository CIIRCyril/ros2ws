// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from monitor_msgs:msg/ProcIoData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_IO_DATA__BUILDER_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_IO_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "monitor_msgs/msg/detail/proc_io_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace monitor_msgs
{

namespace msg
{

namespace builder
{

class Init_ProcIoData_total_write
{
public:
  explicit Init_ProcIoData_total_write(::monitor_msgs::msg::ProcIoData & msg)
  : msg_(msg)
  {}
  ::monitor_msgs::msg::ProcIoData total_write(::monitor_msgs::msg::ProcIoData::_total_write_type arg)
  {
    msg_.total_write = std::move(arg);
    return std::move(msg_);
  }

private:
  ::monitor_msgs::msg::ProcIoData msg_;
};

class Init_ProcIoData_total_read
{
public:
  explicit Init_ProcIoData_total_read(::monitor_msgs::msg::ProcIoData & msg)
  : msg_(msg)
  {}
  Init_ProcIoData_total_write total_read(::monitor_msgs::msg::ProcIoData::_total_read_type arg)
  {
    msg_.total_read = std::move(arg);
    return Init_ProcIoData_total_write(msg_);
  }

private:
  ::monitor_msgs::msg::ProcIoData msg_;
};

class Init_ProcIoData_write
{
public:
  explicit Init_ProcIoData_write(::monitor_msgs::msg::ProcIoData & msg)
  : msg_(msg)
  {}
  Init_ProcIoData_total_read write(::monitor_msgs::msg::ProcIoData::_write_type arg)
  {
    msg_.write = std::move(arg);
    return Init_ProcIoData_total_read(msg_);
  }

private:
  ::monitor_msgs::msg::ProcIoData msg_;
};

class Init_ProcIoData_read
{
public:
  Init_ProcIoData_read()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcIoData_write read(::monitor_msgs::msg::ProcIoData::_read_type arg)
  {
    msg_.read = std::move(arg);
    return Init_ProcIoData_write(msg_);
  }

private:
  ::monitor_msgs::msg::ProcIoData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::monitor_msgs::msg::ProcIoData>()
{
  return monitor_msgs::msg::builder::Init_ProcIoData_read();
}

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_IO_DATA__BUILDER_HPP_
