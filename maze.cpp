/* maze.cpp
   Joseph Baruch
   Professor: Bruce Bolden 
   CS 121
   Due: 4/7/2023
 */

#include <iostream> 
#include "mazeclass.h"

using namespace std;

void solveMaze(); // prototype

int main(){
    
  int cont = 1;

  while(cont == 1 ){ // user chooses to loop 

    solveMaze(); 

    do{ // check for valid input
      cout << "Continue? (Yes = 1, No = 0): ";
      cin >> cont;
      cout << endl;
    }while( cont != 1 && cont != 0 ); 
  }
}

void solveMaze(){

  // declare class instance (contructor runs)
  MazeClass maze; 
    // loop until current position is the goal
    while( maze.currChar != 'G' ){  
      // update currChar and gets current position 
      maze.dequeue(); 
      // Checks for valid move and enqueue 
      maze.moveEnqueue(); 
      // prints output      
      maze.Print();      
    }
}
