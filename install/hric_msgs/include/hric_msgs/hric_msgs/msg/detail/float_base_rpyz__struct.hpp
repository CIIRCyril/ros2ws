// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hric_msgs:msg/FloatBaseRPYZ.idl
// generated code does not contain a copyright notice

#ifndef HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__STRUCT_HPP_
#define HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hric_msgs__msg__FloatBaseRPYZ __attribute__((deprecated))
#else
# define DEPRECATED__hric_msgs__msg__FloatBaseRPYZ __declspec(deprecated)
#endif

namespace hric_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FloatBaseRPYZ_
{
  using Type = FloatBaseRPYZ_<ContainerAllocator>;

  explicit FloatBaseRPYZ_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
      this->z = 0.0;
    }
  }

  explicit FloatBaseRPYZ_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
      this->z = 0.0;
    }
  }

  // field types and members
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _yaw_type =
    double;
  _yaw_type yaw;
  using _z_type =
    double;
  _z_type z;

  // setters for named parameter idiom
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hric_msgs::msg::FloatBaseRPYZ_<ContainerAllocator> *;
  using ConstRawPtr =
    const hric_msgs::msg::FloatBaseRPYZ_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hric_msgs::msg::FloatBaseRPYZ_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hric_msgs::msg::FloatBaseRPYZ_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hric_msgs::msg::FloatBaseRPYZ_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::msg::FloatBaseRPYZ_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hric_msgs::msg::FloatBaseRPYZ_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hric_msgs::msg::FloatBaseRPYZ_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hric_msgs::msg::FloatBaseRPYZ_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hric_msgs::msg::FloatBaseRPYZ_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hric_msgs__msg__FloatBaseRPYZ
    std::shared_ptr<hric_msgs::msg::FloatBaseRPYZ_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hric_msgs__msg__FloatBaseRPYZ
    std::shared_ptr<hric_msgs::msg::FloatBaseRPYZ_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FloatBaseRPYZ_ & other) const
  {
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const FloatBaseRPYZ_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FloatBaseRPYZ_

// alias to use template instance with default allocator
using FloatBaseRPYZ =
  hric_msgs::msg::FloatBaseRPYZ_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hric_msgs

#endif  // HRIC_MSGS__MSG__DETAIL__FLOAT_BASE_RPYZ__STRUCT_HPP_
