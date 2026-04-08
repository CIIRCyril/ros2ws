// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hric_msgs:msg/MarkerInfo.idl
// generated code does not contain a copyright notice
#include "hric_msgs/msg/detail/marker_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
// Member `map_id`
// Member `floor`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose2_d__functions.h"

bool
hric_msgs__msg__MarkerInfo__init(hric_msgs__msg__MarkerInfo * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    hric_msgs__msg__MarkerInfo__fini(msg);
    return false;
  }
  // map_id
  if (!rosidl_runtime_c__String__init(&msg->map_id)) {
    hric_msgs__msg__MarkerInfo__fini(msg);
    return false;
  }
  // floor
  if (!rosidl_runtime_c__String__init(&msg->floor)) {
    hric_msgs__msg__MarkerInfo__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose2D__init(&msg->pose)) {
    hric_msgs__msg__MarkerInfo__fini(msg);
    return false;
  }
  return true;
}

void
hric_msgs__msg__MarkerInfo__fini(hric_msgs__msg__MarkerInfo * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // map_id
  rosidl_runtime_c__String__fini(&msg->map_id);
  // floor
  rosidl_runtime_c__String__fini(&msg->floor);
  // pose
  geometry_msgs__msg__Pose2D__fini(&msg->pose);
}

bool
hric_msgs__msg__MarkerInfo__are_equal(const hric_msgs__msg__MarkerInfo * lhs, const hric_msgs__msg__MarkerInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // map_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->map_id), &(rhs->map_id)))
  {
    return false;
  }
  // floor
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->floor), &(rhs->floor)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose2D__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
hric_msgs__msg__MarkerInfo__copy(
  const hric_msgs__msg__MarkerInfo * input,
  hric_msgs__msg__MarkerInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // map_id
  if (!rosidl_runtime_c__String__copy(
      &(input->map_id), &(output->map_id)))
  {
    return false;
  }
  // floor
  if (!rosidl_runtime_c__String__copy(
      &(input->floor), &(output->floor)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose2D__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

hric_msgs__msg__MarkerInfo *
hric_msgs__msg__MarkerInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__msg__MarkerInfo * msg = (hric_msgs__msg__MarkerInfo *)allocator.allocate(sizeof(hric_msgs__msg__MarkerInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hric_msgs__msg__MarkerInfo));
  bool success = hric_msgs__msg__MarkerInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hric_msgs__msg__MarkerInfo__destroy(hric_msgs__msg__MarkerInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hric_msgs__msg__MarkerInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hric_msgs__msg__MarkerInfo__Sequence__init(hric_msgs__msg__MarkerInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__msg__MarkerInfo * data = NULL;

  if (size) {
    data = (hric_msgs__msg__MarkerInfo *)allocator.zero_allocate(size, sizeof(hric_msgs__msg__MarkerInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hric_msgs__msg__MarkerInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hric_msgs__msg__MarkerInfo__fini(&data[i - 1]);
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
hric_msgs__msg__MarkerInfo__Sequence__fini(hric_msgs__msg__MarkerInfo__Sequence * array)
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
      hric_msgs__msg__MarkerInfo__fini(&array->data[i]);
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

hric_msgs__msg__MarkerInfo__Sequence *
hric_msgs__msg__MarkerInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hric_msgs__msg__MarkerInfo__Sequence * array = (hric_msgs__msg__MarkerInfo__Sequence *)allocator.allocate(sizeof(hric_msgs__msg__MarkerInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hric_msgs__msg__MarkerInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hric_msgs__msg__MarkerInfo__Sequence__destroy(hric_msgs__msg__MarkerInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hric_msgs__msg__MarkerInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hric_msgs__msg__MarkerInfo__Sequence__are_equal(const hric_msgs__msg__MarkerInfo__Sequence * lhs, const hric_msgs__msg__MarkerInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hric_msgs__msg__MarkerInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hric_msgs__msg__MarkerInfo__Sequence__copy(
  const hric_msgs__msg__MarkerInfo__Sequence * input,
  hric_msgs__msg__MarkerInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hric_msgs__msg__MarkerInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hric_msgs__msg__MarkerInfo * data =
      (hric_msgs__msg__MarkerInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hric_msgs__msg__MarkerInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hric_msgs__msg__MarkerInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hric_msgs__msg__MarkerInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
