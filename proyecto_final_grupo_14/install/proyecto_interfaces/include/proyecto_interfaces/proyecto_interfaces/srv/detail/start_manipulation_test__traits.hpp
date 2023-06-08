// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from proyecto_interfaces:srv/StartManipulationTest.idl
// generated code does not contain a copyright notice

#ifndef PROYECTO_INTERFACES__SRV__DETAIL__START_MANIPULATION_TEST__TRAITS_HPP_
#define PROYECTO_INTERFACES__SRV__DETAIL__START_MANIPULATION_TEST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "proyecto_interfaces/srv/detail/start_manipulation_test__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace proyecto_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartManipulationTest_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: platform
  {
    out << "platform: ";
    rosidl_generator_traits::value_to_yaml(msg.platform, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartManipulationTest_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: platform
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "platform: ";
    rosidl_generator_traits::value_to_yaml(msg.platform, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartManipulationTest_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace proyecto_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use proyecto_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const proyecto_interfaces::srv::StartManipulationTest_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  proyecto_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use proyecto_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const proyecto_interfaces::srv::StartManipulationTest_Request & msg)
{
  return proyecto_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<proyecto_interfaces::srv::StartManipulationTest_Request>()
{
  return "proyecto_interfaces::srv::StartManipulationTest_Request";
}

template<>
inline const char * name<proyecto_interfaces::srv::StartManipulationTest_Request>()
{
  return "proyecto_interfaces/srv/StartManipulationTest_Request";
}

template<>
struct has_fixed_size<proyecto_interfaces::srv::StartManipulationTest_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<proyecto_interfaces::srv::StartManipulationTest_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<proyecto_interfaces::srv::StartManipulationTest_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace proyecto_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartManipulationTest_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: answer
  {
    out << "answer: ";
    rosidl_generator_traits::value_to_yaml(msg.answer, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartManipulationTest_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: answer
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "answer: ";
    rosidl_generator_traits::value_to_yaml(msg.answer, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartManipulationTest_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace proyecto_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use proyecto_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const proyecto_interfaces::srv::StartManipulationTest_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  proyecto_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use proyecto_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const proyecto_interfaces::srv::StartManipulationTest_Response & msg)
{
  return proyecto_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<proyecto_interfaces::srv::StartManipulationTest_Response>()
{
  return "proyecto_interfaces::srv::StartManipulationTest_Response";
}

template<>
inline const char * name<proyecto_interfaces::srv::StartManipulationTest_Response>()
{
  return "proyecto_interfaces/srv/StartManipulationTest_Response";
}

template<>
struct has_fixed_size<proyecto_interfaces::srv::StartManipulationTest_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<proyecto_interfaces::srv::StartManipulationTest_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<proyecto_interfaces::srv::StartManipulationTest_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<proyecto_interfaces::srv::StartManipulationTest>()
{
  return "proyecto_interfaces::srv::StartManipulationTest";
}

template<>
inline const char * name<proyecto_interfaces::srv::StartManipulationTest>()
{
  return "proyecto_interfaces/srv/StartManipulationTest";
}

template<>
struct has_fixed_size<proyecto_interfaces::srv::StartManipulationTest>
  : std::integral_constant<
    bool,
    has_fixed_size<proyecto_interfaces::srv::StartManipulationTest_Request>::value &&
    has_fixed_size<proyecto_interfaces::srv::StartManipulationTest_Response>::value
  >
{
};

template<>
struct has_bounded_size<proyecto_interfaces::srv::StartManipulationTest>
  : std::integral_constant<
    bool,
    has_bounded_size<proyecto_interfaces::srv::StartManipulationTest_Request>::value &&
    has_bounded_size<proyecto_interfaces::srv::StartManipulationTest_Response>::value
  >
{
};

template<>
struct is_service<proyecto_interfaces::srv::StartManipulationTest>
  : std::true_type
{
};

template<>
struct is_service_request<proyecto_interfaces::srv::StartManipulationTest_Request>
  : std::true_type
{
};

template<>
struct is_service_response<proyecto_interfaces::srv::StartManipulationTest_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // PROYECTO_INTERFACES__SRV__DETAIL__START_MANIPULATION_TEST__TRAITS_HPP_
