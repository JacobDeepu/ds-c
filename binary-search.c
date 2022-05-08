#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

void sortStrings(char arr[][MAX], int n)
{
    char temp[MAX];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int binarySearch(char arr[][MAX], char x[], int n)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        int res = -1000;
        if (strcmp(x, arr[m]) == 0)
            res = 0;

        if (res == 0)
            return m;

        if (strcmp(x, arr[m]) > 0)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int main()
{
    FILE *file;
    char ch, str[MAX], arr[10][MAX];
    int i = 0, n = 0;
    file = fopen("input.txt", "r");

    if (NULL == file)
    {
        printf("File can't be opened \n");
    }

    printf("File content: ");
    while ((ch = fgetc(file)) != EOF)
    {
        str[i] = ch;
        printf("%c", str[i]);
        if (ch == ' ')
        {
            int j = 0;
            while (str[j] != ' ')
            {
                arr[n][j] = str[j];
                j++;
            }
            n++;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    printf("\n");
    sortStrings(arr, n);
    printf("Sorted content: ");
    for (int i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
    }
    printf("\n");
    char x[10];
    printf("Enter string to search: ");
    scanf("%s", &x);
    int res = binarySearch(arr, x, n);
    if (res == -1)
        printf("String not found\n");
    else
        printf("String found at index %d\n", res);
    fclose(file);
    return 0;
}