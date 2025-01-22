#include "rclcpp/rclcpp.hpp"
#include "msb_control/fkin_server.hpp"

MsbFKinServer::MsbFKinServer() : Node("fkin_server")
{
    m_server = this->create_service<msb_interfaces::srv::ForwardKinematics>(
        "fkin", std::bind(&MsbFKinServer::ComputeEndEffectorPose, this, std::placeholders::_1, std::placeholders::_2));
    RCLCPP_INFO(this->get_logger(), "Successfully started the node : %s", this->get_name());
}

void MsbFKinServer::ComputeEndEffectorPose(
    const std::shared_ptr<msb_interfaces::srv::ForwardKinematics::Request> request, 
    std::shared_ptr<msb_interfaces::srv::ForwardKinematics::Response> response)
{
    /* Dummy response for now */
    response->success = true;
    RCLCPP_INFO(this->get_logger(), "Returned dummy response from fkin.");
}

/**
 * @brief Main entry point
 */
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MsbFKinServer>());
    rclcpp::shutdown();
    return 0;
}
