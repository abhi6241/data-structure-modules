/*
    Explain the Merge sort algorithm to arrange the list of the data values in
    ascending order. Write a C Program to read group of integer data values
    using one dimensional array, arrange the data values in ascending order
    using “Merge sort” algorithm. Send one dimensional array and
    number of data values as parameters of a function merge_sort() .
*/

#include <stdio.h>
#include <stdlib.h>

// Helper function to merge two sorted sub-arrays
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    } 
    for (j = 0; j < n2; j++)
    {
         R[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Recursive function to divide the array
void merge_sort_recursive(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        merge_sort_recursive(arr, left, mid);
        merge_sort_recursive(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Wrapper function as requested by the prompt
void merge_sort(int arr[], int n)
{
    if (n > 1)
    {
        merge_sort_recursive(arr, 0, n - 1);
    }
}

int main()
{
    int n, i;
    int data[100];

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1) return 0;

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

    // Calling the merge_sort function
    merge_sort(data, n);

    printf("\nSorted array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
