// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:msg/LocStatus.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__LOC_STATUS__STRUCT_HPP_
#define HRIC_MSGS__MSG__DETAIL__LOC_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hric_msgs__msg__LocStatus __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__msg__LocStatus __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LocStatus_
{
  using Type = LocStatus_<ContainerAllocator>;

  explicit LocStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->confidence = 0.0;
      this->error_code = 0ul;
    }
  }

  explicit LocStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->confidence = 0.0;
      this->error_code = 0ul;
    }
  }

  // field types and members
  using _status_type =
    uint8_t;
  _status_type status;
  using _confidence_type =
    double;
  _confidence_type confidence;
  using _error_code_type =
    uint32_t;
  _error_code_type error_code;
  using _pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__confidence(
    const double & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__error_code(
    const uint32_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t IDLE =
    100u;
  static constexpr uint8_t INITIALIZING =
    101u;
  static constexpr uint8_t RUNNING =
    102u;
  static constexpr uint8_t WEAK =
    103u;
  static constexpr uint8_t LOST =
    104u;
  static constexpr uint8_t BLOCKED =
    105u;
  static constexpr uint32_t NONE =
    0u;
  static constexpr uint32_t UNKNOWN =
    200u;
  static constexpr uint32_t TF_ERROR =
    201u;
  static constexpr uint32_t SENSOR_ERROR =
    202u;
  static constexpr uint32_t RELOCALIZATION_ERROR =
    203u;

  // pointer types
  using RawPtr =
    hric_msgs::msg::LocStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::msg::LocStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::msg::LocStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::msg::LocStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::msg::LocStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::msg::LocStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::msg::LocStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::msg::LocStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::msg::LocStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::msg::LocStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__msg__LocStatus
    std::shared_ptr<hric_msgs::msg::LocStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__msg__LocStatus
    std::shared_ptr<hric_msgs::msg::LocStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LocStatus_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const LocStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LocStatus_

// alias to use template instance with default allocator
using LocStatus =
  hric_msgs::msg::LocStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LocStatus_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LocStatus_<ContainerAllocator>::INITIALIZING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LocStatus_<ContainerAllocator>::RUNNING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LocStatus_<ContainerAllocator>::WEAK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LocStatus_<ContainerAllocator>::LOST;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LocStatus_<ContainerAllocator>::BLOCKED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t LocStatus_<ContainerAllocator>::NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t LocStatus_<ContainerAllocator>::UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t LocStatus_<ContainerAllocator>::TF_ERROR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t LocStatus_<ContainerAllocator>::SENSOR_ERROR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t LocStatus_<ContainerAllocator>::RELOCALIZATION_ERROR;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__LOC_STATUS__STRUCT_HPP_
