#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    if (front < -1 || front > rear)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (rear == (MAX - 1))
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
        rear++;
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
        front++;
    }
    return element;
}

void display()
{
    if (isEmpty())
        printf("\nQueue is empty");
    else
    {
        printf("\nQueue elements: ");
        for (int i = rear; i >= front; --i)
            printf("%d ", queue[i]);
        printf("\n");
    }
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
            printf("\nBye!! \n");
            break;
        default:
            printf("\nIncorrect Choice");
        }
    } while (choice != 4);
}
