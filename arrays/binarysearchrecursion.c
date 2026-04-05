/*
    Write a C program to search for the key element from the set of given data
    values which are arranged in ascending order by applying “Binary search”
    algorithm using Recursion?
*/

#include<stdio.h>

int binarySearch(int a[], int target, int startIndex, int lastIndex)
{
    int mid;

    if(lastIndex >= startIndex)
    {
        mid = (lastIndex + startIndex) / 2;

        if(a[mid] == target)
            return mid;
        else if(a[mid] > target)
            return binarySearch(a, target, startIndex, mid - 1);
        else
            return binarySearch(a, target, mid + 1, lastIndex);
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