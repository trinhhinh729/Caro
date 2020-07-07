#pragma once
#ifndef _MENU_H
#define _MENU_H
#include "_Game.h"
#include <set>
class _Menu
{
	int x;
	int y;
	int _command;
	set<string> listFileName;
public:
	void printMenu();
	void chooseOptions();
	void PVP();
	void PVC();
	void printLoadGame();
	void rule();
	void about();
	char waitKeyBoard();
	void loadGame(string);
	_Menu();
};

#endif