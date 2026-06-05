// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from alicia_d_control_interfaces:msg/GripperState.idl
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
#include "alicia_d_control_interfaces/msg/detail/gripper_state__struct.h"
#include "alicia_d_control_interfaces/msg/detail/gripper_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool alicia_d_control_interfaces__msg__gripper_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[60];
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
    assert(strncmp("alicia_d_control_interfaces.msg._gripper_state.GripperState", full_classname_dest, 59) == 0);
  }
  alicia_d_control_interfaces__msg__GripperState * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // connected
    PyObject * field = PyObject_GetAttrString(_pymsg, "connected");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->connected = (Py_True == field);
    Py_DECREF(field);
  }
  {  // homed
    PyObject * field = PyObject_GetAttrString(_pymsg, "homed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->homed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // raw_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_position");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->raw_position = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // relative_ticks
    PyObject * field = PyObject_GetAttrString(_pymsg, "relative_ticks");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->relative_ticks = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // target_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_position");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->target_position = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // position_error_direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "position_error_direction");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->position_error_direction = (Py_True == field);
    Py_DECREF(field);
  }
  {  // position_error_ticks
    PyObject * field = PyObject_GetAttrString(_pymsg, "position_error_ticks");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->position_error_ticks = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // estimated_position_minus
    PyObject * field = PyObject_GetAttrString(_pymsg, "estimated_position_minus");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->estimated_position_minus = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // estimated_position_plus
    PyObject * field = PyObject_GetAttrString(_pymsg, "estimated_position_plus");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->estimated_position_plus = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // load_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "load_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->load_raw = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // current_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->current_raw = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // moving
    PyObject * field = PyObject_GetAttrString(_pymsg, "moving");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->moving = (Py_True == field);
    Py_DECREF(field);
  }
  {  // voltage_v
    PyObject * field = PyObject_GetAttrString(_pymsg, "voltage_v");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->voltage_v = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // temperature_c
    PyObject * field = PyObject_GetAttrString(_pymsg, "temperature_c");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->temperature_c = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // fault
    PyObject * field = PyObject_GetAttrString(_pymsg, "fault");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->fault, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * alicia_d_control_interfaces__msg__gripper_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GripperState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("alicia_d_control_interfaces.msg._gripper_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GripperState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  alicia_d_control_interfaces__msg__GripperState * ros_message = (alicia_d_control_interfaces__msg__GripperState *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // connected
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->connected ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "connected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // homed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->homed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "homed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_position
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->raw_position);
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // relative_ticks
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->relative_ticks);
    {
      int rc = PyObject_SetAttrString(_pymessage, "relative_ticks", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_position
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->target_position);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // position_error_direction
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->position_error_direction ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "position_error_direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // position_error_ticks
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->position_error_ticks);
    {
      int rc = PyObject_SetAttrString(_pymessage, "position_error_ticks", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // estimated_position_minus
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->estimated_position_minus);
    {
      int rc = PyObject_SetAttrString(_pymessage, "estimated_position_minus", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // estimated_position_plus
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->estimated_position_plus);
    {
      int rc = PyObject_SetAttrString(_pymessage, "estimated_position_plus", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // load_raw
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->load_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "load_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_raw
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->current_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // moving
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->moving ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "moving", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // voltage_v
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->voltage_v);
    {
      int rc = PyObject_SetAttrString(_pymessage, "voltage_v", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // temperature_c
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->temperature_c);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temperature_c", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fault
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->fault.data,
      strlen(ros_message->fault.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "fault", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
