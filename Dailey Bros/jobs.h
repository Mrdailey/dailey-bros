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
    int strength;
    int stamina;
    int intelligence;
    int dexterity;
    int defense;
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
        strength = 0;
        stamina = 0;
        intelligence = 0;        
        dexterity = 0;
        defense = 0;
        
        for (int i = 0; i < 9; i++) {
            ind_ability[i].ability_name = "";
            ind_ability[i].damage = 0;
            ind_ability[i].mp_cost = 0;
            ind_ability[i].ability_info = "";
            ind_ability[i].heal = 0;
            ind_ability[i].defend = 0;
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

    string get_job_type() {
        return job_type;
    }

    void set_job_type(string s) {
        job_type = s;
    }
    /** End of Job functions **/

    /** Begin Experience functions **/

    void increase_experience(int exp_rewarded) {
        experience += exp_rewarded;
    }

    void set_experience(int exp) {
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
        int temp_hp;
        temp_hp = hp;
        hp = hp - dmg;        
        if (hp > temp_hp) {
            hp = temp_hp;
            dmg = 0;
        }
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
    
    int get_ability_defend(int choice) {
        return ind_ability[choice].defend;
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
    
    void set_ability_defend(int choice, int defend_value) {
        ind_ability[choice].defend = defend_value;
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
        item[choice].quantity += quantity;
    }
    
    void decrease_item_quantity(int choice) {
        item[choice].quantity --;
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

    void set_job(string job_name) {
        job_type = job_name;
         // The Warrior job        
        if (job_type == "Warrior") {        
            description = "\n The brave warrior uses his strength and weapon "
                "skills to massacre his foes.\n Select this job? Hit 'y' or 'n' and 'enter': ";            
            hp = 50;
            mp = 20;
            max_hp = 50;
            max_mp = 20;
            strength = 30;
            intelligence = 12;
            stamina = 25;
            dexterity = 15;
            defense = 28;
            
            ind_ability[0].ability_name = "Sword Attack";
            ind_ability[0].damage = 8;
            ind_ability[0].ability_info = "A strong basic sword attack.";
            
            ind_ability[1].ability_name = "Head-bonk";
            ind_ability[1].damage = 10;
            ind_ability[1].mp_cost = 2;
            ind_ability[1].ability_info = "A strong head bash. Ouch.";            
            // The Black Mage Job
        } else if (job_type == "Black Mage") {                    
            description = "\n The powerful black mage unleashes spells to devastate his foes.\n"
                " Select this job? Hit 'y' or 'n' and 'enter': ";
            hp = 40;
            mp = 40;
            max_hp = 40;
            max_mp = 40;
            strength = 16;
            intelligence = 36;
            stamina = 23;
            dexterity = 12;
            defense = 23;

            ind_ability[0].ability_name = "Surge";
            ind_ability[0].damage = 15;
            ind_ability[0].mp_cost = 5;            
            ind_ability[0].ability_info = "Releases a powerful non-elemental burst of energy.";
            
            ind_ability[1].ability_name = "Staff-yack";            
            ind_ability[1].damage = 4;
            ind_ability[1].mp_cost = 0;
            ind_ability[1].ability_info = "A forceful swing of the staff oughta do the trick.";
            // The Thief Job
        } else if (job_type == "Thief") {        
            description = "\n The agile thief uses his cunning and agility to overcome his foes.\n"
                " Select this job? Hit 'y' or 'n' and 'enter': ";
            hp = 44;
            mp = 22;
            max_hp = 44;
            max_mp = 22;
            strength = 19;
            intelligence = 12;
            stamina = 24;
            dexterity = 30;
            defense = 25;
            
            ind_ability[0].ability_name = "Double stab-jab";
            ind_ability[0].damage = 7;
            ind_ability[0].ability_info = "A sudden two strikes that can be lethal.";            

            ind_ability[1].ability_name = "Stealth";
            ind_ability[1].mp_cost = 3;
            ind_ability[1].ability_info = "Hide from sight and increase the damage of the next attack. Can be used additively.";
            // The Paladin Job
        } else if (job_type == "Paladin") {        
            description = "\n The noble paladin is a master of both weaponry and holy magic.\n"
                " Select this job? Hit 'y' or 'n' and 'enter': ";
            hp = 50;
            mp = 25;
            max_hp = 50;
            max_mp = 25;
            strength = 26;
            intelligence = 24;
            stamina = 25;
            dexterity = 10;
            defense = 25;
            
            ind_ability[0].ability_name = "Holy Slash";
            ind_ability[0].damage = 8;
            ind_ability[0].ability_info = "A magical strike that deals consistent damage.";            

            ind_ability[1].ability_name = "Atonement";
            ind_ability[1].damage = 11;
            ind_ability[1].mp_cost = 3;
            ind_ability[1].ability_info = "Channels holy energy into a blade to damage enemies.";
        }
    }
    
    // Gives information on character while exploring
    void display_info() {
        char choice;
        int cap = 3;
        cout << "                   " << name << "\n";
        cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
        cout << "  HP         : " << hp << " / " << max_hp << "\n";
        cout << "  MP         : " << mp << " / " << max_mp << "\n";
        cout << "  EXP        : " << experience << " / " << level_exp[level] << "\n";
        cout << "  LEVEL      : " << level << "\n";
        cout << "  JOB        : " << job_type << "\n";
        cout << "  VIEW STATS : PRESS 'S'\n";
        cout << "  ABILITIES  : \n\n";

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
        // View Stats?
        cin >> choice; toupper(choice); cin.ignore(80, '\n');
        switch (choice) {
            case 's': case 'S': {                
                display_stats();
            } break;
            default: {}               
        }
    }
    
    void display_stats() {    
        system("cls");
        cout << "                 " << name << "\n";
        cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";
        if (job_type == "Warrior") {            
            cout << " STRENGTH     : " << strength << "\n Increases damage of attacks by 2 for every 1 strength.\n\n";
            cout << " INTELLIGENCE : " << intelligence << "\n\n";
            cout << " DEXTERITY    : " << dexterity << "\n\n";
            cout << " STAMINA      : " << stamina << "\n Increases health by 2 for every 1 stamina.\n\n";
            cout << " DEFENSE      : " << defense << "\n Reduces damage taken from all sources.\n\n";
        } else if (job_type == "Black Mage") {
            cout << " STRENGTH     : " << strength << "\n\n";
            cout << " INTELLIGENCE : " << intelligence << "\n Increases damage done by magic by 2 for every 1 intelligence.\n\n";
            cout << " DEXTERITY    : " << dexterity << "\n\n";
            cout << " STAMINA      : " << stamina << "\n Increases health by 1.5 for every 1 stamina.\n\n";
            cout << " DEFENSE      : " << defense << "\n Reduces damage taken from all sources.\n";
        } else if (job_type == "Thief") {
            cout << " STRENGTH     : " << strength << "\n Increases damage done by attacks by 1 for every 1 strength.\n\n";
            cout << " INTELLIGENCE : " << intelligence << "\n\n";
            cout << " DEXTERITY    : " << dexterity << "\n Increases damage done by attacks by 2 for every 1 dexterity.\n\n";
            cout << " STAMINA      : " << stamina << "\n Increases health by 1.5 for every 1 stamina.\n\n";
            cout << " DEFENSE      : " << defense << "\n Reduces damage taken from all sources.\n\n";            
        } else if (job_type == "Paladin") {
            cout << " STRENGTH     : " << strength << "\n Increases damage done by attacks by 1.5 for every 1 strength.\n\n";
            cout << " INTELLIGENCE : " << intelligence << "\n Increases damage done by magic by 1.5 for every 1 intelligence.\n\n";
            cout << " DEXTERITY    : " << dexterity << "\n\n";
            cout << " STAMINA      : " << stamina << "\n Increases health by 2 for every 1 stamina.\n\n";
            cout << " DEFENSE      : " << defense << "\n Reduces damage taken from all sources.\n\n";
        }
    }

    void display_items() {
        system("cls");
        int items = sizeof (item) / sizeof (item[0]);
        cout << "      ITEMS\n";
        cout << "_ _ _ _ _ _ _ _ _\n\n";
        for (int i = 0; i < items; i++) {
            if (item[i].quantity != 0) {
                cout << "  " << item[i].item.get_name() << "  Quantity: " << item[i].quantity << "\n\n";
                cout << "  Description: " << item[i].item.get_description() << "\n\n";
            }
        }
    }
    
    bool item_validation(string item_choice) {
        if (item_choice == "Basic Health Potion" || item_choice == "Basic Mana Potion") {
            return true;
        } else {
            return false;
        }
    }
    
    int item_selection(string item_choice) {
        string a; 
        int items = sizeof (item) / sizeof (item[0]);
        for (int i = 0; i < items; i++) {
            if (item[i].quantity != 0) {
                a = item[i].item.get_name();
                if (a == item_choice) {
                    return i;
                }
            }
        }
    }
    
    bool item_activate(string item_name, int item_value) {
        int val;
        cout << " " << name << " consumes a " << item_name << "!\n";
        if (item_name == "Basic Health Potion") {            
            hp += item_value;
            if (hp > max_hp) {
                val = hp - max_hp;
                item_value = item_value - val;
                hp = max_hp;
            }
            cout << " " <<  name << " restored " << item_value << " hp!\n";            
            return true;
        } else if (item_name == "Basic Mana Potion") {
            mp += item_value;     
            if (mp > max_mp) {
                val = mp - max_mp;                
                item_value = item_value - val;
                mp = max_mp;
            }            
            cout << " " << name << " restores " << item_value << " mp!\n";            
            return true;
        } else {
            return false;
        }
    }
    // For Leveling up 

    void level_up() {
        for (int k = 1; k < 21; k++) {
            // If their experience is higher than the experience required and they 
            // are not already that level.
            if (experience >= level_exp[k] && level != k + 1) {
                level++;
                cout << " " << name << " is now level " << level << "!\n";

                if (level % 2 == 0) {
                    if (job_type == "Warrior") {
                        max_hp += 10;
                        max_mp += 3;
                        hp = max_hp;
                        mp = max_mp;
                        intelligence += 1;
                        strength += 3;
                        stamina += 3;
                        dexterity += 1;
                        defense += 2;

                    } else if (job_type == "Black Mage") {
                        max_hp += 6;
                        max_mp += 8;
                        hp = max_hp;
                        mp = max_mp;
                        intelligence += 4;
                        stamina += 2;
                        defense += 1;
                        strength += 1;

                    } else if (job_type == "Thief") {
                        max_hp += 7;
                        max_mp += 3;
                        hp = max_hp;
                        mp = max_mp;
                        intelligence += 1;
                        stamina += 2;
                        strength += 1;
                        dexterity += 4;
                        defense += 1;

                    } else if (job_type == "Paladin") {
                        max_hp += 10;
                        max_mp += 5;
                        hp = max_hp;
                        mp = max_mp;
                        intelligence += 2;
                        stamina += 2;
                        strength += 2;
                        dexterity += 1;
                        defense += 2;                        
                    }

                    if (level == 2) {

                        // Warrior levels up
                        if (job_type == "Warrior") {
                            // NEW ABILITY!!                    
                            ind_ability[3].ability_name = "Defend";
                            ind_ability[3].defend = defense / 8;
                            ind_ability[3].mp_cost = 5;
                            ind_ability[3].ability_info = "Braces for next attack and reduces incoming damage.\n";
                            // reduces damage of the next attack by 50% 
                            // Black Mage level up stuffs
                        } else if (job_type == "Black Mage") {
                            // NEW ABILITY!~
                            ind_ability[3].ability_name = "Flame";
                            ind_ability[3].damage = get_rand(16, 18);
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
                    } else if (level == 6) {

                        if (job_type == "Warrior") {
                            ind_ability[4].ability_name = "";
                            ind_ability[4].ability_info = "";

                        }
                    } else {
                        
                    }
                } else if (level % 2 == 1) {

                    if (job_type == "Warrior") {
                        max_hp += 7;
                        max_mp += 2;
                        hp = max_hp;
                        mp = max_mp;
                        strength += 3;
                        stamina += 3;
                        dexterity += 1;
                        defense += 2;
                        ind_ability[0].damage += strength / 10;
                        ind_ability[1].damage += strength / 8;
                        ind_ability[1].mp_cost += 1;
                        ind_ability[3].mp_cost += 1;
                        ind_ability[3].defend += defense / 10;

                    } else if (job_type == "Black Mage") {
                        max_hp += 5;
                        max_mp += 6;
                        hp = max_hp;
                        mp = max_mp;
                        intelligence += 4;
                        stamina += 2;
                        defense += 1;
                        ind_ability[0].damage += intelligence / 10;
                        ind_ability[0].mp_cost += 2;
                        ind_ability[1].damage += strength / 20;
                        ind_ability[3].damage += intelligence / 8;
                        ind_ability[3].mp_cost += 2;                        
                        
                    } else if (job_type == "Thief") {
                        max_hp += 5;
                        max_mp += 3;
                        hp = max_hp;
                        mp = max_mp;
                        intelligence += 1;
                        stamina += 2;
                        strength += 1;
                        dexterity += 4;
                        defense += 1;
                        ind_ability[0].damage += dexterity / 10;
                        ind_ability[1].mp_cost += 1;
                        ind_ability[3].damage += dexterity / 8;
                        ind_ability[3].mp_cost += 2;
                                                
                    } else if (job_type == "Paladin") {
                        max_hp += 7;
                        max_mp += 4;
                        hp = max_hp;
                        mp = max_mp;                       
                        intelligence += 2;
                        stamina += 2;
                        strength += 2;
                        dexterity += 1;
                        defense += 2;                        
                        ind_ability[0].damage += strength / 12;
                        ind_ability[1].damage += strength / 9;
                        ind_ability[1].mp_cost += 1;
                        ind_ability[3].heal += intelligence / 6;
                        ind_ability[3].mp_cost += 2;
                    }
                } // end of odd level increments
            } // end of level up
            else {
                
            }
        } // end of for loop
    } // end of function
};

#endif	/* JOBS_H */

