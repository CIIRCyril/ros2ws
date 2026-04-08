// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from monitor_msgs:msg/ProcIoData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_IO_DATA__TRAITS_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_IO_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "monitor_msgs/msg/detail/proc_io_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace monitor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ProcIoData & msg,
  std::ostream & out)
{
  out << "{";
  // member: read
  {
    out << "read: ";
    rosidl_generator_traits::value_to_yaml(msg.read, out);
    out << ", ";
  }

  // member: write
  {
    out << "write: ";
    rosidl_generator_traits::value_to_yaml(msg.write, out);
    out << ", ";
  }

  // member: total_read
  {
    out << "total_read: ";
    rosidl_generator_traits::value_to_yaml(msg.total_read, out);
    out << ", ";
  }

  // member: total_write
  {
    out << "total_write: ";
    rosidl_generator_traits::value_to_yaml(msg.total_write, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ProcIoData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: read
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "read: ";
    rosidl_generator_traits::value_to_yaml(msg.read, out);
    out << "\n";
  }

  // member: write
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "write: ";
    rosidl_generator_traits::value_to_yaml(msg.write, out);
    out << "\n";
  }

  // member: total_read
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total_read: ";
    rosidl_generator_traits::value_to_yaml(msg.total_read, out);
    out << "\n";
  }

  // member: total_write
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total_write: ";
    rosidl_generator_traits::value_to_yaml(msg.total_write, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ProcIoData & msg, bool use_flow_style = false)
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
  const monitor_msgs::msg::ProcIoData & msg,
  std::ostream & out, size_t indentation = 0)
{
  monitor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use monitor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const monitor_msgs::msg::ProcIoData & msg)
{
  return monitor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<monitor_msgs::msg::ProcIoData>()
{
  return "monitor_msgs::msg::ProcIoData";
}

template<>
inline const char * name<monitor_msgs::msg::ProcIoData>()
{
  return "monitor_msgs/msg/ProcIoData";
}

template<>
struct has_fixed_size<monitor_msgs::msg::ProcIoData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<monitor_msgs::msg::ProcIoData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<monitor_msgs::msg::ProcIoData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_IO_DATA__TRAITS_HPP_
