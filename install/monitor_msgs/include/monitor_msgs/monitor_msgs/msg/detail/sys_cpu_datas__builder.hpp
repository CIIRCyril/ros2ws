// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from monitor_msgs:msg/SysCpuDatas.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATAS__BUILDER_HPP_
#define MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATAS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "monitor_msgs/msg/detail/sys_cpu_datas__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace monitor_msgs
{

namespace msg
{

namespace builder
{

class Init_SysCpuDatas_cpu_datas
{
public:
  explicit Init_SysCpuDatas_cpu_datas(::monitor_msgs::msg::SysCpuDatas & msg)
  : msg_(msg)
  {}
  ::monitor_msgs::msg::SysCpuDatas cpu_datas(::monitor_msgs::msg::SysCpuDatas::_cpu_datas_type arg)
  {
    msg_.cpu_datas = std::move(arg);
    return std::move(msg_);
  }

private:
  ::monitor_msgs::msg::SysCpuDatas msg_;
};

class Init_SysCpuDatas_timestamp
{
public:
  Init_SysCpuDatas_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SysCpuDatas_cpu_datas timestamp(::monitor_msgs::msg::SysCpuDatas::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_SysCpuDatas_cpu_datas(msg_);
  }

private:
  ::monitor_msgs::msg::SysCpuDatas msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::monitor_msgs::msg::SysCpuDatas>()
{
  return monitor_msgs::msg::builder::Init_SysCpuDatas_timestamp();
}

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATAS__BUILDER_HPP_
