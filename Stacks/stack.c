#include <stdio.h>
#include <stdlib.h>
#define size 3

int top = -1, stack[size];

int is_full()
{
    if (top == (size - 1))
        return 1;
    else
        return 0;
}

int is_empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int element)
{
    if (is_full())
    {
        printf("Stack is full!!!\n");
    }
    else
    {
        top++;
        stack[top] = element;
        printf("ELement pushed is %d\n", element);
    }
}

void pop()
{
    if (is_empty())
    {
        printf("Stack is empty!!");
    }
    else
    {

        printf("Element poped is %d \n", stack[top]);
        top--; 
    }
}

void display()
{
    if (is_empty())
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        printf("Elements in the stack are:\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void size_stack()
{
    printf("The size of stack is=%d\n", (top + 1));
}
void main()
{
    int ch, element;
    printf("Enter your choice\n");
    while (1)
    {
        printf("STACK OPERATIONS:\n");
        printf("1.Push 2.Pop 3.size 4.display 5.exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element to be pushed inside stack\n");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            pop();
            break;

        case 3:
            size_stack();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice ....Try Again\n");
            break;
        }
    }
}