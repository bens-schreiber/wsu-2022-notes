#include "log.h"
int getIntInput() {
    int input = 0;
    printf("\nEnter a value: ");
    scanf("%d", &input);
    return input;
}

void logMenu() {
    system("clear");
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