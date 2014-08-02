/* 
 * File:   text_adventure.cpp
 * Author: Michael Ryan
 *
 * Created on August 1, 2014, 9:10 PM
 */

#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "mob_main.h"
#include "jobs.h"
using namespace std;

/*
 * 
 */
int main() {
    Warrior Sedon;
    Goblins Mob;
    
    cout << "The Goblin mob has" << Mob.get_hp() << " hit points!" << endl;
    Mob.damage_hp(Sedon.get_warrior_ability());
    
    cout << "The Goblin mob now has " << Mob.get_hp() << " hit points!!" << endl;
    
    for(int i = 0; i<5; i++){
        Sedon.increase_experience(Mob.get_reward_experience());
    }
    
    cout << "Sedon has " << Sedon.get_experience() << " experience points!!!!!";
    
    
    
    return 0;
}

