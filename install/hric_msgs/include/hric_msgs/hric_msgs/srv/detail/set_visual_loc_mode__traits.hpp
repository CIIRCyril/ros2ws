// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hric_msgs:srv/SetVisualLocMode.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_VISUAL_LOC_MODE__TRAITS_HPP_
#define HRIC_MSGS__SRV__DETAIL__SET_VISUAL_LOC_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hric_msgs/srv/detail/set_visual_loc_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hric_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetVisualLocMode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: loc_mode
  {
    out << "loc_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.loc_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetVisualLocMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: loc_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "loc_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.loc_mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetVisualLocMode_Request & msg, bool use_flow_style = false)
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
  const hric_msgs::srv::SetVisualLocMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::srv::SetVisualLocMode_Request & msg)
{
  return hric_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::srv::SetVisualLocMode_Request>()
{
  return "hric_msgs::srv::SetVisualLocMode_Request";
}

template<>
inline const char * name<hric_msgs::srv::SetVisualLocMode_Request>()
{
  return "hric_msgs/srv/SetVisualLocMode_Request";
}

template<>
struct has_fixed_size<hric_msgs::srv::SetVisualLocMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hric_msgs::srv::SetVisualLocMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hric_msgs::srv::SetVisualLocMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hric_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetVisualLocMode_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetVisualLocMode_Response & msg,
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

  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetVisualLocMode_Response & msg, bool use_flow_style = false)
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
  const hric_msgs::srv::SetVisualLocMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hric_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hric_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hric_msgs::srv::SetVisualLocMode_Response & msg)
{
  return hric_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hric_msgs::srv::SetVisualLocMode_Response>()
{
  return "hric_msgs::srv::SetVisualLocMode_Response";
}

template<>
inline const char * name<hric_msgs::srv::SetVisualLocMode_Response>()
{
  return "hric_msgs/srv/SetVisualLocMode_Response";
}

template<>
struct has_fixed_size<hric_msgs::srv::SetVisualLocMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hric_msgs::srv::SetVisualLocMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hric_msgs::srv::SetVisualLocMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hric_msgs::srv::SetVisualLocMode>()
{
  return "hric_msgs::srv::SetVisualLocMode";
}

template<>
inline const char * name<hric_msgs::srv::SetVisualLocMode>()
{
  return "hric_msgs/srv/SetVisualLocMode";
}

template<>
struct has_fixed_size<hric_msgs::srv::SetVisualLocMode>
  : std::integral_constant<
    bool,
    has_fixed_size<hric_msgs::srv::SetVisualLocMode_Request>::value &&
    has_fixed_size<hric_msgs::srv::SetVisualLocMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<hric_msgs::srv::SetVisualLocMode>
  : std::integral_constant<
    bool,
    has_bounded_size<hric_msgs::srv::SetVisualLocMode_Request>::value &&
    has_bounded_size<hric_msgs::srv::SetVisualLocMode_Response>::value
  >
{
};

template<>
struct is_service<hric_msgs::srv::SetVisualLocMode>
  : std::true_type
{
};

template<>
struct is_service_request<hric_msgs::srv::SetVisualLocMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hric_msgs::srv::SetVisualLocMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HRIC_MSGS__SRV__DETAIL__SET_VISUAL_LOC_MODE__TRAITS_HPP_
