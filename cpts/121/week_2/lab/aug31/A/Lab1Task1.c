/* 
    Name: Benjamin Schreiber
    Date: 8/29/22
    Class: CPTS 121

    Description: 
*/
 
#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings
 
#include <stdio.h>
#include <math.h>
 
int main(void)
{
       int number1_int = 0, number2_int = 0; 
       double number1_float = 0.0, number2_float = 0.0; 
 
       printf("Enter two integer values: "); 
       scanf("%d%d", &number1_int, &number2_int);
 
       printf("Enter two floating-point values: ");
       scanf("%lf%lf", &number1_float, &number2_float); 
 
       // place all code for the subtasks/operations below here
 
        printf("\n\n\n");

        printf("%d\n", number1_int + number2_int);

        printf("%f\n", number1_float - number2_float);

        printf("%f\n", number1_int * number1_float);

        printf("%d\n", number1_int/number2_int);

        printf("%f\n", number1_int/number2_int);

        printf("%f\n", ((float) number1_int) / number2_int);

        printf("%d\n", (int)number1_float % (int)number2_float);

        printf("%d\n", (number1_int % 2) == 1);
        printf("%d\n", (number2_int % 2) == 1);
 
       return 0;
}
