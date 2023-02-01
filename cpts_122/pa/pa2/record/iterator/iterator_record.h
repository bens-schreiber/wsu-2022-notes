#include "../record_t.h"
// .toHead()
// Sets the iterator index to 0 and node to front
void toHead_IteratorRecord(QueueRecord *queue);

// .toTail()
// Sets the iterator index to queue->length - 1 and node to tail
void toTail_IteratorRecord(QueueRecord *queue);

// .hasNext()
// Checks if the index is less than size
unsigned char hasNext_IteratorRecord(QueueRecord *queue);

// .hasPrevius()
// Checks if the index is greater than 0
unsigned char hasPrevious_IteratorRecord(QueueRecord *queue);

// .next()
// goes to the next node
NodeRecord *next_IteratorRecord(QueueRecord *queue);

// .previous()
// Goes to the previous node
NodeRecord *previous_IteratorRecord(QueueRecord *queue);