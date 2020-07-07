#include "_Menu.h"
using namespace std;
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
	system("cls");
	system("color F0");
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hStdout, 50);
	_Common::setFontSize(20);
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
	/*while (_kbhit() && waitKeyBoard() != 'S')
	{
		_Common::highlight(15, 0, 75, 25, "PVP");
		Sleep(500);
		_Common::setTextColor(15, 15);
		Sleep(500);
	}*/
	_Common::gotoXY(75,27);
	cout << "PVC";
	_Common::gotoXY(75, 29);
	cout << "Load Game";
	_Common::gotoXY(75, 31);
	cout << "Rule";
	_Common::gotoXY(75, 33);
	cout << "About";
	_Common::gotoXY(75, 25);
	chooseOptions();
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
			switch (g.getCommand())
			{
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
			case 'L':
				// hien len console yeu cau nhap file name
				/*string fileName;
				g.saveGame(fileName);*/
				break;
			case 27:
				printMenu();
			case 13:
				//Mark the board, then check and process win/lose/draw/continue
				if (g.processCheckBoard()) {
					switch (g.processFinish()) {
					case -1: case 1: case 0:
						if (g.askContinue()) g.exitGame();
						else g.startGame();
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
	cout << "19127542 Tran Thanh Son" << endl;
	while (1)
	{
		if (waitKeyBoard() == 27) printMenu();
	}
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
				printLoadGame();
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
void _Menu::printLoadGame()
{
	system("cls");
	_Common::printTextAt("List of saved files: ", 70, 3);
	int cury=5;
	for (auto i : listFileName)
	{
		_Common::printTextAt(i, 75, cury);
		cury+=2;
	}
	cury = 5;
	_Common::gotoXY(75, cury);
	while (1)
	{
		switch (waitKeyBoard())
		{
		case 'W':
			cury -= 2;
			if (cury < 5) cury = 5;
			_Common::gotoXY(75, cury);
			break;
		case 'S':
			cury += 2;
			if (cury > listFileName.size() * 2 + 3) cury = listFileName.size() * 2 + 3;
			_Common::gotoXY(75, cury);
			break;
		case 27:
			printMenu();
		case 13:
			auto it = listFileName.begin();
			for (int i = 0; i < (cury - 5) / 2; i++) it++;
			loadGame(*it);
			break;
		}
	}
}
void _Menu::loadGame(string filename)
{
	ifstream f;
	f.open(filename);
	// nho viet phan than
	f.close();
}
