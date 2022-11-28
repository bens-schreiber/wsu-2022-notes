#include "log.h"

void logClear() {
    system("clear");
}

int getIntInput() {
    int input = 0;
    printf("\nEnter a value: ");
    scanf("%d", &input);
    return input;
}

void getInput() {
    printf("\nPress ENTER to continue!\n");
    char input = 0;
    fflush(stdin);
    getchar();
    logClear();
}

void logMenu() {
    logClear();
    printf(
        "Poker by Benjamin Schreiber \n\n"
        "# Press 1 to view the rules \n"
        "# Press 2 to start Poker \n"
        "# Press 3 to exit \n"
    );
}

void logRules() {
    printf("these are the roools....\n");
}

void logAskBet(int player, int balance) {
    printf("[Player %d] place your bet! (your balance is %d)", player, balance);
}