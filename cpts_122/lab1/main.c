#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

char *rev_str(char *str, int length) {
    if (length <= 1) {return str;}
    swap(str, str + length - 2);
    return rev_str(str + 1, length - 2) - 1;
}

char *strTok(char *str, const char find) {

    // For consecutive calls, when str is null used the cached spot.
    static char *cachedSpot = NULL;
    if (str == NULL) {
        str = cachedSpot;
    }

    // Save the original beginning of string spot in this variable
    char *original = str;

    while (*str && *str != find) {
        ++str;
    }

    // Place the delimiter
    *str = '\0';

    // Cache the pointer for consecutive calls
    cachedSpot = str + 1;

    return original;
}

void placeIntoBuffer(char *str, char buffer[0xFFF], int *index) {
    while (*str) {
        buffer[*index] = *str;
        *index = *index + 1;
        ++str;
    }
}

void sortStrings(char *str1, char *str2, char buffer[0xFFF]) {
    int index = 0;

    // Str1 larger
    if (strcmp(str1, str2) > 1) {
        placeIntoBuffer(str1, buffer, &index);
        placeIntoBuffer(str2, buffer, &index);
        return;
    }

    // Str2 larger
    placeIntoBuffer(str2, buffer, &index);
    placeIntoBuffer(str1, buffer, &index);

    buffer[index + 1] = '\0';
}

char *sortStringsDynamic(char *str1, char *str2) {
    char *buffer = malloc(sizeof(char) * 0xFFF);
    sortStrings(str1, str2, buffer);
    return buffer;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
