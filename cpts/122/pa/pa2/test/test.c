#include "../commands/commands.h"
#include "../record/record.h"

int main(int argc, char const *argv[])
{
    Queue **queue = malloc(sizeof(Queue*));
    loadRecords(queue);
    displayAllArtistRecords(queue, "Swift, Taylor");
    queue_destruct(*queue);
    return 0;
}
