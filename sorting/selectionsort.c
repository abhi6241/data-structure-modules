/*
    Explain the Selection sort algorithm to arrange the list of the data
    values in ascending order. Write a C Program to read group of integer data
    values using one dimensional array, arrange the data values in ascending
    order using “Selection sort” algorithm. Send one dimensional array and
    number of data values as parameters of a function selection_sort() .
*/

#include <stdio.h>

// Function to perform Selection Sort
void selection_sort(int arr[], int n)
{
    int i, j, min_idx, temp;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted subarray
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int n, i;
    int data[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

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

    // Calling the selection_sort function
    selection_sort(data, n);

    printf("\nSorted array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
