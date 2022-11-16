#include "menu.h"
#include "../game/game.h"

int displayMenu() {

    logMenu();

    switch (getIntInput()) {
        case 1: 
            // display rules
            logRules();
            break;
        case 2:
            // start game
            startPokerGame();
            break;
        case 3:
            // exit
            return 0;
    }

    return 1;
}