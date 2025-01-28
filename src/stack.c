#include "stack.h"
#include <stdlib.h>

Node *create_node(char data){
    Node *new_node = (Node *)malloc(sizeof(Node));
    
    new_node->operation = data;
    new_node->next = NULL;
    return new_node;
}

void initialize_stack(Stack *stack){
    stack->head = NULL;
}

bool is_empthy(Stack *stack){
    return stack->head == NULL;
}

void push(Stack *stack,char data){
    Node *new_node = create_node(data);

    new_node->next = stack->head;
    stack->head = new_node;
}

void pop(Stack *stack){
    if(is_empthy(stack)){
        printf("There is nothing to remove, stack is empthy!\n");
        return;
    }
    Node *remove_head = stack->head;
    stack->head = stack->head->next;
    free(remove_head);
}

char top(Stack *stack){
    if(is_empthy(stack)){
        printf("Stack is empthy!\n");
        return '\0';
    } 
    return stack->head->data;
}
    
