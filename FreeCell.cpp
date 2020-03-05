//*****************************************************************
// Name: Ye Harvey Xia  Student ID: 121866
// Name: Yixin Wang  	Student ID: 121877
// Course: C SC 362
// Assignment 3 - Sudoku Game
// FreeCell.cpp
// Define the methods in FreeCell class
//*****************************************************************
#include "FreeCell.hpp"
//default constructor
FreeCell::FreeCell(){
	location_x = -1;
	location_y = -1;
	value = 0;
	freeCell = true;
}
//constructor
FreeCell::FreeCell(int x, int y, int v){
	location_x = x;
	location_y = y;
	value = v;
	freeCell = true;
}
/*FreeCell::~FreeCell(){
	delete &location_x;
	delete &location_y;
	delete &value;
}//destructor*/
//set location_x
void FreeCell::setLocationX(int x){
	location_x = x;
}
//get location_x
int FreeCell::getLocationX(){
	return location_x;
}
//set location_y
void FreeCell::setLocationY(int y){
	location_y = y;
}
//get location_y
int FreeCell::getLocationY(){
	return location_y;
}
//set value
void FreeCell::setValue(int v){
	value = v;
}
//get value
int FreeCell::getValue(){
	return value;
}
//overload the operator <<
ostream & operator<<(ostream &out, FreeCell &c){
	out << c.getValue();
	return out;
}
//flip free and fixed
void FreeCell::freeNFixed(){
	freeCell = !freeCell;
}
//return if is a freeCell or not
bool FreeCell::isFreeCell(){
	return freeCell;
}
