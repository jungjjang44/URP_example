// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hellocm_msgs:msg/IMUOut.idl
// generated code does not contain a copyright notice
#include "hellocm_msgs/msg/detail/imu_out__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `time`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
hellocm_msgs__msg__IMUOut__init(hellocm_msgs__msg__IMUOut * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    hellocm_msgs__msg__IMUOut__fini(msg);
    return false;
  }
  // time
  if (!builtin_interfaces__msg__Time__init(&msg->time)) {
    hellocm_msgs__msg__IMUOut__fini(msg);
    return false;
  }
  // cycleno
  // synthdelay
  // vx
  // vy
  // vz
  // roll_rate
  // pitch_rate
  // yaw_rate
  // ax
  // ay
  // az
  // roll_acc
  // pitch_acc
  // yaw_acc
  return true;
}

void
hellocm_msgs__msg__IMUOut__fini(hellocm_msgs__msg__IMUOut * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // time
  builtin_interfaces__msg__Time__fini(&msg->time);
  // cycleno
  // synthdelay
  // vx
  // vy
  // vz
  // roll_rate
  // pitch_rate
  // yaw_rate
  // ax
  // ay
  // az
  // roll_acc
  // pitch_acc
  // yaw_acc
}

bool
hellocm_msgs__msg__IMUOut__are_equal(const hellocm_msgs__msg__IMUOut * lhs, const hellocm_msgs__msg__IMUOut * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // time
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->time), &(rhs->time)))
  {
    return false;
  }
  // cycleno
  if (lhs->cycleno != rhs->cycleno) {
    return false;
  }
  // synthdelay
  if (lhs->synthdelay != rhs->synthdelay) {
    return false;
  }
  // vx
  if (lhs->vx != rhs->vx) {
    return false;
  }
  // vy
  if (lhs->vy != rhs->vy) {
    return false;
  }
  // vz
  if (lhs->vz != rhs->vz) {
    return false;
  }
  // roll_rate
  if (lhs->roll_rate != rhs->roll_rate) {
    return false;
  }
  // pitch_rate
  if (lhs->pitch_rate != rhs->pitch_rate) {
    return false;
  }
  // yaw_rate
  if (lhs->yaw_rate != rhs->yaw_rate) {
    return false;
  }
  // ax
  if (lhs->ax != rhs->ax) {
    return false;
  }
  // ay
  if (lhs->ay != rhs->ay) {
    return false;
  }
  // az
  if (lhs->az != rhs->az) {
    return false;
  }
  // roll_acc
  if (lhs->roll_acc != rhs->roll_acc) {
    return false;
  }
  // pitch_acc
  if (lhs->pitch_acc != rhs->pitch_acc) {
    return false;
  }
  // yaw_acc
  if (lhs->yaw_acc != rhs->yaw_acc) {
    return false;
  }
  return true;
}

bool
hellocm_msgs__msg__IMUOut__copy(
  const hellocm_msgs__msg__IMUOut * input,
  hellocm_msgs__msg__IMUOut * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // time
  if (!builtin_interfaces__msg__Time__copy(
      &(input->time), &(output->time)))
  {
    return false;
  }
  // cycleno
  output->cycleno = input->cycleno;
  // synthdelay
  output->synthdelay = input->synthdelay;
  // vx
  output->vx = input->vx;
  // vy
  output->vy = input->vy;
  // vz
  output->vz = input->vz;
  // roll_rate
  output->roll_rate = input->roll_rate;
  // pitch_rate
  output->pitch_rate = input->pitch_rate;
  // yaw_rate
  output->yaw_rate = input->yaw_rate;
  // ax
  output->ax = input->ax;
  // ay
  output->ay = input->ay;
  // az
  output->az = input->az;
  // roll_acc
  output->roll_acc = input->roll_acc;
  // pitch_acc
  output->pitch_acc = input->pitch_acc;
  // yaw_acc
  output->yaw_acc = input->yaw_acc;
  return true;
}

hellocm_msgs__msg__IMUOut *
hellocm_msgs__msg__IMUOut__create()
{
  hellocm_msgs__msg__IMUOut * msg = (hellocm_msgs__msg__IMUOut *)malloc(sizeof(hellocm_msgs__msg__IMUOut));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hellocm_msgs__msg__IMUOut));
  bool success = hellocm_msgs__msg__IMUOut__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
hellocm_msgs__msg__IMUOut__destroy(hellocm_msgs__msg__IMUOut * msg)
{
  if (msg) {
    hellocm_msgs__msg__IMUOut__fini(msg);
  }
  free(msg);
}


bool
hellocm_msgs__msg__IMUOut__Sequence__init(hellocm_msgs__msg__IMUOut__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  hellocm_msgs__msg__IMUOut * data = NULL;
  if (size) {
    data = (hellocm_msgs__msg__IMUOut *)calloc(size, sizeof(hellocm_msgs__msg__IMUOut));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hellocm_msgs__msg__IMUOut__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hellocm_msgs__msg__IMUOut__fini(&data[i - 1]);
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
hellocm_msgs__msg__IMUOut__Sequence__fini(hellocm_msgs__msg__IMUOut__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hellocm_msgs__msg__IMUOut__fini(&array->data[i]);
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

hellocm_msgs__msg__IMUOut__Sequence *
hellocm_msgs__msg__IMUOut__Sequence__create(size_t size)
{
  hellocm_msgs__msg__IMUOut__Sequence * array = (hellocm_msgs__msg__IMUOut__Sequence *)malloc(sizeof(hellocm_msgs__msg__IMUOut__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = hellocm_msgs__msg__IMUOut__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
hellocm_msgs__msg__IMUOut__Sequence__destroy(hellocm_msgs__msg__IMUOut__Sequence * array)
{
  if (array) {
    hellocm_msgs__msg__IMUOut__Sequence__fini(array);
  }
  free(array);
}

bool
hellocm_msgs__msg__IMUOut__Sequence__are_equal(const hellocm_msgs__msg__IMUOut__Sequence * lhs, const hellocm_msgs__msg__IMUOut__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hellocm_msgs__msg__IMUOut__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hellocm_msgs__msg__IMUOut__Sequence__copy(
  const hellocm_msgs__msg__IMUOut__Sequence * input,
  hellocm_msgs__msg__IMUOut__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hellocm_msgs__msg__IMUOut);
    hellocm_msgs__msg__IMUOut * data =
      (hellocm_msgs__msg__IMUOut *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hellocm_msgs__msg__IMUOut__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          hellocm_msgs__msg__IMUOut__fini(&data[i]);
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
    if (!hellocm_msgs__msg__IMUOut__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
