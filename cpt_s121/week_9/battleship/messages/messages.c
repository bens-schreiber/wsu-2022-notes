#include "messages.h"
#define TITLE "Battleship by Benjamin Schreiber\n\n"
void printMenu()
{
    printf(
        TITLE
        "1.) Read rules\n"
        "2.) Start game\n"
        "3.) Exit\n");
}

void printRules()
{
    printf("you really don't know how to play battleship? lol, ok.\n");
}

void printExit()
{
    printf("Exiting...\n");
}

void awaitInput()
{
    printf("\nPress ENTER to continue!\n");
    char input = 0;
    fflush(stdin);
    getchar();
    system("clear");
}

unsigned char getIntOrCharInput(const char *inputMessage)
{
    unsigned char input;
    scanf(inputMessage, &input);
    return input;
}

void printGameBoard(GameBoard *gameBoard)
{
    char *board = gameBoard->board[BOARD_ROWS - 1][BOARD_COLUMNS - 1];
    unsigned char i = 0;
    do
    {
        if (i++ == BOARD_COLUMNS)
        {
            i = 0;
            printf("\n");
        }
        printf("%c", (*board));
    } while (board--);
}

void printBattleshipPlacement(BattleShipGame *game, BattleShip *ship[SHIPS_PER_PLAYER]) {
    printGameBoard(game->gameBoard);
    while (ship++ < &ship[SHIPS_PER_PLAYER]) {
        printf("%s: ", (**ship).name);
        for (int i = 0; i < (**ship).hitPoints; i++) {
            printf("%c", (**ship).graphic);
        }
        printf("\n");
    }
}

void printInvalidArgument() {
    printf("Invalid argument.");
}

void printShipMissed(BattleShipGame *game) {
    printf("MISS!\n");
}

void printShipHit(BattleShipGame *game) {
    printf("HIT!\n");
}

void printShipSank(BattleShipGame *game) {
    printf("SHIP SANK!");
}

void printComputerWins() {
    printf("The computer won the game");
}

void printPlayerWins() {
    printf("You won the game!");
}