// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from example_interfaces:msg/Banner.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "example_interfaces/msg/detail/banner__rosidl_typesupport_introspection_c.h"
#include "example_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "example_interfaces/msg/detail/banner__functions.h"
#include "example_interfaces/msg/detail/banner__struct.h"


// Include directives for member types
// Member `figure`
// Member `word`
// Member `color`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void example_interfaces__msg__Banner__rosidl_typesupport_introspection_c__Banner_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  example_interfaces__msg__Banner__init(message_memory);
}

void example_interfaces__msg__Banner__rosidl_typesupport_introspection_c__Banner_fini_function(void * message_memory)
{
  example_interfaces__msg__Banner__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember example_interfaces__msg__Banner__rosidl_typesupport_introspection_c__Banner_message_member_array[4] = {
  {
    "banner",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(example_interfaces__msg__Banner, banner),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "figure",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(example_interfaces__msg__Banner, figure),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "word",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(example_interfaces__msg__Banner, word),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "color",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(example_interfaces__msg__Banner, color),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers example_interfaces__msg__Banner__rosidl_typesupport_introspection_c__Banner_message_members = {
  "example_interfaces__msg",  // message namespace
  "Banner",  // message name
  4,  // number of fields
  sizeof(example_interfaces__msg__Banner),
  example_interfaces__msg__Banner__rosidl_typesupport_introspection_c__Banner_message_member_array,  // message members
  example_interfaces__msg__Banner__rosidl_typesupport_introspection_c__Banner_init_function,  // function to initialize message memory (memory has to be allocated)
  example_interfaces__msg__Banner__rosidl_typesupport_introspection_c__Banner_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t example_interfaces__msg__Banner__rosidl_typesupport_introspection_c__Banner_message_type_support_handle = {
  0,
  &example_interfaces__msg__Banner__rosidl_typesupport_introspection_c__Banner_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_example_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, example_interfaces, msg, Banner)() {
  if (!example_interfaces__msg__Banner__rosidl_typesupport_introspection_c__Banner_message_type_support_handle.typesupport_identifier) {
    example_interfaces__msg__Banner__rosidl_typesupport_introspection_c__Banner_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &example_interfaces__msg__Banner__rosidl_typesupport_introspection_c__Banner_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
