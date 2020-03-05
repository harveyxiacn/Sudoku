//*****************************************************************
// Name: Ye Harvey Xia  Student ID: 121866
// Name: Yixin Wang  	Student ID: 121877
// Course: C SC 362
// Assignment 3 - Sudoku Game
// FixedCell.hpp
// Define FixedCell class which extends from FreeCell class
// declare getters and setters, overload the << operator
//*****************************************************************
#include "FreeCell.hpp"

class FixedCell:public FreeCell{
	public:
	FixedCell();//default constructor
	FixedCell(int x, int y, int v);//constructor
	//~FixedCell():~FreeCell(){}//destructor
	void setX(int x);//set location_x
	int getX();//get location_x
	void setY(int y);//set location_y
	int getY();//get location_y
	void setValues(int v);//set value
	int getValues();//get value
	// overload << operator
	friend ostream & operator<<(ostream &out, FixedCell &p);
};
