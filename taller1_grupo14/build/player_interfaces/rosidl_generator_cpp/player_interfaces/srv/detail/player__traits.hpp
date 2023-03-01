// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from player_interfaces:srv/Player.idl
// generated code does not contain a copyright notice

#ifndef PLAYER_INTERFACES__SRV__DETAIL__PLAYER__TRAITS_HPP_
#define PLAYER_INTERFACES__SRV__DETAIL__PLAYER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "player_interfaces/srv/detail/player__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'posiciones'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace player_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Player_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: nombre
  {
    out << "nombre: ";
    rosidl_generator_traits::value_to_yaml(msg.nombre, out);
    out << ", ";
  }

  // member: posiciones
  {
    if (msg.posiciones.size() == 0) {
      out << "posiciones: []";
    } else {
      out << "posiciones: [";
      size_t pending_items = msg.posiciones.size();
      for (auto item : msg.posiciones) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Player_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: nombre
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nombre: ";
    rosidl_generator_traits::value_to_yaml(msg.nombre, out);
    out << "\n";
  }

  // member: posiciones
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.posiciones.size() == 0) {
      out << "posiciones: []\n";
    } else {
      out << "posiciones:\n";
      for (auto item : msg.posiciones) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Player_Request & msg, bool use_flow_style = false)
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

}  // namespace player_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use player_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const player_interfaces::srv::Player_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  player_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use player_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const player_interfaces::srv::Player_Request & msg)
{
  return player_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<player_interfaces::srv::Player_Request>()
{
  return "player_interfaces::srv::Player_Request";
}

template<>
inline const char * name<player_interfaces::srv::Player_Request>()
{
  return "player_interfaces/srv/Player_Request";
}

template<>
struct has_fixed_size<player_interfaces::srv::Player_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<player_interfaces::srv::Player_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<player_interfaces::srv::Player_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace player_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Player_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: respuesta
  {
    out << "respuesta: ";
    rosidl_generator_traits::value_to_yaml(msg.respuesta, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Player_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: respuesta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "respuesta: ";
    rosidl_generator_traits::value_to_yaml(msg.respuesta, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Player_Response & msg, bool use_flow_style = false)
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

}  // namespace player_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use player_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const player_interfaces::srv::Player_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  player_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use player_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const player_interfaces::srv::Player_Response & msg)
{
  return player_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<player_interfaces::srv::Player_Response>()
{
  return "player_interfaces::srv::Player_Response";
}

template<>
inline const char * name<player_interfaces::srv::Player_Response>()
{
  return "player_interfaces/srv/Player_Response";
}

template<>
struct has_fixed_size<player_interfaces::srv::Player_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<player_interfaces::srv::Player_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<player_interfaces::srv::Player_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<player_interfaces::srv::Player>()
{
  return "player_interfaces::srv::Player";
}

template<>
inline const char * name<player_interfaces::srv::Player>()
{
  return "player_interfaces/srv/Player";
}

template<>
struct has_fixed_size<player_interfaces::srv::Player>
  : std::integral_constant<
    bool,
    has_fixed_size<player_interfaces::srv::Player_Request>::value &&
    has_fixed_size<player_interfaces::srv::Player_Response>::value
  >
{
};

template<>
struct has_bounded_size<player_interfaces::srv::Player>
  : std::integral_constant<
    bool,
    has_bounded_size<player_interfaces::srv::Player_Request>::value &&
    has_bounded_size<player_interfaces::srv::Player_Response>::value
  >
{
};

template<>
struct is_service<player_interfaces::srv::Player>
  : std::true_type
{
};

template<>
struct is_service_request<player_interfaces::srv::Player_Request>
  : std::true_type
{
};

template<>
struct is_service_response<player_interfaces::srv::Player_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // PLAYER_INTERFACES__SRV__DETAIL__PLAYER__TRAITS_HPP_
