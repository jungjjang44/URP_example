cmake_minimum_required(VERSION 3.5)
project(hellocm_cmnode)

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

set(CARMAKER_VER 9.1.1)
set(CARMAKER_NUMVER 90101)

set(CARMAKER_DIR $ENV{IPGHOME}/carmaker/linux64-${CARMAKER_VER})
set(CARMAKER_INC_DIR ${CARMAKER_DIR}/include)
set(CMAKE_POSITION_INDEPENDENT_CODE_ON)

add_definitions(-DCM_NUMVER=${CARMAKER_NUMVER})

###   CarMaker ROS Node specific   ###
set(CMNODE_BUILD_NAME CMNode_ROS1_HelloCM)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosgraph_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(cmrosutils REQUIRED)
find_package(hellocm REQUIRED)
find_package(hellocm_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(Boost REQUIRED
  system 
  thread 
  program_options
)

include_directories(
	include ${CARMAKER_INC_DIR}
	include "/opt/ipg/carmaker/linux64-9.1.1/include"
	
	include ${rclcpp_INCLUDE_DIRS}
	include ${std_msgs_INCLUDE_DIRS}
	include ${rosgraph_msgs_INCLUDE_DIRS}
	include ${cmrosutils_INCLUDE_DIRS}
	include ${hellocm_INCLUDE_DIRS}
	include ${hellocm_msgs_INCLUDE_DIRS}
	include ${tf2_INCLUDE_DIRS}
	include ${tf2_ros_INCLUDE_DIRS}
	include ${tf2_geometry_msgs_INCLUDE_DIRS}
	include ${sensor_msgs_INCLUDE_DIRS}
	include ${visualization_msgs_INCLUDE_DIRS}
	include ${nav_msgs_INCLUDE_DIRS}
)

add_library(
	${CMNODE_BUILD_NAME} SHARED src/${CMNODE_BUILD_NAME}.cpp
)

target_link_libraries(${CMNODE_BUILD_NAME}
  ${Boost_LIBRARIES}
)

ament_target_dependencies(
	${CMNODE_BUILD_NAME}
	
	rclcpp
	std_msgs
	rosgraph_msgs
	cmrosutils
	hellocm
	hellocm_msgs
	tf2
	tf2_ros
	tf2_geometry_msgs
	sensor_msgs
	visualization_msgs
	nav_msgs
	Boost
)

install(TARGETS ${CMNODE_BUILD_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION include
)

install(DIRECTORY meshes
  DESTINATION share/${PROJECT_NAME}
)

ament_export_include_directories(include)

##------------------------------------------------------------------------------------------
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
