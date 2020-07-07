#include "_Common.h"
#include <Windows.h>
#include <conio.h>
#include "_Point.h"
#include "_Board.h"
#include "_Game.h"
#include"_Menu.h"

using namespace std;

int main()
{
	_Common::resizeConsole(1920, 1080);
	_Menu menu;
	menu.printMenu();
	/*for (int i = 0; i < 255; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		cout << i << endl;
	}*/
}