#include "menu.h"

static void _gamePlayer() {
    PokerGame *game = pokerGame();
    startPokerGame(game);
    while (1) {
        logPlayAgain();
        switch(getIntInput()) {
        case 0:
            free(game);
            return;
        case 1:
            startPokerGame(game);
            break;
    }
    }
}

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
            _gamePlayer();
            break;
        case 3:
            runTests();
            break;
        case 4:
            // exit
            return 0;
        
    }

    return 1;
}