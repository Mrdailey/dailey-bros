/**********************************************************************
 *  Definition of a class for Inventory Items.  Each variable           *
 *  has three (private) fields and (public) functions to enable a user  *
 *  to get the value or set the value of each of these three fields.    *
 *        There are three constructor functions to initialize fields    *
 *  of a new InventoryItem variable that is declared.  Each such        *
 *  variable is known as an "object" from the InventoryItem class.      *
 *        The function definitions are given "inline" within the header *
 *  file.  In order to access and use this class definition, you must   *
 *  include it in the calling program unit, by using:                   *
 *     #include "InventoryItem.h" at the beginning of the file wishing  *
 *  to use this class definition.                                       *
 ************************************************************************/

#ifndef INVENTORY_ITEM_H
#define INVENTORY_ITEM_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class InventoryItem
{
   private:
      string description; // item description
      double cost;        // unit cost
      int units;          // number of units currently in inventory

   public:
      InventoryItem ()   // constructor function (default form)
      {
         description = "No description";
         cost = 0.0;
         units = 0;
      }

      InventoryItem (string descr) // constructor function
      {
         description = descr;
         cost = 0.0;
         units = 0;
      }

      InventoryItem (string descr, double c, int u)  // constructor function
      {
         description = descr;
         cost = c;
         units = u;
      }
	 
      void increaseUnits (int quantity)
      {
         units = units + quantity;
      }

      bool decreaseUnits (int quantity) // boolean tells if operation is successful
      {
         if (quantity <= units)
         {
            units = units - quantity;
            return true;
         }
            return false;
      }

      void  setDescription (string descr)    // "mutator" functions
      { description = descr; }

      void  setCost (double c)
      { cost = c;}

      void  setUnits (int u)
      { units = u; }

      string getDescription ()     // "accessor" functions
      { return description; }

      double getCost ()
      { return cost; }

      int getUnits ()
      { return units; }

      void printData ()   // quick print of object's data fields
      {
          cout << "Description:   " << description << endl
               << "Unit Cost:    $" << cost << endl
               << "Units on Hand: " << units << endl << endl;
      }     
};
#endif
