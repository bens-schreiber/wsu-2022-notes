#include "framework/stack.h"
#include <stdio.h>
static int test_push(Stack *stack) {
    Node *n = stack_push(stack, 't');
    if (n == stack->head) {
        printf("passed push\n");
        return 1;
    }
    printf("failed push\n");
    return 0;
}

static int test_peek(Stack *stack) {
    if (stack_peek(stack) == stack->head) {
        printf("passed peek\n");
        return 1;
    }
    printf("failed peek\n");
    return 0;
}

static int test_isEmpty(Stack *stack) {
    if (stack_isEmpty(stack) && stack->length == 0) {
       printf("passed isEmpty\n");
       return 1;
    }
    printf("failed isEmpty\n");
    return 0;
}

static int test_pop(Stack *stack) {
    Node *top = stack_peek(stack);
    if (stack_pop(stack) == top && stack_peek(stack) != top) {
       printf("passed pop\n");
       return 1;
    }
    printf("failed pop\n");
    return 0;
}

int main(int argc, char const *argv[])
{
    Stack* stack = stack_initialize('a');
    test_pop(stack);
    test_isEmpty(stack);
    test_push(stack);
    test_peek(stack);
    stack_destruct(stack);
    return 0;
}
