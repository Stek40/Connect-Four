#include "Board.h"
#include <iostream>

Board::Board(int height, int width) : height(height), width(width)
{
     initialize_board();
     initialize_columns_capacity();
}

void Board::initialize_board()
{ 
    matrix = new char*[height];
    for (int i = 0; i < height; ++i)
    {
        matrix[i] = new char[width];

        for (int j = 0; j < width; ++j)
        {
           // std::cout << i << " " << j << std::endl;
            matrix[i][j] = ' ';
        }
    }
}

void Board::initialize_columns_capacity()
{
    empty_column_boxes = new int[width];
    for (int i = 0; i < width; i++)
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
    for (int j = 0; j < 2 * width + 1; ++j)
        std::cout << "_";

    std::cout << "\n";
    for (int i = 0; i < height; ++i)
    {
        std::cout << "\t\t|";
        for (int j = 0; j < width; ++j)
        {
            std::cout << matrix[i][j] << "|";
        }
        std::cout << "\n";
    }
    std::cout << "\t\t";

    for (int j = 0; j < 2 * width + 1; ++j)
        std::cout << "-";
}

void::Board::play_turn()
{
	int column = -1;
    
	while (update(column) != SUCCESS)
	{
		std::cout << "\tenter column: ";
		std::cin >> column;
	}
}

bool Board::update(int column)
{
    if (column < 0 || column > width - 1 || empty_column_boxes[column] == 0)
    {
        return false;
    }

    turn = (turn + 1) % 2; //changes @/#
    empty_column_boxes[column]--;
    lastColumn = column;
    lastRow = empty_column_boxes[column];
    matrix[lastRow][lastColumn] = (!turn ? '@' : '#');
    total_turns++;

    return true;
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
            if (matrix[lastRow][i] == check[turn])
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
            if (matrix[i][lastColumn] == check[turn])
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
            if (matrix[lastRow + j][i] == check[turn])
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
            if (matrix[lastRow + j][i] == check[turn])
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

int Board::get_total_turns()
{
    return total_turns;
}
