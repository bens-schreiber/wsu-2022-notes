#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int loadCount = 4;
    char ellipsis[3] = "   ";
    while (loadCount--) {
        printf("BENJAMIN SCHREIBER\n");
        printf("%s%s %d\n", "LOADING", ellipsis, loadCount);

        // who needs string library functions when you're awesome
        ellipsis[abs(loadCount - 3)] = '.';
    }


    return 0;
}
