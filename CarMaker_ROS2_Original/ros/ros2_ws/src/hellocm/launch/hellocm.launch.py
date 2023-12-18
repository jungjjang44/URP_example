from launch import LaunchDescription
import launch_ros.actions

def generate_launch_description():
    
    return LaunchDescription([
        launch_ros.actions.Node(
            package="hellocm",
            executable="hellocm_node",
            name="hellocm",
            emulate_tty=True,
            output="screen",
            parameters=[
                {"use_sim_time": True}
            ],
            
        ),
        
    ])
