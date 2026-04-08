// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from monitor_msgs:msg/SysIoData.idl
// generated code does not contain a copyright notice
#include "monitor_msgs/msg/detail/sys_io_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
monitor_msgs__msg__SysIoData__init(monitor_msgs__msg__SysIoData * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->timestamp)) {
    monitor_msgs__msg__SysIoData__fini(msg);
    return false;
  }
  // disk_read
  // disk_write
  return true;
}

void
monitor_msgs__msg__SysIoData__fini(monitor_msgs__msg__SysIoData * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  builtin_interfaces__msg__Time__fini(&msg->timestamp);
  // disk_read
  // disk_write
}

bool
monitor_msgs__msg__SysIoData__are_equal(const monitor_msgs__msg__SysIoData * lhs, const monitor_msgs__msg__SysIoData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->timestamp), &(rhs->timestamp)))
  {
    return false;
  }
  // disk_read
  if (lhs->disk_read != rhs->disk_read) {
    return false;
  }
  // disk_write
  if (lhs->disk_write != rhs->disk_write) {
    return false;
  }
  return true;
}

bool
monitor_msgs__msg__SysIoData__copy(
  const monitor_msgs__msg__SysIoData * input,
  monitor_msgs__msg__SysIoData * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->timestamp), &(output->timestamp)))
  {
    return false;
  }
  // disk_read
  output->disk_read = input->disk_read;
  // disk_write
  output->disk_write = input->disk_write;
  return true;
}

monitor_msgs__msg__SysIoData *
monitor_msgs__msg__SysIoData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__SysIoData * msg = (monitor_msgs__msg__SysIoData *)allocator.allocate(sizeof(monitor_msgs__msg__SysIoData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(monitor_msgs__msg__SysIoData));
  bool success = monitor_msgs__msg__SysIoData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
monitor_msgs__msg__SysIoData__destroy(monitor_msgs__msg__SysIoData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    monitor_msgs__msg__SysIoData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
monitor_msgs__msg__SysIoData__Sequence__init(monitor_msgs__msg__SysIoData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__SysIoData * data = NULL;

  if (size) {
    data = (monitor_msgs__msg__SysIoData *)allocator.zero_allocate(size, sizeof(monitor_msgs__msg__SysIoData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = monitor_msgs__msg__SysIoData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        monitor_msgs__msg__SysIoData__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
monitor_msgs__msg__SysIoData__Sequence__fini(monitor_msgs__msg__SysIoData__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      monitor_msgs__msg__SysIoData__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

monitor_msgs__msg__SysIoData__Sequence *
monitor_msgs__msg__SysIoData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__SysIoData__Sequence * array = (monitor_msgs__msg__SysIoData__Sequence *)allocator.allocate(sizeof(monitor_msgs__msg__SysIoData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = monitor_msgs__msg__SysIoData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
monitor_msgs__msg__SysIoData__Sequence__destroy(monitor_msgs__msg__SysIoData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    monitor_msgs__msg__SysIoData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
monitor_msgs__msg__SysIoData__Sequence__are_equal(const monitor_msgs__msg__SysIoData__Sequence * lhs, const monitor_msgs__msg__SysIoData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!monitor_msgs__msg__SysIoData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
monitor_msgs__msg__SysIoData__Sequence__copy(
  const monitor_msgs__msg__SysIoData__Sequence * input,
  monitor_msgs__msg__SysIoData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(monitor_msgs__msg__SysIoData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    monitor_msgs__msg__SysIoData * data =
      (monitor_msgs__msg__SysIoData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!monitor_msgs__msg__SysIoData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          monitor_msgs__msg__SysIoData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!monitor_msgs__msg__SysIoData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
