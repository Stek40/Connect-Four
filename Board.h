#ifndef BOARD_H
#define BOARD_H

int const DEFAULT_HEIGHT = 6;
int const DEFAULT_WIDTH = 7;

class Board
{
public:
	int const SUCCESS = 1;

    Board(int height = DEFAULT_HEIGHT, int width = DEFAULT_WIDTH);

    void initialize_board();
    void initialize_columns_capacity();
    void print() const;
    bool win() const;
    void play_turn();
    int get_total_turns();

private:
    char **matrix;
    int height,
        width,
        turn = 0,
        total_turns = 0,
        lastRow = -1,
        lastColumn = -1,
        *empty_column_boxes;

        
    bool update(int column);
};

#endif
