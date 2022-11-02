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

int getIntInput(const char *inputMessage)
{
    int input = 0;
    printf("%s", inputMessage);
    scanf("%d", &input);
    return input;
}

void printGameBoard(GameBoard *gameBoard)
{
    char *board = &gameBoard->board[BOARD_ROWS - 1][BOARD_COLUMNS - 1];
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

void printComputerWins() {
    printf("The computer won the game");
}

void printPlayerWins() {
    printf("You won the game!");
}