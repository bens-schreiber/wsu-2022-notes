#include <time.h>
#include "src/main/menu/menu.h"
#include "src/framework/record/record.h"

static void _insertTest() {
    Queue **queue = malloc(sizeof(Queue*));
    queue_insert(*queue,
        (Record) {
            .artist = "Perry, Katy",
            .album = "Witness",
            .song = "Chained to the Rhythm",
            .genre = "pop",
            .length = (Duration) {.minutes = 4, .seconds = 36},
            .plays = -1,
            .rating = 6
        }
    );
    displayAllRecords(queue);
}

static void _deleteTest() {
    Queue **queue = malloc(sizeof(Queue*));
    queue_insert(*queue,
        (Record) {
            .artist = "Perry, Katy",
            .album = "Witness",
            .song = "Chained to the Rhythm",
            .genre = "pop",
            .length = (Duration) {.minutes = 4, .seconds = 36},
            .plays = -1,
            .rating = 6
        }
    );
    delete(queue, "Chained to the Rythm");
    displayAllRecords(queue);
}

static void _shuffleTest() {
    Queue **queue = malloc(sizeof(Queue*));
    loadRecords(queue);
    shuffle(queue);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    FILE *f = fopen(INPUT_FILE_DOCKER, "r");
    printf("%d", f == NULL);
    getInput();
    return 0;
}