// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from proyecto_interfaces:srv/StartPerceptionTest.idl
// generated code does not contain a copyright notice
#include "proyecto_interfaces/srv/detail/start_perception_test__rosidl_typesupport_fastrtps_cpp.hpp"
#include "proyecto_interfaces/srv/detail/start_perception_test__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace proyecto_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
cdr_serialize(
  const proyecto_interfaces::srv::StartPerceptionTest_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: banner_a
  cdr << ros_message.banner_a;
  // Member: banner_b
  cdr << ros_message.banner_b;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  proyecto_interfaces::srv::StartPerceptionTest_Request & ros_message)
{
  // Member: banner_a
  cdr >> ros_message.banner_a;

  // Member: banner_b
  cdr >> ros_message.banner_b;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
get_serialized_size(
  const proyecto_interfaces::srv::StartPerceptionTest_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: banner_a
  {
    size_t item_size = sizeof(ros_message.banner_a);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: banner_b
  {
    size_t item_size = sizeof(ros_message.banner_b);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
max_serialized_size_StartPerceptionTest_Request(
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


  // Member: banner_a
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: banner_b
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _StartPerceptionTest_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const proyecto_interfaces::srv::StartPerceptionTest_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _StartPerceptionTest_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<proyecto_interfaces::srv::StartPerceptionTest_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _StartPerceptionTest_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const proyecto_interfaces::srv::StartPerceptionTest_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _StartPerceptionTest_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_StartPerceptionTest_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _StartPerceptionTest_Request__callbacks = {
  "proyecto_interfaces::srv",
  "StartPerceptionTest_Request",
  _StartPerceptionTest_Request__cdr_serialize,
  _StartPerceptionTest_Request__cdr_deserialize,
  _StartPerceptionTest_Request__get_serialized_size,
  _StartPerceptionTest_Request__max_serialized_size
};

static rosidl_message_type_support_t _StartPerceptionTest_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_StartPerceptionTest_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace proyecto_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_proyecto_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<proyecto_interfaces::srv::StartPerceptionTest_Request>()
{
  return &proyecto_interfaces::srv::typesupport_fastrtps_cpp::_StartPerceptionTest_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, proyecto_interfaces, srv, StartPerceptionTest_Request)() {
  return &proyecto_interfaces::srv::typesupport_fastrtps_cpp::_StartPerceptionTest_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace proyecto_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
cdr_serialize(
  const proyecto_interfaces::srv::StartPerceptionTest_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: answer
  cdr << ros_message.answer;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  proyecto_interfaces::srv::StartPerceptionTest_Response & ros_message)
{
  // Member: answer
  cdr >> ros_message.answer;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
get_serialized_size(
  const proyecto_interfaces::srv::StartPerceptionTest_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: answer
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.answer.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
max_serialized_size_StartPerceptionTest_Response(
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


  // Member: answer
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

static bool _StartPerceptionTest_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const proyecto_interfaces::srv::StartPerceptionTest_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _StartPerceptionTest_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<proyecto_interfaces::srv::StartPerceptionTest_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _StartPerceptionTest_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const proyecto_interfaces::srv::StartPerceptionTest_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _StartPerceptionTest_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_StartPerceptionTest_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _StartPerceptionTest_Response__callbacks = {
  "proyecto_interfaces::srv",
  "StartPerceptionTest_Response",
  _StartPerceptionTest_Response__cdr_serialize,
  _StartPerceptionTest_Response__cdr_deserialize,
  _StartPerceptionTest_Response__get_serialized_size,
  _StartPerceptionTest_Response__max_serialized_size
};

static rosidl_message_type_support_t _StartPerceptionTest_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_StartPerceptionTest_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace proyecto_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_proyecto_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<proyecto_interfaces::srv::StartPerceptionTest_Response>()
{
  return &proyecto_interfaces::srv::typesupport_fastrtps_cpp::_StartPerceptionTest_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, proyecto_interfaces, srv, StartPerceptionTest_Response)() {
  return &proyecto_interfaces::srv::typesupport_fastrtps_cpp::_StartPerceptionTest_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace proyecto_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _StartPerceptionTest__callbacks = {
  "proyecto_interfaces::srv",
  "StartPerceptionTest",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, proyecto_interfaces, srv, StartPerceptionTest_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, proyecto_interfaces, srv, StartPerceptionTest_Response)(),
};

static rosidl_service_type_support_t _StartPerceptionTest__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_StartPerceptionTest__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace proyecto_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_proyecto_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<proyecto_interfaces::srv::StartPerceptionTest>()
{
  return &proyecto_interfaces::srv::typesupport_fastrtps_cpp::_StartPerceptionTest__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, proyecto_interfaces, srv, StartPerceptionTest)() {
  return &proyecto_interfaces::srv::typesupport_fastrtps_cpp::_StartPerceptionTest__handle;
}

#ifdef __cplusplus
}
#endif
