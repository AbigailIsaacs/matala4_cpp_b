#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <stdio.h>
#include "Ninja.hpp"
using namespace std ;
namespace ariel{
    Ninja::Ninja(std::string _name ,Point _point, int _hit_points,int _speed) : Character(_name ,_point,_hit_points), speed(_speed){}
    
    void Ninja::move(Character* enemy){
        
        Point p = Point::moveTowards(this->getLocation(),enemy->getLocation(),this->get_speed());
        this->setLocation(p);
    }
    
    void Ninja::slash(Character* enemy){
        
        if(this->isAlive()==false) {
            throw runtime_error("Attacer is already dead");
        }
        if(enemy->isAlive()==false){
             throw runtime_error("Enemy is already dead");
        }
        if(this==enemy){
            throw runtime_error("No self harm");
        }
     
        if(this->isAlive()){
            if((this->distance(enemy))<1){
                enemy->hit(40);
            }
        }
        
    } 

    std::string Ninja::print(){
        std::string s ;
        if(this->isAlive()){
            s = "name: " + this->getName() +" hit points: "+ to_string(this->get_hit_points()) + " point at: " + this->getLocation().print();
        }
        else{
            s = "name: N(" + this->getName() + ") point at: "+ this->getLocation().print();
        }
        return s;
    }

}