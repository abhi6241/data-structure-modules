/*
    Write a C program to implement the “Double Linked List” with single integer as a
    data member and perform the following operations, To
    i) Create head node.
    ii) Add node at the end of the list.
    iii) Insert node at the specified location of the list.
    iv) Delete the node at the specified location of the list.
    v) Add node as a first node of the list.
    vi) Display the data values of the list in forward order.
    vii) Display the data values of the list in reverse order.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a Doubly Linked List Node
typedef struct _node
{
    int data;
    struct _node *prev;
    struct _node *next;
} node;

node *head = NULL;

// Function Prototypes
void insertAtHead(int val);
void addAtEnd(int val);
void insertAtPos(int val, int pos);
void deleteAtPos(int pos);
void displayForward();
void displayReverse();

int main() 
{
    int choice, val, pos;

    while (1) 
    {
        printf("\n--- Doubly Linked List Menu ---");
        printf("\n1. Create/Insert Head\n2. Add at End\n3. Insert at Position");
        printf("\n4. Delete at Position\n5. Display Forward\n6. Display Reverse\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value for Head: ");
                scanf("%d", &val);
                insertAtHead(val);
                break;
            case 2:
                printf("Enter value for End: ");
                scanf("%d", &val);
                addAtEnd(val);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insertAtPos(val, pos);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayReverse();
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}

// i & v) Insert Node as First / Create Head
void insertAtHead(int val) 
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->prev = NULL;
    temp->next = head;

    if (head != NULL) 
    {
        head->prev = temp;
    }
    head = temp;
    printf("\nNode with %d inserted at head.\n", val);
}

// ii) Add node at the end
void addAtEnd(int val) 
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;

    if (head == NULL) 
    {
        temp->prev = NULL;
        head = temp;
        return;
    }

    node *p = head;
    while (p->next != NULL) 
    {
        p = p->next;
    }

    p->next = temp;
    temp->prev = p;
    printf("\nNode with %d added at the end.\n", val);
}

// iii) Insert node at specified location
void insertAtPos(int val, int pos) 
{
    if (pos == 1) 
    {
        insertAtHead(val);
        return;
    }

    node *p = head;
    for (int i = 1; i < pos - 1 && p != NULL; i++) 
    {
        p = p->next;
    }

    if (p == NULL) 
    {
        printf("\nPosition out of bounds!\n");
    } 
    else 
    {
        node *temp = (node*)malloc(sizeof(node));
        temp->data = val;
        temp->next = p->next;
        temp->prev = p;

        if (p->next != NULL) 
        {
            p->next->prev = temp;
        }
        p->next = temp;
        printf("\nNode with %d inserted at position %d.\n", val, pos);
    }
}

// iv) Delete node at specified location
void deleteAtPos(int pos) 
{
    if (head == NULL) 
    {
        printf("\nList is empty!\n");
        return;
    }

    node *p = head;

    if (pos == 1) 
    {
        head = head->next;
        if (head != NULL) 
        {
            head->prev = NULL;
        }
        free(p);
        printf("\nHead node deleted.\n");
        return;
    }

    for (int i = 1; i < pos && p != NULL; i++) 
    {
        p = p->next;
    }

    if (p == NULL) 
    {
        printf("\nPosition out of bounds!\n");
    } 
    else 
    {
        p->prev->next = p->next;
        if (p->next != NULL) 
        {
            p->next->prev = p->prev;
        }
        free(p);
        printf("\nNode at position %d deleted.\n", pos);
    }
}

// vi) Display Forward
void displayForward() 
{
    node *p = head;
    if (p == NULL) 
    {
        printf("\nList is empty!\n");
        return;
    }
    printf("\nForward: ");
    while (p != NULL) 
    {
        printf("%d <-> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// vii) Display Reverse
void displayReverse() 
{
    node *p = head;
    if (p == NULL) 
    {
        printf("\nList is empty!\n");
        return;
    }

    // Go to the last node
    while (p->next != NULL) 
    {
        p = p->next;
    }

    printf("\nReverse: ");
    while (p != NULL) 
    {
        printf("%d <-> ", p->data);
        p = p->prev; // Use the prev pointer
    }
    printf("NULL\n");
}