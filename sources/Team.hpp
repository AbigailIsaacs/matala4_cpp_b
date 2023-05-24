#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <vector>

#include "Cowboy.hpp"
#include "Point.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"


namespace ariel{
    class Team{
        private:
            std::vector<Character*> characters;
            int size_vector;
            Character* leader;
        public:
            Team(Character* newcaracter);
            void add(Character* newcaracter);
            void attack(Team *Team_b);
            int stillAlive();
            virtual void print();
            Character* get_leader();
            void set_leader(Character* new_leader);
            std::vector<Character*> get_characters();            
            
            Character* fined_closest_to(Character* org, Team team);

            // Clean up memory
            virtual ~Team();
            
    };
   
    
        




}