//*****************************************************************
// Name: Ye Harvey Xia  Student ID: 121866
// Name: Yixin Wang  	Student ID: 121877
// Course: C SC 362
// Assignment 3 - Sudoku Game
// FreeCell.hpp
// Define BJcard class which declare location variables, value,
// freeCell, the getters and setters, freeNFixed, isFreeCell
// and overload << operator
//*****************************************************************
#include <iostream>
using namespace std;
class FreeCell{
	private:
	int location_x, location_y, value;
	bool freeCell;
	public:
	FreeCell();//default constructor
	FreeCell(int, int, int);//constructor
	//~FreeCell();//destructor
	void setLocationX(int x);//set location_x
	int getLocationX();//get location_x
	void setLocationY(int y);//set location_y
	int getLocationY();//get location_y
	void setValue(int v);//set value
	int getValue();//get value
	// overload << operator
	friend ostream & operator<<(ostream &out, FreeCell &p);
	void freeNFixed();//flip free and fixed
	bool isFreeCell();//return if it is a free cell or not
};
