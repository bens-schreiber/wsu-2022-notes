#include "src/main/menu/menu.h"
#include "src/framework/record/record.h"

int main(int argc, char const *argv[])
{
    Queue **queue = malloc(sizeof(Queue*));
    loadRecords(queue);
    displayAllArtistRecords(queue, "Eminem");
    queue_destruct(*queue);
    return 0;
}
