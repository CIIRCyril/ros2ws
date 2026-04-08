// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from monitor_msgs:msg/SysCpuDatas.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATAS__TRAITS_HPP_
#define MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATAS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "monitor_msgs/msg/detail/sys_cpu_datas__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"
// Member 'cpu_datas'
#include "monitor_msgs/msg/detail/sys_cpu_data__traits.hpp"

namespace monitor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SysCpuDatas & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: cpu_datas
  {
    if (msg.cpu_datas.size() == 0) {
      out << "cpu_datas: []";
    } else {
      out << "cpu_datas: [";
      size_t pending_items = msg.cpu_datas.size();
      for (auto item : msg.cpu_datas) {
        to_flow_style_yaml(item, out);
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
  const SysCpuDatas & msg,
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

  // member: cpu_datas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cpu_datas.size() == 0) {
      out << "cpu_datas: []\n";
    } else {
      out << "cpu_datas:\n";
      for (auto item : msg.cpu_datas) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SysCpuDatas & msg, bool use_flow_style = false)
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
  const monitor_msgs::msg::SysCpuDatas & msg,
  std::ostream & out, size_t indentation = 0)
{
  monitor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use monitor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const monitor_msgs::msg::SysCpuDatas & msg)
{
  return monitor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<monitor_msgs::msg::SysCpuDatas>()
{
  return "monitor_msgs::msg::SysCpuDatas";
}

template<>
inline const char * name<monitor_msgs::msg::SysCpuDatas>()
{
  return "monitor_msgs/msg/SysCpuDatas";
}

template<>
struct has_fixed_size<monitor_msgs::msg::SysCpuDatas>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<monitor_msgs::msg::SysCpuDatas>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<monitor_msgs::msg::SysCpuDatas>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_CPU_DATAS__TRAITS_HPP_
