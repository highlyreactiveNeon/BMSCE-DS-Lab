#include <stdio.h>
# define SIZE 100

void push();
void pop();
void show();
int inp_arr[SIZE];
int r = - 1;
int f = - 1;
main()
{
    int ch;
    while (1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
            default:
                printf("Incorrect choice \n");
        } 
    } 
} 

void push()
{
    int insert_item;
    if (r == SIZE - 1)
       printf("Overflow \n");
    else
    {
        if (f == - 1)

        f = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &insert_item);
        r = r + 1;
        inp_arr[r] = insert_item;
    }
} 

void pop()
{
    if (f == - 1 || f > r)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[f]);
        f = f + 1;
    }
} 

void show()
{

    if (f == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = f; i <= r; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}
