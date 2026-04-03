/*
    Write a C program to construct the polynomial using Single Linked List and
    display the same?
*/

#include <stdio.h>
#include <stdlib.h>

// Using typedef to define 'node' for cleaner code
typedef struct _node 
{
    int coeff;
    int exp;
    struct _node *next;
} node;

// Function to insert a term and maintain descending order of exponents
node* insertTerm(node *head, int c, int e) 
{
    if (c == 0) return head; // Do not add terms with zero coefficient

    node *newNode = (node*)malloc(sizeof(node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    // Case 1: List is empty OR new exponent is the highest
    if (head == NULL || e > head->exp) 
    {
        newNode->next = head;
        head = newNode;
    } 
    else 
    {
        node *temp = head;
        // Traverse to find the correct spot or an existing exponent
        while (temp->next != NULL && temp->next->exp >= e) 
        {
            temp = temp->next;
        }

        // Case 2: Exponent already exists, just add coefficients
        if (temp->exp == e) 
        {
            temp->coeff += c;
            free(newNode); 
        } 
        // Case 3: Insert in middle or at the end
        else 
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

// Function to display the polynomial in standard mathematical format
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
        // Handle the sign and coefficient
        printf("%d", temp->coeff);

        // Handle the variable and exponent
        if (temp->exp > 1) 
        {
            printf("x^%d", temp->exp);
        } 
        else if (temp->exp == 1) 
        {
            printf("x");
        }

        temp = temp->next;

        // Add formatting for the next term
        if (temp != NULL) 
        {
            if (temp->coeff >= 0) printf(" + ");
            else printf(" "); // Negative coefficients provide their own '-'
        }
    }
    printf("\n");
}

int main() 
{
    node *poly = NULL;
    int n, i, c, e;

    printf("--- Polynomial Construction ---\n");
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        printf("\nTerm %d - Enter Coeff and Exp: ", i + 1);
        scanf("%d %d", &c, &e);
        poly = insertTerm(poly, c, e);
    }

    printf("\nResultant Polynomial: ");
    display(poly);

    return 0;
}