#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data[100];
    struct node *pNext;
};

int insertPosN(struct node **pHead, int n, char *newData) {

    // iterate
    while ((*pHead)->pNext && n-- > 0) {
        (*pHead) = (*pHead)->pNext;
    }

    // allocate
    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {return 0;}

    // copy taht memory in there
    memcpy(newNode->data, newData, 100);

    // put that guy in between there
    newNode->pNext = (*pHead)->pNext;
    (*pHead)->pNext = newNode;

    // return -1 if we didnt iterate n times
    return n == 0 ? 1 : -1;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
