/* 
 * File:   jobs.h
 * Author: Michael Ryan
 *
 * Created on August 1, 2014, 10:24 PM
 */

#ifndef JOBS_H
#define	JOBS_H
#include <iostream>
#include <string>
#include <iomanip>
//#include "items.h"
//#include "begin_adventure.h"
#include "mob_main.h"

using namespace std;

// initialize levels from 1-20
int level_exp[21] = {
    0, 50, 125, 225, 350, 500, 675, 875, 1100, 1350, 1625,
    1925, 2250, 2600, 2975, 3375, 3800, 4250, 4725, 5525, 6050
};  

typedef ability ab;
typedef item_bag items;
class Jobs {
      
    private:
        string name;
        string job_type;
        string description;
        int hp;
        int mp;
        int max_hp;
        int max_mp;
        int experience;    
        int level;
        ab ind_ability[10];
        items item[20];
        
    public:
        Jobs() {
            name = "";
            job_type = "";
            description = "";
            hp = 0;
            mp = 0;
            max_hp = 0;
            max_mp = 0;
            experience = 0;
            level = 1;            
            
            for (int i = 0; i < 9; i++) {
                ind_ability[i].ability_name = "";
                ind_ability[i].damage = 0;
                ind_ability[i].mp_cost = 0;
                ind_ability[i].ability_info = "";  
                ind_ability[i].heal = 0;
            }
            
            for (int k = 0; k < 2; k++) {
                item[k].item.set_description("");
                item[k].item.set_cost(0);
                item[k].item.set_name("");    
                item[k].item.set_value(0);
                item[k].item.set_drop_rate(0);
                item[k].quantity = 0;
            }
        }          

        /** Begin name functions **/
        
        void set_name(string n) {
            name = n;
        }
        
        string get_name() {
            return name;
        }        
        /** End name functions **/
        
        /** Begin Job functions **/ 
        
        string get_job() {
            return job_type;
        }
        
        void set_job(string s) {
            job_type = s;
        }
        /** End of Job functions **/
        
        /** Begin Experience functions **/
     
        void increase_experience(int exp_rewarded) {
            experience += exp_rewarded;
        }
        
        void set_experience (int exp) {
            experience = exp;
        }
        
        int get_experience() {
            return experience;
        }                
        /** End experience functions **/
       
        /** Begin Level functions **/
        
        int get_level() {
            return level;
        }
        
        void set_level(int lvl) {
            level = lvl;
        }        
        
        void increase_level() {
            level++;
        }
        
        /** End of Level functions **/
        
        /** Begin Description functions **/ 
        
        void set_description(string desc) {
            description = desc;
        }
        
        string get_description() {
            return description;
        }
        /** End Description functions **/        
        
        /** Begin hp functions **/
        
        void set_hp(int health) {
            hp = health;
        }
        
        int get_hp() {
            return hp;
        }
        
        // job is damaged; @return bool if job is killed        
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
        void set_mp(int magic) {
            mp = magic;
        }
        
        int get_mp() {
            return mp;
        }
        
        void increase_mp(int mp_gained) {
            mp += mp_gained;
        }
        
        // decrease mp on ability usage
        void decrease_mp(int mp_cost) {
            mp = mp - mp_cost;
        }
        
        /** End of mp functions **/
        
        /** Begin max hp and max mp functions **/
        
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
        
        /** Begin Ability Functions **/        
        int get_ability_damage(int choice) {
            return ind_ability[choice].damage;
        }
                
        int get_ability_heal(int choice) {
            return ind_ability[choice].heal;
        }                
                
        string get_ability_name(int choice) {
            return ind_ability[choice].ability_name;
        }
                
