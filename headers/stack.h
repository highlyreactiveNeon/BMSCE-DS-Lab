#pragma once

#include<stdlib.h>
#include<stdio.h>

typedef struct Stack {
    int* container;
    size_t size;
    size_t capacity;
} Stack;

void stack_constructor(Stack* stack, size_t capacity) {
    stack->size = 0;
    stack->capacity = capacity;
    stack->container = (int*)malloc(sizeof(int)*capacity);

    if(stack->container == NULL) {
        fprintf(stderr, "[ERR] stack_constructor(): Failed to allocate memory for container of stack\n");
        exit(1);
    }
}

void stack_constructor_heap(Stack** stack, size_t capacity) {
    *stack = (Stack*)malloc(sizeof(Stack));
    (*stack)->size = 0;
    (*stack)->capacity = capacity;
    (*stack)->container = (int*)malloc(sizeof(int));

    if(*stack == NULL){
        fprintf(stderr, "[ERR] stack_constructor_heap(): Failed to allocate stack in heap\n");
        exit(1);
    }

    if((*stack)->container == NULL) {
        fprintf(stderr, "[ERR] stack_constructor_heap(): Failed to allocate memory for container of stack\n");
        exit(1);
    }
}

void stack_push(Stack* stack, int val) {
    if(stack->size == stack->capacity) {
        fprintf(stderr, "[ERR] stack_push(): stack overflown\n");
        exit(1);
    }

    stack->container[stack->size] = val;
    stack->size++;
}

void stack_pop(Stack* stack) {
    if(stack->size == 0) {
        fprintf(stderr, "[ERR] stack_pop(): stack underflown\n");
        exit(1);
    }

    stack->size--;
}

void stack_print(Stack* stack) {
    if(stack->size == 0) {
        printf("The stack is empty\n");
        return;
    }

    printf("The contents of the dstack are:\n");
    for(int i = stack->size - 1; i >= 0; i--)
        printf("%d ", stack->container[i]);

    printf("\n");
}