#include "menu/menu.h"
#include "record/record.h"

int main(int argc, char const *argv[])
{
    Queue **queue = malloc(sizeof(Queue*));
    clear();
    while (displayMenu(queue));
    queue_destruct(*queue);
    return 0;
}
