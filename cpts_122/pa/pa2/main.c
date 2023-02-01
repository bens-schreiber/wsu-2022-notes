#include "menu/menu.h"
#include "record/record.h"
int main(int argc, char const *argv[])
{
    QueueRecord *queue = NULL;
    while (displayMenu());
    return 0;
}
