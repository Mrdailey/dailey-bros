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

using namespace std;


void pause();
bool movement();
void draw_map(char maze[][25]);
int get_rand(int min, int max);
bool encounter_goblin();
bool encounter_skeleton_warrior();
bool encounter_giant_tree_frog();
bool your_dead();
void battle_menu(string mob_name); 
void edge_of_map();
void exit_game();
void set_job(string job_type);
void set_mob(string mob_type);
void level_up();

//declare booleans for exiting purposes.
bool game_over = false;
bool game_active = true;
string error_message = " You can\'t seem to follow simple instructions, can you?\n";

Mobs mob;
Jobs job;

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
    string description;
    string job_type;
    string mob_type;
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
        job.set_name(name);
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
            
            // case of the user picking a warrior.
            if (response == "warrior" || response == "Warrior") {                                         
                job_type = "Warrior";
                set_job(job_type);
                description = job.get_description();
                
                do {                                
                    cout << "\n You have selected the warrior job." << description;
                    cin >> decision; cin.ignore(80, '\n');
                    cout << "\n";
                    
                    // confirm decision
                    if (decision == 'Y' || decision == 'y') {
                        cout << " " << name << ": I'm a warrior.\n";                        
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
                        cout << error_message;                        
                    }     
                } while (error);    
                
            } else if (response == "black mage" || response == "Black Mage") {    
                job_type = "Black Mage";
                set_job(job_type);
                description = job.get_description();
                do {
                    cout << "\n You have selected the black mage job." << description;
                    cin >> decision; cin.ignore(80, '\n');
                    cout << "\n";
                    // confirm job choice
                    if (decision == 'Y' || decision == 'y') {
                        
                        cout << " " << name << ": I'm a black mage.\n";                        
                        selected_job = true;
                        error = false;
                        cout << " Gidian: Black Mage\'s are very powerful beings!\n"
                                " Gidian: You should go first.\n";
                        // changing of the mind
                    } else if (decision == 'N' || decision == 'n') {
                        
                        cout << " " << name << ": Gotcha! I'm not a black mage.\n";
                        pause();                        
                        error = false;
                        selected_job = false;                        
                    } else {
                        
                        selected_job = false;
                        cout << error_message;
                    }
                } while (error);                
                
            } else if (response == "thief" || response == "Thief") {
                job_type = "Thief";
                set_job(job_type);
                description = job.get_description();
                do {
                    cout << "\n You have selected the thief job." << description;
                    cin >> decision; cin.ignore(80, '\n');
                    cout << "\n";
                    
                    // confirm job choice
                    if (decision == 'Y' || decision == 'y') {
                        cout << " " << name << ": I'm a thief.\n";                        
                        selected_job = true;
                        error = false;
                        cout << " Gidian: A thief, how wonderful! I may have a use for you.\n"
                                " Gidian: Have you ever tried stealing from a king? *winks*\n";
                        
                        // changing of the mind
                    } else if (decision == 'N' || decision == 'n') {
                        cout << " " << name << ": There\'s no way I\'m a thief!\n";
                        pause();                        
                        error = false;
                        selected_job = false;     
                        
                    } else {
                        selected_job = false;
                        cout << error_message;
                    }                    
                } while (error);
                
            } else if (response == "paladin" || response == "Paladin") {
                job_type = "Paladin";
                set_job(job_type);
                description = job.get_description();
                do {
                    cout << "\n You have selected the paladin job." << description;
                    cin >> decision; cin.ignore(80, '\n');
                    cout << "\n";
                    
                    // confirm job choice
                    if (decision == 'Y' || decision == 'y') {
                        cout << " " << name << ": I'm a paladin.\n";                        
                        selected_job = true;
                        error = false;
                        cout << " Gidian: A Mister Goody-Two-Shoes, eh?\n"
                                " Gidian: Listen, you answer to me now, got it?!\n";
                        // changing of the mind
                        
                    } else if (decision == 'N' || decision == 'n') {
                        cout << " " << name << ": You fell for it! I\'m no paladin!\n";
                        pause();                        
                        error = false;
                        selected_job = false;         
                        
                    } else {
                        selected_job = false;
                        cout << error_message;
                    }                    
                } while (error);
            } else { // They did something wrong.
                cout << "That\'s not a real job!\n";
                pause();
            }
            job.set_ability_name(2, "Flee");
            job.set_ability_damage(2, 0);
            job.set_ability_mp_cost(2, 0);
            job.set_ability_info(2, "Run from the battle.");    
        } 
        cout << "\n Gidian: There\'s a random goblin just standing over there.\n"
                " Gidian: How convenient. I wonder if he wants to play?";
        pause();        
        cout << " Gidian: Well let\'s just see what you can do, " << name << ".";
        
        // begin first encounter with the goblin class!
        if (encounter_goblin() == true) { // if the character is dead, return false!
            cout << " Gidian: Wow. You really showed that goblin how to bake bread!\n";
            cout << " Gidian: So where do you want to go from here?\n\n";             
            
        } else {
            exit_game();
        }

        pause();    
        game_active = movement(); // begin exploring the forest!
        // If false, return to main menu
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
bool movement() {
    string move_to_position;
    string name = job.get_name();
    bool exploring = true;
    char maze[25][25] = {'-'}; // build a 2D array of 25 by 25 -'s
    int row,col;
    for (row = 0; row < 25; row++) {
        
        for (col = 0; col < 25; col++) {            
            maze[col][row] = '-';              
        }
    }
    int spaces = 0;
    maze[10][10] = 'X';
    int x_pos = 10, y_pos = 10;
    draw_map(maze); // initialize map with o's, X being the character.
    while (exploring) { // until user types exit or quit 
        
        cout << " Gidian: Where to next, " << name << "?\n";
        cout << " Type in either \'move left\', move \'right\', etc...\n";
        cout << " Press \'C\' to display character information.\n";
        getline(cin, move_to_position); // choose which direction to go

        if (move_to_position == "move up") { // character moves up
            
            if (y_pos - 1 >= 0) { // character cannot leave the grid with this here
                system("cls"); // clear the screen upon movement
                maze[x_pos][y_pos] = 'o'; // trace your movement with circles
                y_pos--;
                maze[x_pos][y_pos] = 'X'; // move the x to new value
                draw_map(maze);
                spaces++;
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
                spaces++; // increment spaces to generate battles!
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
                draw_map(maze); // calls function draw_map to construct a new maze.               
                spaces++;
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
                spaces++;
                cout << " " << name << " journeys deeper east into the \n"
                        "\"Forest of the Dark Things That Hurt Good People.\"\n"; 
            } else {
                edge_of_map();
            }
            
        } else if (move_to_position == "C" || move_to_position == "c") {
            job.display_info(); // all character info that is currently in the system
            pause();
            
        } else if (move_to_position == "quit" || move_to_position == "exit") {// user types quit or exit
            char goodbye;
            bool error;
            
            do { 
                error = true;                
                cout << " Are you sure you want to exit the game?\n";
                cout << " Y/N: ";
                cin >> goodbye; cin.ignore(80, '\n');
                
                if (goodbye == 'Y' || goodbye == 'y') { // if they're sure they want to leave
                    exploring = false;
                    error = false;
                    
                } else if (goodbye == 'N' || goodbye == 'n') { // they changed their mind, np
                    exploring = true;
                    error = false;
                    
                } else { // they pressed an incorrect key                                                                      
                    exploring = true;
                    error = true;                        
                }
            } while (error);   
            
        } else { // character movement invalid
            
            if (move_to_position != "") {
                cout << " Gidian: Up, Down, Left, or right! Let's move " << name << "!!\n\n";
            }
        }    
        if (exploring) {
            if (spaces % 12 == 0 && spaces != 0) {
                system("cls");
                cout << " Gidian: Here we go " << name << "!\n"
                        " Gidian: Let\'s show \'em what we\'re made of!\n";
                exploring = encounter_goblin();
            } else if (spaces % 7 == 0 && spaces != 0) {
                system("cls");
                cout << " Gidian: No more picking berries " << name << "!\n"
                        " Gidian: I am an old man, remember!\n";
                exploring = encounter_skeleton_warrior();
            } else if (spaces % 9 == 0 && spaces !=0) {                
               system("cls");
               exploring = encounter_giant_tree_frog(); 
            } else if (spaces == 19 || spaces == 17 || spaces == 23) {
//                found_item();
            }   
        }        
    }    
    return exploring;
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
 * @return bool if user died during the encounter
 */
bool encounter_goblin() {      
    string mob_type;
    pause();
    string name = job.get_name();
    mob_type = "Goblins";
    set_mob(mob_type);
    string goblin_name = mob.get_name();
    cout << " Gidian: " << mob.get_description();
    cout << " " << name << ": I better do something... this goblin looks like he's mad.\n";
    pause();
    // Initiate the battle !!!
    battle_menu(goblin_name);
    if (your_dead()) {
        return false;        
    }
    level_up();
    return true;
}    

/**
 * 
 * @return bool if user lived through the encounter 
 */
bool encounter_skeleton_warrior() {       
    pause();
    string mob_type;
    string name = job.get_name();
    mob_type = "Skeleton Warrior";
    set_mob(mob_type);
    string skeleton_name = mob.get_name();
    cout << " Gidian: " << mob.get_description();
    cout << " " << name << ": Time to turn these dry bones to dust!\n";
    pause();
    // Initiate the battle!
    battle_menu(skeleton_name);
    if (your_dead()) {
        return false;
    }
    level_up();
    return true;
}

bool encounter_giant_tree_frog() {
    pause();
    string mob_type;
    string name = job.get_name();
    mob_type = "Giant Tree Frog";
    set_mob(mob_type);
    string giant_tree_frog_name = mob.get_name();
    cout << " Gidian: " << mob.get_description();
    cout << " " << name << ": Is that a hippo or a frog?!?!\n";
    pause();
    // Start the battle!
    battle_menu(giant_tree_frog_name);
    if (your_dead()) {
        return false;        
    }
    level_up();
    return true;
}

/**
 * 
 * @return bool true if you're dead! 
 */
bool your_dead() {
    if (job.get_hp() <= 0) {        
        cout << "*********************************\n";
        cout << "*                               *\n";
        cout << "*                               *\n";
        cout << "*       G A M E  O V E R        *\n";
        cout << "*                               *\n";
        cout << "*                               *\n";
        cout << "*********************************\n";
        return true;
    } 
return false;    
}

/**
 * Battle Menu for an encounter.
 * 
 * @param string name The name the user has set.
 * @param string mob_name The name of the mob being fought.
 */
void battle_menu(string mob_name) {    
    system("cls");    
    string name = job.get_name();
    string choice;      
    string job_ability_name;
    int hp_gained = mob.get_hp() * .20;
    int mp_gained = mob.get_mp() * .15;
    int job_ability_dmg;
    int ability_type;
    int job_ability_mp_cost;
    string job_ability_info;
    int job_ability_heal;
    bool battle_over = false;    
    // reset the thief's damage on his boosted ability
    if (job.get_job() == "Thief") {
         job.set_ability_damage(0, 7);
    }
    cout << " " << name << " has encountered a " << mob_name << "!!\n\n";
    // if mob is dead battle is over
    while (!battle_over) {           
        int stealth_counter = 0;
        bool flee = false;    
        bool error = false;
        bool tried_to_run = false;
        do {            
            cout << " " << name << " HP: " << job.get_hp() << "    MP: " << job.get_mp(); 
            cout << " " << mob_name << " HP: " << mob.get_hp() << "    MP: " << mob.get_mp() << "\n\n";
            int cap = 4;
            if (job.get_level() == 2) {
                cap = 5;
            }
            for (int i = 1; i < cap; i++) {                
                cout << "[" << i << "]  " << job.get_ability_name(i-1) << "\n";        
            }
            cout << "What will " << name << " do?\n";
            getline(cin, choice);              
            string ab_1, ab_2, ab_3, ab_4;
            ab_1 = job.get_ability_name(0);
            ab_2 = job.get_ability_name(1);
            ab_3 = job.get_ability_name(2);
            ab_4 = job.get_ability_name(3);
            // choosing the first ability
            if (choice == ab_1 || choice == "1") {        
                error = false;    
                tried_to_run = false;
                job_ability_name = job.get_ability_name(0);                
                job_ability_dmg = job.get_ability_damage(0);
                job_ability_mp_cost = job.get_ability_mp_cost(0);
                job_ability_info = job.get_ability_info(0);
                job.decrease_mp(job_ability_mp_cost);  
                if (job.get_mp() < 0) { // test to see if the character has enough mana first
                    cout << " Not enough mana to use that ability!\n";
                    job.increase_mp(job_ability_mp_cost); // if not then reset the mp
                    error = true;
                }                
                // choosing the second ability
            } else if (choice == ab_2 || choice == "2") {
                error = false;       
                tried_to_run = false;
                job_ability_name = job.get_ability_name(1);
                job_ability_dmg = job.get_ability_damage(1);
                job_ability_mp_cost = job.get_ability_mp_cost(1);
                job_ability_info = job.get_ability_info(1);
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
                
            } else if (choice == ab_4 || choice == "4") {
              error = false;
              tried_to_run = false;
              job_ability_name = job.get_ability_name(3);
              job_ability_dmg = job.get_ability_damage(3);
              job_ability_mp_cost = job.get_ability_mp_cost(3);
              job_ability_info = job.get_ability_info(3);
              job_ability_heal = job.get_ability_heal(3);
              job.decrease_mp(job_ability_mp_cost);
              if (job.get_mp() < 0) {
                  cout << " Not enough mana to use that ability!\n";
                  job.increase_mp(job_ability_mp_cost);
                  error = true;
              }
              // You don't know what you're doing anymore.
            } else {        
                error = true;                   
                cout << " Invalid option... Please just do what I tell you to.\n\n";            
            } 
            // if the user DIDNT flee AND DIDNT try to run AND there was no ERROR with ability mp cost
            if (flee == false && tried_to_run == false && error == false) {
                cout << " " << name << " uses " << job_ability_name << "!\n";
                if (job_ability_name == "Stealth") {
                    cout << " " << name << " enters the shadows unseen.\n";
                } else if (job_ability_name == "Defend") {
                    cout << " " << name << " raises his shield for the next blow!\n";                    
                } else if(job_ability_name == "Redemptive Light") {
                    cout << " " << name << " calls down the light of Redemption!\n";
                    job.increase_hp(job_ability_heal);
                    cout << " " << name << " gains " << job_ability_heal << " health!\n";
                } else {
                    cout << " " << mob_name;
                    battle_over = mob.damage_hp(job_ability_dmg);
                    cout << " The " << mob_name << " now has " << mob.get_hp() << " hit points!\n";
                }
                // if the mob is dead!
                if (battle_over) {
                    cout << " " << name << " has defeated the " << mob_name << "!!\n";
                    job.increase_experience(mob.get_exp_reward());
                    cout << " " << name << " has received " << mob.get_exp_reward() << " experience points!\n";                
                    job.increase_hp(hp_gained);
                    job.increase_mp(mp_gained);
                    pause();
                } else {                  
                    // giant tree frog will use consume to heal below 10 hp
                    if (mob_name == "Giant Tree Frog" && mob.get_hp() < 10) {
                        ability_type = 1;
                        mob.increase_hp(mob.get_ability_heal(1));
                    } else {
                        ability_type = 0;// always uses first ability unless out of mana                                            
                    }
                    mob.decrease_mp(mob.get_ability_mp_cost(ability_type));  
                     // if the mob doesnt have enough mp for first ability, use other ability
                    if (mob.get_mp() < 0) {
                        mob.increase_mp(mob.get_ability_mp_cost(ability_type));
                        ability_type = 1;          
                        if (mob_name == "Giant Tree Frog") {
                            ability_type = 0;
                        }
                    }                             
                    cout << mob.get_ability_info(ability_type);
                    if (job_ability_name == "Stealth") {
                        stealth_counter ++;
                        cout << " " << mob_name << " cannot find " << name << "!\n";
                        cout << " " << name << " is hiding in the shadows.\n";
                        job.set_ability_damage(0, job.get_ability_damage(0) + stealth_counter);                        
                    } else if(job_ability_name == "Defend") {
                        cout << " " << name;
                        game_over = job.damage_hp((mob.get_ability_damage(ability_type)) * .50);
                        cout << " " << name << " now has " << job.get_hp() << " hit points!\n\n";    
                    } else {
                        cout << " " << name;
                        game_over = job.damage_hp((mob.get_ability_damage(ability_type)));
                        cout << " " << name << " now has " << job.get_hp() << " hit points!\n\n";                          
                    }
                                                                                                                                       
                }
                if (game_over) {
                    cout << " " << name << " has been defeated by " << mob_name << "!!\n";
                    battle_over = true;
                }
            } // end if char didnt flee, didnt try to flee, and no error with mp cost condition
            
        } while (error); // end do while loop
        
        // Successful Flee!!! Will exit battle!
        if (flee == true) {
            cout << "\n Successfully fled from the " << mob_name << "!!\n";
            cout << "\n Gidian: Brave sir " << name << " ran away! Bravely ran away, away!\n"
                    " Gidian: When danger reared it's ugly head, he bravely turned his tail and fled!\n";
            cout << " " << name << ": No wonder this guy is all alone out here...\n";        
        } 
        
        // after double stab is used reset it's damage boost.
        if (job.get_job() == "Thief" && job_ability_name == "Double Stab-jab") {
            job.set_ability_damage(0, 7);
        }
    }  // end while (!battle_over) loop 
   
    system("cls");
} // end of function

// used for spacing and pauses for an enter key
void pause () {    
    cout << "  \n\n <Enter to continue> \n";
    cin.ignore();
}    


/**
 * @param int min
 * @param int max
 * @return int random between the min and max
 */
int get_rand(int min, int max){ 
    srand(time(NULL));
    return(rand()% (max - min) + min); 
} 

// Exits the game if a condition is met.
void exit_game() {    
    game_active = false;
}

/**
 * Sets all of the values for the job the user has selected.
 * 
 * @param string job_type The name of the job to pass in
 */
void set_job(string job_type) {
    // The Warrior job
    if (job_type == "Warrior") {        
        job.set_job(job_type);
        job.set_description("\n The brave warrior uses his strength and weapon "
                "skills to massacre his foes.\n Select this job? Hit 'y' or 'n' and 'enter': ");          
        job.set_hp(50);                    
        job.set_mp(20);
        job.set_experience(0);
        job.set_level(1);

        job.set_ability_name(0, "Sword Attack");
        job.set_ability_damage(0, 8);
        job.set_ability_mp_cost(0, 0);
        job.set_ability_info(0, "A strong basic sword attack.");

        job.set_ability_name(1, "Head-bonk");
        job.set_ability_damage(1, 9); // dmg 5-9
        job.set_ability_mp_cost(1, 2);
        job.set_ability_info(1, "A strong head bash. Ouch.");
        // The Black Mage Job
    } else if (job_type == "Black Mage") {        
        job.set_job(job_type);
        job.set_description("\n The powerful black mage unleashes spells to devastate his foes.\n"
                    " Select this job? Hit 'y' or 'n' and 'enter': ");          
        job.set_hp(40);                    
        job.set_mp(40);
        job.set_experience(0);
        job.set_level(1);

        job.set_ability_name(0, "Surge");
        job.set_ability_damage(0, 15); // dmg 7-15
        job.set_ability_mp_cost(0, 5);
        job.set_ability_info(0, "Releases a powerful non-elemental burst of energy.");

        job.set_ability_name(1, "Staff-yack");
        job.set_ability_damage(1, 4);
        job.set_ability_mp_cost(1, 0);
        job.set_ability_info(1, "A forceful swing of the staff oughta do the trick.");  
        // The Thief Job
    } else if (job_type == "Thief") {        
        job.set_job(job_type);
        job.set_description("\n The agile thief uses his cunning and agility to overcome his foes.\n"
                    " Select this job? Hit 'y' or 'n' and 'enter': ");          
        job.set_hp(44);                    
        job.set_mp(22);
        job.set_experience(0);
        job.set_level(1);

        job.set_ability_name(0, "Double Stab-jab");
        job.set_ability_damage(0, 7);
        job.set_ability_mp_cost(0, 0);
        job.set_ability_info(0, "A sudden two strikes that can be lethal.");

        job.set_ability_name(1, "Stealth");
        job.set_ability_damage(1, 0);
        job.set_ability_mp_cost(1, 5);
        job.set_ability_info(1, "Hide from sight and increase the damage of the next attack. Can be used additively.");    
        // The Paladin Job
    } else if (job_type == "Paladin") {        
        job.set_job(job_type);
        job.set_description("\n The noble paladin is a master of both weaponry and holy magic.\n"
                    " Select this job? Hit 'y' or 'n' and 'enter': ");          
        job.set_hp(50);                    
        job.set_mp(25);
        job.set_experience(0);
        job.set_level(1);

        job.set_ability_name(0, "Holy Slash");
        job.set_ability_damage(0, 8);
        job.set_ability_mp_cost(0, 0);
        job.set_ability_info(0, "A magical strike that deals consistent damage.");

        job.set_ability_name(1, "Atonement");
        job.set_ability_damage(1, 11);
        job.set_ability_mp_cost(1, 3);
        job.set_ability_info(1, "Channels holy energy into a blade to damage enemies.");        
    }
}

/**
 * Will set all the values necessary to load the mob.
 * 
 * @param string mob_type The mob to be loaded.
 */
void set_mob(string mob_type) {
    // The Skeleton Warrior mob type
    if (mob_type == "Skeleton Warrior") {
        mob.set_name("Skeleton Warrior");
        mob.set_description("Skeleton Warriors may be small and bony, but they "
                    "can swing a sword like nobody's business!\n");
        mob.set_hp(25);
        mob.set_mp(8);
        mob.set_exp_reward(15);

        mob.set_ability_name(0, "Bone Hammer");
        mob.set_ability_damage(0, get_rand(4, 7));
        mob.set_ability_mp_cost(0, 4);
        mob.set_ability_info(0, " The skeleton warrior snaps his leg off and hammers it down!\n"); 
        
        mob.set_ability_name(1, "Bone Sword");
        mob.set_ability_damage(1, get_rand(3, 6));
        mob.set_ability_mp_cost(1, 0);
        mob.set_ability_info(1, " Skeleton Warrior breaks off his arm and uses it as a sword!\n");
        // The Goblin mob type
    } else if (mob_type == "Goblins") {
    mob.set_name("Goblin");
    mob.set_description("The nasty Goblin race is after many things, but most of all"
            " is after   your money!\n");
    mob.set_hp(20);
    mob.set_mp(5);
    mob.set_exp_reward(10);

    mob.set_ability_name(0, "Fire");
    mob.set_ability_damage(0, get_rand(4, 6));
    mob.set_ability_mp_cost(0, 3);
    mob.set_ability_info(0, " The goblin unleashes a surge of fire!\n");
    
    mob.set_ability_name(1, "Goblin Toss");    
    mob.set_ability_damage(1, get_rand(3, 4));
    mob.set_ability_mp_cost(1,0);    
    mob.set_ability_info(1, " The goblin grabs an item from his sack and tosses it!\n");      
    // The Giant Tree Frog mob type
    } else if (mob_type == "Giant Tree Frog") {
        mob.set_name("Giant Tree Frog");
        mob.set_description("This strange creature is both intimidating and extremely fond of"
        " small bugs.\n");
        mob.set_hp(22);
        mob.set_mp(0);
        mob.set_exp_reward(15);
        
        mob.set_ability_name(0, "Leap of Death");
        mob.set_ability_damage(0, get_rand(4, 6));
        mob.set_ability_heal(0, 6);
        mob.set_ability_mp_cost(0, 0);
        mob.set_ability_info(0, " The Giant Tree Frog leaps forward and lands on it's belly!\n");
        
        mob.set_ability_name(1, "Consume");
        mob.set_ability_damage(1, 0);
        mob.set_ability_heal(1, 12);
        mob.set_ability_mp_cost(1, 0);
        mob.set_ability_info(1, " The Giant Tree Frog consumes a nearby bug and restores its health!\n");
        
    }
}

void level_up() {
    // initialize levels from 1-20

    int level_exp[21] = {
        0, 50, 125, 225, 350, 500, 675, 875, 1100, 1350, 1625,
        1925, 2250, 2600, 2975, 3375, 3800, 4250, 4725, 5525, 6050
    };            
            
    for (int k = 1; k < 21; k++) {                                                                                                                                                                                                                                                         
        
        // If their experience is higher than the experience required and they 
        // are not already that level.
        if (job.get_experience() > level_exp[k] && job.get_level() != k+1) {
            job.increase_level();

            cout << " " << job.get_name() << " is now level " << job.get_level() << "!\n";        
            // Level 2
            if (job.get_level() == 2) {
                
                // Warrior levels up
                if (job.get_job() == "Warrior") {
                                     
                    job.set_hp(60);
                    job.set_mp(23);
                    // NEW ABILITY!!                    
                    job.set_ability_name(3, "Defend");
                    job.set_ability_damage(3, 0);
                    job.set_ability_mp_cost(3, 0);
                    job.set_ability_info(3, "Braces for next attack and reduces incoming damage.\n");                
                    
            // Black Mage level up stuffs
                } else if (job.get_job() == "Black Mage") {                                      
                    job.set_hp(45);
                    job.set_mp(48);      
                    // NEW ABILITY!~
                    job.set_ability_name(3, "Flame");
                    job.set_ability_damage(3, 16);
                    job.set_ability_mp_cost(3, 6);
                    job.set_ability_info(3, "Engulfs the enemy in flames.\n");
                    
                // Thief levels up 
                } else if (job.get_job() == "Thief") {
                    job.set_hp(50);
                    job.set_mp(25);
                    // NEW ABILITY!!
                    job.set_ability_name(3, "Low Blow");
                    job.set_ability_damage(3, 10);
                    job.set_ability_mp_cost(3, 2);
                    job.set_ability_info(3, "Dashes quickly to deliver a sudden cheap shot.\n");                        
                    
                // Pally levels up 
                } else if(job.get_job() == "Paladin") {
                    job.set_hp(60);
                    job.set_mp(35);
                    // NEW ABILITY!!
                    job.set_ability_name(3, "Redemptive Light");
                    job.set_ability_damage(3, 0);
                    job.set_ability_heal(3, 15);
                    job.set_ability_mp_cost(3, 5);
                    job.set_ability_info(3, "The power of redemption restores the Paladin's health.");
                }
                cout << " " << job.get_name() << " has learned the new ability " << job.get_ability_name(3) << "!\n";
            }
        }                                
    }
}    
#endif	/* BEGIN_ADVENTURE_H */

