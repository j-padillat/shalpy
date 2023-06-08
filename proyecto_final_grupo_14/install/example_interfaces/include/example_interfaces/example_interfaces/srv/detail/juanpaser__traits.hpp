// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from example_interfaces:srv/Juanpaser.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_INTERFACES__SRV__DETAIL__JUANPASER__TRAITS_HPP_
#define EXAMPLE_INTERFACES__SRV__DETAIL__JUANPASER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "example_interfaces/srv/detail/juanpaser__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace example_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Juanpaser_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: banner
  {
    out << "banner: ";
    rosidl_generator_traits::value_to_yaml(msg.banner, out);
    out << ", ";
  }

  // member: empieza
  {
    out << "empieza: ";
    rosidl_generator_traits::value_to_yaml(msg.empieza, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Juanpaser_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: banner
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "banner: ";
    rosidl_generator_traits::value_to_yaml(msg.banner, out);
    out << "\n";
  }

  // member: empieza
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "empieza: ";
    rosidl_generator_traits::value_to_yaml(msg.empieza, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Juanpaser_Request & msg, bool use_flow_style = false)
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

}  // namespace example_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use example_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const example_interfaces::srv::Juanpaser_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  example_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use example_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const example_interfaces::srv::Juanpaser_Request & msg)
{
  return example_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<example_interfaces::srv::Juanpaser_Request>()
{
  return "example_interfaces::srv::Juanpaser_Request";
}

template<>
inline const char * name<example_interfaces::srv::Juanpaser_Request>()
{
  return "example_interfaces/srv/Juanpaser_Request";
}

template<>
struct has_fixed_size<example_interfaces::srv::Juanpaser_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<example_interfaces::srv::Juanpaser_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<example_interfaces::srv::Juanpaser_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace example_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Juanpaser_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: termina
  {
    out << "termina: ";
    rosidl_generator_traits::value_to_yaml(msg.termina, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Juanpaser_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: termina
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "termina: ";
    rosidl_generator_traits::value_to_yaml(msg.termina, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Juanpaser_Response & msg, bool use_flow_style = false)
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

}  // namespace example_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use example_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const example_interfaces::srv::Juanpaser_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  example_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use example_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const example_interfaces::srv::Juanpaser_Response & msg)
{
  return example_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<example_interfaces::srv::Juanpaser_Response>()
{
  return "example_interfaces::srv::Juanpaser_Response";
}

template<>
inline const char * name<example_interfaces::srv::Juanpaser_Response>()
{
  return "example_interfaces/srv/Juanpaser_Response";
}

template<>
struct has_fixed_size<example_interfaces::srv::Juanpaser_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<example_interfaces::srv::Juanpaser_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<example_interfaces::srv::Juanpaser_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<example_interfaces::srv::Juanpaser>()
{
  return "example_interfaces::srv::Juanpaser";
}

template<>
inline const char * name<example_interfaces::srv::Juanpaser>()
{
  return "example_interfaces/srv/Juanpaser";
}

template<>
struct has_fixed_size<example_interfaces::srv::Juanpaser>
  : std::integral_constant<
    bool,
    has_fixed_size<example_interfaces::srv::Juanpaser_Request>::value &&
    has_fixed_size<example_interfaces::srv::Juanpaser_Response>::value
  >
{
};

template<>
struct has_bounded_size<example_interfaces::srv::Juanpaser>
  : std::integral_constant<
    bool,
    has_bounded_size<example_interfaces::srv::Juanpaser_Request>::value &&
    has_bounded_size<example_interfaces::srv::Juanpaser_Response>::value
  >
{
};

template<>
struct is_service<example_interfaces::srv::Juanpaser>
  : std::true_type
{
};

template<>
struct is_service_request<example_interfaces::srv::Juanpaser_Request>
  : std::true_type
{
};

template<>
struct is_service_response<example_interfaces::srv::Juanpaser_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // EXAMPLE_INTERFACES__SRV__DETAIL__JUANPASER__TRAITS_HPP_
