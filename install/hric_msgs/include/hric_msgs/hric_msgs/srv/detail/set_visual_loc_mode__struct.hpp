// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:srv/SetVisualLocMode.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__SRV__DETAIL__SET_VISUAL_LOC_MODE__STRUCT_HPP_
#define HRIC_MSGS__SRV__DETAIL__SET_VISUAL_LOC_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hric_msgs__srv__SetVisualLocMode_Request __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__srv__SetVisualLocMode_Request __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetVisualLocMode_Request_
{
  using Type = SetVisualLocMode_Request_<ContainerAllocator>;

  explicit SetVisualLocMode_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->loc_mode = 0;
    }
  }

  explicit SetVisualLocMode_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->loc_mode = 0;
    }
  }

  // field types and members
  using _loc_mode_type =
    uint8_t;
  _loc_mode_type loc_mode;

  // setters for named parameter idiom
  Type & set__loc_mode(
    const uint8_t & _arg)
  {
    this->loc_mode = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t IDLE_MODE =
    0u;
  static constexpr uint8_t ODOM_MODE =
    1u;
  static constexpr uint8_t MAP_REFINE_MODE =
    2u;
  static constexpr uint8_t MAP_LOC_MODE =
    3u;

  // pointer types
  using RawPtr =
    hric_msgs::srv::SetVisualLocMode_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::srv::SetVisualLocMode_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::srv::SetVisualLocMode_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::srv::SetVisualLocMode_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::SetVisualLocMode_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::SetVisualLocMode_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::SetVisualLocMode_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::SetVisualLocMode_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::srv::SetVisualLocMode_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::srv::SetVisualLocMode_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__srv__SetVisualLocMode_Request
    std::shared_ptr<hric_msgs::srv::SetVisualLocMode_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__srv__SetVisualLocMode_Request
    std::shared_ptr<hric_msgs::srv::SetVisualLocMode_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetVisualLocMode_Request_ & other) const
  {
    if (this->loc_mode != other.loc_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetVisualLocMode_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetVisualLocMode_Request_

// alias to use template instance with default allocator
using SetVisualLocMode_Request =
  hric_msgs::srv::SetVisualLocMode_Request_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetVisualLocMode_Request_<ContainerAllocator>::IDLE_MODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetVisualLocMode_Request_<ContainerAllocator>::ODOM_MODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetVisualLocMode_Request_<ContainerAllocator>::MAP_REFINE_MODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetVisualLocMode_Request_<ContainerAllocator>::MAP_LOC_MODE;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace hric_msgs


#ifndef _WIN32
# define DEPRECATED__hric_msgs__srv__SetVisualLocMode_Response __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__srv__SetVisualLocMode_Response __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetVisualLocMode_Response_
{
  using Type = SetVisualLocMode_Response_<ContainerAllocator>;

  explicit SetVisualLocMode_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_code = 0ul;
      this->message = "";
    }
  }

  explicit SetVisualLocMode_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_code = 0ul;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _error_code_type =
    uint32_t;
  _error_code_type error_code;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__error_code(
    const uint32_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint32_t NONE =
    0u;
  static constexpr uint32_t UNKNOWN =
    200u;

  // pointer types
  using RawPtr =
    hric_msgs::srv::SetVisualLocMode_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::srv::SetVisualLocMode_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::srv::SetVisualLocMode_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::srv::SetVisualLocMode_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::SetVisualLocMode_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::SetVisualLocMode_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::srv::SetVisualLocMode_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::srv::SetVisualLocMode_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::srv::SetVisualLocMode_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::srv::SetVisualLocMode_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__srv__SetVisualLocMode_Response
    std::shared_ptr<hric_msgs::srv::SetVisualLocMode_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__srv__SetVisualLocMode_Response
    std::shared_ptr<hric_msgs::srv::SetVisualLocMode_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetVisualLocMode_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetVisualLocMode_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetVisualLocMode_Response_

// alias to use template instance with default allocator
using SetVisualLocMode_Response =
  hric_msgs::srv::SetVisualLocMode_Response_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t SetVisualLocMode_Response_<ContainerAllocator>::NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t SetVisualLocMode_Response_<ContainerAllocator>::UNKNOWN;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace hric_msgs

namespace hric_msgs
{

namespace srv
{

struct SetVisualLocMode
{
  using Request = hric_msgs::srv::SetVisualLocMode_Request;
  using Response = hric_msgs::srv::SetVisualLocMode_Response;
};

}  // namespace srv

}  // namespace hric_msgs

#endif  // HRIC_MSGS__SRV__DETAIL__SET_VISUAL_LOC_MODE__STRUCT_HPP_
