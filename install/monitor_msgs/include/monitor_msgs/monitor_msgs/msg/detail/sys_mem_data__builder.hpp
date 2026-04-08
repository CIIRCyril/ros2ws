// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from monitor_msgs:msg/SysMemData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_MEM_DATA__BUILDER_HPP_
#define MONITOR_MSGS__MSG__DETAIL__SYS_MEM_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "monitor_msgs/msg/detail/sys_mem_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace monitor_msgs
{

namespace msg
{

namespace builder
{

class Init_SysMemData_swap_free
{
public:
  explicit Init_SysMemData_swap_free(::monitor_msgs::msg::SysMemData & msg)
  : msg_(msg)
  {}
  ::monitor_msgs::msg::SysMemData swap_free(::monitor_msgs::msg::SysMemData::_swap_free_type arg)
  {
    msg_.swap_free = std::move(arg);
    return std::move(msg_);
  }

private:
  ::monitor_msgs::msg::SysMemData msg_;
};

class Init_SysMemData_swap_total
{
public:
  explicit Init_SysMemData_swap_total(::monitor_msgs::msg::SysMemData & msg)
  : msg_(msg)
  {}
  Init_SysMemData_swap_free swap_total(::monitor_msgs::msg::SysMemData::_swap_total_type arg)
  {
    msg_.swap_total = std::move(arg);
    return Init_SysMemData_swap_free(msg_);
  }

private:
  ::monitor_msgs::msg::SysMemData msg_;
};

class Init_SysMemData_sreclaimable
{
public:
  explicit Init_SysMemData_sreclaimable(::monitor_msgs::msg::SysMemData & msg)
  : msg_(msg)
  {}
  Init_SysMemData_swap_total sreclaimable(::monitor_msgs::msg::SysMemData::_sreclaimable_type arg)
  {
    msg_.sreclaimable = std::move(arg);
    return Init_SysMemData_swap_total(msg_);
  }

private:
  ::monitor_msgs::msg::SysMemData msg_;
};

class Init_SysMemData_cached
{
public:
  explicit Init_SysMemData_cached(::monitor_msgs::msg::SysMemData & msg)
  : msg_(msg)
  {}
  Init_SysMemData_sreclaimable cached(::monitor_msgs::msg::SysMemData::_cached_type arg)
  {
    msg_.cached = std::move(arg);
    return Init_SysMemData_sreclaimable(msg_);
  }

private:
  ::monitor_msgs::msg::SysMemData msg_;
};

class Init_SysMemData_buffers
{
public:
  explicit Init_SysMemData_buffers(::monitor_msgs::msg::SysMemData & msg)
  : msg_(msg)
  {}
  Init_SysMemData_cached buffers(::monitor_msgs::msg::SysMemData::_buffers_type arg)
  {
    msg_.buffers = std::move(arg);
    return Init_SysMemData_cached(msg_);
  }

private:
  ::monitor_msgs::msg::SysMemData msg_;
};

class Init_SysMemData_available
{
public:
  explicit Init_SysMemData_available(::monitor_msgs::msg::SysMemData & msg)
  : msg_(msg)
  {}
  Init_SysMemData_buffers available(::monitor_msgs::msg::SysMemData::_available_type arg)
  {
    msg_.available = std::move(arg);
    return Init_SysMemData_buffers(msg_);
  }

private:
  ::monitor_msgs::msg::SysMemData msg_;
};

class Init_SysMemData_shared
{
public:
  explicit Init_SysMemData_shared(::monitor_msgs::msg::SysMemData & msg)
  : msg_(msg)
  {}
  Init_SysMemData_available shared(::monitor_msgs::msg::SysMemData::_shared_type arg)
  {
    msg_.shared = std::move(arg);
    return Init_SysMemData_available(msg_);
  }

private:
  ::monitor_msgs::msg::SysMemData msg_;
};

class Init_SysMemData_free
{
public:
  explicit Init_SysMemData_free(::monitor_msgs::msg::SysMemData & msg)
  : msg_(msg)
  {}
  Init_SysMemData_shared free(::monitor_msgs::msg::SysMemData::_free_type arg)
  {
    msg_.free = std::move(arg);
    return Init_SysMemData_shared(msg_);
  }

private:
  ::monitor_msgs::msg::SysMemData msg_;
};

class Init_SysMemData_used
{
public:
  explicit Init_SysMemData_used(::monitor_msgs::msg::SysMemData & msg)
  : msg_(msg)
  {}
  Init_SysMemData_free used(::monitor_msgs::msg::SysMemData::_used_type arg)
  {
    msg_.used = std::move(arg);
    return Init_SysMemData_free(msg_);
  }

private:
  ::monitor_msgs::msg::SysMemData msg_;
};

class Init_SysMemData_total
{
public:
  explicit Init_SysMemData_total(::monitor_msgs::msg::SysMemData & msg)
  : msg_(msg)
  {}
  Init_SysMemData_used total(::monitor_msgs::msg::SysMemData::_total_type arg)
  {
    msg_.total = std::move(arg);
    return Init_SysMemData_used(msg_);
  }

private:
  ::monitor_msgs::msg::SysMemData msg_;
};

class Init_SysMemData_timestamp
{
public:
  Init_SysMemData_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SysMemData_total timestamp(::monitor_msgs::msg::SysMemData::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_SysMemData_total(msg_);
  }

private:
  ::monitor_msgs::msg::SysMemData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::monitor_msgs::msg::SysMemData>()
{
  return monitor_msgs::msg::builder::Init_SysMemData_timestamp();
}

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_MEM_DATA__BUILDER_HPP_
