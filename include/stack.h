#ifndef STACK_H 
#define STACK_H

#include <stdbool.h>

typedef struct Node {
    char operation;
    struct Node *next;
} Node;

// create new Node
Node *create_node(char data);

typedef struct Stack {
    Node *head;
} Stack;

void initialize_stack(Stack *stack);
// basic operation for stack
// push, pop, isempthy, etc, maybe also display all elements

bool is_empthy(Stack *stack);

void push(Stack *stack, char data);

void pop(Stack *stack);

char top(Stack *stack);

#endif
