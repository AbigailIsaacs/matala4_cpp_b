#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "SmartTeam.hpp"
using namespace std ;

namespace ariel{
    SmartTeam::SmartTeam(Character* newcaracter):Team(newcaracter){}
    void SmartTeam::attack(Team *Team_b){



        
    }

    void SmartTeam::print(){
        for(Character* c : get_characters()){
            cout<< c->print()<<endl;
        }
    }

}
