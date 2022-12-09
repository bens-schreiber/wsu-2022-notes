#include <stdio.h>
#include <string.h>
#include <math.h>

char *my_str_n_cat(char *src, char *dest, int n) {
    if (!n || !*src || !*dest) return dest;
    *dest = *src;
    return my_str_n_cat(src + 1, dest + 1, n - 1) - 1;
}

int bin_search(int *arr, int size, int target) {
    if (size == 1) return arr[0] == target ? arr[0] : 0;
    if (size == 2) return arr[0] == target ? arr[0] : bin_search(arr + 1, size - 1, target);
    if (target == arr[size/2]) return arr[size/2];
    if (target > arr[size/2]) return bin_search(arr + size/2 + (size % 2 != 0), size/2, target);
    return bin_search(arr, size/2, target);
}

void bubble_sort(char **arr, int s) {
    if (s == 1) return;
    for (char i = 0; i < s - 1; ++i) {
        if (strcmp(arr[i], arr[i+1]) > 0) {
            char *temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    return bubble_sort(arr, s - 1);
}

int is_palindrome(char *str, int s) {
    if (s == 0 || s == 1) return 1;
    if (s == 2) return str[0] == str[1];
    if (str[0] == str[s-1]) return is_palindrome(str+1,s-2);
    return 0;
}

unsigned int sum_primes(unsigned int n) {
    if (n == 3) return 3 + 2;
    if (n % 2 == 0 ) return sum_primes(n - 1);
    if (n % 3 == 0) return sum_primes(n - 1);
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) return sum_primes(n - 1);
    }
    return n + sum_primes(n - 1);
}

typedef struct {
    int num_occurences;
    double frequency;
    char character;
} Occurence;

Occurence maximum_occurences(char *str) {
    // 'A' == 65
    // 'z' == 122
    // therefore, size is 57
    // add 1 for whitespace
    int map[58] = {};
    memset(map, 0, sizeof(int) * 58);
    Occurence highest = {.num_occurences = 0, .frequency = 0, .character = str[0]};
    int strSize = 0;
    while (*str != '\0') {
        int key = *str == ' ' ? 57 : *str - 'A';
        map[key] += 1;
        if (map[key] > highest.num_occurences) {
            highest.character = *str;
            highest.num_occurences = map[key];
        }
        ++str;
        ++strSize;
    }
    highest.frequency = highest.num_occurences / strSize;
    return highest;
}

int main(int argc, char const *argv[])
{

    // STRING REPLACE
    char str[] = "hello";
    char dest[] = "abcde";
    // (original string, string to copy to, amount to copy from left onward)
    printf("string replace: %s\n", my_str_n_cat(str, dest, 3));

    // BIN SEARCH
    int arr[] = {1,2,3,4,5,6};
    // (list, size, target)
    printf("binary search: %d\n", bin_search(arr, 6, 1));

    // BUBBLE SORT
    char *strs[] = {"z", "e", "w", "a", "d"};
    // (list, num of strs)
    bubble_sort(strs, 5);
    printf("bubble sort: %s", strs[0]);
    for (int i = 1; i < 5; ++i) {
        printf(" %s", strs[i]);
    }
    printf("\n");

    //PALINDROME
    // (word, num of chars)
    printf("is palindrome: %d\n", is_palindrome("kayak", 5));

    // PRIME SUM
    // (n)
    printf("sum primes: %d\n", sum_primes(17));

    // OCCURENCES
    // (string)
    Occurence o = maximum_occurences("test string");
    printf("max occurences: %c %d %lf", o.character, o.num_occurences, o.frequency);
    
    return 0;
}
