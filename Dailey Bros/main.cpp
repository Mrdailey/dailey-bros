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
    for(int i = 0; i<5; i++){
        Sedon.increase_experience(Mob.reward_experience());
    }
    
    cout << "Sedon has " << Sedon.get_experience() << " experience points!!!!!";
    
    
    return 0;
}

