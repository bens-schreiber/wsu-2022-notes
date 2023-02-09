#include "commands.h"

static void _replaceStrWithInput(char a[STRING_SIZE]) {
        char str[STRING_SIZE];
        memcpy(a, getStrInput("Enter a value: ", str), STRING_SIZE);
}

static int _findAllInstancesOfArtist(Queue **queue, const char *artist, Node *buffer[]) {
    Iterator iter = iter_new(*queue);
    int i = 0;
    while (iter_next(&iter)) {
        if (strcmp(iter.node->data.artist, artist) == 0) {buffer[i++] =  iter.node;}
    };
    return i;
}

void loadRecords(Queue **queue)  {
    FILE *f = fopen(INPUT_FILE, "r");
    (*queue) = readRecordsFromFile(f);
    fclose(f);
}

void store();

void displayAllRecords(Queue **queue) {
    Record r;
    Iterator iter = iter_new(*queue);
    while (iter_next(&iter)) {
        r = iter.node->data;
        printf(
            "Artist: %s, Album: %s, Genre: %s\n"
            "Song: %s, Length: %d:%d\n"
            "Rating: %d, Plays: %d\n\n",
            r.artist, r.album, r.genre, r.song, r.length.minutes, r.length.seconds, r.rating, r.plays
        );
    };
}

void displayAllArtistRecords(Queue **queue, const char *artist) {
    Node *buffer[(*queue)->length];
    int matches = _findAllInstancesOfArtist(queue, artist, buffer);
    Record r;
    for (int i = 0; i < matches; ++i) {
        r = buffer[i]->data;
        printf(
            "Artist: %s, Album: %s, Genre: %s\n"
            "Song: %s, Length: %d:%d\n"
            "Rating: %d, Plays: %d\n\n",
            r.artist, r.album, r.genre, r.song, r.length.minutes, r.length.seconds, r.rating, r.plays
        );
    }
}

void edit(Queue **queue, const char *artist) {
    Node *buffer[(*queue)->length];
    int matches = _findAllInstancesOfArtist(queue, artist, buffer);

    // No matches
    if (matches == 0) {
        printf("No matches found.");
        return;
    }

    // Pick from the found albums
    printf("Choose an album: \n");
    for (int i = 0; i < matches; ++i) {
        printf("(%d) %s\n", i, buffer[i]->data.album);
    }

    // Get the corresponding album
    Record *r = &buffer[getIntInput("", 0,matches)]->data;

    // Choose the field to edit
    switch(getIntInput(
            "Enter the field you would like to edit\n"
            "(1) Album\n"
            "(2) Artist\n"
            "(3) Genre\n"
            "(4) Length\n"
            "(5) Plays\n"
            "(6) Ratings\n"
            "(7) Song\n", 
            1,7)
        ) {
        case 1: {
            _replaceStrWithInput(r->album);
            break;
        }
        case 2: {
            _replaceStrWithInput(r->artist);
            break;
        }
        case 3: {
            _replaceStrWithInput(r->genre);
            break;
        }
        case 4: {
            int s = getIntInput("Enter seconds", 0, 60);

            int m = getIntInput("Enter minutes", 0,60);

            r->length.seconds = s;
            r->length.minutes = m;
            break;
        }
        case 5: {
            r->rating = getIntInput("Enter a rating (1-5)", 1, 5);
            break;
        }
        case 6: {
            _replaceStrWithInput(r->song);
        }
    }
}

void rate(Queue *queue);

void play(Queue *queue);
