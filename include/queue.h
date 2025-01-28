#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

enum data_type {
    CHAR = 1,
    DOUBLE = 2
};

typedef struct node {
    void *data;
    int data_type;
    struct node *next;
} node;

typedef struct queue_results {
    node *front, *rear;
} queue_results;

node *create_node(void *data, int d_type);

void initialize_queue(queue_results *queue);

bool is_empty(queue_results *queue);

void enqueue(queue_results *queue,void *data, int d_type);

void dequeue(queue_results *queue);

void *front(queue_results *queue);

void *rear(queue_results *queue);

#endif
