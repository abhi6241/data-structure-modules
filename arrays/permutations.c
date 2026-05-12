/*
    Given a set of n≥1 elements, write a C program to print out all possible
    Permutations of this set using recursion.
    If the set is {1,2,3} then the set of permutations are {(1,2,3) , (1,3,2), (2,1,3),
    (2,3,1), (3,1,2), (3,2,1)}.
*/

#include<stdio.h>
#include<string.h>

#define SWAP(p,q,t) {t = p; p = q; q = t;}

int count = 0;

void permutations(char b[], int i, int n)
{
    int j;
    char temp;

    if(i == n)
    {
        printf("%s\n", b);  // better formatting
        count++;
        return;
    }

    for(j = i; j <= n; j++)
    {
        SWAP(b[i], b[j], temp);
        permutations(b, i+1, n);
        SWAP(b[i], b[j], temp); // backtracking
    }
}

int main()
{
    char c[20];
    int n = 0;

    printf("Enter the String: ");
    scanf("%s", c); // Read string without whitespace

    // Manual strlen: count characters until null terminator '\0'
    while (c[n] != '\0')
    {
        n++;
    }

    // Call permutations with 0-based indexing (0 to n-1)
    permutations(c, 0, n - 1);

    printf("\n%dP%d = %d\n", n, n, count);

    return 0;
}