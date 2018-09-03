//
//  main.cpp
//  Tryout
//
//  Created by Max Vennerholm Gesner on 2018-08-30.
//  Copyright © 2018 Max Vennerholm Gesner. All rights reserved.
//

#include <iostream>
//for the random number
#include <cstdlib>
#include <ctime>
//for the sleep/pause
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...

    //array of random_integer with two numbers to store. [0] being first hit and total sum
    //and [1] being the card you add to [0]
    int random_integer[2];
    
    cout << "_______________" << endl;
    cout << "-- BLACKJACK --" << endl;
    cout << "_______________" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Deal the cards?" << endl;
    
    
    
    
    //generate random number for random_integer[0]
    srand(time(0));
        random_integer[0] = (rand()%10)+1;
    
    //show random number random_integer[0]
    cout << "--------" << setw(12) << "---" << endl;
    cout << "you hit " << setw(10)<< "|" << random_integer[0] << "|" << endl;
    
    
    
    //stop for 1 second
    this_thread::sleep_for(chrono::milliseconds(1000));
    
    //increase array [0] of random_integer with a number from 1 - 10 while it is less than 21
    do {
      
        //generate random number for random_integer[1]
    srand(time(0));
    random_integer[1] = (rand()%10)+1;
        
        //Add random_integer[1] to random_integer[0]
    random_integer[0]+=random_integer[1];
        
        //show random_integer[1] number
        cout << "________" << setw(12) << "___" << endl;
    cout << "you hit " << setw(10) << "|" << random_integer[1] << "|" << endl;
        
        //pause for 1 second
        this_thread::sleep_for(chrono::milliseconds(1500));
        
        //show sum of random_integer[1] plus random_integer[0]
        cout << "________" << setw(12) << "___" << endl;
    cout << "total is " << setw(10) << random_integer[0] << endl;
        
        //stop for 1 second
        this_thread::sleep_for(chrono::milliseconds(1000));
        
        
    }
    while(random_integer[0] < 21);
    
    return 0;
}
