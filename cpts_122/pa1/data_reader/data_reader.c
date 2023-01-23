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
    row = fgets(buffer, DATA_SIZE, file);

    // Target is two searches in
    strtok(row, ",");
    strToken = strtok(NULL, ",");
    
    strcpy(target, strToken);
}

static void _readLine(FILE *file, char buffer[DATA_SIZE], char *target, FitbitData *data) {

    // Get the raw line
    char *row;
    row = fgets(buffer, DATA_SIZE, file);

    char *strToken;

    // Check target
    // If target isn't the required target, return null
    if (strcmp(target, strtok(row, ",")) != 0) {
        data = NULL;
        return;
    }

    // MINUTES
    strToken = strtok(NULL, ",");
    for (int i = 0; i < MINUTE_SIZE; ++i) {
        data->minute[i] = strToken[i];
    }

    // CALORIES
    strToken = strtok(NULL, ",");
    data->calories = atof(strToken);

    // DISTANCE
    strToken = strtok(NULL, ",");
    data->distance = atof(strToken);

    // FLOORS
    strToken = strtok(NULL, ",");
    data->floors = atoi(strToken);

    // HEART
    strToken = strtok(NULL, ",");
    data->heartRate = atoi(strToken);

    // STEPS
    strToken = strtok(NULL, ",");
    data->steps = atoi(strToken);

    // SLEEP LEVEL
    strToken = strtok(NULL, ",");
    data->sleepLevel = (Sleep) atoi(strToken);
    
}


// TODO: deduping? what even do they want
FitbitResult *readAndComputeData(FILE *file) {

    // Find target patient
    char target[TARGET_SIZE];
    _findTarget(file, target);

    // Begin result data
    FitbitResult *result = malloc(sizeof(FitbitResult));

    // Skip the csv title desc line
    char buffer[DATA_SIZE];
    fgets(buffer, DATA_SIZE, file);

    int index = 0;
    FitbitData *data = NULL;
    while (!feof(file)) {
        // Read data
        data = &(FitbitData) {};
        _readLine(file, buffer, target, data);

        if (data == NULL) {continue;}

        // Compute data
        _computeFitbitData(data, result);

        // Store data
        result->data[index++] = *data;
    }

    return result;
}