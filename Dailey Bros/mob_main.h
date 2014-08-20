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
#include "begin_adventure.h"
#include "jobs.h"
#include "items.h"

using namespace std;
int get_rand(int min, int max);

struct ability {
    string ability_name;
    int damage;
    int mp_cost;
    string ability_info;
    int heal;
};

struct item_bag {
    Items item;
    int quantity;
};

typedef item_bag items;
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
        items item[10];
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
            // item bag for mob
            for (int k = 0; k < 9; k++) {
                item[k].item.set_description("");
                item[k].item.set_drop_rate(0);
                item[k].item.set_cost(0);
                item[k].item.set_name("");  
                item[k].quantity = 0;
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
        
        void set_ability_damage(int choice, int dmg) {
            ind_ability[choice].damage = dmg;
        }
        
        void set_ability_heal(int choice, int health) {
            ind_ability[choice].heal = health;
        }
        
        void set_ability_name(int choice, string name) {
            ind_ability[choice].ability_name = name;
        }
        
        void set_ability_mp_cost(int choice, int magic) {
            ind_ability[choice].mp_cost = magic;
        }
        
        void set_ability_info(int choice, string info) {
            ind_ability[choice].ability_info = info;
        }
        /** End of Ability functions **/
        
        /** Begin Items functions **/
        
        // Set default items to potions
        void default_items() {
            Items potion;
            for (int i = 0; i < 2; i++) {
                if (i == 0) {
                    potion.health_potion();
                } else {
                    potion.mana_potion();                    
                }
                item[i].item.set_name(potion.get_name());
                item[i].item.set_cost(potion.get_cost());
                item[i].item.set_description(potion.get_description());
                item[i].item.set_drop_rate(potion.get_drop_rate());
                item[i].item.set_value(potion.get_value());
                item[i].quantity = 1;
            }
        }
        
        void set_item_name(int choice, string item_name) {
            item[choice].item.set_name(item_name);
        }
        
        void set_item_cost(int choice, int cost) {
            item[choice].item.set_cost(cost);
        }
        
        void set_item_description(int choice, string desc) {
            item[choice].item.set_description(desc);
        }
        
        void set_item_drop_rate(int choice, int rate) {
            item[choice].item.set_drop_rate(rate);
        }
        
        void set_item_quantity(int choice, int quantity) {
            item[choice].quantity = quantity;
        }        
        
        void set_item_value(int choice, int val) {
            item[choice].item.set_value(val);
        }
        
        int get_item_value(int choice) {
            return item[choice].item.get_value();
        }
        
        string get_item_name(int choice) {
            return item[choice].item.get_name();
        }
        
        int get_item_cost(int choice) {
            return item[choice].item.get_cost();            
        }
        
        int get_item_drop_rate(int choice) {
            return item[choice].item.get_drop_rate();
        }
        
        int get_item_quantity(int choice) {
            return item[choice].quantity;
        }
        
        string get_item_description(int choice) {
            return item[choice].item.get_description();
        }
                
        /** Begin functions for general mob sets **/
        void set_mob(string mob_type) {
            if (mob_type == "Skeleton Warrior") {
                name = mob_type;
                description = "Skeleton Warriors may be small and bony, but they "
                            "can swing a sword like nobody's business!\n";
                hp = 25;
                mp = 8;
                max_hp = 25;
                max_mp = 8;
                exp_reward = 15;
                default_items();

                ind_ability[0].ability_name = "Bone Hammer";
                ind_ability[0].damage = get_rand(4, 7);
                ind_ability[0].heal = 0;
                ind_ability[0].mp_cost = 4;
                ind_ability[0].ability_info = " The skeleton warrior snaps his leg off and hammers it down!\n"; 

                ind_ability[1].ability_name = "Bone Sword";
                ind_ability[1].damage = get_rand(3, 6);
                ind_ability[1].heal = 0;
                ind_ability[1].mp_cost = 0;
                ind_ability[1].ability_info = " Skeleton Warrior breaks off his arm and uses it as a sword!\n";
                // The Goblin mob type
            } else if (mob_type == "Goblins") {
                name = "Goblin";
                description = "The nasty Goblin race is after many things, but most of all"
                        " is after   your money!\n";
                hp = 20;
                mp = 5;
                max_hp = 20;
                max_mp = 5;
                exp_reward = 10;
                default_items();
                
                ind_ability[0].ability_name = "Fire";
                ind_ability[0].damage = get_rand(4, 6);
                ind_ability[0].heal =  0;
                ind_ability[0].mp_cost = 3;
                ind_ability[0].ability_info = " The goblin unleashes a surge of fire!\n";

                ind_ability[1].ability_name = "Goblin Toss";   
                ind_ability[1].damage = get_rand(3, 4);   
                ind_ability[1].heal = 0;
                ind_ability[1].mp_cost = 0;
                ind_ability[1].ability_info = " The goblin grabs an item from his sack and tosses it!\n";    
                
            // The Giant Tree Frog mob type
            } else if (mob_type == "Giant Tree Frog") {
                name = mob_type;
                description = "This strange creature is both intimidating and extremely fond of"
                " small bugs.\n";
                hp = 22;
                mp = 10;
                max_hp = 22;
                max_mp = 10;
                exp_reward = 15;
                default_items(); // set the default items to potions
                
                ind_ability[0].ability_name = "Leap of Death";
                ind_ability[0].damage = get_rand(4, 6);  
                ind_ability[0].heal = 0;
                ind_ability[0].mp_cost = 0;
                ind_ability[0].ability_info = " The Giant Tree Frog leaps forward and lands on it's belly!\n";

                ind_ability[1].ability_name = "Consume";
                ind_ability[1].damage = 0;
                ind_ability[1].heal = 6;
                ind_ability[1].mp_cost = 3;
                ind_ability[1].heal = 0;
                ind_ability[1].ability_info = " The Giant Tree Frog consumes a nearby bug and restores its health!\n";        
                
            // First Boss Encounter!!    
            } else if (mob_type == "The Forest Feral") {
                name = mob_type;
                description = "This forest belongs to me! You have no power here, Gidian,"
                        "Keeper of the Forest.\n Now, you face ferocity! Cower at my magnificence,"
                        " beware of my might!\n";
                hp = 100;
                mp = 50;
                max_hp = 100;
                max_mp = 50;
                exp_reward = 75;
                default_items();
                
                ind_ability[0].ability_name = "Forest\'s Wrath";
                ind_ability[0].damage = 12;
                ind_ability[0].heal = 0;
                ind_ability[0].mp_cost = 5;
                ind_ability[0].ability_info = " The Forest Feral uproots a nearby tree and slams it down!\n";
                
                ind_ability[1].ability_name = "Rejuvenate";
                ind_ability[1].damage = 0;
                ind_ability[1].heal = 15;
                ind_ability[1].mp_cost = 30;
                ind_ability[1].ability_info = " The Forest Feral takes a large bite out of the earth.\n";
                
                ind_ability[2].ability_name = "Wild Roots";
                ind_ability[2].damage = 10;
                ind_ability[2].heal = 0;
                ind_ability[2].mp_cost = 0;
                ind_ability[2].ability_info = " The Forest Feral commands strong roots to spring out of the ground with force!\n";
            }
        }                
};      
#endif	/* MOB_MAIN_H */
