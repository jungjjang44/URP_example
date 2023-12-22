#
# Message from external ROS Node to CarMaker ROS Node
#

# General
std_msgs/Header  header                                 # General ROS Header (optional)
builtin_interfaces/Time    time                                   # ROS time when message was sent(optional)
int8      sw                                   # Control mode
float64   ax                                   # mps2
float64   steer_ang                            # rad
int8      gear_no                              #
