#include "menu/menu.h"
#include "record/record.h"
int main(int argc, char const *argv[])
{
    QueueRecord **queue = malloc(sizeof(QueueRecord*));
    while (displayMenu(queue));
    return 0;
}
