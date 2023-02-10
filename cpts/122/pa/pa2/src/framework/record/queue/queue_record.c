#include "queue_record.h"

static Node *record_new(Record data) {
    Node *n = malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    n->previous = NULL;
    return n;
}

Queue *queue_new() {

    // Create a new Queue instance
    Queue *queue = malloc(sizeof(Queue));

    // Null beginning of queue
    queue->head = record_new((Record) {});

    // Set head to tail
    queue->tail = queue->head;

    // Length is currently 1 (disregard null head)
    queue->length = 0;
    return queue;
}

void queue_destruct(Queue *queue) {

    // Free all node instances
    while (queue->length > 0) {
        queue_popTail(queue);
    }

    // Free queue instance
    free(queue);
}

Node *queue_tailInsert(Queue *queue, Record data) {

    // Create new node
    Node *n = record_new(data);

    // Insert the node at the end
    n->previous = queue->tail;
    queue->tail->next = n;
    queue->tail = n;
    queue->length++;
    return n;
}

Node *queue_headInsert(Queue *queue, Record data) {

    // Insert the node after the null head
    // Consider the list [a,c] where we 'a' is the null head, and we are inserting b at [a,b,c]
    // (C COULD BE NULL)
    Node *a = queue->head; 
    Node *b = record_new(data);  // New node
    Node *c = a->next;

    a->next = b;
    b->previous = a;
    b->next = c;
    if (c) {c->previous = b;}
    else {queue->tail = b;}
    queue->length++;
    return b;
}

Node *queue_insertIndex(Queue *queue, Record data, unsigned int index) {

    // Handle out of bounds and head/tail insertion
    if (index > (queue->length - 1)) {return NULL;}
    if (index == 0) {return queue_headInsert(queue, data);}
    if (index == queue->length - 1) {return queue_tailInsert(queue, data);}

    // Iterate to index from head
    // could be smart here and based off index choose head or tail
    Iterator iter = iter_new(queue);
    while (iter_next(&iter) && iter.index < index);

    // Consider the nodes [a,c] where we want to place [a,b,c] at index iterator.index
    Node *a = iter.node;
    Node *c = a->next;
    Node *b = record_new(data);

    c->previous = b;
    a->next = b;
    b->previous = a;
    b->next = c;

    queue->length++;
    return b;
}

Node *queue_insert(Queue *queue, Record data) {
    if (queue->length == 0) {
        return queue_headInsert(queue, data);
    }
    return queue_tailInsert(queue, data);
}


void queue_pop(Queue *queue, Node *n) {
    // Consider the nodes [a,b,c] where b is being the node at index n
    Node *a = n->previous;
    Node *b = n;
    Node *c = n->next;

    // Destroy b
    free(b);

    a->next = c;
    c->previous = a;

    queue->length--;
}

void queue_popTail(Queue *queue) {

    if (queue->length == 0) {return;}
    
    // Get the node before the tail
    Node *n = queue->tail->previous;

    queue_pop(queue, n);
}

void queue_popHead(Queue *queue) {

    if (queue->length == 0) {return;}

    // Head is the null head, so delete the actual head at head->next
    queue_pop(queue, queue->head->next);
}

void queue_popIndex(Queue *queue, unsigned int index) {

    // Handle out of bounds and head/tail deletion
    if (index > (queue->length - 1)) {return;}
    if (queue->length == 0) {return;}
    if (index == 0) {return queue_popHead(queue);}
    if (index == queue->length - 1) {return queue_popTail(queue);}

    // Iterate to index n
    Iterator iter = iter_new(queue);
    while (iter_next(&iter) && iter.index < index);

    queue_pop(queue, iter.node);
}