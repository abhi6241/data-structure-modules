#include<stdio.h>

int binarySearch(int a[], int t, int s, int l)
{
    int m;

    if(l >= s)
    {
        m = (l + s) / 2;

        if(a[m] == t)
            return m;
        else if(a[m] > t)
            return binarySearch(a, t, s, m - 1);
        else
            return binarySearch(a, t, m + 1, l);
    }

    return -1;
}

int main()
{
    int a[] = {2, 5, 8, 12, 16, 23};
    int n = 6;
    int target = 12;

    int result = binarySearch(a, target, 0, n - 1);

    if(result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");

    return 0;
}