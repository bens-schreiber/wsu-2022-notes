#include "../fitbit/fitbit_t.h"
#include "../consts.h"
typedef struct {
    const FitbitData data[DATA_SIZE];
    FitbitComputation computations;

} FitbitResult;

typedef struct {
    unsigned int maxCaloriesBurned;
    unsigned int maxDistanceWalked;
    unsigned int maxFloorsWalked;
    unsigned int maxStepsWalked;
    double averageHeartrate;
    unsigned int maxStepsTaken;
    unsigned int maxPoorSleep;
} FitbitComputation;