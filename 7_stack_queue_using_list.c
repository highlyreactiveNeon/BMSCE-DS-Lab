#include<stdio.h>
#include"list.h"

typedef struct Stack {
    int head;
    List* container;
} Stack;

void stack_initialize(Stack* vec) {
    vec->head = 0;
    list_constructor_heap(&(vec->container));
}

void stack_push(Stack* vec, int val) {
    list_push_front(vec->container, val);
    vec->head++;
}

void stack_pop(Stack* vec) {
    if(vec->head == 0){
        printf("Stack Underflow\n");
        return;
    }

    list_pop_front(vec->container);
    vec->head--;
}

typedef struct Queue {
    int head;
    List* container;
} Queue;

void queue_initialize(Queue* vec) {
    vec->head = 0;
    list_constructor_heap(&(vec->container));
}

void queue_push(Queue* vec, int val) {
    list_push_back(vec->container, val);
    vec->head++;
}

void queue_pop(Queue* vec) {
    if(vec->head == 0){
        printf("Queue Underflow\n");
        return;
    }

    list_pop_front(vec->container);
    vec->head--;
}

void queue_display(Queue* vec) {
    printf("Queue -> ");
    list_print(vec->container);
}

void stack_display(Stack* vec) {
    printf("Stack -> ");
    list_print(vec->container);
}

int main() {
    Stack vec;
    stack_initialize(&vec);
    
    stack_push(&vec, 5);
    stack_push(&vec, 10);
    stack_push(&vec, 15);

    stack_pop(&vec);

    Queue q;
    queue_initialize(&q);
    
    queue_push(&q, 5);
    queue_push(&q, 10);
    queue_push(&q, 15);

    queue_pop(&q);

    queue_display(&q);
    stack_display(&vec);
}