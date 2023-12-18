// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hellocm_msgs:msg/GPSOut.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__GPS_OUT__STRUCT_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__GPS_OUT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'time'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hellocm_msgs__msg__GPSOut __attribute__((deprecated))
#else
# define DEPRECATED__hellocm_msgs__msg__GPSOut __declspec(deprecated)
#endif

namespace hellocm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GPSOut_
{
  using Type = GPSOut_<ContainerAllocator>;

  explicit GPSOut_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    time(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cycleno = 0ll;
      this->synthdelay = 0.0;
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->altitude = 0.0;
    }
  }

  explicit GPSOut_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    time(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cycleno = 0ll;
      this->synthdelay = 0.0;
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->altitude = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _time_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _time_type time;
  using _cycleno_type =
    int64_t;
  _cycleno_type cycleno;
  using _synthdelay_type =
    double;
  _synthdelay_type synthdelay;
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _longitude_type =
    double;
  _longitude_type longitude;
  using _altitude_type =
    double;
  _altitude_type altitude;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__time(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->time = _arg;
    return *this;
  }
  Type & set__cycleno(
    const int64_t & _arg)
  {
    this->cycleno = _arg;
    return *this;
  }
  Type & set__synthdelay(
    const double & _arg)
  {
    this->synthdelay = _arg;
    return *this;
  }
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__altitude(
    const double & _arg)
  {
    this->altitude = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hellocm_msgs::msg::GPSOut_<ContainerAllocator> *;
  using ConstRawPtr =
    const hellocm_msgs::msg::GPSOut_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hellocm_msgs::msg::GPSOut_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hellocm_msgs::msg::GPSOut_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::GPSOut_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::GPSOut_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::GPSOut_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::GPSOut_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hellocm_msgs::msg::GPSOut_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hellocm_msgs::msg::GPSOut_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hellocm_msgs__msg__GPSOut
    std::shared_ptr<hellocm_msgs::msg::GPSOut_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hellocm_msgs__msg__GPSOut
    std::shared_ptr<hellocm_msgs::msg::GPSOut_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GPSOut_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    if (this->cycleno != other.cycleno) {
      return false;
    }
    if (this->synthdelay != other.synthdelay) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->altitude != other.altitude) {
      return false;
    }
    return true;
  }
  bool operator!=(const GPSOut_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GPSOut_

// alias to use template instance with default allocator
using GPSOut =
  hellocm_msgs::msg::GPSOut_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__GPS_OUT__STRUCT_HPP_
