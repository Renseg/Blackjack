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


    int random_integer[2], dealer_int[2], active, loops;
    string hit, replay;
    
    //title
    cout << "_______________" << endl;
    cout << "-- BLACKJACK --" << endl;
    cout << "_______________" << endl;
    
    //stop 500 ms
    this_thread::sleep_for(chrono::milliseconds(500));
    
    //ask for 1 to start the game
    cout << "Deal the cards?" << endl;
    cout << "type: 1" << endl;
    cin >> active;
    
    //while variable active = 1 the game will play
     do {
         
         //reset both arrays in random_integer to 0
         random_integer[0] = 0;
         random_integer[1] = 0;
         
       
         
    //generate random number for random_integer[0]
    srand(time(0));
        random_integer[0] = (rand()%10)+1;
  
    //show random number random_integer[0]
    cout << "--------" << setw(12) << "---" << endl;
    cout << "you hit " << setw(10)<< "|" << random_integer[0] << "|" << endl;
         
         srand(time(0));
         dealer_int[0] = (rand()%10)+1;
         
         srand(time(0));
         dealer_int[1] = (rand()%10)+1;
         
         cout << "__________" << setw(12) << "___" << endl;
         cout << "dealer hit" << setw(10) << "|" << dealer_int[0] << "|" << endl
         << endl;
         
         this_thread::sleep_for(chrono::milliseconds(500));
    
        
    //stop 500 ms
    this_thread::sleep_for(chrono::milliseconds(500));
         cout << "do you hit again" << endl;
         cout << "yes" << setw(12) << "no" << endl;
         cin >> hit;
        
        //keep adding numbers to random_integer[0] while variable hit is "yes"
         //and random_integer[0] is less or equal to 21
         do
         {
             
        //generate random number for random_integer[1]
    srand(time(0));
    random_integer[1] = (rand()%10)+1;
        
             //show random_integer[1] number
             cout << "________" << setw(12) << "___" << endl;
             cout << "you hit " << setw(10) << "|" << random_integer[1] << "|" << endl;
             
        //Add random_integer[1] to random_integer[0]
    random_integer[0]+=random_integer[1];
        
        
        //stop 500 ms
        this_thread::sleep_for(chrono::milliseconds(500));
        
        //show sum of random_integer[1] plus random_integer[0]
        cout << "________" << setw(12) << "___" << endl;
    cout << "total is " << setw(10) << random_integer[0] << endl;
        
             this_thread::sleep_for(chrono::milliseconds(500));
             
             loops = 1;
             loops++;
             if(loops >= 2 && dealer_int[0] <= 17)
             {
                 srand(time(0));
                 dealer_int[1] = (rand()%10)+1;
                 
                 cout << "dealer hit" << dealer_int[1] << endl;
                 dealer_int[0]+=dealer_int[1];
             }
                 cout << "dealer total is" << dealer_int[0] << endl;
             
                 
        //stop 500 ms
        this_thread::sleep_for(chrono::milliseconds(500));
             
             //ask player for "yes" to loop or "no" exit loop
             cout << "do you hit again" << endl;
             cout << "yes" << setw(12) << "no" << endl;
             cin >> hit;
             cout << hit << endl;
             
          
                 
             
             
         }
         while (hit=="yes" && random_integer[0] <= 21);
         
        
         
         
         
         //the game stopped
         cout << "you stopped" << endl;
         
         //stop 500 ms
         this_thread::sleep_for(chrono::milliseconds(500));
         
         //the program will ask you to hit
         if (random_integer[0] > 21)
         {
             cout << " you hit over 21" << endl
             << endl;
             cout << "GAME OVER" << endl
             << endl;
         }
        else
        {
          
                cout << "your total is" << setw(10) << random_integer[0]<< endl
                << "dealer total is" << setw(10) << dealer_int[0] << endl;
                
                this_thread::sleep_for(chrono::milliseconds(500));
            if(random_integer[0] > dealer_int[0])
            {
                cout << "YOU WIN" << endl;
            }
            else
            {
                cout << "YOU LOSE" << endl;
            }
        }
         
         
         //ask player if restart
         cout << "play again?" << endl;
         cout << "yes" << setw(12) << "no" << endl;
         
         //input "yes" or "no". if "no" active variable will be 0 and program will stop,
         //else it will loop to start of do/while loop and replay game
         cin >> replay;
         if(replay == "no")
         {
             active = 0;
         }
        }
    while(active==1);
    
    return 0;
}
