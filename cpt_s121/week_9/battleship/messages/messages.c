#include "messages.h"
#define TITLE "BATTLESHIP by Benjamin Schreiber\n\n"
void printMenu()
{
    printf(
        "\n"
        TITLE
        "###########################\n"
        "\n"
        "1.) Read rules\n"
        "2.) Start game\n"
        "3.) Exit\n"
        "\n"
        "###########################\n"
        "\n"
        );
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

char getCharInput(const char *inputMessage) {
    char input = '\0';
    printf("%s", inputMessage);
    scanf("%c", &input);
    return input;
}

void printGameBoard(GameBoard *gameBoard, const char *titleMessage)
{
    system("clear");

    printf(TITLE);
    printf("%s\n\n", titleMessage);

    char bottomChars[BOARD_COLUMNS] = {};
    char bottomCharLetter = 'A';
    for (int row = 0; row < BOARD_ROWS; row++) {
        printf("%d   ", (BOARD_ROWS - 1) - row);
        for (int col = 0; col < BOARD_COLUMNS; col++) {
            printf("%c ", gameBoard->board[row][col]);
        }
        printf("\n");
        bottomChars[row] = bottomCharLetter++;
    }
    
    printf("\n    ");
    for (int i = 0; i < BOARD_COLUMNS; i++) {
        printf("%c ", bottomChars[i]);
    }
    printf("\n");
}

void printComputerWins()
{
    printf("The computer won the game");
}

void printPlayerWins()
{
    printf("You won the game!");
}