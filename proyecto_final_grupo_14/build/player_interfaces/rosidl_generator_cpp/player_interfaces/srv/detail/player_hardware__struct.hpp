// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from player_interfaces:srv/PlayerHardware.idl
// generated code does not contain a copyright notice

#ifndef PLAYER_INTERFACES__SRV__DETAIL__PLAYER_HARDWARE__STRUCT_HPP_
#define PLAYER_INTERFACES__SRV__DETAIL__PLAYER_HARDWARE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'posiciones'
#include "geometry_msgs/msg/detail/twist__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__player_interfaces__srv__PlayerHardware_Request __attribute__((deprecated))
#else
# define DEPRECATED__player_interfaces__srv__PlayerHardware_Request __declspec(deprecated)
#endif

namespace player_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PlayerHardware_Request_
{
  using Type = PlayerHardware_Request_<ContainerAllocator>;

  explicit PlayerHardware_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nombre = "";
    }
  }

  explicit PlayerHardware_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : nombre(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nombre = "";
    }
  }

  // field types and members
  using _nombre_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _nombre_type nombre;
  using _posiciones_type =
    std::vector<geometry_msgs::msg::Twist_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Twist_<ContainerAllocator>>>;
  _posiciones_type posiciones;
  using _keys_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _keys_type keys;
  using _times_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _times_type times;

  // setters for named parameter idiom
  Type & set__nombre(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->nombre = _arg;
    return *this;
  }
  Type & set__posiciones(
    const std::vector<geometry_msgs::msg::Twist_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Twist_<ContainerAllocator>>> & _arg)
  {
    this->posiciones = _arg;
    return *this;
  }
  Type & set__keys(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->keys = _arg;
    return *this;
  }
  Type & set__times(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->times = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    player_interfaces::srv::PlayerHardware_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const player_interfaces::srv::PlayerHardware_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<player_interfaces::srv::PlayerHardware_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<player_interfaces::srv::PlayerHardware_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      player_interfaces::srv::PlayerHardware_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<player_interfaces::srv::PlayerHardware_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      player_interfaces::srv::PlayerHardware_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<player_interfaces::srv::PlayerHardware_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<player_interfaces::srv::PlayerHardware_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<player_interfaces::srv::PlayerHardware_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__player_interfaces__srv__PlayerHardware_Request
    std::shared_ptr<player_interfaces::srv::PlayerHardware_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__player_interfaces__srv__PlayerHardware_Request
    std::shared_ptr<player_interfaces::srv::PlayerHardware_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlayerHardware_Request_ & other) const
  {
    if (this->nombre != other.nombre) {
      return false;
    }
    if (this->posiciones != other.posiciones) {
      return false;
    }
    if (this->keys != other.keys) {
      return false;
    }
    if (this->times != other.times) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlayerHardware_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlayerHardware_Request_

// alias to use template instance with default allocator
using PlayerHardware_Request =
  player_interfaces::srv::PlayerHardware_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace player_interfaces


#ifndef _WIN32
# define DEPRECATED__player_interfaces__srv__PlayerHardware_Response __attribute__((deprecated))
#else
# define DEPRECATED__player_interfaces__srv__PlayerHardware_Response __declspec(deprecated)
#endif

namespace player_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PlayerHardware_Response_
{
  using Type = PlayerHardware_Response_<ContainerAllocator>;

  explicit PlayerHardware_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit PlayerHardware_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    player_interfaces::srv::PlayerHardware_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const player_interfaces::srv::PlayerHardware_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<player_interfaces::srv::PlayerHardware_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<player_interfaces::srv::PlayerHardware_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      player_interfaces::srv::PlayerHardware_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<player_interfaces::srv::PlayerHardware_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      player_interfaces::srv::PlayerHardware_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<player_interfaces::srv::PlayerHardware_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<player_interfaces::srv::PlayerHardware_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<player_interfaces::srv::PlayerHardware_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__player_interfaces__srv__PlayerHardware_Response
    std::shared_ptr<player_interfaces::srv::PlayerHardware_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__player_interfaces__srv__PlayerHardware_Response
    std::shared_ptr<player_interfaces::srv::PlayerHardware_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlayerHardware_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlayerHardware_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlayerHardware_Response_

// alias to use template instance with default allocator
using PlayerHardware_Response =
  player_interfaces::srv::PlayerHardware_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace player_interfaces

namespace player_interfaces
{

namespace srv
{

struct PlayerHardware
{
  using Request = player_interfaces::srv::PlayerHardware_Request;
  using Response = player_interfaces::srv::PlayerHardware_Response;
};

}  // namespace srv

}  // namespace player_interfaces

#endif  // PLAYER_INTERFACES__SRV__DETAIL__PLAYER_HARDWARE__STRUCT_HPP_
