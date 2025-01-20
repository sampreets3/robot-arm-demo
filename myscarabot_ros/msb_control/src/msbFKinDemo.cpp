#include "msb_control/msbFKinDemo.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

using namespace std::chrono_literals;

MyScaraBotForwardKinematicsNode::MyScaraBotForwardKinematicsNode() : Node("msb_fk_control") {
    RCLCPP_INFO(this->get_logger(), "Hello, from forward kinematics node.");
    timer_ = this->create_wall_timer(1s, std::bind(&MyScaraBotForwardKinematicsNode::timer_callback, this));

    m_jointStateSub = this->create_subscription<sensor_msgs::msg::JointState>("/joint_states", 10, std::bind(&MyScaraBotForwardKinematicsNode::SubCb, this, std::placeholders::_1));
}

void MyScaraBotForwardKinematicsNode::timer_callback() {
    RCLCPP_INFO(this->get_logger(), "Hello, this is from the timer.");
}

void MyScaraBotForwardKinematicsNode::SubCb(const sensor_msgs::msg::JointState &msg)
{
    for (int i = 0; i < msg.name.size(); i++)
    {
        RCLCPP_INFO(this->get_logger(), "Joint: %s   Value : %.3f", msg.name[i].c_str(), msg.position[i]);
    }
    RCLCPP_INFO(this->get_logger(), "---------------------");
}