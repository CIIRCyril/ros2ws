// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:msg/NavStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__NAV_STATUS__STRUCT_HPP_
#define HRIC_MSGS__MSG__DETAIL__NAV_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hric_msgs__msg__NavStatus __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__msg__NavStatus __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavStatus_
{
  using Type = NavStatus_<ContainerAllocator>;

  explicit NavStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->error_code = 0ul;
    }
  }

  explicit NavStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->error_code = 0ul;
    }
  }

  // field types and members
  using _status_type =
    uint8_t;
  _status_type status;
  using _error_code_type =
    uint32_t;
  _error_code_type error_code;

  // setters for named parameter idiom
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__error_code(
    const uint32_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint32_t NONE =
    0u;
  static constexpr uint32_t UNKNOWN =
    100u;
  static constexpr uint32_t GOAL_OCCUPIED =
    101u;
  static constexpr uint32_t TIMEOUT =
    102u;
  static constexpr uint32_t NO_VALID_PATH =
    103u;
  static constexpr uint8_t IDLE =
    0u;
  static constexpr uint8_t EXECUTE_TASK =
    1u;
  static constexpr uint8_t CANCELED =
    2u;
  static constexpr uint8_t FAILED =
    3u;
  static constexpr uint8_t REACHED_GOAL =
    4u;

  // pointer types
  using RawPtr =
    hric_msgs::msg::NavStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::msg::NavStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::msg::NavStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::msg::NavStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::msg::NavStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::msg::NavStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::msg::NavStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::msg::NavStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::msg::NavStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::msg::NavStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__msg__NavStatus
    std::shared_ptr<hric_msgs::msg::NavStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__msg__NavStatus
    std::shared_ptr<hric_msgs::msg::NavStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavStatus_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavStatus_

// alias to use template instance with default allocator
using NavStatus =
  hric_msgs::msg::NavStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavStatus_<ContainerAllocator>::NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavStatus_<ContainerAllocator>::UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavStatus_<ContainerAllocator>::GOAL_OCCUPIED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavStatus_<ContainerAllocator>::TIMEOUT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t NavStatus_<ContainerAllocator>::NO_VALID_PATH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavStatus_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavStatus_<ContainerAllocator>::EXECUTE_TASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavStatus_<ContainerAllocator>::CANCELED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavStatus_<ContainerAllocator>::FAILED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavStatus_<ContainerAllocator>::REACHED_GOAL;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__NAV_STATUS__STRUCT_HPP_
