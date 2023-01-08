#pragma once

#include<stdlib.h>
#include<stdio.h>

typedef struct Queue {
    size_t size;
    size_t capacity;
    unsigned int front;
    int* container;
} Queue;

void queue_constructor(Queue* queue, size_t capacity) {
    queue->size = 0;
    queue->front = 0;
    queue->capacity = capacity;
    queue->container = (int*)malloc(sizeof(int)*capacity);

    if(queue->container == NULL) {
        fprintf(stderr, "[ERR] queue_constructor(): Failed to allocate memory for container of queue\n");
        exit(1);
    }
}

void queue_constructor_heap(Queue** queue, size_t capacity) {
    *queue = (Queue*)malloc(sizeof(Queue));
    (*queue)->size = 0;
    (*queue)->front = 0;
    (*queue)->capacity = capacity;
    (*queue)->container = (int*)malloc(sizeof(int));

    if(*queue == NULL) {
        fprintf(stderr, "[ERR] queue_constructor(): Failed to allocate queue in heap\n");
        exit(1);
    }

    if((*queue)->container == NULL) {
        fprintf(stderr, "[ERR] queue_constructor_heap(): Failed to allocate memory for container of queue\n");
        exit(1);
    }
}

void queue_enqueue(Queue* queue, int val) {
    if(queue->size == queue->capacity) {
        fprintf(stderr, "[ERR] queue_push(): queue overflown\n");
        exit(1);
    }

    queue->container[(queue->front + queue-> size) % queue->capacity] = val;
    queue->size++;
}

void queue_dequeue(Queue* queue) {
    if(queue->size == 0) {
        fprintf(stderr, "[ERR] queue_dequeue(): queue underflown\n");
        exit(1);
    }

    queue->size--;
    queue->front = (queue->front + 1) % queue->capacity;
}

void queue_print(Queue* queue) {
    if(queue->size == 0) {
        printf("The queue is empty\n");
        return;
    }    

    printf("The contents of the queue are:\n");
    
    int i = queue->front;
    int count = 0;
    while(count < queue->size) {
        printf("%d ", queue->container[i]);

        i = (i + 1) % queue->capacity;
        count++;
    }
    

    printf("\n");
}