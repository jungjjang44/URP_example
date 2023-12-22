#
# Message from CarMaker ROS Node to external ROS Node
#

# General
std_msgs/Header  header                                 # General ROS Header (optional)
builtin_interfaces/Time    time                                   # ROS time when message was sent (optional)
int64   cycleno                                # Cycle number since simulation start (optional)
float64 synthdelay                             # Synthetic delay to check synchronization (optional)

int16 num
float64[50] id
float64[50] x
float64[50] y
float64[50] w
float64[50] h
float64[50] vx
float64[50] vy
float64[50] alpha
float64[50] global_vx
float64[50] global_vy