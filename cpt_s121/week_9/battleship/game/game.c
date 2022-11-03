#include "./game_struct.h"

void battleShipGameStart()
{
    BattleShipGame *game = malloc(sizeof(BattleShipGame));
    *game = (BattleShipGame){
        .round = 0,
        .player = &(BattleShipPlayer){.score = 0, .shipMap = {{}}, .ships = SHIPS},
        .computer = &(BattleShipPlayer){.score = 0, .shipMap = {{}}, .ships = SHIPS},
        .gameBoard = &(GameBoard){}};

    // Place player ships
    battleShipPlayerPlaceShips(game->player);

    // Generate computer ships
    battleShipPlayerGenerateShips(game->computer);

    gameBoardInitialize(game->gameBoard);

    while (1)
    {
        _battleShipGameDoPlayerRound(game);
        if (game->player->score == WINNING_SCORE)
        {
            printPlayerWins();
            break;
        }

        awaitInput();

        _battleShipGameDoComputerRound(game);

        if (game->computer->score == WINNING_SCORE)
        {
            printComputerWins();
            break;
        }

        awaitInput();
    }

    free(game);
}

// Does a single round of the game for the player
void _battleShipGameDoPlayerRound(BattleShipGame *game)
{
    // Player tile selection with WASD
    char input;
    unsigned char x = 0, y = 0;
    GameBoard *copyBoard = malloc(sizeof(GameBoard));
    gameBoardPlaceValue(copyBoard, 'O', (Coordinate){x, y});
    printGameBoard(game->gameBoard, "Select a tile to attack! (X: HIT) (M: MISS) (O: CURSOR)");
    while ((input = getCharInput("")))
    {
        if (input == 'Y' || input == 'y')
        {
            break;
        }

        *copyBoard = *game->gameBoard;

        switch (input)
        {
        case 's':
        case 'S':
            if (y == BOARD_ROWS - 1)
                break;
            y++;
            break;

        case 'w':
        case 'W':
            if (y == 0)
                break;
            y--;
            break;

        case 'd':
        case 'D':
            if (x == BOARD_COLUMNS - 1)
                break;
            x++;
            break;

        case 'a':
        case 'A':
            if (x == 0)
                break;
            x--;
            break;
        }

        gameBoardPlaceValue(copyBoard, 'O', (Coordinate){x, y});
        printGameBoard(copyBoard, "Select a tile to attack! (X: HIT) (M: MISS) (O: CURSOR)");
    }

    switch (battleShipGameAttack(game, (Coordinate){x, y}))
    {
    case MISS:
        gameBoardPlaceValue(game->gameBoard, 'M', (Coordinate){x, y});
        break;
    case HIT:
        gameBoardPlaceValue(game->gameBoard, 'X', (Coordinate){x, y});
        break;
    case SANK:
        gameBoardPlaceValue(game->gameBoard, 'X', (Coordinate){x, y});
        printShipSank(game);
        break;
    }

    printGameBoard(game->gameBoard, "Attack Results! (X: HIT) (M: MISS) (O: CURSOR)");
}

// TODO: this can be sophisticated
void _battleShipGameDoComputerRound(BattleShipGame *game)
{
    battleShipGameAttack(
        game, (Coordinate){
                  rand() % BOARD_COLUMNS,
                  rand() % BOARD_ROWS});
}

AttackResult battleShipGameAttack(BattleShipGame *game, Coordinate coordinate)
{
    BattleShipPlayer *p = game->round % 2 ? game->player : game->computer;

    BattleShip *ship = p->shipMap[coordinate.Y][coordinate.X];
    if (ship)
    {
        ship->hitPoints--;
        p->score++;
        if (ship->hitPoints == 0)
        {
            return SANK;
        }
        return HIT;
    }
    return MISS;
}

void printInvalidArgument()
{
    printf("Invalid argument.");
}

void printShipSank(BattleShipGame *game)
{
    printf("SHIP SANK!");
}