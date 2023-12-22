// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hellocm_msgs:msg/IMUOut.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__IMU_OUT__BUILDER_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__IMU_OUT__BUILDER_HPP_

#include "hellocm_msgs/msg/detail/imu_out__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hellocm_msgs
{

namespace msg
{

namespace builder
{

class Init_IMUOut_yaw_acc
{
public:
  explicit Init_IMUOut_yaw_acc(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::msg::IMUOut yaw_acc(::hellocm_msgs::msg::IMUOut::_yaw_acc_type arg)
  {
    msg_.yaw_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_pitch_acc
{
public:
  explicit Init_IMUOut_pitch_acc(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_yaw_acc pitch_acc(::hellocm_msgs::msg::IMUOut::_pitch_acc_type arg)
  {
    msg_.pitch_acc = std::move(arg);
    return Init_IMUOut_yaw_acc(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_roll_acc
{
public:
  explicit Init_IMUOut_roll_acc(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_pitch_acc roll_acc(::hellocm_msgs::msg::IMUOut::_roll_acc_type arg)
  {
    msg_.roll_acc = std::move(arg);
    return Init_IMUOut_pitch_acc(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_az
{
public:
  explicit Init_IMUOut_az(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_roll_acc az(::hellocm_msgs::msg::IMUOut::_az_type arg)
  {
    msg_.az = std::move(arg);
    return Init_IMUOut_roll_acc(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_ay
{
public:
  explicit Init_IMUOut_ay(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_az ay(::hellocm_msgs::msg::IMUOut::_ay_type arg)
  {
    msg_.ay = std::move(arg);
    return Init_IMUOut_az(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_ax
{
public:
  explicit Init_IMUOut_ax(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_ay ax(::hellocm_msgs::msg::IMUOut::_ax_type arg)
  {
    msg_.ax = std::move(arg);
    return Init_IMUOut_ay(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_yaw_rate
{
public:
  explicit Init_IMUOut_yaw_rate(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_ax yaw_rate(::hellocm_msgs::msg::IMUOut::_yaw_rate_type arg)
  {
    msg_.yaw_rate = std::move(arg);
    return Init_IMUOut_ax(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_pitch_rate
{
public:
  explicit Init_IMUOut_pitch_rate(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_yaw_rate pitch_rate(::hellocm_msgs::msg::IMUOut::_pitch_rate_type arg)
  {
    msg_.pitch_rate = std::move(arg);
    return Init_IMUOut_yaw_rate(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_roll_rate
{
public:
  explicit Init_IMUOut_roll_rate(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_pitch_rate roll_rate(::hellocm_msgs::msg::IMUOut::_roll_rate_type arg)
  {
    msg_.roll_rate = std::move(arg);
    return Init_IMUOut_pitch_rate(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_vz
{
public:
  explicit Init_IMUOut_vz(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_roll_rate vz(::hellocm_msgs::msg::IMUOut::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return Init_IMUOut_roll_rate(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_vy
{
public:
  explicit Init_IMUOut_vy(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_vz vy(::hellocm_msgs::msg::IMUOut::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_IMUOut_vz(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_vx
{
public:
  explicit Init_IMUOut_vx(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_vy vx(::hellocm_msgs::msg::IMUOut::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_IMUOut_vy(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_synthdelay
{
public:
  explicit Init_IMUOut_synthdelay(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_vx synthdelay(::hellocm_msgs::msg::IMUOut::_synthdelay_type arg)
  {
    msg_.synthdelay = std::move(arg);
    return Init_IMUOut_vx(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_cycleno
{
public:
  explicit Init_IMUOut_cycleno(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_synthdelay cycleno(::hellocm_msgs::msg::IMUOut::_cycleno_type arg)
  {
    msg_.cycleno = std::move(arg);
    return Init_IMUOut_synthdelay(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_time
{
public:
  explicit Init_IMUOut_time(::hellocm_msgs::msg::IMUOut & msg)
  : msg_(msg)
  {}
  Init_IMUOut_cycleno time(::hellocm_msgs::msg::IMUOut::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_IMUOut_cycleno(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

class Init_IMUOut_header
{
public:
  Init_IMUOut_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IMUOut_time header(::hellocm_msgs::msg::IMUOut::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_IMUOut_time(msg_);
  }

private:
  ::hellocm_msgs::msg::IMUOut msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::msg::IMUOut>()
{
  return hellocm_msgs::msg::builder::Init_IMUOut_header();
}

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__IMU_OUT__BUILDER_HPP_
