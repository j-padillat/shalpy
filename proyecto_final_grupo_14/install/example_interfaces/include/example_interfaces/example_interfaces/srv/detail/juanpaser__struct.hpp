// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from example_interfaces:srv/Juanpaser.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_INTERFACES__SRV__DETAIL__JUANPASER__STRUCT_HPP_
#define EXAMPLE_INTERFACES__SRV__DETAIL__JUANPASER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__example_interfaces__srv__Juanpaser_Request __attribute__((deprecated))
#else
# define DEPRECATED__example_interfaces__srv__Juanpaser_Request __declspec(deprecated)
#endif

namespace example_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Juanpaser_Request_
{
  using Type = Juanpaser_Request_<ContainerAllocator>;

  explicit Juanpaser_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->banner = 0l;
      this->empieza = "";
    }
  }

  explicit Juanpaser_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : empieza(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->banner = 0l;
      this->empieza = "";
    }
  }

  // field types and members
  using _banner_type =
    int32_t;
  _banner_type banner;
  using _empieza_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _empieza_type empieza;

  // setters for named parameter idiom
  Type & set__banner(
    const int32_t & _arg)
  {
    this->banner = _arg;
    return *this;
  }
  Type & set__empieza(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->empieza = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    example_interfaces::srv::Juanpaser_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const example_interfaces::srv::Juanpaser_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<example_interfaces::srv::Juanpaser_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<example_interfaces::srv::Juanpaser_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      example_interfaces::srv::Juanpaser_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<example_interfaces::srv::Juanpaser_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      example_interfaces::srv::Juanpaser_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<example_interfaces::srv::Juanpaser_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<example_interfaces::srv::Juanpaser_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<example_interfaces::srv::Juanpaser_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__example_interfaces__srv__Juanpaser_Request
    std::shared_ptr<example_interfaces::srv::Juanpaser_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__example_interfaces__srv__Juanpaser_Request
    std::shared_ptr<example_interfaces::srv::Juanpaser_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Juanpaser_Request_ & other) const
  {
    if (this->banner != other.banner) {
      return false;
    }
    if (this->empieza != other.empieza) {
      return false;
    }
    return true;
  }
  bool operator!=(const Juanpaser_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Juanpaser_Request_

// alias to use template instance with default allocator
using Juanpaser_Request =
  example_interfaces::srv::Juanpaser_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace example_interfaces


#ifndef _WIN32
# define DEPRECATED__example_interfaces__srv__Juanpaser_Response __attribute__((deprecated))
#else
# define DEPRECATED__example_interfaces__srv__Juanpaser_Response __declspec(deprecated)
#endif

namespace example_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Juanpaser_Response_
{
  using Type = Juanpaser_Response_<ContainerAllocator>;

  explicit Juanpaser_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->termina = "";
    }
  }

  explicit Juanpaser_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : termina(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->termina = "";
    }
  }

  // field types and members
  using _termina_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _termina_type termina;

  // setters for named parameter idiom
  Type & set__termina(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->termina = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    example_interfaces::srv::Juanpaser_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const example_interfaces::srv::Juanpaser_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<example_interfaces::srv::Juanpaser_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<example_interfaces::srv::Juanpaser_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      example_interfaces::srv::Juanpaser_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<example_interfaces::srv::Juanpaser_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      example_interfaces::srv::Juanpaser_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<example_interfaces::srv::Juanpaser_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<example_interfaces::srv::Juanpaser_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<example_interfaces::srv::Juanpaser_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__example_interfaces__srv__Juanpaser_Response
    std::shared_ptr<example_interfaces::srv::Juanpaser_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__example_interfaces__srv__Juanpaser_Response
    std::shared_ptr<example_interfaces::srv::Juanpaser_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Juanpaser_Response_ & other) const
  {
    if (this->termina != other.termina) {
      return false;
    }
    return true;
  }
  bool operator!=(const Juanpaser_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Juanpaser_Response_

// alias to use template instance with default allocator
using Juanpaser_Response =
  example_interfaces::srv::Juanpaser_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace example_interfaces

namespace example_interfaces
{

namespace srv
{

struct Juanpaser
{
  using Request = example_interfaces::srv::Juanpaser_Request;
  using Response = example_interfaces::srv::Juanpaser_Response;
};

}  // namespace srv

}  // namespace example_interfaces

#endif  // EXAMPLE_INTERFACES__SRV__DETAIL__JUANPASER__STRUCT_HPP_
