#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef enum {
    CHAR = 1,
    DOUBLE = 2
} data_type;

typedef struct node {
    union {
        double num;
        char op;
    }data;
    data_type type;
    struct node *next;
} node_q;

typedef struct queue {
    node_q *front, *rear;
} queue;

//node_q *create_node_q(void *data, int d_type);

void initialize_queue(queue *q);

bool is_empty(queue *q);

void enqueue_double(queue *q, double data);
void enqueue_char(queue *q, char op);

void dequeue(queue *q);

node_q *get_front(queue *q);

// for now, i don't need it
//node_q rear(queue *q);

#endif
