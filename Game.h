#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game
{
public:
	Game();
	Game(int, int);

	void play();
	bool is_running();
	void draw();

private:
	Board board;
};

#endif