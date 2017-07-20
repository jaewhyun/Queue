//
//  main.cpp
//  queue
//
//  Created by Jae Won Hyun on 11/6/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#include <iostream>
#include "queue.h"
#include "node.h"
using namespace std;

int main()
{
    Queue A;
    
    srand((unsigned int) time(NULL));
    
    // ask for the duration of the time
    A.duration();
    int currenttime = 0;
    int countertime = 1;
    int max = 5;
    int min = 1;
    int plannedentry;
    int previouscustomer;
    int numberofcustomers = 0;

    // while the current time is less than the duration set by the user
    while(currenttime < A.getduration())
    {
        // increase current and counter
        currenttime++;
        countertime++;
        
        // if number of customers is bigger than 0,
        if(numberofcustomers > 0)
        {
            // if current time is equal to the previous customer's entry minute + random number, add another customer
            if(currenttime == previouscustomer + plannedentry)
            {
                numberofcustomers++;
                A.didweaddacustomer(numberofcustomers, currenttime);
                A.getcurrentcustomer();
                //A.decreaseallnodes(countertime, currenttime);
            }
            
            // if the counter is bigger than the current time
            if(countertime > currenttime)
            {
                // if end does not equal NULL,
                if(A.returnend() != NULL)
                {
                    previouscustomer = A.getpreviouscustomerentryminute();
                }
                // decrease all the nodes by 1 minute
                A.decreaseallnodes(countertime, currenttime);
            }
            
            // http://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand
            // get random number for 1 ~ 5
            plannedentry = rand() % (max + 1 - min) + min;
            A.gothroughtheline(currenttime);
            
            // if end is null,
            if(A.returnend() == NULL)
            {
                currenttime++;
                countertime++;
                numberofcustomers++;
                // add another random customer to the line
                A.didweaddacustomer(numberofcustomers, currenttime);
                cout << "\nminute: " << currenttime;
                A.getcurrentcustomer();
                
            }
        }
        else // if there are no customers // if the numberofcustomers = 0
        {
            numberofcustomers++;
            A.didweaddacustomer(numberofcustomers, currenttime);
            A.gothroughtheline(currenttime);
            plannedentry = rand() % (max + 1 - min) + min;
        }
        
    }
    
    cout << "\ntime is up!" << endl;
}
