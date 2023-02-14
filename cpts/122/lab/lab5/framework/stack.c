#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack *stack_initialize(char data) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    stack->head = node;
    stack->length = 1;
    return stack;
}

Node *stack_pop(Stack *stack) {
    Node *n = stack->head;
    stack->head = n->next;
    stack->length--;
    return n;
}

Node *stack_peek(Stack *stack) {
    return stack->head;
}

Node *stack_push(Stack *stack, char data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = stack->head;
    stack->head = node;
    stack->length++;
    return node;
}

unsigned char stack_isEmpty(Stack *stack) {
    return stack->length == 0;
}

void stack_destruct(Stack *stack) {
    while (!stack_isEmpty(stack)) {
        free(stack_pop(stack));
    }
    free(stack);
}