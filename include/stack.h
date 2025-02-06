#ifndef STACK_H 
#define STACK_H

#include <stdbool.h>

typedef enum { DOUBLE_ST = 1, CHAR_ST = 2}data_type_st; 

typedef struct Node {
    union {
        double num;
        char op;
    } data;
    data_type_st type;
    struct Node *next;
} node_stack;

// create new Node
node_stack *create_char(char data);
node_stack *create_double(double data);

typedef struct stack_op {
    node_stack *head;
} stack;

void initialize_stack(stack *s);
// basic operation for stack
// push, pop, isempthy, etc, maybe also display all elements

bool is_empthy(stack *s);

void push_char(stack *s, char data);
void push_double(stack *s, double data);

void pop(stack *s);

char top_char(stack *s);
double top_double(stack *s);

#endif
