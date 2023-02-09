#include "iterator_record.h"

Iterator iter_new(Queue *queue) {
     return (Iterator) {.index = -1, .node = queue->head, .queue = queue};
}

void iter_toHead(Iterator *iterator) {
    iterator->index = -1;
    iterator->node = iterator->queue->head;
}

void iter_toTail(Iterator *iterator) {
    iterator->index = iterator->queue->length - 1;
    iterator->node = iterator->queue->tail;
}

unsigned char iter_hasNext(Iterator *iterator) {
    return iterator->index != iterator->queue->length - 1;
}

unsigned char iter_hasPrevious(Iterator *iterator) {
    return iterator->index > 0;
}

Node *iter_next(Iterator *iterator) {
    if (!iter_hasNext(iterator)) {
        return NULL;
    }
    iterator->index++;
    iterator->node = iterator->node->next;
    return iterator->node;
}

Node *iter_previous(Iterator *iterator) {
    if (!iter_hasPrevious(iterator)) {
        return NULL;
    }
    iterator->index--;
    iterator->node = iterator->node->previous;
    return iterator->node;
}