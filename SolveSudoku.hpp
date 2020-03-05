//*****************************************************************
// Name: Ye Harvey Xia  Student ID: 121866
// Name: Yixin Wang  	Student ID: 121877
// Course: C SC 362
// Assignment 3 - Sudoku Game
// SolveSudoku.hpp
// Define SolveSudoku class which declare readPuzzle, passPuzzle,
// printSolve method and a Sudoku object.
//*****************************************************************
#include "Sudoku.hpp"

class SolveSudoku{
	private:
	Sudoku sudoku;
	public:
	SolveSudoku(){}//constructor
	//~SolveSudoku(){}//destructor
	bool readPuzzle(FreeCell **&map, int&, int&);//read puzzle from txt file
	void passPuzzle(FreeCell **&map, int&, int&);//pass puzzle to Sudoku
	void printSolve();//print solution
};
