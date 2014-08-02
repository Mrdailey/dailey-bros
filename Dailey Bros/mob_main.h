/* 
 * File:   mob_main.h
 * Author: rcsda_000
 *
 * Created on August 1, 2014, 9:59 PM
 */

#ifndef MOB_MAIN_H
#define	MOB_MAIN_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// hey there crakka

//asdfasdf

/*class MobType
{
    private:
        string mob_name;
    public:
        MobType(){
        }
};*/

/*
 * The Goblin monster type.  Has initial hp 15, mp 5.
 *
 * 
 * 
 * 
 */
class Goblins
{
    private:
        string name;
        string description;
        int hp;
        int mp;
        int exp_reward;
       
    public:
        Goblins(){
            name = "Goblin";
            description = "The nasty Goblin race is after many things, but most of all\
                            is after your money!";
            hp = 15;
            mp = 5;
            exp_reward = 1;
        }
        
        /** Begin Experience fuctions **/
        // award exp to character that defeated goblin
        int reward_experience(){
            return exp_reward;
        }
        
        
};


#endif	/* MOB_MAIN_H */

