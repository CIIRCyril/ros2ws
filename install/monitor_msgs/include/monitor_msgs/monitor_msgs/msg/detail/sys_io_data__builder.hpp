// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from monitor_msgs:msg/SysIoData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_IO_DATA__BUILDER_HPP_
#define MONITOR_MSGS__MSG__DETAIL__SYS_IO_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "monitor_msgs/msg/detail/sys_io_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace monitor_msgs
{

namespace msg
{

namespace builder
{

class Init_SysIoData_disk_write
{
public:
  explicit Init_SysIoData_disk_write(::monitor_msgs::msg::SysIoData & msg)
  : msg_(msg)
  {}
  ::monitor_msgs::msg::SysIoData disk_write(::monitor_msgs::msg::SysIoData::_disk_write_type arg)
  {
    msg_.disk_write = std::move(arg);
    return std::move(msg_);
  }

private:
  ::monitor_msgs::msg::SysIoData msg_;
};

class Init_SysIoData_disk_read
{
public:
  explicit Init_SysIoData_disk_read(::monitor_msgs::msg::SysIoData & msg)
  : msg_(msg)
  {}
  Init_SysIoData_disk_write disk_read(::monitor_msgs::msg::SysIoData::_disk_read_type arg)
  {
    msg_.disk_read = std::move(arg);
    return Init_SysIoData_disk_write(msg_);
  }

private:
  ::monitor_msgs::msg::SysIoData msg_;
};

class Init_SysIoData_timestamp
{
public:
  Init_SysIoData_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SysIoData_disk_read timestamp(::monitor_msgs::msg::SysIoData::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_SysIoData_disk_read(msg_);
  }

private:
  ::monitor_msgs::msg::SysIoData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::monitor_msgs::msg::SysIoData>()
{
  return monitor_msgs::msg::builder::Init_SysIoData_timestamp();
}

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_IO_DATA__BUILDER_HPP_
