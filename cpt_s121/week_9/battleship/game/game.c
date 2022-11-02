#include "./game_struct.h"

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
    battleShipPlayerPlaceShips(game);

    // Generate computer ships
    battleShipPlayerGenerateShips(game);

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