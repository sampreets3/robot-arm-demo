import os

from ament_index_python.packages import get_package_share_directory
import xacro
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration, PythonExpression, Command
from launch_ros.actions import Node

def generate_launch_description():
    # Get the launch directory
    bringup_dir = get_package_share_directory('msb_description')
    launch_dir = os.path.join(bringup_dir, 'launch')
    rviz_config = os.path.join(bringup_dir, 'rviz', 'config.rviz')
    urdf_file 	= os.path.join(bringup_dir, 'urdf', 'scarabot.urdf')
    xacro_file = os.path.join(bringup_dir, 'xacro', 'scarabot.xacro') 
    controllers_file = os.path.join(get_package_share_directory('msb_control'), 'controllers', 'myscarabot_controllers.yaml')
    robot_description = {'robot_description' : Command(['xacro',' ', xacro_file ])}

    start_robot_state_publisher_cmd = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        #parameters=[{'use_sim_time': use_sim_time}],
        # arguments=[urdf_file]
        parameters=[robot_description],
        )
    
    start_joint_state_publisher_cmd = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui',
        output='screen',
        arguments=[urdf_file])
    
    rviz_cmd = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_config],
        output='screen')

    controller_manager = Node(
        package="controller_manager", 
        executable="ros2_control_node", 
        parameters=[robot_description, controllers_file], 
        output='screen'
    )

    # Create the launch description and populate
    ld = LaunchDescription()

    # Add any conditioned actions
    ld.add_action(start_joint_state_publisher_cmd)
    ld.add_action(start_robot_state_publisher_cmd)
    ld.add_action(rviz_cmd)
    ld.add_action(controller_manager)

    return ld
