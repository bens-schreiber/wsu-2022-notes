#include "./game_struct.h"

void battleShipGameStart()
{
    BattleShipGame *game = malloc(sizeof(BattleShipGame));
    *game = (BattleShipGame){
        .round = 0,
        .player = &(BattleShipPlayer){.score = 0, .shipMap = {{}}, .ships = SHIPS, .gameBoard = &(GameBoard){}},
        .computer = &(BattleShipPlayer){.score = 0, .shipMap = {{}}, .ships = SHIPS, .gameBoard = &(GameBoard){}}};

    // Place player ships
    battleShipPlayerPlaceShips(game->player);

    // Generate computer ships
    battleShipPlayerGenerateShips(game->computer);

    // Computer game board will stay blank until attacks are launched,
    gameBoardInitialize(game->computer->gameBoard);

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
        game->round++;
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
    printGameBoard(game->computer->gameBoard, "Select a tile to attack! (X: HIT) (M: MISS) (O: CURSOR)");
    while ((input = getCharInput("")))
    {
        if (input == 'Y' || input == 'y')
        {
            break;
        }

        *copyBoard = *game->computer->gameBoard;

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
        gameBoardPlaceValue(game->computer->gameBoard, 'M', (Coordinate){x, y});
        break;
    case HIT:
        gameBoardPlaceValue(game->computer->gameBoard, 'X', (Coordinate){x, y});
        break;
    case SANK:
        gameBoardPlaceValue(game->computer->gameBoard, 'X', (Coordinate){x, y});
        printGameBoard(game->computer->gameBoard, "Attack Launched (X: HIT) (M: MISS) (O: CURSOR)");
        printShipSank(game, (Coordinate){x, y});
        return;
    }

    printGameBoard(game->computer->gameBoard, "Attack Launched (X: HIT) (M: MISS) (O: CURSOR)");
}

// TODO: this can be sophisticated
void _battleShipGameDoComputerRound(BattleShipGame *game)
{
    Coordinate coordinate = (Coordinate){
        rand() % BOARD_COLUMNS,
        rand() % BOARD_ROWS};

    switch (battleShipGameAttack(game, coordinate))
    {
    case MISS:
        gameBoardPlaceValue(game->player->gameBoard, 'M', coordinate);
        break;
    case HIT:
        gameBoardPlaceValue(game->player->gameBoard, 'X', coordinate);
        break;
    case SANK:
        gameBoardPlaceValue(game->player->gameBoard, 'X', coordinate);
        printGameBoard(game->player->gameBoard, "Computer Attack");
        printShipSank(game, coordinate);
        return;
    }

    printGameBoard(game->player->gameBoard, "Computer Attack");
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

void printShipSank(BattleShipGame *game, Coordinate coordinate)
{
    const char *ship = game->player->shipMap[coordinate.Y][coordinate.X]->name;
    printf("\n\n");
    printf("HOLY MOLY! YOU SUNK A %s!\n", ship);
}