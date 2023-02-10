#pragma once
#include <unistd.h>
#include "src/framework/log/log.h"
#include "src/framework/record/record.h"
#include "src/framework/file/reader/reader.h"

// Load all of the records into a queue
void loadRecords(Queue **queue);

void store();

// Display all records loaded
void displayAllRecords(Queue **queue);

// Display all records associated with an artist
void displayAllArtistRecords(Queue **queue, const char *artist);

void edit(Queue **queue, const char *artist);

void rate(Queue **queue, const char *song);

void play(Queue **queue);
