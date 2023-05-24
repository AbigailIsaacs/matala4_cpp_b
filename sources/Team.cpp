#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "Team.hpp"
using namespace std ;

namespace ariel{
            
    Team::Team(Character* newcaracter):leader(newcaracter){
        if(newcaracter->get_isPlaying()==true){
            throw runtime_error("A player cant play in tow teams");
        }
        characters.push_back(newcaracter);
        newcaracter->set_isPlaying(true);
        size_vector =1;
    }

    void Team::set_leader(Character* new_leader){
        leader = new_leader;
    }

    void Team::add(Character* newcaracter){
        
        if(newcaracter->get_isPlaying()){
            throw runtime_error("A player cant play in two teams");
        }
        newcaracter->set_isPlaying(true);
        if(size_vector <10){
            characters.push_back(newcaracter);
            size_vector  = size_vector +1;
        }
        else{
            throw runtime_error("Already 10 players");
        }
    }

    Character* Team::fined_closest_to(Character* org, Team team){
        
        
        bool one_iter = true;
        double min_dis;
        Character* closest_char = NULL;
        for(Character* c : team.get_characters()){
           
            if(c->isAlive()){
                if(one_iter){
                    min_dis = org->distance(c);
                    closest_char = c;
                    one_iter = false;
                }
                else{
                    double dis = org->distance(c);
                    if (dis<min_dis){
                        min_dis = dis;
                        closest_char = c;
                    }
                }

            }
        }  
        return closest_char;
            
    }

    void Team::attack(Team *Team_b){
        if(Team_b==NULL){
            throw invalid_argument ("Team_b is null");
        }
        if(this->get_leader()->isAlive()==false){
           this->leader = fined_closest_to(this->leader, *this);
           if (this->leader==NULL){
                cout<<"attack is over no living solgers IN ATTACK TEAM"<<endl;
                return ;
           }
        }
        Character* victom = fined_closest_to(this->leader,*Team_b);
        if (victom==NULL){
                cout<<"attack is over no living solgers IN TEAM B"<<endl;
                return ;
           }
        
        for(Character* c : characters){
            Cowboy *cowboy = dynamic_cast<Cowboy *>(c);
             //its a Cowboy
            if (cowboy != NULL){
                if(cowboy->isAlive()){
                    if(cowboy->hasboolets()){
                        cowboy->shoot(victom);
                        if(victom->isAlive()==false){
                            victom = fined_closest_to(this->leader,*Team_b);
                            if (victom==NULL){
                                    cout<<"attack is over no living solgers IN TEAM B"<<endl;
                                    return ;
                            }
                        }
                    }
                    else{
                        cowboy->reload();
                    } 
                }
                
            }
                   
        }
        for(Character* c : characters){
            Ninja* ninja = dynamic_cast<Ninja*>(c) ;//its a Ninja
            if (ninja!=NULL){
                if(ninja->isAlive()){
                    if(ninja->distance(victom)<=1){
                        ninja->slash(victom);
                        if(victom->isAlive()==false){
                            victom = fined_closest_to(this->leader,*Team_b);
                            if (victom==NULL){
                                    cout<<"attack is over no living solgers IN TEAM B"<<endl;
                                    return ;
                            }
                        }
                    }
                    else{
                        ninja->move(victom);
                    }   
                }
            }
        }
    }
    

    int Team::stillAlive(){
        int count = 0;
        for(Character* c : characters){
            if(c->get_hit_points() >0){
                count++;
            }
        }
        return count;
    }

    void Team::print(){
        for(Character* c : characters){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(c); //its a Cowboy
            if (cowboy!=NULL) { //its a Cowboy
                cout<< c->print()<<endl;
            }
        }
        for(Character* c : characters){
            Ninja* ninja = dynamic_cast<Ninja*>(c); //its a Cowboy
            if (ninja!=NULL){  
                cout<< c->print()<<endl;
            }
        }
    
    }

    Character* Team::get_leader(){
        return leader;
    }

    std::vector<Character*> Team::get_characters(){
        return characters;
    }

    Team::~Team(){
         for (Character* character : characters) {
                delete character;
            }
        characters.clear();

     }
           
    
}
