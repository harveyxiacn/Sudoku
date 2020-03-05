CC=g++
CFLAGS=-c -Wall

head = FreeCell.hpp FixedCell.hpp Sudoku.hpp SolveSudoku.hpp
source = FreeCell.cpp FixedCell.cpp Sudoku.cpp SolveSudoku.cpp
obj = FreeCell.o FixedCell.o Sudoku.o SolveSudoku.o

all: SudokuGame

SudokuGame: $(obj)
	$(CC) $(obj) -o $@

FreeCell.o: FreeCell.cpp
	$(CC) $(CFLAGS) $< 

FixedCell.o: FixedCell.cpp
	$(CC) $(CFLAGS) $<

Sudoku.o: Sudoku.cpp
	$(CC) $(CFLAGS) $<

SolveSudoku.o: SolveSudoku.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *o SudokuGame
tarAll:
	tar -cvf YeHarveyXia_YixinWang_ast3.tar *
