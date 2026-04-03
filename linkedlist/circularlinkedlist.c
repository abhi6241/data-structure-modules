/*
    Write a C program to implement Circular Single Linked List for integer data
    values and perform various operations.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node 
{
    int data;
    struct _node *next;
} node;

node *head = NULL;

// --- INSERTION OPERATIONS ---

void insertAtHead(int val) 
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;

    if (head == NULL) 
    {
        head = newNode;
        newNode->next = head;
    } 
    else 
    {
        node *temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insertAtEnd(int val) 
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;

    if (head == NULL) 
    {
        head = newNode;
        newNode->next = head;
    } 
    else 
    {
        node *temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAtPos(int val, int pos) 
{
    if (pos == 1) { insertAtHead(val); return; }
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) temp = temp->next;
    
    newNode->next = temp->next;
    temp->next = newNode;
}

// --- DELETION OPERATIONS ---

void deleteAtHead() 
{
    if (head == NULL) return;
    node *temp = head;
    if (head->next == head) 
    {
        head = NULL;
        free(temp);
    } 
    else 
    {
        node *last = head;
        while (last->next != head) last = last->next;
        head = head->next;
        last->next = head;
        free(temp);
    }
}

void deleteAtEnd() 
{
    if (head == NULL) return;
    node *temp = head;
    if (head->next == head) 
    {
        head = NULL;
        free(temp);
    } 
    else 
    {
        node *prev = NULL;
        while (temp->next != head) 
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
}

void deleteAtPos(int pos) 
{
    if (pos == 1) { deleteAtHead(); return; }
    node *temp = head, *prev = NULL;
    for (int i = 1; i < pos && temp->next != head; i++) 
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

// --- UTILITY OPERATIONS ---

void search(int val) 
{
    if (head == NULL) return;
    node *temp = head;
    int pos = 1;
    do 
    {
        if (temp->data == val) 
        {
            printf("\nValue %d found at position %d", val, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("\nValue not found.");
}

void sortAscending() 
{
    if (head == NULL) return;
    node *i, *j;
    int tempVal;
    for (i = head; i->next != head; i = i->next) 
    {
        for (j = i->next; j != head; j = j->next) 
        {
            if (i->data > j->data) 
            {
                tempVal = i->data;
                i->data = j->data;
                j->data = tempVal;
            }
        }
    }
    printf("\nList sorted in ascending order.");
}

void display() 
{
    if (head == NULL) 
    {
        printf("\nList is empty!");
        return;
    }
    node *temp = head;
    printf("\nCircular List: ");
    do 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head: %d)\n", head->data);
}

int main() 
{
    int choice, val, pos;

    while (1) 
    {
        printf("\n--- Full Circular SLL Menu ---");
        printf("\n1. Insert Head\t2. Insert End\t3. Insert Pos");
        printf("\n4. Delete Head\t5. Delete End\t6. Delete Pos");
        printf("\n7. Search\t8. Sort (Asc)\t9. Display\t10. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: printf("Enter value: "); scanf("%d", &val); insertAtHead(val); break;
            case 2: printf("Enter value: "); scanf("%d", &val); insertAtEnd(val); break;
            case 3: printf("Enter value & pos: "); scanf("%d %d", &val, &pos); insertAtPos(val, pos); break;
            case 4: deleteAtHead(); break;
            case 5: deleteAtEnd(); break;
            case 6: printf("Enter pos: "); scanf("%d", &pos); deleteAtPos(pos); break;
            case 7: printf("Search for: "); scanf("%d", &val); search(val); break;
            case 8: sortAscending(); break;
            case 9: display(); break;
            case 10: exit(0);
            default: printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}
