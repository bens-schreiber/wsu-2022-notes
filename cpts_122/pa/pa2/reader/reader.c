#include "reader.h"

static void _readLine(Record *record, FILE *file, char buffer[0xFFF]) {
    char *line;
    line = fgets(buffer, 0xFFF, file);

    // Check for "'s
    if (line[0] == '\"') {
        line += 1;
        memcpy(record->artist, strtok(line, "\""), STRING_SIZE);
        line += 2;
    } else {
        memcpy(record->artist, strtok(line, ","), STRING_SIZE);
    }

    memcpy(record->album, strtok(NULL, ","), STRING_SIZE);
    memcpy(record->song, strtok(NULL, ","), STRING_SIZE);
    memcpy(record->genre, strtok(NULL, ","), STRING_SIZE);
    record->length = (Duration) {};
    record->length.minutes = atoi(strtok(NULL, ":"));
    record->length.seconds = atoi(strtok(NULL, ","));
    record->plays = atoi(strtok(NULL, ","));
    record->rating = atoi(strtok(NULL, ",")); 
}

QueueRecord *readRecordsFromFile(FILE *input) {
    char buffer[0xFFF];
    Record record = {};
    _readLine(&record, input, buffer);
    QueueRecord *queue =  new_QueueRecord(record);

    while(!feof(input)) {
        _readLine(&record, input, buffer);
        tailInsert_QueueRecord(queue, record);
    }

    return queue;
}