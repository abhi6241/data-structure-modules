/*
    Write C program to display the Magic square matrix of size n by n, (n is odd).
*/

#include<stdio.h>

int main() {
    int a[10][10] = {0};
    int n, i, j, r, c, r1, c1;

    printf("Enter an odd number for the size: ");
    scanf("%d", &n);

    // Initial position
    r = 0; 
    c = n / 2;
    a[r][c] = 1;

    for (i = 2; i <= n * n; i++) {
        r1 = r; 
        c1 = c;
        
        // Try moving up and left
        r--; 
        c--;
        
        // Wrap around boundaries
        if (r < 0) r = n - 1;
        if (c < 0) c = n - 1;
        
        // Rule: If cell is filled, move down from the PREVIOUS position
        if (a[r][c] != 0) {
            r = r1 + 1;
            c = c1;
            // Ensure the 'move down' doesn't exceed matrix rows
            if (r >= n) r = 0; 
        }
        
        a[r][c] = i;
    }

    // Display the Magic Square
    printf("\nMagic Square of size %d:\n", n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}