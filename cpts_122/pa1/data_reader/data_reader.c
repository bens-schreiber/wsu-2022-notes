#include "data_reader.h"

static void _computeFitbitData(const FitbitData *data, FitbitResult *fitbitResult) {
    static PoorSleep sleep = {0};
    FitbitComputation *v = &fitbitResult->computations;

    // Totals
    v->totalCaloriesBurned += data->calories;
    v->totalDistanceWalked += data->distance;
    v->totalFloorsWalked += data->floors;
    v->totalStepsTaken += data->steps;

    // Max steps
    v->maxStepsTaken = data->steps > v->maxStepsTaken ? data->steps : v->maxStepsTaken;

    // Sleep
    if (data->sleepLevel < 1) {
        sleep = (PoorSleep) {.beginning = '\0', .end = '\0', 0};
        return;
    }
    
    // Set sleep beginning
    if (!sleep.beginning) {
        strcpy(sleep.beginning, data->minute);
    }
    
    // Set sleep end
    strcpy(sleep.end, data->minute);

    // Increment sleep
    ++sleep.range;
    sleep.sum += data->sleepLevel;

    // Replace poor sleep max if greater
    v->poorSleep = sleep.sum > v->poorSleep.sum ? sleep : v->poorSleep;

}

static void _setTarget(FILE *file, char target[TARGET_SIZE]) {
    char *row;
    char *strToken;
    row = fgets(row, 0xFF, file);
    for (int i = 0; i < TARGET_DEPTH + 1; ++i) {
        strToken = strtok(row, ",");
    }
    strcpy(target, strToken);
}


// TODO: deduping? what even do they want
const FitbitResult readAndComputeData(FILE *file) {

    // Find target patient
    char target[TARGET_SIZE];
    _setTarget(file, target);

    char buffer[DATA_SIZE];
    char *row;
    char *strToken;
    while (!feof(file)) {
        row = fgets(buffer, DATA_SIZE, file);
        while((strToken = strtok(row, ",")) && strToken) {

        }
    }
}