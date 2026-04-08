// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from monitor_msgs:msg/SysMemData.idl
// generated code does not contain a copyright notice

#ifndef MONITOR_MSGS__MSG__DETAIL__SYS_MEM_DATA__STRUCT_HPP_
#define MONITOR_MSGS__MSG__DETAIL__SYS_MEM_DATA__STRUCT_HPP_

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
# define DEPRECATED__monitor_msgs__msg__SysMemData __attribute__((deprecated))
#else
# define DEPRECATED__monitor_msgs__msg__SysMemData __declspec(deprecated)
#endif

namespace monitor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SysMemData_
{
  using Type = SysMemData_<ContainerAllocator>;

  explicit SysMemData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->total = 0ull;
      this->used = 0ull;
      this->free = 0ull;
      this->shared = 0ull;
      this->available = 0ull;
      this->buffers = 0ull;
      this->cached = 0ull;
      this->sreclaimable = 0ull;
      this->swap_total = 0ull;
      this->swap_free = 0ull;
    }
  }

  explicit SysMemData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->total = 0ull;
      this->used = 0ull;
      this->free = 0ull;
      this->shared = 0ull;
      this->available = 0ull;
      this->buffers = 0ull;
      this->cached = 0ull;
      this->sreclaimable = 0ull;
      this->swap_total = 0ull;
      this->swap_free = 0ull;
    }
  }

  // field types and members
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;
  using _total_type =
    uint64_t;
  _total_type total;
  using _used_type =
    uint64_t;
  _used_type used;
  using _free_type =
    uint64_t;
  _free_type free;
  using _shared_type =
    uint64_t;
  _shared_type shared;
  using _available_type =
    uint64_t;
  _available_type available;
  using _buffers_type =
    uint64_t;
  _buffers_type buffers;
  using _cached_type =
    uint64_t;
  _cached_type cached;
  using _sreclaimable_type =
    uint64_t;
  _sreclaimable_type sreclaimable;
  using _swap_total_type =
    uint64_t;
  _swap_total_type swap_total;
  using _swap_free_type =
    uint64_t;
  _swap_free_type swap_free;

  // setters for named parameter idiom
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__total(
    const uint64_t & _arg)
  {
    this->total = _arg;
    return *this;
  }
  Type & set__used(
    const uint64_t & _arg)
  {
    this->used = _arg;
    return *this;
  }
  Type & set__free(
    const uint64_t & _arg)
  {
    this->free = _arg;
    return *this;
  }
  Type & set__shared(
    const uint64_t & _arg)
  {
    this->shared = _arg;
    return *this;
  }
  Type & set__available(
    const uint64_t & _arg)
  {
    this->available = _arg;
    return *this;
  }
  Type & set__buffers(
    const uint64_t & _arg)
  {
    this->buffers = _arg;
    return *this;
  }
  Type & set__cached(
    const uint64_t & _arg)
  {
    this->cached = _arg;
    return *this;
  }
  Type & set__sreclaimable(
    const uint64_t & _arg)
  {
    this->sreclaimable = _arg;
    return *this;
  }
  Type & set__swap_total(
    const uint64_t & _arg)
  {
    this->swap_total = _arg;
    return *this;
  }
  Type & set__swap_free(
    const uint64_t & _arg)
  {
    this->swap_free = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    monitor_msgs::msg::SysMemData_<ContainerAllocator> *;
  using ConstRawPtr =
    const monitor_msgs::msg::SysMemData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<monitor_msgs::msg::SysMemData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<monitor_msgs::msg::SysMemData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::SysMemData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::SysMemData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      monitor_msgs::msg::SysMemData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<monitor_msgs::msg::SysMemData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<monitor_msgs::msg::SysMemData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<monitor_msgs::msg::SysMemData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__monitor_msgs__msg__SysMemData
    std::shared_ptr<monitor_msgs::msg::SysMemData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__monitor_msgs__msg__SysMemData
    std::shared_ptr<monitor_msgs::msg::SysMemData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SysMemData_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->total != other.total) {
      return false;
    }
    if (this->used != other.used) {
      return false;
    }
    if (this->free != other.free) {
      return false;
    }
    if (this->shared != other.shared) {
      return false;
    }
    if (this->available != other.available) {
      return false;
    }
    if (this->buffers != other.buffers) {
      return false;
    }
    if (this->cached != other.cached) {
      return false;
    }
    if (this->sreclaimable != other.sreclaimable) {
      return false;
    }
    if (this->swap_total != other.swap_total) {
      return false;
    }
    if (this->swap_free != other.swap_free) {
      return false;
    }
    return true;
  }
  bool operator!=(const SysMemData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SysMemData_

// alias to use template instance with default allocator
using SysMemData =
  monitor_msgs::msg::SysMemData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace monitor_msgs

#endif  // MONITOR_MSGS__MSG__DETAIL__SYS_MEM_DATA__STRUCT_HPP_
