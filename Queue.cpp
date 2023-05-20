/* Queue.cpp
   Joseph Baruch 
   CS 121
 */

#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue(){ 
    head = NULL;
}

Queue::~Queue(){ 

    while( head != NULL){ // go until h == NULL

        QNodePtr del = head; // aux pointer = head
        head = head->next; // move head
        del->next = NULL;    
        delete del; // delete node
    }
    head = NULL; // queue is empty
}

void Queue::Enqueue(int c, int r){ 
    
    QNodePtr n = new qNode; // allocate

    n->row = r; // initialize 
    n->col = c;

    if( head == NULL){ // if queue is empty 
        head = n;
    }else{ 
        QNodePtr p = head; // aux pointer
        // move to the end of the queue
        while( p->next != NULL){ 
            p = p->next;
        }
        p->next = n;
    }
}

void Queue::Dequeue( int& c, int& r){ 
    
    // aux pointer equal to head
    QNodePtr p = head; 

    // updates current position 
    r = head->row; 
    c = head->col;

    if( p == NULL){
        // nothing 
    }else{
        head = p->next;
        p->next = NULL;
        delete p;
    }

}