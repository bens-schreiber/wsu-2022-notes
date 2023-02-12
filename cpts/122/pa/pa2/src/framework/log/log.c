#include "log.h"

int getIntInput(const char *prompt, int min, int max) {
    int input = -1;
    while (input < min || input > max ) {
        printf("%s", prompt);
        printf("\n%s", "Enter a value: ");
        fflush(stdout);
        scanf("%d", &input);
        clear();
    }
    return input;
}

void getInput() {
    printf("\nPress ENTER to continue!\n");
    char input = 0;
    fflush(stdout);
    fflush(stdin);
    getchar();
}

int displayOption(const char *prompt) {
    printf("%s", prompt);
    int input = 0;
    fflush(stdout);
    scanf("%d", &input);
    return input;
}

void clear() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

char *getStrInput(const char *prompt, char *str) {
    printf("%s: ", prompt);
    fflush(stdin);
    fflush(stdout);
    fgets(str, STRING_SIZE, stdin);
    str[strcspn(str, "\n")] = 0;
    return str;
}
