/*
    Write a C program to implement “Queue” with enqueue() and dequeue()
    functions using Single Linked List?
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node 
{
    int data;
    struct _node *next;
} node;

node *front = NULL;
node *rear = NULL;

void enqueue(int val) 
{
    node *temp = (node*)malloc(sizeof(node));
    if (temp == NULL) 
    {
        printf("\nQueue Overflow! (Out of Memory)\n");
        return;
    }

    temp->data = val;
    temp->next = NULL;

    if (front == NULL) 
    {
        // First element in the queue
        front = rear = temp;
    } 
    else 
    {
        // Link the new node to the end and move rear
        rear->next = temp;
        rear = temp;
    }
    printf("\nValue %d enqueued successfully.\n", val);
}

int dequeue() 
{
    if (front == NULL) 
    {
        printf("\nQueue Underflow! (Nothing to remove)\n");
        return -1;
    }

    node *temp = front;
    int val = temp->data;

    // Move front pointer forward
    front = front->next;

    // If queue becomes empty, reset rear to NULL
    if (front == NULL) 
    {
        rear = NULL;
    }

    free(temp);
    return val;
}

void display() 
{
    if (front == NULL) 
    {
        printf("\nQueue is currently empty!\n");
        return;
    }

    node *p = front;
    printf("\nQueue Status: ");
    while (p != NULL) 
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() 
{
    int choice, val;

    while (1) 
    {
        printf("\n--- Linked Queue Menu ---");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter choice: ");
        
        if (scanf("%d", &choice) != 1) break;

        switch (choice) 
        {
            case 1:
            {
                printf("Enter integer to add: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            }
            case 2:
            {
                val = dequeue();
                if (val != -1) 
                {
                    printf("\nRemoved value: %d\n", val);
                }
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\nExiting program...\n");
                exit(0);
            }
            default:
            {
                printf("\nInvalid selection. Try again.\n");
            }
        }
    }
    return 0;
}