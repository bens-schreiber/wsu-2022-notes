#include "queue_record.h"

static NodeRecord *_new_NodeRecord(Record data) {
    NodeRecord *n = malloc(sizeof(NodeRecord));
    n->data = data;
    n->next = NULL;
    n->previous = NULL;
    return n;
}

QueueRecord *new_QueueRecord(Record data) {

    // Create a new QueueRecord instance
    QueueRecord *queue = malloc(sizeof(QueueRecord));

    // Make a node from data and set it as head
    queue->head = _new_NodeRecord(data);

    // Set head to tail
    queue->tail = queue->head;

    // Iterate from index 0 at the head
    queue->iterator = (IteratorNodeRecord) {.index = 0, .node = queue->head};

    // Length is currently 1
    queue->length = 1;
    return queue;
}

void *destruct_QueueRecord(QueueRecord *queue) {

    // Free all node instances
    while (queue->length > 0) {
        popTail_QueueRecord(queue);
    }

    // Free queue instance
    free(queue);
}

void tailInsert_QueueRecord(QueueRecord *queue, Record data) {

    // Create new node
    NodeRecord *n = _new_NodeRecord(data);

    // Insert the node at the end
    n->previous = queue->tail;
    queue->tail->next = n;
    queue->tail = n;
    queue->length++;
}

void headInsert_QueueRecord(QueueRecord *queue, Record data) {

    // Create a new node
    NodeRecord *n = _new_NodeRecord(data);

    // Insert the node at the head
    n->next = queue->head;
    queue->head->previous = n;
    queue->head = n;
    queue->length++;
}

// could be smart here and based off index choose head or tail but i don't care
void insertIndex_QueueRecord(QueueRecord *queue, Record data, unsigned int index) {

    // Iterate to index n
    toHead_IteratorRecord(queue);
    while (queue->iterator.index < index) {
        iteratorNext_QueueRecord(queue);
    }

    // Consider the nodes [a,c] where we want to place [a,b,c] at index iterator.index
    NodeRecord *a = queue->iterator.node;
    NodeRecord *c = queue->iterator.node->next;
    NodeRecord *b = _new_NodeRecord(data);
    c->previous = b;
    a->next = b;
    b->previous = a;
    b->next = c;

    queue->length++;
}

void popTail_QueueRecord(QueueRecord *queue) {
    
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

    // Get the node after the head
    NodeRecord *n = queue->head->next;

    // Set the node after the head to have no previous
    n->previous = NULL;

    // Destroy the head
    free(queue->head);

    // Set the node after the head to the new head
    queue->head = n;
    
    queue->length--;
}

void popIndex_QueueRecord(QueueRecord *queue, unsigned int index) {

    // Iterate to index n
    toHead_IteratorRecord(queue);
    while (queue->iterator.index < index) {
        iteratorNext_QueueRecord(queue);
    }

    // Consider the nodes [a,b,c] where b is being the node at index n
    NodeRecord *a = queue->iterator.node->previous;
    NodeRecord *c = queue->iterator.node->next;

    // Destroy b
    free(queue->iterator.node);

    a->next = c;
    c->previous = a;

    queue->length--;
}