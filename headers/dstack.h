#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef struct DStack {
    int* container;
    int size;
    int capacity;
} DStack;

void dstack_constructor(DStack* stack) {
    stack->size = 0;
    stack->capacity = 1;
    stack->container = (int*)malloc(sizeof(int));

    if(stack->container == NULL) {
        fprintf(stderr, "[ERR] dstack_constructor(): Failed to allocate memory for container of dstack\n");
        exit(1);
    }
}

void dstack_constructor_heap(DStack** stack) {
    *stack = (DStack*)malloc(sizeof(DStack));
    (*stack)->size = 0;
    (*stack)->capacity = 1;
    (*stack)->container = (int*)malloc(sizeof(int));

    if(*stack == NULL){
        fprintf(stderr, "[ERR] dstack_constructor_heap(): Failed to allocate dstack of heap\n");
        exit(1);
    }

    if((*stack)->container == NULL) {
        fprintf(stderr, "[ERR] dstack_constructor_heap(): Failed to allocate memory for container of dstack\n");
        exit(1);
    }
}

void dstack_push(DStack* stack, int val) {
    if(stack->size == stack->capacity){
        stack->capacity *= 2;
        realloc(stack->container, stack->capacity);
    }

    stack->container[stack->size] = val;
    stack->size++;
}

void dstack_pop(DStack* stack) {
    if(stack->size == 0) {
        fprintf(stderr, "[ERR] dstack_pop(): dstack underflown\n");
        exit(1);
    }

    stack->size--;

    if(stack->size*2 == stack->capacity) {
        stack->capacity /= 2;
        realloc(stack->container, stack->capacity);
    }
}

void dstack_print(DStack* stack) {
    if(stack->size == 0) {
        printf("The list is empty\n");
        return;
    }

    printf("The contents of the dstack are:\n");
    for(int i = stack->size - 1; i >= 0; i--)
        printf("%d ", stack->container[i]);

    printf("\n");
}