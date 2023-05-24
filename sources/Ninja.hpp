#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <string>

#include "Point.hpp"

#include "Character.hpp"


namespace ariel{
    class Ninja : public Character {
        private:
            int speed;
        public:
            Ninja(std::string _name ,Point _point, int _speed, int _hit_points);
            void move(Character* enemy);
            void slash(Character* enemy);
            virtual int get_speed()=0;
            std::string print(); 
            virtual ~Ninja() = default;
            


    };
}