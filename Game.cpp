#include "Game.h"
#include <iostream>

Game::Game(int height, int width):board(Board(height, width))
{
}

void Game::play()
{
	int col;

	while (board.get_turns() < 7 || !board.win())
	{
		board.print();
		std::cout << "\n\tenter column: ";
		std::cin >> col;

		while (!board.update(col))
		{
			std::cout << "\tenter column: ";
			std::cin >> col;
		}
	}

}