#include "queue_record.h"

static NodeRecord *_new_NodeRecord(Record data) {
    NodeRecord *n = malloc(sizeof(NodeRecord));
    n->data = data;
    n->next = NULL;
    n->previous = NULL;
    return n;
}

QueueRecord *new_QueueRecord(Record data) {
    QueueRecord *list = malloc(sizeof(QueueRecord));
    list->head = _new_NodeRecord(data);
    list->tail = list->head;
    list->iterator = (IteratorNodeRecord) {.index = 0, .node = list->head};
    list->length = 1;
    return list;
}

void tailInsert_QueueRecord(QueueRecord *list, Record data) {
    NodeRecord *n = _new_NodeRecord(data);
    n->previous = list->tail;
    list->tail->next = n;
    list->tail = n;
    list->length++;
}

void headInsert_QueueRecord(QueueRecord *list, Record data) {
    NodeRecord *n = _new_NodeRecord(data);
    n->next = list->head;
    list->head->previous = n;
    list->head = n;
    list->length++;
}

// could be smart here and based off index choose head or tail but i don't care
void insertIndex_QueueRecord(QueueRecord *list, Record data, unsigned int index) {
    iteratorResetToHead_QueueRecord(list);
    unsigned char i = 0;
    while (i++ < index) {
        iteratorNext_QueueRecord(list);
    }
    NodeRecord *old = list->iterator.node;
    NodeRecord *oldNext = list->iterator.node->next;
    NodeRecord *new = _new_NodeRecord(data);
    oldNext->previous = new;
    old->next = new;
    new->previous = old;
    new->next = old->next;
}

void popTail_QueueRecord(QueueRecord *list) {
    NodeRecord *n = list->tail->previous;
    n->next = NULL;
    free(n);
    list->length--;
}

void popHead_QueueRecord(QueueRecord *list) {
    NodeRecord *n = list;
}

void popIndex_QueueRecord(QueueRecord *list, unsigned int index) {

}