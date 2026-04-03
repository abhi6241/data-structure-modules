/*
    Write a C program to implement the “Single Linked List” with single integer as a
    data member and perform the following operations, To
    i) Create head node.
    ii) Add node at the end of the list.
    iii) Insert node at the specified location of the list.
    iv) Insert node as head.
    v) Delete the node at the specified location of the list.
    vi) Delete the last node of the list.
    vii) Delete the head node.
    viii) Arrange the data values of the SLL in ascending order.
    ix) Display the data values of the list.
    x) Search for the given data value if the data values are in improper order.
    xi) To display data values in Reverse order.
    xii) Reverse the List.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} node;

node *head = NULL;

void insertAtHead(int val)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = head;
    head = temp;
}

void createHead(int val)
{
    if (head != NULL) printf("Head already exists!");
    else insertAtHead(val);
}

// ii) Add node at the end
void addAtEnd(int val)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    node *p = head;
    while (p->next != NULL) p = p->next;
    p->next = temp;
}

// iii) Insert at specified location (1-based index)
void insertAtPos(int val, int pos)
{
    if (pos == 1) { insertAtHead(val); return; }
    node *temp = (node*)malloc(sizeof(node));
    temp->data = val;
    node *p = head;
    for (int i = 1; i < pos - 1 && p != NULL; i++) p = p->next;
    if (p == NULL) { printf("Position out of bounds!"); free(temp); }
    else
    {
        temp->next = p->next;
        p->next = temp;
    }
}

// vii) Delete head
void deleteHead()
{
    if (head == NULL) return;
    node *temp = head;
    head = head->next;
    free(temp);
}

// vi) Delete last node
void deleteLast()
{
    if (head == NULL) return;
    if (head->next == NULL) { free(head); head = NULL; return; }
    node *p = head;
    while (p->next->next != NULL) p = p->next;
    free(p->next);
    p->next = NULL;
}

// v) Delete at specified position
void deleteAtPos(int pos)
{
    if (pos == 1) { deleteHead(); return; }
    node *p = head;
    for (int i = 1; i < pos - 1 && p != NULL; i++) p = p->next;
    if (p == NULL || p->next == NULL) printf("Position out of bounds!");
    else
    {
        node *temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}

// viii) Sort in Ascending order (Bubble Sort on data)
void sortAscending()
{
    if (head == NULL) return;
    node *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// ix) Display
void display()
{
    node *p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// x) Search
void search(int val)
{
    node *p = head;
    int pos = 1;
    while (p != NULL)
    {
        if (p->data == val) { printf("Found %d at position %d\n", val, pos); return; }
        p = p->next; pos++;
    }
    printf("Value not found.\n");
}

// xi) Display in Reverse order (using Recursion)
void displayReverse(node *p)
{
    if (p == NULL) return;
    displayReverse(p->next);
    printf("%d -> ", p->data);
}

// xii) Reverse the list (Actual pointer reversal)
void reverseList()
{
    node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("List Reversed.\n");
}

int main()
{
    int choice, val, pos;

    while (1)
    {
        printf("\n--- SLL Menu ---");
        printf("\n1. Create Head\t2. Add End\t3. Insert Pos\t4. Insert Head");
        printf("\n5. Delete Pos\t6. Delete Last\t7. Delete Head\t8. Sort");
        printf("\n9. Display\t10. Search\t11. Print Rev\t12. Reverse List\t13. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: printf("Enter value: "); scanf("%d", &val); createHead(val); break;
            case 2: printf("Enter value: "); scanf("%d", &val); addAtEnd(val); break;
            case 3: printf("Enter value & pos: "); scanf("%d %d", &val, &pos); insertAtPos(val, pos); break;
            case 4: printf("Enter value: "); scanf("%d", &val); insertAtHead(val); break;
            case 5: printf("Enter pos to delete: "); scanf("%d", &pos); deleteAtPos(pos); break;
            case 6: deleteLast(); break;
            case 7: deleteHead(); break;
            case 8: sortAscending(); break;
            case 9: display(); break;
            case 10: printf("Search value: "); scanf("%d", &val); search(val); break;
            case 11: printf("Reverse Display: "); displayReverse(head); printf("NULL\n"); break;
            case 12: reverseList(); break;
            case 13: exit(0);
            default: printf("Invalid Choice!");
        }
    }
    return 0;
}
