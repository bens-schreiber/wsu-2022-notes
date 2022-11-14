#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// swap a with b
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void bubbleSort(int *arr, int size)
{
    while (size--)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
            }
        }
    }
}

int count_alphas(char *string, int size)
{
    int count = 0;
    do {
        count += isalpha(*string);
    } while(*(string++)); // While the value isn't '\0', increment value
    return count;
}

int remove_whitespace(char *string, int size)
{
    int count = 0;
    char *copyPtr = string;
    do {

        // Check if whitespace
        while (*copyPtr == ' ') {

            // Increment counter
            ++count;

            // Go to the next value of the copy pointer
            ++copyPtr;
        }

    // While the value at string isn't '\0' (this can be done using the assignment operator, not ==)
    // Set the value at letters to be the value at the copyPtr.
    // copyPtr will skip all of the whitespaces and move on to the next alphanumeric value.
    // The loop sets the value at string to the copyPtr
    } while (*(string++) = *(copyPtr++)); 
    return count;
}

typedef struct node {
    int data;
    struct node *next;
} node_t;

void reverse_matrix(int rows, int columns, int matrix[rows][columns]) {

    if (rows < 2) return;

    int *rowA = matrix[0];
    int *rowB = matrix[rows - 1];

    do {
        for (int col = 0; col < columns; col++) {
            swap(&rowA[col], &rowB[col]);
        }
    } while ((rowA += columns) <= (rowB -= columns));
}

int hash_two_uint8s(unsigned char x, unsigned char y) {
    return (( x*137 ) + y) % 100;
}

int factorial(int n) {
    if (n == 1) return n;
    return n * factorial(n - 1);
}


int main(int argc, char const *argv[])
{
    printf("%d", factorial(4));
}