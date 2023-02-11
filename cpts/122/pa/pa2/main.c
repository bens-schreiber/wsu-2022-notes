#include <time.h>
#include "src/main/menu/menu.h"
#include "src/framework/record/record.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Queue **queue = malloc(sizeof(Queue*));
    clear();
    while (displayMenu(queue));
    return 0;
}
