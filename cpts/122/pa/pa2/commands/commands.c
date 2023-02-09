#include "commands.h"

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
    Record r;
    Iterator iter = iter_new(*queue);
    while (iter_next(&iter)) {
        r = iter.node->data;

        // Only output those associated with some artist
        if (strcmp(artist, r.artist) != 0) {continue;}

        printf(
            "Artist: %s, Album: %s, Genre: %s\n"
            "Song: %s, Length: %d:%d\n"
            "Rating: %d, Plays: %d\n\n",
            r.artist, r.album, r.genre, r.song, r.length.minutes, r.length.seconds, r.rating, r.plays
        );
    };
}

void edit(Queue *queue);

void rate(Queue *queue);

void play(Queue *queue);
