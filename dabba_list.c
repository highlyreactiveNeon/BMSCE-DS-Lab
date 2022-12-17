#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node* nextNode;
    int data;
} Node;

typedef struct List {
    struct Node* head;
    int size;
} List;

void listConstructor(List* list) {
    list->size = 0;
    list->head = (Node*)0;
}

void push_front(List* list) {

}

void push_back(List* list, int val) {
    Node* currentNode = list->head;
    Node* prevNode = list->head;

    while(currentNode != (Node*)0){
        prevNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    currentNode = (Node*)malloc(sizeof(Node));
    prevNode->nextNode = currentNode;
    currentNode->data = val;
    currentNode->nextNode = (Node*)0;

    list->size += 1;
}

void display(List* list) {
    if(list->size == 0){
        printf("The list is empty, lol\n");
    }

    Node* currentNode = list->head;

    while(currentNode != (Node*)0) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->nextNode;
    }
}

int main() {
    List list;
    listConstructor(&list);

    push_back(&list, 6);

    display(&list);

    return 0;
}
