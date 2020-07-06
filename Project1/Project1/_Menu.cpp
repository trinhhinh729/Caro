#include "_Menu.h"
#include "_Common.h"
#include <Windows.h>
#include <conio.h>
#include "_Point.h"
#include "_Board.h"
#include "_Game.h"
#include <iostream>
using namespace std;
void setFontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 0, 0, width, height, TRUE);
}
void SetColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}
_Menu::_Menu()
{
	x = 75;
	y = 25;

}
char _Menu::waitKeyBoard()
{
	_command = toupper(_getch());
	return _command;
}
void _Menu::printMenu()
{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hStdout, 50);
		setFontSize(20);
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "			     ____________________________________________________________________________________________      " << endl;
	cout << "			    |         ___________          ______             ___________            ___________         |     " << endl;
	cout << "			    |        | _________|         /  __  \\           /   _____   \\          /  _______  \\        |     " << endl;
	cout << "			    |       / /                  /  /  \\  \\         |   /     \\   |        /  /       \\  \\       |     " << endl;
	cout << "			    |      / /                  /  /    \\  \\        |   \\_____/   |       |  /         \\  |      |     " << endl;
	cout << "			    |     | |                  /  /______\\  \\       |    _____   /        | |           | |      |     " << endl;
	cout << "			    |     | |                 /  __________  \\      |   /     \\  \\        | |           | |      |     " << endl;
	cout << "			    |      \\ \\               /  /          \\  \\     |  |       \\  \\       |  \\         /  |      |     " << endl;
	cout << "			    |       \\ \\_________    /  /            \\  \\    |  |        \\  \\       \\  \\_______/  /       |     " << endl;
	cout << "			    |        |__________|  /_ /              \\ _\\   |_ |         \\ _\\       \\___________/        |     " << endl;
	cout << "			    |____________________________________________________________________________________________|     " << endl;
	cout << "				                                                                                                       " << endl;
	_Common::gotoXY(75,25);
	cout << "PVP";
	_Common::gotoXY(75,27);
	cout << "PVC";
	_Common::gotoXY(75, 29);
	cout << "Load Game";
	_Common::gotoXY(75, 31);
	cout << "Rule";
	_Common::gotoXY(75, 33);
	cout << "About";
	_Common::gotoXY(75, 25);
}
void _Menu::PVP()
{
	system("cls");
	int BOARD_SIZE = 10;
	int LEFT = 0;
	int TOP = 0;

	_Common::fixConsoleWindow();
	_Game g(BOARD_SIZE, LEFT, TOP); // You yourself define some constants
	g.startGame();
	while (g.isContinue()) {
		g.waitKeyBoard();
		if (g.getCommand() == 27) g.exitGame();
		else {
			switch (g.getCommand()) {
			case 'A':
				g.moveLeft();
				break;
			case 'W':
				g.moveUp();
				break;
			case 'S':
				g.moveDown();
				break;
			case 'D':
				g.moveRight();
				break;
			case 13:
				//Mark the board, then check and process win/lose/draw/continue
				if (g.processCheckBoard()) {
					switch (g.processFinish()) {
					case -1: case 1: case 0:
						if (g.askContinue() != 'Y') g.exitGame();
						else g.startGame();
					}
				}
			}
		}
	}
}
void _Menu::about()
{
	system("cls");
	cout << "19127501 Tran Phan Minh Nhut" << endl;
	cout << "19127378 Nguyen Viet Thanh Duy" << endl;
	cout << "19127303 Hinh Ich Trinh" << endl;
	cout << "19127 Tran Thanh Son" << endl;
}
void _Menu::chooseOptions()
{
	while (1)
	{
		switch (waitKeyBoard())
		{
		case 'W':
			y -= 2;
			if (y < 25) y = 25;
			_Common::gotoXY(x, y);
			break;
		case 'S':
			y += 2;
			if (y > 33) y = 33;
			_Common::gotoXY(x, y);
			break;
		case 13:
			switch (y)
			{
			case 25:
				PVP();
				break;
			case 27:
				//PVC();
				break;
			case 29:
				//loadGame();
				break;
			case 31:
				//rule();
				break;
			case 33:
				about();
				break;
			}

		}
	}
}
