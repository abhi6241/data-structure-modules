/*
    Write a C program to define an ADT t_term with members row, col, and val, and implement the following operations:
        To read a sparse matrix in triple term format
        To find the transpose of the sparse matrix
        To display the sparse matrix in triple term format
*/

#include<stdio.h>
#define ROW 10
#define COL 10

typedef struct 
{
    int row, col, val;
} t_term;

void m_conv(int a[][10], t_term b[], int r, int c)
{
    int i, j, k = 1;
    b[0].row = r;
    b[0].col = c;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(a[i][j] != 0)
            {
                b[k].row = i;
                b[k].col = j;
                b[k].val = a[i][j];
                k++;
            }
        }
    }
    b[0].val = k - 1;
}

void transpose(t_term b[], t_term c[])
{
    int n = b[0].val;
    int i, j, k = 1;

    c[0].row = b[0].col;
    c[0].col = b[0].row;
    c[0].val = n;

    for(i = 0; i < b[0].col; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(b[j].col == i)
            {
                c[k].row = b[j].col;   // swapped
                c[k].col = b[j].row;   // swapped
                c[k].val = b[j].val;
                k++;
            }
        }
    }
}

void display(t_term b[])
{
    int i;
    printf("Row Col Val\n");
    for(i = 0; i <= b[0].val; i++)
    {
        printf("%d\t%d\t%d\n", b[i].row, b[i].col, b[i].val);
    }
}

int main()
{
    int a[ROW][COL], r, c, i, j;
    t_term b[20], d[20];

    printf("Enter rows and columns of matrix: ");
    scanf("%d%d", &r, &c);

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("Enter [%d][%d] data: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nOriginal matrix:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }

    m_conv(a, b, r, c);

    printf("\nTriple form:\n");
    display(b);

    transpose(b, d);

    printf("\nTranspose (triple form):\n");
    display(d);

    return 0;
}
