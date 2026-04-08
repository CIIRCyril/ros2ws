// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from monitor_msgs:msg/ProcCpuData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_CPU_DATA__STRUCT_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_CPU_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__monitor_msgs__msg__ProcCpuData __attribute__((deprecated))
#else
# define DEPRECATED__monitor_msgs__msg__ProcCpuData __declspec(deprecated)
#endif

namespace monitor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProcCpuData_
{
  using Type = ProcCpuData_<ContainerAllocator>;

  explicit ProcCpuData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0ul;
      this->used = 0.0;
    }
  }

  explicit ProcCpuData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0ul;
      this->used = 0.0;
    }
  }

  // field types and members
  using _num_type =
    uint32_t;
  _num_type num;
  using _used_type =
    double;
  _used_type used;

  // setters for named parameter idiom
  Type & set__num(
    const uint32_t & _arg)
  {
    this->num = _arg;
    return *this;
  }
  Type & set__used(
    const double & _arg)
  {
    this->used = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    monitor_msgs::msg::ProcCpuData_<ContainerAllocator> *;
  using ConstRawPtr =
    const monitor_msgs::msg::ProcCpuData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<monitor_msgs::msg::ProcCpuData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<monitor_msgs::msg::ProcCpuData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::ProcCpuData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::ProcCpuData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::ProcCpuData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::ProcCpuData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<monitor_msgs::msg::ProcCpuData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<monitor_msgs::msg::ProcCpuData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__monitor_msgs__msg__ProcCpuData
    std::shared_ptr<monitor_msgs::msg::ProcCpuData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__monitor_msgs__msg__ProcCpuData
    std::shared_ptr<monitor_msgs::msg::ProcCpuData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcCpuData_ & other) const
  {
    if (this->num != other.num) {
      return false;
    }
    if (this->used != other.used) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcCpuData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcCpuData_

// alias to use template instance with default allocator
using ProcCpuData =
  monitor_msgs::msg::ProcCpuData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_CPU_DATA__STRUCT_HPP_
