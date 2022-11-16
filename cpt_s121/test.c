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
    } while ((*(string++) = *(copyPtr++))); 
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

// WARNING: funny linear solution :D
// For fun, lets assume that the length of the string is unknown
// The str given also needs to be modifiable. (char[])
// [str] - the original string
// [ptr1] - pointer that increments left to right
// [ptr2] - pointer that increments from right to left
// [ptr3] - pointer that finds the end of the string
// yes, you would call this like rec_reverse_string(str, str, str, str)
char *recursively_reverse_string(char *str, char *ptr1, char *ptr2, char *ptr3) {
    if (*(ptr3 + 1) != '\0') {
        return recursively_reverse_string(str, ptr1, ptr2 + 1, ptr3 + 1);
    }

    if (ptr1 == ptr2) {
        return str;
    }

    // swap
    char tmp = *ptr2;
    *ptr2 = *ptr1;
    *ptr1 = tmp;
    
    if (ptr1 + 1 == ptr2) {
        return str;
    }

    return recursively_reverse_string(str, ptr1 + 1, ptr2 - 1, ptr3);
}

void recursive_string_copy(const char *source, char *destination) {
    if (*source == '\0') {
        *destination = *source;
        return;
    }
    *destination = *source;
    recursive_string_copy(source + 1, destination + 1);
}

char *rev_str(char *str) {

    int i = 0;
    int strLen;
    int midpoint;
    while (++i) {
        midpoint = i;
        if (str[2 * i] == '\0') {
            strLen = 2 * i - 1;
            break;
        }

        if (str[2 * i + 1] == '\0') {
            strLen = 2 * i + 1 - 1;
            break;
        }
    }

    for (int i = 0; i < midpoint; i++) {
        char tmp = str[i];
        str[i] = str[strLen - i];
        str[strLen - i] = tmp;
    }
    
    return str;

}


int main(int argc, char const *argv[])
{
    char str[] = "abc";
    // char str2[7] = {};
    // recursive_string_copy(str, str2);
    printf("%s", rev_str(str));
}