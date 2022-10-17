#include "menu.h"

int displayMenu()
{
    system("clear");
    displayMenuMessage();

    switch (_awaitMenuInput())
    {
        case 1:
            displayGameRules();
            break;
        case 2:
            yahtzeeGame();
            break;
        case 3:
            return 0;   // EXIT
    }

    return 1;
}

int _awaitMenuInput()
{
    int input = 0;
    scanf("%d", &input);
    return input;
}