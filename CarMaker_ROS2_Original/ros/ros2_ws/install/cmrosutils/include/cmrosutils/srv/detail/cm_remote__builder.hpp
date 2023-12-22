// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cmrosutils:srv/CMRemote.idl
// generated code does not contain a copyright notice

#ifndef CMROSUTILS__SRV__DETAIL__CM_REMOTE__BUILDER_HPP_
#define CMROSUTILS__SRV__DETAIL__CM_REMOTE__BUILDER_HPP_

#include "cmrosutils/srv/detail/cm_remote__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace cmrosutils
{

namespace srv
{

namespace builder
{

class Init_CMRemote_Request_data
{
public:
  explicit Init_CMRemote_Request_data(::cmrosutils::srv::CMRemote_Request & msg)
  : msg_(msg)
  {}
  ::cmrosutils::srv::CMRemote_Request data(::cmrosutils::srv::CMRemote_Request::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cmrosutils::srv::CMRemote_Request msg_;
};

class Init_CMRemote_Request_msg
{
public:
  explicit Init_CMRemote_Request_msg(::cmrosutils::srv::CMRemote_Request & msg)
  : msg_(msg)
  {}
  Init_CMRemote_Request_data msg(::cmrosutils::srv::CMRemote_Request::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return Init_CMRemote_Request_data(msg_);
  }

private:
  ::cmrosutils::srv::CMRemote_Request msg_;
};

class Init_CMRemote_Request_type
{
public:
  Init_CMRemote_Request_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CMRemote_Request_msg type(::cmrosutils::srv::CMRemote_Request::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_CMRemote_Request_msg(msg_);
  }

private:
  ::cmrosutils::srv::CMRemote_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cmrosutils::srv::CMRemote_Request>()
{
  return cmrosutils::srv::builder::Init_CMRemote_Request_type();
}

}  // namespace cmrosutils


namespace cmrosutils
{

namespace srv
{

namespace builder
{

class Init_CMRemote_Response_msg
{
public:
  explicit Init_CMRemote_Response_msg(::cmrosutils::srv::CMRemote_Response & msg)
  : msg_(msg)
  {}
  ::cmrosutils::srv::CMRemote_Response msg(::cmrosutils::srv::CMRemote_Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cmrosutils::srv::CMRemote_Response msg_;
};

class Init_CMRemote_Response_res
{
public:
  Init_CMRemote_Response_res()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CMRemote_Response_msg res(::cmrosutils::srv::CMRemote_Response::_res_type arg)
  {
    msg_.res = std::move(arg);
    return Init_CMRemote_Response_msg(msg_);
  }

private:
  ::cmrosutils::srv::CMRemote_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cmrosutils::srv::CMRemote_Response>()
{
  return cmrosutils::srv::builder::Init_CMRemote_Response_res();
}

}  // namespace cmrosutils

#endif  // CMROSUTILS__SRV__DETAIL__CM_REMOTE__BUILDER_HPP_
