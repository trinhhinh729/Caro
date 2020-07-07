#include <iostream>
#include "_Common.h"
#include <Windows.h>
#include <conio.h>
#include "_Point.h"
#include "_Board.h"

using namespace std;

int _Board::getSize() { return _size; }
int _Board::getLeft() { return _left; }
int _Board::getTop() { return _top; }
int _Board::getXAt(int i, int j)
{
	return _pArr[i][j].getX();
}
int _Board::getYAt(int i, int j)
{
	return _pArr[i][j].getY();
}
_Board::_Board()
{
	_size = 10;
	_left = 0;
	_top = 0;
	_pArr = new _Point * [_size];
	for (int i = 0; i < _size; i++) _pArr[i] = new _Point[_size];
}
_Board::_Board(int pSize, int pX, int pY)
{
	_size = pSize;
	_left = pX;
	_top = pY;
	_pArr = new _Point * [pSize];
	for (int i = 0; i < pSize; i++) _pArr[i] = new _Point[pSize];
}
_Board::~_Board()
{
	for (int i = 0; i < _size; i++) delete[] _pArr[i];
	delete[] _pArr;
}
void _Board::resetData()
{
	if (_size == 0) return; // Firstly calling constructor before calling resetData
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			_pArr[i][j].setX(4 * j + _left + 2); // x-value of boardgame
			_pArr[i][j].setY(2 * i + _top + 1); // y-value of boardgame
			_pArr[i][j].setCheck(0);
		}
	}
}
void _Board::drawBoard()
{
	if (_pArr == NULL) return; // firstly call constructor
	char a = char(179); //│
	char b = char(196); //─
	char c = char(218); //┌
	char d = char(217); // ┘
	char e = char(192); //└
	char f = char(191); //┐
	char g = char(193); // ┴
	char h = char(194); //┬
	char l = char(195); // ├
	char m = char(197); //┼
	char k = char(180); // ┤

	int wPix = 4 * 17;
	int hPix = 2 * 17;
	system("color F0");
	//_Common::setTextColor(7, 0);
	for (int i = 0; i <= wPix; i++)
	{
		for (int j = 0; j <= hPix; j++)
		{
			_Common::gotoXY(i, j);
			if (i == 0 and j == 0)
			{
				cout << c;
			}
			else if (i == 0 and j == hPix)
			{
				cout << e;
			}
			else if (i == wPix and j == 0)
			{
				cout << f;
			}
			else if (i == wPix and j == hPix)
			{
				cout << d;
			}
			else if (i % 4 == 0)
			{
				if (j == 0)
				{
					cout << h;
				}
				else if (j == hPix)
				{
					cout << g;
				}
				else if (j % 2 != 0)
				{
					cout << a;
				}
				else if (i == 0)
				{
					cout << l;
				}
				else if (i == wPix)
				{
					cout << k;
				}
				else if (j % 2 == 0)
				{
					cout << m;
				}
			}
			else if (j % 2 == 0)
			{
				if (i == 0)
				{
					cout << l;
				}
				else if (i == wPix)
				{
					cout << k;
				}
				else
				{
					cout << b;
				}
			}
		}
	}
	_Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());//move to the 1st cell
}
int _Board::checkBoard(int pX, int pY, bool pTurn)
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
			{
				if (pTurn) _pArr[i][j].setCheck(-1);// If current turn is true: c = -1
				else _pArr[i][j].setCheck(1);// If current turn is false: c = 1
				return _pArr[i][j].getCheck();
			}
		}
	}
	return 0;
}


bool checkDoc(int curx, int cury, _Point** _pArr, int _size)
{
	//check doc
	int tmp = _pArr[curx][cury].getCheck();
	int i = curx;
	int j = cury;
	int count = 0;
	while (i < _size && _pArr[i][j].getCheck() == tmp)
	{
		i++;
		count++;
	}
	i = curx;
	while (i >= 0 && _pArr[i][j].getCheck() == tmp)
	{
		i--;
		count++;
	}
	if (count == 6) return 1;// xem ai thang -1 la X (danh truoc), 1 la O
	return 0; // chua danh xong
}
bool checkNgang(int curx, int cury, _Point** _pArr, int _size)
{
	//check doc
	int tmp = _pArr[curx][cury].getCheck();
	int i = curx;
	int j = cury;
	int count = 0;
	while (j < _size && _pArr[i][j].getCheck() == tmp)
	{
		j++;
		count++;
	}
	j = cury;
	while (j >= 0 && _pArr[i][j].getCheck() == tmp)
	{
		j--;
		count++;
	}
	if (count == 6) return 1;// xem ai thang -1 la X (danh truoc), 1 la O
	return 0; // chua danh xong
}

bool checkCheoChinh(int curx, int cury, _Point** _pArr, int _size)
{
	//check doc
	int tmp = _pArr[curx][cury].getCheck();
	int i = curx;
	int j = cury;
	int count = 0;
	while (i < _size && j < _size && _pArr[i][j].getCheck() == tmp)
	{
		i++;
		j++;
		count++;
	}
	i = curx;
	j = cury;
	while (i >= 0 && j >= 0 && _pArr[i][j].getCheck() == tmp)
	{
		i--;
		j--;
		count++;
	}
	if (count == 6) return 1;// xem ai thang -1 la X (danh truoc), 1 la O
	return 0; // chua danh xong
}

bool checkCheoPhu(int curx, int cury, _Point** _pArr, int _size)
{
	//check doc
	int tmp = _pArr[curx][cury].getCheck();
	int i = curx;
	int j = cury;
	int count = 0;
	while (i < _size && j >= 0 && _pArr[i][j].getCheck() == tmp)
	{
		i++;
		j--;
		count++;
	}
	i = curx;
	j = cury;
	while (i >= 0 && j < _size && _pArr[i][j].getCheck() == tmp)
	{
		i--;
		j++;
		count++;
	}
	if (count == 6) return 1;// xem ai thang -1 la X (danh truoc), 1 la O
	return 0; // chua danh xong
}

int _Board::testBoard(int x, int y) {
	int count = 0;
	int curx, cury;
	bool check = false;
	//Kiem tra bàn cờ có đầy hay khong?
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getCheck() == 0)
				check = true;
		}
	}

	if (check)
	{
		for (int i = 0; i < _size; i++)
		{
			for (int j = 0; j < _size; j++)
			{
				if (_pArr[i][j].getX() == x and _pArr[i][j].getY() == y)
				{
					curx = i;
					cury = j;
					break;
				}
			}
		}

		if (checkNgang(curx, cury, _pArr, _size) || checkDoc(curx, cury, _pArr, _size) || checkCheoChinh(curx, cury, _pArr, _size) || checkCheoPhu(curx, cury, _pArr, _size))
		{
			return _pArr[curx][cury].getCheck();
		}
		else
		{
			return 2;
		}
	}
	else
		return 0; // Draw
} // Defaultly returns ‘Draw
