#include "menu.h"

int displayMenu() {

    logMenu();

    switch (getIntInput()) {
        case 1: 
            // display rules
            logRules();
            getInput();
            break;
        case 2:
            // start game
            startPokerGame();
            break;
        case 3:
            runTests();
        case 4:
            // exit
            return 0;
        
    }

    return 1;
}