        int get_ability_mp_cost(int choice) {
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
        
        /** End of all ability functions **/
        
        /** Begin Item Functions **/
        
        void set_item_name(int choice, string item_name) {
            item[choice].item.set_name(item_name);
        }
        
        void set_item_cost(int choice, int cost) {
            item[choice].item.set_cost(cost);
        }
                 
        void set_item_value(int choice, int val) {
            item[choice].item.set_value(val);
        }
        
        int get_item_value(int choice) {
            return item[choice].item.get_value();
        }
        
        void set_item_description(int choice, string desc) {
            item[choice].item.set_description(desc);
        }
        
        void set_item_quantity(int choice, int quantity) {
            item[choice].quantity = quantity;
        }
        
        string get_item_name(int choice) {
            return item[choice].item.get_name();
        }
        
        int get_item_cost(int choice) {
            return item[choice].item.get_cost();            
        }
        
        int get_item_quantity(int choice) {
            return item[choice].quantity;
        }
        
        string get_item_description(int choice) {
            return item[choice].item.get_description();
        }
        
        // Gives information on character while exploring
        void display_info() {    
            int items = sizeof(item)/sizeof(item[0]);
            int cap = 3;
            cout << "                   " << name << "\n";
            cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
            cout << "  HP       : " << hp << " / " << max_hp << "\n";
            cout << "  MP       : " << mp << " / " << max_mp << "\n";
            cout << "  EXP      : " << experience << " / " << level_exp[level] << "\n";
            cout << "  LEVEL    : " << level << "\n";
            cout << "  JOB      : " << job_type << "\n";
            cout << "  ITEMS    : ";
            for (int i = 0; i < items; i++) {
                if (item[i].quantity != 0) {
                    cout << setw(19) << right << item[i].item.get_name() << " - " << item[i].quantity<< "\n";
                }                
            }    
            cout << "  ABILITIES: \n\n";   
            
            if (level >= 2) {
                cap = 4;
            } else if (level >= 6) {
                cap = 5;
            }
            
            for (int k = 0; k < cap; k++) { // for printing all ability props
                cout << " " << ind_ability[k].ability_name << "\n";
                cout << " ____________\n";
                
                if (ind_ability[k].heal > 0) {
                    cout << "  Heal   : " << ind_ability[k].heal << "\n";
                } else {
                    cout << "  Damage : " << ind_ability[k].damage << "\n";                    
                }
                
                cout << "  MP Cost: " << ind_ability[k].mp_cost << "\n";
                cout << "  Info   : " << ind_ability[k].ability_info << "\n\n";                
            }

            cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";            
        }
        
        // For Leveling up 
        void level_up() {          

            for (int k = 1; k < 21; k++) {                                                                                                                                                                                                                                                         

                // If their experience is higher than the experience required and they 
                // are not already that level.
                if (experience >= level_exp[k] && level != k+1) {
                    level++;

                    cout << " " << name << " is now level " << level << "!\n";                           
                    
                    if (level % 2 == 0) {
                        
                        if (job_type == "Warrior") {
                            max_hp += 10;
                            max_mp += 3;                            
                            hp = max_hp;
                            mp = max_mp;                            
                            
                        } else if (job_type == "Black Mage") {
                            max_hp += 6;
                            max_mp += 8;
                            hp = max_hp;
                            mp = max_mp;
                            
                        } else if (job_type == "Thief") {
                            max_hp += 7;
                            max_mp += 3;
                            hp = max_hp;
                            mp = max_mp;
                            
                        } else if (job_type == "Paladin") {
                            max_hp += 10;
                            max_mp += 5;
                            hp = max_hp;
                            mp = max_mp;
                        }

                        if (level == 2) {

                            // Warrior levels up
                            if (job_type == "Warrior") {
                                // NEW ABILITY!!                    
                                ind_ability[3].ability_name = "Defend";
                                ind_ability[3].ability_info = "Braces for next attack and reduces incoming damage.\n";                
                                // reduces damage of the next attack by 50% 
                        // Black Mage level up stuffs
                            } else if (job_type == "Black Mage") {                                      
                                // NEW ABILITY!~
                                ind_ability[3].ability_name = "Flame";
                                ind_ability[3].damage = 6;
                                ind_ability[3].mp_cost = 6;
                                ind_ability[3].ability_info = "Engulfs the enemy in flames.\n";

                            // Thief levels up 
                            } else if (job_type == "Thief") {
                                // NEW ABILITY!!
                                ind_ability[3].ability_name = "Low Blow";
                                ind_ability[3].damage = 10;
                                ind_ability[3].mp_cost = 2;
                                ind_ability[3].ability_info = "Dashes quickly to deliver a sudden cheap shot.\n";                        

                            // Pally levels up 
                            } else if (job_type == "Paladin") {
                                // NEW ABILITY!!
                                ind_ability[3].ability_name = "Redemptive Light";                            
                                ind_ability[3].heal = 15;
                                ind_ability[3].mp_cost = 5;
                                ind_ability[3].ability_info = "The power of redemption restores the Paladin's health.\n";
                            }
                            cout << " " << name << " has learned the new ability " << ind_ability[3].ability_name << "!\n\n";
                        }
                        
                        if (level == 6) {
                            
                            if (job_type == "Warrior") {
                                ind_ability[4].ability_name = "";
                                ind_ability[4].ability_info = "";
                                
                            }
                        }
                    } else if (level % 2 == 1) {

                        if (job_type == "Warrior") {
                            max_hp += 7;                    
                            max_mp += 2;
                            hp = max_hp;
                            mp = max_mp;
                            ind_ability[0].damage += hp * 0.05;
                            
                        } else if (job_type == "Black Mage") {
                            max_hp += 5;
                            max_mp += 6;
                            hp = max_hp;
                            mp = max_mp;
                            ind_ability[0].damage += mp * 0.04;
                            ind_ability[0].mp_cost += 1;
                            ind_ability[3].damage += mp * 0.05;
                            ind_ability[3].mp_cost += 1;
                            
                        } else if (job_type == "Thief") {
                            max_hp += 5;
                            max_mp += 3;
                            hp = max_hp;
                            mp = max_mp;
                            ind_ability[0].damage += hp * 0.04;
                            ind_ability[3].damage += hp * 0.05;
                            
                        } else if (job_type == "Paladin") {
                            max_hp += 7;
                            max_mp += 4;
                            hp = max_hp;
                            mp = max_mp;     
                            ind_ability[0].damage += hp * .04;
                            ind_ability[1].damage += hp * .05;
                            ind_ability[3].heal += mp * .04;
                        }
                    }
                }                                
            }
        }        
};

#endif	/* JOBS_H */

