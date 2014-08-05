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

struct ability {
    string ability_name;
    int damage;        
    int mp_cost;
    string ability_info;
};

typedef ability ab;

class Jobs {
      
    private:
        string name;
        string job;
        string description;
        int hp;
        int mp;
        int experience;    
        int level;
        ab ind_ability[3];
        
    public:
        Jobs() {
            name = "";
            job = "";
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
        Jobs(string job_type) {
            if (job_type == "Warrior") {
                name = "";
                job = "Warrior";
                description = "\n The brave warrior uses his strength and weapon "
                        "skills to massacre his foes.\n Select this job? Hit 'y' or 'n' and enter: ";
                hp =  50;
                mp = 20;
                experience = 0;   
                level = 1;            
                ind_ability[0].ability_name = "Sword Attack";
                ind_ability[0].damage = 8;
                ind_ability[0].mp_cost = 0;            
                ind_ability[0].ability_info = "A strong basic sword attack.";
                ind_ability[1].ability_name = "Head-bonk";
                ind_ability[1].damage = get_rand(5, 9);
                ind_ability[1].mp_cost = 2;
                ind_ability[1].ability_info = "A strong head bash. Ouch.";
                ind_ability[2].ability_name = "Flee";
                ind_ability[2].damage = 0;
                ind_ability[2].mp_cost = 0;
                ind_ability[2].ability_info = "Run from the battle.";
            } else if (job_type == "Black Mage") {
                name = "";
                job = "Black Mage";
                description = "\n The powerful black mage unleashes spells to devastate his foes.\n"
                        " Select this job? Hit 'y' or 'n' and 'enter': ";
                hp = 40;
                mp = 40;
                experience = 0;
                level = 1;
                ind_ability[0].ability_name = "Surge";
                ind_ability[0].damage = get_rand(8,12);
                ind_ability[0].mp_cost = 5;
                ind_ability[0].ability_info = "Releases a powerful non-elemental burst of energy.";
                ind_ability[1].ability_name = "Staff-yack";
                ind_ability[1].damage = get_rand(3,5);
                ind_ability[1].mp_cost = 0;
                ind_ability[1].ability_info = "A forceful swing of the staff oughta do the trick.";
                ind_ability[2].ability_name = "Flee";
                ind_ability[2].damage = 0;
                ind_ability[2].mp_cost = 0;
                ind_ability[2].ability_info = "Run from the battle.";                
            } else if (job_type == "Thief") {
                name = "";
                job = "Thief";
                description = "\n The agile thief uses his cunning and agility to overcome his foes.\n"
                        " Select this job? Hit 'y' or 'n' and 'enter': ";
                hp = 44;
                mp = 22;
                experience = 0;
                level = 1;
                ind_ability[0].ability_name = "Double Stab-jab";
                ind_ability[0].damage = get_rand(4,12);
                ind_ability[0].mp_cost = 3;
                ind_ability[0].ability_info = "A sudden two strikes that can be lethal.";
                ind_ability[1].ability_name = "Stealth";
                ind_ability[1].damage = 0;
                ind_ability[1].mp_cost = 0;
                ind_ability[1].ability_info = "Hide from sight and increase the damage of the next attack.";
                ind_ability[2].ability_name = "Flee";
                ind_ability[2].damage = 0;
                ind_ability[2].mp_cost = 0;
                ind_ability[2].ability_info = "Run from the battle.";
            } else {
                name = "";
                job = "Paladin";
                description = "\n The noble paladin is a master of both weaponry and holy magic.\n"
                        " Select this job? Hit 'y' or 'n' and 'enter': ";
                hp = 50;
                mp = 25;
                experience = 0;
                level = 1;
                ind_ability[0].ability_name = "Holy Strike";
                ind_ability[0].damage = 8;
                ind_ability[0].mp_cost = 0;
                ind_ability[0].ability_info = "A magical strike that deals consistent damage.";
                ind_ability[1].ability_name = "Atonement";
                ind_ability[1].damage = get_rand(5,10);
                ind_ability[1].mp_cost = 3;
                ind_ability[1].ability_info = "Channels holy energy into a blade to damage enemies.";
                ind_ability[2].ability_name = "Flee";
                ind_ability[2].damage = 0;
                ind_ability[2].mp_cost = 0;
                ind_ability[2].ability_info = "Run from the battle.";                  
            }
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
            return job;
        }
        
        // set the job title
        void set_job(string s) {
            job = s;
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

class Warrior : public Jobs {
    
    private:
        string name;
        string job;
        string description;
        int hp;
        int mp;
        int experience;    
        int level;
        ab ind_ability[3];
        
    public:
        Warrior() : Jobs("Warrior") {

        }
};

class BlackMage : public Jobs {
    
    private:
        string name;
        string job;
        string description;
        int hp;
        int mp;
        int experience;    
        int level;
        ab ind_ability[3];
        
    public:
        BlackMage() : Jobs("Black Mage") {
            
        }
};

class Thief : public Jobs {
        
    private:
        string name;
        string job;
        string description;
        int hp;
        int mp;
        int experience;    
        int level;
        ab ind_ability[3];
        
    public:
        Thief() : Jobs("Thief") {
            
        }
};

class Paladin : public Jobs {
        
    private:
        string name;
        string job;
        string description;
        int hp;
        int mp;
        int experience;    
        int level;
        ab ind_ability[3];
    
    public:    
        Paladin() : Jobs("Paladin") {
                      
        }
};

#endif	/* JOBS_H */

