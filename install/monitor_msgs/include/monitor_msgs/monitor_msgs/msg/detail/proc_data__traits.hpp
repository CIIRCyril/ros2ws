// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from monitor_msgs:msg/ProcData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_DATA__TRAITS_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "monitor_msgs/msg/detail/proc_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'cpu_data'
#include "monitor_msgs/msg/detail/proc_cpu_data__traits.hpp"
// Member 'io_data'
#include "monitor_msgs/msg/detail/proc_io_data__traits.hpp"
// Member 'mem_data'
#include "monitor_msgs/msg/detail/proc_mem_data__traits.hpp"

namespace monitor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ProcData & msg,
  std::ostream & out)
{
  out << "{";
  // member: pid
  {
    out << "pid: ";
    rosidl_generator_traits::value_to_yaml(msg.pid, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: active
  {
    out << "active: ";
    rosidl_generator_traits::value_to_yaml(msg.active, out);
    out << ", ";
  }

  // member: cpu_data
  {
    out << "cpu_data: ";
    to_flow_style_yaml(msg.cpu_data, out);
    out << ", ";
  }

  // member: io_data
  {
    out << "io_data: ";
    to_flow_style_yaml(msg.io_data, out);
    out << ", ";
  }

  // member: mem_data
  {
    out << "mem_data: ";
    to_flow_style_yaml(msg.mem_data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ProcData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pid: ";
    rosidl_generator_traits::value_to_yaml(msg.pid, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: active
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "active: ";
    rosidl_generator_traits::value_to_yaml(msg.active, out);
    out << "\n";
  }

  // member: cpu_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cpu_data:\n";
    to_block_style_yaml(msg.cpu_data, out, indentation + 2);
  }

  // member: io_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "io_data:\n";
    to_block_style_yaml(msg.io_data, out, indentation + 2);
  }

  // member: mem_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mem_data:\n";
    to_block_style_yaml(msg.mem_data, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ProcData & msg, bool use_flow_style = false)
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
  const monitor_msgs::msg::ProcData & msg,
  std::ostream & out, size_t indentation = 0)
{
  monitor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use monitor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const monitor_msgs::msg::ProcData & msg)
{
  return monitor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<monitor_msgs::msg::ProcData>()
{
  return "monitor_msgs::msg::ProcData";
}

template<>
inline const char * name<monitor_msgs::msg::ProcData>()
{
  return "monitor_msgs/msg/ProcData";
}

template<>
struct has_fixed_size<monitor_msgs::msg::ProcData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<monitor_msgs::msg::ProcData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<monitor_msgs::msg::ProcData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_DATA__TRAITS_HPP_
