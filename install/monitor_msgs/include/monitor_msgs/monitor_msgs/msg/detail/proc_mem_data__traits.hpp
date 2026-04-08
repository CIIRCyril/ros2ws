// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from monitor_msgs:msg/ProcMemData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__TRAITS_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "monitor_msgs/msg/detail/proc_mem_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace monitor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ProcMemData & msg,
  std::ostream & out)
{
  out << "{";
  // member: vmsize
  {
    out << "vmsize: ";
    rosidl_generator_traits::value_to_yaml(msg.vmsize, out);
    out << ", ";
  }

  // member: vmrss
  {
    out << "vmrss: ";
    rosidl_generator_traits::value_to_yaml(msg.vmrss, out);
    out << ", ";
  }

  // member: vmshared
  {
    out << "vmshared: ";
    rosidl_generator_traits::value_to_yaml(msg.vmshared, out);
    out << ", ";
  }

  // member: vmexe
  {
    out << "vmexe: ";
    rosidl_generator_traits::value_to_yaml(msg.vmexe, out);
    out << ", ";
  }

  // member: vmdata
  {
    out << "vmdata: ";
    rosidl_generator_traits::value_to_yaml(msg.vmdata, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ProcMemData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: vmsize
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vmsize: ";
    rosidl_generator_traits::value_to_yaml(msg.vmsize, out);
    out << "\n";
  }

  // member: vmrss
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vmrss: ";
    rosidl_generator_traits::value_to_yaml(msg.vmrss, out);
    out << "\n";
  }

  // member: vmshared
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vmshared: ";
    rosidl_generator_traits::value_to_yaml(msg.vmshared, out);
    out << "\n";
  }

  // member: vmexe
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vmexe: ";
    rosidl_generator_traits::value_to_yaml(msg.vmexe, out);
    out << "\n";
  }

  // member: vmdata
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vmdata: ";
    rosidl_generator_traits::value_to_yaml(msg.vmdata, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ProcMemData & msg, bool use_flow_style = false)
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
  const monitor_msgs::msg::ProcMemData & msg,
  std::ostream & out, size_t indentation = 0)
{
  monitor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use monitor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const monitor_msgs::msg::ProcMemData & msg)
{
  return monitor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<monitor_msgs::msg::ProcMemData>()
{
  return "monitor_msgs::msg::ProcMemData";
}

template<>
inline const char * name<monitor_msgs::msg::ProcMemData>()
{
  return "monitor_msgs/msg/ProcMemData";
}

template<>
struct has_fixed_size<monitor_msgs::msg::ProcMemData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<monitor_msgs::msg::ProcMemData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<monitor_msgs::msg::ProcMemData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__TRAITS_HPP_
