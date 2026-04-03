#include<stdio.h>
#define ROW 10
#define COL 10

typedef struct
{
    int row, col, val;
}t_term;

void sRead(t_term s[])
{
    int i;
    int r, c, nonzero;

    printf("\nEnter the no.of Rows, Columns and the no.of non-zero values of the Sparse Matrix: ");
    scanf("%d%d%d", &r, &c, &nonzero);

    s[0].row = r; s[0].col = c; s[0].val = nonzero;

    for(i = 1; i <= s[0].val; i++)
    {
        printf("\nEnter the %d triple term Square matrix: ", i);
        scanf("%d%d%d", &s[i].row, &s[i].col, &s[i].val);
    }
}

void sAdd(t_term b1[], t_term b2[], t_term b3[])
{
    int t1 = b1[0].val;
    int t2 = b2[0].val;
    int i = 1, j = 1, k = 1;

    // Check compatibility
    if(b1[0].row != b2[0].row || b1[0].col != b2[0].col)
    {
        printf("Addition not possible\n");
        return;
    }

    b3[0].row = b1[0].row;
    b3[0].col = b1[0].col;

    while(i <= t1 && j <= t2)
    {
        if(b1[i].row < b2[j].row ||
           (b1[i].row == b2[j].row && b1[i].col < b2[j].col))
        {
            b3[k++] = b1[i++];
        }
        else if(b2[j].row < b1[i].row ||
           (b2[j].row == b1[i].row && b2[j].col < b1[i].col))
        {
            b3[k++] = b2[j++];
        }
        else
        {
            int sum = b1[i].val + b2[j].val;
            if(sum != 0)   // avoid zero entries
            {
                b3[k].row = b1[i].row;
                b3[k].col = b1[i].col;
                b3[k].val = sum;
                k++;
            }
            i++; j++;
        }
    }

    while(i <= t1)
        b3[k++] = b1[i++];

    while(j <= t2)
        b3[k++] = b2[j++];

    b3[0].val = k - 1;
}

void display(t_term b[])
{
    int i;
    for(i = 0; i <= b[0].val; i++)
    {
        printf("%d\t%d\t%d", b[i].row, b[i].col, b[i].val);
        printf("\n");
    }
}

int main()
{
    t_term b1[20], b2[20], b3[40];

    printf("\nEnter first sparse matrix:\n");
    sRead(b1);

    printf("\nFirst matrix (triplet form):\n");
    display(b1);

    printf("\nEnter second sparse matrix:\n");
    sRead(b2);

    printf("\nSecond matrix (triplet form):\n");
    display(b2);

    sAdd(b1, b2, b3);

    printf("\nResultant matrix after addition:\n");
    display(b3);

    return 0;
}