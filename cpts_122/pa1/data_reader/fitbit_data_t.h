#include "../fitbit/fitbit_t.h"
#include "../consts.h"
typedef struct {
    const FitbitData data[DATA_SIZE];
    FitbitComputation computations;

} FitbitResult;

typedef struct {
    char beginning[9];
    char end[9];
    unsigned int range;
    unsigned int sum;
} PoorSleep;

typedef struct {
    unsigned int totalCaloriesBurned, totalDistanceWalked, totalFloorsWalked, totalStepsTaken;
    float averageHeartRate;
    unsigned int maxStepsTaken;
    PoorSleep poorSleep;

} FitbitComputation;