// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from monitor_msgs:msg/ProcIoData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_IO_DATA__STRUCT_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_IO_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__monitor_msgs__msg__ProcIoData __attribute__((deprecated))
#else
# define DEPRECATED__monitor_msgs__msg__ProcIoData __declspec(deprecated)
#endif

namespace monitor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProcIoData_
{
  using Type = ProcIoData_<ContainerAllocator>;

  explicit ProcIoData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->read = 0.0;
      this->write = 0.0;
      this->total_read = 0.0;
      this->total_write = 0.0;
    }
  }

  explicit ProcIoData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->read = 0.0;
      this->write = 0.0;
      this->total_read = 0.0;
      this->total_write = 0.0;
    }
  }

  // field types and members
  using _read_type =
    double;
  _read_type read;
  using _write_type =
    double;
  _write_type write;
  using _total_read_type =
    double;
  _total_read_type total_read;
  using _total_write_type =
    double;
  _total_write_type total_write;

  // setters for named parameter idiom
  Type & set__read(
    const double & _arg)
  {
    this->read = _arg;
    return *this;
  }
  Type & set__write(
    const double & _arg)
  {
    this->write = _arg;
    return *this;
  }
  Type & set__total_read(
    const double & _arg)
  {
    this->total_read = _arg;
    return *this;
  }
  Type & set__total_write(
    const double & _arg)
  {
    this->total_write = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    monitor_msgs::msg::ProcIoData_<ContainerAllocator> *;
  using ConstRawPtr =
    const monitor_msgs::msg::ProcIoData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<monitor_msgs::msg::ProcIoData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<monitor_msgs::msg::ProcIoData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::ProcIoData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::ProcIoData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::ProcIoData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::ProcIoData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<monitor_msgs::msg::ProcIoData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<monitor_msgs::msg::ProcIoData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__monitor_msgs__msg__ProcIoData
    std::shared_ptr<monitor_msgs::msg::ProcIoData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__monitor_msgs__msg__ProcIoData
    std::shared_ptr<monitor_msgs::msg::ProcIoData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcIoData_ & other) const
  {
    if (this->read != other.read) {
      return false;
    }
    if (this->write != other.write) {
      return false;
    }
    if (this->total_read != other.total_read) {
      return false;
    }
    if (this->total_write != other.total_write) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcIoData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcIoData_

// alias to use template instance with default allocator
using ProcIoData =
  monitor_msgs::msg::ProcIoData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_IO_DATA__STRUCT_HPP_
