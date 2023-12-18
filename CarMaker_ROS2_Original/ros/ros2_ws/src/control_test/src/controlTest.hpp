#ifndef _CONTROL_TEST_HPP
#define _CONTROL_TEST_HPP

#include <functional>
#include <iostream>
#include <fstream>
#include <memory>
#include <array>
#include <vector>
#include <cmath>
#include "utils.hpp"

using namespace std;

// 종 제어
class cruiseControl
{
    public:
        cruiseControl(){

        }

        float gain = 1.0;

        float accControl(float currentSpd, float targetSpd)
        {   
            return (targetSpd - currentSpd) * this->gain;
        }

};

// 일단은 글로벌 경로 추종, 추후 로컬 경로로 변경할 예정
float PurePursuit(vector<double> refPath_x, vector<double> refPath_y, float currentSpd, float ego_x, float ego_y, float ego_head)
{
    double min_dist = 100000.0;
    int min_idx = 0;
    float Lp = K * currentSpd;
    float Lp_x = ego_x + Lp * cos(ego_head);
    float Lp_y = ego_y + Lp * sin(ego_head);

    vector<double> dis_P2;
    for (int i=0; i<int(refPath_x.size()); i++)
    {
        double dist = sqrt(pow(refPath_x[i] - Lp_x, 2) + pow(refPath_y[i] - Lp_y, 2));
        dis_P2.push_back(dist);
        if (dist < min_dist){
            min_idx = i;
            min_dist = dist;
        }
    }

    std::cout << "min index : " << min_idx << std::endl;
    float Way_x = refPath_x[min_idx];
    float Way_y = refPath_y[min_idx];
    
    std::cout << "ref x : " << Way_x << " | cur x : " << ego_x << std::endl;
    std::cout << "ref y : " << Way_y << " | cur y : " << ego_y << std::endl;
    
    float x_2 = (Way_x - ego_x) * cos(ego_head) + (Way_y - ego_y) * sin(ego_head);
    float y_2 = (ego_x - Way_x) * sin(ego_head) + (Way_y - ego_y) * cos(ego_head);

    float L_bar = sqrt(pow(x_2,2) + pow(y_2,2));
    //float sin_alpha = y_2 / L_bar;

    //float k = 2 * sin_alpha / L_bar;
    float steer_angle = LW * 2 * y_2 / pow(L_bar, 2);

    return steer_angle;
}

#endif