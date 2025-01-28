#include "queue.h"
#include <stdlib.h>

node *create_node(void *data, int d_type){
    node *new_node = (node *)malloc(sizeof(node));

    new_node->data = data;
    new_node->data_type = d_type;
    new_node->next = NULL;
    return new_node;
}

void initialize_queue(queue_results *queue){
    queue->front = NULL;
    queue->rear = NULL;
}
bool is_empty(queue_results *queue){
    return (queue->front == NULL) && (queue->rear == NULL);
}

void enqueue(queue_results *queue, void *data, int d_type){
    node *new_node = create_node(data, d_type);

    if(is_empty(queue)){
        queue->front = queue->rear = new_node;
        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;
}

void dequeue(queue_results *queue){
    if(is_empty(queue)){
       printf("There is no removal; The queue is empthy!\n");
       return ;
    }

    node *temp = queue->front;
    queue->front = queue->front->next;
    if(queue->front == NULL){ queue->rear = NULL;}
    free(temp);
}

void *front(queue_resutls *queue){
    if(is_empty(queue)){
        printf("The queue is empthy!\n");
        return NULL;
    }
    return queue->front->data;
}

void *rear(queue_results *queue){
    if(is_empty(queue)){
        printf("The queue is empthy!\n");
        return;
    }
    return queue->rear->data;
}
