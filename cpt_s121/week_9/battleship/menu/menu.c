#include "menu.h"
#include "../messages/messages.h"
#include "../game/game_struct.h"

int displayMenu()
{
    // Clear screen and display menu
    system("clear");
    printMenu();

    switch (getIntOrCharInput(""))
    {
        case 1:
            printRules();;
            break;
        case 2:
            BattleShipGame *game = battleShipGame();
            battleShipGameStart(game);
            free(game);
            break;
        case 3:
            return 0;   // EXIT
    }

    return 1;
}