// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from hellocm_msgs:msg/SignalLightIn.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "hellocm_msgs/msg/detail/signal_light_in__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace hellocm_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SignalLightIn_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) hellocm_msgs::msg::SignalLightIn(_init);
}

void SignalLightIn_fini_function(void * message_memory)
{
  auto typed_message = static_cast<hellocm_msgs::msg::SignalLightIn *>(message_memory);
  typed_message->~SignalLightIn();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SignalLightIn_message_member_array[2] = {
  {
    "signal_light",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs::msg::SignalLightIn, signal_light),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "hazard",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs::msg::SignalLightIn, hazard),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SignalLightIn_message_members = {
  "hellocm_msgs::msg",  // message namespace
  "SignalLightIn",  // message name
  2,  // number of fields
  sizeof(hellocm_msgs::msg::SignalLightIn),
  SignalLightIn_message_member_array,  // message members
  SignalLightIn_init_function,  // function to initialize message memory (memory has to be allocated)
  SignalLightIn_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SignalLightIn_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SignalLightIn_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace hellocm_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<hellocm_msgs::msg::SignalLightIn>()
{
  return &::hellocm_msgs::msg::rosidl_typesupport_introspection_cpp::SignalLightIn_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, hellocm_msgs, msg, SignalLightIn)() {
  return &::hellocm_msgs::msg::rosidl_typesupport_introspection_cpp::SignalLightIn_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
