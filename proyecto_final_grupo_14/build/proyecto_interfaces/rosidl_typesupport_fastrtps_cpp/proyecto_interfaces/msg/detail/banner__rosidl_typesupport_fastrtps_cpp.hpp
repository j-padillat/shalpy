// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from proyecto_interfaces:msg/Banner.idl
// generated code does not contain a copyright notice

#ifndef PROYECTO_INTERFACES__MSG__DETAIL__BANNER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define PROYECTO_INTERFACES__MSG__DETAIL__BANNER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "proyecto_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "proyecto_interfaces/msg/detail/banner__struct.hpp"

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

#include "fastcdr/Cdr.h"

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
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  proyecto_interfaces::msg::Banner & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
get_serialized_size(
  const proyecto_interfaces::msg::Banner & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
max_serialized_size_Banner(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace proyecto_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_proyecto_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, proyecto_interfaces, msg, Banner)();

#ifdef __cplusplus
}
#endif

#endif  // PROYECTO_INTERFACES__MSG__DETAIL__BANNER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
