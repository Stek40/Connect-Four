#include "Board.h"
#include <iostream>


Board::Board(int height, int width) : height(height), width(width)
{
    //board
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            board[i][j] = ' ';
        }
    }

    //array for empty_column_boxes

    for (int i = 0; i < height; i++)
    {
        empty_column_boxes[i] = height;
    }
}

void Board::print() const
{
    std::cout << "\n\t\tPlayer 1: @\n\t\tPlayer 2: #\n\n";
    // std::cout << "\t\tturns: " << turns++;
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
        std::cout << "-";
}


bool Board::update(int column)
{
    if (empty_column_boxes[column] == 0)//full column
    {
        return false;

    } else
    {
        turn = (turn + 1) % 2; //changes @/#
        empty_column_boxes[column]--;
        lastColumn = column;
        lastRow = empty_column_boxes[column];
        board[lastRow][lastColumn] = (!turn ? '@' : '#');
        return true;
    }
}

bool Board::win() const
{
    int count = 0;

    const char check[2] = { '@', '#' };

    // horizontal
    for (int i = lastColumn - 3; i <= lastColumn + 3; ++i)
    {
        if (i >= 0 && i < width)
        {
            if (board[lastRow][i] == check[turn])
                ++count;
            else
                count = 0;
        }
        if (count == 4)
        {
            std::cout << "\n\t\tPlayer " << turn + 1 << " wins.\n\n";
            return true;
        }
    }

    // vertical
    for (int i = lastRow; i <= lastRow + 3; ++i)
    {
        if (i >= 0 && i < height)
        {
            if (board[i][lastColumn] == check[turn])
                ++count;
            else
                count = 0;
        }
        if (count == 4)
        {
            std::cout << "\n\t\tPlayer " << turn + 1 << " wins.\n\n";
            return true;
        }
    }

    // 1st diagonal
    int j = 3;
    for (int i = lastColumn + 3; i >= lastColumn - 3; --i)
    {
        if (i >= 0 && i < width && lastRow + j >= 0 && lastRow + j < height)
        {
            if (board[lastRow + j][i] == check[turn])
            {
                ++count;
            }
            else
                count = 0;

            --j;
        }
        if (count == 4)
        {
            std::cout << "\n\t\tPlayer " << turn + 1 << " wins.\n\n";
            return true;
        }
    }

    // 2nd diagonal
    j = 3;
    for (int i = lastColumn - 3; i <= lastColumn + 3; ++i)
    {
        if (i >= 0 && i < width && lastRow + j >= 0 && lastRow + j < height)
        {
            if (board[lastRow + j][i] == check[turn])
            {
                ++count;
            }
            else
                count = 0;

            --j;
        }
        if (count == 4)
        {
            std::cout << "\n\t\tPlayer " << turn + 1 << " wins.\n\n";
            return true;
        }
    }


    return false;
}
