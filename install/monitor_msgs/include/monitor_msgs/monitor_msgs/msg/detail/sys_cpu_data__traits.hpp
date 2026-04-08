// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from monitor_msgs:msg/SysCpuData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATA__TRAITS_HPP_
#define MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "monitor_msgs/msg/detail/sys_cpu_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace monitor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SysCpuData & msg,
  std::ostream & out)
{
  out << "{";
  // member: cpu_num
  {
    out << "cpu_num: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_num, out);
    out << ", ";
  }

  // member: cpu_used
  {
    out << "cpu_used: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_used, out);
    out << ", ";
  }

  // member: proc_num
  {
    out << "proc_num: ";
    rosidl_generator_traits::value_to_yaml(msg.proc_num, out);
    out << ", ";
  }

  // member: proc_array
  {
    if (msg.proc_array.size() == 0) {
      out << "proc_array: []";
    } else {
      out << "proc_array: [";
      size_t pending_items = msg.proc_array.size();
      for (auto item : msg.proc_array) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SysCpuData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cpu_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cpu_num: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_num, out);
    out << "\n";
  }

  // member: cpu_used
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cpu_used: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_used, out);
    out << "\n";
  }

  // member: proc_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "proc_num: ";
    rosidl_generator_traits::value_to_yaml(msg.proc_num, out);
    out << "\n";
  }

  // member: proc_array
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.proc_array.size() == 0) {
      out << "proc_array: []\n";
    } else {
      out << "proc_array:\n";
      for (auto item : msg.proc_array) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SysCpuData & msg, bool use_flow_style = false)
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
  const monitor_msgs::msg::SysCpuData & msg,
  std::ostream & out, size_t indentation = 0)
{
  monitor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use monitor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const monitor_msgs::msg::SysCpuData & msg)
{
  return monitor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<monitor_msgs::msg::SysCpuData>()
{
  return "monitor_msgs::msg::SysCpuData";
}

template<>
inline const char * name<monitor_msgs::msg::SysCpuData>()
{
  return "monitor_msgs/msg/SysCpuData";
}

template<>
struct has_fixed_size<monitor_msgs::msg::SysCpuData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<monitor_msgs::msg::SysCpuData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<monitor_msgs::msg::SysCpuData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATA__TRAITS_HPP_
