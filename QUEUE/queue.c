#include <stdio.h>
#include <stdlib.h>
#define qs 5


int front = -1, rear = -1, queue[qs];

int is_full()
{
    if (rear == (qs - 1))
        return 1;
    else
        return 0;
}

int is_empty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

void display()
{

    if (is_empty())
        printf("Queue Underflow\n");
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
void dequeue()
{
    if (is_empty())
        printf("Queue Underflow\n");
    else
    {
        printf("Element dequeued from queue : %d\n", queue[front]);
        front++;
    }
}
void peek()
{
    if (is_empty())
        printf("Queue Underflow\n");
    else
        printf("The first element : %d\n", queue[front]);
}

void enqueue()
{
    int ele;
    printf("Enter the element to be enqueued\n");
    scanf("%d", &ele);

    if (is_full())
        printf("Queue Overflow\n");
    else if (is_empty())
    {
        front++;
        rear++;
        queue[front] = ele;
        printf("Element enqueued into queue : %d\n", ele);
    }
    else
    {

        rear++;
        queue[rear] = ele;
        printf("Element enqueued into queue : %d\n", ele);
    }
}

void main()
{
    int ch;
    while (1)
    {
        printf("Enter your choice\n");
        printf("Queue Operations\n");
        printf("1.Enqueue \n 2.Dequeue \n 3.Peek \n 4.Display \n 5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;

        default:
            printf("Invalid Choice.....!\n");
            break;
        }
    }
}