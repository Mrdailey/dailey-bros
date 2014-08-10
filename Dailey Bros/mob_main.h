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
#include <stdlib.h>

using namespace std;

int get_rand(int min, int max);

struct ability {
    string ability_name;
    int damage;
    int mp_cost;
    string ability_info;
};

//struct mob_stats {
//    string name;
//    string description;
//    int hp;
//    int mp;
//    int exp_reward;
//};

//typedef mob_stats ms;
typedef ability ab;

/**
 * Defines the mob type!
 * 
 * This will be used as the basic mob structure.
 */
class Mobs {

    private:
//        ms stat[0]; // define stats struct
        string name;
        string description;
        int hp;
        int mp;
        int exp_reward;
        ab ind_ability[3]; // mobs can have 5 abilities
    public:
        // Basic Mob
        Mobs() {
            name = "";
            exp_reward = 0;
            description = "";
            hp = 0;
            mp = 0;
    
            for (int i = 0; i < 3; i++) {
                ind_ability[i].ability_name = "";
                ind_ability[i].damage = 0;
                ind_ability[i].mp_cost = 0;
                ind_ability[i].ability_info = "";                   
            }
        }
        
        /** Begin Description functions **/
        // retrieve goblin description string
        string get_description() {
//            return stat[0].description;
            return description;
        }
        
        // set the goblin description string
        void set_description(string desc) {
//            stat[0].description = desc;
            description = desc;
        }
        /** End of Description functions **/
        
        /** Begin Name functions **/
        // retreive the name of the goblin class
        string get_name() {
//            return stat[0].name;
            return name;
        }
        
        // set the name of the goblin class
        void set_name(string n) {
//            stat[0].name = n;
            name = n;
        }
        
        /** End of Name functions **/
        
        /** Begin Experience fuctions **/
        // award exp to character that defeated goblin
        int get_exp_reward() {
//            return stat[0].exp_reward;
            return exp_reward;
        }
        
        // set the exp reward of the goblin class
        void set_exp_reward(int exp) {
//            stat[0].exp_reward = exp;
            exp_reward = exp;
        }
        
        /** End of experience functions **/
        
        /** Begin hp functions **/
        // set hp of goblin
        void set_hp(int health) {
//            stat[0].hp = health;
            hp = health;
        }
        
        // get hp of goblin class
        int get_hp() {
//            return stat[0].hp;
            return hp;
        }
        
        /*
         * Goblin is damaged
         * 
         * @return bool if goblin is killed
         */
        bool damage_hp(int dmg) {
            bool dead = false;            
//            stat[0].hp = stat[0].hp - dmg;     
            hp = hp - dmg;
            cout << " took " << dmg << " points of damage!\n";
//            if (stat[0].hp <= 0) {
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
//            return stat[0].mp;            
            return mp;
        }
        
        // set the mp of the goblin
        void set_mp(int magic) {
//            stat[0].mp = magic;
            mp = magic;
        }
        
        // decrease mp based on cost
        void decrease_mp(int mp_cost)  {
//            stat[0].mp = stat[0].mp - mp_cost;
            mp = mp - mp_cost;
        }
        
        // increase mp, if spell fails
        void increase_mp(int mp_cost) {
//            stat[0].mp += mp_cost;
            mp += mp_cost;
        }
        
        /** End of mp functions **/
        
        /** Begin Ability functions **/
        // get the ability name of the goblin
        string get_ability_name(int choice) {
            return ind_ability[choice].ability_name;
        }
        
        // get the ability damage
        int get_ability_damage(int choice) {
            return ind_ability[choice].damage;            
        }
        
        // get the ability's mana cost
        int get_ability_mp_cost (int choice) {
            return ind_ability[choice].mp_cost;
        }
        
        string get_ability_info(int choice) {
            return ind_ability[choice].ability_info;
        }
        
        // set the ability attributes in the following functions
        int set_ability_damage(int choice, int dmg) {
//            if (ind_ability[choice].damage == 0) {
//                ind_ability[choice].damage = get_rand(low, high);
//            }
            ind_ability[choice].damage = dmg;
        }
        
        int set_ability_name(int choice, string name) {
            ind_ability[choice].ability_name = name;
        }
        
        int set_ability_mp_cost(int choice, int magic) {
            ind_ability[choice].mp_cost = magic;
        }
        
        int set_ability_info(int choice, string info) {
            ind_ability[choice].ability_info = info;
        }
        /** End of Ability functions **/
};
        
//class Goblins : public Mobs {
//    
//    public:
//        Goblins() {
//            set_name("Goblin");
//            set_description("The nasty Goblin race is after many things, but most of all"
//                    " is after   your money!\n");
//            set_hp(20);
//            set_mp(5);
//            set_exp_reward(5);
//
//            set_ability_name(0, "Fire");
//            set_ability_damage(0, get_rand(4, 7));
//            set_ability_mp_cost(0, 3);
//            set_ability_info(0, "The goblin unleashes a surge of fire!\n");
//
//            set_ability_name(1, "Goblin Toss");    
//            set_ability_damage(1, get_rand(3,6));
//            set_ability_mp_cost(1,0);    
//            set_ability_info(1, "The goblin grabs an item from his sack and tosses it!\n");  
//        }
//};    
///**
// * Defines the mob type Skeleton Warrior!
// * 
// * Inherits sets/gets from Mobs type
// */
//class SkeletonWarrior : public Mobs {
//    
//    public:
//        SkeletonWarrior() {
//            set_name ("Skeleton Warrior");
//            set_description("Skeleton Warriors may be small and bony, but they "
//                        "can swing a sword like nobody's business!\n");
//            set_hp(25);
//            set_mp(8);
//            set_exp_reward(8);
//            
//            set_ability_name(0, "Bone Sword");
//            set_ability_damage(0, get_rand(5, 7));
//            set_ability_mp_cost(0, 0);
//            set_ability_info(0, "Skeleton Warrior breaks off a bone and uses it as a sword!\n");
//            
//            set_ability_name(1, "Bone Hammer");
//            set_ability_damage(1, get_rand(6, 9));
//            set_ability_mp_cost(1, 4);
//            set_ability_info(1, "The skeleton warrior snaps his leg off and hammers it down!\n");
//        }    
//};

#endif	/* MOB_MAIN_H */
