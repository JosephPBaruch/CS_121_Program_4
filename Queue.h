/* Queue.h
   Joseph Baruch 
   CS 121
 */ 

#ifndef QUEUE_H // file guards
#define QUEUE_H

#include <iostream> 

using namespace std;

class Queue{
    public:
        Queue(); // constructor
        ~Queue(); // deconstructor 
        void Enqueue(int c, int r); 
        void Dequeue(int& c, int& r); 
    private:
        struct qNode{
            int row; // y coordinate
            int col; // x coordinate
            qNode* next; 
        };
        typedef qNode * QNodePtr;
        QNodePtr head;
};

#endif