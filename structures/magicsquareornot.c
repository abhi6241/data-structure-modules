/*
    Write a C program to read a Square Matrix and verify whether the given matrix
    is Magic square matrix or not.
*/

#include <stdio.h>

int main()
{
    int n, i, j, sum, rowsum, colsum, diag1 = 0, diag2 = 0;
    int isMagic = 1;
    int mat[20][20];

    printf("\nEnter the order of matrix (n): ");
    scanf("%d", &n);

    // 1. Input with fixed loop condition (j < n)
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    // 2. Expected sum formula
    sum = (n * (n * n + 1)) / 2;
    printf("\nExpected Magic Sum: %d\n", sum);

    // 3. Check Rows
    for(i = 0; i < n && isMagic; i++)
    {
        rowsum = 0;
        for(j = 0; j < n; j++)
        {
            rowsum += mat[i][j];
        }
        if(rowsum != sum) isMagic = 0;
    }

    // 4. Check Columns
    for(j = 0; j < n && isMagic; j++)
    {
        colsum = 0;
        for(i = 0; i < n; i++)
        {
            colsum += mat[i][j];
        }
        if(colsum != sum) isMagic = 0;
    }

    // 5. Check Main Diagonal (top-left to bottom-right)
    if(isMagic)
    {
        for(i = 0; i < n; i++)
        {
            diag1 += mat[i][i]; // Fixed: Use mat[i][i]
        }
        if(diag1 != sum) isMagic = 0;
    }

    // 6. Check Anti-Diagonal (top-right to bottom-left)
    if(isMagic)
    {
        for(i = 0; i < n; i++)
        {
            diag2 += mat[i][n - i - 1];
        }
        if(diag2 != sum) isMagic = 0;
    }

    if(isMagic)
        printf("\nIt is a Magic Square Matrix!\n");
    else
        printf("\nIt is not a Magic Square Matrix!\n");

    return 0;
}
