#include "menu.h"

static void _loadRecords(Queue **queue) {
    loadRecords(queue);
    printf("\nRecords loaded!\n");
}

static void _displayRecords(Queue **queue) {
    printf(*queue ?  "Display all records (1) or display all artists records (2)   \n\n" : "Records need to be loaded first\n");
    if (*queue) {
        switch (displayOption("")) {
            case 1: {
                displayAllRecords(queue);
                break;
            }
            case 2: {
                printf("Enter an artists name: ");
                char buffer[STRING_SIZE];
                scanf("%s", buffer);
                displayAllArtistRecords(queue, buffer);
                break;
            }
        }
    }
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
    getInput();
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

void getInput() {
    printf("\nPress ENTER to continue!\n");
    char input = 0;
    fflush(stdin);
    getchar();
}

int displayOption(const char *prompt) {
    printf("%s", prompt);
    int input = 0;
    scanf("%d", &input);
    return input;
}