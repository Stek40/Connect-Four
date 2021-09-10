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
    int turns = 1; // сложи го в .h и да се взима от там директно 
    
    std::cout << "\n\t\tPlayer 1: @\n\t\tPlayer 2: #\n\n";
    std::cout << "\t\tturns: " << turns++;
    std::cout << "\n\n\n\n";
    
    std::cout << "\t\t";
    for (int j = 0; j < 2*width + 1; ++j)
        std::cout << "_";
    std::cout << "\n";
    for (int i = 0; i < height; ++i)
    {
        std::cout << "\t\t|";
        for (int j = 0; j < width; ++j)
        {
            std::cout << board[i][j] << "|";
        }
        std::cout << "\n";
    }
    std::cout << "\t\t";
    for (int j = 0; j < 2*width + 1; ++j)
        std::cout << "¯";
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
