// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hellocm_msgs:msg/VehicleInfoOut.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__VEHICLE_INFO_OUT__STRUCT_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__VEHICLE_INFO_OUT__STRUCT_HPP_

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
# define DEPRECATED__hellocm_msgs__msg__VehicleInfoOut __attribute__((deprecated))
#else
# define DEPRECATED__hellocm_msgs__msg__VehicleInfoOut __declspec(deprecated)
#endif

namespace hellocm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleInfoOut_
{
  using Type = VehicleInfoOut_<ContainerAllocator>;

  explicit VehicleInfoOut_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    time(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cycleno = 0ll;
      this->synthdelay = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
      this->vx = 0.0;
      this->vy = 0.0;
      this->vz = 0.0;
      this->roll_vel = 0.0;
      this->pitch_vel = 0.0;
      this->yaw_vel = 0.0;
      this->ax = 0.0;
      this->ay = 0.0;
      this->az = 0.0;
      this->roll_acc = 0.0;
      this->pitch_acc = 0.0;
      this->yaw_acc = 0.0;
    }
  }

  explicit VehicleInfoOut_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    time(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cycleno = 0ll;
      this->synthdelay = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
      this->vx = 0.0;
      this->vy = 0.0;
      this->vz = 0.0;
      this->roll_vel = 0.0;
      this->pitch_vel = 0.0;
      this->yaw_vel = 0.0;
      this->ax = 0.0;
      this->ay = 0.0;
      this->az = 0.0;
      this->roll_acc = 0.0;
      this->pitch_acc = 0.0;
      this->yaw_acc = 0.0;
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
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _yaw_type =
    double;
  _yaw_type yaw;
  using _vx_type =
    double;
  _vx_type vx;
  using _vy_type =
    double;
  _vy_type vy;
  using _vz_type =
    double;
  _vz_type vz;
  using _roll_vel_type =
    double;
  _roll_vel_type roll_vel;
  using _pitch_vel_type =
    double;
  _pitch_vel_type pitch_vel;
  using _yaw_vel_type =
    double;
  _yaw_vel_type yaw_vel;
  using _ax_type =
    double;
  _ax_type ax;
  using _ay_type =
    double;
  _ay_type ay;
  using _az_type =
    double;
  _az_type az;
  using _roll_acc_type =
    double;
  _roll_acc_type roll_acc;
  using _pitch_acc_type =
    double;
  _pitch_acc_type pitch_acc;
  using _yaw_acc_type =
    double;
  _yaw_acc_type yaw_acc;

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
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__vx(
    const double & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__vy(
    const double & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__vz(
    const double & _arg)
  {
    this->vz = _arg;
    return *this;
  }
  Type & set__roll_vel(
    const double & _arg)
  {
    this->roll_vel = _arg;
    return *this;
  }
  Type & set__pitch_vel(
    const double & _arg)
  {
    this->pitch_vel = _arg;
    return *this;
  }
  Type & set__yaw_vel(
    const double & _arg)
  {
    this->yaw_vel = _arg;
    return *this;
  }
  Type & set__ax(
    const double & _arg)
  {
    this->ax = _arg;
    return *this;
  }
  Type & set__ay(
    const double & _arg)
  {
    this->ay = _arg;
    return *this;
  }
  Type & set__az(
    const double & _arg)
  {
    this->az = _arg;
    return *this;
  }
  Type & set__roll_acc(
    const double & _arg)
  {
    this->roll_acc = _arg;
    return *this;
  }
  Type & set__pitch_acc(
    const double & _arg)
  {
    this->pitch_acc = _arg;
    return *this;
  }
  Type & set__yaw_acc(
    const double & _arg)
  {
    this->yaw_acc = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hellocm_msgs::msg::VehicleInfoOut_<ContainerAllocator> *;
  using ConstRawPtr =
    const hellocm_msgs::msg::VehicleInfoOut_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hellocm_msgs::msg::VehicleInfoOut_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hellocm_msgs::msg::VehicleInfoOut_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::VehicleInfoOut_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::VehicleInfoOut_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::VehicleInfoOut_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::VehicleInfoOut_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hellocm_msgs::msg::VehicleInfoOut_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hellocm_msgs::msg::VehicleInfoOut_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hellocm_msgs__msg__VehicleInfoOut
    std::shared_ptr<hellocm_msgs::msg::VehicleInfoOut_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hellocm_msgs__msg__VehicleInfoOut
    std::shared_ptr<hellocm_msgs::msg::VehicleInfoOut_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleInfoOut_ & other) const
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
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    if (this->vz != other.vz) {
      return false;
    }
    if (this->roll_vel != other.roll_vel) {
      return false;
    }
    if (this->pitch_vel != other.pitch_vel) {
      return false;
    }
    if (this->yaw_vel != other.yaw_vel) {
      return false;
    }
    if (this->ax != other.ax) {
      return false;
    }
    if (this->ay != other.ay) {
      return false;
    }
    if (this->az != other.az) {
      return false;
    }
    if (this->roll_acc != other.roll_acc) {
      return false;
    }
    if (this->pitch_acc != other.pitch_acc) {
      return false;
    }
    if (this->yaw_acc != other.yaw_acc) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleInfoOut_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleInfoOut_

// alias to use template instance with default allocator
using VehicleInfoOut =
  hellocm_msgs::msg::VehicleInfoOut_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__VEHICLE_INFO_OUT__STRUCT_HPP_
