#include "queue_record.h"

static NodeRecord *_new_NodeRecord(Record data) {
    NodeRecord *n = malloc(sizeof(NodeRecord));
    n->data = data;
    n->next = NULL;
    n->previous = NULL;
    return n;
}

QueueRecord *new_QueueRecord(Record data) {
    QueueRecord *queue = malloc(sizeof(QueueRecord));
    queue->head = _new_NodeRecord(data);
    queue->tail = queue->head;
    queue->iterator = (IteratorNodeRecord) {.index = 0, .node = queue->head};
    queue->length = 1;
    return queue;
}

void *destruct_QueueRecord(QueueRecord *queue) {
    while (queue->length > 0) {
        popTail_QueueRecord(queue);
    }
}

void tailInsert_QueueRecord(QueueRecord *queue, Record data) {
    NodeRecord *n = _new_NodeRecord(data);
    n->previous = queue->tail;
    queue->tail->next = n;
    queue->tail = n;
    queue->length++;
}

void headInsert_QueueRecord(QueueRecord *queue, Record data) {
    NodeRecord *n = _new_NodeRecord(data);
    n->next = queue->head;
    queue->head->previous = n;
    queue->head = n;
    queue->length++;
}

// could be smart here and based off index choose head or tail but i don't care
void insertIndex_QueueRecord(QueueRecord *queue, Record data, unsigned int index) {
    iteratorResetToHead_QueueRecord(queue);
    unsigned char i = 0;
    while (i++ < index) {
        iteratorNext_QueueRecord(queue);
    }
    NodeRecord *old = queue->iterator.node;
    NodeRecord *oldNext = queue->iterator.node->next;
    NodeRecord *new = _new_NodeRecord(data);
    oldNext->previous = new;
    old->next = new;
    new->previous = old;
    new->next = old->next;
}

void popTail_QueueRecord(QueueRecord *queue) {
    NodeRecord *n = queue->tail->previous;
    n->next = NULL;
    queue->tail = n;
    free(n);
    queue->length--;
}

void popHead_QueueRecord(QueueRecord *queue) {
    NodeRecord *n = queue;
}

void popIndex_QueueRecord(QueueRecord *queue, unsigned int index) {

}