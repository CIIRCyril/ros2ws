// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from monitor_msgs:msg/ProcDatas.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_DATAS__TRAITS_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_DATAS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "monitor_msgs/msg/detail/proc_datas__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"
// Member 'proc_datas'
#include "monitor_msgs/msg/detail/proc_data__traits.hpp"

namespace monitor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ProcDatas & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: proc_datas
  {
    if (msg.proc_datas.size() == 0) {
      out << "proc_datas: []";
    } else {
      out << "proc_datas: [";
      size_t pending_items = msg.proc_datas.size();
      for (auto item : msg.proc_datas) {
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
  const ProcDatas & msg,
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

  // member: proc_datas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.proc_datas.size() == 0) {
      out << "proc_datas: []\n";
    } else {
      out << "proc_datas:\n";
      for (auto item : msg.proc_datas) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ProcDatas & msg, bool use_flow_style = false)
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
  const monitor_msgs::msg::ProcDatas & msg,
  std::ostream & out, size_t indentation = 0)
{
  monitor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use monitor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const monitor_msgs::msg::ProcDatas & msg)
{
  return monitor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<monitor_msgs::msg::ProcDatas>()
{
  return "monitor_msgs::msg::ProcDatas";
}

template<>
inline const char * name<monitor_msgs::msg::ProcDatas>()
{
  return "monitor_msgs/msg/ProcDatas";
}

template<>
struct has_fixed_size<monitor_msgs::msg::ProcDatas>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<monitor_msgs::msg::ProcDatas>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<monitor_msgs::msg::ProcDatas>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_DATAS__TRAITS_HPP_
