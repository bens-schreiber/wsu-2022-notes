#include "battleship_player_struct.h"

void battleShipPlayerPlaceShips(BattleShipPlayer *player)
{
    // Create a game board to display the ship placement in
    GameBoard *placementBoard = malloc(sizeof(GameBoard));
    GameBoard *copyBoard = malloc(sizeof(GameBoard));

    gameBoardInitialize(placementBoard);
    // for SHIPS_PER_PLAYER
    for (int shipIndex = 0; shipIndex < SHIPS_PER_PLAYER; shipIndex++)
    {
        // Display instructions and print the board
        printGameBoard(placementBoard, "Use W A S D to move the ship, F to flip, Y to place!");

        // W A S D, Y to confirm, F for flip
        char input;
        unsigned char x = 0, y = 0;
        Axis axis = VERTICAL;
        while ((input = getCharInput("")))
        {

            // User is attempting to place ship.
            // The ship at this point could be colliding with another
            // Check for collision before putting the ship into the shipMap
            if (input == 'Y' || input == 'y')
            {
                // incase of a collision, we can't directly use shiftX or shiftY
                // copy into shipX and shipY for traversal of the array
                unsigned char shipX = x, shipY = y;

                // check for collisions
                for (char i = player->ships[shipIndex].hitPoints; i > 0; i--)
                {
                    // Check if the shipMap has a value where any values of a ship are
                    if (player->shipMap[axis == VERTICAL ? shipY++ : shipY][axis == HORITZONTAL ? shipX++ : shipX])
                        goto ignoreKey;
                }

                // put ships in shipmap
                for (char i = player->ships[shipIndex].hitPoints; i > 0; i--)
                {
                    player->shipMap[axis == VERTICAL ? y++ : y][axis == HORITZONTAL ? x++ : x] = &player->ships[shipIndex];
                }

                // Ship placed
                // Put the copyboard into the game board to save ship placement
                *placementBoard = *copyBoard;
                break;
            }

            *copyBoard = *placementBoard;

            // Handle WASD F input
            // Ignore the key if out of bounds
            switch (input)
            {
            case 's':
            case 'S':
                if ((axis == VERTICAL && y + player->ships[shipIndex].hitPoints == BOARD_ROWS) || y == BOARD_ROWS - 1)
                    goto ignoreKey;
                y++;
                break;

            case 'w':
            case 'W':
                if (y == 0)
                    goto ignoreKey;
                y--;
                break;

            case 'd':
            case 'D':
                if ((axis == HORITZONTAL && x + player->ships[shipIndex].hitPoints == BOARD_COLUMNS) || x == BOARD_COLUMNS - 1)
                    goto ignoreKey;
                x++;
                break;

            case 'a':
            case 'A':
                if (x == 0)
                    goto ignoreKey;
                x--;
                break;

            case 'f':
            case 'F':
                if (axis == VERTICAL && x + player->ships[shipIndex].hitPoints > BOARD_COLUMNS || axis == HORITZONTAL && y + player->ships[shipIndex].hitPoints > BOARD_ROWS)
                    goto ignoreKey;
                axis = !axis;
            }

            // Place the new ship position onto the copyBoard
            gameBoardPlaceValues(
                copyBoard,
                player->ships[shipIndex].graphic,
                player->ships[shipIndex].hitPoints,
                (Coordinate){x, y},
                axis);

            // Print the copy board
            printGameBoard(copyBoard, "Use W A S D to move the ship, F to flip, Y to place!");

        // skips while from within a switch
        ignoreKey:;
        }
    }
    *player->gameBoard = *placementBoard;
    free(copyBoard);
}

// Brute forcing this really. Some sort of spacial awareness ds would be smarter here
unsigned char _notTouchingAndNoShips(unsigned char row, unsigned char column, unsigned char valid[BOARD_ROWS][BOARD_COLUMNS])
{
    return !valid[row][column] && !valid[row + 1][column] && !valid[row - 1][column] && !valid[row][column + 1] && !valid[row][column - 1];
}

void _searchAndPlaceHorizontal(BattleShipPlayer *player, BattleShip *ship, unsigned char validCoordinates[BOARD_ROWS][BOARD_COLUMNS])
{
    // traverse for horizontal placement
    unsigned char rIter = rand() % SHIP_PLACEMENT_SALT + 1;
    unsigned char valid = 0;
    for (unsigned char row = 0; row < BOARD_ROWS; ++row)
    {
        for (unsigned char col = 0; col < BOARD_COLUMNS; ++col)
        {
            if (_notTouchingAndNoShips(row, col, validCoordinates))
            {
                ++valid;
            }
            else
            {
                valid = 0;
            }

            if (valid == ship->hitPoints)
            {
                --rIter;
            }
            if (!rIter)
            {
                // put ships in shipmap; mark invalid coords
                for (int i = ship->hitPoints; i > 0; --i)
                {
                    player->shipMap[row][col] = ship;
                    validCoordinates[row][col] = 1;
                    col--;
                }
                return;
            }
        }
        valid = 0;
    }
}

void _searchAndPlaceVertical(BattleShipPlayer *player, BattleShip *ship, unsigned char validCoordinates[BOARD_ROWS][BOARD_COLUMNS])
{
    // traverse for horizontal placement
    unsigned char rIter = rand() % SHIP_PLACEMENT_SALT + 1;
    unsigned char valid = 0;
    for (unsigned char col = 0; col < BOARD_COLUMNS; ++col)
    {
        for (unsigned char row = 0; row < BOARD_ROWS; ++row)
        {
            if (_notTouchingAndNoShips(row, col, validCoordinates))
            {
                ++valid;
            }
            else
            {
                valid = 0;
            }

            if (valid == ship->hitPoints)
            {
                --rIter;
            }
            if (!rIter)
            {
                // put ships in shipmap; mark invalid coords
                for (int i = ship->hitPoints; i > 0; --i)
                {
                    player->shipMap[row][col] = ship;
                    validCoordinates[row][col] = 1;
                    row--;
                }
                return;
            }
        }
        valid = 0;
    }
}

void battleShipPlayerGenerateShips(BattleShipPlayer *player)
{

    // Any coordinate that is 0 is valid to place on
    unsigned char validCoordinates[BOARD_ROWS][BOARD_COLUMNS] = {0};

    srand(time(NULL));
    for (int i = 0; i < SHIPS_PER_PLAYER; ++i)
    {
        rand() % 2 ? _searchAndPlaceHorizontal(player, &player->ships[i], validCoordinates) : _searchAndPlaceVertical(player, &player->ships[i], validCoordinates);
    }

    if (!HIDE_ENEMY_SHIPS)
    {
        printf("\nGenerated enemy ships! (@ represents any ship type ships)\n");
        for (int i = 0; i < BOARD_ROWS; ++i)
        {
            for (int j = 0; j < BOARD_COLUMNS; ++j)
            {
                char c = validCoordinates[i][j] ? '@' : '~';
                printf("%c ", c);
            }
            printf("\n");
        }
    }

    awaitInput();
}