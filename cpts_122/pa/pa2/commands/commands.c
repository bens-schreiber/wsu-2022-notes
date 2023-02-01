#include "commands.h"

void loadRecords(QueueRecord **queue)  {
    FILE *f = fopen(INPUT_FILE, "r");
    (*queue) = readRecordsFromFile(f);
    fclose(f);
}

void store();

void displayRecords(QueueRecord **queue) {
    Record r;
    while (next_IteratorRecord(*queue)) {
        r = (*queue)->iterator.node->data;
        printf(
            "Artist: %s, Album: %s, Genre: %s\n"
            "Song: %s, Length: %d:%d\n"
            "Rating: %d, Plays: %d\n\n",
            r.artist, r.album, r.genre, r.song, r.length.minutes, r.length.seconds, r.rating, r.plays
        );
    };
}

void edit(QueueRecord *queue);

void rate(QueueRecord *queue);

void play(QueueRecord *queue);
