#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>

#include "Point.hpp"
#include "Character.hpp"


namespace ariel{
    class Cowboy : public Character {
        private:
            int num_bullets;

        public:
            Cowboy(std::string _name ,Point _p);
            void shoot(Character *enemy);
            bool hasboolets();
            void reload();
            int get_num_bullets();
            
            std::string print(); 

            ~Cowboy() = default;
    };
   
    
        




}