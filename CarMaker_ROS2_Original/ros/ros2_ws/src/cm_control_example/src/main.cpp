#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"


using std::placeholders::_1;
using namespace std;

rclcpp::Clock clk;

class cm_control_example : public rclcpp::Node
{
    public:

    cm_control_example()
    : Node("cm_control_example")
    {
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(1));

        controlPublisher = this->create_publisher<std_msgs::msg::Float64MultiArray> ("control/vehicle_control", qos_profile);
        vehicleInfoSubscriber = this->create_subscription<std_msgs::msg::Float64MultiArray>
        ("/carmaker/vehicle_info_out2", 20, std::bind(&cm_control_example::vehicleInfoCallback, this, _1));
        timer_ = this->create_wall_timer(10ms, std::bind(&cm_control_example::timer_callback, this));
    }

    void vehicleInfoCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg)
    {

    }

    void timer_callback()
    {
        auto msg_CM = std_msgs::msg::Float64MultiArray();
        double steer_input = 0.1;
        double acc_input = 0.5;
        msg_CM.data = {1, steer_input, acc_input, 3, 1};
        this->controlPublisher->publish(msg_CM);
        std::cout << "steer input : " << steer_input << std::endl;
        std::cout << "acc_input : " << acc_input << std::endl;
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr controlPublisher;
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr vehicleInfoSubscriber;

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<cm_control_example>());
    rclcpp::shutdown();

    return 0;
}