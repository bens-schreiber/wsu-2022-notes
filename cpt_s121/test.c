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

    // reversing something with 0 or 1 rows is as simple as this
    if (rows < 2) return;

    // we will swap index a with index b
    // rowA is the first row
    // rowB is the last row
    int *rowA = matrix[0];
    int *rowB = matrix[rows - 1];

    do {
        for (int col = 0; col < columns; col++) {
            swap(&rowA[col], &rowB[col]);
        }
    } while ((rowA += columns) <= (rowB -= columns));
}


int main(int argc, char const *argv[])
{
    const int ROWS = 2;
    const int COLS = 5;

    int arr[ROWS][COLS] = {{1,2,3,4,5}, {6,7,8,9,10}};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    reverse_matrix(ROWS, COLS, arr);

    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}