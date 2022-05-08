#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (front == rear + 1 || (front == 0 && rear == (MAX - 1)))
        return 1;
    else
        return 0;
}

void enqueue(int element)
{
    if (isFull())
        printf("\nQueue is full");
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = element;
        front = front == -1 ? 0 : front;
    }
}

int dequeue()
{
    int element = -1;
    if (isEmpty())
        printf("\nQueue is empty");
    else
    {
        element = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
    return element;
}

void display()
{
    if (isEmpty())
        printf("\nQueue is empty");
    else
    {
        int i = front;
        printf("\nQueue elements: ");
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d", queue[rear]);
    }
    printf("\n");
}

void main()
{
    int choice, element;

    printf("\n1. Insert element to queue");
    printf("\n2. Delete element from queue");
    printf("\n3. Display queue");
    printf("\n4. Exit");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter integer to insert: ");
            scanf("%d", &element);
            enqueue(element);
            display(queue);
            break;
        case 2:
            element = dequeue();
            if (element != -1)
                printf("\nElement %d deleted from queue", element);
            display(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            printf("\n Bye!! \n");
            break;
        default:
            printf("\nIncorrect Choice");
        }
    } while (choice != 4);
}
