// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from hellocm_msgs:msg/ObjectInfoOut.idl
// generated code does not contain a copyright notice
#include "hellocm_msgs/msg/detail/object_info_out__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "hellocm_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hellocm_msgs/msg/detail/object_info_out__struct.h"
#include "hellocm_msgs/msg/detail/object_info_out__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "builtin_interfaces/msg/detail/time__functions.h"  // time
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hellocm_msgs
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hellocm_msgs
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hellocm_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hellocm_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hellocm_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hellocm_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _ObjectInfoOut__ros_msg_type = hellocm_msgs__msg__ObjectInfoOut;

static bool _ObjectInfoOut__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ObjectInfoOut__ros_msg_type * ros_message = static_cast<const _ObjectInfoOut__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: time
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->time, cdr))
    {
      return false;
    }
  }

  // Field name: cycleno
  {
    cdr << ros_message->cycleno;
  }

  // Field name: synthdelay
  {
    cdr << ros_message->synthdelay;
  }

  // Field name: num
  {
    cdr << ros_message->num;
  }

  // Field name: id
  {
    size_t size = 50;
    auto array_ptr = ros_message->id;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: x
  {
    size_t size = 50;
    auto array_ptr = ros_message->x;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: y
  {
    size_t size = 50;
    auto array_ptr = ros_message->y;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: w
  {
    size_t size = 50;
    auto array_ptr = ros_message->w;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: h
  {
    size_t size = 50;
    auto array_ptr = ros_message->h;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: vx
  {
    size_t size = 50;
    auto array_ptr = ros_message->vx;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: vy
  {
    size_t size = 50;
    auto array_ptr = ros_message->vy;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: alpha
  {
    size_t size = 50;
    auto array_ptr = ros_message->alpha;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: global_vx
  {
    size_t size = 50;
    auto array_ptr = ros_message->global_vx;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: global_vy
  {
    size_t size = 50;
    auto array_ptr = ros_message->global_vy;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _ObjectInfoOut__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ObjectInfoOut__ros_msg_type * ros_message = static_cast<_ObjectInfoOut__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: time
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->time))
    {
      return false;
    }
  }

  // Field name: cycleno
  {
    cdr >> ros_message->cycleno;
  }

  // Field name: synthdelay
  {
    cdr >> ros_message->synthdelay;
  }

  // Field name: num
  {
    cdr >> ros_message->num;
  }

  // Field name: id
  {
    size_t size = 50;
    auto array_ptr = ros_message->id;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: x
  {
    size_t size = 50;
    auto array_ptr = ros_message->x;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: y
  {
    size_t size = 50;
    auto array_ptr = ros_message->y;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: w
  {
    size_t size = 50;
    auto array_ptr = ros_message->w;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: h
  {
    size_t size = 50;
    auto array_ptr = ros_message->h;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: vx
  {
    size_t size = 50;
    auto array_ptr = ros_message->vx;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: vy
  {
    size_t size = 50;
    auto array_ptr = ros_message->vy;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: alpha
  {
    size_t size = 50;
    auto array_ptr = ros_message->alpha;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: global_vx
  {
    size_t size = 50;
    auto array_ptr = ros_message->global_vx;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: global_vy
  {
    size_t size = 50;
    auto array_ptr = ros_message->global_vy;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hellocm_msgs
size_t get_serialized_size_hellocm_msgs__msg__ObjectInfoOut(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ObjectInfoOut__ros_msg_type * ros_message = static_cast<const _ObjectInfoOut__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name time

  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->time), current_alignment);
  // field.name cycleno
  {
    size_t item_size = sizeof(ros_message->cycleno);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name synthdelay
  {
    size_t item_size = sizeof(ros_message->synthdelay);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name num
  {
    size_t item_size = sizeof(ros_message->num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name id
  {
    size_t array_size = 50;
    auto array_ptr = ros_message->id;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name x
  {
    size_t array_size = 50;
    auto array_ptr = ros_message->x;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y
  {
    size_t array_size = 50;
    auto array_ptr = ros_message->y;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name w
  {
    size_t array_size = 50;
    auto array_ptr = ros_message->w;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name h
  {
    size_t array_size = 50;
    auto array_ptr = ros_message->h;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vx
  {
    size_t array_size = 50;
    auto array_ptr = ros_message->vx;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vy
  {
    size_t array_size = 50;
    auto array_ptr = ros_message->vy;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name alpha
  {
    size_t array_size = 50;
    auto array_ptr = ros_message->alpha;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name global_vx
  {
    size_t array_size = 50;
    auto array_ptr = ros_message->global_vx;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name global_vy
  {
    size_t array_size = 50;
    auto array_ptr = ros_message->global_vy;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ObjectInfoOut__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hellocm_msgs__msg__ObjectInfoOut(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hellocm_msgs
size_t max_serialized_size_hellocm_msgs__msg__ObjectInfoOut(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: time
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_builtin_interfaces__msg__Time(
        full_bounded, current_alignment);
    }
  }
  // member: cycleno
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: synthdelay
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: num
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: id
  {
    size_t array_size = 50;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: x
  {
    size_t array_size = 50;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: y
  {
    size_t array_size = 50;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: w
  {
    size_t array_size = 50;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: h
  {
    size_t array_size = 50;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vx
  {
    size_t array_size = 50;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vy
  {
    size_t array_size = 50;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: alpha
  {
    size_t array_size = 50;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: global_vx
  {
    size_t array_size = 50;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: global_vy
  {
    size_t array_size = 50;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ObjectInfoOut__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_hellocm_msgs__msg__ObjectInfoOut(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ObjectInfoOut = {
  "hellocm_msgs::msg",
  "ObjectInfoOut",
  _ObjectInfoOut__cdr_serialize,
  _ObjectInfoOut__cdr_deserialize,
  _ObjectInfoOut__get_serialized_size,
  _ObjectInfoOut__max_serialized_size
};

static rosidl_message_type_support_t _ObjectInfoOut__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ObjectInfoOut,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hellocm_msgs, msg, ObjectInfoOut)() {
  return &_ObjectInfoOut__type_support;
}

#if defined(__cplusplus)
}
#endif
