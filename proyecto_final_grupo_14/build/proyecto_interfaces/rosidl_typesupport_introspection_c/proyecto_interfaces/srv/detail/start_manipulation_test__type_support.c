// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from proyecto_interfaces:srv/StartManipulationTest.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "proyecto_interfaces/srv/detail/start_manipulation_test__rosidl_typesupport_introspection_c.h"
#include "proyecto_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "proyecto_interfaces/srv/detail/start_manipulation_test__functions.h"
#include "proyecto_interfaces/srv/detail/start_manipulation_test__struct.h"


// Include directives for member types
// Member `platform`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void proyecto_interfaces__srv__StartManipulationTest_Request__rosidl_typesupport_introspection_c__StartManipulationTest_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  proyecto_interfaces__srv__StartManipulationTest_Request__init(message_memory);
}

void proyecto_interfaces__srv__StartManipulationTest_Request__rosidl_typesupport_introspection_c__StartManipulationTest_Request_fini_function(void * message_memory)
{
  proyecto_interfaces__srv__StartManipulationTest_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember proyecto_interfaces__srv__StartManipulationTest_Request__rosidl_typesupport_introspection_c__StartManipulationTest_Request_message_member_array[2] = {
  {
    "platform",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(proyecto_interfaces__srv__StartManipulationTest_Request, platform),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(proyecto_interfaces__srv__StartManipulationTest_Request, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers proyecto_interfaces__srv__StartManipulationTest_Request__rosidl_typesupport_introspection_c__StartManipulationTest_Request_message_members = {
  "proyecto_interfaces__srv",  // message namespace
  "StartManipulationTest_Request",  // message name
  2,  // number of fields
  sizeof(proyecto_interfaces__srv__StartManipulationTest_Request),
  proyecto_interfaces__srv__StartManipulationTest_Request__rosidl_typesupport_introspection_c__StartManipulationTest_Request_message_member_array,  // message members
  proyecto_interfaces__srv__StartManipulationTest_Request__rosidl_typesupport_introspection_c__StartManipulationTest_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  proyecto_interfaces__srv__StartManipulationTest_Request__rosidl_typesupport_introspection_c__StartManipulationTest_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t proyecto_interfaces__srv__StartManipulationTest_Request__rosidl_typesupport_introspection_c__StartManipulationTest_Request_message_type_support_handle = {
  0,
  &proyecto_interfaces__srv__StartManipulationTest_Request__rosidl_typesupport_introspection_c__StartManipulationTest_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_proyecto_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, proyecto_interfaces, srv, StartManipulationTest_Request)() {
  if (!proyecto_interfaces__srv__StartManipulationTest_Request__rosidl_typesupport_introspection_c__StartManipulationTest_Request_message_type_support_handle.typesupport_identifier) {
    proyecto_interfaces__srv__StartManipulationTest_Request__rosidl_typesupport_introspection_c__StartManipulationTest_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &proyecto_interfaces__srv__StartManipulationTest_Request__rosidl_typesupport_introspection_c__StartManipulationTest_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "proyecto_interfaces/srv/detail/start_manipulation_test__rosidl_typesupport_introspection_c.h"
// already included above
// #include "proyecto_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "proyecto_interfaces/srv/detail/start_manipulation_test__functions.h"
// already included above
// #include "proyecto_interfaces/srv/detail/start_manipulation_test__struct.h"


// Include directives for member types
// Member `answer`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void proyecto_interfaces__srv__StartManipulationTest_Response__rosidl_typesupport_introspection_c__StartManipulationTest_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  proyecto_interfaces__srv__StartManipulationTest_Response__init(message_memory);
}

void proyecto_interfaces__srv__StartManipulationTest_Response__rosidl_typesupport_introspection_c__StartManipulationTest_Response_fini_function(void * message_memory)
{
  proyecto_interfaces__srv__StartManipulationTest_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember proyecto_interfaces__srv__StartManipulationTest_Response__rosidl_typesupport_introspection_c__StartManipulationTest_Response_message_member_array[1] = {
  {
    "answer",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(proyecto_interfaces__srv__StartManipulationTest_Response, answer),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers proyecto_interfaces__srv__StartManipulationTest_Response__rosidl_typesupport_introspection_c__StartManipulationTest_Response_message_members = {
  "proyecto_interfaces__srv",  // message namespace
  "StartManipulationTest_Response",  // message name
  1,  // number of fields
  sizeof(proyecto_interfaces__srv__StartManipulationTest_Response),
  proyecto_interfaces__srv__StartManipulationTest_Response__rosidl_typesupport_introspection_c__StartManipulationTest_Response_message_member_array,  // message members
  proyecto_interfaces__srv__StartManipulationTest_Response__rosidl_typesupport_introspection_c__StartManipulationTest_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  proyecto_interfaces__srv__StartManipulationTest_Response__rosidl_typesupport_introspection_c__StartManipulationTest_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t proyecto_interfaces__srv__StartManipulationTest_Response__rosidl_typesupport_introspection_c__StartManipulationTest_Response_message_type_support_handle = {
  0,
  &proyecto_interfaces__srv__StartManipulationTest_Response__rosidl_typesupport_introspection_c__StartManipulationTest_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_proyecto_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, proyecto_interfaces, srv, StartManipulationTest_Response)() {
  if (!proyecto_interfaces__srv__StartManipulationTest_Response__rosidl_typesupport_introspection_c__StartManipulationTest_Response_message_type_support_handle.typesupport_identifier) {
    proyecto_interfaces__srv__StartManipulationTest_Response__rosidl_typesupport_introspection_c__StartManipulationTest_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &proyecto_interfaces__srv__StartManipulationTest_Response__rosidl_typesupport_introspection_c__StartManipulationTest_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "proyecto_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "proyecto_interfaces/srv/detail/start_manipulation_test__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers proyecto_interfaces__srv__detail__start_manipulation_test__rosidl_typesupport_introspection_c__StartManipulationTest_service_members = {
  "proyecto_interfaces__srv",  // service namespace
  "StartManipulationTest",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // proyecto_interfaces__srv__detail__start_manipulation_test__rosidl_typesupport_introspection_c__StartManipulationTest_Request_message_type_support_handle,
  NULL  // response message
  // proyecto_interfaces__srv__detail__start_manipulation_test__rosidl_typesupport_introspection_c__StartManipulationTest_Response_message_type_support_handle
};

static rosidl_service_type_support_t proyecto_interfaces__srv__detail__start_manipulation_test__rosidl_typesupport_introspection_c__StartManipulationTest_service_type_support_handle = {
  0,
  &proyecto_interfaces__srv__detail__start_manipulation_test__rosidl_typesupport_introspection_c__StartManipulationTest_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, proyecto_interfaces, srv, StartManipulationTest_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, proyecto_interfaces, srv, StartManipulationTest_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_proyecto_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, proyecto_interfaces, srv, StartManipulationTest)() {
  if (!proyecto_interfaces__srv__detail__start_manipulation_test__rosidl_typesupport_introspection_c__StartManipulationTest_service_type_support_handle.typesupport_identifier) {
    proyecto_interfaces__srv__detail__start_manipulation_test__rosidl_typesupport_introspection_c__StartManipulationTest_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)proyecto_interfaces__srv__detail__start_manipulation_test__rosidl_typesupport_introspection_c__StartManipulationTest_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, proyecto_interfaces, srv, StartManipulationTest_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, proyecto_interfaces, srv, StartManipulationTest_Response)()->data;
  }

  return &proyecto_interfaces__srv__detail__start_manipulation_test__rosidl_typesupport_introspection_c__StartManipulationTest_service_type_support_handle;
}
