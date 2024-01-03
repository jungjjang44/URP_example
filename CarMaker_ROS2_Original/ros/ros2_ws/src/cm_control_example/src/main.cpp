#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "json/json.h"


#define MODE 2 // , MODE 2 : Route 따라서 가는 모드, MODE 3 : 데이터 저장 JSON
/**
 * MODE 1 : 자율주행 모드
 * MODE 2 : ROUTE FOLLOWING
 * MODE 3 : ROUTE JSON으로 저장
*/

using std::placeholders::_1;
using namespace std;

rclcpp::Clock clk;

std::ofstream output_file("map/road.json");
Json::Value root;
Json::Value record;
Json::StyledWriter writer;

// 전역 경로 저장
std::vector<double> reference_x = {};
std::vector<double> reference_y = {};

void map_parser()
{
    if (MODE == 1 || MODE == 2) {
        
        std::ifstream ist("map/example_road.json");
        std::string str;
        for (char p; ist >> p;) str += p;

        Json::Reader reader;
        Json::Value map_global;
        Json::Value _x;
        Json::Value _y;
        
        bool parsingNet = reader.parse(str, map_global);
        if (!parsingNet) std::cout << "Parsing Failed" << std::endl;
        _x = map_global["x"];
        _y = map_global["y"];
        
        for (unsigned int i=0; i<_x.size(); i++) {
            reference_x.push_back(_x[i].asDouble());
            reference_y.push_back(_y[i].asDouble());   
        }
    }
}

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
        if (MODE == 3) {
            double x = msg->data[15];
            double y = msg->data[16];
            
            root["x"].append(x);
            root["y"].append(y);

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        ///////////////////////////// USER /////////////////////////////



        ////////////////////////////////////////////////////////////////
    }

    void timer_callback()
    {
        auto msg_CM = std_msgs::msg::Float64MultiArray();

        if (MODE == 1) {
            
            ///////////////////////////// USER /////////////////////////////

            double steer_input = 0.1;
            double acc_input = 0.5;
            // 제어기 설계해주세요

            // 전역 경로는 reference_x, reference_y(벡터)로 담겨 있습니다.


            ////////////////////////////////////////////////////////////////

            msg_CM.data = {3, steer_input, acc_input, 3, 1};
            std::cout << "steer input : " << steer_input << std::endl;
            std::cout << "acc_input : " << acc_input << std::endl;
        } else if (MODE == 2) {
            std::cout << "CarMaker Route Following" << std::endl;
            std::cout << "x size : " << reference_x.size() << std::endl;
            std::cout << "y size : " << reference_y.size() << std::endl;
            msg_CM.data = {0, 0, 0, 0, 0};
        } else {
            std::cout << "JSON WRITING..." << std::endl;
            msg_CM.data = {0, 0, 0, 0, 0};
        }
        this->controlPublisher->publish(msg_CM);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr controlPublisher;
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr vehicleInfoSubscriber;

};

int main(int argc, char * argv[])
{
    map_parser();
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<cm_control_example>());
    rclcpp::shutdown();

    // Json Write
    std::string out = writer.write(root);
    output_file << out;
    output_file.close();
    return 0;
}