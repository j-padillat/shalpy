// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from proyecto_interfaces:msg/Banner.idl
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
#include "proyecto_interfaces/msg/detail/banner__struct.h"
#include "proyecto_interfaces/msg/detail/banner__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool proyecto_interfaces__msg__banner__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
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
    assert(strncmp("proyecto_interfaces.msg._banner.Banner", full_classname_dest, 38) == 0);
  }
  proyecto_interfaces__msg__Banner * ros_message = _ros_message;
  {  // banner
    PyObject * field = PyObject_GetAttrString(_pymsg, "banner");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->banner = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // figure
    PyObject * field = PyObject_GetAttrString(_pymsg, "figure");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->figure, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // word
    PyObject * field = PyObject_GetAttrString(_pymsg, "word");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->word, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // color
    PyObject * field = PyObject_GetAttrString(_pymsg, "color");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->color, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * proyecto_interfaces__msg__banner__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Banner */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("proyecto_interfaces.msg._banner");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Banner");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  proyecto_interfaces__msg__Banner * ros_message = (proyecto_interfaces__msg__Banner *)raw_ros_message;
  {  // banner
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->banner);
    {
      int rc = PyObject_SetAttrString(_pymessage, "banner", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // figure
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->figure.data,
      strlen(ros_message->figure.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "figure", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // word
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->word.data,
      strlen(ros_message->word.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "word", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // color
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->color.data,
      strlen(ros_message->color.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "color", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
