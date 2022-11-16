#include "menu.h"

int displayMenu() {

    switch (getIntInput()) {
        case 1: 
            // display rules
            break;
        case 2:
            // start game
            break;
        case 3:
            // exit
            return 0;
    }

    return 1;
}