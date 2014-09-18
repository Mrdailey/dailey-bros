/* 
 * File:   gcd_test.cpp
 * Author: Michael Ryan
 *
 * Created on August 28, 2014, 6:29 PM
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int gcd(int m, int n);
int get_rand(int min, int max);
int lcm(int m, int n);
void menu();

/*
 * 
 */
int main() {
    int m, n, answer;
    clock_t t1, t2;
    bool doing_math = true;
    char response;
    
    while (doing_math) {
        bool error = false;
        char choice;
        menu();    
        t1 = clock();
        cin >> choice; cin.ignore(80,'\n');
        switch (choice) {
            case '1': {     
                cout << "\n\nPlease enter two integers. One must not be zero: \n";
                cin >> m; cin.ignore(80,'\n');
                cin >> n; cin.ignore(80,'\n');    
                
                answer = gcd(m, n);
                t2 = clock();
                float diff ((float)t2 - (float)t1);
                float runtime = diff / CLOCKS_PER_SEC;
                cout << "The greatest common denominator between " << m << " and " << n << " is " << answer << endl;
                cout << "Runtime: " << runtime << " seconds\n";
                cout << "Clocks: " << diff << "\n";
                break;
            }      
            case '2': {
                cout << "\n\nPlease enter two integers: \n";
                cin >> m; cin.ignore(80,'\n');
                cin >> n; cin.ignore(80,'\n');
                
                answer = lcm(m, n);
                t2 = clock();
                float diff ((float)t2 - (float)t1);
                float runtime = diff / CLOCKS_PER_SEC;
                cout << "The least common multiple between " << m << " and " << n << " is " << answer << "\n";            
                cout << "Runtime: " << runtime << endl;
                cout << "Clocks: " << diff << "\n";
                break;
            }
            default: {
                cout << "Invalid choice...\n";
            }
        }

        
        do {
            cout << "Do you want to go again, Y/N?\n";
            cin >> response; cin.ignore(80, '\n');
            if (response == 'N' || response == 'n') {
                error = false;
                doing_math = false;
                cout << "Exiting...\n";
            } else if (response == 'Y' || response == 'y') {
                error = false;
                doing_math = true;
            } else {
                error = true;
            }
        } while(error);        
    }
    return 0;
}

int get_rand(int min, int max){ 
    srand(time(NULL));
    return(rand()% (max - min) + min); 
} 

int gcd(int m, int n) {
    int r;
    if (n == 0) {
        return m;
    } else {
        r = m % n;
        gcd(n, r);
    }    
}

/**
 *  GCD(M,N) * LCM(M,N) = M * N
 * @param m
 * @param n
 * @return 
 */
int lcm(int m, int n) {
    int max, r;        
    if (m > n) {
        max = m;
        r = m % n;
        if (r == 0) {
            return m;
        } else {
            for (int i = 2; i <= m; i++) {
                n = n * i;               
                if (n % m == 0) {
                    return n;
                } else {
                    n = n / i;
                }
            }
        }
    } else {
        max = n;
        r = n % m;
        if (r == 0) {
            return n;
        } else {
            for (int i = 2 ; i <= n; i++) {
                m = m * i;
                if (m % n == 0) {
                    return m;
                } else {
                    m = m / i;
                }
            }
        }
    }        
}

void menu() {
    cout << "***************\n";
    cout << "* 1) GCD      *\n";
    cout << "* 2) LCM      *\n"; 
    cout << "***************\n";
    cout << "Choose which value to find: ";
}