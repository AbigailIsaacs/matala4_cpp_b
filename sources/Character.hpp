#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <string>

#include "Point.hpp"



namespace ariel{
    class Character {
        private:
            Point point;
            int hit_points;
            std::string name;
            bool isPlaying = false;

    
        public:
            Character ( std::string _name, Point _point, int _hit_points);
            bool isAlive();
            double distance (const Character *outher);
            void hit (int num_points);
            std::string getName();
            Point getLocation();
            void setLocation(Point p);
            int get_hit_points();
            bool get_isPlaying();     
            void set_isPlaying(bool b);  
            virtual std::string print()=0; 

            virtual ~Character() = default;
            

            Character(const Character &) = delete;
            Character &operator=(const Character &) = delete;
            Character(Character &&) = delete;
            Character &operator=(Character &&) = delete;
    };
}