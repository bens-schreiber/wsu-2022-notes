#include "linked_list_t.h"
Node *makeNode(Contact newData) {
    Node *n = malloc(sizeof(Node));
    n->data = newData;
    return n;
}

Boolean insertContactAtFront(Node **pList, Contact newData) {

    // create a node, return false if null
    Node *n = makeNode(newData);
    if (!n) {return FALSE;}

    // put the new node in front
    n->pNext = *pList;

    // if plist is null return true
    if (!(*pList)) {return TRUE;}

    // pLists previous node to n
    (*pList)->pPrev = n;
    return TRUE;
}

Boolean insertContactInOrder(Node **pList, Contact newData) {

    // find the spot it should be at
    while ((*pList)->pNext 
        && strcmp(newData.name, (*pList)->data.name)) {
            (*pList) = (*pList)->pNext;
    }

    // create node, return false if null
    Node *n = makeNode(newData);
    if (!n) {return FALSE;}

    // put it between
    n->pPrev = (*pList)->pPrev;
    n->pNext = (*pList);
    (*pList)->pPrev = n;
    return TRUE;
}