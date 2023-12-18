// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hellocm_msgs:msg/IMUOut.idl
// generated code does not contain a copyright notice
#include "hellocm_msgs/msg/detail/imu_out__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hellocm_msgs/msg/detail/imu_out__struct.hpp"

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
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace builtin_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const builtin_interfaces::msg::Time &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  builtin_interfaces::msg::Time &);
size_t get_serialized_size(
  const builtin_interfaces::msg::Time &,
  size_t current_alignment);
size_t
max_serialized_size_Time(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace builtin_interfaces


namespace hellocm_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hellocm_msgs
cdr_serialize(
  const hellocm_msgs::msg::IMUOut & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: time
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.time,
    cdr);
  // Member: cycleno
  cdr << ros_message.cycleno;
  // Member: synthdelay
  cdr << ros_message.synthdelay;
  // Member: vx
  cdr << ros_message.vx;
  // Member: vy
  cdr << ros_message.vy;
  // Member: vz
  cdr << ros_message.vz;
  // Member: roll_rate
  cdr << ros_message.roll_rate;
  // Member: pitch_rate
  cdr << ros_message.pitch_rate;
  // Member: yaw_rate
  cdr << ros_message.yaw_rate;
  // Member: ax
  cdr << ros_message.ax;
  // Member: ay
  cdr << ros_message.ay;
  // Member: az
  cdr << ros_message.az;
  // Member: roll_acc
  cdr << ros_message.roll_acc;
  // Member: pitch_acc
  cdr << ros_message.pitch_acc;
  // Member: yaw_acc
  cdr << ros_message.yaw_acc;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hellocm_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hellocm_msgs::msg::IMUOut & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: time
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.time);

  // Member: cycleno
  cdr >> ros_message.cycleno;

  // Member: synthdelay
  cdr >> ros_message.synthdelay;

  // Member: vx
  cdr >> ros_message.vx;

  // Member: vy
  cdr >> ros_message.vy;

  // Member: vz
  cdr >> ros_message.vz;

  // Member: roll_rate
  cdr >> ros_message.roll_rate;

  // Member: pitch_rate
  cdr >> ros_message.pitch_rate;

  // Member: yaw_rate
  cdr >> ros_message.yaw_rate;

  // Member: ax
  cdr >> ros_message.ax;

  // Member: ay
  cdr >> ros_message.ay;

  // Member: az
  cdr >> ros_message.az;

  // Member: roll_acc
  cdr >> ros_message.roll_acc;

  // Member: pitch_acc
  cdr >> ros_message.pitch_acc;

  // Member: yaw_acc
  cdr >> ros_message.yaw_acc;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hellocm_msgs
get_serialized_size(
  const hellocm_msgs::msg::IMUOut & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: time

  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.time, current_alignment);
  // Member: cycleno
  {
    size_t item_size = sizeof(ros_message.cycleno);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: synthdelay
  {
    size_t item_size = sizeof(ros_message.synthdelay);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vx
  {
    size_t item_size = sizeof(ros_message.vx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vy
  {
    size_t item_size = sizeof(ros_message.vy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vz
  {
    size_t item_size = sizeof(ros_message.vz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: roll_rate
  {
    size_t item_size = sizeof(ros_message.roll_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pitch_rate
  {
    size_t item_size = sizeof(ros_message.pitch_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: yaw_rate
  {
    size_t item_size = sizeof(ros_message.yaw_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ax
  {
    size_t item_size = sizeof(ros_message.ax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ay
  {
    size_t item_size = sizeof(ros_message.ay);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: az
  {
    size_t item_size = sizeof(ros_message.az);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: roll_acc
  {
    size_t item_size = sizeof(ros_message.roll_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pitch_acc
  {
    size_t item_size = sizeof(ros_message.pitch_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: yaw_acc
  {
    size_t item_size = sizeof(ros_message.yaw_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hellocm_msgs
max_serialized_size_IMUOut(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: time
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        builtin_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Time(
        full_bounded, current_alignment);
    }
  }

  // Member: cycleno
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: synthdelay
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vx
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vy
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vz
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: roll_rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: pitch_rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: yaw_rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ax
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ay
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: az
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: roll_acc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: pitch_acc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: yaw_acc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _IMUOut__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hellocm_msgs::msg::IMUOut *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _IMUOut__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hellocm_msgs::msg::IMUOut *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _IMUOut__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hellocm_msgs::msg::IMUOut *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _IMUOut__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_IMUOut(full_bounded, 0);
}

static message_type_support_callbacks_t _IMUOut__callbacks = {
  "hellocm_msgs::msg",
  "IMUOut",
  _IMUOut__cdr_serialize,
  _IMUOut__cdr_deserialize,
  _IMUOut__get_serialized_size,
  _IMUOut__max_serialized_size
};

static rosidl_message_type_support_t _IMUOut__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_IMUOut__callbacks,
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
get_message_type_support_handle<hellocm_msgs::msg::IMUOut>()
{
  return &hellocm_msgs::msg::typesupport_fastrtps_cpp::_IMUOut__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hellocm_msgs, msg, IMUOut)() {
  return &hellocm_msgs::msg::typesupport_fastrtps_cpp::_IMUOut__handle;
}

#ifdef __cplusplus
}
#endif
