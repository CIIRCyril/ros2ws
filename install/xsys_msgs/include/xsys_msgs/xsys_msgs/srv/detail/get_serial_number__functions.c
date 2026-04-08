// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xsys_msgs:srv/GetSerialNumber.idl
// generated code does not contain a copyright notice
#include "xsys_msgs/srv/detail/get_serial_number__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
xsys_msgs__srv__GetSerialNumber_Request__init(xsys_msgs__srv__GetSerialNumber_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
xsys_msgs__srv__GetSerialNumber_Request__fini(xsys_msgs__srv__GetSerialNumber_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
xsys_msgs__srv__GetSerialNumber_Request__are_equal(const xsys_msgs__srv__GetSerialNumber_Request * lhs, const xsys_msgs__srv__GetSerialNumber_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
xsys_msgs__srv__GetSerialNumber_Request__copy(
  const xsys_msgs__srv__GetSerialNumber_Request * input,
  xsys_msgs__srv__GetSerialNumber_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

xsys_msgs__srv__GetSerialNumber_Request *
xsys_msgs__srv__GetSerialNumber_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsys_msgs__srv__GetSerialNumber_Request * msg = (xsys_msgs__srv__GetSerialNumber_Request *)allocator.allocate(sizeof(xsys_msgs__srv__GetSerialNumber_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsys_msgs__srv__GetSerialNumber_Request));
  bool success = xsys_msgs__srv__GetSerialNumber_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
xsys_msgs__srv__GetSerialNumber_Request__destroy(xsys_msgs__srv__GetSerialNumber_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    xsys_msgs__srv__GetSerialNumber_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
xsys_msgs__srv__GetSerialNumber_Request__Sequence__init(xsys_msgs__srv__GetSerialNumber_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsys_msgs__srv__GetSerialNumber_Request * data = NULL;

  if (size) {
    data = (xsys_msgs__srv__GetSerialNumber_Request *)allocator.zero_allocate(size, sizeof(xsys_msgs__srv__GetSerialNumber_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsys_msgs__srv__GetSerialNumber_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsys_msgs__srv__GetSerialNumber_Request__fini(&data[i - 1]);
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
xsys_msgs__srv__GetSerialNumber_Request__Sequence__fini(xsys_msgs__srv__GetSerialNumber_Request__Sequence * array)
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
      xsys_msgs__srv__GetSerialNumber_Request__fini(&array->data[i]);
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

xsys_msgs__srv__GetSerialNumber_Request__Sequence *
xsys_msgs__srv__GetSerialNumber_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsys_msgs__srv__GetSerialNumber_Request__Sequence * array = (xsys_msgs__srv__GetSerialNumber_Request__Sequence *)allocator.allocate(sizeof(xsys_msgs__srv__GetSerialNumber_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = xsys_msgs__srv__GetSerialNumber_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
xsys_msgs__srv__GetSerialNumber_Request__Sequence__destroy(xsys_msgs__srv__GetSerialNumber_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    xsys_msgs__srv__GetSerialNumber_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
xsys_msgs__srv__GetSerialNumber_Request__Sequence__are_equal(const xsys_msgs__srv__GetSerialNumber_Request__Sequence * lhs, const xsys_msgs__srv__GetSerialNumber_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xsys_msgs__srv__GetSerialNumber_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xsys_msgs__srv__GetSerialNumber_Request__Sequence__copy(
  const xsys_msgs__srv__GetSerialNumber_Request__Sequence * input,
  xsys_msgs__srv__GetSerialNumber_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xsys_msgs__srv__GetSerialNumber_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    xsys_msgs__srv__GetSerialNumber_Request * data =
      (xsys_msgs__srv__GetSerialNumber_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xsys_msgs__srv__GetSerialNumber_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          xsys_msgs__srv__GetSerialNumber_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xsys_msgs__srv__GetSerialNumber_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `serial_number`
#include "rosidl_runtime_c/string_functions.h"

bool
xsys_msgs__srv__GetSerialNumber_Response__init(xsys_msgs__srv__GetSerialNumber_Response * msg)
{
  if (!msg) {
    return false;
  }
  // serial_number
  if (!rosidl_runtime_c__String__init(&msg->serial_number)) {
    xsys_msgs__srv__GetSerialNumber_Response__fini(msg);
    return false;
  }
  return true;
}

void
xsys_msgs__srv__GetSerialNumber_Response__fini(xsys_msgs__srv__GetSerialNumber_Response * msg)
{
  if (!msg) {
    return;
  }
  // serial_number
  rosidl_runtime_c__String__fini(&msg->serial_number);
}

bool
xsys_msgs__srv__GetSerialNumber_Response__are_equal(const xsys_msgs__srv__GetSerialNumber_Response * lhs, const xsys_msgs__srv__GetSerialNumber_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // serial_number
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->serial_number), &(rhs->serial_number)))
  {
    return false;
  }
  return true;
}

bool
xsys_msgs__srv__GetSerialNumber_Response__copy(
  const xsys_msgs__srv__GetSerialNumber_Response * input,
  xsys_msgs__srv__GetSerialNumber_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // serial_number
  if (!rosidl_runtime_c__String__copy(
      &(input->serial_number), &(output->serial_number)))
  {
    return false;
  }
  return true;
}

xsys_msgs__srv__GetSerialNumber_Response *
xsys_msgs__srv__GetSerialNumber_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsys_msgs__srv__GetSerialNumber_Response * msg = (xsys_msgs__srv__GetSerialNumber_Response *)allocator.allocate(sizeof(xsys_msgs__srv__GetSerialNumber_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsys_msgs__srv__GetSerialNumber_Response));
  bool success = xsys_msgs__srv__GetSerialNumber_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
xsys_msgs__srv__GetSerialNumber_Response__destroy(xsys_msgs__srv__GetSerialNumber_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    xsys_msgs__srv__GetSerialNumber_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
xsys_msgs__srv__GetSerialNumber_Response__Sequence__init(xsys_msgs__srv__GetSerialNumber_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsys_msgs__srv__GetSerialNumber_Response * data = NULL;

  if (size) {
    data = (xsys_msgs__srv__GetSerialNumber_Response *)allocator.zero_allocate(size, sizeof(xsys_msgs__srv__GetSerialNumber_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsys_msgs__srv__GetSerialNumber_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsys_msgs__srv__GetSerialNumber_Response__fini(&data[i - 1]);
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
xsys_msgs__srv__GetSerialNumber_Response__Sequence__fini(xsys_msgs__srv__GetSerialNumber_Response__Sequence * array)
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
      xsys_msgs__srv__GetSerialNumber_Response__fini(&array->data[i]);
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

xsys_msgs__srv__GetSerialNumber_Response__Sequence *
xsys_msgs__srv__GetSerialNumber_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsys_msgs__srv__GetSerialNumber_Response__Sequence * array = (xsys_msgs__srv__GetSerialNumber_Response__Sequence *)allocator.allocate(sizeof(xsys_msgs__srv__GetSerialNumber_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = xsys_msgs__srv__GetSerialNumber_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
xsys_msgs__srv__GetSerialNumber_Response__Sequence__destroy(xsys_msgs__srv__GetSerialNumber_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    xsys_msgs__srv__GetSerialNumber_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
xsys_msgs__srv__GetSerialNumber_Response__Sequence__are_equal(const xsys_msgs__srv__GetSerialNumber_Response__Sequence * lhs, const xsys_msgs__srv__GetSerialNumber_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xsys_msgs__srv__GetSerialNumber_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xsys_msgs__srv__GetSerialNumber_Response__Sequence__copy(
  const xsys_msgs__srv__GetSerialNumber_Response__Sequence * input,
  xsys_msgs__srv__GetSerialNumber_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xsys_msgs__srv__GetSerialNumber_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    xsys_msgs__srv__GetSerialNumber_Response * data =
      (xsys_msgs__srv__GetSerialNumber_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xsys_msgs__srv__GetSerialNumber_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          xsys_msgs__srv__GetSerialNumber_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xsys_msgs__srv__GetSerialNumber_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
