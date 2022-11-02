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
        if (game->player->score == WINNING_SCORE)
        {
            printPlayerWins();
            break;
        }

        _battleShipGameDoComputerRound(game);

        if (game->computer->score == WINNING_SCORE)
        {
            printComputerWins();
            break;
        }
    }
}

// Does a single round of the game for the player
void _battleShipGameDoPlayerRound(BattleShipGame *game)
{
    printGameBoard(game->gameBoard);

    // Player tile selection with WASD
    GameBoard copyBoard;
    while (1)
    {
        copyBoard = *game->gameBoard;
        char input;
        unsigned char x = 0, y = 0;
        while ((input = getIntOrCharInput("") != 'Y'))
        {
            switch (input)
            {
            case 'W':
                if (y + 1 > BOARD_ROWS)
                    goto ignoreKey;
                y++;
                break;
            case 'S':
                if (y - 1 < BOARD_ROWS)
                    goto ignoreKey;
                y--;
                break;
            case 'D':
                if (x + 1 > BOARD_COLUMNS)
                    goto ignoreKey;
                x++;
                break;
            case 'A':
                if (x - 1 < BOARD_COLUMNS)
                    goto ignoreKey;
                x--;
                break;
            }

        ignoreKey:;
        }

        switch (battleShipGameAttack(game, (Coordinate){x, y}))
        {
        case MISS:
            printShipMissed(game);
            break;
        case HIT:
            printShipHit(game);
            break;
        case SANK:
            printShipSank(game);
            break;
        }
    }
}

// TODO: this can be sophisticated
void _battleShipGameDoComputerRound(BattleShipGame *game)
{
    switch (battleShipGameAttack(
        game, (Coordinate){
                  rand() % BOARD_COLUMNS,
                  rand() % BOARD_ROWS}))
    {
    case MISS:
        printShipMissed(game);
        break;
    case HIT:
        printShipHit(game);
        break;
    case SANK:
        printShipSank(game);
        break;
    };
}

AttackResult battleShipGameAttack(BattleShipGame *game, Coordinate coordinate)
{
    BattleShipPlayer *p = game->round % 2 ? game->player : game->computer;
    if (p != game->computer)
    {
        gameBoardPlaceValue(game->gameBoard, 'X', coordinate);
    }
    if (p->shipMap[coordinate.Y][coordinate.X])
    {
        p->shipMap[coordinate.Y][coordinate.X]->hitPoints--;
        p->score++;
        if (p->shipMap[coordinate.Y][coordinate.X]->hitPoints == 0)
        {
            return SANK;
        }
        return HIT;
    }
    return MISS;
}