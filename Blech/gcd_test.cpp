/* 
 * File:   gcd_test.cpp
 * Author: Michael Ryan
 *
 * Created on August 28, 2014, 6:29 PM
 */

#include <iostream>

using namespace std;

int gcd(int m, int n);

/*
 * 
 */
int main() {
    int m, n, answer;
    bool doing_math = true;
    char response;
    
    while (doing_math) {
        bool error = false;
        cout << "\n\nPlease enter two integers. One must not be zero: \n";
        cin >> m; cin.ignore(80,'\n');
        cin >> n; cin.ignore(80,'\n');    

        answer = gcd(m, n);
        cout << "The greatest common denominator between " << m << " and " << n << " is " << answer << endl;
        
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
    
}


// Homework 3, 4, 7, 9 p.17-18 