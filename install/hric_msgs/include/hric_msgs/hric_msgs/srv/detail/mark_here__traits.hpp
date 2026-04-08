// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hric_msgs:srv/MarkHere.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__MARK_HERE__TRAITS_HPP_
#define HRIC_MSGS__SRV__DETAIL__MARK_HERE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hric_msgs/srv/detail/mark_here__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hric_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const MarkHere_Request & msg,
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MarkHere_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MarkHere_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hric_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hric_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hric_msgs::srv::MarkHere_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::srv::MarkHere_Request & msg)
{
  return hric_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::srv::MarkHere_Request>()
{
  return "hric_msgs::srv::MarkHere_Request";
}

template<>
inline const char * name<hric_msgs::srv::MarkHere_Request>()
{
  return "hric_msgs/srv/MarkHere_Request";
}

template<>
struct has_fixed_size<hric_msgs::srv::MarkHere_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hric_msgs::srv::MarkHere_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hric_msgs::srv::MarkHere_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'marker'
#include "hric_msgs/msg/detail/marker_info__traits.hpp"

namespace hric_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const MarkHere_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: marker
  {
    out << "marker: ";
    to_flow_style_yaml(msg.marker, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MarkHere_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: marker
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "marker:\n";
    to_block_style_yaml(msg.marker, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MarkHere_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hric_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hric_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hric_msgs::srv::MarkHere_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::srv::MarkHere_Response & msg)
{
  return hric_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::srv::MarkHere_Response>()
{
  return "hric_msgs::srv::MarkHere_Response";
}

template<>
inline const char * name<hric_msgs::srv::MarkHere_Response>()
{
  return "hric_msgs/srv/MarkHere_Response";
}

template<>
struct has_fixed_size<hric_msgs::srv::MarkHere_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hric_msgs::srv::MarkHere_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hric_msgs::srv::MarkHere_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hric_msgs::srv::MarkHere>()
{
  return "hric_msgs::srv::MarkHere";
}

template<>
inline const char * name<hric_msgs::srv::MarkHere>()
{
  return "hric_msgs/srv/MarkHere";
}

template<>
struct has_fixed_size<hric_msgs::srv::MarkHere>
  : std::integral_constant<
    bool,
    has_fixed_size<hric_msgs::srv::MarkHere_Request>::value &&
    has_fixed_size<hric_msgs::srv::MarkHere_Response>::value
  >
{
};

template<>
struct has_bounded_size<hric_msgs::srv::MarkHere>
  : std::integral_constant<
    bool,
    has_bounded_size<hric_msgs::srv::MarkHere_Request>::value &&
    has_bounded_size<hric_msgs::srv::MarkHere_Response>::value
  >
{
};

template<>
struct is_service<hric_msgs::srv::MarkHere>
  : std::true_type
{
};

template<>
struct is_service_request<hric_msgs::srv::MarkHere_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hric_msgs::srv::MarkHere_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HRIC_MSGS__SRV__DETAIL__MARK_HERE__TRAITS_HPP_
