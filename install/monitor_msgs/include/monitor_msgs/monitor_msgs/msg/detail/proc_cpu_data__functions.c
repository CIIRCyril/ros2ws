// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from monitor_msgs:msg/ProcCpuData.idl
// generated code does not contain a copyright notice
#include "monitor_msgs/msg/detail/proc_cpu_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
monitor_msgs__msg__ProcCpuData__init(monitor_msgs__msg__ProcCpuData * msg)
{
  if (!msg) {
    return false;
  }
  // num
  // used
  return true;
}

void
monitor_msgs__msg__ProcCpuData__fini(monitor_msgs__msg__ProcCpuData * msg)
{
  if (!msg) {
    return;
  }
  // num
  // used
}

bool
monitor_msgs__msg__ProcCpuData__are_equal(const monitor_msgs__msg__ProcCpuData * lhs, const monitor_msgs__msg__ProcCpuData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // num
  if (lhs->num != rhs->num) {
    return false;
  }
  // used
  if (lhs->used != rhs->used) {
    return false;
  }
  return true;
}

bool
monitor_msgs__msg__ProcCpuData__copy(
  const monitor_msgs__msg__ProcCpuData * input,
  monitor_msgs__msg__ProcCpuData * output)
{
  if (!input || !output) {
    return false;
  }
  // num
  output->num = input->num;
  // used
  output->used = input->used;
  return true;
}

monitor_msgs__msg__ProcCpuData *
monitor_msgs__msg__ProcCpuData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__ProcCpuData * msg = (monitor_msgs__msg__ProcCpuData *)allocator.allocate(sizeof(monitor_msgs__msg__ProcCpuData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(monitor_msgs__msg__ProcCpuData));
  bool success = monitor_msgs__msg__ProcCpuData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
monitor_msgs__msg__ProcCpuData__destroy(monitor_msgs__msg__ProcCpuData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    monitor_msgs__msg__ProcCpuData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
monitor_msgs__msg__ProcCpuData__Sequence__init(monitor_msgs__msg__ProcCpuData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__ProcCpuData * data = NULL;

  if (size) {
    data = (monitor_msgs__msg__ProcCpuData *)allocator.zero_allocate(size, sizeof(monitor_msgs__msg__ProcCpuData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = monitor_msgs__msg__ProcCpuData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        monitor_msgs__msg__ProcCpuData__fini(&data[i - 1]);
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
monitor_msgs__msg__ProcCpuData__Sequence__fini(monitor_msgs__msg__ProcCpuData__Sequence * array)
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
      monitor_msgs__msg__ProcCpuData__fini(&array->data[i]);
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

monitor_msgs__msg__ProcCpuData__Sequence *
monitor_msgs__msg__ProcCpuData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__ProcCpuData__Sequence * array = (monitor_msgs__msg__ProcCpuData__Sequence *)allocator.allocate(sizeof(monitor_msgs__msg__ProcCpuData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = monitor_msgs__msg__ProcCpuData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
monitor_msgs__msg__ProcCpuData__Sequence__destroy(monitor_msgs__msg__ProcCpuData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    monitor_msgs__msg__ProcCpuData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
monitor_msgs__msg__ProcCpuData__Sequence__are_equal(const monitor_msgs__msg__ProcCpuData__Sequence * lhs, const monitor_msgs__msg__ProcCpuData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!monitor_msgs__msg__ProcCpuData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
monitor_msgs__msg__ProcCpuData__Sequence__copy(
  const monitor_msgs__msg__ProcCpuData__Sequence * input,
  monitor_msgs__msg__ProcCpuData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(monitor_msgs__msg__ProcCpuData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    monitor_msgs__msg__ProcCpuData * data =
      (monitor_msgs__msg__ProcCpuData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!monitor_msgs__msg__ProcCpuData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          monitor_msgs__msg__ProcCpuData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!monitor_msgs__msg__ProcCpuData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
