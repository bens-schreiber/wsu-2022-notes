#include "../record/record.h"
#include "../reader/reader.h"

// Load all of the records into a queue
void loadRecords(QueueRecord **queue);

void store();

// Display all records
// OR
// Display all records of an artist
void displayRecords(QueueRecord **queue);

void edit(QueueRecord *queue);

void rate(QueueRecord *queue);

void play(QueueRecord *queue);
