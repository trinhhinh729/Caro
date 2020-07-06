#pragma once
#include "_Point.h"
class _Board: public _Point {
private:
	int _size;
	int _left, _top;
	_Point** _pArr;
public:
	_Board();
	_Board(int, int, int);
	~_Board();
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	void resetData();
	void drawBoard();
	int checkBoard(int, int, bool);
	int testBoard(int, int);
};