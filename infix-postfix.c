#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 20

char stack_char[MAX];
int stack_int[MAX];
int top = -1;

void pushchar(char ch)
{
    top++;
    stack_char[top] = ch;
}
char popchar()
{
    char value;
    value = stack_char[top];
    top--;
    return value;
}
void pushint(int num)
{
    top++;
    stack_int[top] = num;
}
int popint()
{
    int value;
    value = stack_int[top];
    top--;
    return value;
}

int precedence(char x)
{
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    return 0;
}
void infixPostfix(char infix[])
{
    char postfix[MAX], *ch, value;
    ch = infix;
    int n = 0;
    while (*ch != '\0')
    {
        if (isalnum(*ch))
            postfix[n++] = *ch;
        else if (*ch == '(')
            pushchar('(');
        else if (*ch == ')')
        {
            while ((value = popchar()) != '(')
                postfix[n++] = value;
        }
        else
        {
            while (precedence(stack_char[top]) >= precedence(*ch))
                postfix[n++] = popchar();
            pushchar(*ch);
        }
        ch++;
    }

    while (top != -1)
        postfix[n++] = popchar();
    postfix[n++] = '\0';

    printf("\nPostfix expression: ");
    printf("%s\n", postfix);
}
void evaluate(char postfix[])
{
    char *ch;
    ch = postfix;
    int result = 0;
    while (*ch != '\0')
    {
        if (isalnum(*ch))
            pushint(*ch - 48);
        else
        {
            int n1 = popint();
            int n2 = popint();
            switch (*ch)
            {
            case '+':
                result = n2 + n1;
                break;
            case '-':
                result = n2 - n1;
                break;
            case '*':
                result = n2 * n1;
                break;
            case '/':
                result = n2 / n1;
                break;
            }
            pushint(result);
        }
        ch++;
    }
    printf("\nResult of Postfix evaluation: %d\n", popint());
}

void main()
{
    int choice, element;
    char exp[MAX];

    printf("\n1. Convert Infix to Postfix.");
    printf("\n2. Evaluate a Postfix expression.");
    printf("\n3. Exit");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Inifinix expression: ");
            scanf("%s", exp);
            infixPostfix(exp);
            break;
        case 2:
            printf("\nEnter Postfix expression: ");
            scanf("%s", exp);
            evaluate(exp);
            break;
        case 3:
            printf("\nBye!! \n");
            break;
        default:
            printf("\nIncorrect Choice");
        }
    } while (choice != 3);
}
