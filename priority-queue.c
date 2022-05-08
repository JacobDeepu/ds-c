#include <stdio.h>

#define MAX 10

int queue[MAX];
int priorityQueue[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    if (front == -1 || front > rear)
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

void enqueue(int element, int priority)
{
    if (isFull())
        printf("\nQueue is full\n");
    else
    {
        rear++;
        queue[rear] = element;
        priorityQueue[rear] = priority;
        front = front == -1 ? 0 : front;
    }
}

int dequeue()
{
    int element = -1;
    if (isEmpty())
        printf("\nQueue is empty\n");
    else
    {
        int priority = 0, position = 0;
        for (int i = front; i <= rear; i++)
        {
            if (priority < priorityQueue[i])
            {
                priority = priorityQueue[i];
                position = i;
            }
        }
        if (queue[front] == queue[position])
        {

            element = queue[front];
            front++;
        }
        else
        {
            element = queue[position];
            for (int i = position; i < rear; i++)
            {
                queue[i] = queue[i + 1];
                priorityQueue[i] = priorityQueue[i + 1];
            }
            rear--;
        }
    }
    return element;
}

void display()
{
    if (isEmpty())
        printf("\nQueue is empty\n");
    else
    {
        printf("\nQueue elements: ");
        for (int i = rear; i >= front; --i)
            printf("%d ", queue[i]);
        printf("\nQueue priority: ");
        for (int i = rear; i >= front; --i)
            printf("%d ", priorityQueue[i]);
        printf("\n");
    }
}

void main()
{
    int choice, element, priority;

    do
    {
        printf("\n1. Insert element to queue");
        printf("\n2. Delete element from queue");
        printf("\n3. Display queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter integer to insert: ");
            scanf("%d", &element);
            printf("\nEnter its priority: ");
            scanf("%d", &priority);
            enqueue(element, priority);
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
