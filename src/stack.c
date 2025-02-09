#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

node_stack *create_char(char data){
    node_stack *new_node = (node_stack *)malloc(sizeof(node_stack));
    
    new_node->data.op = data;
    new_node->type = CHAR_ST;
    new_node->next = NULL;
    return new_node;
}

node_stack *create_double(double data){
    node_stack *new_node = (node_stack *)malloc(sizeof(node_stack));
    new_node->data.num = data;
    new_node->type = DOUBLE_ST;
    new_node->next = NULL;
    return new_node;
}

void initialize_stack(stack *s){
    s->head = NULL;
}

bool is_empthy(stack *s){
    return s->head == NULL;
}

void push_char(stack *s, char data){
    node_stack *new_node = create_char(data);

    new_node->next = s->head;
    s->head = new_node;
}

void push_double(stack *s, double data){
    node_stack *new_node = create_double(data);

    new_node->next = s->head;
    s->head = new_node;
}

void pop(stack *s){
    if(is_empthy(s)){
        printf("There is nothing to remove, stack is empthy!\n");
        return;
    }
    node_stack *remove_head = s->head;
    s->head = s->head->next;
    free(remove_head);
}

char top_char(stack *s){
    if(is_empthy(s)){
        printf("Stack is empthy!\n");
        return '\0';
    } 
    return s->head->data.op;
}

double top_double(stack *s){
    if(is_empthy(s)){
        printf("Stack is empty!\n");
        return 0;
    }
    return s->head->data.num;
}
