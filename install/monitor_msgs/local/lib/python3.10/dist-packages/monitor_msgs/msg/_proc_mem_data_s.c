// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from monitor_msgs:msg/ProcMemData.idl
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
#include "monitor_msgs/msg/detail/proc_mem_data__struct.h"
#include "monitor_msgs/msg/detail/proc_mem_data__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool monitor_msgs__msg__proc_mem_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
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
    assert(strncmp("monitor_msgs.msg._proc_mem_data.ProcMemData", full_classname_dest, 43) == 0);
  }
  monitor_msgs__msg__ProcMemData * ros_message = _ros_message;
  {  // vmsize
    PyObject * field = PyObject_GetAttrString(_pymsg, "vmsize");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->vmsize = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // vmrss
    PyObject * field = PyObject_GetAttrString(_pymsg, "vmrss");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->vmrss = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // vmshared
    PyObject * field = PyObject_GetAttrString(_pymsg, "vmshared");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->vmshared = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // vmexe
    PyObject * field = PyObject_GetAttrString(_pymsg, "vmexe");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->vmexe = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // vmdata
    PyObject * field = PyObject_GetAttrString(_pymsg, "vmdata");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->vmdata = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * monitor_msgs__msg__proc_mem_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ProcMemData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("monitor_msgs.msg._proc_mem_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ProcMemData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  monitor_msgs__msg__ProcMemData * ros_message = (monitor_msgs__msg__ProcMemData *)raw_ros_message;
  {  // vmsize
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->vmsize);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vmsize", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vmrss
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->vmrss);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vmrss", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vmshared
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->vmshared);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vmshared", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vmexe
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->vmexe);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vmexe", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vmdata
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->vmdata);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vmdata", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
