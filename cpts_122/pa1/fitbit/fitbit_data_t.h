#pragma once
#include "../fitbit/fitbit_t.h"

#include "../consts.h"

typedef struct {
    char beginning[9];
    char end[9]; 
    unsigned int range;
    unsigned int sum;
} PoorSleep;

typedef struct {
    double totalCaloriesBurned;
    double totalDistanceWalked;
    unsigned int totalFloorsWalked;
    unsigned int totalStepsTaken;
    float averageHeartRate;
    unsigned int maxStepsTaken;
    PoorSleep poorSleep;

} FitbitComputation;

typedef struct {
    FitbitData cleansedData[DATA_SIZE];
    char cleansedDataString[0xFFFF]; // arbitrarily large
    FitbitComputation computations;

} FitbitResult;