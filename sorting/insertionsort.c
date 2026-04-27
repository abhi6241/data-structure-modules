#include <stdio.h>

// Function to perform Insertion Sort
void insertion_sort(int arr[], int n)
{
    int i, key, j;
    
    // Start from the second element (index 1)
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1] that are greater than key
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // Place the key in its correct sorted position
        arr[j + 1] = key;
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

    // Calling the insertion_sort function
    insertion_sort(data, n);

    printf("\nSorted array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
