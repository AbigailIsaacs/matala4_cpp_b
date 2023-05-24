#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "OldNinja.hpp"
using namespace std ;
namespace ariel{
    OldNinja::OldNinja(std::string _name ,Point _point) : Ninja(_name ,_point,150,8){}
    int OldNinja::get_speed(){
        return 8;
    }

}