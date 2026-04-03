#include <stdio.h>

// Function to remove duplicates
int removeDuplicates(int arr[], int n)
{
    int i, j, k;

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                // Shift elements to left
                for(k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--;   // Reduce size
                j--;   // Stay at same index
            }
        }
    }

    return n;  // Return new size
}

int main() 
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Call function
    n = removeDuplicates(arr, n);

    // Display result
    printf("Array after removing duplicates:\n");
    for(i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}