#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void push(int element)
{
    struct node *temp, *new;
    new = malloc(sizeof(struct node));
    new->data = element;
    new->next = NULL;

    if (head == NULL)
        head = new;
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

int pop()
{
    int element = -1;
    struct node *temp, *previous;
    if (head == NULL)
        printf("\nStack is empty");
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            previous = temp;
            temp = temp->next;
        }
        element = temp->data;
        if (temp == head)
            head = NULL;
        else
        {
            previous->next = NULL;
            free(temp);
        }
    }
    return element;
}

void display()
{
    struct node *temp;
    if (head == NULL)
        printf("\nStack is empty");
    else
    {
        temp = head;
        printf("\nStack elements: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
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
            display();
            break;
        case 2:
            element = pop();
            if (element != -1)
                printf("\nElement %d poped from stack\n", element);
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n Bye!! \n");
            break;
        default:
            printf("\nIncorrect Choice");
        }
    } while (choice != 4);
}