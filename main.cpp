/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ehansen
 *
 * Created on June 16, 2018, 7:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

float calculate_power(float base, int power) {
    float result = 1;
    
    for(int k=1; k <= abs(power); k++)
        result *= base;
    
    result = (power < 0) ? 1/result : result;
    return result;
}

void print_table(float base, int min_power, int max_power) {
    // print table output
    float result;
    
    cout << "Base  Exponent    Result\n";
    for(int i = min_power; i <= max_power; i++) {
        result = calculate_power(base, i);
        cout << base << "     ";
        cout << i << "           ";
        cout <<  result << "\n";
    }
    return;
}

int check_quit(string ready_to_quit) {
    if(ready_to_quit.compare("Y") != 0 && ready_to_quit.compare("y") != 0) {
        return 0;
    } else {
        return 1;
    }
}
/*
 * 
 */
int main(int argc, char** argv) {
    int done = 0;
    float base;
    int min_exponent, max_exponent;
    string quit;
    
    do {
        cout << "Enter base value: ";
        cin >> base;
        cout << "Enter minimum power: ";
        cin >> min_exponent;
        cout << "Enter maximum power: ";
        cin >> max_exponent;
        
        print_table(base, min_exponent, max_exponent);
        
        cout << "Do you want to quit? (Y/N) ";
        cin  >> quit;
        
        done = check_quit(quit);
    } while (!done);
    return 0;
}

