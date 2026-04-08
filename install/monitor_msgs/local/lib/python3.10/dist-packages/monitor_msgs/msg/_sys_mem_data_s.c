// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from monitor_msgs:msg/SysMemData.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "monitor_msgs/msg/detail/sys_mem_data__struct.h"
#include "monitor_msgs/msg/detail/sys_mem_data__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool monitor_msgs__msg__sys_mem_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("monitor_msgs.msg._sys_mem_data.SysMemData", full_classname_dest, 41) == 0);
  }
  monitor_msgs__msg__SysMemData * ros_message = _ros_message;
  {  // timestamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__time__convert_from_py(field, &ros_message->timestamp)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // total
    PyObject * field = PyObject_GetAttrString(_pymsg, "total");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->total = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // used
    PyObject * field = PyObject_GetAttrString(_pymsg, "used");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->used = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // free
    PyObject * field = PyObject_GetAttrString(_pymsg, "free");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->free = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // shared
    PyObject * field = PyObject_GetAttrString(_pymsg, "shared");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->shared = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // available
    PyObject * field = PyObject_GetAttrString(_pymsg, "available");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->available = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // buffers
    PyObject * field = PyObject_GetAttrString(_pymsg, "buffers");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->buffers = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // cached
    PyObject * field = PyObject_GetAttrString(_pymsg, "cached");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cached = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // sreclaimable
    PyObject * field = PyObject_GetAttrString(_pymsg, "sreclaimable");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sreclaimable = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // swap_total
    PyObject * field = PyObject_GetAttrString(_pymsg, "swap_total");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->swap_total = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // swap_free
    PyObject * field = PyObject_GetAttrString(_pymsg, "swap_free");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->swap_free = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * monitor_msgs__msg__sys_mem_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SysMemData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("monitor_msgs.msg._sys_mem_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SysMemData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  monitor_msgs__msg__SysMemData * ros_message = (monitor_msgs__msg__SysMemData *)raw_ros_message;
  {  // timestamp
    PyObject * field = NULL;
    field = builtin_interfaces__msg__time__convert_to_py(&ros_message->timestamp);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "timestamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // total
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->total);
    {
      int rc = PyObject_SetAttrString(_pymessage, "total", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // used
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->used);
    {
      int rc = PyObject_SetAttrString(_pymessage, "used", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // free
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->free);
    {
      int rc = PyObject_SetAttrString(_pymessage, "free", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // shared
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->shared);
    {
      int rc = PyObject_SetAttrString(_pymessage, "shared", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // available
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->available);
    {
      int rc = PyObject_SetAttrString(_pymessage, "available", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // buffers
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->buffers);
    {
      int rc = PyObject_SetAttrString(_pymessage, "buffers", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cached
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->cached);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cached", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sreclaimable
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->sreclaimable);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sreclaimable", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // swap_total
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->swap_total);
    {
      int rc = PyObject_SetAttrString(_pymessage, "swap_total", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // swap_free
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->swap_free);
    {
      int rc = PyObject_SetAttrString(_pymessage, "swap_free", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
