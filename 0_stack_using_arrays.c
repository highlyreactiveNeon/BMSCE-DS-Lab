#include <stdio.h>
#define STACK_SIZE 5

int top = -1;
int array[10];

void push()
{
    top++;
    if (top == STACK_SIZE)
    {
        top--;
        printf("StackOverflow\n");
        return;
    }
    printf("Enter the element: ");
    int ele;
    scanf("%d", &ele);
    printf("\n");
    array[top] = ele;
}

int pop()
{
    if (top == -1)
    {
        printf("StackUnderflow\n");
        return 0;
    }
    top--;
    return array[top++];
}

void display()
{
    if (top == -1)
    {
        printf("The stack is empty, lol\n\n");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d ", array[i]);
    printf("\n\n");
}

int main()
{
    int flag = 1;
    int choice;

    while (flag)
    {
        printf("Enter the operation to be performed\n");
        printf("1.push\n2.pop\n3.display\n4.exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("The program has been terminated\n");
            flag = 0;
            break;
        default:
            printf("Please enter a valid option\n");
        }
    }

    return 0;
}
