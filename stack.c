#include <stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == (MAX - 1))
        return 1;
    else
        return 0;
}

void push(int element)
{
    if (isFull())
        printf("\nStack is full");
    else
    {
        top++;
        stack[top] = element;
    }
}

int pop()
{
    int element = -1;
    if (isEmpty())
        printf("\nStack is empty");
    else
    {
        element = stack[top];
        top--;
    }
    return element;
}

void display()
{
    if (isEmpty())
        printf("\nStack is empty");
    else
    {
        printf("\nStack elements: ");
        for (int i = top; i >= 0; --i)
        {
            printf("\n%d", stack[i]);
        }
        printf("\n");
    }
}

void main()
{
    int choice, element;

    printf("\n1. Push element to stack");
    printf("\n2. Pop element from stack");
    printf("\n3. Display stack");
    printf("\n4. Exit");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter integer to push: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            element = pop();
            if (element != -1)
                printf("\nElement %d poped from stack\n", element);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nBye!! \n");
            break;
        default:
            printf("\nIncorrect Choice");
        }
    } while (choice != 4);
}
