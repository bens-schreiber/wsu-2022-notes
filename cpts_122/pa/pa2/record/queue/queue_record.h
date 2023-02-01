#include "../record_t.h"

// Create a new node
static NodeRecord *_new_NodeRecord(Record data);

// new Queue<Record>
// Create a new Queue with the head and tail pointing to a node made from [data]
QueueRecord *new_QueueRecord(Record data);

// .tailInsert()
// Insert a node made from [data] at the tail
void tailInsert_QueueRecord(QueueRecord *list, Record data);

// .headInsert()
// Insert a node made from [data] at the head
void headInsert_QueueRecord(QueueRecord *list, Record data);

// .insertIndex(index: n)
// Insert a node made from [data] at index n
void insertIndex_QueueRecord(QueueRecord *list, Record data, unsigned int index);

// .popTail()
// Pop the back of the queue
void popTail_QueueRecord(QueueRecord *list);

// .popHead()
// Pop the head of the queue
void popHead_QueueRecord(QueueRecord *list);

// .popIndex(index: n)
// Pop a node at index n
void popIndex_QueueRecord(QueueRecord *list, unsigned int index);