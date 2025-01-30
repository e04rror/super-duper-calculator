#ifndef STACK_H 
#define STACK_H

#include <stdbool.h>

typedef struct Node {
    char operation;
    struct Node *next;
} node_op;

// create new Node
node_op *create_node(char data);

typedef struct stack_op {
    node_op *head;
} stack_op;

void initialize_stack(stack_op *stack);
// basic operation for stack
// push, pop, isempthy, etc, maybe also display all elements

bool is_empthy(stack_op *stack);

void push(stack_op *stack, char data);

void pop(stack_op *stack);

char top(stack_op *stack);

#endif
