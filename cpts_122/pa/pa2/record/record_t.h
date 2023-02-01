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
typedef struct NodeRecord NodeRecord;
struct NodeRecord {
    NodeRecord *next;
    NodeRecord *previous;
    Record data;
};

// Iterator<Node<Record>>
// Tracks a paticular index of a node, can iterate forwards/backwards from any point
typedef struct {
    unsigned int index;
    NodeRecord* node;
} IteratorNodeRecord;

// Queue<Record>
// doubly linked list implemented queue
typedef struct {
    NodeRecord* head;
    NodeRecord* tail;
    IteratorNodeRecord iterator;
    unsigned int length;
} QueueRecord;