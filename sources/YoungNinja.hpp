#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel{
    class YoungNinja : public Ninja{
    
        public:
            
            YoungNinja(std::string _name ,Point _point);
            int get_speed();
            ~YoungNinja() = default;


    };
}