#
# Message from CarMaker ROS Node to external ROS Node
#

# General
std_msgs/Header header                         # General ROS Header (optional)
builtin_interfaces/Time time                   # ROS time when message was sent (optional)
int64   cycleno                                # Cycle number since simulation start (optional)
float64 synthdelay                             # Synthetic delay to check synchronization (optional)

float64 latitude                               # Latitude [degrees]
float64 longitude                              # Longitude [degrees]
float64 altitude                               # Altitude [m]
