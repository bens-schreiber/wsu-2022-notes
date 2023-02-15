#pragma once
typedef struct Node Node;
struct Node {
    Node *next;
    char data;
};

typedef struct {
    Node *head;
    unsigned int length;
} Stack;

Stack *stack_initialize(char data);

Node *stack_pop(Stack *stack);

Node *stack_peek(Stack *stack);

Node *stack_push(Stack *stack, char data);

Node *stack_pushN(Stack *stack, Node *node);

unsigned char stack_isEmpty(Stack *stack);

void stack_destruct(Stack *stack);