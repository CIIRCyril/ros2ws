// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from monitor_msgs:msg/ProcData.idl
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
#include "monitor_msgs/msg/detail/proc_data__struct.h"
#include "monitor_msgs/msg/detail/proc_data__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

bool monitor_msgs__msg__proc_cpu_data__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * monitor_msgs__msg__proc_cpu_data__convert_to_py(void * raw_ros_message);
bool monitor_msgs__msg__proc_io_data__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * monitor_msgs__msg__proc_io_data__convert_to_py(void * raw_ros_message);
bool monitor_msgs__msg__proc_mem_data__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * monitor_msgs__msg__proc_mem_data__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool monitor_msgs__msg__proc_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
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
    assert(strncmp("monitor_msgs.msg._proc_data.ProcData", full_classname_dest, 36) == 0);
  }
  monitor_msgs__msg__ProcData * ros_message = _ros_message;
  {  // pid
    PyObject * field = PyObject_GetAttrString(_pymsg, "pid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pid = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // name
    PyObject * field = PyObject_GetAttrString(_pymsg, "name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // active
    PyObject * field = PyObject_GetAttrString(_pymsg, "active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // cpu_data
    PyObject * field = PyObject_GetAttrString(_pymsg, "cpu_data");
    if (!field) {
      return false;
    }
    if (!monitor_msgs__msg__proc_cpu_data__convert_from_py(field, &ros_message->cpu_data)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // io_data
    PyObject * field = PyObject_GetAttrString(_pymsg, "io_data");
    if (!field) {
      return false;
    }
    if (!monitor_msgs__msg__proc_io_data__convert_from_py(field, &ros_message->io_data)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // mem_data
    PyObject * field = PyObject_GetAttrString(_pymsg, "mem_data");
    if (!field) {
      return false;
    }
    if (!monitor_msgs__msg__proc_mem_data__convert_from_py(field, &ros_message->mem_data)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * monitor_msgs__msg__proc_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ProcData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("monitor_msgs.msg._proc_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ProcData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  monitor_msgs__msg__ProcData * ros_message = (monitor_msgs__msg__ProcData *)raw_ros_message;
  {  // pid
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->name.data,
      strlen(ros_message->name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cpu_data
    PyObject * field = NULL;
    field = monitor_msgs__msg__proc_cpu_data__convert_to_py(&ros_message->cpu_data);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "cpu_data", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // io_data
    PyObject * field = NULL;
    field = monitor_msgs__msg__proc_io_data__convert_to_py(&ros_message->io_data);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "io_data", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mem_data
    PyObject * field = NULL;
    field = monitor_msgs__msg__proc_mem_data__convert_to_py(&ros_message->mem_data);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "mem_data", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
