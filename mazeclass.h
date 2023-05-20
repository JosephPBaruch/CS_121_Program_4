/* mazeclass.h 
   Joseph Baruch 
   CS 121
 */

#ifndef MAZECLASS_H // file guards
#define MAZECLASS_H

#include <iostream> 
#include <fstream>

#include "Queue.h"

using namespace std;

class MazeClass{
public:
    MazeClass(); // constructor 
    ~MazeClass(); // deconstructor 
    void moveEnqueue(); 
    void dequeue();
    void Print(); 
    char currChar; // current character 
    int printCounter; // Counts the number of steps
    int printEvery; // print every amount time
private:
    int choice; 
    int width; // width of array
    int height; // height of array
    int x; // == col 
    int y; // == row
    Queue myQ; // declares class instance 
    char **mazeArr; // 2D array variable 
};

#endif // file guards 
