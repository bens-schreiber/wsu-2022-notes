#include <stdio.h>
#include <string.h>
char *myStrncpy (char *destination, const char *source, int n) {
    if (n == 0) {return destination;}
    *destination = *source;
    if (*source == '\0') { return myStrncpy(destination + 1, source, n - 1) - 1; }
    return myStrncpy(destination + 1, source + 1, n - 1) - 1;
}

// assuming destination points to the beginning of a string
// this returns the pointer of where the string was appended, not the beginning.
// unsure how to get the beginning when strlen is required in this case, at least recursively
char *myStrncat (char *destination, const char *source, int n) {
    if (!n || !*source) {return destination;}
    destination = &destination[strlen(destination)];
    *destination = *source;
    *(destination + 1) = '\0';
    return myStrncat(destination + 1, source + 1, n - 1) - 1;
}

int recStrLen(char *str) {
    return !*str ? 0 : recStrLen(str + 1) + 1;
}

int main(int argc, char const *argv[])
{
    char source[] = "test";
    char destination[15] = "test";
    myStrncat(destination, source, 3);
    printf("%s", destination);
    return 0;
}
