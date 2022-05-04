#include <stdio.h>

#define MAX 100

struct tuple
{
    int row;
    int col;
    int value;
};

void matrixToTuple(struct tuple tupleMatrix[], int matrix[][MAX], int row, int col)
{
    int size = 1;
    tupleMatrix[0].row = row;
    tupleMatrix[0].col = col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                tupleMatrix[size].row = i;
                tupleMatrix[size].col = j;
                tupleMatrix[size].value = matrix[i][j];
                size++;
            }
        }
    }
    tupleMatrix[0].value = size - 1;
}

void transpose(struct tuple tupleMatrix[])
{
    int size = tupleMatrix[0].value;
    struct tuple transpose[size + 1];
    transpose[0].row = tupleMatrix[0].col;
    transpose[0].col = tupleMatrix[0].row;
    transpose[0].value = size;
    if (size != 0)
    {
        int t = 1;
        for (int i = 0; i < tupleMatrix[0].col; i++)
        {
            for (int j = 1; j <= size; j++)
            {
                if (tupleMatrix[j].col == i)
                {
                    transpose[t].row = tupleMatrix[j].col;
                    transpose[t].col = tupleMatrix[j].row;
                    transpose[t].value = tupleMatrix[j].value;
                    t++;
                }
            }
        }
    }
    printf("Row\t Column\t Value\n");
    for (int i = 0; i <= size; i++)
    {
        printf("%d\t %d\t %d\n", transpose[i].row, transpose[i].col, transpose[i].value);
    }
}

void addMetrices(struct tuple tupleMatrixOne[], struct tuple tupleMatrixTwo[])
{
    struct tuple result[MAX];
    if (tupleMatrixOne[0].row != tupleMatrixTwo[0].row || tupleMatrixOne[0].col != tupleMatrixTwo[0].col)
        printf("matrix addtition not possible");
    else
    {
        result[0].row = tupleMatrixOne[0].row;
        result[0].col = tupleMatrixOne[0].col;
        int apos = 1, bpos = 1, size = 1;

        while (apos <= tupleMatrixOne[0].value && bpos <= tupleMatrixTwo[0].value)
        {
            if (tupleMatrixOne[apos].row > tupleMatrixTwo[bpos].row || (tupleMatrixOne[apos].row == tupleMatrixTwo[bpos].row && tupleMatrixOne[apos].col > tupleMatrixTwo[bpos].col))
            {
                result[size].row = tupleMatrixTwo[bpos].row;
                result[size].col = tupleMatrixTwo[bpos].col;
                result[size].value = tupleMatrixTwo[bpos].value;
                bpos++;
                size++;
            }
            else if (tupleMatrixOne[apos].row < tupleMatrixTwo[bpos].row || (tupleMatrixOne[apos].row == tupleMatrixTwo[bpos].row && tupleMatrixOne[apos].col < tupleMatrixTwo[bpos].col))
            {
                result[size].row = tupleMatrixOne[apos].row;
                result[size].col = tupleMatrixOne[apos].col;
                result[size].value = tupleMatrixOne[apos].value;
                apos++;
                size++;
            }
            else
            {
                int addedval = tupleMatrixOne[apos].value + tupleMatrixTwo[bpos].value;
                if (addedval != 0)
                {
                    result[size].row = tupleMatrixOne[apos].row;
                    result[size].col = tupleMatrixOne[apos].col;
                    result[size].value = addedval;
                    size++;
                }
                apos++;
                bpos++;
            }
        }
        while (tupleMatrixOne[0].value >= apos)
        {
            result[size].row = tupleMatrixOne[apos].row;
            result[size].col = tupleMatrixOne[apos].col;
            result[size].value = tupleMatrixOne[apos].value;
            apos++;
            size++;
        }
        while (tupleMatrixTwo[0].value >= bpos)
        {
            result[size].row = tupleMatrixTwo[bpos].row;
            result[size].col = tupleMatrixTwo[bpos].col;
            result[size].value = tupleMatrixTwo[bpos].value;
            bpos++;
            size++;
        }
        result[0].value = size - 1;
    }
    printf("\nResultant matrix: \n");
    printf("Row\t Column\t Value\n");
    for (int i = 0; i <= result[0].value; i++)
    {
        printf("%d\t %d\t %d\n", result[i].row, result[i].col, result[i].value);
    }
}

void main()
{
    struct tuple tupleMatrixOne[MAX];
    struct tuple tupleMatrixTwo[MAX];
    int row, col;

    printf("\nEnter number of rows and columns: ");
    scanf("%d %d", &row, &col);
    int a[row][MAX];
    printf("\nEnter matrix elements: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            scanf("%d", &a[i][j]);
    }
    matrixToTuple(tupleMatrixOne, a, row, col);
    printf("\nTuple Form of first matrix: \n");
    printf("Row\t Column\t Value\n");
    for (int i = 0; i <= tupleMatrixOne[0].value; i++)
    {
        printf("%d\t %d\t %d\n", tupleMatrixOne[i].row, tupleMatrixOne[i].col, tupleMatrixOne[i].value);
    }
    printf("\nTranspose of first matrix: \n");
    transpose(tupleMatrixOne);

    printf("\nEnter number of rows and columns: ");
    scanf("%d %d", &row, &col);
    int b[row][MAX];
    printf("\nEnter matrix elements: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            scanf("%d", &b[i][j]);
    }
    matrixToTuple(tupleMatrixTwo, b, row, col);
    printf("\nTuple Form of second matrix: \n");
    printf("Row\t Column\t Value\n");
    for (int i = 0; i <= tupleMatrixTwo[0].value; i++)
    {
        printf("%d\t %d\t %d\n", tupleMatrixTwo[i].row, tupleMatrixTwo[i].col, tupleMatrixTwo[i].value);
    }
    printf("\nTranspose of second matrix: \n");
    transpose(tupleMatrixTwo);

    addMetrices(tupleMatrixOne, tupleMatrixTwo);
}