// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from monitor_msgs:msg/ProcMemData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__BUILDER_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "monitor_msgs/msg/detail/proc_mem_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace monitor_msgs
{

namespace msg
{

namespace builder
{

class Init_ProcMemData_vmdata
{
public:
  explicit Init_ProcMemData_vmdata(::monitor_msgs::msg::ProcMemData & msg)
  : msg_(msg)
  {}
  ::monitor_msgs::msg::ProcMemData vmdata(::monitor_msgs::msg::ProcMemData::_vmdata_type arg)
  {
    msg_.vmdata = std::move(arg);
    return std::move(msg_);
  }

private:
  ::monitor_msgs::msg::ProcMemData msg_;
};

class Init_ProcMemData_vmexe
{
public:
  explicit Init_ProcMemData_vmexe(::monitor_msgs::msg::ProcMemData & msg)
  : msg_(msg)
  {}
  Init_ProcMemData_vmdata vmexe(::monitor_msgs::msg::ProcMemData::_vmexe_type arg)
  {
    msg_.vmexe = std::move(arg);
    return Init_ProcMemData_vmdata(msg_);
  }

private:
  ::monitor_msgs::msg::ProcMemData msg_;
};

class Init_ProcMemData_vmshared
{
public:
  explicit Init_ProcMemData_vmshared(::monitor_msgs::msg::ProcMemData & msg)
  : msg_(msg)
  {}
  Init_ProcMemData_vmexe vmshared(::monitor_msgs::msg::ProcMemData::_vmshared_type arg)
  {
    msg_.vmshared = std::move(arg);
    return Init_ProcMemData_vmexe(msg_);
  }

private:
  ::monitor_msgs::msg::ProcMemData msg_;
};

class Init_ProcMemData_vmrss
{
public:
  explicit Init_ProcMemData_vmrss(::monitor_msgs::msg::ProcMemData & msg)
  : msg_(msg)
  {}
  Init_ProcMemData_vmshared vmrss(::monitor_msgs::msg::ProcMemData::_vmrss_type arg)
  {
    msg_.vmrss = std::move(arg);
    return Init_ProcMemData_vmshared(msg_);
  }

private:
  ::monitor_msgs::msg::ProcMemData msg_;
};

class Init_ProcMemData_vmsize
{
public:
  Init_ProcMemData_vmsize()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcMemData_vmrss vmsize(::monitor_msgs::msg::ProcMemData::_vmsize_type arg)
  {
    msg_.vmsize = std::move(arg);
    return Init_ProcMemData_vmrss(msg_);
  }

private:
  ::monitor_msgs::msg::ProcMemData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::monitor_msgs::msg::ProcMemData>()
{
  return monitor_msgs::msg::builder::Init_ProcMemData_vmsize();
}

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__BUILDER_HPP_
