// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from player_interfaces:srv/PlayerHardware.idl
// generated code does not contain a copyright notice

#ifndef PLAYER_INTERFACES__SRV__DETAIL__PLAYER_HARDWARE__TRAITS_HPP_
#define PLAYER_INTERFACES__SRV__DETAIL__PLAYER_HARDWARE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "player_interfaces/srv/detail/player_hardware__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'posiciones'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace player_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PlayerHardware_Request & msg,
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
    out << ", ";
  }

  // member: keys
  {
    if (msg.keys.size() == 0) {
      out << "keys: []";
    } else {
      out << "keys: [";
      size_t pending_items = msg.keys.size();
      for (auto item : msg.keys) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: times
  {
    if (msg.times.size() == 0) {
      out << "times: []";
    } else {
      out << "times: [";
      size_t pending_items = msg.times.size();
      for (auto item : msg.times) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const PlayerHardware_Request & msg,
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

  // member: keys
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.keys.size() == 0) {
      out << "keys: []\n";
    } else {
      out << "keys:\n";
      for (auto item : msg.keys) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: times
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.times.size() == 0) {
      out << "times: []\n";
    } else {
      out << "times:\n";
      for (auto item : msg.times) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PlayerHardware_Request & msg, bool use_flow_style = false)
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
  const player_interfaces::srv::PlayerHardware_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  player_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use player_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const player_interfaces::srv::PlayerHardware_Request & msg)
{
  return player_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<player_interfaces::srv::PlayerHardware_Request>()
{
  return "player_interfaces::srv::PlayerHardware_Request";
}

template<>
inline const char * name<player_interfaces::srv::PlayerHardware_Request>()
{
  return "player_interfaces/srv/PlayerHardware_Request";
}

template<>
struct has_fixed_size<player_interfaces::srv::PlayerHardware_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<player_interfaces::srv::PlayerHardware_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<player_interfaces::srv::PlayerHardware_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace player_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PlayerHardware_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PlayerHardware_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PlayerHardware_Response & msg, bool use_flow_style = false)
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
  const player_interfaces::srv::PlayerHardware_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  player_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use player_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const player_interfaces::srv::PlayerHardware_Response & msg)
{
  return player_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<player_interfaces::srv::PlayerHardware_Response>()
{
  return "player_interfaces::srv::PlayerHardware_Response";
}

template<>
inline const char * name<player_interfaces::srv::PlayerHardware_Response>()
{
  return "player_interfaces/srv/PlayerHardware_Response";
}

template<>
struct has_fixed_size<player_interfaces::srv::PlayerHardware_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<player_interfaces::srv::PlayerHardware_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<player_interfaces::srv::PlayerHardware_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<player_interfaces::srv::PlayerHardware>()
{
  return "player_interfaces::srv::PlayerHardware";
}

template<>
inline const char * name<player_interfaces::srv::PlayerHardware>()
{
  return "player_interfaces/srv/PlayerHardware";
}

template<>
struct has_fixed_size<player_interfaces::srv::PlayerHardware>
  : std::integral_constant<
    bool,
    has_fixed_size<player_interfaces::srv::PlayerHardware_Request>::value &&
    has_fixed_size<player_interfaces::srv::PlayerHardware_Response>::value
  >
{
};

template<>
struct has_bounded_size<player_interfaces::srv::PlayerHardware>
  : std::integral_constant<
    bool,
    has_bounded_size<player_interfaces::srv::PlayerHardware_Request>::value &&
    has_bounded_size<player_interfaces::srv::PlayerHardware_Response>::value
  >
{
};

template<>
struct is_service<player_interfaces::srv::PlayerHardware>
  : std::true_type
{
};

template<>
struct is_service_request<player_interfaces::srv::PlayerHardware_Request>
  : std::true_type
{
};

template<>
struct is_service_response<player_interfaces::srv::PlayerHardware_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // PLAYER_INTERFACES__SRV__DETAIL__PLAYER_HARDWARE__TRAITS_HPP_
