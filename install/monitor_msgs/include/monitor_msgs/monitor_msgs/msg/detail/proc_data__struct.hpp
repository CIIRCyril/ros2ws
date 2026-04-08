// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from monitor_msgs:msg/ProcData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__PROC_DATA__STRUCT_HPP_
#define MONITOR_MSGS__MSG__DETAIL__PROC_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'cpu_data'
#include "monitor_msgs/msg/detail/proc_cpu_data__struct.hpp"
// Member 'io_data'
#include "monitor_msgs/msg/detail/proc_io_data__struct.hpp"
// Member 'mem_data'
#include "monitor_msgs/msg/detail/proc_mem_data__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__monitor_msgs__msg__ProcData __attribute__((deprecated))
#else
# define DEPRECATED__monitor_msgs__msg__ProcData __declspec(deprecated)
#endif

namespace monitor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProcData_
{
  using Type = ProcData_<ContainerAllocator>;

  explicit ProcData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cpu_data(_init),
    io_data(_init),
    mem_data(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pid = 0ul;
      this->name = "";
      this->active = false;
    }
  }

  explicit ProcData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    cpu_data(_alloc, _init),
    io_data(_alloc, _init),
    mem_data(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pid = 0ul;
      this->name = "";
      this->active = false;
    }
  }

  // field types and members
  using _pid_type =
    uint32_t;
  _pid_type pid;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _active_type =
    bool;
  _active_type active;
  using _cpu_data_type =
    monitor_msgs::msg::ProcCpuData_<ContainerAllocator>;
  _cpu_data_type cpu_data;
  using _io_data_type =
    monitor_msgs::msg::ProcIoData_<ContainerAllocator>;
  _io_data_type io_data;
  using _mem_data_type =
    monitor_msgs::msg::ProcMemData_<ContainerAllocator>;
  _mem_data_type mem_data;

  // setters for named parameter idiom
  Type & set__pid(
    const uint32_t & _arg)
  {
    this->pid = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__active(
    const bool & _arg)
  {
    this->active = _arg;
    return *this;
  }
  Type & set__cpu_data(
    const monitor_msgs::msg::ProcCpuData_<ContainerAllocator> & _arg)
  {
    this->cpu_data = _arg;
    return *this;
  }
  Type & set__io_data(
    const monitor_msgs::msg::ProcIoData_<ContainerAllocator> & _arg)
  {
    this->io_data = _arg;
    return *this;
  }
  Type & set__mem_data(
    const monitor_msgs::msg::ProcMemData_<ContainerAllocator> & _arg)
  {
    this->mem_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    monitor_msgs::msg::ProcData_<ContainerAllocator> *;
  using ConstRawPtr =
    const monitor_msgs::msg::ProcData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<monitor_msgs::msg::ProcData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<monitor_msgs::msg::ProcData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::ProcData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::ProcData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::ProcData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::ProcData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<monitor_msgs::msg::ProcData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<monitor_msgs::msg::ProcData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__monitor_msgs__msg__ProcData
    std::shared_ptr<monitor_msgs::msg::ProcData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__monitor_msgs__msg__ProcData
    std::shared_ptr<monitor_msgs::msg::ProcData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcData_ & other) const
  {
    if (this->pid != other.pid) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->active != other.active) {
      return false;
    }
    if (this->cpu_data != other.cpu_data) {
      return false;
    }
    if (this->io_data != other.io_data) {
      return false;
    }
    if (this->mem_data != other.mem_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcData_

// alias to use template instance with default allocator
using ProcData =
  monitor_msgs::msg::ProcData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__PROC_DATA__STRUCT_HPP_
