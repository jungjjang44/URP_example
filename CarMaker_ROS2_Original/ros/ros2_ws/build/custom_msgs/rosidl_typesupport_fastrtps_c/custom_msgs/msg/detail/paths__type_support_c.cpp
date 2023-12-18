// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_msgs:msg/Paths.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/paths__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_msgs/msg/detail/paths__struct.h"
#include "custom_msgs/msg/detail/paths__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // h, id, left_roi, right_roi, s, x, y
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // h, id, left_roi, right_roi, s, x, y

// forward declare type support functions


using _Paths__ros_msg_type = custom_msgs__msg__Paths;

static bool _Paths__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Paths__ros_msg_type * ros_message = static_cast<const _Paths__ros_msg_type *>(untyped_ros_message);
  // Field name: x
  {
    size_t size = ros_message->x.size;
    auto array_ptr = ros_message->x.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: y
  {
    size_t size = ros_message->y.size;
    auto array_ptr = ros_message->y.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: s
  {
    size_t size = ros_message->s.size;
    auto array_ptr = ros_message->s.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: h
  {
    size_t size = ros_message->h.size;
    auto array_ptr = ros_message->h.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: id
  {
    size_t size = ros_message->id.size;
    auto array_ptr = ros_message->id.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: left_roi
  {
    size_t size = ros_message->left_roi.size;
    auto array_ptr = ros_message->left_roi.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: right_roi
  {
    size_t size = ros_message->right_roi.size;
    auto array_ptr = ros_message->right_roi.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _Paths__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Paths__ros_msg_type * ros_message = static_cast<_Paths__ros_msg_type *>(untyped_ros_message);
  // Field name: x
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->x.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->x);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->x, size)) {
      fprintf(stderr, "failed to create array for field 'x'");
      return false;
    }
    auto array_ptr = ros_message->x.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: y
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->y.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->y);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->y, size)) {
      fprintf(stderr, "failed to create array for field 'y'");
      return false;
    }
    auto array_ptr = ros_message->y.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: s
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->s.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->s);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->s, size)) {
      fprintf(stderr, "failed to create array for field 's'");
      return false;
    }
    auto array_ptr = ros_message->s.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: h
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->h.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->h);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->h, size)) {
      fprintf(stderr, "failed to create array for field 'h'");
      return false;
    }
    auto array_ptr = ros_message->h.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: id
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->id.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->id);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->id, size)) {
      fprintf(stderr, "failed to create array for field 'id'");
      return false;
    }
    auto array_ptr = ros_message->id.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: left_roi
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->left_roi.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->left_roi);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->left_roi, size)) {
      fprintf(stderr, "failed to create array for field 'left_roi'");
      return false;
    }
    auto array_ptr = ros_message->left_roi.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: right_roi
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->right_roi.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->right_roi);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->right_roi, size)) {
      fprintf(stderr, "failed to create array for field 'right_roi'");
      return false;
    }
    auto array_ptr = ros_message->right_roi.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t get_serialized_size_custom_msgs__msg__Paths(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Paths__ros_msg_type * ros_message = static_cast<const _Paths__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name x
  {
    size_t array_size = ros_message->x.size;
    auto array_ptr = ros_message->x.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y
  {
    size_t array_size = ros_message->y.size;
    auto array_ptr = ros_message->y.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name s
  {
    size_t array_size = ros_message->s.size;
    auto array_ptr = ros_message->s.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name h
  {
    size_t array_size = ros_message->h.size;
    auto array_ptr = ros_message->h.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name id
  {
    size_t array_size = ros_message->id.size;
    auto array_ptr = ros_message->id.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_roi
  {
    size_t array_size = ros_message->left_roi.size;
    auto array_ptr = ros_message->left_roi.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_roi
  {
    size_t array_size = ros_message->right_roi.size;
    auto array_ptr = ros_message->right_roi.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Paths__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_msgs__msg__Paths(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t max_serialized_size_custom_msgs__msg__Paths(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: x
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: y
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: s
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: h
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: id
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: left_roi
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_roi
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Paths__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_msgs__msg__Paths(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Paths = {
  "custom_msgs::msg",
  "Paths",
  _Paths__cdr_serialize,
  _Paths__cdr_deserialize,
  _Paths__get_serialized_size,
  _Paths__max_serialized_size
};

static rosidl_message_type_support_t _Paths__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Paths,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, msg, Paths)() {
  return &_Paths__type_support;
}

#if defined(__cplusplus)
}
#endif
