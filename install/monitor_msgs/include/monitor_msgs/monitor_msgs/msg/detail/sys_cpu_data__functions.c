// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from monitor_msgs:msg/SysCpuData.idl
// generated code does not contain a copyright notice
#include "monitor_msgs/msg/detail/sys_cpu_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `proc_array`
#include "rosidl_runtime_c/string_functions.h"

bool
monitor_msgs__msg__SysCpuData__init(monitor_msgs__msg__SysCpuData * msg)
{
  if (!msg) {
    return false;
  }
  // cpu_num
  // cpu_used
  // proc_num
  // proc_array
  if (!rosidl_runtime_c__String__Sequence__init(&msg->proc_array, 0)) {
    monitor_msgs__msg__SysCpuData__fini(msg);
    return false;
  }
  return true;
}

void
monitor_msgs__msg__SysCpuData__fini(monitor_msgs__msg__SysCpuData * msg)
{
  if (!msg) {
    return;
  }
  // cpu_num
  // cpu_used
  // proc_num
  // proc_array
  rosidl_runtime_c__String__Sequence__fini(&msg->proc_array);
}

bool
monitor_msgs__msg__SysCpuData__are_equal(const monitor_msgs__msg__SysCpuData * lhs, const monitor_msgs__msg__SysCpuData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cpu_num
  if (lhs->cpu_num != rhs->cpu_num) {
    return false;
  }
  // cpu_used
  if (lhs->cpu_used != rhs->cpu_used) {
    return false;
  }
  // proc_num
  if (lhs->proc_num != rhs->proc_num) {
    return false;
  }
  // proc_array
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->proc_array), &(rhs->proc_array)))
  {
    return false;
  }
  return true;
}

bool
monitor_msgs__msg__SysCpuData__copy(
  const monitor_msgs__msg__SysCpuData * input,
  monitor_msgs__msg__SysCpuData * output)
{
  if (!input || !output) {
    return false;
  }
  // cpu_num
  output->cpu_num = input->cpu_num;
  // cpu_used
  output->cpu_used = input->cpu_used;
  // proc_num
  output->proc_num = input->proc_num;
  // proc_array
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->proc_array), &(output->proc_array)))
  {
    return false;
  }
  return true;
}

monitor_msgs__msg__SysCpuData *
monitor_msgs__msg__SysCpuData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__SysCpuData * msg = (monitor_msgs__msg__SysCpuData *)allocator.allocate(sizeof(monitor_msgs__msg__SysCpuData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(monitor_msgs__msg__SysCpuData));
  bool success = monitor_msgs__msg__SysCpuData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
monitor_msgs__msg__SysCpuData__destroy(monitor_msgs__msg__SysCpuData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    monitor_msgs__msg__SysCpuData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
monitor_msgs__msg__SysCpuData__Sequence__init(monitor_msgs__msg__SysCpuData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__SysCpuData * data = NULL;

  if (size) {
    data = (monitor_msgs__msg__SysCpuData *)allocator.zero_allocate(size, sizeof(monitor_msgs__msg__SysCpuData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = monitor_msgs__msg__SysCpuData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        monitor_msgs__msg__SysCpuData__fini(&data[i - 1]);
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
monitor_msgs__msg__SysCpuData__Sequence__fini(monitor_msgs__msg__SysCpuData__Sequence * array)
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
      monitor_msgs__msg__SysCpuData__fini(&array->data[i]);
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

monitor_msgs__msg__SysCpuData__Sequence *
monitor_msgs__msg__SysCpuData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__SysCpuData__Sequence * array = (monitor_msgs__msg__SysCpuData__Sequence *)allocator.allocate(sizeof(monitor_msgs__msg__SysCpuData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = monitor_msgs__msg__SysCpuData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
monitor_msgs__msg__SysCpuData__Sequence__destroy(monitor_msgs__msg__SysCpuData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    monitor_msgs__msg__SysCpuData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
monitor_msgs__msg__SysCpuData__Sequence__are_equal(const monitor_msgs__msg__SysCpuData__Sequence * lhs, const monitor_msgs__msg__SysCpuData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!monitor_msgs__msg__SysCpuData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
monitor_msgs__msg__SysCpuData__Sequence__copy(
  const monitor_msgs__msg__SysCpuData__Sequence * input,
  monitor_msgs__msg__SysCpuData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(monitor_msgs__msg__SysCpuData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    monitor_msgs__msg__SysCpuData * data =
      (monitor_msgs__msg__SysCpuData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!monitor_msgs__msg__SysCpuData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          monitor_msgs__msg__SysCpuData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!monitor_msgs__msg__SysCpuData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
