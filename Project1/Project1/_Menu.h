#pragma once
#ifndef _MENU_H
#define _MENU_H

#include "_Common.h"
#include <Windows.h>
#include <conio.h>
#include "_Point.h"
#include "_Board.h"
#include "_Game.h"
class _Menu
{
	int x;
	int y;
	int _command;
public:
	void printMenu();
	void chooseOptions();
	void PVP();
	void PVC();
	void loadGame();
	void rule();
	void about();
	char waitKeyBoard();
	_Menu();
};

#endif