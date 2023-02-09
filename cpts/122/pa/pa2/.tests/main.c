#include "../commands/commands.h"
#include "../record/record.h"

int main(int argc, char const *argv[])
{
    Queue **queue = malloc(sizeof(Queue*));
    loadRecords(queue);
    queue_destruct(*queue);
    return 0;
}
