#include "commands.h"

static void _replaceStrWithInput(char a[STRING_SIZE]) {
        char str[STRING_SIZE];
        memcpy(a, getStrInput("Enter a new value", str), STRING_SIZE);
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

void store(Queue **queue) {
    FILE *f = fopen(OUTPUT_FILE, "w");
    saveRecordsToFile(f, queue);
    fclose(f);
}

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

void rate(Queue **queue, const char *song) {
    Iterator iter = iter_new(*queue);
    Node *n = NULL;
    while (iter_next(&iter)) {
        if (strcmp(iter.node->data.song, song) == 0) {n = iter.node; break;}
    }

    if (n == NULL) {
        printf("No song found.");
        return;
    }

    n->data.rating = getIntInput("Rating Value (1-5)", 1,5);
}

void play(Queue **queue) {
    Iterator iter = iter_new(*queue);
    while (iter_next(&iter)) {
        printf("Now playing - %s by %s\n", iter.node->data.song, iter.node->data.artist);
        sleep(3);
    }
}

void insert(Queue **queue) {
    Record r = (Record) {};
    getStrInput("Enter artist name", r.artist);
    getStrInput("Enter album name", r.album);
    getStrInput("Enter song name", r.song);
    getStrInput("Enter genre name", r.genre);
    r.rating = getIntInput("Rating",1, 5);
    r.plays = getIntInput("Plays", 0,999);
    r.length.minutes = getIntInput("Minutes", 0, 60);
    r.length.seconds = getIntInput("Seconds", 0, 60);
    queue_headInsert(*queue, r);
}

void delete(Queue **queue, const char *song) {
    Iterator iter = iter_new(*queue);
    while (iter_next(&iter)) {
        if (strcmp(iter.node->data.song, song) == 0) {break;}
    }
    queue_popIndex(*queue, iter.index);
}

static int _cmpr(Node *a, Node *b, const Sort sortType) {
    switch (sortType) {
        case ALBUM:
            return strcmp(a->data.album, b->data.album);
        case ARTIST:
            return strcmp(a->data.artist, b->data.artist);
        case RATING:
            return a->data.rating > b->data.rating;
        case PLAYS:
            return a->data.plays < b->data.plays;
    }
}

// Bubble sorts
void sort(Queue **queue, const Sort sortType) {
    Iterator iterA = iter_new(queue);
    Iterator iterB;
    while (iter_next(&iterA)) {
        iterB = iterA;
        while (iter_next(&iterB)) {
            if (_cmpr(iterB.node, iterB.node->next, sortType)) {
                queue_swap(iterB.node, iterB.node->next);
            }
        }
    }
}