#include "src/main/menu/menu.h"
#include "src/framework/record/record.h"

int main(int argc, char const *argv[])
{
    Queue **queue = malloc(sizeof(Queue*));
    loadRecords(queue);
    sort(queue, ARTIST);
    queue_destruct(*queue);
    return 0;
}
