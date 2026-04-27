/*
    Explain the Heap sort algorithm to arrange the list of the data values in
    ascending order. Write a C Program to read group of integer data values
    using one dimensional array, arrange the data values in ascending order
    using “Heap sort” algorithm. Send one dimensional array and number of
    data values as parameters of a function heap_sort() .
*/

#include <stdio.h>

// Helper function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the Max-Heap property
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // If right child is larger than current largest
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to perform Heap Sort
void heap_sort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
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

    // Calling the heap_sort function
    heap_sort(data, n);

    printf("\nSorted array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
