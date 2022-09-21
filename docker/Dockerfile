FROM osrf/ros:foxy-desktop

RUN echo "Building the image for SCARA robot demo"

RUN mkdir -p /home/ros2_ws/src && cd /home/ros2_ws/src && \
    sudo apt-get update && sudo apt-get upgrade -y
RUN sudo apt-get install -y libpoco-dev xterm gdb libasio-dev libtinyxml2-dev wget
	
RUN sudo apt-get update && sudo apt-get install ros-foxy-control-msgs \
    ros-foxy-rqt-graph \
    ros-foxy-ros2-control \
    ros-foxy-ros2-controllers \
    ros-foxy-realtime-tools \
    ros-foxy-xacro \
    ros-foxy-joint-state-publisher-gui \
    iputils-ping -y

RUN git clone -b foxy-devel  https://github.com/PickNikRobotics/rviz_visual_tools.git /home/ros2_ws/src/rviz_visual_tools

RUN cd /home/ros2_ws && rosdep update && rosdep install -r --from-paths src --ignore-src --rosdistro foxy -y

RUN echo 'source /home/ros2_ws/install/setup.bash' >> ~/.bashrc
RUN echo 'export HISTSIZE=10000' >> ~/.bashrc 
RUN echo 'export HISTFILESIZE=10000' >> ~/.bashrc 

RUN apt-get update && rm -rf /var/lib/apt/lists/* && \
    apt-get clean 
    
RUN . /opt/ros/$ROS_DISTRO/setup.sh && \
    cd /home/ros2_ws && \
    colcon build

ADD startup.sh /startup.sh
RUN chmod +x /startup.sh
ENTRYPOINT ["/startup.sh"]
CMD ["/bin/bash"]

