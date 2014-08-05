/* 
 * File:   begin_adventure.h
 * Author: Michael Ryan
 *
 * Created on August 2, 2014, 8:03 PM
 */

#ifndef BEGIN_ADVENTURE_H
#define	BEGIN_ADVENTURE_H

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "jobs.h"
#include "mob_main.h"

using namespace std;
bool game_over = false;
bool game_active = true;
void pause();
void movement();
void draw_map(char maze[][25]);
int get_rand(int min, int max);
bool encounter_goblin();
void battle_menu(string mob_name); 
void edge_of_map();
void exit_game();
void display_info();

Warrior job;
//BlackMage job;
//Thief job;
//Paladin job;

/**
 * In order to test a certain class, simply comment out the Warrior job line above
 * and take away the comment marks on the job you choose to test.
 * Also change the first if (response == "warrior" || response == "Warrior") to
 * the job name you are testing.
 * 
 */
/**
 * The adventure will take place in this function!
 * Most of the story elements and decisions will be made here.
 * It will call several functions throughout, like movement
 * and encounter_mob.
 * 
 * "The Forest of the Dark Things That Hurt Good People"
 *  
 */    
void begin_adventure() {
//    system("cls");  // clears the screen
    while (game_active) {
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
                " Gidian: I\'m the Keeper of this forest. Well, that's what I like to call myself.\n"
                " Gidian: No one else really does...What is your name anyways?\n";    
        cout << "\n\n Enter your name: "; cin >> name; cin.ignore(80, '\n');
        cout << " " << name << ": My name is " << name;
        pause();
        cout << " Gidian: That\'s quite an interesting name...\n"
                " Gidian: You are probably wondering why you are here.\n"
                " Gidian: Well, so am I young adventurer.";    
        pause();
        cout << " Gidian: If you stick with me, you\'ll be able to skip stones"
                " in any \n country before no time.";
        pause();
        // This is the loop where the user picks their job Class to load.
        while (!selected_job) {
            bool error = true;
            cout << " Gidian: So, " << name << ", what kind of adventurer are you?\n\n";         
            cout << " (warrior)\n";
            cout << " (black mage)\n";        
            cout << " (thief)\n";
            cout << " (paladin)\n\n";    
            cout << " What job do you choose?\n"
                    " If you want to select warrior, type \'warrior\' and hit \'enter\': ";
            getline(cin, response);
//            cin >> response; cin.ignore(80, '\n');
            // case of the user picking a warrior.
            if (response == "warrior" || response == "Warrior") {                         

                string description = job.get_description();
                while (error) {
                    cout << "\n You have selected the warrior job." << description;
                    cin >> decision; cin.ignore(80, '\n');
                    cout << "\n";
                    // confirm decision
                    if (decision == 'Y' || decision == 'y') {
                        cout << " " << name << ": I'm a warrior.\n";
                        job.set_name(name);
                        selected_job = true;
                        error = false;
                        cout << " Gidian: Warrior\'s are like mindless beasts.\n"
                                " Gidian: But like all beasts, they too can be tamed.\n";
                        // changing your mind is okay!
                    } else if (decision == 'N' || decision == 'n') {
                        cout << " " << name << ": On second thought, I am definitely not a warrior.\n";  
                        pause();
                        error = false;
                        selected_job = false;
                        // Users are idiots, so...
                    } else {
                        selected_job = false;
                        cout << " You can\'t seem to follow simple instructions, can you?\n";                        
                    }     
                }    
            } else if (response == "black mage" || response == "Black Mage") {
                
            } else if (response == "thief" || response == "Thief") {
                
            } else if (response == "paladin" || response == "Paladin") {
                
            } else { // They did something wrong.
                cout << "That\'s not a real job!\n";
                pause();
            }
        } 
        cout << "\n Gidian: There\'s a random goblin just standing over there.\n"
                " Gidian: How convenient. I wonder if he wants to play?";
        pause();        
        cout << " Gidian: Well let\'s just see what you can do, " << name << ".\n";
        // begin first encounter with the goblin class!
        if (encounter_goblin() == true) { // if the character is dead, return false!
            cout << " Gidian: Wow. You really showed that goblin how to bake bread!\n";
            cout << " Gidian: So where do you want to go from here?\n\n"; 
            cout << " " << name << " has " << job.get_experience() << "\n";        
        } else {
            exit_game();
        }

        pause();    
        movement(); // begin exploring the forest!        
    }
}

/**
 * Creates the map the user will be exploring!!
 * 
 * "Forest of the Dark Things That Hurt Good People"
 */
void draw_map(char maze[][25]) {
    for (int row = 0; row < 25; row++) {
        for (int col = 0; col < 25; col++) {
            cout << maze[col][row];
        }
        cout << endl;
    }
}

/**
 * Handles character movement and navigation of the map.
 * @param string name The name of the user.
 */
