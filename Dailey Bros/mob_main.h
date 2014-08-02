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
    struct ability{
        string ability_name;
        int damage;
    };
    
    private:
        string name;
        string description;
        int hp;
        int mp;
        int exp_reward;
        ability ind_ability[2];
    public:
        Goblins(){
            name = "Goblin";
            description = "The nasty Goblin race is after many things, but most of all\
                            is after your money!";
            hp = 15;
            mp = 5;
            exp_reward = 1;
            ind_ability[0].ability_name = "fire";
            ind_ability[0].damage = 2;
            ind_ability[1].ability_name = "goblin toss";
            ind_ability[1].damage = 5;
        }
        
        /** Begin Experience fuctions **/
        // award exp to character that defeated goblin
        int get_reward_experience(){
            return exp_reward;
        }
        
        /** End of experience functions **/
        
        /** Begin hp functions **/
        // set hp of goblin
        void set_hp(int health) {
            hp = health;
        }
        
        // get hp of goblin class
        int get_hp() {
            return hp;
        }
        
        /*
         * Goblin is damaged
         * 
         * @return bool if goblin is killed
         */
        string damage_hp(int dmg) {
            bool dead = false;
            string result;
            hp = hp - dmg;            
            if (hp > 0) {
                result = " has defeated the Goblin!";
                return result;
            } else {
                dead = true;
                result = " Goblin took " + dmg + " points of damage!";
                return result;
            }                                 
        }
        
        /** End of hp functions **/
        
        /** Begin **/
        
};

#endif	/* MOB_MAIN_H */
