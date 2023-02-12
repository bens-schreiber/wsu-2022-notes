#include "menu.h"

static unsigned char _recordsLoaded(Queue **queue) {
    if (!*queue) {
        clear();
        printf("Records need to be loaded first\n\n");
        return 0;
    }
    return 1;
}

static void _loadRecords(Queue **queue) {
    loadRecords(queue);
    clear();
    printf("Records loaded!\n");
}

static void _displayRecords(Queue **queue) {
    if (!_recordsLoaded(queue)) {
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
            char str[STRING_SIZE];
            getStrInput("Enter an artists name", str);
            clear();
            displayAllArtistRecords(queue, str);
            break;
        }
    }
    getInput();
    clear();
}

static void _editRecords(Queue **queue) {
    if (!_recordsLoaded(queue)) {
        return;
    }
    clear();
    char str[STRING_SIZE];
    edit(queue, getStrInput("Enter an artists name", str));
    clear();
}

static void _rateSong(Queue **queue) {
    if (!_recordsLoaded(queue)) {
        return;
    }
    clear();
    char str[STRING_SIZE];
    rate(queue, getStrInput("Enter a song name", str));
    clear();
}

static void _playSongs(Queue **queue) {
    if (!_recordsLoaded(queue)) { return; }
    clear();
    play(queue);
    clear();
}

static void _storeRecords(Queue **queue) {
    if (!_recordsLoaded(queue)) { return; }
    store(queue);
    clear();
    printf("Records saved!\n");
}

static void _insertRecord(Queue **queue) {
    if (!_recordsLoaded(queue)) { return; }
    insert(queue);
    clear();
    printf("Inserted new song.\n");
}

static void _deleteRecord(Queue **queue) {
    if (!_recordsLoaded(queue)) { return; }
    char str[STRING_SIZE];
    getStrInput("Enter a song name to delete", str);
    delete(queue, str);
    clear();
    printf("Song deleted.\n");
}

static void _sortRecords(Queue **queue) {
    if (!_recordsLoaded(queue)) { return; }
    clear();
    sort(queue, getIntInput(
        "(1) Artist\n"
        "(2) Album\n"
        "(3) Rating\n"
        "(4) Plays\n", 1, 4
    ) - 1);
    clear();
    printf("Sorted!\n");
}

static void _shuffle(Queue **queue) {
    if (!_recordsLoaded(queue)) { return; }
    clear();
    shuffle(queue);
    clear();
}

int displayMenu(Queue **queue) {
    switch(
        getIntInput(
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
            "(11) exit\n",
            1,12)
        ) {
        case 1: {
            _loadRecords(queue);
            break;
        }
        case 2:
            _storeRecords(queue);
            break;
        case 3: {
            _displayRecords(queue);
            break;
        }
        case 4:
            _insertRecord(queue);
            break;
        case 5:
            _deleteRecord(queue);
            break;
        case 6:
            _editRecords(queue);
            break;
        case 7:
            _sortRecords(queue);
            break;
        case 8:
            _rateSong(queue);
            break;
        case 9:
            _playSongs(queue);
            break;
        case 10:
            // shuffle
            break;
        case 11:
            if (*queue) {_storeRecords(queue);}
            return 0;
        default:
            break;

    }
    return 1;
}