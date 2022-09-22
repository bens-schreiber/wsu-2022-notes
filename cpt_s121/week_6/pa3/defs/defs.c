#include "defs.h"

double read_double(FILE *infile)
{
    double value;
    fscanf(infile, "%lf", &value);
    return value;
}

int read_integer(FILE *infile)
{
    int value;
    fscanf(infile, "%d", &value);
    return value;
}

double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
    return number1 + number2 + number3 + number4 + number5;
}

double calculate_mean(double sum, int number)
{
    return sum / number;
}

double calculate_deviation(double number, double mean)
{
    return number - mean;
}

double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
    return calculate_mean(
        pow(deviation1, 2) 
        + pow(deviation2, 2) 
        + pow(deviation3, 2) 
        + pow(deviation4, 2) 
        + pow(deviation5, 2), number);
}

double calculate_standard_deviation(double variance)
{
    return sqrt(variance);
}

// i simply will not make 5 if statements, it will negatively impact my health, hope you understand
double find_max(double number1, double number2, double number3, double number4, double number5)
{
    double nums[5] = {number1, number2, number3, number4, number5};
    double max = number1;
    for(int i = 1; i < 5; i++)
    {
        max = nums[i] > max ? nums[i] : max;
    }
    return max;
}

double find_min(double number1, double number2, double number3, double number4, double number5)
{
    double nums[5] = {number1, number2, number3, number4, number5};
    double min = nums[0];
    for(int i = 1; i < 4; i++)
    {
        min = nums[i] < min ? nums[i] : min;
    }
    return min;
}

void print_double(FILE *outfile, double number)
{
    fprintf(outfile, "%lf\n", number);
}
