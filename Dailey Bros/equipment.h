/* 
 * File:   equipment.h
 * Author: Michael Ryan
 *
 * Created on September 23, 2014, 12:57 PM
 */

#ifndef EQUIPMENT_H
#define	EQUIPMENT_H
#include <iostream>
#include <string>
#include <iomanip>
#include "jobs.h"

using namespace std;

class Equipment {
    protected:        
        string description, name, slot;
        int defense, stamina, intelligence, dexterity, strength;
        int drop_rate;
        int cost;
    public:
        Equipment() {
            description = "";
            name = "";
            defense = 0;
            stamina = 0;
            intelligence = 0;
            dexterity = 0;
            strength = 0;
            drop_rate = 0;
            slot = "";
            cost = 0;
        }
        
        void useless_helment() {
            slot = "Head";
            name = "Useless Helmet";
            description = "This helmet is pretty much useless.";
            cost = 12;
            drop_rate = 20;
            defense = 5;
            stamina = 1;            
        }   
        
        void useless_sword() {
            slot = "Weapon";
            name = "Useless Sword";
            description = "This sword is fairly useless.";
            cost = 12;
            drop_rate = 23;
            strength = 1;
            dexterity = 1;
        }
        
        void useless_off_hand() {
            slot = "Off-Hand";
            name = "Useless Shield";
            description = "This shield is not worth much";
            cost = 10;
            drop_rate = 15;
            strength = 1;
            stamina = 2;
        }     
        
        string get_name() {
            return name;
        }
        
        string get_slot() {
            return slot;
        }
        
        string get_description() {
            return description;
        }
        
        int get_cost() {
            return cost;            
        }
        
        int get_drop_rate() {
            return cost;
        }
        
        int get_strength() {
            return strength;
        }
        
        int get_dexterity() {
            return dexterity;
        }
        
        int get_defense() {
            return defense;
        }
        
        int get_stamina() {
            return stamina;
        }
        
        int get_intelligence() {
            return intelligence;
        }
};    
#endif	/* EQUIPMENT_H */

