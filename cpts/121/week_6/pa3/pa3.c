#include "defs/defs.h"

// I would argue that the amount of entries should be put in main
// instead of in the def header, since defs acts more like a library
// of functions to read write to a specific kind of file.
#define AMOUNT_OF_ENTRIES 5

int main(int argc, char const *argv[])
{

    FILE *input = fopen("in/input.dat", "r"), *output = fopen("out/output.dat", "w");

    // Not going to make variables for every entry,
    // that would make me cry. Use array instead.
    double gpas[AMOUNT_OF_ENTRIES] = { 0 };
    int standings[AMOUNT_OF_ENTRIES] = { 0 };
    double ages[AMOUNT_OF_ENTRIES] = { 0 };

    // Again, not going to individually set each value,
    // that would make me want to quit programming. Iterate instead.
    for (int i = 0; i < AMOUNT_OF_ENTRIES; i++)
    {
        // Skip the student ID line
        read_integer(input);

        gpas[i] = read_double(input);
        standings[i] = read_integer(input);
        ages[i] = read_double(input);
    }

    // File no longer needed
    fclose(input);

    // Calculate sum of gpas
    // Ideally these function would take in an array, but
    // I am keeping the function prototype the same as the prompt wrote it as.
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
    double gpaDeviation[AMOUNT_OF_ENTRIES] = { 0 };
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

    // thanks for grading have a wonderful day

    return 0;
}
