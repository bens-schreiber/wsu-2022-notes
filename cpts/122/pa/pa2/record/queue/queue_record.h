#include "../record_t.h"
#include "../iterator/iterator_record.h"

// Create a new node
static Node *record_new(Record data);

// new Queue<Record>
// Create a new Queue with the head and tail pointing to a null node
Queue *queue_new();

// destructor
// Frees the queue and all elements
void queue_destruct(Queue *queue);

// .tailInsert()
// Insert a node made from [data] at the tail (last index of all elements)
Node *queue_tailInsert(Queue *queue, Record data);

// .headInsert()
// Insert a node made from [data] at the head (beginning of all elements, head->next)
Node *queue_headInsert(Queue *queue, Record data);

// .insertIndex(index: n)
// Insert a node made from [data] at index n
Node *queue_insertIndex(Queue *queue, Record data, unsigned int index);

// .insert()
// Inserts at head if no data, defaults to tail otherwise
Node *queue_insert(Queue *queue, Record data);

// .popTail()
// Pop the back of the queue
void queue_popTail(Queue *queue);

// .popHead()
// Pop the head of the queue
void queue_popHead(Queue *queue);

// .popIndex(index: n)
// Pop a node at index n
void queue_popIndex(Queue *queue, unsigned int index);