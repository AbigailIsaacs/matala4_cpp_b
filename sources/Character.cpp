#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "Character.hpp"

using namespace std ;
namespace ariel{

    Character::Character (std::string _name, Point _point, int _hit_points):name(_name) , point(_point), hit_points(_hit_points){
    
    }
    bool Character::isAlive(){
        if(hit_points==0){
            return false;
        }
        return true;
    }

    double Character::distance (Character *outher){
       
        return this->point.distance(outher->point);
    }

    void Character::hit (int num_points){
        if(num_points<0){
            throw invalid_argument("Num_points mast be positive");
        }
        if((hit_points- num_points)<0){
            hit_points=0;
        }
        else{
            hit_points = hit_points-num_points;
        }
    }

    std::string Character::getName(){
        return name;
    }
    Point Character::getLocation(){
        return point;
    }
    int Character::get_hit_points(){
        return hit_points;
    }

    bool Character::get_isPlaying(){
        return isPlaying ;
    }  
    void Character::set_isPlaying(bool b){
        isPlaying = b;
    }

    void Character::setLocation(Point p){
        point = p;
    }

}