#include "stack_numbers.h"
#include <stdlib.h>
#include <stdio.h>

node_num *create_nn(double data){
    node_num *new_node = (node_num *)malloc(sizeof(node_num));
    
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void init_stack_num(stack_num *stack){
    stack->head = NULL;
}

bool is_emp(stack_num *stack){
    return stack->head == NULL;
}

void push_num(stack_num *stack, double data){
    node_num *new_node = create_nn(data);

    new_node->next = stack->head;
    stack->head = new_node;
}

void pop_num(stack_num *stack){
    if(is_emp(stack)){
        printf("There is nothing to remove, stack is empthy!\n");
        return;
    }
    node_num *remove_head = stack->head;
    stack->head = stack->head->next;
    free(remove_head);
}

double top_num(stack_num *stack){
    if(is_emp(stack)){
        printf("Stack is empthy!\n");
        return '\0';
    } 
    return stack->head->data;
}
