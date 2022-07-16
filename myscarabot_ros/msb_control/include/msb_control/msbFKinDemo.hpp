#include <ctime>
#include <chrono>
#include <cstdio>
#include <memory>
#include <fstream>
#include <iostream>

#include "rclcpp/rclcpp.hpp"

class MyScaraBotForwardKinematicsNode : public rclcpp::Node {

public:
    MyScaraBotForwardKinematicsNode();
    void timer_callback();

private:
    rclcpp::TimerBase::SharedPtr timer_;
    int                          count_;
};

