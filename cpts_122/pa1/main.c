#include "tests/tests.h"
#include "consts.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fin = fopen(CSV_IN_LOCATION, "rw");
    FitbitResult *result = readAndComputeFitbitData(fin);

    FILE *fout = fopen(CSV_OUT_LOCATION, "w");
    exportFitbitData(result, fout);

    // TESTS
    runTests(RUN_TESTS, result);

    free(result);
    fclose(fin);
    fclose(fout);
    return 0;
}
