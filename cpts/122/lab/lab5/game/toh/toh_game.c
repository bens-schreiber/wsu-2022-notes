#include "toh_game.h"

Stack **tower_initialize() {
    Stack **towers = malloc(sizeof(Stack*) * 3);
    Stack *first = stack_initialize('f');
    Stack *second = stack_initialize('\0');
    Stack *third = stack_initialize('\0');
    for (int i = 0; i < TOWER_DIAMETER; ++i) {
        stack_push(first, stack_peek(first)->data - 1);
    }
    towers[0] = first;
    towers[1] = second;
    towers[2] = third;
    return towers;
}

static void _printTower(Stack *stack) {
    Node *n = stack_peek(stack);
    for (int i = 0; i < stack->length; ++i) {
        for (int diameter = 0; diameter <= (n->data - 'a'); ++diameter) {
            printf("%c", n->data);
        }
        n = n->next;
        printf("\n");
    }
    printf("\n\n");
}

static void _display(Stack **towers) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    _printTower(towers[0]);
    _printTower(towers[1]);
    _printTower(towers[2]);
    sleep(1);
}

// ultimate destination: tower 3
void tower_play(Stack **towers, int n, int from, int to, int other) {
    if (n == 1) {
        // move to->from
        stack_pushN(towers[to], stack_pop(towers[from]));
        _display(towers);
        return;
    }
    tower_play(towers, n-1, from, other, to);

    // move to -> from
    stack_pushN(towers[to], stack_pop(towers[from]));
    _display(towers);

    tower_play(towers, n-1, other, to, from);
}