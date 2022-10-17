#include "menu.h"

int displayMenu()
{
    system("clear");
    displayMenuMessage();

    switch (_awaitMenuInput())
    {
        case 1:
            displayGameRulesMessage();
            break;
        case 2:
            yahtzeeGameStart();
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