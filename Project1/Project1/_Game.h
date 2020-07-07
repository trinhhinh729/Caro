#pragma once
#include "_Board.h"
#include <Windows.h>
#include<conio.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


class _Game: public _Board
{
	_Board* _b;// a board game
	bool _turn;// turn: true for the 1st player and false for the 2nd player
	int _x, _y; // current position of cursor
	int _command; // input-key from the players
	bool _loop; // decision bool variable to exit game or not
public:
	_Game(int, int, int);
	~_Game();
	int getCommand();
	bool isContinue();
	char waitKeyBoard(); // Receiving keyboard from players
	char askContinue();
	void startGame(); // Function to start the game
	void exitGame(); // Function to exit the game
	int processFinish();
	bool processCheckBoard();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void saveGame(string);
};
