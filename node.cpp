//
//  node.cpp
//  node
//
//  Created by Jae Won Hyun on 11/6/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#include "node.h"
#include <iostream>
using namespace std;

// default constructor
Node::Node()
{
    
}

// input a new customer at the end of the list
Node* Node::inCustomer(Node* endptr, int newcustomernumber, int currentminute)
{
    // initiate a customer pointer
    Node* temp = NULL;
    
    // if a new customer can be added and pointed by temp
    if((temp = new Node))
    {
        // new node's previous customer would point to the whatever the end pointer was pointing to
        temp->prevCustomer = endptr;
        // new customer's info would be s
        temp->customernumber = newcustomernumber;
        // indicate which minute that they came in at
        temp->entryminute = currentminute;
        // set individual service time
        setindividualservicetime(temp, newcustomernumber);
        // set individual wait time which is equal to the previous customer wait time
        // set minutes remaining until service is finished
        // new customer doesn't have a next customer yet because she's the last in line
        temp->nextCustomer = NULL;
        setindividualwaittime(temp, newcustomernumber);
        temp->minutesremaining = temp->individualservicetime + temp->individualwaittime;
        // new customer points to the previously last customer
        
        // if the end ptr was pointing to the previously last customer ,
        if(endptr != NULL)
        {
            // have the previuosly last customer point to the new customer pointed to by temp
            endptr->nextCustomer = temp;
        }
    }
    
    return temp;
    
}

void Node::setindividualwaittime(Node* currentcustomer, int numberofcustomers)
{
    Node* pointer;
    pointer = currentcustomer->prevCustomer;
    
    if(numberofcustomers > 1)
    {
        if(pointer != NULL)
        {
            currentcustomer->individualwaittime = pointer->getminutesremaining();
        }
        else
        {
            currentcustomer->individualwaittime = 0;
        }
    }
    else
    {
        currentcustomer->individualwaittime = 0;
    }
}

void Node::setindividualservicetime(Node* currentcustomer, int numberofcustomers)
{
    int randomnumber;
    
    int max = 4;
    int min = 2;
    
    randomnumber = rand()% (max + 2 - min) + min;
    currentcustomer->individualservicetime = randomnumber;
}


// deleting a customer
Node* Node::outCustomer(Node* firstCustomer)
{
    // initiate a customer pointer
    Node* temp;
    
    // have the customer pointer point to the person after the first customer
    temp = firstCustomer->nextCustomer;
    // then serve the first customer and say bye
    delete firstCustomer;
    
    // if the customer pointer is pointing to the person after the first customer
    // meaning if the first customer was not the only customer in line
    if(temp != NULL)
    {
        // have the new first customer point to no one in front of her LOL
        temp->prevCustomer = NULL;
    }
    
    // return the new front of the list
    return temp;
}

// get the next customer on the list
Node* Node::getNextCustomer ()
{
    // return the next customer
    return nextCustomer;
}

// get the previous customer on the ilst
Node* Node::getPrevCustomer()
{
    // return the previous customer
    return prevCustomer;
}

int Node::getentryminute()
{
    return entryminute;
}

// return the customer number
int Node::getcustomernumber()
{
    // return information about the Customer
    return customernumber;
}

int Node::getservicetime()
{
    return individualservicetime;
}

int Node::getwaittime()
{
    return individualwaittime;
}

int Node::getminutesremaining()
{
    return minutesremaining;
}

void Node::setservicetime(int newtime)
{
    individualservicetime = newtime;
}

void Node::setwaittime(int newtime)
{
    individualwaittime = newtime;
}

void Node::setremainingtime(int newtime)
{
    minutesremaining = newtime;
}

// decrease each customer's time
void Node::decreasetime(Node* currentcustomer)
{
    int waitindicator;
    
    // waitindicator is current customer's reamining service time
    waitindicator = currentcustomer->individualservicetime;
    
    // if the remaining service time is 0,
    if(waitindicator == 0)
    {
        // just decrease it by nothing
        waitindicator = waitindicator - 0;
    }
    // if the remaining service time is not 0,
    else
    {
        // if the wait indicator is still bigger than 0, decrease by 1 everytime this function is called
        waitindicator = waitindicator - 1;
    }
}
