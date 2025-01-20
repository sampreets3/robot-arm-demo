#include <ctime>
#include <chrono>
#include <cstdio>
#include <memory>
#include <fstream>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

class MyScaraBotForwardKinematicsNode : public rclcpp::Node {

public:
    MyScaraBotForwardKinematicsNode();

private:
    rclcpp::TimerBase::SharedPtr timer_;
    int                          count_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr m_jointStateSub;

    void timer_callback();
    void SubCb(const sensor_msgs::msg::JointState &msg);
};

