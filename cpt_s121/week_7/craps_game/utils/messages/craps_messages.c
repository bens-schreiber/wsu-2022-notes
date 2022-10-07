#include "craps_messages.h"

void gameRulesMessage() {
    printf(
        "\n"
        "\n"
        "Welcome to Craps by Benjamin Schreiber, for CS121. "
        "Begin the game by placing a wager. You will be able to add to the wager each round. "
        "On round one, if you land a 7 or an 11, you instantly win. "
        "If you land a 2, 3, or 12, you lose. "
        "Any other number you roll will become the point. For subsequent rounds, your goal is to roll the point."
        "If you roll a 7 in these rounds, you lose. If you roll the point, you win."
        "\n"
        "\n"
        );
}

void houseBalanceMessage(int balance) {
    printf(
        "The house balance is %d\n", balance
    );
}

void confirmMessage() {
    char a;
    printf("\nPress ENTER to continue.");
    scanf("%c%*c", &a);
    system("clear");
}

void placeWagerMessage(int *wager) {
    printf("Place a wager! ");
    scanf("%d", wager);
}

void wagerPlacedMessage(int wager) {
    printf("The current wager is %d", wager);
}

void rollDiceMessage() {
    printf("Rolling the dice!");
}

void showDiceMessage(int diceSum) {
    printf("You rolled a: %d", diceSum);
}

void youLoseGameMessage() {
    printf("you lost craps, dude... :(");
}

void pointMessage(int point) {
    printf("The point is: %d", point);
}

void addToWagerMessage(int wager) {
    printf("Adding %d to your wager", wager);
}

void youWinGameMessage() {
    printf("Holy friggin craps you won!");
}

void exitMessage() {
    printf("game ova");
}