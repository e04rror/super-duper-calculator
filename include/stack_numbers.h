#ifndef STACK_NUM_H 
#define STACK_NUM_H

#include <stdbool.h>

typedef struct node_numbers {
    double data;
    struct node_numbers *next;
} node_num;

// create new Node
node_num *create_nn(double data);

typedef struct {
    node_num *head;
} stack_num;

void init_stack_num(stack_num *stack);
// basic operation for stack
// push, pop, isempthy, etc, maybe also display all elements

bool is_emp(stack_num *stack);

void push_num(stack_num *stack, double data);

void pop_num(stack_num *stack);

double top_num(stack_num *stack);

#endif
