// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/Paths.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__PATHS__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__PATHS__BUILDER_HPP_

#include "custom_msgs/msg/detail/paths__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_Paths_right_roi
{
public:
  explicit Init_Paths_right_roi(::custom_msgs::msg::Paths & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::Paths right_roi(::custom_msgs::msg::Paths::_right_roi_type arg)
  {
    msg_.right_roi = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::Paths msg_;
};

class Init_Paths_left_roi
{
public:
  explicit Init_Paths_left_roi(::custom_msgs::msg::Paths & msg)
  : msg_(msg)
  {}
  Init_Paths_right_roi left_roi(::custom_msgs::msg::Paths::_left_roi_type arg)
  {
    msg_.left_roi = std::move(arg);
    return Init_Paths_right_roi(msg_);
  }

private:
  ::custom_msgs::msg::Paths msg_;
};

class Init_Paths_id
{
public:
  explicit Init_Paths_id(::custom_msgs::msg::Paths & msg)
  : msg_(msg)
  {}
  Init_Paths_left_roi id(::custom_msgs::msg::Paths::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Paths_left_roi(msg_);
  }

private:
  ::custom_msgs::msg::Paths msg_;
};

class Init_Paths_h
{
public:
  explicit Init_Paths_h(::custom_msgs::msg::Paths & msg)
  : msg_(msg)
  {}
  Init_Paths_id h(::custom_msgs::msg::Paths::_h_type arg)
  {
    msg_.h = std::move(arg);
    return Init_Paths_id(msg_);
  }

private:
  ::custom_msgs::msg::Paths msg_;
};

class Init_Paths_s
{
public:
  explicit Init_Paths_s(::custom_msgs::msg::Paths & msg)
  : msg_(msg)
  {}
  Init_Paths_h s(::custom_msgs::msg::Paths::_s_type arg)
  {
    msg_.s = std::move(arg);
    return Init_Paths_h(msg_);
  }

private:
  ::custom_msgs::msg::Paths msg_;
};

class Init_Paths_y
{
public:
  explicit Init_Paths_y(::custom_msgs::msg::Paths & msg)
  : msg_(msg)
  {}
  Init_Paths_s y(::custom_msgs::msg::Paths::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Paths_s(msg_);
  }

private:
  ::custom_msgs::msg::Paths msg_;
};

class Init_Paths_x
{
public:
  Init_Paths_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Paths_y x(::custom_msgs::msg::Paths::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Paths_y(msg_);
  }

private:
  ::custom_msgs::msg::Paths msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::Paths>()
{
  return custom_msgs::msg::builder::Init_Paths_x();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__PATHS__BUILDER_HPP_
