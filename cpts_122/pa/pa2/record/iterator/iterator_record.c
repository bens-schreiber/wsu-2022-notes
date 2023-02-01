#include "iterator_record.h"

void toHead_IteratorRecord(QueueRecord *list) {
    list->iterator.index = 0;
    list->iterator.node = list->head;
}

void toTail_IteratorRecord(QueueRecord *list) {
    list->iterator.index = list->length - 1;
    list->iterator.node = list->tail;
}

unsigned char hasNext_IteratorRecord(QueueRecord *list) {
    return list->iterator.index != list->length - 1;
}

unsigned char hasPrevious_IteratorRecord(QueueRecord *list) {
    return list->iterator.index > 0;
}

void next_IteratorRecord(QueueRecord *list) {
    list->iterator.index++;
    list->iterator.node = list->iterator.node->next;
}

void previous_IteratorRecord(QueueRecord *list) {
    list->iterator.index--;
    list->iterator.node = list->iterator.node->previous;
}