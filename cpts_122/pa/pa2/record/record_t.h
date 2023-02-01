#pragma once
#include "../consts.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    unsigned int seconds;
    unsigned int minutes;
} Duration;

typedef struct {
    char artist[STRING_SIZE];
    char album[STRING_SIZE];
    char song[STRING_SIZE];
    char genre[STRING_SIZE];
    Duration length;
    unsigned int plays;
    unsigned int rating; 
} Record;

// Node<Record>
// Nodes for a doubly linked list
typedef struct Node Node;
struct Node {
    Node *next;
    Node *previous;
    Record data;
};

// Queue<Record>
// doubly linked list implemented queue
// Head always points to a null node before the beginning of data. 
// Iterator should be used to grab any data
// Initialize with new and insert first data with headInsert
typedef struct {
    Node* head;
    Node* tail;
    unsigned int length;
} Queue;

// Iterator<Queue<Node<Record>>>
// Tracks a paticular index of a node, can iterate forwards/backwards from any point
// EX: while (next_IteratorRecord(queue)) {queue->iterator ...}
typedef struct {
    int index;
    Node* node;
    Queue *queue;
} Iterator;