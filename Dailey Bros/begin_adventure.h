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
#include <map>
#include "jobs.h"
#include "items.h"

using namespace std;


void pause();
bool movement();
void draw_map(char maze[][25]);
int get_rand(int min, int max);
bool encounter_goblin();
bool encounter_skeleton_warrior();
bool encounter_giant_tree_frog();
bool encounter_forest_feral();
void loot_items(string name);
bool your_dead();
void battle_menu(string mob_name); 
void edge_of_map();
void exit_game();

//declare booleans for exiting purposes.
bool game_over = false;
bool game_active = true;
string error_message = " You can\'t seem to follow simple instructions, can you?\n";

Mobs mob;
Jobs job;
Items item;

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
        cout << " Gidian: That's quite an interesting name...\n"
                " Gidian: You are probably wondering why you are here.\n"
                " Gidian: Well, so am I young adventurer.";    
        pause();
        cout << " Gidian: If you stick with me, you'll be able to skip stones"
                " in any \n country before no time.";
        pause();
        job.set_name(name);
        // This is the loop where the user picks their job Class to load.
        while (!selected_job) {
            bool error = true;
            cout << " Gidian: So, " << name << ", what kind of adventurer are you?\n\n";         
            cout << " (protector)\n";
            cout << " (elementalist)\n";        
            cout << " (prowler)\n";
            cout << " (crusader)\n\n";    
            cout << " What job do you choose?\n"
                    " If you want to select protector, type 'protector' and hit 'enter': ";
            getline(cin, response);
            
            // case of the user picking a protector.
            if (response == "protector" || response == "Protector") {                                         
                job_type = "Protector";
                job.set_job(job_type);
                description = job.get_description();
                
                do {                                
                    cout << "\n You have selected the protector job." << description;
                    cin >> decision; cin.ignore(80, '\n');
                    cout << "\n";
                    
                    // confirm decision
                    if (decision == 'Y' || decision == 'y') {
                        cout << " " << name << ": I'm a protector.\n";                        
                        selected_job = true;
                        error = false;                        
                        cout << " Gidian: Protector's are like mindless beasts.\n"
                                " Gidian: But like all beasts, they too can be tamed.\n";
                        
                        // changing your mind is okay!
                    } else if (decision == 'N' || decision == 'n') {
                        cout << " " << name << ": On second thought, I am definitely not a protector.\n";  
                        pause();
                        error = false;
                        selected_job = false;
                        // Users are idiots, so...
                        
                    } else {
                        selected_job = false;
                        cout << error_message;                        
                    }     
                } while (error);    
                
            } else if (response == "elementalist" || response == "Elementalist") {    
                job_type = "Elementalist";
                job.set_job(job_type);
                description = job.get_description();
                do {
                    cout << "\n You have selected the elementalist job." << description;
                    cin >> decision; cin.ignore(80, '\n');
                    cout << "\n";
                    // confirm job choice
                    if (decision == 'Y' || decision == 'y') {
                        
                        cout << " " << name << ": I'm a elementalist.\n";                        
                        selected_job = true;
                        error = false;
                        cout << " Gidian: Elementalists are very powerful beings!\n"
                                " Gidian: You should go first.\n";
                        // changing of the mind
                    } else if (decision == 'N' || decision == 'n') {
                        
                        cout << " " << name << ": Gotcha! I'm not a elementalist.\n";
                        pause();                        
                        error = false;
                        selected_job = false;                        
                    } else {
                        
                        selected_job = false;
                        cout << error_message;
                    }
                } while (error);                
                
            } else if (response == "prowler" || response == "Prowler") {
                job_type = "Prowler";
                job.set_job(job_type);
                description = job.get_description();
                do {
                    cout << "\n You have selected the prowler job." << description;
                    cin >> decision; cin.ignore(80, '\n');
                    cout << "\n";
                    
                    // confirm job choice
                    if (decision == 'Y' || decision == 'y') {
                        cout << " " << name << ": I'm a prowler.\n";                        
                        selected_job = true;
                        error = false;
                        cout << " Gidian: A prowler, how wonderful! I may have a use for you.\n"
                                " Gidian: Have you ever tried stealing from a king? *winks*\n";
                        
                        // changing of the mind
                    } else if (decision == 'N' || decision == 'n') {
                        cout << " " << name << ": There\'s no way I\'m a prowler!\n";
                        pause();                        
                        error = false;
                        selected_job = false;     
                        
                    } else {
                        selected_job = false;
                        cout << error_message;
                    }                    
                } while (error);
                
            } else if (response == "crusader" || response == "Crusader") {
                job_type = "Crusader";
                job.set_job(job_type);
                description = job.get_description();
                do {
                    cout << "\n You have selected the Crusader job." << description;
                    cin >> decision; cin.ignore(80, '\n');
                    cout << "\n";
                    
                    // confirm job choice
                    if (decision == 'Y' || decision == 'y') {
                        cout << " " << name << ": I'm a crusader.\n";                        
                        selected_job = true;
                        error = false;
                        cout << " Gidian: A purist eh?\n"
                                " Gidian: Listen, you answer to me now, got it?!\n";
                        // changing of the mind
                        
                    } else if (decision == 'N' || decision == 'n') {
                        cout << " " << name << ": You fell for it! I'm no crusader!\n";
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
    bool not_in_menu = true;
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
        cout << " Press 'I' to display item info.\n";
        getline(cin, move_to_position); // choose which direction to go
        
        if (move_to_position == "move up") { // character moves up
            not_in_menu = true;            
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
            not_in_menu = true;            
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
            not_in_menu = true;            
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
            not_in_menu = true;            
            if (x_pos + 1 < 25) {   
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
            not_in_menu = false;
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
                    cout << error_message;
                    exploring = true;
                    error = true;                        
                }
            } while (error);               
        } else if(move_to_position == "I" || move_to_position == "i") {
            job.display_items(); 
            not_in_menu = false;
            pause();
        } else {   
            cout << " Gidian: Up, Down, Left, or right! Let's move " << name << "!!\n\n";        
        }          
        if (exploring && not_in_menu) {
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
               cout << " Gidian: This is no ordinary Giant Tree Frog!\n"
                       " Gidian: Let's bust 'em up!\n";
               exploring = encounter_giant_tree_frog(); 
               
            } else if (spaces == 19 || spaces == 17 || spaces == 23) {
             
            } else if (spaces == 50) {
                // FIRST BOSS ENCOUNTER
                system("cls");
                exploring = encounter_forest_feral();
            }
        }       
        spaces++;
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
    bool item_dropped;
    pause();
    string name = job.get_name();
    mob_type = "Goblins";
    mob.set_mob(mob_type);
    string goblin_name = mob.get_name();
    cout << " Gidian: " << mob.get_description();
    cout << " " << name << ": I better do something... this goblin looks like he's mad.\n";
    pause();
    // Initiate the battle !!!
    battle_menu(goblin_name);
    if (your_dead()) {
        return false;        
    }        
    loot_items(name);
    job.level_up();
    return true;
}    

/**
 * 
 * @return bool if user lived through the encounter 
 */
bool encounter_skeleton_warrior() {       
    string mob_type;
    pause();
    string name = job.get_name();
    mob_type = "Skeleton Warrior";
    mob.set_mob(mob_type);
    string skeleton_name = mob.get_name();
    cout << " Gidian: " << mob.get_description();
    cout << " " << name << ": Time to turn these dry bones to dust!\n";
    pause();
    // Initiate the battle!
    battle_menu(skeleton_name);
    if (your_dead()) {
        return false;
    }
    loot_items(name);
    job.level_up();
    return true;
}

bool encounter_giant_tree_frog() {
    pause();
    string mob_type;
    string name = job.get_name();
    mob_type = "Giant Tree Frog";
    mob.set_mob(mob_type);
    string giant_tree_frog_name = mob.get_name();
    cout << " Gidian: " << mob.get_description();
    cout << " " << name << ": Is that a hippo or a frog?!?!\n";
    pause();
    // Start the battle!
    battle_menu(giant_tree_frog_name);
    if (your_dead()) {
        return false;        
    }    
    loot_items(name);
    job.level_up();
    return true;
}

bool encounter_forest_feral() {
    pause();
    string mob_type = "The Forest Feral";
    mob.set_mob(mob_type);
    string name = job.get_name();
    cout << " Gidian: This fowl creature is much more powerful than a Goblin,\n be on your guard " << name << "!\n";
    cout << " Gidian: I am the keeper of this forest, and I will defeat you!\n"
            " Gidian: With " << name << "\'s help, of course...\n";
    pause();
    cout << " The Forest Feral: " << mob.get_description();
    // Start the battle!
    battle_menu(mob_type);
    if (your_dead()) {
        return false;
    } 
    loot_items(name);
    int level_before = job.get_level();            
    job.level_up();
    int level_after = job.get_level();
    
    if (level_before != level_after) {
        job.set_hp(job.get_max_hp());
        job.set_mp(job.get_max_mp());
    }
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

void loot_items(string name) {
    string item_description[3], item_name[3];
    int item_cost[3], item_quantity[3], item_drop_rate[3], item_value[3];
    bool item_dropped;
    bool printed = FALSE;
    
    for (int i = 0; i < 2; i++) {
        item_name[i] = mob.get_item_name(i);
        item_cost[i] = mob.get_item_cost(i);
        item_value[i] = mob.get_item_value(i);
        item_description[i] = mob.get_item_description(i);
        item_quantity[i] = mob.get_item_quantity(i);
        item_drop_rate[i] = mob.get_item_drop_rate(i);
        item_dropped = item.drop_item(item_drop_rate[i]);
        
        if (item_dropped == TRUE) {
            job.set_item_name(i, item_name[i]);
            job.set_item_cost(i, item_cost[i]);
            job.set_item_value(i, item_value[i]);
            job.set_item_description(i, item_description[i]);
            job.set_item_quantity(i, item_quantity[i]);
            cout << " " << name << " received " << mob.get_item_quantity(i) << " " << job.get_item_name(i) << ".\n";
        } else if (item_dropped == FALSE && printed == FALSE) {            
            cout << " " << name << " found no items!\n";
            printed = TRUE;
        }
    }
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
    string choice, job_ability_name;    
    int hp_gained = mob.get_hp() * .15;
    int mp_gained = mob.get_mp() * .12;
    int job_ability_dmg, ability_type, job_ability_mp_cost, job_ability_heal, job_ability_defend;
    string job_ability_info;
    bool battle_over = false;   
    int max_hp = job.get_max_hp();
    int max_mp = job.get_max_mp();
    int mob_max_hp = mob.get_max_hp();
    int mob_max_mp = mob.get_max_mp();
    // reset the prowler's damage on his boosted ability
    if (job.get_job_type() == "Prowler") {
        job.set_ability_damage(0, job.get_ability_base_dmg(0));
    }
    cout << " " << name << " has encountered a " << mob_name << "!!\n\n";
    // if mob is dead battle is over
    while (!battle_over) {           
        int stealth_counter = 0;
        bool flee = false;    
        bool error = false;
        bool used_item = false;
        bool tried_to_run = false;
        do {            
            cout << "\n " << name << " HP: " << job.get_hp() << " / " << max_hp << "    MP: " << job.get_mp() << " / " << max_mp << "  "; 
            cout << " " << mob_name << " HP: " << mob.get_hp() << " / " << mob_max_hp << "    MP: " << mob.get_mp() << " / " << mob_max_mp << "\n\n";
            int cap = 4;
            
            if (job.get_level() >= 2) {
                cap = 5;
            } else if (job.get_level() >= 6) {
                cap = 6;
            }
            
            for (int i = 1; i < cap; i++) {                
                cout << " [" << i << "]  " << job.get_ability_name(i-1) << "\n";        
            }
            cout << " [I]  Use Item \n";
            cout << "\n What will " << name << " do?\n";
            getline(cin, choice);              
            string ab_1, ab_2, ab_3, ab_4, ab_5;
            ab_1 = job.get_ability_name(0);
            ab_2 = job.get_ability_name(1);
            ab_3 = job.get_ability_name(2);
            ab_4 = job.get_ability_name(3);
            ab_5 = job.get_ability_name(4);
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
                job_ability_defend = job.get_ability_defend(3);
                job.decrease_mp(job_ability_mp_cost);
                if (job.get_mp() < 0) {
                    cout << " Not enough mana to use that ability!\n";
                    job.increase_mp(job_ability_mp_cost);
                    error = true;
                }            
            } else if (choice == ab_5 || choice == "5") {
                error = false;
                tried_to_run = false;
                job_ability_name = job.get_ability_name(5);
                job_ability_dmg = job.get_ability_damage(5);
                job_ability_mp_cost = job.get_ability_mp_cost(5);
                job_ability_info = job.get_ability_info(5);
                job_ability_heal = job.get_ability_heal(5);
                job_ability_defend = job.get_ability_defend(5);
                job.decrease_mp(job_ability_mp_cost);
                if (job.get_mp() < 0) {
                    cout << " Not enough mana to use that ability!\n";
                    job.increase_mp(job_ability_mp_cost);
                    error = true;
                }
                // Use an item    
            } else if (choice == "i" || choice == "I") {
                error = false;
                tried_to_run = false;                
                bool real_item  = true;
                int item_to_use;
                string item_name;
                int item_value;
                string item_choice;
                job.display_items();
                cout << "\n\n  Choose an item to use by typing it's name: ";
                getline(cin, item_choice);
                real_item = job.item_validation(item_choice);
                if (real_item) {
                    item_to_use = job.item_selection(item_choice);
                    item_value = job.get_item_value(item_to_use);
                    item_name = job.get_item_name(item_to_use);
                    used_item = job.item_activate(item_name, item_value);                                        
                } else {
                    cout << " That is not a real item!\n";
                    error = true;
                }                     
                
                if (used_item) {
                    error = false;
                    job.decrease_item_quantity(item_to_use);
                } else if (!real_item) {
                    error = true;
                    cout << " You have no " << item_choice << "s available to use!\n";
                } else {
                    
                }                                
            } else {        
                error = true;                   
                cout << " Invalid option... Please just do what I tell you to.\n\n";            
            } 
            // if the user DIDNT flee AND DIDNT try to run AND there was no ERROR with ability mp cost
            if (flee == false && tried_to_run == false && error == false) {
                if (!used_item) {
                    cout << "\n " << name << " uses " << job_ability_name << "!\n";
                    if (job_ability_name == "Stealth") {
                        cout << " " << name << " enters the shadows unseen.\n";
                    } else if (job_ability_name == "Earth's Shell") {
                        cout << " " << name << " surrounds himself with an earthen shield!\n";                    
                    } else if(job_ability_name == "Redemptive Light") {
                        cout << " " << name << " calls down the light of Redemption!\n";
                        job.increase_hp(job_ability_heal);                    
                        // Check for overheal
                        if (job.get_hp() > max_hp) {
                            int val;
                            val = job.get_hp() - max_hp;
                            job_ability_heal = job_ability_heal - val;
                            job.set_hp(max_hp);                        
                        }                    
                        cout << " " << name << " restored "  << job_ability_heal << " hit points!\n";
                    } else {
                        cout << " " << mob_name;
                        battle_over = mob.damage_hp(job_ability_dmg);                    
                    }                    
                    used_item = false;
                }    
                // if the mob is dead!
                if (battle_over == true && flee == false) {                    
                    cout << " " << name << " has defeated the " << mob_name << "!!\n";
                    job.increase_experience(mob.get_exp_reward());
                    cout << " " << name << " has received " << mob.get_exp_reward() << " experience points!\n";                
                    job.increase_hp(hp_gained);
                    job.increase_mp(mp_gained);

                    // Check for overheal
                    if (job.get_hp() > max_hp) {
                        job.set_hp(max_hp);
                    }
                    // Check for TOO much mana
                    if (job.get_mp() > max_mp) {
                        job.set_mp(max_mp);
                    }
                    pause();
                } else {                  
                    // giant tree frog will use consume to heal below 10 hp
                    if ((mob_name == "Giant Tree Frog" && mob.get_hp() < 10) 
                        || mob_name == "The Forest Feral" && mob.get_hp() < 20) {
                        ability_type = 1;                        
                    } else {
                        ability_type = 0;
                    }
                    mob.decrease_mp(mob.get_ability_mp_cost(ability_type));                      
                     // if the mob doesnt have enough mp for first ability, use other ability
                    if (mob.get_mp() < 0) {
                        mob.increase_mp(mob.get_ability_mp_cost(ability_type));
                        ability_type = 1;          
                        if (mob_name == "Giant Tree Frog") {
                            ability_type = 0;
                        } else if (mob_name == "The Forest Feral") {
                            ability_type = 2;
                        }
                    }
                    cout << mob.get_ability_info(ability_type);
                    mob.increase_hp(mob.get_ability_heal(ability_type));
                    if (job_ability_name == "Stealth") {
                        stealth_counter += 2;
                        cout << " " << mob_name << " cannot find " << name << "!\n";
                        cout << " " << name << " is hiding in the shadows.\n";
                        job.set_ability_damage(0, job.get_ability_damage(0) + stealth_counter);                        
                    } else if (job_ability_name == "Earth's Shell") {
                        cout << " " << name;
                        game_over = job.damage_hp((mob.get_ability_damage(ability_type)) - job_ability_defend);
                    } else {
                        cout << " " << name;
                        game_over = job.damage_hp((mob.get_ability_damage(ability_type)));                                               
                    }
                                                                                                                                       
                }
                if (game_over) {
                    cout << " " << name << " has been defeated by " << mob_name << "!!\n";
                    pause();
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
        if (job_ability_name == "Double Stab") {            
            job.set_ability_damage(0, job.get_ability_base_dmg(0));
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

#endif	/* BEGIN_ADVENTURE_H */

