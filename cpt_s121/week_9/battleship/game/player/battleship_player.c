#include "battleship_player_struct.h"

void _battleShipPlayerPlaceShips(BattleShipGame *game)
{
    // Create a game board to display the ship placement in
    GameBoard gameBoard = {0};
    gameBoardInitialize(&gameBoard);

    // define array of battleships on heap (ships mem will be freed at the end of the game)
    // mem copy in the ship array defined in utils.h
    BattleShip *ships = malloc(sizeof(BattleShip) * SHIPS_PER_PLAYER);
    memcpy(ships, (BattleShip[])SHIPS, sizeof(BattleShip) * SHIPS_PER_PLAYER);

    GameBoard copyBoard;
    // for SHIPS_PER_PLAYER
    for (int i = 0; i < SHIPS_PER_PLAYER; i++)
    {
        // Use a copy of the game board for each animation
        copyBoard = gameBoard;

        // Display instructions and print the board
        printShipPlacementInstructions(&ships[i]);
        printGameBoard(&gameBoard);

        // W A S D, Y to confirm, F for flip
        char input;
        unsigned char shiftX = 0, shiftY = 0;
        Axis axis = VERTICAL;
        while ((input = getIntOrCharInput("")))
        {
            // User is attempting to place ship.
            // The ship at this point could be colliding with another
            // Check for collision before putting the ship into the shipMap
            if (input == 'Y')
            {
                // incase of a collision, we can't directly use shiftX or shiftY
                // copy into shipX and shipY for traversal of the array
                unsigned char shipX = shiftX, shipY = shiftY;

                // check for collisions
                for (int i = ships[i].hitPoints; i >= 0; i--)
                {
                    // Check if the shipMap has a value where any values of a ship are
                    if (game->player->shipMap[axis == VERTICAL ? shipY-- : shipY][axis == HORITZONTAL ? shipX-- : shipX])
                        goto ignoreKey;
                }

                // put ships in shipmap
                for (int i = ships[i].hitPoints; i >= 0; i--)
                {
                    game->player->shipMap[axis == VERTICAL ? shiftY-- : shiftY][axis == HORITZONTAL ? shiftX-- : shiftX] = &ships[i];
                }

                // Ship placed
                // Put the copyboard into the game board to save ship placement
                gameBoard = copyBoard;
                break;
            }

            // Handle WASD F input
            // Ignore the key if out of bounds
            switch (input)
            {
            case 'W':
                if (shiftY + 1 > BOARD_ROWS)
                    goto ignoreKey;
                shiftY++;
                break;
            case 'S':
                if (shiftY - 1 < BOARD_ROWS)
                    goto ignoreKey;
                shiftX--;
                break;
            case 'D':
                if (shiftX + 1 > BOARD_COLUMNS)
                    goto ignoreKey;
                shiftY++;
                break;
            case 'A':
                if (shiftX - 1 < BOARD_COLUMNS)
                    goto ignoreKey;
                shiftY--;
                break;
            case 'F':
                axis = !axis;
            }

            // Place the new ship position onto the copyBoard
            gameBoardPlaceValues(
                &copyBoard,
                ships[i].graphic,
                ships[i].hitPoints,
                (Coordinate){shiftX, shiftY},
                axis);

            // Print the copy board
            printGameBoard(&copyBoard);

        // skips while from within a switch
        ignoreKey:;
        }
    }
}

void _battleShipPlayerGenerateShips(BattleShipGame *game) {
    
}