#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game
{



public:
	Game(int, int);
	void play();

private:
	Board board;
};

#endif