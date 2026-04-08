// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from monitor_msgs:msg/ProcMemData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__STRUCT_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__monitor_msgs__msg__ProcMemData __attribute__((deprecated))
#else
# define DEPRECATED__monitor_msgs__msg__ProcMemData __declspec(deprecated)
#endif

namespace monitor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProcMemData_
{
  using Type = ProcMemData_<ContainerAllocator>;

  explicit ProcMemData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vmsize = 0ul;
      this->vmrss = 0ul;
      this->vmshared = 0ul;
      this->vmexe = 0ul;
      this->vmdata = 0ul;
    }
  }

  explicit ProcMemData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vmsize = 0ul;
      this->vmrss = 0ul;
      this->vmshared = 0ul;
      this->vmexe = 0ul;
      this->vmdata = 0ul;
    }
  }

  // field types and members
  using _vmsize_type =
    uint32_t;
  _vmsize_type vmsize;
  using _vmrss_type =
    uint32_t;
  _vmrss_type vmrss;
  using _vmshared_type =
    uint32_t;
  _vmshared_type vmshared;
  using _vmexe_type =
    uint32_t;
  _vmexe_type vmexe;
  using _vmdata_type =
    uint32_t;
  _vmdata_type vmdata;

  // setters for named parameter idiom
  Type & set__vmsize(
    const uint32_t & _arg)
  {
    this->vmsize = _arg;
    return *this;
  }
  Type & set__vmrss(
    const uint32_t & _arg)
  {
    this->vmrss = _arg;
    return *this;
  }
  Type & set__vmshared(
    const uint32_t & _arg)
  {
    this->vmshared = _arg;
    return *this;
  }
  Type & set__vmexe(
    const uint32_t & _arg)
  {
    this->vmexe = _arg;
    return *this;
  }
  Type & set__vmdata(
    const uint32_t & _arg)
  {
    this->vmdata = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    monitor_msgs::msg::ProcMemData_<ContainerAllocator> *;
  using ConstRawPtr =
    const monitor_msgs::msg::ProcMemData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<monitor_msgs::msg::ProcMemData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<monitor_msgs::msg::ProcMemData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::ProcMemData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::ProcMemData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::ProcMemData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::ProcMemData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<monitor_msgs::msg::ProcMemData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<monitor_msgs::msg::ProcMemData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__monitor_msgs__msg__ProcMemData
    std::shared_ptr<monitor_msgs::msg::ProcMemData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__monitor_msgs__msg__ProcMemData
    std::shared_ptr<monitor_msgs::msg::ProcMemData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcMemData_ & other) const
  {
    if (this->vmsize != other.vmsize) {
      return false;
    }
    if (this->vmrss != other.vmrss) {
      return false;
    }
    if (this->vmshared != other.vmshared) {
      return false;
    }
    if (this->vmexe != other.vmexe) {
      return false;
    }
    if (this->vmdata != other.vmdata) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcMemData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcMemData_

// alias to use template instance with default allocator
using ProcMemData =
  monitor_msgs::msg::ProcMemData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_MEM_DATA__STRUCT_HPP_
