// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from player_interfaces:msg/Trace.idl
// generated code does not contain a copyright notice

#ifndef PLAYER_INTERFACES__MSG__DETAIL__TRACE__TRAITS_HPP_
#define PLAYER_INTERFACES__MSG__DETAIL__TRACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "player_interfaces/msg/detail/trace__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace player_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Trace & msg,
  std::ostream & out)
{
  out << "{";
  // member: key
  {
    out << "key: ";
    rosidl_generator_traits::value_to_yaml(msg.key, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: th
  {
    out << "th: ";
    rosidl_generator_traits::value_to_yaml(msg.th, out);
    out << ", ";
  }

  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Trace & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: key
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "key: ";
    rosidl_generator_traits::value_to_yaml(msg.key, out);
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

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: th
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "th: ";
    rosidl_generator_traits::value_to_yaml(msg.th, out);
    out << "\n";
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Trace & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace player_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use player_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const player_interfaces::msg::Trace & msg,
  std::ostream & out, size_t indentation = 0)
{
  player_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use player_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const player_interfaces::msg::Trace & msg)
{
  return player_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<player_interfaces::msg::Trace>()
{
  return "player_interfaces::msg::Trace";
}

template<>
inline const char * name<player_interfaces::msg::Trace>()
{
  return "player_interfaces/msg/Trace";
}

template<>
struct has_fixed_size<player_interfaces::msg::Trace>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<player_interfaces::msg::Trace>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<player_interfaces::msg::Trace>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PLAYER_INTERFACES__MSG__DETAIL__TRACE__TRAITS_HPP_
