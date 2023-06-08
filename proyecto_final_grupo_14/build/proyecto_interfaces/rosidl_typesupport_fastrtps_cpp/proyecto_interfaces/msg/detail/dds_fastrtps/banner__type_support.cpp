// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from proyecto_interfaces:msg/Banner.idl
// generated code does not contain a copyright notice
#include "proyecto_interfaces/msg/detail/banner__rosidl_typesupport_fastrtps_cpp.hpp"
#include "proyecto_interfaces/msg/detail/banner__struct.hpp"

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

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
cdr_serialize(
  const proyecto_interfaces::msg::Banner & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: banner
  cdr << ros_message.banner;
  // Member: figure
  cdr << ros_message.figure;
  // Member: word
  cdr << ros_message.word;
  // Member: color
  cdr << ros_message.color;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  proyecto_interfaces::msg::Banner & ros_message)
{
  // Member: banner
  cdr >> ros_message.banner;

  // Member: figure
  cdr >> ros_message.figure;

  // Member: word
  cdr >> ros_message.word;

  // Member: color
  cdr >> ros_message.color;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
get_serialized_size(
  const proyecto_interfaces::msg::Banner & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: banner
  {
    size_t item_size = sizeof(ros_message.banner);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: figure
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.figure.size() + 1);
  // Member: word
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.word.size() + 1);
  // Member: color
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.color.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
max_serialized_size_Banner(
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


  // Member: banner
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: figure
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

  // Member: word
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

  // Member: color
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

static bool _Banner__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const proyecto_interfaces::msg::Banner *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Banner__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<proyecto_interfaces::msg::Banner *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Banner__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const proyecto_interfaces::msg::Banner *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Banner__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Banner(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Banner__callbacks = {
  "proyecto_interfaces::msg",
  "Banner",
  _Banner__cdr_serialize,
  _Banner__cdr_deserialize,
  _Banner__get_serialized_size,
  _Banner__max_serialized_size
};

static rosidl_message_type_support_t _Banner__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Banner__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace proyecto_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_proyecto_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<proyecto_interfaces::msg::Banner>()
{
  return &proyecto_interfaces::msg::typesupport_fastrtps_cpp::_Banner__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, proyecto_interfaces, msg, Banner)() {
  return &proyecto_interfaces::msg::typesupport_fastrtps_cpp::_Banner__handle;
}

#ifdef __cplusplus
}
#endif
