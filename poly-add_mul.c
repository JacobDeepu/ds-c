#include <stdlib.h>
#include <stdio.h>

struct list
{
	int coeff, exp;
	struct list *next;
};
struct list *first = NULL, *second = NULL, *sum = NULL, *pro = NULL;

void traverse(struct list *node)
{
	struct list *temp;

	if (node == NULL)
		printf("\nList is empty");
	else
	{
		temp = node;
		while (temp != NULL)
		{
			printf("%dx^%d", temp->coeff, temp->exp);
			if (temp->exp != 0)
				printf(" + ");
			temp = temp->next;
		}
	}
}

void insertNode(struct list **node, int coeff, int exp)
{
	struct list *new = malloc(sizeof(struct list));
	struct list *temp;

	new->coeff = coeff;
	new->exp = exp;
	new->next = NULL;

	if (*node == NULL)
		*node = new;
	else
	{
		temp = *node;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

void insertAtFront(struct list **node, int coeff, int exp)
{
	struct list *new = malloc(sizeof(struct list));
	struct list *temp;

	new->coeff = coeff;
	new->exp = exp;
	new->next = *node;
	*node = new;
}

void add(int firstD, int secondD, int max)
{
	if (firstD > secondD)
	{
		for (int i = secondD + 1; i <= firstD; i++)
		{
			insertAtFront(&second, 0, i);
		}
	}
	else
	{
		for (int i = firstD + 1; i <= secondD; i++)
		{
			insertAtFront(&first, 0, i);
		}
	}
	struct list *temp1, *temp2;

	if (first == NULL && second == NULL)
		printf("\nList is empty");
	else
	{
		temp1 = first;
		temp2 = second;
		while (temp1 != NULL && temp2 != NULL)
		{
			int coeff = temp1->coeff + temp2->coeff;
			insertNode(&sum, coeff, temp1->exp);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
}

void multiply()
{
	int coeff = 0;
	int exp = 0;
	struct list *temp1 = first;
	struct list *temp3 = NULL;
	while (temp1 != NULL)
	{
		struct list *temp2 = second;
		while (temp2 != NULL)
		{
			exp = temp1->exp + temp2->exp;
			coeff = temp1->coeff * temp2->coeff;
			insertNode(&pro, coeff, exp);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	struct list *ptr1, *ptr2, *dup;
	ptr1 = pro;
	while (ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;
		while (ptr2->next != NULL)
		{
			if (ptr1->exp == ptr2->next->exp)
			{
				ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(dup);
			}
			else
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

int main()
{
	int firstD, secondD, coeff;

	printf("Enter degree of first polynomial: ");
	scanf("%d", &firstD);
	for (int i = firstD; i >= 0; i--)
	{
		printf("Enter coefficient of x^%d: ", i);
		scanf("%d", &coeff);
		insertNode(&first, coeff, i);
	}

	printf("Enter degree of second polynomial: ");
	scanf("%d", &secondD);
	for (int i = secondD; i >= 0; i--)
	{
		printf("Enter coefficient of x^%d: ", i);
		scanf("%d", &coeff);
		insertNode(&second, coeff, i);
	}
	int max = firstD > secondD ? firstD : secondD;

	printf("First polynomial: ");
	traverse(first);
	printf("\n");

	printf("Second polynomial: ");
	traverse(second);
	printf("\n");

	multiply();
	printf("Product of Polynomial: ");
	traverse(pro);
	printf("\n");

	add(firstD, secondD, max);
	printf("Sum of Polynomial: ");
	traverse(sum);
	printf("\n");
}
