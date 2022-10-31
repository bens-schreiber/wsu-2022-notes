#include "./game_struct.h"

// Hashes a coordinate into the domain of BOARD_ROWS * BOARD_COLUMN unint8's
unsigned char _battleShipPlayerHashCoordinate(const Coordinate *coordinate)
{
    return ((coordinate->X * HASH_SALT) + coordinate->Y) % (BOARD_ROWS * BOARD_COLUMNS);
}

BattleShipGame *battleShipGame()
{
    BattleShipGame *game = malloc(sizeof(BattleShipGame));
    game->round = 0;
    game->player->score = 0;
    game->computer->score = 0;
    gameBoardInitialize(game->gameBoard);
    return game;
}

void battleShipGameStart(BattleShipGame *game)
{
    // Ask the player to place their ships
    // & generate computer ship location
    _battleShipGamePlaceShips(game);

    while (1)
    {
        _battleShipGameDoPlayerRound(game);
        _battleShipGameDoComputerRound(game);
        if (game->player->score == WINNING_SCORE)
        {
            // TODO: player wins
            break;
        }

        if (game->computer->score == WINNING_SCORE)
        {
            // todo: computer wins
            break;
        }
    }
}

// Does a single round of the game for the player
void _battleShipGameDoPlayerRound(BattleShipGame *game)
{

}

// Does a single round for the computer
void _battleShipGameDoComputerRound(BattleShipGame *game)
{
}