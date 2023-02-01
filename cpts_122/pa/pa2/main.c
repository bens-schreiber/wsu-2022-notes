#include "menu/menu.h"
#include "record/record.h"

// TODO: account for user errors in queue library
int main(int argc, char const *argv[])
{
    Queue **queue = malloc(sizeof(Queue*));
    while (displayMenu(queue));
    queue_destruct(*queue);
    return 0;
}
