// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hellocm_msgs:msg/SignalLightIn.idl
// generated code does not contain a copyright notice
#include "hellocm_msgs/msg/detail/signal_light_in__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hellocm_msgs/msg/detail/signal_light_in__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace hellocm_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hellocm_msgs
cdr_serialize(
  const hellocm_msgs::msg::SignalLightIn & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: signal_light
  cdr << ros_message.signal_light;
  // Member: hazard
  cdr << (ros_message.hazard ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hellocm_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hellocm_msgs::msg::SignalLightIn & ros_message)
{
  // Member: signal_light
  cdr >> ros_message.signal_light;

  // Member: hazard
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hazard = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hellocm_msgs
get_serialized_size(
  const hellocm_msgs::msg::SignalLightIn & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: signal_light
  {
    size_t item_size = sizeof(ros_message.signal_light);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hazard
  {
    size_t item_size = sizeof(ros_message.hazard);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hellocm_msgs
max_serialized_size_SignalLightIn(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: signal_light
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hazard
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _SignalLightIn__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hellocm_msgs::msg::SignalLightIn *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SignalLightIn__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hellocm_msgs::msg::SignalLightIn *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SignalLightIn__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hellocm_msgs::msg::SignalLightIn *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SignalLightIn__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_SignalLightIn(full_bounded, 0);
}

static message_type_support_callbacks_t _SignalLightIn__callbacks = {
  "hellocm_msgs::msg",
  "SignalLightIn",
  _SignalLightIn__cdr_serialize,
  _SignalLightIn__cdr_deserialize,
  _SignalLightIn__get_serialized_size,
  _SignalLightIn__max_serialized_size
};

static rosidl_message_type_support_t _SignalLightIn__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SignalLightIn__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace hellocm_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_hellocm_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<hellocm_msgs::msg::SignalLightIn>()
{
  return &hellocm_msgs::msg::typesupport_fastrtps_cpp::_SignalLightIn__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hellocm_msgs, msg, SignalLightIn)() {
  return &hellocm_msgs::msg::typesupport_fastrtps_cpp::_SignalLightIn__handle;
}

#ifdef __cplusplus
}
#endif
