// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hric_msgs:srv/ListMarkers.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__LIST_MARKERS__TRAITS_HPP_
#define HRIC_MSGS__SRV__DETAIL__LIST_MARKERS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hric_msgs/srv/detail/list_markers__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hric_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ListMarkers_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ListMarkers_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ListMarkers_Request & msg, bool use_flow_style = false)
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
  const hric_msgs::srv::ListMarkers_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::srv::ListMarkers_Request & msg)
{
  return hric_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::srv::ListMarkers_Request>()
{
  return "hric_msgs::srv::ListMarkers_Request";
}

template<>
inline const char * name<hric_msgs::srv::ListMarkers_Request>()
{
  return "hric_msgs/srv/ListMarkers_Request";
}

template<>
struct has_fixed_size<hric_msgs::srv::ListMarkers_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hric_msgs::srv::ListMarkers_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hric_msgs::srv::ListMarkers_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'markers'
#include "hric_msgs/msg/detail/marker_info__traits.hpp"

namespace hric_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ListMarkers_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: markers
  {
    if (msg.markers.size() == 0) {
      out << "markers: []";
    } else {
      out << "markers: [";
      size_t pending_items = msg.markers.size();
      for (auto item : msg.markers) {
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
  const ListMarkers_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: markers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.markers.size() == 0) {
      out << "markers: []\n";
    } else {
      out << "markers:\n";
      for (auto item : msg.markers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ListMarkers_Response & msg, bool use_flow_style = false)
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
  const hric_msgs::srv::ListMarkers_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::srv::ListMarkers_Response & msg)
{
  return hric_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::srv::ListMarkers_Response>()
{
  return "hric_msgs::srv::ListMarkers_Response";
}

template<>
inline const char * name<hric_msgs::srv::ListMarkers_Response>()
{
  return "hric_msgs/srv/ListMarkers_Response";
}

template<>
struct has_fixed_size<hric_msgs::srv::ListMarkers_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hric_msgs::srv::ListMarkers_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hric_msgs::srv::ListMarkers_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hric_msgs::srv::ListMarkers>()
{
  return "hric_msgs::srv::ListMarkers";
}

template<>
inline const char * name<hric_msgs::srv::ListMarkers>()
{
  return "hric_msgs/srv/ListMarkers";
}

template<>
struct has_fixed_size<hric_msgs::srv::ListMarkers>
  : std::integral_constant<
    bool,
    has_fixed_size<hric_msgs::srv::ListMarkers_Request>::value &&
    has_fixed_size<hric_msgs::srv::ListMarkers_Response>::value
  >
{
};

template<>
struct has_bounded_size<hric_msgs::srv::ListMarkers>
  : std::integral_constant<
    bool,
    has_bounded_size<hric_msgs::srv::ListMarkers_Request>::value &&
    has_bounded_size<hric_msgs::srv::ListMarkers_Response>::value
  >
{
};

template<>
struct is_service<hric_msgs::srv::ListMarkers>
  : std::true_type
{
};

template<>
struct is_service_request<hric_msgs::srv::ListMarkers_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hric_msgs::srv::ListMarkers_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HRIC_MSGS__SRV__DETAIL__LIST_MARKERS__TRAITS_HPP_
