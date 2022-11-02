#include "menu.h"
#include "../messages/messages.h"
#include "../game/game_struct.h"

int displayMenu()
{
    // Clear screen and display menu
    system("clear");
    printMenu();

    BattleShipGame *game;

    switch (getIntInput(""))
    {
    case 1:
        printRules();
        break;
    case 2:
        game = battleShipGame();
        battleShipGameStart(game);
        free(game);
        break;
    case 3:
        return 0; // EXIT
    }
    
    awaitInput();

    return 1;
}