// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from example_interfaces:srv/Comimagen.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_INTERFACES__SRV__DETAIL__COMIMAGEN__STRUCT_HPP_
#define EXAMPLE_INTERFACES__SRV__DETAIL__COMIMAGEN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'imagen'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__example_interfaces__srv__Comimagen_Request __attribute__((deprecated))
#else
# define DEPRECATED__example_interfaces__srv__Comimagen_Request __declspec(deprecated)
#endif

namespace example_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Comimagen_Request_
{
  using Type = Comimagen_Request_<ContainerAllocator>;

  explicit Comimagen_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imagen(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->banner = 0l;
    }
  }

  explicit Comimagen_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imagen(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->banner = 0l;
    }
  }

  // field types and members
  using _imagen_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _imagen_type imagen;
  using _banner_type =
    int32_t;
  _banner_type banner;

  // setters for named parameter idiom
  Type & set__imagen(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->imagen = _arg;
    return *this;
  }
  Type & set__banner(
    const int32_t & _arg)
  {
    this->banner = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    example_interfaces::srv::Comimagen_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const example_interfaces::srv::Comimagen_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<example_interfaces::srv::Comimagen_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<example_interfaces::srv::Comimagen_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      example_interfaces::srv::Comimagen_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<example_interfaces::srv::Comimagen_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      example_interfaces::srv::Comimagen_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<example_interfaces::srv::Comimagen_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<example_interfaces::srv::Comimagen_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<example_interfaces::srv::Comimagen_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__example_interfaces__srv__Comimagen_Request
    std::shared_ptr<example_interfaces::srv::Comimagen_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__example_interfaces__srv__Comimagen_Request
    std::shared_ptr<example_interfaces::srv::Comimagen_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Comimagen_Request_ & other) const
  {
    if (this->imagen != other.imagen) {
      return false;
    }
    if (this->banner != other.banner) {
      return false;
    }
    return true;
  }
  bool operator!=(const Comimagen_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Comimagen_Request_

// alias to use template instance with default allocator
using Comimagen_Request =
  example_interfaces::srv::Comimagen_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace example_interfaces


#ifndef _WIN32
# define DEPRECATED__example_interfaces__srv__Comimagen_Response __attribute__((deprecated))
#else
# define DEPRECATED__example_interfaces__srv__Comimagen_Response __declspec(deprecated)
#endif

namespace example_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Comimagen_Response_
{
  using Type = Comimagen_Response_<ContainerAllocator>;

  explicit Comimagen_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->finalizo = "";
    }
  }

  explicit Comimagen_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : finalizo(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->finalizo = "";
    }
  }

  // field types and members
  using _finalizo_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _finalizo_type finalizo;

  // setters for named parameter idiom
  Type & set__finalizo(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->finalizo = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    example_interfaces::srv::Comimagen_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const example_interfaces::srv::Comimagen_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<example_interfaces::srv::Comimagen_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<example_interfaces::srv::Comimagen_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      example_interfaces::srv::Comimagen_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<example_interfaces::srv::Comimagen_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      example_interfaces::srv::Comimagen_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<example_interfaces::srv::Comimagen_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<example_interfaces::srv::Comimagen_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<example_interfaces::srv::Comimagen_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__example_interfaces__srv__Comimagen_Response
    std::shared_ptr<example_interfaces::srv::Comimagen_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__example_interfaces__srv__Comimagen_Response
    std::shared_ptr<example_interfaces::srv::Comimagen_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Comimagen_Response_ & other) const
  {
    if (this->finalizo != other.finalizo) {
      return false;
    }
    return true;
  }
  bool operator!=(const Comimagen_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Comimagen_Response_

// alias to use template instance with default allocator
using Comimagen_Response =
  example_interfaces::srv::Comimagen_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace example_interfaces

namespace example_interfaces
{

namespace srv
{

struct Comimagen
{
  using Request = example_interfaces::srv::Comimagen_Request;
  using Response = example_interfaces::srv::Comimagen_Response;
};

}  // namespace srv

}  // namespace example_interfaces

#endif  // EXAMPLE_INTERFACES__SRV__DETAIL__COMIMAGEN__STRUCT_HPP_
