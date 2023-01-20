#include "./data_reader/data_reader.h"
#include "consts.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *f = fopen(CSV_LOCATION, "rw");
    readAndComputeData(f);
    return 0;
}
