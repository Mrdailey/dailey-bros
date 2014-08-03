/* 
 * File:   begin_adventure.h
 * Author: Michael Ryan
 *
 * Created on August 2, 2014, 8:03 PM
 */

#ifndef BEGIN_ADVENTURE_H
#define	BEGIN_ADVENTURE_H
/* 
 * Functions for beginning the journey!
 *
 *
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "mob_main.h"
#include "jobs.h"
#include "keys.h"

using namespace std;

void pause();
int get_rand(int min, int max);
void encounter_goblin(string name);
void battle_menu(string name, string mob_name); 

void begin_adventure() {
    system("cls");  // clears the screen
    
    string name;
    char decision;
    string response;
    bool selected_job = false;
    
    cout << "\n\n Your adventure has begun. You find yourself awakened all"
        " of a sudden from a     dream-like state.";        
    pause();
    cout << "\n\n Surrounded by a dense fog, "
        "you gaze around, wandering where you could be...";    
    pause();
    cout << " Mysterious Old Man: Welcome to the Dark Forest. My name is Gidian.\n"
            " Gidian: I am the Keeper of this forest. Well, that's what I like to call myself.\n"
            " Gidian: No one else really does...What is your name anyways?\n";    
    cout << "\n\n Enter your name: "; cin >> name; cin.ignore(80, '\n');
    cout << " " << name << ": My name is " << name;
    cout << "\n\n Gidian: That\'s quite an interesting name...\n Gidian: You are probably"
            " wondering why you are here. Well, so am I young adventurer.";
    pause();
    
    while (!selected_job) {
        cout << " Gidian: So, " << name << ", what kind of adventurer are you?\n";         
        cout << " (warrior)\n";
        cout << " (black mage)\n";        
        cout << " (thief)\n";
        cout << " (paladin)\n";    
        cout << "  What job do you choose? If you want to select warrior, \n type \'warrior\' and hit \'enter\': ";
        getline(cin, response);
    
        if (response == "warrior" || response == "Warrior") {                         
            Warrior job;    
            bool error = true;
            string description = job.get_description();
            while (error) {
                cout << "\n You have selected the warrior job." << description;
                cin >> decision; toupper(decision); cin.ignore(80,'\n');
                if (decision == 'y' || decision == 'Y') {
                    cout << " " << name << ": I'm a warrior.\n";
                    job.set_name(name);
                    selected_job = true;
                    error = false;
                    cout << " Gidian: Warrior\'s are like mindless beasts.\n "
                            " Gidian: But like all beasts, they too can be tamed.\n";
                } else if (decision == 'N' || decision == 'n') {
                    cout << " " << name << ": On second thought, I am definitely not a warrior.\n";  
                    pause();
                    error = false;
                    selected_job = false;
                } else {
                    selected_job = false;
                    cout << " You've pressed an incorrect key dumby...\n";                        
                }     
            }    
        } 
//            case "black mage": case "Black Mage": {
//
//            } break;
//            case "thief": case "Thief": {
//
//            } break;
//            case "paladin": case "Paladin": {
//
//            } break;
        else {
            cout << "That\'s not a real job!\n";
            pause();
        }
    } 
    cout << "\n Gidian: Really? Well let\'s just see what you can do.\n";
    encounter_goblin(name);
}
    
void encounter_goblin(string name) {
    Warrior job;
    pause();
    Goblins goblin;    
    string goblin_name = goblin.get_name();
    cout << " Gidian: " << goblin.get_description();
    cout << " " << job.get_name() << ": I better do something... this old guy just yells random things.\n";
    battle_menu(name,goblin_name);
}    

void battle_menu(string name, string mob_name) {
    Warrior job;
    Goblins mob;    
    string choice;
    string ability_name;    
    string job_ability;
    int job_dmg;
    int job_mp_cost;
    bool battle_over = false;    
    // if mob is dead battle is over
    while (!battle_over) {   
        bool flee = false;    
        bool error = false;
        do {
        for (int i = 1; i < 4; i++) {
            ability_name = job.get_ability_name(i-1);
            cout << "[" << i << "]  " << ability_name << "\n";        
        }
        cout << "Type the number or the name of the ability followed by <enter>.\n";
        getline(cin, choice);
        // choosing the first ability
        string ab_1, ab_2, ab_3;
        ab_1 = job.get_ability_name(0);
        ab_2 = job.get_ability_name(1);
        ab_3 = job.get_ability_name(2);
        if (choice == ab_1) {        
            error = false;            
            job_ability = job.get_ability_name(0);
            job_dmg = job.get_ability_damage(0);
            job_mp_cost = job.get_ability_mp_cost(0);
        } else if (choice == ab_2) {
            error = false;            
            job_ability = job.get_ability_name(1);
            job_dmg = job.get_ability_damage(1);
            job_mp_cost = job.get_ability_mp_cost(1);
        }
        else if (choice == ab_3) {
            error = false;
            battle_over = true;
            flee = true;
            cout << " " << name << " uses " << choice << "\n";
            cout << " " << name << " has fled the battle!\n What a noob!\n";            
        } else {        
            error = true;            
            cout << " Invalid option...\n\n";            
        } 
        if (flee == false) {
            cout << " " << name << " uses " << job_ability << "!\n";
            cout << " " << mob_name;
            battle_over = mob.damage_hp(job_dmg);
            cout << " The " << mob_name << " now has " << mob.get_hp() << " hit points!\n";
            if (battle_over) {
                cout << " " << name << " has defeated the " << mob_name << "!!\n";
                job.increase_experience(mob.get_reward_experience());
                cout << " " << name << " has received " << job.get_experience() << " experience points!\n";                
            }
        }            
        } while (error);
    }    
}
    
    
    
    
    
//    cout << "The Goblin mob has " << Mob.get_hp() << " hit points!" << endl;
//    cout << Mob.damage_hp(Sedon.get_warrior_ability()) << endl;
//    cout << Mob.damage_hp(Sedon.get_warrior_ability()) << endl;
//
//    cout << "The Goblin mob now has " << Mob.get_hp() << " hit points!!" << endl;
//
//    for(int j = 0; j<5; j++){
//        Sedon.increase_experience(Mob.get_reward_experience());
//    }
//
//    cout << Sedon.get_name() << " has received " << Sedon.get_experience() << " experience points!!!!!";                            


void pause () {    
    cout << "  \n\n <Enter to continue> \n";
    cin.ignore();
}    

int get_rand(int min, int max){ 
    srand(time(NULL));
    return(rand()% (max - min) + min); 
} 


#endif	/* BEGIN_ADVENTURE_H */

