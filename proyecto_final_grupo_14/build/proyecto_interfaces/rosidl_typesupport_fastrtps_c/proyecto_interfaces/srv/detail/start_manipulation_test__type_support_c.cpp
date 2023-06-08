// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from proyecto_interfaces:srv/StartManipulationTest.idl
// generated code does not contain a copyright notice
#include "proyecto_interfaces/srv/detail/start_manipulation_test__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "proyecto_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "proyecto_interfaces/srv/detail/start_manipulation_test__struct.h"
#include "proyecto_interfaces/srv/detail/start_manipulation_test__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // platform
#include "rosidl_runtime_c/string_functions.h"  // platform

// forward declare type support functions


using _StartManipulationTest_Request__ros_msg_type = proyecto_interfaces__srv__StartManipulationTest_Request;

static bool _StartManipulationTest_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartManipulationTest_Request__ros_msg_type * ros_message = static_cast<const _StartManipulationTest_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: platform
  {
    const rosidl_runtime_c__String * str = &ros_message->platform;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: x
  {
    cdr << ros_message->x;
  }

  return true;
}

static bool _StartManipulationTest_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartManipulationTest_Request__ros_msg_type * ros_message = static_cast<_StartManipulationTest_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: platform
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->platform.data) {
      rosidl_runtime_c__String__init(&ros_message->platform);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->platform,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'platform'\n");
      return false;
    }
  }

  // Field name: x
  {
    cdr >> ros_message->x;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_proyecto_interfaces
size_t get_serialized_size_proyecto_interfaces__srv__StartManipulationTest_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartManipulationTest_Request__ros_msg_type * ros_message = static_cast<const _StartManipulationTest_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name platform
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->platform.size + 1);
  // field.name x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _StartManipulationTest_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_proyecto_interfaces__srv__StartManipulationTest_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_proyecto_interfaces
size_t max_serialized_size_proyecto_interfaces__srv__StartManipulationTest_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: platform
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _StartManipulationTest_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_proyecto_interfaces__srv__StartManipulationTest_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartManipulationTest_Request = {
  "proyecto_interfaces::srv",
  "StartManipulationTest_Request",
  _StartManipulationTest_Request__cdr_serialize,
  _StartManipulationTest_Request__cdr_deserialize,
  _StartManipulationTest_Request__get_serialized_size,
  _StartManipulationTest_Request__max_serialized_size
};

static rosidl_message_type_support_t _StartManipulationTest_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartManipulationTest_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, proyecto_interfaces, srv, StartManipulationTest_Request)() {
  return &_StartManipulationTest_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "proyecto_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "proyecto_interfaces/srv/detail/start_manipulation_test__struct.h"
// already included above
// #include "proyecto_interfaces/srv/detail/start_manipulation_test__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/string.h"  // answer
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // answer

// forward declare type support functions


using _StartManipulationTest_Response__ros_msg_type = proyecto_interfaces__srv__StartManipulationTest_Response;

static bool _StartManipulationTest_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartManipulationTest_Response__ros_msg_type * ros_message = static_cast<const _StartManipulationTest_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: answer
  {
    const rosidl_runtime_c__String * str = &ros_message->answer;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _StartManipulationTest_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartManipulationTest_Response__ros_msg_type * ros_message = static_cast<_StartManipulationTest_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: answer
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->answer.data) {
      rosidl_runtime_c__String__init(&ros_message->answer);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->answer,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'answer'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_proyecto_interfaces
size_t get_serialized_size_proyecto_interfaces__srv__StartManipulationTest_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartManipulationTest_Response__ros_msg_type * ros_message = static_cast<const _StartManipulationTest_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name answer
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->answer.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _StartManipulationTest_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_proyecto_interfaces__srv__StartManipulationTest_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_proyecto_interfaces
size_t max_serialized_size_proyecto_interfaces__srv__StartManipulationTest_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: answer
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _StartManipulationTest_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_proyecto_interfaces__srv__StartManipulationTest_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartManipulationTest_Response = {
  "proyecto_interfaces::srv",
  "StartManipulationTest_Response",
  _StartManipulationTest_Response__cdr_serialize,
  _StartManipulationTest_Response__cdr_deserialize,
  _StartManipulationTest_Response__get_serialized_size,
  _StartManipulationTest_Response__max_serialized_size
};

static rosidl_message_type_support_t _StartManipulationTest_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartManipulationTest_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, proyecto_interfaces, srv, StartManipulationTest_Response)() {
  return &_StartManipulationTest_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "proyecto_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "proyecto_interfaces/srv/start_manipulation_test.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t StartManipulationTest__callbacks = {
  "proyecto_interfaces::srv",
  "StartManipulationTest",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, proyecto_interfaces, srv, StartManipulationTest_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, proyecto_interfaces, srv, StartManipulationTest_Response)(),
};

static rosidl_service_type_support_t StartManipulationTest__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &StartManipulationTest__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, proyecto_interfaces, srv, StartManipulationTest)() {
  return &StartManipulationTest__handle;
}

#if defined(__cplusplus)
}
#endif
