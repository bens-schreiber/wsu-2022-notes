#include "menu.h"

int displayMenu()
{
    // Clear screen and display menu
    system("clear");
    displayMenuMessage();

    switch (awaitMenuInput())
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