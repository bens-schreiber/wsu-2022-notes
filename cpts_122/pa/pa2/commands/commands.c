#include "commands.h"
void loadRecords(QueueRecord **queue)  {
    FILE *f = fopen(INPUT_FILE, "r");
    (*queue) = readRecordsFromFile(f);
    fclose(f);
}

void store();

void displayRecords(QueueRecord **queue) {
    do {
        printf("%s\n", (*queue)->iterator.node->data.artist);
    } while (next_IteratorRecord(*queue));
}

void edit(QueueRecord *queue);

void rate(QueueRecord *queue);

void play(QueueRecord *queue);
