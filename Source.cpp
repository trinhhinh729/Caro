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
	menu.chooseOptions();
}