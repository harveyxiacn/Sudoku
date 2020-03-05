//*****************************************************************
// Name: Ye Harvey Xia  Student ID: 121866
// Name: Yixin Wang  	Student ID: 121877
// Course: C SC 362
// Assignment 3 - Sudoku Game
// FixedCell.cpp
// Define the methods in FixedCell
//*****************************************************************
#include "FixedCell.hpp"
//constructor
FixedCell::FixedCell(int x, int y, int v):FreeCell(x, y, v){
	freeNFixed();
}
//set location_x
void FixedCell::setX(int x){
	setLocationX(x);
}
//get location_x
int FixedCell::getX(){
	return getLocationX();
}
//set location_y
void FixedCell::setY(int y){
	setLocationY(y);
}
//get location_y
int FixedCell::getY(){
	return getLocationY();
}
//set value
void FixedCell::setValues(int v){
	setValue(v);
}
//get value
int FixedCell::getValues(){
	return getValue();
}
//overload the operator <<
ostream & operator<<(ostream &out, FixedCell &c){
	out << c.getValues();
	return out;
}
