#include "log.h"

int getIntInput() {
    int input = 0;
    printf("\nEnter a value: ");
    scanf("%d", &input);
    return input;
}

void getInput() {
    printf("\nPress ENTER to continue!\n");
    char input = 0;
    fflush(stdin);
    getchar();
}

int displayOption(const char *prompt) {
    printf("%s", prompt);
    int input = 0;
    scanf("%d", &input);
    return input;
}

void clear() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void getStrInput(const char *prompt, char *str) {
    printf("%s: ", prompt);
    fflush(stdin);
    fgets(str, STRING_SIZE, stdin);
    str[strcspn(str, "\n")] = 0;
}
