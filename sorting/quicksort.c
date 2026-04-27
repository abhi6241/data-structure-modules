/*
    Explain the Quick sort algorithm to arrange the list of the data
    values in ascending order. Write a C Program to read group of integer
    data values using one dimensional array, arrange the data values in
    ascending order using “Quick sort” algorithm. Send one dimensional array
    and number of data values as parameters of a function quick_sort() .
*/

#include <stdio.h>

// Helper function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array based on a pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);    // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Recursive Quick Sort function
void quick_sort_recursive(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }
}

// Wrapper function as requested
void quick_sort(int arr[], int n)
{
    if (n > 1)
    {
        quick_sort_recursive(arr, 0, n - 1);
    }
}

int main()
{
    int n, i;
    int data[100];

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1)
    {
        return 0;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    printf("\nOriginal array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    // Calling the quick_sort function
    quick_sort(data, n);

    printf("\nSorted array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
