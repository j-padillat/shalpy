// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from player_interfaces:srv/Player.idl
// generated code does not contain a copyright notice

#ifndef PLAYER_INTERFACES__SRV__DETAIL__PLAYER__STRUCT_HPP_
#define PLAYER_INTERFACES__SRV__DETAIL__PLAYER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__player_interfaces__srv__Player_Request __attribute__((deprecated))
#else
# define DEPRECATED__player_interfaces__srv__Player_Request __declspec(deprecated)
#endif

namespace player_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Player_Request_
{
  using Type = Player_Request_<ContainerAllocator>;

  explicit Player_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nombre = "";
    }
  }

  explicit Player_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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

  // setters for named parameter idiom
  Type & set__nombre(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->nombre = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    player_interfaces::srv::Player_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const player_interfaces::srv::Player_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<player_interfaces::srv::Player_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<player_interfaces::srv::Player_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      player_interfaces::srv::Player_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<player_interfaces::srv::Player_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      player_interfaces::srv::Player_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<player_interfaces::srv::Player_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<player_interfaces::srv::Player_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<player_interfaces::srv::Player_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__player_interfaces__srv__Player_Request
    std::shared_ptr<player_interfaces::srv::Player_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__player_interfaces__srv__Player_Request
    std::shared_ptr<player_interfaces::srv::Player_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Player_Request_ & other) const
  {
    if (this->nombre != other.nombre) {
      return false;
    }
    return true;
  }
  bool operator!=(const Player_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Player_Request_

// alias to use template instance with default allocator
using Player_Request =
  player_interfaces::srv::Player_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace player_interfaces


#ifndef _WIN32
# define DEPRECATED__player_interfaces__srv__Player_Response __attribute__((deprecated))
#else
# define DEPRECATED__player_interfaces__srv__Player_Response __declspec(deprecated)
#endif

namespace player_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Player_Response_
{
  using Type = Player_Response_<ContainerAllocator>;

  explicit Player_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Player_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    player_interfaces::srv::Player_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const player_interfaces::srv::Player_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<player_interfaces::srv::Player_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<player_interfaces::srv::Player_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      player_interfaces::srv::Player_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<player_interfaces::srv::Player_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      player_interfaces::srv::Player_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<player_interfaces::srv::Player_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<player_interfaces::srv::Player_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<player_interfaces::srv::Player_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__player_interfaces__srv__Player_Response
    std::shared_ptr<player_interfaces::srv::Player_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__player_interfaces__srv__Player_Response
    std::shared_ptr<player_interfaces::srv::Player_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Player_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Player_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Player_Response_

// alias to use template instance with default allocator
using Player_Response =
  player_interfaces::srv::Player_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace player_interfaces

namespace player_interfaces
{

namespace srv
{

struct Player
{
  using Request = player_interfaces::srv::Player_Request;
  using Response = player_interfaces::srv::Player_Response;
};

}  // namespace srv

}  // namespace player_interfaces

#endif  // PLAYER_INTERFACES__SRV__DETAIL__PLAYER__STRUCT_HPP_
