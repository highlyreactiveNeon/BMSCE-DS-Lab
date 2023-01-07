#include<stdio.h>
#include<stdlib.h>

#include"headers/dstack.h"

int main() {
    DStack* stk;
    dstack_constructor_heap(&stk);

    int ele;
    int temp;
    int bRunCode = 1;
    
    while(bRunCode){
    printf("Enter the command\n1.Push\n2.Pop\n3.Display\n4.Exit\n");    
        
    int choice;
    scanf("%d", &choice);
    
        switch(choice){
            case 1:
                scanf("%d", &temp);
                dstack_push(stk, temp);
                break;
            case 2:
                dstack_pop(stk);
                break;
            case 3:
                dstack_print(stk);
                break;
            case 4:
                bRunCode = 0;
                break;
            default:
                printf("Please enter the correct command\n");
        }

        printf("\n");
    }

    return 0;
}