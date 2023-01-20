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
    if (!sleep.beginning[0]) {
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

static void _findTarget(FILE *file, char target[TARGET_SIZE]) {
    char buffer[DATA_SIZE];
    char *row;
    char *strToken;
    row = fgets(buffer, 0xFF, file);

    // Target is two searches in
    strtok(row, ",");
    strToken = strtok(NULL, ",");
    
    strcpy(target, strToken);
}


// TODO: deduping? what even do they want
const FitbitResult readAndComputeData(FILE *file) {

    // Find target patient
    char target[TARGET_SIZE];
    _findTarget(file, target);

    // Begin result data
    FitbitResult result = (FitbitResult) {};

    // Get the entire files data
    char buffer[DATA_SIZE];
    while (!feof(file)) {
        
    }

    return result;
}