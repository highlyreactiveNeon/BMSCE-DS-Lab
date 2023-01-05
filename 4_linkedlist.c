#include <stdio.h>
#include "list.h"

int main() {
    List* list;
    list_constructor_heap(&list);

    int choice, temp;
    int tempInd;
    char bIsRunning = 1;
    while(bIsRunning) {
        printf("Enter a operation:\n");
        printf("0.Exit\n1.Display\n2.Push Front\n3.Push Back\n4.Push at any location\n5.Pop Front\n6.Pop Back\n7.Pop at any location\n");

        scanf("%d", &choice);

        switch (choice){
        case 0:
            bIsRunning = 0;
            break;
        case 1:
            printf("value: ");
            scanf("%d", &temp);
            list_push_front(list, temp);
            break;
        case 2:
            printf("value: ");
            scanf("%d", &temp);
            list_push_back(list, temp);
            break;
        case 3:
            printf("index: ");
            scanf("%d", &tempInd);
            printf("value: ");
            scanf("%d", &temp);
            list_push_at(list, tempInd, temp);
            break;
        case 4:
            list_pop_front(list);
            break;
        case 5:
            list_pop_back(list);
            break;
        case 6:
            printf("index: ");
            scanf("%d", &tempInd);
            list_pop_at(list, tempInd);
            break;
        case 7:
            list_print(list);
            break;
        default:
            printf("Enter a correct choice, lol\n");
            break;
        }
    }

    return 0;
}