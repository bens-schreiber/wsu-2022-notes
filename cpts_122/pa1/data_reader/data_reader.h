#include "fitbit_data_t.h"
#include <stdlib.h>
#include <stdio.h>

static _computeFitbitData(const FitbitData *data);

const FitbitResult readAndComputeData(FILE *file);