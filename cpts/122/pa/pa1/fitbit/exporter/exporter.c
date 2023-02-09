#include "exporter.h"

void exportFitbitData(const FitbitResult *result, FILE *file) {
    fprintf(file, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
    fprintf(file, "Target: ,12cx7,,,,,,\nPatient,minute,calories,distance,floors,heart,steps,sleep_level");
    fprintf(file, "%lf,%lf,%d,%d,%lf,%d,%d\n", result->computations.totalCaloriesBurned, result->computations.totalDistanceWalked, result->computations.totalFloorsWalked, result->computations.totalStepsTaken, result->computations.averageHeartRate, result->computations.maxStepsTaken, result->computations.poorSleep.sum);
    fprintf(file, "%s", result->cleansedDataString);
}