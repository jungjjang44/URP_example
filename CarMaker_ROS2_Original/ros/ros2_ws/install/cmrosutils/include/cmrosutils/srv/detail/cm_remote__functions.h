// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cmrosutils:srv/CMRemote.idl
// generated code does not contain a copyright notice

#ifndef CMROSUTILS__SRV__DETAIL__CM_REMOTE__FUNCTIONS_H_
#define CMROSUTILS__SRV__DETAIL__CM_REMOTE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cmrosutils/msg/rosidl_generator_c__visibility_control.h"

#include "cmrosutils/srv/detail/cm_remote__struct.h"

/// Initialize srv/CMRemote message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cmrosutils__srv__CMRemote_Request
 * )) before or use
 * cmrosutils__srv__CMRemote_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
bool
cmrosutils__srv__CMRemote_Request__init(cmrosutils__srv__CMRemote_Request * msg);

/// Finalize srv/CMRemote message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
void
cmrosutils__srv__CMRemote_Request__fini(cmrosutils__srv__CMRemote_Request * msg);

/// Create srv/CMRemote message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cmrosutils__srv__CMRemote_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
cmrosutils__srv__CMRemote_Request *
cmrosutils__srv__CMRemote_Request__create();

/// Destroy srv/CMRemote message.
/**
 * It calls
 * cmrosutils__srv__CMRemote_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
void
cmrosutils__srv__CMRemote_Request__destroy(cmrosutils__srv__CMRemote_Request * msg);

/// Check for srv/CMRemote message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
bool
cmrosutils__srv__CMRemote_Request__are_equal(const cmrosutils__srv__CMRemote_Request * lhs, const cmrosutils__srv__CMRemote_Request * rhs);

/// Copy a srv/CMRemote message.
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
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
bool
cmrosutils__srv__CMRemote_Request__copy(
  const cmrosutils__srv__CMRemote_Request * input,
  cmrosutils__srv__CMRemote_Request * output);

/// Initialize array of srv/CMRemote messages.
/**
 * It allocates the memory for the number of elements and calls
 * cmrosutils__srv__CMRemote_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
bool
cmrosutils__srv__CMRemote_Request__Sequence__init(cmrosutils__srv__CMRemote_Request__Sequence * array, size_t size);

/// Finalize array of srv/CMRemote messages.
/**
 * It calls
 * cmrosutils__srv__CMRemote_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
void
cmrosutils__srv__CMRemote_Request__Sequence__fini(cmrosutils__srv__CMRemote_Request__Sequence * array);

/// Create array of srv/CMRemote messages.
/**
 * It allocates the memory for the array and calls
 * cmrosutils__srv__CMRemote_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
cmrosutils__srv__CMRemote_Request__Sequence *
cmrosutils__srv__CMRemote_Request__Sequence__create(size_t size);

/// Destroy array of srv/CMRemote messages.
/**
 * It calls
 * cmrosutils__srv__CMRemote_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
void
cmrosutils__srv__CMRemote_Request__Sequence__destroy(cmrosutils__srv__CMRemote_Request__Sequence * array);

/// Check for srv/CMRemote message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
bool
cmrosutils__srv__CMRemote_Request__Sequence__are_equal(const cmrosutils__srv__CMRemote_Request__Sequence * lhs, const cmrosutils__srv__CMRemote_Request__Sequence * rhs);

/// Copy an array of srv/CMRemote messages.
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
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
bool
cmrosutils__srv__CMRemote_Request__Sequence__copy(
  const cmrosutils__srv__CMRemote_Request__Sequence * input,
  cmrosutils__srv__CMRemote_Request__Sequence * output);

/// Initialize srv/CMRemote message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cmrosutils__srv__CMRemote_Response
 * )) before or use
 * cmrosutils__srv__CMRemote_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
bool
cmrosutils__srv__CMRemote_Response__init(cmrosutils__srv__CMRemote_Response * msg);

/// Finalize srv/CMRemote message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
void
cmrosutils__srv__CMRemote_Response__fini(cmrosutils__srv__CMRemote_Response * msg);

/// Create srv/CMRemote message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cmrosutils__srv__CMRemote_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
cmrosutils__srv__CMRemote_Response *
cmrosutils__srv__CMRemote_Response__create();

/// Destroy srv/CMRemote message.
/**
 * It calls
 * cmrosutils__srv__CMRemote_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
void
cmrosutils__srv__CMRemote_Response__destroy(cmrosutils__srv__CMRemote_Response * msg);

/// Check for srv/CMRemote message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
bool
cmrosutils__srv__CMRemote_Response__are_equal(const cmrosutils__srv__CMRemote_Response * lhs, const cmrosutils__srv__CMRemote_Response * rhs);

/// Copy a srv/CMRemote message.
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
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
bool
cmrosutils__srv__CMRemote_Response__copy(
  const cmrosutils__srv__CMRemote_Response * input,
  cmrosutils__srv__CMRemote_Response * output);

/// Initialize array of srv/CMRemote messages.
/**
 * It allocates the memory for the number of elements and calls
 * cmrosutils__srv__CMRemote_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
bool
cmrosutils__srv__CMRemote_Response__Sequence__init(cmrosutils__srv__CMRemote_Response__Sequence * array, size_t size);

/// Finalize array of srv/CMRemote messages.
/**
 * It calls
 * cmrosutils__srv__CMRemote_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
void
cmrosutils__srv__CMRemote_Response__Sequence__fini(cmrosutils__srv__CMRemote_Response__Sequence * array);

/// Create array of srv/CMRemote messages.
/**
 * It allocates the memory for the array and calls
 * cmrosutils__srv__CMRemote_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
cmrosutils__srv__CMRemote_Response__Sequence *
cmrosutils__srv__CMRemote_Response__Sequence__create(size_t size);

/// Destroy array of srv/CMRemote messages.
/**
 * It calls
 * cmrosutils__srv__CMRemote_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
void
cmrosutils__srv__CMRemote_Response__Sequence__destroy(cmrosutils__srv__CMRemote_Response__Sequence * array);

/// Check for srv/CMRemote message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
bool
cmrosutils__srv__CMRemote_Response__Sequence__are_equal(const cmrosutils__srv__CMRemote_Response__Sequence * lhs, const cmrosutils__srv__CMRemote_Response__Sequence * rhs);

/// Copy an array of srv/CMRemote messages.
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
ROSIDL_GENERATOR_C_PUBLIC_cmrosutils
bool
cmrosutils__srv__CMRemote_Response__Sequence__copy(
  const cmrosutils__srv__CMRemote_Response__Sequence * input,
  cmrosutils__srv__CMRemote_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CMROSUTILS__SRV__DETAIL__CM_REMOTE__FUNCTIONS_H_
