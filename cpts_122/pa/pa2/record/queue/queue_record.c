#include "queue_record.h"

static NodeRecord *_new_NodeRecord(Record data) {
    NodeRecord *n = malloc(sizeof(NodeRecord));
    n->data = data;
    n->next = NULL;
    n->previous = NULL;
    return n;
}

QueueRecord *new_QueueRecord() {

    // Create a new QueueRecord instance
    QueueRecord *queue = malloc(sizeof(QueueRecord));

    // Null beginning of queue
    queue->head = _new_NodeRecord((Record) {});

    // Set head to tail
    queue->tail = queue->head;

    // Iterate from index -1 at the null head
    queue->iterator = (IteratorNodeRecord) {.index = -1, .node = queue->head};

    // Length is currently 1 (disregard null head)
    queue->length = 0;
    return queue;
}

void destruct_QueueRecord(QueueRecord *queue) {

    // Free all node instances
    while (queue->length > 0) {
        popTail_QueueRecord(queue);
    }

    // Free queue instance
    free(queue);
}

NodeRecord *tailInsert_QueueRecord(QueueRecord *queue, Record data) {

    // Create new node
    NodeRecord *n = _new_NodeRecord(data);

    // Insert the node at the end
    n->previous = queue->tail;
    queue->tail->next = n;
    queue->tail = n;
    queue->length++;
    return n;
}

NodeRecord *headInsert_QueueRecord(QueueRecord *queue, Record data) {

    // Insert the node after the null head
    // Consider the list [a,c] where we 'a' is the null head, and we are inserting b at [a,b,c]
    // (C COULD BE NULL)
    NodeRecord *a = queue->head; 
    NodeRecord *b = _new_NodeRecord(data);  // New node
    NodeRecord *c = a->next;

    a->next = b;
    b->previous = a;
    b->next = c;
    if (c) {c->previous = b;}
    queue->length++;
    return b;
}

NodeRecord *insertIndex_QueueRecord(QueueRecord *queue, Record data, unsigned int index) {

    // Handle out of bounds and head/tail insertion
    if (index > (queue->length - 1)) {return NULL;}
    if (index == 0) {return headInsert_QueueRecord(queue, data);}
    if (index == queue->length - 1) {return tailInsert_QueueRecord(queue, data);}

    // Iterate to index from head
    // could be smart here and based off index choose head or tail
    toHead_IteratorRecord(queue);
    while (next_IteratorRecord(queue) && queue->iterator.index < index);

    // Consider the nodes [a,c] where we want to place [a,b,c] at index iterator.index
    NodeRecord *a = queue->iterator.node;
    NodeRecord *c = a->next;
    NodeRecord *b = _new_NodeRecord(data);

    c->previous = b;
    a->next = b;
    b->previous = a;
    b->next = c;

    queue->length++;
    return b;
}

NodeRecord *insert_QueueRecord(QueueRecord *queue, Record data) {
    if (queue->length == 0) {
        return headInsert_QueueRecord(queue, data);
    }
    return tailInsert_QueueRecord(queue, data);
}

void popTail_QueueRecord(QueueRecord *queue) {

    if (queue->length == 0) {return;}
    
    // Get the node before the tail
    NodeRecord *n = queue->tail->previous;

    // Set the node before the tail to link forward to null
    n->next = NULL;

    // Destroy the tail
    free(queue->tail);

    // Set the node before the tail to the new tail
    queue->tail = n;
    
    queue->length--;
}

void popHead_QueueRecord(QueueRecord *queue) {

    if (queue->length == 0) {return;}

    // We want to pop the node after the null head
    // Consider the nodes [a,b,c] where 'a' is the null head and 'b' is what we want to delete
    NodeRecord *a = queue->head;
    NodeRecord *b = a->next;
    NodeRecord *c = b->next;

    a->next = c;
    c->previous = a;
    free(b);
    
    queue->length--;
}

void popIndex_QueueRecord(QueueRecord *queue, unsigned int index) {

    // Handle out of bounds and head/tail deletion
    if (index > (queue->length - 1)) {return;}
    if (queue->length == 0) {return;}
    if (index == 0) {return popHead_QueueRecord(queue);}
    if (index == queue->length - 1) {return popTail_QueueRecord(queue);}

    // Iterate to index n
    toHead_IteratorRecord(queue);
    while (next_IteratorRecord(queue) && queue->iterator.index < index);

    // Consider the nodes [a,b,c] where b is being the node at index n
    NodeRecord *a = queue->iterator.node->previous;
    NodeRecord *b = queue->iterator.node;
    NodeRecord *c = queue->iterator.node->next;

    // Destroy b
    free(b);

    a->next = c;
    c->previous = a;

    queue->length--;
}