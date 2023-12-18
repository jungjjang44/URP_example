// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/Paths.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/paths__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `x`
// Member `y`
// Member `s`
// Member `h`
// Member `id`
// Member `left_roi`
// Member `right_roi`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
custom_msgs__msg__Paths__init(custom_msgs__msg__Paths * msg)
{
  if (!msg) {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__init(&msg->x, 0)) {
    custom_msgs__msg__Paths__fini(msg);
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__init(&msg->y, 0)) {
    custom_msgs__msg__Paths__fini(msg);
    return false;
  }
  // s
  if (!rosidl_runtime_c__double__Sequence__init(&msg->s, 0)) {
    custom_msgs__msg__Paths__fini(msg);
    return false;
  }
  // h
  if (!rosidl_runtime_c__double__Sequence__init(&msg->h, 0)) {
    custom_msgs__msg__Paths__fini(msg);
    return false;
  }
  // id
  if (!rosidl_runtime_c__double__Sequence__init(&msg->id, 0)) {
    custom_msgs__msg__Paths__fini(msg);
    return false;
  }
  // left_roi
  if (!rosidl_runtime_c__float__Sequence__init(&msg->left_roi, 0)) {
    custom_msgs__msg__Paths__fini(msg);
    return false;
  }
  // right_roi
  if (!rosidl_runtime_c__float__Sequence__init(&msg->right_roi, 0)) {
    custom_msgs__msg__Paths__fini(msg);
    return false;
  }
  return true;
}

void
custom_msgs__msg__Paths__fini(custom_msgs__msg__Paths * msg)
{
  if (!msg) {
    return;
  }
  // x
  rosidl_runtime_c__double__Sequence__fini(&msg->x);
  // y
  rosidl_runtime_c__double__Sequence__fini(&msg->y);
  // s
  rosidl_runtime_c__double__Sequence__fini(&msg->s);
  // h
  rosidl_runtime_c__double__Sequence__fini(&msg->h);
  // id
  rosidl_runtime_c__double__Sequence__fini(&msg->id);
  // left_roi
  rosidl_runtime_c__float__Sequence__fini(&msg->left_roi);
  // right_roi
  rosidl_runtime_c__float__Sequence__fini(&msg->right_roi);
}

bool
custom_msgs__msg__Paths__are_equal(const custom_msgs__msg__Paths * lhs, const custom_msgs__msg__Paths * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->x), &(rhs->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->y), &(rhs->y)))
  {
    return false;
  }
  // s
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->s), &(rhs->s)))
  {
    return false;
  }
  // h
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->h), &(rhs->h)))
  {
    return false;
  }
  // id
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  // left_roi
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->left_roi), &(rhs->left_roi)))
  {
    return false;
  }
  // right_roi
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->right_roi), &(rhs->right_roi)))
  {
    return false;
  }
  return true;
}

bool
custom_msgs__msg__Paths__copy(
  const custom_msgs__msg__Paths * input,
  custom_msgs__msg__Paths * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->x), &(output->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->y), &(output->y)))
  {
    return false;
  }
  // s
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->s), &(output->s)))
  {
    return false;
  }
  // h
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->h), &(output->h)))
  {
    return false;
  }
  // id
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  // left_roi
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->left_roi), &(output->left_roi)))
  {
    return false;
  }
  // right_roi
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->right_roi), &(output->right_roi)))
  {
    return false;
  }
  return true;
}

custom_msgs__msg__Paths *
custom_msgs__msg__Paths__create()
{
  custom_msgs__msg__Paths * msg = (custom_msgs__msg__Paths *)malloc(sizeof(custom_msgs__msg__Paths));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__Paths));
  bool success = custom_msgs__msg__Paths__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__Paths__destroy(custom_msgs__msg__Paths * msg)
{
  if (msg) {
    custom_msgs__msg__Paths__fini(msg);
  }
  free(msg);
}


bool
custom_msgs__msg__Paths__Sequence__init(custom_msgs__msg__Paths__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  custom_msgs__msg__Paths * data = NULL;
  if (size) {
    data = (custom_msgs__msg__Paths *)calloc(size, sizeof(custom_msgs__msg__Paths));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__Paths__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__Paths__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msgs__msg__Paths__Sequence__fini(custom_msgs__msg__Paths__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msgs__msg__Paths__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msgs__msg__Paths__Sequence *
custom_msgs__msg__Paths__Sequence__create(size_t size)
{
  custom_msgs__msg__Paths__Sequence * array = (custom_msgs__msg__Paths__Sequence *)malloc(sizeof(custom_msgs__msg__Paths__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__Paths__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__Paths__Sequence__destroy(custom_msgs__msg__Paths__Sequence * array)
{
  if (array) {
    custom_msgs__msg__Paths__Sequence__fini(array);
  }
  free(array);
}

bool
custom_msgs__msg__Paths__Sequence__are_equal(const custom_msgs__msg__Paths__Sequence * lhs, const custom_msgs__msg__Paths__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__Paths__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__Paths__Sequence__copy(
  const custom_msgs__msg__Paths__Sequence * input,
  custom_msgs__msg__Paths__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__Paths);
    custom_msgs__msg__Paths * data =
      (custom_msgs__msg__Paths *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__Paths__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__Paths__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msgs__msg__Paths__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
