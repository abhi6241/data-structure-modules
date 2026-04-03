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
    int n;

    printf("Enter the String: ");
    fgets(c, sizeof(c), stdin);

    // Remove newline from fgets
    c[strcspn(c, "\n")] = '\0';

    n = strlen(c);

    permutations(c, 0, n-1);

    printf("\n%dP%d = %d\n", n, n, count);

    return 0;
}