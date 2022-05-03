#include <stdio.h>

#define MAX 20

typedef struct
{
    int coeff;
    int exp;
} polynomial;

int main()
{
    polynomial first[MAX], second[MAX], sum[MAX];
    int firstD, secondD, max;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &firstD);
    for (int i = firstD; i >= 0; i--)
    {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &first[i].coeff);
        first[i].exp = i;
    }

    printf("Enter degree of second polynomial: ");
    scanf("%d", &secondD);
    for (int i = secondD; i >= 0; i--)
    {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &second[i].coeff);
        second[i].exp = i;
    }

    printf("First polynomial: ");
    for (int i = firstD; i >= 0; i--)
    {
        printf("%dx^%d", first[i].coeff, first[i].exp);
        if (i != 0)
            printf(" + ");
    }
    printf("\n");

    printf("Second polynomial: ");
    for (int i = secondD; i >= 0; i--)
    {
        printf("%dx^%d", second[i].coeff, second[i].exp);
        if (i != 0)
            printf(" + ");
    }
    printf("\n");

    max = firstD > secondD ? firstD : secondD;
    if (firstD > secondD)
    {
        for (int i = secondD + 1; i <= firstD; i++)
        {
            second[i].coeff = 0;
            second[i].exp = i;
        }
    }
    else
    {
        for (int i = firstD + 1; i <= secondD; i++)
        {
            first[i].coeff = 0;
            first[i].exp = i;
        }
    }

    for (int i = max; i >= 0; i--)
    {
        sum[i].coeff = second[i].coeff + first[i].coeff;
        sum[i].exp = i;
    }

    printf("Resultant Polynomial: ");
    for (int i = max; i >= 0; i--)
    {
        printf("%dx^%d", sum[i].coeff, sum[i].exp);
        if (i != 0)
            printf(" + ");
    }
    printf("\n");
}