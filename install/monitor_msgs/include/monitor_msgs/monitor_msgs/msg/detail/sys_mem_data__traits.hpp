// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from monitor_msgs:msg/SysMemData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_MEM_DATA__TRAITS_HPP_
#define MONITOR_MSGS__MSG__DETAIL__SYS_MEM_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "monitor_msgs/msg/detail/sys_mem_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace monitor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SysMemData & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: total
  {
    out << "total: ";
    rosidl_generator_traits::value_to_yaml(msg.total, out);
    out << ", ";
  }

  // member: used
  {
    out << "used: ";
    rosidl_generator_traits::value_to_yaml(msg.used, out);
    out << ", ";
  }

  // member: free
  {
    out << "free: ";
    rosidl_generator_traits::value_to_yaml(msg.free, out);
    out << ", ";
  }

  // member: shared
  {
    out << "shared: ";
    rosidl_generator_traits::value_to_yaml(msg.shared, out);
    out << ", ";
  }

  // member: available
  {
    out << "available: ";
    rosidl_generator_traits::value_to_yaml(msg.available, out);
    out << ", ";
  }

  // member: buffers
  {
    out << "buffers: ";
    rosidl_generator_traits::value_to_yaml(msg.buffers, out);
    out << ", ";
  }

  // member: cached
  {
    out << "cached: ";
    rosidl_generator_traits::value_to_yaml(msg.cached, out);
    out << ", ";
  }

  // member: sreclaimable
  {
    out << "sreclaimable: ";
    rosidl_generator_traits::value_to_yaml(msg.sreclaimable, out);
    out << ", ";
  }

  // member: swap_total
  {
    out << "swap_total: ";
    rosidl_generator_traits::value_to_yaml(msg.swap_total, out);
    out << ", ";
  }

  // member: swap_free
  {
    out << "swap_free: ";
    rosidl_generator_traits::value_to_yaml(msg.swap_free, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SysMemData & msg,
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

  // member: total
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total: ";
    rosidl_generator_traits::value_to_yaml(msg.total, out);
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

  // member: free
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "free: ";
    rosidl_generator_traits::value_to_yaml(msg.free, out);
    out << "\n";
  }

  // member: shared
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shared: ";
    rosidl_generator_traits::value_to_yaml(msg.shared, out);
    out << "\n";
  }

  // member: available
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "available: ";
    rosidl_generator_traits::value_to_yaml(msg.available, out);
    out << "\n";
  }

  // member: buffers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "buffers: ";
    rosidl_generator_traits::value_to_yaml(msg.buffers, out);
    out << "\n";
  }

  // member: cached
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cached: ";
    rosidl_generator_traits::value_to_yaml(msg.cached, out);
    out << "\n";
  }

  // member: sreclaimable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sreclaimable: ";
    rosidl_generator_traits::value_to_yaml(msg.sreclaimable, out);
    out << "\n";
  }

  // member: swap_total
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "swap_total: ";
    rosidl_generator_traits::value_to_yaml(msg.swap_total, out);
    out << "\n";
  }

  // member: swap_free
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "swap_free: ";
    rosidl_generator_traits::value_to_yaml(msg.swap_free, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SysMemData & msg, bool use_flow_style = false)
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
  const monitor_msgs::msg::SysMemData & msg,
  std::ostream & out, size_t indentation = 0)
{
  monitor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use monitor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const monitor_msgs::msg::SysMemData & msg)
{
  return monitor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<monitor_msgs::msg::SysMemData>()
{
  return "monitor_msgs::msg::SysMemData";
}

template<>
inline const char * name<monitor_msgs::msg::SysMemData>()
{
  return "monitor_msgs/msg/SysMemData";
}

template<>
struct has_fixed_size<monitor_msgs::msg::SysMemData>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<monitor_msgs::msg::SysMemData>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<monitor_msgs::msg::SysMemData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_MEM_DATA__TRAITS_HPP_
