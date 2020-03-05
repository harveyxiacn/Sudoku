//*****************************************************************
// Name: Ye Harvey Xia  Student ID: 121866
// Name: Yixin Wang  	Student ID: 121877
// Course: C SC 362
// Assignment 3 - Sudoku Game
// Sudoku.cpp
// Define methods in Sudoku class
//*****************************************************************
#include "Sudoku.hpp"
//constructor
Sudoku::Sudoku(){
		countBack = 0;
		//backtrace(0, map, x, y);
}//constructor
//destructor
/*Sudoku::~Sudoku(){
	delete &count;
	delete &countBack;
	//delete map;
}*/
//check if the puzzle accept this cell
bool Sudoku::isPlace(int value, FreeCell& cell, FreeCell **&map, int &x, int &y){
    int row = cell.getLocationX();
    int col = cell.getLocationY();
    //same row
    int i;
    for(i = 0; i < x; i++){
        if((map[row][i].getValue() == value) && (i != col)){
			//cout << "("<<row<<", "<<i<<") has " <<cell.getValue()<<" fail"<< endl;
            return false;
        }
    }
    //same col
    for(i = 0; i < y; i++){
        if((map[i][col].getValue() == value) && (i != row)){
			//cout << "("<<i<<", "<<col<<") has " <<cell.getValue()<<" fail"<< endl;
            return false;
        }
    }
    //same square
    int tempRow = row / 3 * 3;
    int tempCol = col / 3 * 3;
    for(i = tempRow; i < tempRow + 3; i++){
        for(int j = tempCol; j < tempCol + 3; j++){
            if((map[i][j].getValue() == value) && (i != row) && (j != col)){
				//cout << "("<<i<<", "<<j<<") has " <<cell.getValue()<<" fail"<< endl;
                return false;
            }
        }
    }
    //cout << "successful! row: " << row << " col: " << col << " value: " << cell.getValue() << endl;
    return true;
}
//backtrace for attempting
bool Sudoku::traverse(int count, FreeCell **&map, int &x, int &y){
	//cout << "begin level " << count << endl;
    if(count == 81){
        cout<<"Result："<<endl;
        mapResult = map;
        return true;
    }
	int row = count / 9;
	int col = count % 9;
	if(map[row][col].getValue()==0){
		//cout << "is free cell, try" << endl;
		for(int i = 1; i <= 9; ++i){
		countBack++;
		//cout << "attempt: " << i << endl;
		if(isPlace((int)i, map[row][col], map, x, y)){//if can place
			map[row][col].setValue(i);//set value
			if(traverse(count+1, map, x, y))
				return true;//enter next guess
		}
	}
	//cout  << "fail, backtrace: level " << count-1 << endl;
		map[row][col].setValue(0);//backtrace
		return false;
	}else{
		//cout << "is a fixed cell, move to next cell" << endl;
		return(traverse(count+1, map, x, y));
	}
}
//reset countBack;
void Sudoku::resetCountBack(){
    countBack = 0;
}
//get countBack
int Sudoku::getCountBack(){
	return countBack;
}
//print the map
int Sudoku::printMap(int x, int y){
	return mapResult[x][y].getValue();
}
// overload << operator
ostream & operator<<(ostream &out, Sudoku &p){
	out << "Attempt times: " << p.getCountBack() << endl;
		cout << "Find the solution:" << endl;
		for(int i = 0; i < 9; i ++){
			for(int j = 0; j < 9; j ++)
				out << p.printMap(i, j) << " " ;
			out << endl;
		}
	return out;
}
