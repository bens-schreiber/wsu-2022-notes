#include "defs.h"

typedef struct node
{
Contact data;
struct node *pNext;
struct node *pPrev; // this lab is now using two links
} Node;

Node *makeNode(Contact newData);