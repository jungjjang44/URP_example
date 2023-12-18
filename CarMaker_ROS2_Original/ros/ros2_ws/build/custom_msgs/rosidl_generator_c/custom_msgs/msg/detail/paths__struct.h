// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/Paths.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__PATHS__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__PATHS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'x'
// Member 'y'
// Member 's'
// Member 'h'
// Member 'id'
// Member 'left_roi'
// Member 'right_roi'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/Paths in the package custom_msgs.
typedef struct custom_msgs__msg__Paths
{
  rosidl_runtime_c__double__Sequence x;
  rosidl_runtime_c__double__Sequence y;
  rosidl_runtime_c__double__Sequence s;
  rosidl_runtime_c__double__Sequence h;
  rosidl_runtime_c__double__Sequence id;
  rosidl_runtime_c__float__Sequence left_roi;
  rosidl_runtime_c__float__Sequence right_roi;
} custom_msgs__msg__Paths;

// Struct for a sequence of custom_msgs__msg__Paths.
typedef struct custom_msgs__msg__Paths__Sequence
{
  custom_msgs__msg__Paths * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__Paths__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__PATHS__STRUCT_H_
