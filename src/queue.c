//0x5dfc32625eb0
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

/*node_q *create_node_q(void *data, int d_type){
    node_q *new_node = (node_q *)malloc(sizeof(node_q));

    new_node->data = data;
    new_node->data_type = d_type;
    new_node->next = NULL;
    return new_node;
}*/

void initialize_queue(queue *q){
    q->front = NULL;
    q->rear = NULL;
}
bool is_empty(queue *q){
    return (q->front == NULL) && (q->rear == NULL);
}

void enqueue_double(queue *q, double data){
    node_q *new_node = (node_q *)malloc(sizeof(node_q));

    new_node->data.num = data;
    new_node->type = DOUBLE;
    new_node->next = NULL;

    if(is_empty(q)){
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
}

void enqueue_char(queue *q, char op){
    node_q *new_node = (node_q *) malloc(sizeof(node_q));

    new_node->data.op = op;
    new_node->type = CHAR;
    new_node->next = NULL;

    if(is_empty(q)){
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

void dequeue(queue *q){
    if(is_empty(q)){
       printf("There is no removal; The queue is empthy!\n");
       return ;
    }

    node_q *temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL){ q->rear = NULL;}
    free(temp);
}

node_q *get_front(queue *q){
    if(is_empty(q)){
        printf("The queue is empthy!\n");
        return NULL;
    }
    return q->front;
}

/*node_q rear(queue *q){
    if(is_empty(q)){
        printf("The queue is empthy!\n");
        return NULL;
    }
    return q->rear;
}*/
