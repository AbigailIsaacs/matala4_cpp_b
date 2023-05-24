#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "YoungNinja.hpp"
using namespace std ;
namespace ariel{
    YoungNinja::YoungNinja(std::string _name ,Point _point) : Ninja(_name ,_point,100,14){}
    int YoungNinja::get_speed(){
        return 14;
    }
}