//
//  queue.cpp
//  queue
//
//  Created by Jae Won Hyun on 11/6/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#include <iostream>
#include "queue.h"
#include "node.h"
using namespace std;

Queue::Queue()
{
    front = NULL;
    end = NULL;
}

// successfully add a new customer and then check to see if we have
bool Queue::didweaddacustomer(int numberofcustomers, int currentminute)
{
    // yes or no answer
    bool answer = false;
    
    // initiate a new customer
    Node customer;
    
    // end pointer points to
    // 1. at first end is pointing to NULL
    // 2. next end will always point to the end of the list
    end = customer.inCustomer(end, numberofcustomers, currentminute);
    
    // if the end is pointing to something
    if(end != NULL)
    {
        // if the front is pointing to nothing
        if(front == NULL)
        {
            // have front pointer point point to whatever the end pointer is pointing to
            front = end;
        }
        
        // yes we did!
        answer = true;
    }
    
    return answer;
}

// let's serve the customer!
void Queue::servefirstCustomer(Node* firstcustomer)
{
    // if there a customer? yes!
    if(front != NULL)
    {
        // serve the first customer and say bye
        front = firstcustomer->outCustomer(front);
            
        // if the front of the list is not pointing to anything, it means that there is no one left in the list
        if(front == NULL)
        {
            // make sure the end is not poiting to anything as well since there is no end!
            end = NULL;
        }
    }
    // psych. there are no customers. if the front of the list is not pointing to anything
    else
    {
        cout << "The line is empty" << endl;
    }
}

int Queue::getpreviouscustomerentryminute()
{
    return end->getentryminute();
}


//set the duration of minutes
void Queue::duration()
{
    cout << "enter how long you want the line to run for between 10 to 60 minutes: ";
    int userinputduration;
    cin >> userinputduration;
    
    while(userinputduration <= 10 || userinputduration >= 60)
    {
        cout << "Sorry, invalid time. Please try again";
        cin >> userinputduration;
    }

    if(!cin.eof() && cin.good())
    {
        if(userinputduration > 10 && userinputduration < 60)
        {
            timeduration = userinputduration;
        }
        else
        {
            cout << "Sorry, invalid input";
        }
    }
    else
    {
        cout << "Sorry, wrong input. Good bye";
    }
}

int Queue::getduration()
{
    return timeduration;
}

void Queue::fixservicetime(Node* currentcustomer, int decreasedtime)
{
    currentcustomer->setservicetime(decreasedtime);
}

void Queue::fixwaittime(Node* currentcustomer, int decreasedtime)
{
    currentcustomer->setwaittime(decreasedtime);
}

void Queue::fixremainingtime(Node*currentcustomer, int decreasedtime)
{
    currentcustomer->setremainingtime(decreasedtime);
}

void Queue::gothroughtheline(int currenttime)
{
    if(front != NULL)
    {
        Node* temp;
    
        for(temp = front; temp != NULL; temp = temp->getNextCustomer())
        {
                cout << "\nminute: " << currenttime;
                cout << "   customer number: " << temp->getcustomernumber();
                cout << "   entry minute: " << temp->getentryminute();
                cout << "   service time remaining: " << temp->getservicetime();
                cout << "   wait time remaining: " << temp->getwaittime();
                cout << "   time until service is finished: " << temp->getminutesremaining() << "\n";
        }
    }
    else
    {
        cout << "\nminute: " << currenttime;
        cout << "   customer number: 0";
        cout << "   entry minute: 0";
        cout << "   service time remaining: 0";
        cout << "   wait time remaining: 0";
        cout << "   time until service is finished: 0\n";
    }
}

void Queue::getcurrentcustomer()
{
    if(front != NULL)
    {
        cout << "   customer number: " << end->getcustomernumber();
        cout << "   entry minute: " << end->getentryminute();
        cout << "   service time remaining: " << end->getservicetime();
        cout << "   wait time remaining: " << end->getwaittime();
        cout << "   time until service is finished: " << end->getminutesremaining() << "\n";
    }
    else
    {
        cout << "The line is empty. No more customers";
    }
}

// decreasing all nodes
void Queue::decreaseallnodes(int countertime, int currenttime)
{
    
    Node* temp;
    int waitindicator;
    int serviceindicator;
    int remainingtimeindicator;
    
    // if the counter is bigger than the current time,
    if(countertime > currenttime)
    {
        // iterate through the line
        for(temp = front; temp != NULL; temp = temp->getNextCustomer())
        {
            waitindicator = temp->getwaittime();
            serviceindicator = temp->getservicetime();
            remainingtimeindicator = temp->getminutesremaining();
            
            // if the customer does not have anyone in front of her
            if(waitindicator == 0)
            {
                waitindicator = waitindicator - 0;
                fixwaittime(temp, waitindicator);
            }
            // if the customer does have someone in front of her
            else
            {
                waitindicator = waitindicator - 1;
                fixwaittime(temp, waitindicator);
            }
            
            // if the customer does have someone ahead of them and the previous customer's time remaining does not equal 0,
            if(temp->getPrevCustomer() != NULL && temp->getPrevCustomer()->getminutesremaining() != 0)
            {
                // don't do anything to the service indicator
                serviceindicator = serviceindicator - 0;
                fixservicetime(temp, serviceindicator);
                
                fixremainingtime(temp, waitindicator + serviceindicator);
            }
            // otherwise
            else
            {
                // decrease service indicator by one minute
                serviceindicator = serviceindicator - 1;
                
                fixservicetime(temp, serviceindicator);
                fixremainingtime(temp, waitindicator + serviceindicator);
            
            }
            
            // if the remaining time equals 1, serve the customer and delete the node
            if(remainingtimeindicator == 1)
            {
                servefirstCustomer(temp);
            }
        }
    }
}

Node* Queue::returnend()
{
    return end;
}
