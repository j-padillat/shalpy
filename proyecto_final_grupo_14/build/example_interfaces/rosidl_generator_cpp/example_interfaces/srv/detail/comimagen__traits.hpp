// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from example_interfaces:srv/Comimagen.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_INTERFACES__SRV__DETAIL__COMIMAGEN__TRAITS_HPP_
#define EXAMPLE_INTERFACES__SRV__DETAIL__COMIMAGEN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "example_interfaces/srv/detail/comimagen__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'imagen'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace example_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Comimagen_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: imagen
  {
    out << "imagen: ";
    to_flow_style_yaml(msg.imagen, out);
    out << ", ";
  }

  // member: banner
  {
    out << "banner: ";
    rosidl_generator_traits::value_to_yaml(msg.banner, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Comimagen_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: imagen
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imagen:\n";
    to_block_style_yaml(msg.imagen, out, indentation + 2);
  }

  // member: banner
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "banner: ";
    rosidl_generator_traits::value_to_yaml(msg.banner, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Comimagen_Request & msg, bool use_flow_style = false)
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
  const example_interfaces::srv::Comimagen_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  example_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use example_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const example_interfaces::srv::Comimagen_Request & msg)
{
  return example_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<example_interfaces::srv::Comimagen_Request>()
{
  return "example_interfaces::srv::Comimagen_Request";
}

template<>
inline const char * name<example_interfaces::srv::Comimagen_Request>()
{
  return "example_interfaces/srv/Comimagen_Request";
}

template<>
struct has_fixed_size<example_interfaces::srv::Comimagen_Request>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<example_interfaces::srv::Comimagen_Request>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<example_interfaces::srv::Comimagen_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace example_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Comimagen_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: finalizo
  {
    out << "finalizo: ";
    rosidl_generator_traits::value_to_yaml(msg.finalizo, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Comimagen_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: finalizo
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "finalizo: ";
    rosidl_generator_traits::value_to_yaml(msg.finalizo, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Comimagen_Response & msg, bool use_flow_style = false)
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
  const example_interfaces::srv::Comimagen_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  example_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use example_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const example_interfaces::srv::Comimagen_Response & msg)
{
  return example_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<example_interfaces::srv::Comimagen_Response>()
{
  return "example_interfaces::srv::Comimagen_Response";
}

template<>
inline const char * name<example_interfaces::srv::Comimagen_Response>()
{
  return "example_interfaces/srv/Comimagen_Response";
}

template<>
struct has_fixed_size<example_interfaces::srv::Comimagen_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<example_interfaces::srv::Comimagen_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<example_interfaces::srv::Comimagen_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<example_interfaces::srv::Comimagen>()
{
  return "example_interfaces::srv::Comimagen";
}

template<>
inline const char * name<example_interfaces::srv::Comimagen>()
{
  return "example_interfaces/srv/Comimagen";
}

template<>
struct has_fixed_size<example_interfaces::srv::Comimagen>
  : std::integral_constant<
    bool,
    has_fixed_size<example_interfaces::srv::Comimagen_Request>::value &&
    has_fixed_size<example_interfaces::srv::Comimagen_Response>::value
  >
{
};

template<>
struct has_bounded_size<example_interfaces::srv::Comimagen>
  : std::integral_constant<
    bool,
    has_bounded_size<example_interfaces::srv::Comimagen_Request>::value &&
    has_bounded_size<example_interfaces::srv::Comimagen_Response>::value
  >
{
};

template<>
struct is_service<example_interfaces::srv::Comimagen>
  : std::true_type
{
};

template<>
struct is_service_request<example_interfaces::srv::Comimagen_Request>
  : std::true_type
{
};

template<>
struct is_service_response<example_interfaces::srv::Comimagen_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // EXAMPLE_INTERFACES__SRV__DETAIL__COMIMAGEN__TRAITS_HPP_
