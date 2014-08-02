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

class job {
    private:
        string job_name;        
    public:
        // idk
};
/*
 * The warrior class. Has initial hp 100, mp 20.
 * 
 * 
 */
class Warrior {
    private:
        string name;
        string description;
        int hp;
        int mp;
        int experience;    
        int level;
        
    public:
        Warrior() {
            name = "Sedon";
            description = "The brave warrior hails from the ancient land of Clouds.";
            hp =  100.0;
            mp = 20.0;
            experience = 0;   
            level = 1;
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
        string getDescription() {
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
        string get_name(string n) {
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
        
        // warrior is damaged
        
      
        
        
        
               
};

class BlackMage {
    
};

class Thief {
    
};

class Paladin {
    
};


#endif	/* JOBS_H */

