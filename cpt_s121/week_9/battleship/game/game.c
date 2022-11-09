#include "./game.h"

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

    logStats(game);
    free(game);
}

// Does a single round of the game for the player
void _battleShipGameDoPlayerRound(BattleShipGame *game)
{
    char input;
    unsigned char x = 0, y = 0;

    // Game board to print the movement of the attack. We don't want to write over our actual game board.
    GameBoard *copyBoard = malloc(sizeof(GameBoard));
    *copyBoard = *game->computer->gameBoard;
    gameBoardPlaceValue(copyBoard, 'O', (Coordinate){x, y});
    printGameBoard(copyBoard, ATTACK_INSTRUCTIONS);

    // Move attack using WASD. Y to confirm attack placement. Check if going out of bounds with each input.
    while ((input = getCharInput("")))
    {
        if (input == 'Y' || input == 'y')
        {
            break;
        }

        // Reset the copy board to the value the game board is at. This is so we don't keep previous cursor position,
        // and instead make it look like it moved.
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

        // Place the cursor at the new value
        gameBoardPlaceValue(copyBoard, 'O', (Coordinate){x, y});

        // Print the copy of the game board with the new cursor position
        printGameBoard(copyBoard, ATTACK_INSTRUCTIONS);
    }

    // Attack the computer with the given coordinates
    unsigned char sank = _processAttackResult(
        _battleShipGameAttack(
                game->computer, 
                game->player, 
                (Coordinate){x, y}), 
            game->computer, 
            (Coordinate){x, y}
    );

    // Print the board with the attack
    printGameBoard(game->computer->gameBoard, ATTACK_LAUNCHED);
    if (sank)
    {
        printShipSank(game->computer, (Coordinate){x, y});
    }
}

// TODO: this can be sophisticated
void _battleShipGameDoComputerRound(BattleShipGame *game)
{
    Coordinate coordinate = (Coordinate){
        rand() % BOARD_COLUMNS,
        rand() % BOARD_ROWS};

    unsigned char sank = _processAttackResult(_battleShipGameAttack(game->player, game->computer, coordinate), game->player, coordinate);

    printGameBoard(game->player->gameBoard, "Computer Attack");
    if (sank)
    {
        printShipSank(game->player, coordinate);
    }
}

AttackResult _battleShipGameAttack(BattleShipPlayer *attack, BattleShipPlayer *player, Coordinate coordinate)
{

    BattleShip *ship = attack->shipMap[coordinate.Y][coordinate.X];

    if (ship)
    {

        // Already been hit here, just return hit again
        if (attack->gameBoard->board[coordinate.Y][coordinate.X] == 'X')
        {
            return HIT;
        }

        // Lower the ships health, increase player score
        ship->hitPoints--;
        player->score++;

        // 0 hitpoints means the ship has been sank
        if (ship->hitPoints == 0)
        {
            return SANK;
        }

        return HIT;
    }
    return MISS;
}

unsigned char _processAttackResult(AttackResult attackResult, BattleShipPlayer *player, Coordinate coordinate)
{
    logAttack(coordinate, attackResult);
    switch (attackResult)
    {
    case MISS:
        gameBoardPlaceValue(player->gameBoard, MISS_MARKER, coordinate);
        return 0;
    case HIT:
        gameBoardPlaceValue(player->gameBoard, HIT_MARKER, coordinate);
        return 0;
    case SANK:
        gameBoardPlaceValue(player->gameBoard, HIT_MARKER, coordinate);
        return 1;
    }
}

void printShipSank(BattleShipPlayer *player, Coordinate coordinate)
{
    const char *ship = player->shipMap[coordinate.Y][coordinate.X]->name;
    printf("\n\n");
    printf("HOLY MOLY! A FRIGGN %s WAS SUNK!\n", ship);
}