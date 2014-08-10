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

#include "mob_main.h"

using namespace std;

int get_rand(int min, int max);

//struct ability {
//    string ability_name;
//    int damage;        
//    int mp_cost;
//    string ability_info;
//};

typedef ability ab;

class Jobs {
      
    private:
        string name;
        string job_type;
        string description;
        int hp;
        int mp;
        int experience;    
        int level;
        ab ind_ability[3];
        
    public:
        Jobs() {
            name = "";
            job_type = "";
            description = "";
            hp = 0;
            mp = 0;
            experience = 0;
            level = 0;
            ind_ability[0].ability_name = "";
            ind_ability[0].damage = 0;
            ind_ability[0].mp_cost = 0;
            ind_ability[0].ability_info = "";
            ind_ability[1].ability_name = "";
            ind_ability[1].damage = 0;
            ind_ability[1].mp_cost = 0;
            ind_ability[1].ability_info = "";
            ind_ability[2].ability_name = "";
            ind_ability[2].damage = 0;
            ind_ability[2].mp_cost = 0;
            ind_ability[2].ability_info = "";
        }          

        /** Begin name functions **/
        // set the name of the job class
        void set_name(string n) {
            name = n;
        }
        
        // get the name for the job 
        // the user can change this name
        string get_name() {
            return name;
        }        
        /** End name functions **/
        
        /** Begin Job functions **/ 
        // get the job title
        string get_job() {
            return job_type;
        }
        
        // set the job title
        void set_job(string s) {
            job_type = s;
        }
        /** End of Job functions **/
        
        /** Begin Experience functions **/
        // add exp to job class upon defeating mob         
        void increase_experience(int exp_rewarded) {
            experience += exp_rewarded;
        }
        
        // set exp to job class
        void set_experience (double exp) {
            experience = exp;
        }
        
        // gets the current exp the job has attained.
        int get_experience() {
            return experience;
        }                
        /** End experience functions **/
       
        /** Begin Level functions **/
        // get the current level
        int get_level() {
            return level;
        }
        
        // set the level of the character
        void set_level(int lvl) {
            level = lvl;
        }        
        
        void increase_level() {
            experience ++;
        }
        /** End of Level functions **/
        
        /** Begin Description functions **/ 
        // set the description of the job
        void set_description(string desc) {
            description = desc;
        }
        
        // returns the description of the job class       
        string get_description() {
            return description;
        }
        /** End Description functions **/        
        
        /** Begin hp functions **/
        // set the hp of the job
        void set_hp(int health) {
            hp = health;
        }
        
        // get the hp of the job
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
        
        // job regains health upon level up or 
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
        
        // return the current mp of the job
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
//            if (ind_ability[choice].damage == 0) {
//                return get_rand(low, high);
//            }
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
        
        // get ability info
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
        
        /** End of all ability functions **/
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
        // Gives information on character while exploring
        void display_info() {            
            cout << "                   " << name << "\n";
            cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
            cout << "  HP       : " << hp << "\n";
            cout << "  MP       : " << mp << "\n";
            cout << "  EXP      : " << experience << "\n";
            cout << "  LEVEL    : " << level << "\n";
            cout << "  JOB      : " << job_type << "\n";
            cout << "  ABILITIES: \n\n";   

            for (int k = 0; k < 3; k++) { // for printing all ability props
                cout << " " << ind_ability[k].ability_name << "\n";
                cout << " ____________\n";
                cout << "  Damage : " << ind_ability[k].damage << "\n";
                cout << "  MP Cost: " << ind_ability[k].mp_cost << "\n";
                cout << "  Info   : " << ind_ability[k].ability_info << "\n\n";
            }

            cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";            
        }               
};

#endif	/* JOBS_H */

