#include <stdio.h>
#include <stdlib.h>

// swap a with b
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void bubbleSort(int *arr, int size) {
    while (size--) {
        for (int i = 0; i < size; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i+1]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[4] = {90,-10,1,1};
    bubbleSort(arr, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

