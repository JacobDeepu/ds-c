#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *link;
};
struct list *start = NULL;

void traverse()
{
    struct list *temp;

    if (start == NULL)
        printf("\nList is empty");
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("\nData = %d", temp->data);
            temp = temp->link;
        }
    }
}

void insertAtFront()
{
    int data;
    struct list *temp;
    temp = malloc(sizeof(struct list));
    printf("\nEnter number to  be inserted : ");
    scanf("%d", &data);
    temp->data = data;

    temp->link = start;
    start = temp;
}

void insertAtEnd()
{
    int data;
    struct list *temp, *head;
    temp = malloc(sizeof(struct list));

    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);

    temp->link = 0;
    temp->data = data;
    head = start;
    while (head->link != NULL)
    {
        head = head->link;
    }
    head->link = temp;
}

void insertAtPosition()
{
    struct list *temp, *newlist;
    int pos, data, i = 1;
    newlist = malloc(sizeof(struct list));

    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);

    temp = start;
    newlist->data = data;
    newlist->link = 0;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    newlist->link = temp->link;
    temp->link = newlist;
}

void deleteFirst()
{
    struct list *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = start;
        start = start->link;
        free(temp);
    }
}

void deleteEnd()
{
    struct list *temp, *prevlist;
    if (start == NULL)
        printf("\nList is Empty\n");
    else
    {
        temp = start;
        while (temp->link != 0)
        {
            prevlist = temp;
            temp = temp->link;
        }
        free(temp);
        prevlist->link = 0;
    }
}

void deletePosition()
{
    struct list *temp, *position;
    int i = 1, pos;

    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        printf("\nEnter index : ");

        scanf("%d", &pos);
        position = malloc(sizeof(struct list));
        temp = start;

        while (i < pos - 1)
        {
            temp = temp->link;
            i++;
        }

        position = temp->link;
        temp->link = position->link;

        free(position);
    }
}

void main()
{
    int choice;

    printf("\n1. Display");
    printf("\n2. Insert at Beginning");
    printf("\n3. Insert at End");
    printf("\n4. Insert at a specified Position");
    printf("\n5. Delete from Beginning");
    printf("\n6. Delete from End");
    printf("\n7. Delete from a specified Position");
    printf("\n8. Exit");
    while (1)
    {
        printf("\nEnter Choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deletePosition();
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
}