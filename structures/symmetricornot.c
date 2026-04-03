/*
    Write a C program to read a square Matrix of size by user’s choice by allocating
    memory dynamically using calloc() function, and display whether the given
    matrix is Symmetric or not.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, j;
    int **m;
    int isSymmetric = 1;

    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid size\n");
        return 1;
    }

    // Allocate memory
    m = (int **)calloc(n, sizeof(int *));
    if(!m)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(i = 0; i < n; i++)
    {
        m[i] = (int *)calloc(n, sizeof(int));
        if(!m[i])
        {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    // Input
    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    // Display
    printf("\nMatrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    // Check symmetry
    for(i = 0; i < n && isSymmetric; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(m[i][j] != m[j][i])
            {
                isSymmetric = 0;
                break;
            }
        }
    }

    // Output
    if(isSymmetric)
        printf("\nThe given square matrix is Symmetric!\n");
    else
        printf("\nThe given square matrix is NOT Symmetric!\n");

    // Free memory
    for(i = 0; i < n; i++)
        free(m[i]);
    free(m);

    return 0;
}