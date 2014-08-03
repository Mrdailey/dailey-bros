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
        int mp_cost;
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
            description = "The nasty Goblin race is after many things, but most of all"
                    " is after your money!\n";
            hp = 20;
            mp = 5;
            exp_reward = 5;
            ind_ability[0].ability_name = "fire";
            ind_ability[0].damage = 2;
            ind_ability[0].mp_cost = 3;
            ind_ability[1].ability_name = "goblin toss";
            ind_ability[1].damage = 5;
            ind_ability[1].mp_cost = 0;
        }
        
        /** Begin Description functions **/
        // retrieve goblin description string
        string get_description() {
            return description;
        }
        
        // set the goblin description string
        void set_description(string desc) {
            description = desc;
        }
        /** End of Description functions **/
        
        /** Begin Name functions **/
        // retreive the name of the goblin class
        string get_name() {
            return name;
        }
        
        // set the name of the goblin class
        void set_name(string n) {
            name = n;
        }
        
        /** End of Name functions **/
        
        /** Begin Experience fuctions **/
        // award exp to character that defeated goblin
        int get_reward_experience(){
            return exp_reward;
        }
        
        // set the exp reward of the goblin class
        void set_reward_experience(int exp) {
            exp_reward = exp;
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
        bool damage_hp(int dmg) {
            bool dead = false;            
            hp = hp - dmg;     
            cout << " took " << dmg << " points of damage!\n";
            if (hp <= 0) {
                dead = true;                
            } else {
                dead = false;                                
            }                
            return dead;
        }
        
        /** End of hp functions **/
        
        /** Begin mp functions **/
        // get the mp of the goblin class
        int get_mp() {
            return mp;            
        }
        
        // 
        
};

#endif	/* MOB_MAIN_H */
