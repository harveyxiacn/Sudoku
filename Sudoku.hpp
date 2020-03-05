//*****************************************************************
// Name: Ye Harvey Xia  Student ID: 121866
// Name: Yixin Wang  	Student ID: 121877
// Course: C SC 362
// Assignment 3 - Sudoku Game
// Sudoku.hpp
// Define Sudoku class declares mathods to solve a puzzle
//*****************************************************************
#include "FixedCell.hpp"
class Sudoku{
	private:
	int countBack, count;
	FreeCell **mapResult;
	public:
	Sudoku();//constructor
	//~Sudoku();
	bool isPlace(int, FreeCell&, FreeCell **&, int&, int&);//check if the puzzle accept this cell
	bool traverse(int, FreeCell **&, int&, int&);//backtrace for attempting
	void resetCountBack();//reset countBack;
	int getCountBack();//get countBack
	int printMap(int, int);//print the map
	// overload << operator
	friend ostream & operator<<(ostream &out, Sudoku &p);
};
