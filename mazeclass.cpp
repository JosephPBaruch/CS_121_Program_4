/* mazeclass.cpp
   Joseph Baruch
   CS 121
 */

#include <iostream>
#include <fstream>

#include "mazeclass.h"

using namespace std;

MazeClass::MazeClass(){
    ifstream myFile; // open file 

    do{ // loops if user input is invalid
        cout << "Which Maze would you like to choose? " << endl;
        cout << "   1 = (5 x 5) " << endl;
        cout << "   2 = (10 x 10) " << endl;
        cout << "   3 = (20 x 20) " << endl;
        cout << "   4 = (40 x 40) " << endl;
        cout << "Maze: ";
        cin >> choice;
    }while( choice != 1 && choice != 2 && choice != 3 && choice != 4 );
        // file is opened according to user
        // printEvery is change depending on size of maze
        switch( choice ){ // user chooses maze
            case 0: // base case
                break;
            case 1: 
                myFile.open("maze1.txt");
                printEvery = 5;
                break;
            case 2:
                myFile.open("maze2.txt");
                printEvery = 15;
                break;
            case 3:
                myFile.open("maze3.txt");
                printEvery = 50;
                break;
            case 4:
                myFile.open("maze4.txt");
                printEvery = 250;
                break;
        }
        
        myFile >> width; // read in height and width
        myFile >> height;

        mazeArr = new char *[height]; // allocate 2d array

        for( int i = 0; i < height; i++){
            mazeArr[i] = new char[width];
        }

        // initialize 2d array by reading file 
        for(int i = 0; i < height; i++){  
            for(int j = 0; j < width; j++){
                myFile >> mazeArr[i][j];
            }
        }

        myFile.close();  // close file

        // find 's', init x and y, enqueue
        for(int i = 0; i < height; i++){   
            for(int j = 0; j < width; j++){
                if( mazeArr[i][j] == 'S'){ 
                    x = j;
                    y = i;
                    myQ.Enqueue(x,y);
                }
            }
        }
    // initialize printing aids
    printCounter = 0; 
}

MazeClass::~MazeClass(){
    myQ.~Queue(); // deletes queue
   
    // deallocate 2D array
    for( int i = 0; i < height; i ++ ){  
        delete [] mazeArr[i];
    }    
    delete [] mazeArr;
}

void MazeClass::moveEnqueue(){ 
    // if north exists
    if( 0 <= (y - 1) ){ // north
        // if north is unvisited
        if(mazeArr[y - 1][x] == '.'){  
            // enqueue
            myQ.Enqueue(x, (y - 1));
            // make north visited (invalid)   
            mazeArr[y - 1][x] = '^';   
        }
        // check for 'G'
        if(mazeArr[y - 1][x] == 'G' ){ 
            // will break loop
            currChar = 'G';
        }
    }

    if( (width - 1) >= (x + 1) ){ // east
        if(mazeArr[y][x + 1] == '.'){
            myQ.Enqueue((x + 1), y); 
            mazeArr[y][x + 1] = '>';
        }
        if(mazeArr[y][x + 1] == 'G' ){ 
            currChar = 'G';
        }
    }

    if( (height - 1) >= (y + 1) ){ // south
        if(mazeArr[y + 1][x] == '.'){
            myQ.Enqueue(x, (y + 1)); 
            mazeArr[y + 1][x] = 'V';
        }
        if(mazeArr[y + 1][x] == 'G' ){ 
            currChar = 'G';
        }
    }
    
    if( 0 <= (x - 1) ){ // west
        if(mazeArr[y][x - 1] == '.'){
            myQ.Enqueue((x - 1), y); 
            mazeArr[y][x - 1] = '<';
        }
        if(mazeArr[y][x - 1] == 'G' ){ 
            currChar = 'G';
        }
    }
}

void MazeClass::dequeue(){
    // dequeue next current position
    myQ.Dequeue(x, y); 
    // set currChar
    currChar = mazeArr[y][x]; 
}

void MazeClass::Print(){
    
    printCounter++;
    // prints array every pritnEvery times
    if(printCounter % printEvery == 0 || currChar == 'G'){ 

        cout << "Move: " << printCounter << endl;

        for(int i = 0; i < height; i++){ 
            for(int j = 0; j < width; j++){
                cout << mazeArr[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}
