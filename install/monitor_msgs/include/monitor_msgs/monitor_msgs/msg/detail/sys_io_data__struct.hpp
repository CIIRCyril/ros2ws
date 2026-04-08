// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from monitor_msgs:msg/SysIoData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_IO_DATA__STRUCT_HPP_
#define MONITOR_MSGS__MSG__DETAIL__SYS_IO_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__monitor_msgs__msg__SysIoData __attribute__((deprecated))
#else
# define DEPRECATED__monitor_msgs__msg__SysIoData __declspec(deprecated)
#endif

namespace monitor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SysIoData_
{
  using Type = SysIoData_<ContainerAllocator>;

  explicit SysIoData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->disk_read = 0.0;
      this->disk_write = 0.0;
    }
  }

  explicit SysIoData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->disk_read = 0.0;
      this->disk_write = 0.0;
    }
  }

  // field types and members
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;
  using _disk_read_type =
    double;
  _disk_read_type disk_read;
  using _disk_write_type =
    double;
  _disk_write_type disk_write;

  // setters for named parameter idiom
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__disk_read(
    const double & _arg)
  {
    this->disk_read = _arg;
    return *this;
  }
  Type & set__disk_write(
    const double & _arg)
  {
    this->disk_write = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    monitor_msgs::msg::SysIoData_<ContainerAllocator> *;
  using ConstRawPtr =
    const monitor_msgs::msg::SysIoData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<monitor_msgs::msg::SysIoData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<monitor_msgs::msg::SysIoData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::SysIoData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::SysIoData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::SysIoData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::SysIoData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<monitor_msgs::msg::SysIoData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<monitor_msgs::msg::SysIoData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__monitor_msgs__msg__SysIoData
    std::shared_ptr<monitor_msgs::msg::SysIoData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__monitor_msgs__msg__SysIoData
    std::shared_ptr<monitor_msgs::msg::SysIoData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SysIoData_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->disk_read != other.disk_read) {
      return false;
    }
    if (this->disk_write != other.disk_write) {
      return false;
    }
    return true;
  }
  bool operator!=(const SysIoData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SysIoData_

// alias to use template instance with default allocator
using SysIoData =
  monitor_msgs::msg::SysIoData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_IO_DATA__STRUCT_HPP_