void movement() {
    string move_to_position;
    string name = job.get_name();
    char maze[25][25] = {'-'}; // build a 2D array of 25 by 25 o's
    int row,col;
    for (row = 0; row < 25; row++) {
        for (col = 0; col < 25; col++) {            
            maze[col][row] = '-';            
        }
    }
    maze[10][10] = 'X';
    int x_pos = 10, y_pos = 10;
    draw_map(maze); // initialize map with o's, X being the character.
    while (true) { //  empty loops runs indefinitely  
        int spaces = 0;
        for (spaces = 0; spaces <= 5; spaces++) {
            cout << " Gidian: Where to next, " << name << "?\n";
            cout << " Type in either \'move left\', move \'right\', etc...\n";
            cout << " Press \'C\' to display character information.\n";
            getline(cin, move_to_position); // choose which direction to go
    //        cin >> move_to_position; cin.ignore(80, '\n');
            if (move_to_position == "move up") { // character moves up
                if (y_pos - 1 >= 0) { // character cannot leave the grid with this here
                    system("cls"); // clear the screen upon movement
                    maze[x_pos][y_pos] = 'o'; // erase X where the character was
                    y_pos--;
                    maze[x_pos][y_pos] = 'X'; // move the x to new value
                    draw_map(maze);
                    cout << " " << name << " journeys to the distant north of the \n"
                            "\"Forest of the Dark Things That Hurt Good People.\"\n";                    
                } else {
                    edge_of_map();
                } 
            } else if (move_to_position == "move down") { // character moves down
                if (y_pos + 1 < 25) {
                    system("cls");
                    maze[x_pos][y_pos] = 'o';
                    y_pos++;
                    maze[x_pos][y_pos] = 'X';
                    draw_map(maze);
                    cout << " " << name << " journeys further south into the \n"
                            "\"Forest of the Dark Things That Hurt Good People.\"\n";                    
                } else {
                    edge_of_map();
                }
            } else if (move_to_position == "move left") { // character moves to the left
                if (x_pos - 1 >= 0) {
                    system("cls");
                    maze[x_pos][y_pos] = 'o';
                    x_pos--;
                    maze[x_pos][y_pos] = 'X';
                    draw_map(maze);
                    cout << " " << name << " journeys far west into the \n"
                            "\"Forest of the Dark Things That Hurt Good People.\"\n"; 
                } else {
                    edge_of_map();
                }
            } else if (move_to_position == "move right") { // character moves to the right
                if (x_pos +1 < 25) {   
                    system("cls");
                    maze[x_pos][y_pos] = 'o'; // where the character was
                    x_pos++;
                    maze[x_pos][y_pos] = 'X';
                    draw_map(maze);
                    cout << " " << name << " journeys deeper east into the \n"
                            "\"Forest of the Dark Things That Hurt Good People.\"\n"; 
                } else {
                    edge_of_map();
                }
            } else if (move_to_position == "C" || move_to_position == "c") {
                display_info();
            } else { // character movement invalid
                if (move_to_position != "") {
                    cout << " Gidian: Up, Down, Left, or right! Let's move " << name << "!!\n\n";
                }
            }
        }
        encounter_goblin();
    }
}

/**
 * If character reaches the edge of the map, call this function.
 */
void edge_of_map () {
    cout << " You've reached the edge of the map!\n"
            " Please move in a different direction.\n";
}

/**
 * Basic layout of the function for a goblin encounter.
 * 
 * @param string name The name the user has set.
 */
bool encounter_goblin() {    
    pause();
    string name = job.get_name();
    Goblins goblin;    
    string goblin_name = goblin.get_name();
    cout << " Gidian: " << goblin.get_description();
    cout << " " << name << ": I better do something... this old guy just yells random things.\n";
    // Initiate the battle !!!
    battle_menu(goblin_name);
    if (job.get_hp() <= 0) {        
        cout << "*********************************\n";
        cout << "*                               *\n";
        cout << "*                               *\n";
        cout << "*       G A M E  O V E R        *\n";
        cout << "*                               *\n";
        cout << "*                               *\n";
        cout << "*********************************\n";
        return false;
    }
    return true;
}    

/**
 * Battle Menu for an encounter.
 * 
 * @param string name The name the user has set.
 * @param string mob_name The name of the mob being fought.
 */
