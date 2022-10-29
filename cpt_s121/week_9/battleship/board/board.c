#include "board_struct.h"

// Initialize all values to tilde
// Quadratic time complexity given BOARD_ROWS and BOARD_COLUMNS are equal
void gameBoardInitialize(GameBoard *gameBoard)
{
    for (int i = 0; i < BOARD_ROWS * BOARD_COLUMNS; i++)
    {
        *((char *)(gameBoard->board) + i) = '~';
    }
}

int gameBoardPlaceValue(GameBoard *gameBoard, char value, const Coordinate coordinate)
{
    // Bad coordinate
    if (!coordinate.X || coordinate.X > BOARD_COLUMNS || !coordinate.Y || coordinate.Y > BOARD_ROWS)
    {
        return 0;
    }

    gameBoard->board[coordinate.Y][coordinate.X] = value;
    return 1;
}

int gameBoardPlaceValues(GameBoard *gameBoard, char *values, const int valueAmount, Coordinate coordinate, const Direction direction)
{
    // Bad coordinate
    if (!coordinate.X || coordinate.X > BOARD_COLUMNS || !coordinate.Y || coordinate.Y > BOARD_ROWS)
    {
        return 0;
    }

    for (int i = 0; i < valueAmount; i++)
    {
        // Bad coordinate
        switch (direction)
        {
        case UP:
            if ((coordinate.Y + valueAmount - 1) > BOARD_ROWS)
                return 0;
            
            
        case DOWN:
            if ((coordinate.Y + valueAmount - 1) < BOARD_ROWS)
                return 0;
        case RIGHT:
            if ((coordinate.X + valueAmount - 1) > BOARD_COLUMNS)
                return 0;
        case LEFT:
            if ((coordinate.X + valueAmount - 1) < BOARD_COLUMNS)
                return 0;
        }
    }
}