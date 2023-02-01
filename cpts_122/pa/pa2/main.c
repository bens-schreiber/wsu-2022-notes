#include "menu/menu.h"
#include "record/record.h"

// TODO: account for user errors in queue library
int main(int argc, char const *argv[])
{
    QueueRecord **queue = malloc(sizeof(QueueRecord*));
    while (displayMenu(queue));
    return 0;
}
