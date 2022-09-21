#include "msb_control/msbFKinDemo.hpp"

using namespace std::chrono_literals;

MyScaraBotForwardKinematicsNode::MyScaraBotForwardKinematicsNode() : Node("msb_fk_control") {
    RCLCPP_INFO(this->get_logger(), "Hello, from forward kinematics node.");
    timer_ = this->create_wall_timer(1s, std::bind(&MyScaraBotForwardKinematicsNode::timer_callback, this));
}

void MyScaraBotForwardKinematicsNode::timer_callback() {
    RCLCPP_INFO(this->get_logger(), "Hello, this is from the timer.");
}