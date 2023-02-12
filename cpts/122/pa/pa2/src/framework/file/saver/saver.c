#include "saver.h"
static void saveToFile(Node *node, FILE *output) {
    Record r = node->data;
    fprintf(
        output,
        "\"%s\",%s,%s,%s,%d:%d,%d,%d%c", 
        r.artist, r.album, r.song, r.genre, r.length.minutes, r.length.seconds, r.plays, r.rating, node->next == NULL ? ' ' : '\n'
    );
}

Queue **saveRecordsToFile(FILE *output, Queue **queue) {
    Iterator iter = iter_new(*queue);
    while(iter_next(&iter)) {
        saveToFile(iter.node, output);
    }
    return queue;
}