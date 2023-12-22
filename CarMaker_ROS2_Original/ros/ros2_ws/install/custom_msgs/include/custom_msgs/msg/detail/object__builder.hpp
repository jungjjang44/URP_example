// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/Object.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__OBJECT__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__OBJECT__BUILDER_HPP_

#include "custom_msgs/msg/detail/object__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_Object_collision_status
{
public:
  explicit Init_Object_collision_status(::custom_msgs::msg::Object & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::Object collision_status(::custom_msgs::msg::Object::_collision_status_type arg)
  {
    msg_.collision_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::Object msg_;
};

class Init_Object_heading
{
public:
  explicit Init_Object_heading(::custom_msgs::msg::Object & msg)
  : msg_(msg)
  {}
  Init_Object_collision_status heading(::custom_msgs::msg::Object::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_Object_collision_status(msg_);
  }

private:
  ::custom_msgs::msg::Object msg_;
};

class Init_Object_y
{
public:
  explicit Init_Object_y(::custom_msgs::msg::Object & msg)
  : msg_(msg)
  {}
  Init_Object_heading y(::custom_msgs::msg::Object::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Object_heading(msg_);
  }

private:
  ::custom_msgs::msg::Object msg_;
};

class Init_Object_x
{
public:
  explicit Init_Object_x(::custom_msgs::msg::Object & msg)
  : msg_(msg)
  {}
  Init_Object_y x(::custom_msgs::msg::Object::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Object_y(msg_);
  }

private:
  ::custom_msgs::msg::Object msg_;
};

class Init_Object_id
{
public:
  Init_Object_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Object_x id(::custom_msgs::msg::Object::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Object_x(msg_);
  }

private:
  ::custom_msgs::msg::Object msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::Object>()
{
  return custom_msgs::msg::builder::Init_Object_id();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__OBJECT__BUILDER_HPP_
