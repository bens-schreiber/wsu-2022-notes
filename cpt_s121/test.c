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

int main(int argc, char const *argv[])
{

    // initialize values
    node_t *head = malloc(sizeof(node_t));
    node_t *iterator = head;
    for (char i = 1; i < 5; i++) {
        iterator->next = malloc(sizeof(node_t));
        iterator = iterator->next;
        iterator->data = i;
    }

    iterator = head;

    do {
        printf("%d", iterator->data);
    } while (iterator = iterator->next);


    return 0;
}