#include "saver.h"
static void saveToFile(Node *node, FILE *output) {
    Record r = node->data;
    fprintf(
        output,
        "\"%s\", %s, %s, %s, %d:%d,%d,%d", 
        r.artist, r.album, r.song, r.genre, r.length.minutes, r.length.seconds, r.plays, r.rating
    );
}

Queue **saveRecordsToFile(FILE *output, Queue **queue) {
    Iterator iter = iter_new(*queue);
    while(iter_hasNext(&iter)) {
        saveToFile(iter.node, output);
    }

    return queue;
}