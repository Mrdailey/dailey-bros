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
void battle_menu(string mob_name); 
void edge_of_map();
void exit_game();
void display_info();
void set_job(string job_type);

//declare booleans for exiting purposes.
bool game_over = false;
bool game_active = true;
string error_message = " You can\'t seem to follow simple instructions, can you?\n";

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
            cout << " " << name << " has " << job.get_experience() << "\n";        
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
            display_info(); // all character info that is currently in the system
            
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
        if (spaces % 5 == 0 && exploring == true) {
            encounter_goblin();
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
    string job_ability_info;
    bool battle_over = false;    
    // reset the thief's damage on his boosted ability
    if (job.get_job() == "Thief") {
         job.set_ability_damage(0, 10);
    }
    cout << " " << name << " has encountered a " << mob_name << "!!\n\n";
    // if mob is dead battle is over
    while (!battle_over) {           
        int stealth_counter = 0;
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
                job_ability_info = job.get_ability_info(0);
                job.decrease_mp(job_ability_mp_cost);                
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
                } else {
                    cout << " " << mob_name;
                    battle_over = mob.damage_hp(job_ability_dmg);
                    cout << " The " << mob_name << " now has " << mob.get_hp() << " hit points!\n";
                }
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
                    if (job_ability_name == "Stealth") {
                        stealth_counter ++;
                        cout << " " << mob_name << " cannot find " << name << "!\n";
                        cout << " " << name << " is hiding in the shadows.\n";
                        job.set_ability_damage(0, job.get_ability_damage(0) + stealth_counter);
                    } else {
                        cout << " " << name;
                        game_over = job.damage_hp((mob.get_ability_damage(ability_type)));
                        cout << " " << name << " now has " << job.get_hp() << " hit points!\n";                          
                    }
                                                                                                                                       
                }
                if (game_over) {
                    cout << " " << name << " has been defeated by " << mob_name << "!!\n";
                    battle_over = true;
                }
            }              
        } while (error); // end do while loop
        // Successful Flee!!! Will exit battle!
        if (flee == true) {
            cout << "\n Successfully fled from the " << mob_name << "!!\n";
            cout << "\n Gidian: Brave sir " << name << " ran away! Bravely ran away, away!\n"
                    " Gidian: When danger reared it\'s ugly head, he bravely turned his tail and fled!\n";
            cout << " " << name << ": No wonder this guy is all alone out here...\n";        
        } 
        // after double stab is used reset it's damage boost.
        if (job.get_job() == "Thief" && job_ability_name == "Double Stab-jab") {
            job.set_ability_damage(0, 10);
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
        job.set_ability_damage(0, 10);
        job.set_ability_mp_cost(0, 0);
        job.set_ability_info(0, "A sudden two strikes that can be lethal.");

        job.set_ability_name(1, "Stealth");
        job.set_ability_damage(1, 0);
        job.set_ability_mp_cost(1, 5);
        job.set_ability_info(1, "Hide from sight and increase the damage of the next attack. Can be used additively.");    
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

#endif	/* BEGIN_ADVENTURE_H */

