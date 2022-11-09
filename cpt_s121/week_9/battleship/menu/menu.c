#include "menu.h"
#include "../messages/messages.h"
#include "../game/game.h"

int displayMenu()
{
    // Clear screen and display menu
    system("clear");
    printMenu();

    switch (getIntInput(""))
    {
    case 1:
        printRules();
        break;
    case 2:
        battleShipGameStart();
        break;
    case 3:
        return 0; // EXIT
    }
    
    awaitInput();

    return 1;
}