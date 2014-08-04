/* 
 * File:   text_adventure.cpp
 * Author: Michael Ryan
 *
 * Created on August 1, 2014, 9:10 PM
 */

#include <iomanip>
#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "mob_main.h"
#include "jobs.h"
#include "begin_adventure.h"

using namespace std;

int get_rand(int min, int max);

int main() {

    string Menu[3] = {"Start Game", "Continue", "Exit"};
    int pointer = 0;

//    begin_adventure();
    while (true) {               
        system("cls");
	
        cout << "   *************************************************\n";
        cout << "   *                                               *\n";
        cout << "   *                TEXT ADVENTURER                *\n";
        cout << "   *                   Main Menu                   *\n";
        cout << "   *************************************************\n";        
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);        

        for (int i = 0; i < 3; ++i) {
            if (i == pointer) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                cout << Menu[i] << endl;
            } else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << Menu[i] << endl;
            }
        }        

        while (true) {
            if (GetAsyncKeyState(VK_UP) != 0) {
                pointer -= 1;
                if (pointer == -1) {
                    pointer = 2;
                }
                break;                
            } else if (GetAsyncKeyState(VK_DOWN) != 0) {
                pointer += 1;
                if (pointer == 3) {
                    pointer = 0;
                }        
                break;
            } else if (GetAsyncKeyState(VK_RETURN) != 0) {
                    switch (pointer) {
                        case 0: {                                                                             
                            cout << "Start new game?";
                            Sleep(1000);        
                            pause();
                            begin_adventure(); 
                        } break;
                        case 1: {
                            cout << "\n\n\nNo file saved...";
                            Sleep(1000);                                                                    
                        } break;
                        case 2: {  
                            cout << "\n\n\n Exit the game...";                            
                            return 0;           
                        } break;
                    }
                break;
            } 
        }
        Sleep(150);        
    }        
    return 0;
}


// 

/**
 Notes: To compile and run:
 * 1. Navigate in your command prompt to the folder that contains the project files.
 * 2. type "g++ main.cpp -o "name of executable"
 * Ex.
 * cd Documents\GitHub\mrd\dailey-bros\Dailey Bros
 * g++ main.cpp -o main
 * 3. Then type the name of the executable to run.
 * 
 */