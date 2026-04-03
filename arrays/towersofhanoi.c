#include<stdio.h>

void towersOfHanoi(int n, char source, char auxi, char dest)
{
    if(n == 1)
    {
        printf("Move Disc 1 from %c to %c\n", source, dest);
        return;
    }

    towersOfHanoi(n-1, source, dest, auxi);
    printf("Move Disc %d from %c to %c\n", n, source, dest);
    towersOfHanoi(n-1, auxi, source, dest);
}

int main()
{
    int n;
    char source = 'A', auxi = 'B', dest = 'C';

    printf("Enter the number of discs: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid input");
        return 0;
    }

    towersOfHanoi(n, source, auxi, dest);

    return 0;
}