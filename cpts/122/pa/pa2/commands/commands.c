#include "commands.h"

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

    printf("Choose an album: \n");
    for (int i = 0; i < matches; ++i) {
        printf("(%d) %s\n", i, buffer[i]->data.album);
    }
    
}

void rate(Queue *queue);

void play(Queue *queue);
