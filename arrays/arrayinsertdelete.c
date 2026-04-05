/*
    Write a C program to read set of integer data values using one dimensional
    array and perform the following operations
    i) Insert a data value at specified location and display the new set of
    data values.
    ii) Delete a data value of array from specified location and display the
    resultant array.
*/

#include<stdio.h>

void insert(int a[], int *n, int place, int e) {
    for(int i = *n; i > place; i--)
        a[i] = a[i-1];
    a[place] = e;
    (*n)++;
}

void delete(int a[], int *n, int place) {
    for(int i = place; i < *n-1; i++)
        a[i] = a[i+1];
    (*n)--;
}

int main() {
    int n, e, place, a[100], choice;
    
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    
    printf("Initialize array: ");
    for(int i = 0; i < n; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    
    printf("\n1. Insert\n2. Delete\nEnter choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter place to insert: ");
            scanf("%d", &place); place--;
            if(place < 0 || place >= n+1 || n >= 99) {
                printf("Invalid position!\n");
                break;
            }
            printf("Enter element: ");
            scanf("%d", &e);
            insert(a, &n, place, e);
            break;
            
        case 2:
            printf("Enter place to delete: ");
            scanf("%d", &place); place--;
            if(place < 0 || place >= n) {
                printf("Invalid position!\n");
                break;
            }
            delete(a, &n, place);
            break;
    }
    
    printf("\nResultant: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}