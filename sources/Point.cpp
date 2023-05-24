#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <cmath>
#include "Point.hpp"
using namespace std;
namespace ariel
{

    Point::Point(double _x_cord, double _y_cord)
    {
        x_cord = _x_cord;
        y_cord = _y_cord;
    }
    double Point::distance(const Point &p)
    {   
        double distance = std::sqrt(std::pow(this->x_cord - p.x_cord, 2) + std::pow(this->y_cord - p.y_cord, 2));
        return distance;
    }

    std::string Point::print()
    {
        return "(" + to_string(x_cord) + "," + to_string(y_cord) + ")";
    }
    Point Point::moveTowards(Point p1, Point p2, double distance)
    {
        if(distance<0){
            throw invalid_argument("Distanceby must be positive");
        }

        double current_dis = p1.distance(p2);
        if (current_dis <= distance)
        {
            return p2;
        }
        else
        {
            double ratio = distance / current_dis;
            double newX = p1.x_cord + (p2.x_cord - p1.x_cord) * ratio;
            double newY = p1.y_cord + (p2.y_cord - p1.y_cord) * ratio;
            return Point (newX, newY);
        }
    }
    double Point::get_x()
    {
        return x_cord;
    }
    double Point::get_y()
    {
        return y_cord;
    }

    bool operator==(const Point &p1, const Point &p2)
    {
        if (p1.x_cord != p2.x_cord)
        {
            return false;
        }
        if (p1.y_cord != p2.y_cord)
        {
            return false;
        }
        return true;
    }
    void Point::set_point(Point p){
        x_cord = p.get_x();
        y_cord = p.get_y();
    }
}