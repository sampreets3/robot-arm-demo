#ifndef MSB_CONTROL__FKIN_SERVER_HPP_
#define MSB_CONTROL__FKIN_SERVER_HPP_

#include "rclcpp/rclcpp.hpp"

#include "sensor_msgs/msg/joint_state.hpp"
#include "msb_interfaces/srv/forward_kinematics.hpp"

class MsbFKinServer : public rclcpp::Node
{
public:

    /**
     * @brief Constructor
     */
    MsbFKinServer();

private:
    /**
     * @brief Computes the end effector pose for a desired joint state.
     *
     * @param request   The incoming request with the desired joint state.
     * @param response  The end effector pose if solution found, empty if not found. 
     */
    void ComputeEndEffectorPose(
        const std::shared_ptr<msb_interfaces::srv::ForwardKinematics::Request> request,
        std::shared_ptr<msb_interfaces::srv::ForwardKinematics::Response> response);

    rclcpp::Service<msb_interfaces::srv::ForwardKinematics>::SharedPtr m_server;
};

#endif // MSB_CONTROL__FKIN_SERVER_HPP_