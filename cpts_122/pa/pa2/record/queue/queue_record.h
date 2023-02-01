#include "../record_t.h"
#include "../iterator/iterator_record.h"

// Create a new node
static NodeRecord *_new_NodeRecord(Record data);

// new Queue<Record>
// Create a new Queue with the head and tail pointing to a null node
QueueRecord *new_QueueRecord();

// destructor
// Frees the queue and all elements
void destruct_QueueRecord(QueueRecord *queue);

// .tailInsert()
// Insert a node made from [data] at the tail (last index of all elements)
NodeRecord *tailInsert_QueueRecord(QueueRecord *queue, Record data);

// .headInsert()
// Insert a node made from [data] at the head (beginning of all elements, head->next)
NodeRecord *headInsert_QueueRecord(QueueRecord *queue, Record data);

// .insertIndex(index: n)
// Insert a node made from [data] at index n
NodeRecord *insertIndex_QueueRecord(QueueRecord *queue, Record data, unsigned int index);

// .insert()
// Inserts at head if no data, defaults to tail otherwise
NodeRecord *insert_QueueRecord(QueueRecord *queue, Record data);

// .popTail()
// Pop the back of the queue
void popTail_QueueRecord(QueueRecord *queue);

// .popHead()
// Pop the head of the queue
void popHead_QueueRecord(QueueRecord *queue);

// .popIndex(index: n)
// Pop a node at index n
void popIndex_QueueRecord(QueueRecord *queue, unsigned int index);