/*
    Write a C program to construct the Binary tree using array, and display
    the content of nodes by traversing the Binary tree in pre-order, post-order
    and in- order.
*/

#include <stdio.h>

// Use -1 to represent a NULL/Empty node
int tree[100]; 

void inorder(int index, int total_nodes)
{
    if (index < total_nodes && tree[index] != -1)
    {
        inorder(2 * index + 1, total_nodes); // Left child
        printf("%d ", tree[index]);          // Root
        inorder(2 * index + 2, total_nodes); // Right child
    }
}

void preorder(int index, int total_nodes)
{
    if (index < total_nodes && tree[index] != -1)
    {
        printf("%d ", tree[index]);
        preorder(2 * index + 1, total_nodes);
        preorder(2 * index + 2, total_nodes);
    }
}

void postorder(int index, int total_nodes)
{
    if (index < total_nodes && tree[index] != -1) 
    {
        postorder(2 * index + 1, total_nodes);
        postorder(2 * index + 2, total_nodes);
        printf("%d ", tree[index]);
    }
}

int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values (use -1 for empty): \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tree[i]);
    }

    printf("\nIn-order: "); inorder(0, n);
    printf("\nPre-order: "); preorder(0, n);
    printf("\nPost-order: "); postorder(0, n);
    
    return 0;
}
