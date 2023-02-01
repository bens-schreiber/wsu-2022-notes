#include "reader.h"

static void _readLine(Record *record, FILE *file) {
    static char buffer[0xFFF] = {};
    char *line;
    line = fgets(buffer, 0xFFF, file);

    memcpy(record->artist, strtok(line, ","), STRING_SIZE);
    memcpy(record->album, strtok(NULL, ","), STRING_SIZE);
    memcpy(record->song, strtok(NULL, ","), STRING_SIZE);
    memcpy(record->genre, strtok(NULL, ","), STRING_SIZE);
    record->length = (Duration) {.minutes = atoi(strtok(NULL, ":")), .seconds = atoi(strtok(NULL, ","))};
    record->plays = atoi(strtok(NULL, ","));
    record->rating = atoi(strtok(NULL, ",")); 
}

QueueRecord *readRecordsFromFile(FILE *input) {
    Record record = {};
    _readLine(&record, input);
    QueueRecord *queue = new_QueueRecord(record);

    while(!feof(input)) {
        _readLine(&record, input);
        tailInsert_QueueRecord(queue, record);
    }

    return queue;
}