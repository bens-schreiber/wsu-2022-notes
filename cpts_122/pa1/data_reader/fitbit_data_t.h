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
    int totalFloorsWalked;
    int totalStepsTaken;
    float averageHeartRate;
    unsigned int maxStepsTaken;
    PoorSleep poorSleep;

} FitbitComputation;

typedef struct {
    FitbitData data[DATA_SIZE];
    FitbitComputation computations;

} FitbitResult;