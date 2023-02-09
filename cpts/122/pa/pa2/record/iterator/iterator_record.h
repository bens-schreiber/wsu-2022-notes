#include "../record_t.h"

Iterator iter_new(Queue *queue);

// .toHead()
// Sets the iterator index to 0 and node to front
void iter_toHead(Iterator *iterator);

// .toTail()
// Sets the iterator index to queue->length - 1 and node to tail
void iter_toTail(Iterator *iterator);

// .hasNext()
// Checks if the index is less than size
unsigned char iter_hasNext(Iterator *iterator);

// .hasPrevius()
// Checks if the index is greater than 0
unsigned char iter_hasPrevious(Iterator *iterator);

// .next()
// goes to the next node
// Be careful to put the iterator at either the head or tail initially
Node *iter_next(Iterator *iterator);

// .previous()
// Goes to the previous node
// Be careful to put the iterator at either the head or tail initially
Node *iter_previous(Iterator *iterator);