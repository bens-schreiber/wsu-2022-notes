#include "./game_struct.h"

void battleShipGameStart()
{
    BattleShipGame *game = malloc(sizeof(BattleShipGame));
    *game = (BattleShipGame) {
        .round = 0,
        .player = &(BattleShipPlayer) {.score = 0, .shipMap = {{}}},
        .computer = &(BattleShipPlayer) {.score = 0, .shipMap = {{}}},
        .gameBoard = &(GameBoard) {}
    };
    gameBoardInitialize(game->gameBoard);

    // // define array of battleships on heap (ships mem will be freed at the end of the game)
    // // mem copy in the ship array defined in utils.h
    BattleShip *ships = malloc(sizeof(BattleShip) * SHIPS_PER_PLAYER);
    memcpy(ships, (BattleShip[])SHIPS, sizeof(BattleShip) * SHIPS_PER_PLAYER);

    // Ask the player to place their ships
    battleShipPlayerPlaceShips(game->player, ships);

    // // Generate computer ships
    // battleShipPlayerGenerateShips(game->computer);

    // while (1)
    // {
    //     _battleShipGameDoPlayerRound(game);
    //     if (game->player->score == WINNING_SCORE)
    //     {
    //         printPlayerWins();
    //         break;
    //     }

    //     _battleShipGameDoComputerRound(game);

    //     if (game->computer->score == WINNING_SCORE)
    //     {
    //         printComputerWins();
    //         break;
    //     }
    // }

    free(game);
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
        while ((input = getIntInput("") != 'Y'))
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

    BattleShip *ship = p->shipMap[coordinate.Y][coordinate.X];
    if (ship)
    {
        ship->hitPoints--;
        p->score++;
        if (ship->hitPoints == 0)
        {
            free(ship);
            return SANK;
        }
        return HIT;
    }
    return MISS;
}

void printBattleshipPlacement(BattleShipGame *game, BattleShip *ship[SHIPS_PER_PLAYER])
{
    printGameBoard(game->gameBoard);
    while (ship++ < &ship[SHIPS_PER_PLAYER])
    {
        printf("%s: ", (**ship).name);
        for (int i = 0; i < (**ship).hitPoints; i++)
        {
            printf("%c", (**ship).graphic);
        }
        printf("\n");
    }
}

void printInvalidArgument()
{
    printf("Invalid argument.");
}

void printShipMissed(BattleShipGame *game)
{
    printf("MISS!\n");
}

void printShipHit(BattleShipGame *game)
{
    printf("HIT!\n");
}

void printShipSank(BattleShipGame *game)
{
    printf("SHIP SANK!");
}