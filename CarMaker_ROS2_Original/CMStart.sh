# !/bin/bash

# Processes called inside CM GUI will inherit environment variables!
# - Ensure ros workspace is already built!
source ros_setup.bash
#source /opt/ros/eloquent/setup.bash

CM-9.1.1 . -apphost localhost -ext GUI/CMExt-CMRosIF.mod
