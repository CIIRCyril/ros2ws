// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from monitor_msgs:msg/ProcData.idl
// generated code does not contain a copyright notice
#include "monitor_msgs/msg/detail/proc_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `cpu_data`
#include "monitor_msgs/msg/detail/proc_cpu_data__functions.h"
// Member `io_data`
#include "monitor_msgs/msg/detail/proc_io_data__functions.h"
// Member `mem_data`
#include "monitor_msgs/msg/detail/proc_mem_data__functions.h"

bool
monitor_msgs__msg__ProcData__init(monitor_msgs__msg__ProcData * msg)
{
  if (!msg) {
    return false;
  }
  // pid
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    monitor_msgs__msg__ProcData__fini(msg);
    return false;
  }
  // active
  // cpu_data
  if (!monitor_msgs__msg__ProcCpuData__init(&msg->cpu_data)) {
    monitor_msgs__msg__ProcData__fini(msg);
    return false;
  }
  // io_data
  if (!monitor_msgs__msg__ProcIoData__init(&msg->io_data)) {
    monitor_msgs__msg__ProcData__fini(msg);
    return false;
  }
  // mem_data
  if (!monitor_msgs__msg__ProcMemData__init(&msg->mem_data)) {
    monitor_msgs__msg__ProcData__fini(msg);
    return false;
  }
  return true;
}

void
monitor_msgs__msg__ProcData__fini(monitor_msgs__msg__ProcData * msg)
{
  if (!msg) {
    return;
  }
  // pid
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // active
  // cpu_data
  monitor_msgs__msg__ProcCpuData__fini(&msg->cpu_data);
  // io_data
  monitor_msgs__msg__ProcIoData__fini(&msg->io_data);
  // mem_data
  monitor_msgs__msg__ProcMemData__fini(&msg->mem_data);
}

bool
monitor_msgs__msg__ProcData__are_equal(const monitor_msgs__msg__ProcData * lhs, const monitor_msgs__msg__ProcData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pid
  if (lhs->pid != rhs->pid) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // active
  if (lhs->active != rhs->active) {
    return false;
  }
  // cpu_data
  if (!monitor_msgs__msg__ProcCpuData__are_equal(
      &(lhs->cpu_data), &(rhs->cpu_data)))
  {
    return false;
  }
  // io_data
  if (!monitor_msgs__msg__ProcIoData__are_equal(
      &(lhs->io_data), &(rhs->io_data)))
  {
    return false;
  }
  // mem_data
  if (!monitor_msgs__msg__ProcMemData__are_equal(
      &(lhs->mem_data), &(rhs->mem_data)))
  {
    return false;
  }
  return true;
}

bool
monitor_msgs__msg__ProcData__copy(
  const monitor_msgs__msg__ProcData * input,
  monitor_msgs__msg__ProcData * output)
{
  if (!input || !output) {
    return false;
  }
  // pid
  output->pid = input->pid;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // active
  output->active = input->active;
  // cpu_data
  if (!monitor_msgs__msg__ProcCpuData__copy(
      &(input->cpu_data), &(output->cpu_data)))
  {
    return false;
  }
  // io_data
  if (!monitor_msgs__msg__ProcIoData__copy(
      &(input->io_data), &(output->io_data)))
  {
    return false;
  }
  // mem_data
  if (!monitor_msgs__msg__ProcMemData__copy(
      &(input->mem_data), &(output->mem_data)))
  {
    return false;
  }
  return true;
}

monitor_msgs__msg__ProcData *
monitor_msgs__msg__ProcData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__ProcData * msg = (monitor_msgs__msg__ProcData *)allocator.allocate(sizeof(monitor_msgs__msg__ProcData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(monitor_msgs__msg__ProcData));
  bool success = monitor_msgs__msg__ProcData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
monitor_msgs__msg__ProcData__destroy(monitor_msgs__msg__ProcData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    monitor_msgs__msg__ProcData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
monitor_msgs__msg__ProcData__Sequence__init(monitor_msgs__msg__ProcData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__ProcData * data = NULL;

  if (size) {
    data = (monitor_msgs__msg__ProcData *)allocator.zero_allocate(size, sizeof(monitor_msgs__msg__ProcData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = monitor_msgs__msg__ProcData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        monitor_msgs__msg__ProcData__fini(&data[i - 1]);
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
monitor_msgs__msg__ProcData__Sequence__fini(monitor_msgs__msg__ProcData__Sequence * array)
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
      monitor_msgs__msg__ProcData__fini(&array->data[i]);
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

monitor_msgs__msg__ProcData__Sequence *
monitor_msgs__msg__ProcData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  monitor_msgs__msg__ProcData__Sequence * array = (monitor_msgs__msg__ProcData__Sequence *)allocator.allocate(sizeof(monitor_msgs__msg__ProcData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = monitor_msgs__msg__ProcData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
monitor_msgs__msg__ProcData__Sequence__destroy(monitor_msgs__msg__ProcData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    monitor_msgs__msg__ProcData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
monitor_msgs__msg__ProcData__Sequence__are_equal(const monitor_msgs__msg__ProcData__Sequence * lhs, const monitor_msgs__msg__ProcData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!monitor_msgs__msg__ProcData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
monitor_msgs__msg__ProcData__Sequence__copy(
  const monitor_msgs__msg__ProcData__Sequence * input,
  monitor_msgs__msg__ProcData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(monitor_msgs__msg__ProcData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    monitor_msgs__msg__ProcData * data =
      (monitor_msgs__msg__ProcData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!monitor_msgs__msg__ProcData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          monitor_msgs__msg__ProcData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!monitor_msgs__msg__ProcData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
