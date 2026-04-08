// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hric_msgs:msg/MarkerInfo.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__MARKER_INFO__TRAITS_HPP_
#define HRIC_MSGS__MSG__DETAIL__MARKER_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hric_msgs/msg/detail/marker_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__traits.hpp"

namespace hric_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MarkerInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: map_id
  {
    out << "map_id: ";
    rosidl_generator_traits::value_to_yaml(msg.map_id, out);
    out << ", ";
  }

  // member: floor
  {
    out << "floor: ";
    rosidl_generator_traits::value_to_yaml(msg.floor, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MarkerInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: map_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "map_id: ";
    rosidl_generator_traits::value_to_yaml(msg.map_id, out);
    out << "\n";
  }

  // member: floor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "floor: ";
    rosidl_generator_traits::value_to_yaml(msg.floor, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MarkerInfo & msg, bool use_flow_style = false)
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
  const hric_msgs::msg::MarkerInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::msg::MarkerInfo & msg)
{
  return hric_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::msg::MarkerInfo>()
{
  return "hric_msgs::msg::MarkerInfo";
}

template<>
inline const char * name<hric_msgs::msg::MarkerInfo>()
{
  return "hric_msgs/msg/MarkerInfo";
}

template<>
struct has_fixed_size<hric_msgs::msg::MarkerInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hric_msgs::msg::MarkerInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hric_msgs::msg::MarkerInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HRIC_MSGS__MSG__DETAIL__MARKER_INFO__TRAITS_HPP_
