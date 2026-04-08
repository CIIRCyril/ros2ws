// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from monitor_msgs:msg/SysIoData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_IO_DATA__TRAITS_HPP_
#define MONITOR_MSGS__MSG__DETAIL__SYS_IO_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "monitor_msgs/msg/detail/sys_io_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace monitor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SysIoData & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: disk_read
  {
    out << "disk_read: ";
    rosidl_generator_traits::value_to_yaml(msg.disk_read, out);
    out << ", ";
  }

  // member: disk_write
  {
    out << "disk_write: ";
    rosidl_generator_traits::value_to_yaml(msg.disk_write, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SysIoData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp:\n";
    to_block_style_yaml(msg.timestamp, out, indentation + 2);
  }

  // member: disk_read
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "disk_read: ";
    rosidl_generator_traits::value_to_yaml(msg.disk_read, out);
    out << "\n";
  }

  // member: disk_write
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "disk_write: ";
    rosidl_generator_traits::value_to_yaml(msg.disk_write, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SysIoData & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace monitor_msgs

namespace rosidl_generator_traits
{

[[deprecated("use monitor_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const monitor_msgs::msg::SysIoData & msg,
  std::ostream & out, size_t indentation = 0)
{
  monitor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use monitor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const monitor_msgs::msg::SysIoData & msg)
{
  return monitor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<monitor_msgs::msg::SysIoData>()
{
  return "monitor_msgs::msg::SysIoData";
}

template<>
inline const char * name<monitor_msgs::msg::SysIoData>()
{
  return "monitor_msgs/msg/SysIoData";
}

template<>
struct has_fixed_size<monitor_msgs::msg::SysIoData>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<monitor_msgs::msg::SysIoData>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<monitor_msgs::msg::SysIoData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_IO_DATA__TRAITS_HPP_
