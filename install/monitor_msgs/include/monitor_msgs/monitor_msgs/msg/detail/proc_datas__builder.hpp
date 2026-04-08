// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from monitor_msgs:msg/ProcDatas.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_DATAS__BUILDER_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_DATAS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "monitor_msgs/msg/detail/proc_datas__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace monitor_msgs
{

namespace msg
{

namespace builder
{

class Init_ProcDatas_proc_datas
{
public:
  explicit Init_ProcDatas_proc_datas(::monitor_msgs::msg::ProcDatas & msg)
  : msg_(msg)
  {}
  ::monitor_msgs::msg::ProcDatas proc_datas(::monitor_msgs::msg::ProcDatas::_proc_datas_type arg)
  {
    msg_.proc_datas = std::move(arg);
    return std::move(msg_);
  }

private:
  ::monitor_msgs::msg::ProcDatas msg_;
};

class Init_ProcDatas_timestamp
{
public:
  Init_ProcDatas_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcDatas_proc_datas timestamp(::monitor_msgs::msg::ProcDatas::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_ProcDatas_proc_datas(msg_);
  }

private:
  ::monitor_msgs::msg::ProcDatas msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::monitor_msgs::msg::ProcDatas>()
{
  return monitor_msgs::msg::builder::Init_ProcDatas_timestamp();
}

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_DATAS__BUILDER_HPP_
