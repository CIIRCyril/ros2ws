// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from monitor_msgs:msg/SysMemData.idl
// generated code does not contain a copyright notice
#include "monitor_msgs/msg/detail/sys_mem_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
monitor_msgs__msg__SysMemData__init(monitor_msgs__msg__SysMemData * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->timestamp)) {
    monitor_msgs__msg__SysMemData__fini(msg);
    return false;
  }
  // total
  // used
  // free
  // shared
  // available
  // buffers
  // cached
  // sreclaimable
  // swap_total
  // swap_free
  return true;
}

void
monitor_msgs__msg__SysMemData__fini(monitor_msgs__msg__SysMemData * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  builtin_interfaces__msg__Time__fini(&msg->timestamp);
  // total
  // used
  // free
  // shared
  // available
  // buffers
  // cached
  // sreclaimable
  // swap_total
  // swap_free
}

bool
monitor_msgs__msg__SysMemData__are_equal(const monitor_msgs__msg__SysMemData * lhs, const monitor_msgs__msg__SysMemData * rhs)
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
  // total
  if (lhs->total != rhs->total) {
    return false;
  }
  // used
  if (lhs->used != rhs->used) {
    return false;
  }
  // free
  if (lhs->free != rhs->free) {
    return false;
  }
  // shared
  if (lhs->shared != rhs->shared) {
    return false;
  }
  // available
  if (lhs->available != rhs->available) {
    return false;
  }
  // buffers
  if (lhs->buffers != rhs->buffers) {
    return false;
  }
  // cached
  if (lhs->cached != rhs->cached) {
    return false;
  }
  // sreclaimable
  if (lhs->sreclaimable != rhs->sreclaimable) {
    return false;
  }
  // swap_total
  if (lhs->swap_total != rhs->swap_total) {
    return false;
  }
  // swap_free
  if (lhs->swap_free != rhs->swap_free) {
    return false;
  }
  return true;
}

bool
monitor_msgs__msg__SysMemData__copy(
  const monitor_msgs__msg__SysMemData * input,
  monitor_msgs__msg__SysMemData * output)
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
  // total
  output->total = input->total;
  // used
  output->used = input->used;
  // free
  output->free = input->free;
  // shared
  output->shared = input->shared;
  // available
  output->available = input->available;
  // buffers
  output->buffers = input->buffers;
  // cached
  output->cached = input->cached;
  // sreclaimable
  output->sreclaimable = input->sreclaimable;
  // swap_total
  output->swap_total = input->swap_total;
  // swap_free
  output->swap_free = input->swap_free;
  return true;
}

monitor_msgs__msg__SysMemData *
monitor_msgs__msg__SysMemData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__SysMemData * msg = (monitor_msgs__msg__SysMemData *)allocator.allocate(sizeof(monitor_msgs__msg__SysMemData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(monitor_msgs__msg__SysMemData));
  bool success = monitor_msgs__msg__SysMemData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
monitor_msgs__msg__SysMemData__destroy(monitor_msgs__msg__SysMemData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    monitor_msgs__msg__SysMemData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
monitor_msgs__msg__SysMemData__Sequence__init(monitor_msgs__msg__SysMemData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__SysMemData * data = NULL;

  if (size) {
    data = (monitor_msgs__msg__SysMemData *)allocator.zero_allocate(size, sizeof(monitor_msgs__msg__SysMemData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = monitor_msgs__msg__SysMemData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        monitor_msgs__msg__SysMemData__fini(&data[i - 1]);
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
monitor_msgs__msg__SysMemData__Sequence__fini(monitor_msgs__msg__SysMemData__Sequence * array)
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
      monitor_msgs__msg__SysMemData__fini(&array->data[i]);
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

monitor_msgs__msg__SysMemData__Sequence *
monitor_msgs__msg__SysMemData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__SysMemData__Sequence * array = (monitor_msgs__msg__SysMemData__Sequence *)allocator.allocate(sizeof(monitor_msgs__msg__SysMemData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = monitor_msgs__msg__SysMemData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
monitor_msgs__msg__SysMemData__Sequence__destroy(monitor_msgs__msg__SysMemData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    monitor_msgs__msg__SysMemData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
monitor_msgs__msg__SysMemData__Sequence__are_equal(const monitor_msgs__msg__SysMemData__Sequence * lhs, const monitor_msgs__msg__SysMemData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!monitor_msgs__msg__SysMemData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
monitor_msgs__msg__SysMemData__Sequence__copy(
  const monitor_msgs__msg__SysMemData__Sequence * input,
  monitor_msgs__msg__SysMemData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(monitor_msgs__msg__SysMemData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    monitor_msgs__msg__SysMemData * data =
      (monitor_msgs__msg__SysMemData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!monitor_msgs__msg__SysMemData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          monitor_msgs__msg__SysMemData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!monitor_msgs__msg__SysMemData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
