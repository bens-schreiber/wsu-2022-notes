#include "framework/stack.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    Stack* stack = stack_initialize('a');
    stack_push(stack, 'b');
    stack_push(stack, 'c');
    stack_push(stack, 'd');
    free(stack_pop(stack));
    free(stack_pop(stack));
    free(stack_pop(stack));
    printf("%c", stack_peek(stack)->data);
    stack_destruct(stack);
    return 0;
}
