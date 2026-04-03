/*
    Write a C program to implement “Stack” with push() and pop() functions using
    Single Linked List?
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} node;

node *top = NULL;

void push(int x)
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\nStack Overflow (Out of Memory)!");
        return;
    }
    temp->data = x;
    temp->next = top; // New node points to current top
    top = temp;       // Top moves to the new node
}

int pop(void)
{
    if (top == NULL)
    {
        printf("\nStack Underflow!");
        return -1;
    }
    node *temp = top;   // Hold the current top to free it
    int n = temp->data;
    top = top->next;    // Move top to the next node
    free(temp);         // Important: Free the memory!
    return n;
}

void display(void)
{
    node *p = top;
    if (p == NULL)
    {
        printf("\nStack is empty!");
        return;
    }
    printf("\nStack: ");
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main(void)
{
    int opt, b;
    while (1)
    {
        printf("\n1.Push  2.Pop  3.Display  4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &b);
                push(b);
                break;
            case 2:
                b = pop();
                if (b != -1) printf("\nPopped value is: %d", b);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nEnter Valid choice!");
        }
    }
    return 0;
}