void battle_menu(string mob_name) {    
    system("cls");
    Goblins mob;   
    string name = job.get_name();
    string choice;      
    string job_ability_name;
    int job_ability_dmg;
    int ability_type;
    int job_ability_mp_cost;
    bool battle_over = false;    
    cout << " " << name << " has encountered a " << mob_name << "!!\n\n";
    // if mob is dead battle is over
    while (!battle_over) {   
        bool flee = false;    
        bool error = false;
        bool tried_to_run = false;
        do {            
            cout << " " << name << " MP: " << job.get_mp() << "    HP: " << job.get_hp(); 
            cout << " " << mob_name << " MP: " << mob.get_mp() << "    HP: " << mob.get_hp() << "\n\n";
            for (int i = 1; i < 4; i++) {                
                cout << "[" << i << "]  " << job.get_ability_name(i-1) << "\n";        
            }
            cout << "What will " << name << " do?\n";
            getline(cin, choice);              
            string ab_1, ab_2, ab_3;
            ab_1 = job.get_ability_name(0);
            ab_2 = job.get_ability_name(1);
            ab_3 = job.get_ability_name(2);
            // choosing the first ability
            if (choice == ab_1 || choice == "1") {        
                error = false;    
                tried_to_run = false;
                job_ability_name = job.get_ability_name(0);
                job_ability_dmg = job.get_ability_damage(0);
                job_ability_mp_cost = job.get_ability_mp_cost(0);
                job.decrease_mp(job_ability_mp_cost);                
                // choosing the second ability
            } else if (choice == ab_2 || choice == "2") {
                error = false;       
                tried_to_run = false;
                job_ability_name = job.get_ability_name(1);
                job_ability_dmg = job.get_ability_damage(1);
                job_ability_mp_cost = job.get_ability_mp_cost(1);
                job.decrease_mp(job_ability_mp_cost);
                if (job.get_mp() < 0) { // test to see if the character has enough mana first
                    cout << " Not enough mana to use that ability!\n";
                    job.increase_mp(job_ability_mp_cost); // if not then reset the mp
                    error = true;
                }
                // choosing to flee! Can only use in the first case...
            } else if (choice == ab_3 || choice == "3") {
                error = false;
                tried_to_run = true;                
                job_ability_name = job.get_ability_name(2);
                cout << " " << name << " uses " << job_ability_name << "\n";                
                int chance_of_fleeing = (get_rand(1, 100));
                if (chance_of_fleeing >= 30) {
                    battle_over = true;
                    flee = true;
                    cout << " " << name << " has fled the battle!\n What a noob!\n";        
                    pause();
                } else {                    
                    cout << " Gidian: Man, you suck at running away.\n"
                            " Gidian: Guess you have to fight this one out.\n";                    
                }                   
                // You don't know what you're doing anymore.
            } else {        
                error = true;                   
                cout << " Invalid option... Please just do what I tell you to.\n\n";            
            } 
            // if the user DIDNT flee AND DIDNT try to run AND there was no ERROR with ability mp cost
            if (flee == false && tried_to_run == false && error == false) {
                cout << " " << name << " uses " << job_ability_name << "!\n";
                cout << " " << mob_name;
                battle_over = mob.damage_hp(job_ability_dmg);
                cout << " The " << mob_name << " now has " << mob.get_hp() << " hit points!\n";
                
                // if the goblin is dead!
                if (battle_over) {
                    cout << " " << name << " has defeated the " << mob_name << "!!\n";
                    job.increase_experience(mob.get_reward_experience());
                    cout << " " << name << " has received " << mob.get_reward_experience() << " experience points!\n";                
                    pause();
                } else {                  
                    ability_type = 0;// always uses fire unless out of mana
                    mob.decrease_mp(mob.get_ability_mp_cost(ability_type));   
                    // if the goblin doesnt have enough mp for fire, use other ability
                    if (mob.get_mp() < 0) {
                        mob.increase_mp(mob.get_ability_mp_cost(ability_type));
                        ability_type = 1;                            
                    }                             
                    cout << " " << mob_name << " uses " << mob.get_ability_name(ability_type) << "!\n";
                    cout << " " << name;
                    game_over = job.damage_hp((mob.get_ability_damage(ability_type)));
                    cout << " " << name << " now has " << job.get_hp() << " hit points!\n";                                                                                                                                         
                }
                if (game_over) {
                    cout << " " << name << " has been defeated by " << mob_name << "!!\n";
                    battle_over = true;
                }
            }              
        } while (error); // end do while loop
        if (flee == true) {
            cout << "\n Successfully fled from the " << mob_name << "!!\n";
            cout << "\n Gidian: Brave sir " << name << " ran away! Bravely ran away, away!\n"
                    " Gidian: When danger reared it\'s ugly head, he bravely turned his tail and fled!\n";
            cout << " " << name << ": No wonder this guy is all alone out here...\n";        
        } 
    }  // end while (!battle_over) loop 
   
    system("cls");
} // end of function

// Gives information on character while exploring
void display_info() {
    string name = job.get_name();
    cout << "                   " << name << "\n";
    cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
    cout << "  HP       : " << job.get_hp() << "\n";
    cout << "  MP       : " << job.get_mp() << "\n";
    cout << "  EXP      : " << job.get_experience() << "\n";
    cout << "  LEVEL    : " << job.get_level() << "\n";
    cout << "  JOB      : " << job.get_job() << "\n";
    cout << "  ABILITIES: \n\n";   
    
    for (int k = 0; k < 3; k++) { // for printing all ability props
        cout << " " << job.get_ability_name(k) << "\n";
        cout << " ____________\n";
        cout << "  Damage : " << job.get_ability_damage(k) << "\n";
        cout << "  MP Cost: " << job.get_ability_mp_cost(k) << "\n";
        cout << "  Info   : " << job.get_ability_info(k) << "\n\n";
    }
    
    cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
    pause();
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

void exit_game() {    
    game_active = false;
}

#endif	/* BEGIN_ADVENTURE_H */

