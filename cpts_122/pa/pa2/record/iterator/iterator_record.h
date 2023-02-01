#include "../record_t.h"
// .toHead()
// Sets the iterator index to 0 and node to front
void toHead_IteratorRecord(QueueRecord *list);

// .toTail()
// Sets the iterator index to list->length - 1 and node to tail
void toTail_IteratorRecord(QueueRecord *list);

// .hasNext()
// Checks if the index is less than size
unsigned char hasNext_IteratorRecord(QueueRecord *list);

// .hasPrevius()
// Checks if the index is greater than 0
unsigned char hasPrevious_IteratorRecord(QueueRecord *list);

// .next()
// goes to the next node
void next_IteratorRecord(QueueRecord *list);

// .previous()
// Goes to the previous node
void previous_IteratorRecord(QueueRecord *list);