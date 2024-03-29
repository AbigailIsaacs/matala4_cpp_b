#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "Team2.hpp"
using namespace std ;

namespace ariel{

    Team2::Team2(Character* newcaracter):Team(newcaracter){}
    
    void Team2::attack(Team *Team_b){
        if(Team_b==NULL){
            throw invalid_argument ("Team_b is null");
        }
        if(Team_b->stillAlive()==0){
            throw runtime_error ("Team_b is dead");
        }
        if(this->stillAlive()==0){
            throw runtime_error ("Attack Team is dead");
        }
        if(this->get_leader()->isAlive()==false){
           this->set_leader(fined_closest_to(this->get_leader(), this)) ;
           if (this->get_leader()==NULL){
                cout<<"attack is over no living solgers IN ATTACK TEAM"<<endl;
                return ;
           }
        }
        Character* victom = fined_closest_to(this->get_leader(),Team_b);
        if (victom==NULL){
                cout<<"attack is over no living solgers IN TEAM B"<<endl;
                return ;
           }
        
        for(Character* c : this->get_characters()){
            auto &temp = *c;
            if(typeid(temp)==typeid(Cowboy)){
                Cowboy* cowboy = dynamic_cast<Cowboy*>(c) ;//its a Cowboy
                if(cowboy!=NULL){
                    if(cowboy->isAlive()){
                        if(cowboy->hasboolets()){
                            cowboy->shoot(victom);
                            if(victom->isAlive()==false){
                                victom = fined_closest_to(this->get_leader(),Team_b);
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
            else {
                auto &temp2 = *c;
                if(typeid(temp2)==typeid(TrainedNinja)||typeid(temp2)==typeid(OldNinja)||typeid(temp2)==typeid(YoungNinja)){
                    Ninja* ninja = dynamic_cast<Ninja*>(c); //its a Ninja
                    if(ninja!=NULL){
                        if(ninja->isAlive()){
                            if(ninja->distance(victom)<=1){
                                ninja->slash(victom);
                                if(victom->isAlive()==false){
                                    victom = fined_closest_to(this->get_leader(),Team_b);
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
        }
    }
    
    void Team2::print(){
        for(Character* c : get_characters()){
            cout<< c->print()<<endl;
        }
    }
}
