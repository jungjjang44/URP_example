cmake_minimum_required(VERSION 3.5)
project(hellocm_msgs)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(std_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(ament_cmake REQUIRED)
# find_package(rosidl_generate_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/CM2Ext.msg"
  "msg/Ext2CM.msg"
  "msg/GPSOut.msg"
  "msg/IMUOut.msg"
  "msg/ObjectInfoOut.msg"
  "msg/SignalLightIn.msg"
  "msg/SpeedLimit.msg"
  "msg/VehicleControlIn.msg"
  "msg/VehicleInfoOut.msg"
  "srv/Init.srv"
  DEPENDENCIES builtin_interfaces std_msgs
  ADD_LINTER_TESTS
)

ament_export_dependencies(
  std_msgs
  builtin_interfaces
  rosidl_default_runtime
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION include/${PROJECT_NAME}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
