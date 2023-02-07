#include "../record/record.h"
#include "../reader/reader.h"

// Load all of the records into a queue
void loadRecords(Queue **queue);

void store();

// Display all records loaded
void displayAllRecords(Queue **queue);

// Display all records associated with an artist
void displayAllArtistRecords(Queue **queue, const char *artist);

void edit(Queue *queue);

void rate(Queue *queue);

void play(Queue *queue);
