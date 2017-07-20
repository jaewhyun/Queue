//
//  node.h
//  node
//
//  Created by Jae Won Hyun on 11/6/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#ifndef node_h
#define node_h

#include <iostream>
using namespace std;

class Node
{
public:
    Node ();
    Node* inCustomer(Node*, int, int);
    Node* outCustomer(Node*);
    Node* getNextCustomer();
    Node* getPrevCustomer();
    void setindividualwaittime(Node*, int);
    void setindividualservicetime(Node*, int);
    int getcustomernumber();
    int getentryminute();
    int getservicetime();
    int getwaittime();
    int getminutesremaining();
    void decreasetime(Node*);
    void setservicetime(int);
    void setwaittime(int);
    void setremainingtime(int);
    
private:
    int customernumber = 0;
    int entryminute;
    int individualservicetime;
    int individualwaittime = 2;
    int minutesremaining = 0;
    Node* nextCustomer;
    Node* prevCustomer;
};

#endif /* node_h */
