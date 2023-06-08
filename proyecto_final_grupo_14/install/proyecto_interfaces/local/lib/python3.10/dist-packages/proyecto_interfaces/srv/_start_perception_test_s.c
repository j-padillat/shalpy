// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from proyecto_interfaces:srv/StartPerceptionTest.idl
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
#include "proyecto_interfaces/srv/detail/start_perception_test__struct.h"
#include "proyecto_interfaces/srv/detail/start_perception_test__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool proyecto_interfaces__srv__start_perception_test__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[75];
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
    assert(strncmp("proyecto_interfaces.srv._start_perception_test.StartPerceptionTest_Request", full_classname_dest, 74) == 0);
  }
  proyecto_interfaces__srv__StartPerceptionTest_Request * ros_message = _ros_message;
  {  // banner_a
    PyObject * field = PyObject_GetAttrString(_pymsg, "banner_a");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->banner_a = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // banner_b
    PyObject * field = PyObject_GetAttrString(_pymsg, "banner_b");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->banner_b = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * proyecto_interfaces__srv__start_perception_test__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of StartPerceptionTest_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("proyecto_interfaces.srv._start_perception_test");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "StartPerceptionTest_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  proyecto_interfaces__srv__StartPerceptionTest_Request * ros_message = (proyecto_interfaces__srv__StartPerceptionTest_Request *)raw_ros_message;
  {  // banner_a
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->banner_a);
    {
      int rc = PyObject_SetAttrString(_pymessage, "banner_a", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // banner_b
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->banner_b);
    {
      int rc = PyObject_SetAttrString(_pymessage, "banner_b", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "proyecto_interfaces/srv/detail/start_perception_test__struct.h"
// already included above
// #include "proyecto_interfaces/srv/detail/start_perception_test__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool proyecto_interfaces__srv__start_perception_test__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[76];
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
    assert(strncmp("proyecto_interfaces.srv._start_perception_test.StartPerceptionTest_Response", full_classname_dest, 75) == 0);
  }
  proyecto_interfaces__srv__StartPerceptionTest_Response * ros_message = _ros_message;
  {  // answer
    PyObject * field = PyObject_GetAttrString(_pymsg, "answer");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->answer, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * proyecto_interfaces__srv__start_perception_test__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of StartPerceptionTest_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("proyecto_interfaces.srv._start_perception_test");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "StartPerceptionTest_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  proyecto_interfaces__srv__StartPerceptionTest_Response * ros_message = (proyecto_interfaces__srv__StartPerceptionTest_Response *)raw_ros_message;
  {  // answer
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->answer.data,
      strlen(ros_message->answer.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "answer", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
