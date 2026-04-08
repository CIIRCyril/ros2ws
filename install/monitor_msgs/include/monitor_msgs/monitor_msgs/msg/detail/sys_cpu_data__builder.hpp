// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from monitor_msgs:msg/SysCpuData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATA__BUILDER_HPP_
#define MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "monitor_msgs/msg/detail/sys_cpu_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace monitor_msgs
{

namespace msg
{

namespace builder
{

class Init_SysCpuData_proc_array
{
public:
  explicit Init_SysCpuData_proc_array(::monitor_msgs::msg::SysCpuData & msg)
  : msg_(msg)
  {}
  ::monitor_msgs::msg::SysCpuData proc_array(::monitor_msgs::msg::SysCpuData::_proc_array_type arg)
  {
    msg_.proc_array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::monitor_msgs::msg::SysCpuData msg_;
};

class Init_SysCpuData_proc_num
{
public:
  explicit Init_SysCpuData_proc_num(::monitor_msgs::msg::SysCpuData & msg)
  : msg_(msg)
  {}
  Init_SysCpuData_proc_array proc_num(::monitor_msgs::msg::SysCpuData::_proc_num_type arg)
  {
    msg_.proc_num = std::move(arg);
    return Init_SysCpuData_proc_array(msg_);
  }

private:
  ::monitor_msgs::msg::SysCpuData msg_;
};

class Init_SysCpuData_cpu_used
{
public:
  explicit Init_SysCpuData_cpu_used(::monitor_msgs::msg::SysCpuData & msg)
  : msg_(msg)
  {}
  Init_SysCpuData_proc_num cpu_used(::monitor_msgs::msg::SysCpuData::_cpu_used_type arg)
  {
    msg_.cpu_used = std::move(arg);
    return Init_SysCpuData_proc_num(msg_);
  }

private:
  ::monitor_msgs::msg::SysCpuData msg_;
};

class Init_SysCpuData_cpu_num
{
public:
  Init_SysCpuData_cpu_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SysCpuData_cpu_used cpu_num(::monitor_msgs::msg::SysCpuData::_cpu_num_type arg)
  {
    msg_.cpu_num = std::move(arg);
    return Init_SysCpuData_cpu_used(msg_);
  }

private:
  ::monitor_msgs::msg::SysCpuData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::monitor_msgs::msg::SysCpuData>()
{
  return monitor_msgs::msg::builder::Init_SysCpuData_cpu_num();
}

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATA__BUILDER_HPP_
