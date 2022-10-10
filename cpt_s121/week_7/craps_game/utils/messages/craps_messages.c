#include "craps_messages.h"

void titleMessage(CrapsGame *game)
{
    printf(
        "# Craps by Benjamin Schreiber\n"
        "# ROUND: %d\n"
        "# POINT: %d\n"
        "# HOUSE BALANCE: $%d\n"
        "# YOUR BALANCE: $%d\n"
        "# YOUR WAGER: $%d\n",
        game->round, game->crapsPoint, game->houseBalance, game->playerBalance, game->wager);
}

void _loadPrintf(char *loadingText, CrapsGame *game)
{

    int loadCount = 4;

    // I put a buffer char here since random letters would sometimes appear without it
    char ellipsis[4] = {'\0', '\0', '\0', '\0'};
    while (loadCount--)
    {
        printf("%s %s\n", loadingText, ellipsis);
        sleep(1);
        system("clear");
        titleMessage(game);

        // who needs string library functions when you're awesome
        ellipsis[abs(loadCount - 3)] = '.';
    }
}

void gameRulesMessage()
{
    printf(
        "\n"
        "\n"
        "Welcome to Craps by Benjamin Schreiber, for CS121. "
        "Begin the game by placing a wager. You will be able to add to the wager each round. "
        "On round one, if you land a 7 or an 11, you instantly win. "
        "If you land a 2, 3, or 12, you lose. "
        "Any other number you roll will become the point. For subsequent rounds, your goal is to roll the point. "
        "If you roll a 7 in these rounds, you lose. If you roll the point, you win. "
        "If at any point your balance reaches or is under 0, the program will exit.");
}

void houseBalanceMessage(int balance)
{
    printf(
        "The house balance is %d", balance);
}

void confirmMessage()
{
    printf("\n\nPress ENTER to continue!");
    char input = 0;
    fflush(stdin);
    getchar();
    system("clear");
}

void confirmMessageTitle(CrapsGame *game)
{
    confirmMessage();
    titleMessage(game);
}

void placeWagerMessage(int *wager)
{
    printf("\nPlace a wager: ");
    scanf("%d", wager);
}

void wagerPlacedMessage(int wager)
{
    printf("\nThe current wager is %d", wager);
}

void rollDiceMessage(CrapsGame *game)
{
    system("clear");
    titleMessage(game);
    _loadPrintf("\nRolling the dice!", game);
}

void showDiceMessage(int diceSum)
{
    printf("\nYou rolled a: %d", diceSum);
}

void youLoseGameMessage()
{
    printf("\nyou lost craps, dude... :(");
}

void pointMessage(int point)
{
    printf("\nThe point is: %d\nWager added back to your balance.", point);
}

void youWinGameMessage()
{
    printf("\nHoly friggin craps you won!");
}

void exitMessage()
{
    printf("\ngame ova");
}

void resetWagerMessage()
{
    printf("\nNo magic dice. Aw nuts. You lost the wager.");
}

void anotherGameMessage()
{
    system("clear");
    printf("Another game of craps!\n\n");
}

void youLoseBecauseBrokeMessage()
{
    printf("\nyou have no money. leave this establishment immediatly.");
}