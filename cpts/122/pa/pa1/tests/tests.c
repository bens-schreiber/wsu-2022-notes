#include "tests.h"

static void awaitInput()
{
    printf("\nPress ENTER to continue!\n");
    char input = 0;
    fflush(stdin);
    getchar();
    system("clear");
}

void runTests(const int runTests, FitbitResult *result) {
    if (!runTests) {return;}

    printf("\n\navg heart: %f\n", result->computations.averageHeartRate);
    printf("max steps: %d\n", result->computations.maxStepsTaken);
    printf("poor sleep sum: %d\n", result->computations.poorSleep.sum);
    printf("poor sleep beginning: %s\n", result->computations.poorSleep.beginning);
    printf("poor sleep end: %s\n", result->computations.poorSleep.end);
    printf("total calories: %lf\n", result->computations.totalCaloriesBurned);
    printf("total distance: %lf\n", result->computations.totalDistanceWalked);
    printf("total floors: %d\n", result->computations.totalFloorsWalked);
    printf("total steps: %d\n", result->computations.totalStepsTaken);

    awaitInput();

    // Manual reading
    int index = 0;
    while (index < DATA_SIZE) {
        printf("minute: %s\n", result->cleansedData[index].minute);
        printf("calories: %lf\n", result->cleansedData[index].calories);
        printf("distance: %lf\n", result->cleansedData[index].distance);
        printf("floors: %d\n", result->cleansedData[index].floors);
        printf("heart: %d\n", result->cleansedData[index].heartRate);
        printf("steps: %d\n", result->cleansedData[index].steps);
        printf("sleep: %d\n", result->cleansedData[index].sleepLevel);
        awaitInput();
    ++index;
    }
}