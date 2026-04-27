/*
    Write a C program to construct the Max-Heap tree and perform the
    following operations
        i) Adding a new node to the existing Heap tree, and display
            the resultant tree.
        ii) Deleting a node by specifying the data value from the Heap
            tree and display the resultant tree.
*/

#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void makeheap(int *arr, int n);
void restoredown(int pos, int *arr, int n);
void add(int val, int *arr, int *n);
void restoreup(int i, int *arr);
int del_root(int *arr, int *n);

int main(void)
{
    // Index 0 is a sentinel value (higher than any element) to stop restoreup
    int arr[20] = {9999, 7, 10, 25, 17, 23, 27, 16, 19, 37, 42, 4, 33, 1, 5, 11};
    int i, n = 15, ad, de;

    makeheap(arr, n);

    printf("Initial Max-Heap:\n");
    for (i = 1; i <= n; i++) printf("%d ", arr[i]);

    // i) Adding a new node
    printf("\n\nEnter data to add to heap: ");
    scanf("%d", &ad);
    add(ad, arr, &n);
    printf("Heap after adding %d:\n", ad);
    for (i = 1; i <= n; i++) printf("%d ", arr[i]);

    // ii) Deleting the root (Standard Heap Deletion)
    de = del_root(arr, &n);
    printf("\n\nDeleted root element: %d", de);
    printf("\nHeap after deleting root:\n");
    for (i = 1; i <= n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

// Convert a random array into a Max-Heap
void makeheap(int *arr, int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        restoredown(i, arr, n);
    }
}

// Moves a node down to its correct position (Heapify down)
void restoredown(int pos, int *arr, int n)
{
    int i, val;
    val = arr[pos];
    while (pos <= n / 2)
    {
        i = 2 * pos; // Left child
        // If right child exists and is larger, pick it
        if ((i < n) && (arr[i] < arr[i + 1]))
        {
            i++;
        }
        // If parent is already larger than the largest child, stop
        if (val >= arr[i]) break;
        
        arr[pos] = arr[i];
        pos = i;
    }
    arr[pos] = val;
}

// Requirement i: Add a new node
void add(int val, int *arr, int *n)
{
    (*n)++;
    arr[*n] = val;
    restoreup(*n, arr);
}

// Moves a node up to its correct position (Heapify up)
void restoreup(int i, int *arr)
{
    int val = arr[i];
    // Compare with parent (i/2). Sentinel at index 0 stops the loop.
    while (arr[i / 2] < val)
    {
        arr[i] = arr[i / 2];
        i = i / 2;
    }
    arr[i] = val;
}

// Requirement ii: Delete root node
int del_root(int *arr, int *n)
{
    if (*n < 1) return -1;
    int val = arr[1];      // Save the root
    arr[1] = arr[*n];      // Move last element to root
    (*n)--;                // Reduce size
    restoredown(1, arr, *n); // Restore heap property
    return val;
}
