/*
    The Towers of Hanoi problem involves moving a specified number of disks
    from one tower to another using a third as an auxiliary tower. Write a C
    program to move ‘n’ disks from peg A to peg C, using peg B as needed by
    following the conditions
    Only one disk may be moved at a time
    This disk must be the top disk on a peg
    A larger disk can never be placed on top of a smaller disk.
*/

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