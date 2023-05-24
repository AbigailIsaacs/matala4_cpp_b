#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>

#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"


namespace ariel{
    class OldNinja : public Ninja {
        public:
        OldNinja(std::string _name ,Point _point);
        int get_speed();

        ~OldNinja() = default;

    };
}