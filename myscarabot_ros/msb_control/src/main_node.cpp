#include "rclcpp/rclcpp.hpp"
#include "msb_control/msbFKinDemo.hpp"

int main(int argc, char* argv[]) {

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MyScaraBotForwardKinematicsNode>());
    rclcpp::shutdown();
}