// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from monitor_msgs:msg/ProcCpuData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_CPU_DATA__BUILDER_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_CPU_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "monitor_msgs/msg/detail/proc_cpu_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace monitor_msgs
{

namespace msg
{

namespace builder
{

class Init_ProcCpuData_used
{
public:
  explicit Init_ProcCpuData_used(::monitor_msgs::msg::ProcCpuData & msg)
  : msg_(msg)
  {}
  ::monitor_msgs::msg::ProcCpuData used(::monitor_msgs::msg::ProcCpuData::_used_type arg)
  {
    msg_.used = std::move(arg);
    return std::move(msg_);
  }

private:
  ::monitor_msgs::msg::ProcCpuData msg_;
};

class Init_ProcCpuData_num
{
public:
  Init_ProcCpuData_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcCpuData_used num(::monitor_msgs::msg::ProcCpuData::_num_type arg)
  {
    msg_.num = std::move(arg);
    return Init_ProcCpuData_used(msg_);
  }

private:
  ::monitor_msgs::msg::ProcCpuData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::monitor_msgs::msg::ProcCpuData>()
{
  return monitor_msgs::msg::builder::Init_ProcCpuData_num();
}

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_CPU_DATA__BUILDER_HPP_
