//*****************************************************************
// Name: Ye Harvey Xia  Student ID: 121866
// Name: Yixin Wang  	Student ID: 121877
// Course: C SC 362
// Assignment 3 - Sudoku Game
// SolveSudoku.cpp
// Define SolveSudoku class which has the main method, readPuzzle,
// passPuzzle, printPuzzle, to play the Sudoku game.
//*****************************************************************
#include "SolveSudoku.hpp"
#include <fstream>
// main method
int main(){
	FreeCell **map;//declare the double pointer
	int x, y;//declare the row and col for arrary
	bool readFile;
	x = 9;
	y = 9;
	map = new FreeCell*[x];
	for(int i = 0; i < x; i ++)
		map[i] = new FreeCell[y];//make an arrary
	SolveSudoku ss;//declare a SolveSudoku object
	int nextOne = 0;//define a continue sign for user choice
	do{
        do{
            //read a puzzle from a file
            readFile = ss.readPuzzle(map, x, y);
        }while(!readFile);//if it is not an exist file, return to read
        ss.passPuzzle(map, x, y);//pass the puzzle to solve
        cout << "Do you want to read another file?" << endl;
        cout << "0. No" << endl;
        cout << "1. Yes" << endl;
        cin >> nextOne;
	}while(nextOne);
	return 0;
}
//read a puzzle from a file
bool SolveSudoku::readPuzzle(FreeCell **&map, int &x, int &y){
	int value;
	char filename[20];//define a arrary to store the filename
	cout << "Please input the txt file name which has a puzzle you want to solve (*.txt):" << endl;
	cin >> filename;
	cout << "Read a puzzle from " << filename << " :" << endl;
	ifstream fin(filename);
	if(fin == NULL){//if the file is not exist
	    cout << "you input a wrong filename, please try again." << endl;
	    fin.close();
        return false;
    }else{//if the file is exist
        for(int i = 0; i < x; i ++){
            for(int j = 0; j < y; j ++){
                fin>>value;//read the data
                if(value==0){//if the value is 0, define a FreeCell object
                    map[i][j]=FreeCell((int)i, (int)j, (int)value);
                }else{//if the value is not 0, define a FixedCell object
                    map[i][j]=FixedCell((int)i, (int)j, (int)value);
                }//end of if-else
            }//end of for-col
        }//end of for-row
        fin.close();//close file stream
        //display the puzzle which is read from file
        for(int i = 0; i < x; i ++){
            for(int j = 0; j < y; j ++)
                cout << map[i][j] << " ";
            cout << endl;
        }
        return true;
    }
}
//pass the puzzle to solve it
void SolveSudoku::passPuzzle(FreeCell **&map, int &x, int &y){
    sudoku.resetCountBack();//reset the guess times to 0
	if(sudoku.traverse(0, map, x, y))
		printSolve();//if find a solution, print it
	else
		cout << "Failed to find a solution!" << endl;
}
// print the solution
void SolveSudoku::printSolve(){
	cout << sudoku << endl;
}
