/* 
 * File:   items.h
 * Author: Michael Ryan
 *
 * Created on August 14, 2014, 11:08 PM
 */

#ifndef ITEMS_H
#define	ITEMS_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

class Items {
    
    protected:
        string name;
        string description;
        int cost;
        int drop_rate;
    public:
        Items() {
            name = "";
            description = "";
            cost = 0;
            drop_rate = 0;
        }
        
        void set_name(string n) {
            name = n;            
        }
        
        string get_name() {            
            return name;
        }
        
        void set_description(string n) {
            name = n;            
        }
        
        string get_description() {
            return description;
        }
        
        void set_cost(int c) {
            cost = c;
        }
        
        int get_cost() {
            return cost;
        }
        
        void set_drop_rate(int rate) {
            drop_rate = rate;
        }
        
        int get_drop_rate() {
            return drop_rate;
        }           
};

class Potions : public Items {
    
    public:
        Items health_potion() {
            health_potion.name = set_name("Basic Health Potion");
            health_potion.description = set_description("A basic health potion that restores 30 hp.\n");
            health_potion.cost = 10;
            health_potion.drop_rate = .10;
            return health_potion;
        }    
        Items mana_potion() {
            mana_potion.name = set_name("Basic Mana Potion");
            mana_potion.description = set_description("A basic mana potion that restores 20 mp.");
            mana_poition.cost = 10;
            mana_potion.drop_rate = .08;
        }
};


#endif	/* ITEMS_H */

