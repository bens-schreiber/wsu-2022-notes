#include "board_struct.h"

// Initialize all values to tilde
void gameBoardInitialize(GameBoard *gameBoard)
{
    for (int i = 0; i < BOARD_ROWS * BOARD_COLUMNS; i++)
    {
        *((char *)(gameBoard->board) + i) = '~';
    }
}

int gameBoardPlaceValue(GameBoard *gameBoard, char value, const Coordinate coordinate)
{
    gameBoard->board[coordinate.Y][coordinate.X] = value;
    return 1;
}

int gameBoardPlaceValues(GameBoard *gameBoard, char value, const int valueAmount, const Coordinate coordinate, const Axis axis)
{

    unsigned char x = coordinate.X, y = coordinate.Y;
    for (int i = 0; i < valueAmount; i++)
    {
        if (axis == HORITZONTAL)
        {
            x++;
        }
        else
        {
            y++;
        }

        gameBoardPlaceValue(
            gameBoard,
            value,
            (Coordinate){x, y});
    }

    return 1;
}