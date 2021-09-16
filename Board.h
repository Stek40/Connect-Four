#ifndef BOARD_H
#define BOARD_H

const int MAX_HEIGHT = 20;
const int MAX_WIDTH = 40;

class Board
{
public:
    Board(int height, int width);
    void print() const;
    bool update(int, &int);
    bool win() const;

private:
    char board[MAX_HEIGHT][MAX_WIDTH];
    unsigned height, width, turn = 0,
        lastRow = -1, lastColumn = -1,
        empty_column_boxes[MAX_WIDTH];
};

#endif
