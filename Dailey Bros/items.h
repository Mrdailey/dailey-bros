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
#include "begin_adventure.h"

using namespace std;
int get_rand(int min, int max);

class Items {
    
    protected:
        string name;
        string description;
        int cost;
        int drop_rate;
        int value;
    public:
        Items() {
            name = "";
            description = "";
            cost = 0;
            drop_rate = 0;
            value = 0;
        }
        
        void set_name(string n) {
            name = n;            
        }
        
        string get_name() {            
            return name;
        }
        
        void set_description(string desc) {
            description = desc;            
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
        
        void set_value(int val) {
            value = val;
        }
        
        int get_value() {
            return value;
        }
        
        bool drop_item(int rate) {
            int percent = get_rand(0, 100);
                        
            if (percent <= rate) {                
                return true;
            } else {                
                return false;
            }    
        }               
        
        void health_potion() {
        
            name = "Basic Health Potion";
            description = "A basic health potion that restores 30 hp.\n";
            cost = 10;
            drop_rate = 50;
            value = 30;
        }    
            
        void mana_potion() {
                    
            name = "Basic Mana Potion";
            description = "A basic mana potion that restores 20 mp.";
            cost = 10;
            drop_rate = 40;
            value = 15;
        }    
        
};
#endif	/* ITEMS_H */

