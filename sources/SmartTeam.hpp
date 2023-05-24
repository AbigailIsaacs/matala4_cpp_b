#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <vector>
#include "Team.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"


namespace ariel{
    class SmartTeam : public Team {
        public:
            
            SmartTeam(Character* newcaracter);
            void attack(Team *Team_b);
            void print();

            

            
            
    };
   
    
        




}