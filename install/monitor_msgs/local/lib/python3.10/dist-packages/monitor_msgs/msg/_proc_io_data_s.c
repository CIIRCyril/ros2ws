// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from monitor_msgs:msg/ProcIoData.idl
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
#include "monitor_msgs/msg/detail/proc_io_data__struct.h"
#include "monitor_msgs/msg/detail/proc_io_data__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool monitor_msgs__msg__proc_io_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("monitor_msgs.msg._proc_io_data.ProcIoData", full_classname_dest, 41) == 0);
  }
  monitor_msgs__msg__ProcIoData * ros_message = _ros_message;
  {  // read
    PyObject * field = PyObject_GetAttrString(_pymsg, "read");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->read = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // write
    PyObject * field = PyObject_GetAttrString(_pymsg, "write");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->write = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // total_read
    PyObject * field = PyObject_GetAttrString(_pymsg, "total_read");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->total_read = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // total_write
    PyObject * field = PyObject_GetAttrString(_pymsg, "total_write");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->total_write = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * monitor_msgs__msg__proc_io_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ProcIoData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("monitor_msgs.msg._proc_io_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ProcIoData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  monitor_msgs__msg__ProcIoData * ros_message = (monitor_msgs__msg__ProcIoData *)raw_ros_message;
  {  // read
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->read);
    {
      int rc = PyObject_SetAttrString(_pymessage, "read", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // write
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->write);
    {
      int rc = PyObject_SetAttrString(_pymessage, "write", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // total_read
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->total_read);
    {
      int rc = PyObject_SetAttrString(_pymessage, "total_read", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // total_write
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->total_write);
    {
      int rc = PyObject_SetAttrString(_pymessage, "total_write", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
