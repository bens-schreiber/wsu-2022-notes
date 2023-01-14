#include "data_reader.h"

static _computeFitbitData(const FitbitData *data, FitbitResult *fitbitResult) {
    FitbitComputation *currMax = &fitbitResult->computations;
    currMax->maxCaloriesBurned = data->calories > currMax->maxCaloriesBurned ? data->calories : currMax->maxCaloriesBurned;
    currMax->maxCaloriesBurned = data->calories > currMax->maxDistanceWalked ? data->distance : currMax->maxDistanceWalked;
}

const FitbitResult readAndComputeData(FILE *file) {

}