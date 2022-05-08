#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = 0;

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

void enqueueFront(int element)
{
    if (isFull())
        printf("\nQueue is full");
    else if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = MAX - 1;
    else
        front = front - 1;

    queue[front] = element;
}

void enqueueRear(int element)
{
    if (isFull())
        printf("\nQueue is full");
    else if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == (MAX - 1))
        rear = 0;
    else
        rear = rear + 1;

    queue[rear] = element;
}

int dequeueFront()
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
            front = front == (MAX - 1) ? 0 : (front + 1);
        }
    }
    return element;
}

int dequeueRear()
{
    int element = -1;
    if (isEmpty())
        printf("\nQueue is empty");
    else
    {
        element = queue[rear];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear = rear == 0 ? (MAX - 1) : (rear - 1);
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

    printf("\n1. Insert element to the Front of the queue");
    printf("\n2. Insert element to the Rear of the queue");
    printf("\n3. Delete element from the Front of the queue");
    printf("\n4. Delete element from the Rear of the queue");
    printf("\n5. Display queue");
    printf("\n6. Exit");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter integer to insert: ");
            scanf("%d", &element);
            enqueueFront(element);
            display(queue);
            break;
        case 2:
            printf("\nEnter integer to insert: ");
            scanf("%d", &element);
            enqueueRear(element);
            display(queue);
            break;
        case 3:
            element = dequeueFront();
            if (element != -1)
                printf("\nElement %d deleted from queue", element);
            display(queue);
            break;
        case 4:
            element = dequeueRear();
            if (element != -1)
                printf("\nElement %d deleted from queue", element);
            display(queue);
            break;
        case 5:
            display(queue);
            break;
        case 6:
            printf("\n Bye!! \n");
            break;
        default:
            printf("\nIncorrect Choice");
        }
    } while (choice != 6);
}
