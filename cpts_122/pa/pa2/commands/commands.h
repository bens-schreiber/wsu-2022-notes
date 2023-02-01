#include "../record/record.h"
#include "../reader/reader.h"

// Load all of the records into a queue
void loadRecords(Queue **queue);

void store();

// Display all records
// OR
// Display all records of an artist
void displayRecords(Queue **queue);

void edit(Queue *queue);

void rate(Queue *queue);

void play(Queue *queue);
