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

using namespace std;

int get_rand(int min, int max);

class Warrior {
    
    struct ability {
        string ability_name;
        int damage;        
        int mp_cost;
    };
    
    private:
        string name;
        string description;
        int hp;
        int mp;
        int experience;    
        int level;
        ability ind_ability[3];
        
    public:
        Warrior() {
            name = "Warrior";
            description = "\n The brave warrior uses his strength and weapon "
                    "skills to massacre his foes.\n Select this job? Hit 'y' or 'n' and enter: ";
            hp =  50;
            mp = 20;
            experience = 0;   
            level = 1;            
            ind_ability[0].ability_name = "Sword attack";
            ind_ability[0].damage = 8;
            ind_ability[0].mp_cost = 0;            
            ind_ability[1].ability_name = "Head-bonk";
            ind_ability[1].damage = get_rand(5, 9);
            ind_ability[1].mp_cost = 2;
            ind_ability[2].ability_name = "Flee";
            ind_ability[2].damage = 0;
            ind_ability[2].mp_cost = 0;
        }
        
        /** Begin Experience functions **/
        // add exp to warrior class upon defeating mob         
        void increase_experience(int exp_rewarded) {
            experience += exp_rewarded;
        }
        
        // set exp to warrior class
        void set_experience (double exp) {
            experience = exp;
        }
        
        // gets the current exp the warrior has attained.
        int get_experience() {
            return experience;
        }        
        
       /** End experience functions **/
        
       /** Begin Description functions **/ 
        // set the description of the warrior
        void set_description(string desc) {
            description = desc;
        }
        
        // returns the description of the warrior class       
        string get_description() {
            return description;
        }
        /** End Description functions **/
        
        /** Begin name functions **/
        // set the name of the warrior class
        void set_name(string n) {
            name = n;
        }
        
        // get the name for the warrior 
        // the user can change this name
        string get_name() {
            return name;
        }
        
        /** End name functions **/
        
        /** Begin hp functions **/
        // set the hp of the warrior
        void set_hp(int health) {
            hp = health;
        }
        
        // get the hp of the warrior
        int get_hp() {
            return hp;
        }
        
        /* warrior is damaged
         *
         * @return bool if warrior is killed
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
        
        // warrior regains health upon level up or 
        // end of fight.
        void gain_hp(int health) {
            hp += health;
        }
        
        /** End of hp functions **/
        
        /** Begin mp functions **/
        // set the mp
        void set_mp(int magic) {
            mp = magic;
        }
        
        // return the current mp of the warrior
        int get_mp() {
            return mp;
        }
        
        // increase mp on battle win
        void increase_mp(int mp_gained) {
            mp += mp_gained;
        }
        
        // decrease mp on ability usage
        void decrease_mp(int mp_cost) {
            mp = mp - mp_cost;
        }
        
        /** End of mp functions **/
        
        /** Begin Ability Functions **/
        // get name for ability
        int get_ability_damage(int choice) {
            return ind_ability[choice].damage;
        }
        
        // get damage for ability
        string get_ability_name(int choice) {
            return ind_ability[choice].ability_name;
        }
        
        // get mana cost for ability
        int get_ability_mp_cost(int choice) {
            return ind_ability[choice].mp_cost;
        }
        
        // Add ability upon level up
//        int add_job_ability(int num_ability, int lvl) {
//            if (lvl == 2) {
//                ind_ability[num_ability] {
//                    name = "Power Strike";
//                    damage = get_rand(9, 13);
//                    mp_cost = 5;
//                };
//            }                      
//        }                                                      
               
};

class BlackMage {
    
};

class Thief {
    
};

class Paladin {
    
};


#endif	/* JOBS_H */

