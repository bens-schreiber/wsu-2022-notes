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

int gameBoardPlaceValues(GameBoard *gameBoard, char *values, const int valueAmount, const Coordinate coordinate, const Direction direction)
{
    // Bad coordinate
    if (!coordinate.X || coordinate.X > BOARD_COLUMNS || !coordinate.Y || coordinate.Y > BOARD_ROWS)
    {
        return 0;
    }

    // Bad coordinate
    switch (direction)
    {
    case UP:
        if ((coordinate.Y + valueAmount - 1) > BOARD_ROWS)
            return 0;
        break;

    case DOWN:
        if ((coordinate.Y + valueAmount - 1) < BOARD_ROWS)
            return 0;
        break;

    case RIGHT:
        if ((coordinate.X + valueAmount - 1) > BOARD_COLUMNS)
            return 0;
        break;

    case LEFT:
        if ((coordinate.X + valueAmount - 1) < BOARD_COLUMNS)
            return 0;
        break;
    }

    for (int i = 0; i < valueAmount; i++)
    {
        gameBoardPlaceValue(
            gameBoard,
            values[i],
            _directionalCoordinateIncrement(coordinate, direction, i));
    }

    return 1;
}

Coordinate _directionalCoordinateIncrement(Coordinate coordinate, Direction direction, int i)
{
    switch (direction)
    {
    case UP:
        return (const Coordinate){coordinate.X, coordinate.Y + i};

    case DOWN:
        return (const Coordinate){coordinate.X, coordinate.Y - i};

    case RIGHT:
        return (const Coordinate){coordinate.X + i, coordinate.Y};

    case LEFT:
        return (const Coordinate){coordinate.X - i, coordinate.Y};
    }
}