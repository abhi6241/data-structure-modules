#include<stdio.h>

int smallest(int a[], int n)
{
    int small = a[0];
    for(int i = 1; i < n; i++)
    {
        if(small > a[i])
            small = a[i];
    }
    return small;
}

int largest(int a[], int n)
{
    int big = a[0];
    for(int i = 1; i < n; i++)
    {
        if(big < a[i])
            big = a[i];
    }
    return big;
}

int main()
{
    int a[100], n, big, small;

    printf("Enter no. of elements: ");
    scanf("%d", &n);
    
    printf("Initialize array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    big = largest(a, n);  
    small = smallest(a, n);

    printf("\nThe Largest element in the array is: %d", big);
    printf("\nThe Smallest element in the array is: %d", small);

    return 0;
}