#include "menu.h"

static void _loadRecords(Queue **queue) {
    loadRecords(queue);
    clear();
    printf("Records loaded!\n\n");
}

static void _displayRecords(Queue **queue) {
    if (!*queue) {
        clear();
        printf("Records need to be loaded first\n\n");
        return;
    }
    
    clear();
    printf(
        "(1) Display all records \n"
        "(2) Display all artists records\n"
        "Enter a value: "
    );
    switch (displayOption("")) {
        case 1: {
            clear();
            displayAllRecords(queue);
            break;
        }
        case 2: {
            printf("Enter an artists name: ");
            char buffer[STRING_SIZE];
            fflush(stdin);
            fgets(buffer, STRING_SIZE, stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            clear();
            displayAllArtistRecords(queue, buffer);
            break;
        }
    }
    getInput();
    clear();
}

int displayMenu(Queue **queue) {
    outMenuOptions();
    switch(getIntInput()) {
        case 1: {
            _loadRecords(queue);
            break;
        }
        case 2:
            // store
            break;
        case 3: {
            _displayRecords(queue);
            break;
        }
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
            break;

    }
    return 1;
}

void outMenuOptions() {
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