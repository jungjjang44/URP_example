// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hellocm_msgs:msg/GPSOut.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__GPS_OUT__BUILDER_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__GPS_OUT__BUILDER_HPP_

#include "hellocm_msgs/msg/detail/gps_out__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hellocm_msgs
{

namespace msg
{

namespace builder
{

class Init_GPSOut_altitude
{
public:
  explicit Init_GPSOut_altitude(::hellocm_msgs::msg::GPSOut & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::msg::GPSOut altitude(::hellocm_msgs::msg::GPSOut::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::msg::GPSOut msg_;
};

class Init_GPSOut_longitude
{
public:
  explicit Init_GPSOut_longitude(::hellocm_msgs::msg::GPSOut & msg)
  : msg_(msg)
  {}
  Init_GPSOut_altitude longitude(::hellocm_msgs::msg::GPSOut::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_GPSOut_altitude(msg_);
  }

private:
  ::hellocm_msgs::msg::GPSOut msg_;
};

class Init_GPSOut_latitude
{
public:
  explicit Init_GPSOut_latitude(::hellocm_msgs::msg::GPSOut & msg)
  : msg_(msg)
  {}
  Init_GPSOut_longitude latitude(::hellocm_msgs::msg::GPSOut::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_GPSOut_longitude(msg_);
  }

private:
  ::hellocm_msgs::msg::GPSOut msg_;
};

class Init_GPSOut_synthdelay
{
public:
  explicit Init_GPSOut_synthdelay(::hellocm_msgs::msg::GPSOut & msg)
  : msg_(msg)
  {}
  Init_GPSOut_latitude synthdelay(::hellocm_msgs::msg::GPSOut::_synthdelay_type arg)
  {
    msg_.synthdelay = std::move(arg);
    return Init_GPSOut_latitude(msg_);
  }

private:
  ::hellocm_msgs::msg::GPSOut msg_;
};

class Init_GPSOut_cycleno
{
public:
  explicit Init_GPSOut_cycleno(::hellocm_msgs::msg::GPSOut & msg)
  : msg_(msg)
  {}
  Init_GPSOut_synthdelay cycleno(::hellocm_msgs::msg::GPSOut::_cycleno_type arg)
  {
    msg_.cycleno = std::move(arg);
    return Init_GPSOut_synthdelay(msg_);
  }

private:
  ::hellocm_msgs::msg::GPSOut msg_;
};

class Init_GPSOut_time
{
public:
  explicit Init_GPSOut_time(::hellocm_msgs::msg::GPSOut & msg)
  : msg_(msg)
  {}
  Init_GPSOut_cycleno time(::hellocm_msgs::msg::GPSOut::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_GPSOut_cycleno(msg_);
  }

private:
  ::hellocm_msgs::msg::GPSOut msg_;
};

class Init_GPSOut_header
{
public:
  Init_GPSOut_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GPSOut_time header(::hellocm_msgs::msg::GPSOut::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GPSOut_time(msg_);
  }

private:
  ::hellocm_msgs::msg::GPSOut msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::msg::GPSOut>()
{
  return hellocm_msgs::msg::builder::Init_GPSOut_header();
}

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__GPS_OUT__BUILDER_HPP_
