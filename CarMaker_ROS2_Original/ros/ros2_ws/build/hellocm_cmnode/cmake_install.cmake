# Install script for directory: /home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/src/hellocm_cmnode

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/install/hellocm_cmnode")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/hellocm_cmnode/libCMNode_ROS1_HelloCM.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/hellocm_cmnode/libCMNode_ROS1_HelloCM.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/hellocm_cmnode/libCMNode_ROS1_HelloCM.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/hellocm_cmnode" TYPE SHARED_LIBRARY FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/libCMNode_ROS1_HelloCM.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/hellocm_cmnode/libCMNode_ROS1_HelloCM.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/hellocm_cmnode/libCMNode_ROS1_HelloCM.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/hellocm_cmnode/libCMNode_ROS1_HelloCM.so"
         OLD_RPATH "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/install/cmrosutils/lib:/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/install/hellocm_msgs/lib:/opt/ros/galactic/lib:/opt/ros/galactic/lib/x86_64-linux-gnu:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/hellocm_cmnode/libCMNode_ROS1_HelloCM.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/src/hellocm_cmnode/include/hellocm_cmnode/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode" TYPE DIRECTORY FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/src/hellocm_cmnode/meshes")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/hellocm_cmnode")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/hellocm_cmnode")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode/environment" TYPE FILE FILES "/opt/ros/galactic/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode/environment" TYPE FILE FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode/environment" TYPE FILE FILES "/opt/ros/galactic/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode/environment" TYPE FILE FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode" TYPE FILE FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode" TYPE FILE FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode" TYPE FILE FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode" TYPE FILE FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode" TYPE FILE FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_index/share/ament_index/resource_index/packages/hellocm_cmnode")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode/cmake" TYPE FILE FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode/cmake" TYPE FILE FILES
    "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_core/hellocm_cmnodeConfig.cmake"
    "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/ament_cmake_core/hellocm_cmnodeConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hellocm_cmnode" TYPE FILE FILES "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/src/hellocm_cmnode/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/amlab/URP_example/CarMaker_ROS2_Original/ros/ros2_ws/build/hellocm_cmnode/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
