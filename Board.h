#ifndef BOARD_H
#define BOARD_H

const int MAX_HEIGHT = 20;
const int MAX_WIDTH = 40;

class Board
{
public:
    Board(int height, int width);
    void print() const;
    void update(int x, int y);
    bool win() const;
private:
    char board[MAX_HEIGHT][MAX_WIDTH];
    int height, width, turn = 0, lastX = -1, lastY = -1;
};

#endif
