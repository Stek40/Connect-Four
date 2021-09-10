#include "Board.h"
#include <iostream>

Board::Board(int height, int width) : height(height), width(width)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; i < width; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

void Board::print() const
{
    for (int i = 0; i < heigth; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << "|" << board[i][j] << "|";
        }
        std::cout << "\n";
    }
}

void Board::update(int x, int y)
{
    board[x][y] = (!turn ? 'A' : 'B');
    lastX = x;
    lastY = y;
    turn = (turn + 1) % 2;
}

bool Board::win() const
{
    int count = 0;

    // horizontal check

    // diagonal check 1

    // diagonal check 2

    // vertical check
}
