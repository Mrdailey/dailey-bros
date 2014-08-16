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
    int heal;
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
        string name;
        string description;
        int hp;
        int mp;
        int max_hp;
        int max_mp;
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
            max_hp = 0;
            max_mp = 0;
            
            for (int i = 0; i < 3; i++) {
                ind_ability[i].ability_name = "";
                ind_ability[i].damage = 0;
                ind_ability[i].mp_cost = 0;
                ind_ability[i].ability_info = "";    
                ind_ability[i].heal = 0;
            }
        }
        
        /** Begin Description functions **/

        string get_description() {
            return description;
        }
        
        void set_description(string desc) {
            description = desc;
        }
        /** End of Description functions **/
        
        /** Begin Name functions **/
        string get_name() {
            return name;
        }
        
        void set_name(string n) {
            name = n;
        }
        
        /** End of Name functions **/
        
        /** Begin Experience fuctions **/        
        int get_exp_reward() {
            return exp_reward;
        }
                
        void set_exp_reward(int exp) {
            exp_reward = exp;
        }
        
        /** End of experience functions **/
        
        /** Begin hp functions **/
        void set_hp(int health) {
            hp = health;
        }
        
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
        
        void increase_hp(int health) {
            hp += health;
        }
        
        /** End of hp functions **/
        
        /** Begin mp functions **/
        int get_mp() {
            return mp;
        }
        
        void set_mp(int magic) {
            mp = magic;
        }
        
        void decrease_mp(int mp_cost)  {
            mp = mp - mp_cost;
        }
        
        void increase_mp(int mp_cost) {
            mp += mp_cost;
        }
        
        /** End of mp functions **/
        
        /** Begin max hp and mp functions **/
        
        void set_max_hp(int max) {
            max_hp = max;
        }
        
        void set_max_mp(int max) {
            max_mp = max;
        }    
        
        int get_max_hp() {
            return max_hp;
        }
        
        int get_max_mp() {
            return max_mp;
        }
        
        /** End of max hp and mp functions **/
        
        /** Begin Ability functions **/
        
        string get_ability_name(int choice) {
            return ind_ability[choice].ability_name;
        }
        
        int get_ability_damage(int choice) {
            return ind_ability[choice].damage;            
        }
        
        int get_ability_heal(int choice) {
            return ind_ability[choice].heal;
        }
        
        int get_ability_mp_cost (int choice) {
            return ind_ability[choice].mp_cost;
        }
        
        string get_ability_info(int choice) {
            return ind_ability[choice].ability_info;
        }
        
        int set_ability_damage(int choice, int dmg) {
            ind_ability[choice].damage = dmg;
        }
        
        int set_ability_heal(int choice, int health) {
            ind_ability[choice].heal = health;
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
