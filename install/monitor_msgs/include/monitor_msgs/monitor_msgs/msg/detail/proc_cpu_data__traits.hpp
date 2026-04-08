// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from monitor_msgs:msg/ProcCpuData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_CPU_DATA__TRAITS_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_CPU_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "monitor_msgs/msg/detail/proc_cpu_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace monitor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ProcCpuData & msg,
  std::ostream & out)
{
  out << "{";
  // member: num
  {
    out << "num: ";
    rosidl_generator_traits::value_to_yaml(msg.num, out);
    out << ", ";
  }

  // member: used
  {
    out << "used: ";
    rosidl_generator_traits::value_to_yaml(msg.used, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ProcCpuData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num: ";
    rosidl_generator_traits::value_to_yaml(msg.num, out);
    out << "\n";
  }

  // member: used
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "used: ";
    rosidl_generator_traits::value_to_yaml(msg.used, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ProcCpuData & msg, bool use_flow_style = false)
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
  const monitor_msgs::msg::ProcCpuData & msg,
  std::ostream & out, size_t indentation = 0)
{
  monitor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use monitor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const monitor_msgs::msg::ProcCpuData & msg)
{
  return monitor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<monitor_msgs::msg::ProcCpuData>()
{
  return "monitor_msgs::msg::ProcCpuData";
}

template<>
inline const char * name<monitor_msgs::msg::ProcCpuData>()
{
  return "monitor_msgs/msg/ProcCpuData";
}

template<>
struct has_fixed_size<monitor_msgs::msg::ProcCpuData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<monitor_msgs::msg::ProcCpuData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<monitor_msgs::msg::ProcCpuData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_CPU_DATA__TRAITS_HPP_
