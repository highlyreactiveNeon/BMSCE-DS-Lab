#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* nextNode;
    int data;
} Node;

typedef struct List {
    struct Node* head;
    int size;
} List;

// void list_constructor(List* list);
// void list_constructor_heap(List** list);

// void list_push_front(List* list, int val);
// void list_push_back(List* list, int val);
// void list_push_at(List* list, int pos, int val);

// int list_front(List* list);
// int list_back(List* list);
// int list_at(List* list, int pos);

// void list_pop_front(List* list);
// void list_pop_back(List* list);
// void list_pop_at(List* list, int pos);

// void list_print(List* list);

void list_constructor(List* list) {
    list->size = 0;
    list->head = (Node*)0;
}

void list_constructor_heap(List** list) {
    *list = (List*)malloc(sizeof(List));
    (*list)->size = 0;
    (*list)->head = (Node*)0;
}

void list_push_front(List* list, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->nextNode = list->head;

    list->head = newNode;
    list->size++;
}

void list_push_back(List* list, int val) {
    Node* currentNode = (Node*)list;
    while(currentNode->nextNode != (Node*)0)
        currentNode = currentNode->nextNode;
    currentNode->nextNode = (Node*)malloc(sizeof(Node));
    currentNode = currentNode->nextNode;
    currentNode->data = val;
    currentNode->nextNode = (Node*)0;
    list->size++;
}

void list_push_at(List* list, int pos, int val) {
    if(pos > list->size - 1 || pos < 0)
        return;

    Node* currentNode = (Node*)list;

    for(int i = 0; i < pos; i++)
        currentNode = currentNode->nextNode;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->nextNode = currentNode->nextNode;
    currentNode->nextNode = newNode;
    list->size++;
}

int list_at(List* list, int pos) {
    Node* currentNode = list->head;

    for(int i = 0; i < pos; i++)
        currentNode = currentNode->nextNode;

    return currentNode->data;
}

int list_front(List* list) {
    return list->head->data;
}

int list_back(List* list) {
    Node* currentNode = (Node*)list;

    while(currentNode->nextNode != (Node*)0)
        currentNode = currentNode->nextNode;

    return currentNode->data;    
}

void list_pop_front(List* list) {
    if(list->size == 0)
        return;

    Node* temp = list->head;
    list->head = temp->nextNode;
    free(temp);
    list->size--;
}

void list_pop_back(List* list) {
    if(list->size == 0)
        return;

    Node* currentNode = list->head;
    Node* prevNode = (Node*)list;

    while(currentNode->nextNode != (Node*)0) {
        prevNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    prevNode->nextNode = (Node*)0;
    free(currentNode);
    list->size--;
}

void list_pop_at(List* list, int pos) {
    if(pos > list->size - 1 || pos < 0)
        return;

    Node* currentNode = list->head;
    Node* prevNode = (Node*)list;

    for(int i = 0; i < pos; i++) {
        prevNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    prevNode->nextNode = currentNode->nextNode;
    free(currentNode);
    list->size--;
}

void list_print(List* list) {
    if(list->size == 0){
        printf("The list is empty\n");
        return;
    }

    Node* currentNode = list->head;

    printf("The contents of the list are: ");
    while(currentNode != (Node*)0) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->nextNode;
    }
    printf("\n");
}

void list_remove_duplicates(List* list) {
    Node* currentNode = (Node*)list;

    while(currentNode->nextNode != (Node*)0){
        currentNode = currentNode->nextNode;

        if(currentNode->nextNode->data == currentNode->data) {
            int tempValue = currentNode->data;
            Node* tempNode = currentNode->nextNode;

            while(tempNode->nextNode->data == tempValue)
                tempNode = tempNode->nextNode;

            currentNode->nextNode = tempNode->nextNode;
        }
    }
}

// using stack
void list_reverse(List* list) {
    
}