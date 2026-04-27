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

#define FALSE 0
#define TRUE 1

typedef struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
} bstnode;

// Function Prototypes
void insert(bstnode **sr, int num);
void inorder(bstnode *root);
void preorder(bstnode *root);
void postorder(bstnode *root);
void search(bstnode **r, int num, bstnode **par, bstnode **x, int *fo);
void del(bstnode **root, int num);

int main(void)
{
    bstnode *bt = NULL;
    // The specific data set from your question
    int data_set[] = {20, 17, 6, 8, 10, 7, 18, 13, 12, 5};
    int n = sizeof(data_set) / sizeof(data_set[0]);
    int de;

    // i) Construct the BST by invoking insert(btnode**, int)
    printf("Constructing BST with: 20, 17, 6, 8, 10, 7, 18, 13, 12, 5\n");
    for (int i = 0; i < n; i++)
    {
        insert(&bt, data_set[i]);
    }

    // Display contents by applying in-order traversal
    printf("\nIn-order traversal (Step i): ");
    inorder(bt);
    
    printf("\nPre-order traversal:  ");
    preorder(bt);
    
    printf("\nPost-order traversal: ");
    postorder(bt);
    printf("\n");

    // ii) Delete a node specified by its data content
    printf("\nEnter the data to delete: ");
    scanf("%d", &de);
    del(&bt, de);

    printf("\nIn-order traversal after deletion: ");
    inorder(bt);
    printf("\n");

    return 0;
}

// Requirement i: Insert function using double pointer
void insert(bstnode **sr, int num)
{
    if (*sr == NULL)
    {
        *sr = (bstnode *)malloc(sizeof(bstnode));
        (*sr)->left = NULL;
        (*sr)->data = num;
        (*sr)->right = NULL;
    }
    else
    {
        if (num < (*sr)->data)
        {
             insert(&((*sr)->left), num);
        }
        else
        {
            insert(&((*sr)->right), num);
        }
    }
}

void inorder(bstnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(bstnode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(bstnode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Requirement ii: Search for a specific data
void search(bstnode **r, int num, bstnode **par, bstnode **x, int *fo)
{
    bstnode *q = *r;
    *par = NULL;
    *fo = FALSE;
    while (q != NULL)
    {
        if (q->data == num)
        {
            *fo = TRUE;
            *x = q;
            return;
        }
        *par = q;
        if (q->data > num)
        {
            q = q->left;
        }
        else
        {
            q = q->right;
        }
    }
}

// Requirement ii: Delete data verifying all possibilities
void del(bstnode **root, int num)
{
    int found;
    bstnode *parent, *x, *xsucc;

    if (*root == NULL)
    {
        printf("\nTree is empty!");
        return;
    }

    parent = x = NULL;
    search(root, num, &parent, &x, &found);

    if (found == FALSE)
    {
        printf("\nData to be deleted, Not found!");
        return;
    }

    // Possibility 3: The node containing the data has two children
    if (x->left != NULL && x->right != NULL)
    {
        parent = x;
        xsucc = x->right;
        while (xsucc->left != NULL)
        {
            parent = xsucc;
            xsucc = xsucc->left;
        }
        x->data = xsucc->data;
        x = xsucc; // Pointer 'x' now targets the successor to be freed
    }

    // Possibility 1: The node containing the data has no children
    if (x->left == NULL && x->right == NULL)
    {
        if (parent == NULL)
        {
            *root = NULL; // Case: Root node
        }
        else if (parent->right == x)
        {
            parent->right = NULL;
        }
        else
        {
            parent->left = NULL;
        }
        free(x);
        return;
    }

    // Possibility 2a: The node containing the data has exactly one child (Right)
    if (x->left == NULL && x->right != NULL)
    {
        if (parent == NULL)
        {
            *root = x->right;
        }
        else if (parent->left == x)
        {
            parent->left = x->right;
        }
        else
        {
            parent->right = x->right;
        }
        free(x);
        return;
    }

    // Possibility 2b: The node containing the data has exactly one child (Left)
    if (x->left != NULL && x->right == NULL)
    {
        if (parent == NULL)
        {
            *root = x->left;
        }
        else if (parent->left == x)
        {
            parent->left = x->left;
        }
        else
        {
            parent->right = x->left;
        }
        free(x);
        return;
    }
}
