// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from monitor_msgs:msg/ProcMemData.idl
// generated code does not contain a copyright notice
#include "monitor_msgs/msg/detail/proc_mem_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
monitor_msgs__msg__ProcMemData__init(monitor_msgs__msg__ProcMemData * msg)
{
  if (!msg) {
    return false;
  }
  // vmsize
  // vmrss
  // vmshared
  // vmexe
  // vmdata
  return true;
}

void
monitor_msgs__msg__ProcMemData__fini(monitor_msgs__msg__ProcMemData * msg)
{
  if (!msg) {
    return;
  }
  // vmsize
  // vmrss
  // vmshared
  // vmexe
  // vmdata
}

bool
monitor_msgs__msg__ProcMemData__are_equal(const monitor_msgs__msg__ProcMemData * lhs, const monitor_msgs__msg__ProcMemData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // vmsize
  if (lhs->vmsize != rhs->vmsize) {
    return false;
  }
  // vmrss
  if (lhs->vmrss != rhs->vmrss) {
    return false;
  }
  // vmshared
  if (lhs->vmshared != rhs->vmshared) {
    return false;
  }
  // vmexe
  if (lhs->vmexe != rhs->vmexe) {
    return false;
  }
  // vmdata
  if (lhs->vmdata != rhs->vmdata) {
    return false;
  }
  return true;
}

bool
monitor_msgs__msg__ProcMemData__copy(
  const monitor_msgs__msg__ProcMemData * input,
  monitor_msgs__msg__ProcMemData * output)
{
  if (!input || !output) {
    return false;
  }
  // vmsize
  output->vmsize = input->vmsize;
  // vmrss
  output->vmrss = input->vmrss;
  // vmshared
  output->vmshared = input->vmshared;
  // vmexe
  output->vmexe = input->vmexe;
  // vmdata
  output->vmdata = input->vmdata;
  return true;
}

monitor_msgs__msg__ProcMemData *
monitor_msgs__msg__ProcMemData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__ProcMemData * msg = (monitor_msgs__msg__ProcMemData *)allocator.allocate(sizeof(monitor_msgs__msg__ProcMemData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(monitor_msgs__msg__ProcMemData));
  bool success = monitor_msgs__msg__ProcMemData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
monitor_msgs__msg__ProcMemData__destroy(monitor_msgs__msg__ProcMemData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    monitor_msgs__msg__ProcMemData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
monitor_msgs__msg__ProcMemData__Sequence__init(monitor_msgs__msg__ProcMemData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__ProcMemData * data = NULL;

  if (size) {
    data = (monitor_msgs__msg__ProcMemData *)allocator.zero_allocate(size, sizeof(monitor_msgs__msg__ProcMemData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = monitor_msgs__msg__ProcMemData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        monitor_msgs__msg__ProcMemData__fini(&data[i - 1]);
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
monitor_msgs__msg__ProcMemData__Sequence__fini(monitor_msgs__msg__ProcMemData__Sequence * array)
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
      monitor_msgs__msg__ProcMemData__fini(&array->data[i]);
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

monitor_msgs__msg__ProcMemData__Sequence *
monitor_msgs__msg__ProcMemData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__ProcMemData__Sequence * array = (monitor_msgs__msg__ProcMemData__Sequence *)allocator.allocate(sizeof(monitor_msgs__msg__ProcMemData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = monitor_msgs__msg__ProcMemData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
monitor_msgs__msg__ProcMemData__Sequence__destroy(monitor_msgs__msg__ProcMemData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    monitor_msgs__msg__ProcMemData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
monitor_msgs__msg__ProcMemData__Sequence__are_equal(const monitor_msgs__msg__ProcMemData__Sequence * lhs, const monitor_msgs__msg__ProcMemData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!monitor_msgs__msg__ProcMemData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
monitor_msgs__msg__ProcMemData__Sequence__copy(
  const monitor_msgs__msg__ProcMemData__Sequence * input,
  monitor_msgs__msg__ProcMemData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(monitor_msgs__msg__ProcMemData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    monitor_msgs__msg__ProcMemData * data =
      (monitor_msgs__msg__ProcMemData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!monitor_msgs__msg__ProcMemData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          monitor_msgs__msg__ProcMemData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!monitor_msgs__msg__ProcMemData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
