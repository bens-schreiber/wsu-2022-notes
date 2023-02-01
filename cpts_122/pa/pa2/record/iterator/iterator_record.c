#include "iterator_record.h"

void toHead_IteratorRecord(QueueRecord *queue) {
    queue->iterator.index = 0;
    queue->iterator.node = queue->head;
}

void toTail_IteratorRecord(QueueRecord *queue) {
    queue->iterator.index = queue->length - 1;
    queue->iterator.node = queue->tail;
}

unsigned char hasNext_IteratorRecord(QueueRecord *queue) {
    return queue->iterator.index != queue->length - 1;
}

unsigned char hasPrevious_IteratorRecord(QueueRecord *queue) {
    return queue->iterator.index > 0;
}

NodeRecord *next_IteratorRecord(QueueRecord *queue) {
    if (!hasNext_IteratorRecord(queue)) {
        return NULL;
    }
    queue->iterator.index++;
    queue->iterator.node = queue->iterator.node->next;
    return queue->iterator.node;
}

NodeRecord *previous_IteratorRecord(QueueRecord *queue) {
    if (!hasPrevious_IteratorRecord(queue)) {
        return NULL;
    }
    queue->iterator.index--;
    queue->iterator.node = queue->iterator.node->previous;
    return queue->iterator.node;
}