// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hellocm_msgs:msg/VehicleInfoOut.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__VEHICLE_INFO_OUT__BUILDER_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__VEHICLE_INFO_OUT__BUILDER_HPP_

#include "hellocm_msgs/msg/detail/vehicle_info_out__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hellocm_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleInfoOut_y
{
public:
  explicit Init_VehicleInfoOut_y(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::msg::VehicleInfoOut y(::hellocm_msgs::msg::VehicleInfoOut::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_x
{
public:
  explicit Init_VehicleInfoOut_x(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_y x(::hellocm_msgs::msg::VehicleInfoOut::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_VehicleInfoOut_y(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_yaw_acc
{
public:
  explicit Init_VehicleInfoOut_yaw_acc(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_x yaw_acc(::hellocm_msgs::msg::VehicleInfoOut::_yaw_acc_type arg)
  {
    msg_.yaw_acc = std::move(arg);
    return Init_VehicleInfoOut_x(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_pitch_acc
{
public:
  explicit Init_VehicleInfoOut_pitch_acc(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_yaw_acc pitch_acc(::hellocm_msgs::msg::VehicleInfoOut::_pitch_acc_type arg)
  {
    msg_.pitch_acc = std::move(arg);
    return Init_VehicleInfoOut_yaw_acc(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_roll_acc
{
public:
  explicit Init_VehicleInfoOut_roll_acc(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_pitch_acc roll_acc(::hellocm_msgs::msg::VehicleInfoOut::_roll_acc_type arg)
  {
    msg_.roll_acc = std::move(arg);
    return Init_VehicleInfoOut_pitch_acc(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_az
{
public:
  explicit Init_VehicleInfoOut_az(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_roll_acc az(::hellocm_msgs::msg::VehicleInfoOut::_az_type arg)
  {
    msg_.az = std::move(arg);
    return Init_VehicleInfoOut_roll_acc(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_ay
{
public:
  explicit Init_VehicleInfoOut_ay(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_az ay(::hellocm_msgs::msg::VehicleInfoOut::_ay_type arg)
  {
    msg_.ay = std::move(arg);
    return Init_VehicleInfoOut_az(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_ax
{
public:
  explicit Init_VehicleInfoOut_ax(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_ay ax(::hellocm_msgs::msg::VehicleInfoOut::_ax_type arg)
  {
    msg_.ax = std::move(arg);
    return Init_VehicleInfoOut_ay(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_yaw_vel
{
public:
  explicit Init_VehicleInfoOut_yaw_vel(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_ax yaw_vel(::hellocm_msgs::msg::VehicleInfoOut::_yaw_vel_type arg)
  {
    msg_.yaw_vel = std::move(arg);
    return Init_VehicleInfoOut_ax(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_pitch_vel
{
public:
  explicit Init_VehicleInfoOut_pitch_vel(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_yaw_vel pitch_vel(::hellocm_msgs::msg::VehicleInfoOut::_pitch_vel_type arg)
  {
    msg_.pitch_vel = std::move(arg);
    return Init_VehicleInfoOut_yaw_vel(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_roll_vel
{
public:
  explicit Init_VehicleInfoOut_roll_vel(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_pitch_vel roll_vel(::hellocm_msgs::msg::VehicleInfoOut::_roll_vel_type arg)
  {
    msg_.roll_vel = std::move(arg);
    return Init_VehicleInfoOut_pitch_vel(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_vz
{
public:
  explicit Init_VehicleInfoOut_vz(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_roll_vel vz(::hellocm_msgs::msg::VehicleInfoOut::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return Init_VehicleInfoOut_roll_vel(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_vy
{
public:
  explicit Init_VehicleInfoOut_vy(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_vz vy(::hellocm_msgs::msg::VehicleInfoOut::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_VehicleInfoOut_vz(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_vx
{
public:
  explicit Init_VehicleInfoOut_vx(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_vy vx(::hellocm_msgs::msg::VehicleInfoOut::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_VehicleInfoOut_vy(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_yaw
{
public:
  explicit Init_VehicleInfoOut_yaw(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_vx yaw(::hellocm_msgs::msg::VehicleInfoOut::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_VehicleInfoOut_vx(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_pitch
{
public:
  explicit Init_VehicleInfoOut_pitch(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_yaw pitch(::hellocm_msgs::msg::VehicleInfoOut::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_VehicleInfoOut_yaw(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_roll
{
public:
  explicit Init_VehicleInfoOut_roll(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_pitch roll(::hellocm_msgs::msg::VehicleInfoOut::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_VehicleInfoOut_pitch(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_synthdelay
{
public:
  explicit Init_VehicleInfoOut_synthdelay(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_roll synthdelay(::hellocm_msgs::msg::VehicleInfoOut::_synthdelay_type arg)
  {
    msg_.synthdelay = std::move(arg);
    return Init_VehicleInfoOut_roll(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_cycleno
{
public:
  explicit Init_VehicleInfoOut_cycleno(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_synthdelay cycleno(::hellocm_msgs::msg::VehicleInfoOut::_cycleno_type arg)
  {
    msg_.cycleno = std::move(arg);
    return Init_VehicleInfoOut_synthdelay(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_time
{
public:
  explicit Init_VehicleInfoOut_time(::hellocm_msgs::msg::VehicleInfoOut & msg)
  : msg_(msg)
  {}
  Init_VehicleInfoOut_cycleno time(::hellocm_msgs::msg::VehicleInfoOut::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_VehicleInfoOut_cycleno(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

class Init_VehicleInfoOut_header
{
public:
  Init_VehicleInfoOut_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleInfoOut_time header(::hellocm_msgs::msg::VehicleInfoOut::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VehicleInfoOut_time(msg_);
  }

private:
  ::hellocm_msgs::msg::VehicleInfoOut msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::msg::VehicleInfoOut>()
{
  return hellocm_msgs::msg::builder::Init_VehicleInfoOut_header();
}

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__VEHICLE_INFO_OUT__BUILDER_HPP_
