#include "menu.h"

int displayMenu() {
    outMenuOptions();
    switch(getIntInput()) {
        case 1:
            // load
            break;
        case 2:
            // store
            break;
        case 3:
            // display
            break;
        case 4:
            // insert
            break;
        case 5:
            // delete
            break;
        case 6:
            // edit
            break;
        case 7:
            // sort
            break;
        case 8:
            // rate
            break;
        case 9:
            // play
            break;
        case 10:
            // shuffle
            break;
        case 11:
            // exit;
            return 0;
        default:
            return 0;

    }
    return 1;
}

void outMenuOptions() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf(
        "(1) load\n"
        "(2) store\n"
        "(3) display\n"
        "(4) insert\n"
        "(5) delete\n"
        "(6) edit\n"
        "(7) sort\n"
        "(8) rate\n"
        "(9) play\n"
        "(10) shuffle\n"
        "(11) exit\n"
    );
}

int getIntInput() {
    int input = 0;
    printf("\nEnter a value: ");
    scanf("%d", &input);
    return input;
}