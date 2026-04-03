/*
    Consider there are two Single Linked Lists with integer as a data value and the
    lengths of both the lists are same. Write a C program to perform the addition
    between two linked lists and display the resultant list.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node
typedef struct _node 
{
    int data;
    struct _node *next;
} node;

// Function to create a new node
node* createNode(int val) 
{
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) 
    {
        printf("\nMemory allocation failed!\n");
        exit(0);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to a list
void append(node **head, int val) 
{
    node *newNode = createNode(val);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to add two lists and return the result list
node* addLists(node *list1, node *list2) 
{
    node *resultHead = NULL;
    node *p1 = list1;
    node *p2 = list2;

    while (p1 != NULL && p2 != NULL) 
    {
        int sum = p1->data + p2->data;
        append(&resultHead, sum);
        p1 = p1->next;
        p2 = p2->next;
    }
    return resultHead;
}

// Function to display the list
void display(node *head) 
{
    node *temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    node *list1 = NULL;
    node *list2 = NULL;
    node *resultList = NULL;
    int n, val, i;

    printf("Enter the number of elements for the lists: ");
    scanf("%d", &n);

    printf("\nEnter elements for List 1:\n");
    for (i = 0; i < n; i++) 
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &val);
        append(&list1, val);
    }

    printf("\nEnter elements for List 2:\n");
    for (i = 0; i < n; i++) 
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &val);
        append(&list2, val);
    }

    printf("\nList 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    // Perform Addition
    resultList = addLists(list1, list2);

    printf("\nResultant List (List 1 + List 2): ");
    display(resultList);

    return 0;
}