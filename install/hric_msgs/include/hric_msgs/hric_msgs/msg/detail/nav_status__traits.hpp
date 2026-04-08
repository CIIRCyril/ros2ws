// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hric_msgs:msg/NavStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__NAV_STATUS__TRAITS_HPP_
#define HRIC_MSGS__MSG__DETAIL__NAV_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hric_msgs/msg/detail/nav_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hric_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavStatus & msg, bool use_flow_style = false)
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

}  // namespace hric_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hric_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hric_msgs::msg::NavStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::msg::NavStatus & msg)
{
  return hric_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::msg::NavStatus>()
{
  return "hric_msgs::msg::NavStatus";
}

template<>
inline const char * name<hric_msgs::msg::NavStatus>()
{
  return "hric_msgs/msg/NavStatus";
}

template<>
struct has_fixed_size<hric_msgs::msg::NavStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hric_msgs::msg::NavStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hric_msgs::msg::NavStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HRIC_MSGS__MSG__DETAIL__NAV_STATUS__TRAITS_HPP_
