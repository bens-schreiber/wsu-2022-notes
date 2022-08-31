/* 
    Name: Benjamin Schreiber
    Date: 8/29/22
    Class: CPTS 121

    Description: 
*/
 
#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings
 
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int v;
    int r;

    printf("Enter the voltage (V) \n");
    scanf("%d", &v);

    printf("Enter the Resistance (R) \n");
    scanf("%d", &r);

    printf("%d", (v << 2) / r);

    return 0;
}
