#include <stdio.h>
int main()
{
    int inputNumber = 54321;
    int numberCount = 0;
    int sum = 0;
    int lastDigit = 0;
    while (inputNumber > 0) {
        numberCount++;
        lastDigit = inputNumber % 10;
        sum += lastDigit;
        inputNumber = inputNumber / 10;
    }

    printf("%d\n", numberCount);
    printf("%d", sum);
    

    return 0;
}
