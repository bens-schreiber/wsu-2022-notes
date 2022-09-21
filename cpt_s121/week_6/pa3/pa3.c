#include "defs/defs.h"
#define EMPTY         \
    {                 \
        0, 0, 0, 0, 0 \
    }
#define AMOUNT_OF_ENTRIES 5

int main(int argc, char const *argv[])
{

    FILE *input = fopen("in/input.dat", "r"), *output = fopen("out/output.dat", "w");

    double gpas[AMOUNT_OF_ENTRIES] = EMPTY;
    int standings[AMOUNT_OF_ENTRIES] = EMPTY;
    double ages[AMOUNT_OF_ENTRIES] = EMPTY;

    // Initialize the arrays
    for (int i = 0; i < AMOUNT_OF_ENTRIES; i++)
    {
        // Skip line
        read_integer(input);

        gpas[i] = read_double(input);
        standings[i] = read_integer(input);
        ages[i] = read_double(input);
    }

    // File no longer needed
    fclose(input);

    // Calculate sum of gpas
    double gpaSum = calculate_sum(
        gpas[0],
        gpas[1],
        gpas[2],
        gpas[3],
        gpas[4]);

    // Calculate sum of standings
    double standingSum = calculate_sum(
        standings[0],
        standings[1],
        standings[2],
        standings[3],
        standings[4]);

    // Calculate sum of ages
    double ageSum = calculate_sum(
        ages[0],
        ages[1],
        ages[2],
        ages[3],
        ages[4]);

    // Calculate mean of gpas
    print_double(
        output,
        calculate_mean(
            gpaSum,
            AMOUNT_OF_ENTRIES));

    // Calculate mean of standings
    print_double(
        output,
        calculate_mean(
            standingSum,
            AMOUNT_OF_ENTRIES));

    // Calculate mean of ages
    print_double(
        output,
        calculate_mean(
            ageSum,
            AMOUNT_OF_ENTRIES));

    // Line break
    fprintf(output, "\n\n");

    // Calculate deviation of gpas
    double gpaDeviation[AMOUNT_OF_ENTRIES] = EMPTY;
    for (int i = 0; i < AMOUNT_OF_ENTRIES; i++)
    {
        gpaDeviation[i] =
            calculate_deviation(
                gpas[i],
                calculate_mean(gpaSum, AMOUNT_OF_ENTRIES));
    }

    // Calculate variance, print std deviation
    print_double(
        output,
        calculate_standard_deviation(
            calculate_variance(
                gpaDeviation[0],
                gpaDeviation[1],
                gpaDeviation[2],
                gpaDeviation[3],
                gpaDeviation[4],
                AMOUNT_OF_ENTRIES)));

    // Line break
    fprintf(output, "\n\n");

    // Print the min gpa
    print_double(
        output,
        find_min(gpas[0], gpas[1], gpas[2], gpas[3], gpas[4]));

    // Print max gpa
    print_double(
        output,
        find_max(gpas[0], gpas[1], gpas[2], gpas[3], gpas[4]));

    fclose(output);

    return 0;
}
