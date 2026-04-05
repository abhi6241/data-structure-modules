/*
    Define Ackerman’s function? Write a C program to solve the Ackerman’s
    function using Recursion?
*/

#include<stdio.h>

int ackerman(int m, int n)
{
    if(m == 0)
        return n + 1;
    else if(m > 0 && n == 0)
        return ackerman(m-1, 1);
    else
        return ackerman(m-1, ackerman(m, n-1));
}

int main()
{
    int m = 2, n = 4;
    int result;

    result = ackerman(m, n);

    printf("Ackermann(%d, %d) = %d\n", m, n, result);

    return 0;
}