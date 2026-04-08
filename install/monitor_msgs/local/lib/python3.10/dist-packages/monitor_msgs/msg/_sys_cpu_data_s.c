// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from monitor_msgs:msg/SysCpuData.idl
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
#include "monitor_msgs/msg/detail/sys_cpu_data__struct.h"
#include "monitor_msgs/msg/detail/sys_cpu_data__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"
#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool monitor_msgs__msg__sys_cpu_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("monitor_msgs.msg._sys_cpu_data.SysCpuData", full_classname_dest, 41) == 0);
  }
  monitor_msgs__msg__SysCpuData * ros_message = _ros_message;
  {  // cpu_num
    PyObject * field = PyObject_GetAttrString(_pymsg, "cpu_num");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cpu_num = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // cpu_used
    PyObject * field = PyObject_GetAttrString(_pymsg, "cpu_used");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cpu_used = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // proc_num
    PyObject * field = PyObject_GetAttrString(_pymsg, "proc_num");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->proc_num = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // proc_array
    PyObject * field = PyObject_GetAttrString(_pymsg, "proc_array");
    if (!field) {
      return false;
    }
    {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'proc_array'");
      if (!seq_field) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = PySequence_Size(field);
      if (-1 == size) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      if (!rosidl_runtime_c__String__Sequence__init(&(ros_message->proc_array), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create String__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      rosidl_runtime_c__String * dest = ros_message->proc_array.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyUnicode_Check(item));
        PyObject * encoded_item = PyUnicode_AsUTF8String(item);
        if (!encoded_item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        rosidl_runtime_c__String__assign(&dest[i], PyBytes_AS_STRING(encoded_item));
        Py_DECREF(encoded_item);
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * monitor_msgs__msg__sys_cpu_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SysCpuData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("monitor_msgs.msg._sys_cpu_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SysCpuData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  monitor_msgs__msg__SysCpuData * ros_message = (monitor_msgs__msg__SysCpuData *)raw_ros_message;
  {  // cpu_num
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->cpu_num);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cpu_num", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cpu_used
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cpu_used);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cpu_used", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // proc_num
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->proc_num);
    {
      int rc = PyObject_SetAttrString(_pymessage, "proc_num", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // proc_array
    PyObject * field = NULL;
    size_t size = ros_message->proc_array.size;
    rosidl_runtime_c__String * src = ros_message->proc_array.data;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    for (size_t i = 0; i < size; ++i) {
      PyObject * decoded_item = PyUnicode_DecodeUTF8(src[i].data, strlen(src[i].data), "replace");
      if (!decoded_item) {
        return NULL;
      }
      int rc = PyList_SetItem(field, i, decoded_item);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "proc_array", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
