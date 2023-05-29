#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "Cowboy.hpp"


using namespace std ;

namespace ariel{
    Cowboy::Cowboy(std::string _name ,Point _point) : Character(_name ,_point,110){
        num_bullets =6;
    }
    void Cowboy::shoot(Character *enemy){
        
        if(this->isAlive()==false) {
            throw runtime_error("Attacer is already dead");
        }
        if(enemy->isAlive()==false){
             throw runtime_error("Enemy is already dead");
        }
        if(this==enemy){
            throw runtime_error("No self harm");
        }
        if (this->hasboolets()){
            enemy->hit(10);
            num_bullets = num_bullets -1;
        }
        
    }
    bool Cowboy::hasboolets(){
        if (num_bullets != 0){
            return true;
        }
        return false;
    }
    void Cowboy::reload(){
        if(this->isAlive()== false){
            throw runtime_error("Cowboy is already dead");
            return ;
        }
        num_bullets = 6 ;
        
    }    
    int Cowboy::get_num_bullets(){
        return num_bullets;
    }
    string Cowboy::print(){
        string s ;
        if(this->isAlive()){
            s = "name: " + this->getName() +" hit points: "+ to_string(this->get_hit_points()) + " point at: " + this->getLocation().print();
        }
        else{
            s = "name: C(" + this->getName() + ") point at: "+ this->getLocation().print();
        }
       
        return s;
    }

}