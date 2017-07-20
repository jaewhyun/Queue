//
//  queue.h
//  queue
//
//  Created by Jae Won Hyun on 11/6/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//



#ifndef queue_h
#define queue_h

#include <iostream>
#include "node.h"

using namespace std;

//#include "BagList.h"
class Queue
{  //Container class
public:
    Queue (); // default constructor
    bool didweaddacustomer(int, int);
    void servefirstCustomer(Node*);
    void duration();
    void gothroughtheline(int);
    int getduration();
    void decreaseallnodes(int, int);
    void fixservicetime(Node*, int);
    void fixwaittime(Node*, int);
    void fixremainingtime(Node*, int);
    void getcurrentcustomer();
    int getpreviouscustomerentryminute();
    Node* returnend();
    
private:
    Node* front;
    Node* end;
    int timeduration;
    bool isthereacustomer;
};

#endif /* queue_h */
