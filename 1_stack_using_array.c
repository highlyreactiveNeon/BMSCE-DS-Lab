#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 1

typedef struct Stack{
    int head;
    int* container;
} Stack;

void stackConstructor(Stack *s){
    s->head = -1;
    s->container = (int*)malloc(sizeof(int)*STACK_SIZE);
}

void push(Stack *s, int ele){
        s->head++;
        s->container[s->head] = ele;
        printf("\n");
}

void pop(Stack *s){
    if(s->head == -1){
        printf("STACKUNDERFLOW\n\n");
        return;
    }
    
    s->head--;
    printf("\n");
}

void display(Stack *s){
    if(s->head == -1){
        printf("The empty is empty, lol\n\n");
    }
    
    for(int i = 0; i < s->head+1; i++){
        printf("%d ", s->container[i]);
    }
    printf("\n\n");
}

int main(){
    Stack s;
    stackConstructor(&s);
    
    int ele;
    int bRunCode = 1;
    
    while(bRunCode){
    printf("Enter the command\n1.Push\n2.Pop\n3.Display\n4.Exit\n");    
        
    int choice;
    scanf("%d", &choice);
    
        switch(choice){
            case 1:
                if(STACK_SIZE - 1 == s.head){
                    printf("STACKOVERFLOW\n\n");
                    break;
                }
                else{
                    printf("Enter the element: ");
                    scanf("%d", &ele);
                    push(&s, ele);
                    break;
                }
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                bRunCode = 0;
                break;
            default:
                printf("Please enter the correct command\n");
        }
    }
    
    return 0;
}
