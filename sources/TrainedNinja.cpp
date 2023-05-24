#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "TrainedNinja.hpp"
using namespace std ;
namespace ariel{

    TrainedNinja::TrainedNinja(std::string _name ,Point _point) : Ninja(_name ,_point,120,12){}
    int TrainedNinja::get_speed(){
        return 12;
    }

}