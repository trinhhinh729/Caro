#pragma once
#include <string>
using namespace std;
class _Common {

public:
	static void fixConsoleWindow();
	static void gotoXY(int, int);
	static void resizeConsole(int, int);
	static void printTextAt(string, int, int);
	static void setFontSize(int);
	static void setTextColor(int, int);
	static void highlight(int, int, int x, int y);
};
