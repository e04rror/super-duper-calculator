#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

node_op *create_node(char data){
    node_op *new_node = (node_op *)malloc(sizeof(node_op));
    
    new_node->operation = data;
    new_node->next = NULL;
    return new_node;
}

void initialize_stack(stack_op *stack){
    stack->head = NULL;
}

bool is_empthy(stack_op *stack){
    return stack->head == NULL;
}

void push(stack_op *stack,char data){
    node_op *new_node = create_node(data);

    new_node->next = stack->head;
    stack->head = new_node;
}

void pop(stack_op *stack){
    if(is_empthy(stack)){
        printf("There is nothing to remove, stack is empthy!\n");
        return;
    }
    node_op *remove_head = stack->head;
    stack->head = stack->head->next;
    free(remove_head);
}

char top(stack_op *stack){
    if(is_empthy(stack)){
        printf("Stack is empthy!\n");
        return '\0';
    } 
    return stack->head->operation;
}
