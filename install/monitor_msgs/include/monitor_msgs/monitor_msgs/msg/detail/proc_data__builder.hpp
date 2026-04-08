// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from monitor_msgs:msg/ProcData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_DATA__BUILDER_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "monitor_msgs/msg/detail/proc_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace monitor_msgs
{

namespace msg
{

namespace builder
{

class Init_ProcData_mem_data
{
public:
  explicit Init_ProcData_mem_data(::monitor_msgs::msg::ProcData & msg)
  : msg_(msg)
  {}
  ::monitor_msgs::msg::ProcData mem_data(::monitor_msgs::msg::ProcData::_mem_data_type arg)
  {
    msg_.mem_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::monitor_msgs::msg::ProcData msg_;
};

class Init_ProcData_io_data
{
public:
  explicit Init_ProcData_io_data(::monitor_msgs::msg::ProcData & msg)
  : msg_(msg)
  {}
  Init_ProcData_mem_data io_data(::monitor_msgs::msg::ProcData::_io_data_type arg)
  {
    msg_.io_data = std::move(arg);
    return Init_ProcData_mem_data(msg_);
  }

private:
  ::monitor_msgs::msg::ProcData msg_;
};

class Init_ProcData_cpu_data
{
public:
  explicit Init_ProcData_cpu_data(::monitor_msgs::msg::ProcData & msg)
  : msg_(msg)
  {}
  Init_ProcData_io_data cpu_data(::monitor_msgs::msg::ProcData::_cpu_data_type arg)
  {
    msg_.cpu_data = std::move(arg);
    return Init_ProcData_io_data(msg_);
  }

private:
  ::monitor_msgs::msg::ProcData msg_;
};

class Init_ProcData_active
{
public:
  explicit Init_ProcData_active(::monitor_msgs::msg::ProcData & msg)
  : msg_(msg)
  {}
  Init_ProcData_cpu_data active(::monitor_msgs::msg::ProcData::_active_type arg)
  {
    msg_.active = std::move(arg);
    return Init_ProcData_cpu_data(msg_);
  }

private:
  ::monitor_msgs::msg::ProcData msg_;
};

class Init_ProcData_name
{
public:
  explicit Init_ProcData_name(::monitor_msgs::msg::ProcData & msg)
  : msg_(msg)
  {}
  Init_ProcData_active name(::monitor_msgs::msg::ProcData::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ProcData_active(msg_);
  }

private:
  ::monitor_msgs::msg::ProcData msg_;
};

class Init_ProcData_pid
{
public:
  Init_ProcData_pid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcData_name pid(::monitor_msgs::msg::ProcData::_pid_type arg)
  {
    msg_.pid = std::move(arg);
    return Init_ProcData_name(msg_);
  }

private:
  ::monitor_msgs::msg::ProcData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::monitor_msgs::msg::ProcData>()
{
  return monitor_msgs::msg::builder::Init_ProcData_pid();
}

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_DATA__BUILDER_HPP_
