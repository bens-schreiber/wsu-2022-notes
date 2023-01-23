#include "tests/tests.h"
#include "consts.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *f = fopen(CSV_LOCATION, "rw");
    FitbitResult *result = readAndComputeData(f);

    // TESTS
    runTests(RUN_TESTS, result);

    free(result);
    return 0;
}
