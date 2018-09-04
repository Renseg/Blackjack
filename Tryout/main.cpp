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
//for setw()
#include <iomanip>
#include <string>

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...

    //array of random_integer with two numbers to store. [0] being first hit and total sum
    //and [1] being the card you add to [0]
    int random_integer[2], dealer_int[2], active;
    string hit;
    
    cout << "_______________" << endl;
    cout << "-- BLACKJACK --" << endl;
    cout << "_______________" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Deal the cards?" << endl;
    cout << "type: 1" << endl;
    cin >> active;
    
    //while active = 1 the game will play
     do {
         
    //generate random number for random_integer[0]
    srand(time(0));
        random_integer[0] = (rand()%10)+1;
  
    //show random number random_integer[0]
    cout << "--------" << setw(12) << "---" << endl;
    cout << "you hit " << setw(10)<< "|" << random_integer[0] << "|" << endl;
    
        
    //stop for 1 second
    this_thread::sleep_for(chrono::milliseconds(1000));
             
         cout << "do you hit again" << endl;
         cout << "yes" << setw(12) << "no" << endl;
         cin >> hit;
        
        if (hit == "yes")
        {
         do
         {
             
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
             
             cout << "do you hit again" << endl;
             cout << "yes" << setw(12) << "no" << endl;
             cin >> hit;
             cout << hit << endl;
             
         }
         while (hit=="yes");
        }
         else
        {
        if(random_integer[0] <= 21)
        {
            cout << random_integer[0] << endl;
            
        }
        }
    }
    while(active==1);
    
    return 0;
}
