/* 
    Write a C program to Define an Abstract Data Type (ADT) polynomial using
    nested structures concept and implement the following functions
    i) Initializing all terms of the polynomial as zeros
    ii) Appending each term of the polynomial
    iii) To perform addition between two polynomials
    iv) To display the polynomial 
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a Polynomial Term
typedef struct _node 
{
    int coeff;
    int exp;
    struct _node *next;
} node;

// Function to create a new node (Similar to polyAppend)
node* createNode(int c, int e) 
{
    if (c == 0) return NULL; // Ignore terms with zero coefficient
    node *newNode = (node*)malloc(sizeof(node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Function to append a term to the end of a list
void append(node **head, int c, int e) 
{
    node *newNode = createNode(c, e);
    if (newNode == NULL) return;

    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        node *temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// The "Merge" Addition Logic (Following your array method)
node* add(node *p1, node *p2) 
{
    node *p3 = NULL;
    node *i = p1; // Acts like your index 'i'
    node *j = p2; // Acts like your index 'j'

    while (i != NULL && j != NULL) 
    {
        if (i->exp == j->exp) 
        {
            append(&p3, i->coeff + j->coeff, i->exp);
            i = i->next; 
            j = j->next;
        } 
        else if (i->exp > j->exp) 
        {
            append(&p3, i->coeff, i->exp);
            i = i->next;
        } 
        else 
        {
            append(&p3, j->coeff, j->exp);
            j = j->next;
        }
    }

    // Append remaining terms from p1
    while (i != NULL) 
    {
        append(&p3, i->coeff, i->exp);
        i = i->next;
    }

    // Append remaining terms from p2
    while (j != NULL) 
    {
        append(&p3, j->coeff, j->exp);
        j = j->next;
    }

    return p3;
}

void display(node *head) 
{
    if (head == NULL) 
    {
        printf("0\n");
        return;
    }
    node *temp = head;
    while (temp != NULL) 
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL && temp->coeff > 0) printf(" + ");
        else if (temp != NULL) printf(" ");
    }
    printf("\n");
}

int main() 
{
    node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    int n, i, c, e;

    // Input for Poly 1
    printf("Enter number of terms for Poly 1: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        printf("Term %d (coeff exp): ", i + 1);
        scanf("%d %d", &c, &e);
        append(&poly1, c, e);
    }

    // Input for Poly 2
    printf("Enter number of terms for Poly 2: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        printf("Term %d (coeff exp): ", i + 1);
        scanf("%d %d", &c, &e);
        append(&poly2, c, e);
    }

    printf("\nPoly 1: "); display(poly1);
    printf("Poly 2: "); display(poly2);

    poly3 = add(poly1, poly2);

    printf("Result: "); display(poly3);

    return 0;
}