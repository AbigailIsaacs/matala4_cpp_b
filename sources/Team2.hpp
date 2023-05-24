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
    class Team2 : public Team {
        public:
            Team2(Character* newcaracter);
            void attack(Team *Team_b);
            void print();

                  
            
    };
   
    
        




}