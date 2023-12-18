// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from hellocm_msgs:msg/IMUOut.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__IMU_OUT__FUNCTIONS_H_
#define HELLOCM_MSGS__MSG__DETAIL__IMU_OUT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "hellocm_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "hellocm_msgs/msg/detail/imu_out__struct.h"

/// Initialize msg/IMUOut message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hellocm_msgs__msg__IMUOut
 * )) before or use
 * hellocm_msgs__msg__IMUOut__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
bool
hellocm_msgs__msg__IMUOut__init(hellocm_msgs__msg__IMUOut * msg);

/// Finalize msg/IMUOut message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
void
hellocm_msgs__msg__IMUOut__fini(hellocm_msgs__msg__IMUOut * msg);

/// Create msg/IMUOut message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hellocm_msgs__msg__IMUOut__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
hellocm_msgs__msg__IMUOut *
hellocm_msgs__msg__IMUOut__create();

/// Destroy msg/IMUOut message.
/**
 * It calls
 * hellocm_msgs__msg__IMUOut__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
void
hellocm_msgs__msg__IMUOut__destroy(hellocm_msgs__msg__IMUOut * msg);

/// Check for msg/IMUOut message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
bool
hellocm_msgs__msg__IMUOut__are_equal(const hellocm_msgs__msg__IMUOut * lhs, const hellocm_msgs__msg__IMUOut * rhs);

/// Copy a msg/IMUOut message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
bool
hellocm_msgs__msg__IMUOut__copy(
  const hellocm_msgs__msg__IMUOut * input,
  hellocm_msgs__msg__IMUOut * output);

/// Initialize array of msg/IMUOut messages.
/**
 * It allocates the memory for the number of elements and calls
 * hellocm_msgs__msg__IMUOut__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
bool
hellocm_msgs__msg__IMUOut__Sequence__init(hellocm_msgs__msg__IMUOut__Sequence * array, size_t size);

/// Finalize array of msg/IMUOut messages.
/**
 * It calls
 * hellocm_msgs__msg__IMUOut__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
void
hellocm_msgs__msg__IMUOut__Sequence__fini(hellocm_msgs__msg__IMUOut__Sequence * array);

/// Create array of msg/IMUOut messages.
/**
 * It allocates the memory for the array and calls
 * hellocm_msgs__msg__IMUOut__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
hellocm_msgs__msg__IMUOut__Sequence *
hellocm_msgs__msg__IMUOut__Sequence__create(size_t size);

/// Destroy array of msg/IMUOut messages.
/**
 * It calls
 * hellocm_msgs__msg__IMUOut__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
void
hellocm_msgs__msg__IMUOut__Sequence__destroy(hellocm_msgs__msg__IMUOut__Sequence * array);

/// Check for msg/IMUOut message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
bool
hellocm_msgs__msg__IMUOut__Sequence__are_equal(const hellocm_msgs__msg__IMUOut__Sequence * lhs, const hellocm_msgs__msg__IMUOut__Sequence * rhs);

/// Copy an array of msg/IMUOut messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
bool
hellocm_msgs__msg__IMUOut__Sequence__copy(
  const hellocm_msgs__msg__IMUOut__Sequence * input,
  hellocm_msgs__msg__IMUOut__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // HELLOCM_MSGS__MSG__DETAIL__IMU_OUT__FUNCTIONS_H_
