#include <iostream>
#include <Windows.h>
using namespace std;

void gotoXY(int pX, int pY) {
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printText(char s, int x, int y)
{
	gotoXY(x, y);
	cout << s;
}

void draw(int weight, int height)
{
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

	int wPix = 4 * weight;
	int hPix = 2 * height;

	for (int i = 0; i <= wPix; i++)
	{
		for (int j = 0; j <= hPix; j++)
		{
			if (i == 0 and j == 0)
			{
				printText(c, i, j);
			}
			else if (i == 0 and j == hPix)
			{
				printText(e, i, j);
			}
			else if (i == wPix and j == 0)
			{
				printText(f, i, j);
			}
			else if (i == wPix and j == hPix)
			{
				printText(d, i, j);
			}
			else if (i % 4 == 0)
			{
				if (j == 0)
				{
					printText(h, i, j);
				}
				else if (j == hPix)
				{
					printText(g, i, j);
				}
				else if (j % 2 != 0)
				{
					printText(a, i, j);
				}
				else if (i == 0)
				{
					printText(l, i, j);
				}
				else if (i == wPix)
				{
					printText(k, i, j);
				}
				else if (j % 2 == 0)
				{
					printText(m, i, j);
				}
			}
			else if (j % 2 == 0)
			{
				if (i == 0)
				{
					printText(l, i, j);
				}
				else if (i == wPix)
				{
					printText(k, i, j);
				}
				else
				{
					printText(b, i, j);
				}
			}
		}
	}
}
