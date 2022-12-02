#include <stdio.h>
#include <stdlib.h>

typedef struct QueueInt {
    size_t head;
    size_t size;    //rear
    size_t count;
    size_t capacity;
    int* container;
} QueueInt;

void queueIntConstructor(QueueInt* q) {
    q->head = 0;
    q->size = 0;
    q->capacity = 1;
    q->container = (int*)malloc(sizeof(int)*1);
}

void enqueueInt(QueueInt* q, int ele) {
    if(size == capacity) {
        q->container = realloc(q->container, capacity*2);
        q->capacity *= 2;
    }
    
    q->container[max] = ele;
    q->size++;
}

int dequeueInt(QueueInt* q) {
    q->head
}

int main()
{
    

    return 0;
}
