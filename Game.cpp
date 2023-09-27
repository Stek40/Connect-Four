#include "Game.h"
#include <iostream>

Game::Game() : board(Board())
{
}

Game::Game(int height, int width) : board(height, width)
{
}

void Game::play()
{
	while (is_running())
	{
	//do changes
	board.play_turn();

	//draw game
	draw();
	}
}

bool Game::is_running()
{
	return board.get_total_turns() < 7 || !board.win();
}

void Game::draw()
{
	board.print();
	std::cout << "\n\tenter column: ";
}
