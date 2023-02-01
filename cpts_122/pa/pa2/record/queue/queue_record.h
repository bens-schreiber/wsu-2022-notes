#include "../record_t.h"
#include "../iterator/iterator_record.h"

// Create a new node
static NodeRecord *_new_NodeRecord(Record data);

// new Queue<Record>
// Create a new Queue with the head and tail pointing to a node made from [data]
QueueRecord *new_QueueRecord(Record data);

// destructor
// Frees the queue and all elements
void destruct_QueueRecord(QueueRecord *queue);

// .tailInsert()
// Insert a node made from [data] at the tail
void tailInsert_QueueRecord(QueueRecord *queue, Record data);

// .headInsert()
// Insert a node made from [data] at the head
void headInsert_QueueRecord(QueueRecord *queue, Record data);

// .insertIndex(index: n)
// Insert a node made from [data] at index n
void insertIndex_QueueRecord(QueueRecord *queue, Record data, unsigned int index);

// .popTail()
// Pop the back of the queue
void popTail_QueueRecord(QueueRecord *queue);

// .popHead()
// Pop the head of the queue
void popHead_QueueRecord(QueueRecord *queue);

// .popIndex(index: n)
// Pop a node at index n
void popIndex_QueueRecord(QueueRecord *queue, unsigned int index);