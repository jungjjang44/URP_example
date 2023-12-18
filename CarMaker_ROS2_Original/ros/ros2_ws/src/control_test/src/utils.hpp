#ifndef _UTILS_HPP // 이 문구가 정의되어 있지 않을 시
#define _UTILS_HPP // define 

#include <cmath>
#include <tuple>
#include <vector>
#include <iostream>
#include "eigen3/Eigen/Dense"
#include "eigen3/Eigen/LU"

//Parameter
#define WIDTH 2.4
#define LENGTH 4.28
#define K 0.31
#define LW 2.7 // Wheel base

using namespace std;

typedef vector<double> Point;
typedef vector<double> Pose;

typedef struct point
{
    double x;
    double y;
    double z = 0.0;
    
} POINT;

POINT rotation_matrix(POINT p, double heading)
{
    POINT output;
    output.x = p.x*cos(heading) - p.y*sin(heading);
    output.y = p.x*sin(heading) + p.y*cos(heading);
    output.z = 0;

    return output;

}

// Point = {x, y}
Point _global2local(Point point, Pose ego)
{
    double _x, _y, _head;
    _x = ego[0];
    _y = ego[1];
    _head = ego[2];

    Eigen::Matrix3d rotation_mat;
    Eigen::Matrix3d inv_rotation_mat = rotation_mat.inverse();
    rotation_mat << cos(_head), -sin(_head), _x,
    sin(_head), cos(_head), _y,
    0, 0, 1;

    Eigen::Vector3d global_coord;
    global_coord << point[0], point[1], 1;

    Eigen::Vector3d res = inv_rotation_mat * global_coord;

    Point local_point;
    local_point.at(0) = res[0];
    local_point.at(1) = res[1];
    
    return local_point; 
}


#endif