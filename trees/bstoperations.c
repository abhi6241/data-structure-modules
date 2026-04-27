/*
    Consider the set of data values as 20, 17, 6, 8, 10, 7, 18, 13, 12, 5.
    i) Construct the Binary Search Tree(BST) by invoking
        insert(btnode**, int). and display the contents of the nodes by
    applying in-order traversal.
    ii) Delete a node which is specified by its data content, so that
        it is required to search for a specific data in the tree. If not
        present display “ Data to be deleted , Not found!”, if present
        delete the data. Verify all possibilities i.e. the node containing
        the data has no children, the node containing the data has
        exactly one child and the node containing the data has two
        Childs.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for the Binary Search Tree Node
typedef struct btnode 
{
    int data;
    struct btnode *left, *right;
} btnode;

// Function to create a new node
btnode* createNode(int val) 
{
    btnode* newNode = (btnode*)malloc(sizeof(btnode));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// i) Construct the BST by invoking insert(btnode**, int)
void insert(btnode** root, int val) 
{
    if (*root == NULL) 
    {
        *root = createNode(val);
    } 
    else if (val < (*root)->data) 
    {
        insert(&((*root)->left), val);
    } 
    else if (val > (*root)->data) 
    {
        insert(&((*root)->right), val);
    }
}

// In-order Traversal: Left -> Root -> Right
void inOrder(btnode* root) 
{
    if (root != NULL) 
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Helper function to find the minimum value node (In-order Successor)
btnode* findMin(btnode* root) 
{
    while (root != NULL && root->left != NULL) 
    {
        root = root->left;
    }
    return root;
}

// ii) Delete a node with search logic and case handling
btnode* deleteNode(btnode* root, int key, int* found) 
{
    if (root == NULL) 
    {
        return NULL;
    }

    if (key < root->data) 
    {
        root->left = deleteNode(root->left, key, found);
    } 
    else if (key > root->data) 
    {
        root->right = deleteNode(root->right, key, found);
    } 
    else 
    {
        // Node found!
        *found = 1;

        // Case: No child or exactly one child
        if (root->left == NULL) 
        {
            btnode* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            btnode* temp = root->left;
            free(root);
            return temp;
        }

        // Case: Node with two children
        // Get the in-order successor (smallest in the right subtree)
        btnode* temp = findMin(root->right);
        root->data = temp->data;
        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data, found);
    }
    return root;
}

int main() 
{
    btnode* root = NULL;
    int data[] = {20, 17, 6, 8, 10, 7, 18, 13, 12, 5};
    int n = sizeof(data) / sizeof(data[0]);

    // Constructing the BST
    for (int i = 0; i < n; i++) 
    {
        insert(&root, data[i]);
    }

    printf("In-order traversal of constructed BST:\n");
    inOrder(root);
    printf("\n\n");

    int val;
    while (1) 
    {
        printf("Enter data to delete (or -1 to exit): ");
        if (scanf("%d", &val) != 1 || val == -1) 
        {
            break;
        }

        int found = 0;
        root = deleteNode(root, val, &found);

        if (!found) 
        {
            printf("Data to be deleted, Not found!\n");
        } 
        else 
        {
            printf("Node %d deleted. New In-order traversal:\n", val);
            inOrder(root);
            printf("\n");
        }
        printf("----------------------------------\n");
    }

    return 0;
}
