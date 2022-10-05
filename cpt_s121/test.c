#include <stdio.h>
#include <math.h>

// use the 6k +- 1 formula to find prime numbers
int isPrime(int num)
{
    if (num == 2 || num == 3)
    {
        return 1; // prime
    }

    if (num % 2 == 0 || num % 3 == 0)
    {
        return 0; // not prime
    }

    // 4 has already been covered by num % 2, start with 5
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return 0; // not prime
        }
    }

    return 1; // prime
}

int main(int argc, char const *argv[])
{
    int input;
    printf("Enter an integer number: ");
    scanf("%d", &input);
    
    int res = isPrime(input);
    if (res) {
        printf("prime");
    } else {
        printf("not prime");
    }

    return 0;
}
