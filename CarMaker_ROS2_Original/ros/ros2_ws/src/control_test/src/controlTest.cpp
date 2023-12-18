#include <functional>
#include <iostream>
#include <fstream>
#include <memory>
#include <array>
#include <vector>
#include <cmath>

#include "visualization_msgs/msg/marker.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int16_multi_array.hpp"
#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "std_msgs/msg/float64.hpp"
#include "custom_msgs/msg/paths.hpp" // local 경로 publish topic
#include "controlTest.hpp"
#include "utils.hpp"

using std::placeholders::_1;
using namespace std;

rclcpp::Clock clk;

class controlTest : public rclcpp::Node
{
    private:

    public:

    controlTest()
    : Node("ControlTest")
    {
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(1));

        ControlPublisher = this->create_publisher<std_msgs::msg::Float64MultiArray> ("/control/vehicle_control", qos_profile);
        vehicleInfoSubscriber = this->create_subscription<std_msgs::msg::Float64MultiArray> ("/carmaker/vehicle_info_out2", 20, std::bind(&controlTest::vehicleInfoCallback, this, _1));
        lppSubscriber = this->create_subscription<custom_msgs::msg::Paths> ("/lpp/local_path", 20, std::bind(&controlTest::lppCallback, this, _1));
        lppVelSubscriber = this->create_subscription<std_msgs::msg::Float64> ("/lpp/lpp_velocity", 20, std::bind(&controlTest::lppVelCallback, this, _1));
        lpp_rviz_publisher = this->create_publisher<visualization_msgs::msg::Marker> ("/lpp_rviz", qos_profile);
        ego_rviz_publisher = this->create_publisher<visualization_msgs::msg::Marker> ("/ego_pose_rviz", qos_profile);
        timer_ = this->create_wall_timer(10ms, std::bind(&controlTest::timer_callback, this));
    }

    // parameter
    float target_spd = 60 / 3.6; // init;
    float ego_x = 0.0; // init
    float ego_y = 0.0;

    float ego_vx = 0.0;
    float ego_vy = 0.0;
    float ego_v = 0.0;

    float ego_head = 0.0;

    // steering angle
    float steering = 0.0;

    void timer_callback()
    {
        auto msg_CM = std_msgs::msg::Float64MultiArray();

        cruiseControl cc;

        // Cal velocity
        float ego_v = sqrt(pow(this->ego_vx,2) + pow(this->ego_vy,2));
        float acc_CM = cc.accControl(ego_v, this->target_spd);
        float steer_CM = this->steering;
        msg_CM.data = {1, steer_CM, acc_CM, 3, 1};
        //msg_CM.data = {1, 0.0, acc_CM, 3, 1};
        this->ControlPublisher->publish(msg_CM);
        //std::cout << "current acc : " << acc_CM << std::endl;

        // rviz visualization
        visualization_msgs::msg::Marker ego;
        visualization_msgs::msg::Marker rviz_local_path;

        vector<geometry_msgs::msg::Point> ego_box_points;
        geometry_msgs::msg::Point ego_point;

        // Marker
        ego.header.frame_id = "global";
        ego.header.stamp = clk.now();
        ego.ns = "time";
        ego.type = visualization_msgs::msg::Marker::LINE_LIST;
        ego.action = visualization_msgs::msg::Marker::MODIFY;
        ego.id = 0;
        ego.scale.x = 0.1;
        ego.scale.y = 0.1;
        ego.pose.orientation.w = 1.0;
        ego.color.a = 1.0;
        ego.color.r = 0.0;
        ego.color.g = 1.0;
        ego.color.b = 0.0;
        
        vector<POINT> ego_p = get_ego_pose();
        geometry_msgs::msg::Point p;
        for (size_t i=0; i<4; i++) {
            p.x = ego_p[i].x;
            p.y = ego_p[i].y;
            p.z = ego_p[i].z;
            
            ego.points.push_back(p);

            p.x = ego_p[(i+1)%4].x;
            p.y = ego_p[(i+1)%4].y;
            p.z = ego_p[(i+1)%4].z;
            
            ego.points.push_back(p);            

        }

        // Marker Publish
        ego_rviz_publisher->publish(ego);
    }

    void vehicleInfoCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg)
    {
        this->ego_x = msg->data[3];
        this->ego_y = msg->data[4];

        this->ego_vx = msg->data[5];
        this->ego_vy = msg->data[6];
        this->ego_v = sqrt(pow(this->ego_vx,2) + pow(this->ego_vy,2));

        this->ego_head = msg->data[2];
    }

    void lppVelCallback(const std_msgs::msg::Float64::SharedPtr msg)
    {
        this->target_spd = msg->data;
    }

    void lppCallback(const custom_msgs::msg::Paths msg)
    {
        std::cout << "callback" << std::endl;
        vector<double> lpp_x = msg.x; // problem
        vector<double> lpp_y = msg.y;

        for (int i=0; i < lpp_x.size(); i++){
            if (isnan(lpp_x[i]) || isnan(lpp_y[i]) ){
                std::cout << "break!" << std::endl;
                exit(1);
            }
        }


        this->steering = PurePursuit(lpp_x, lpp_y, this->ego_v, this->ego_x, this->ego_y, this->ego_head);

    }
    // 자차 global 좌표 4개의 꼭지점
    vector<POINT> get_ego_pose()
    {
        vector<POINT> ego_pose;
        double _x, _y, _heading;
        POINT ego_lu, ego_ru, ego_ll, ego_rl; 
        POINT ego_lu_p, ego_ru_p, ego_ll_p, ego_rl_p;         
        _x = this->ego_x;
        _y = this->ego_y;
        _heading = this->ego_head;
        
        // left upper
        ego_lu.x = LENGTH * 0.5;
        ego_lu.y = WIDTH * 0.5;

        // left upper
        ego_ru.x = LENGTH * 0.5;
        ego_ru.y = -WIDTH * 0.5;

        // left upper
        ego_ll.x = -LENGTH * 0.5;
        ego_ll.y = WIDTH * 0.5;

        // left upper
        ego_rl.x = -LENGTH * 0.5;
        ego_rl.y = -WIDTH * 0.5;

        // ego_lu_p = rotation_matrix(ego_lu, _heading);
        // ego_ru_p = rotation_matrix(ego_ru, _heading);
        // ego_ll_p = rotation_matrix(ego_ll, _heading);
        // ego_rl_p = rotation_matrix(ego_rl, _heading);
        
        // ego_lu_p.x += ego_x;
        // ego_lu_p.y += ego_y;

        // ego_ru_p.x += ego_x;
        // ego_ru_p.y += ego_y;  

        // ego_ll_p.x += ego_x;
        // ego_ll_p.y += ego_y;

        // ego_rl_p.x += ego_x;
        // ego_rl_p.y += ego_y;        

        ego_pose.push_back(ego_lu);
        ego_pose.push_back(ego_ru);
        ego_pose.push_back(ego_rl);
        ego_pose.push_back(ego_ll);
        
        return ego_pose;
    }


    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr ControlPublisher;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr lpp_rviz_publisher;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr ego_rviz_publisher;
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr vehicleInfoSubscriber;
    rclcpp::Subscription<custom_msgs::msg::Paths>::SharedPtr lppSubscriber;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr lppVelSubscriber;
    
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<controlTest>());
    rclcpp::shutdown();

    return 0;
}