/*
    Write a C program to implement “Queue” with enqueue() and
    dequeue() functions using array?
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct
{
    int key;
}que;

que q[MAX];

int front = -1, rear = -1;

void enqueue(que e)
{
    // 1. Check for Overflow using 'rear'
    if (rear == MAX - 1)
    {
        printf("\nQueue Overflow!");
        return;
    }
    
    // 2. If it's the very first element being added
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        // 3. Otherwise, just move the rear forward
        rear++;
    }

    // 4. Assign the element to the array 'q'
    q[rear] = e;
    printf("\nEnqueued: %d", e.key);
}

que dequeue()
{
    que d;
    // 1. Check if the queue is empty
    if (front == -1)
    {
        printf("\nQueue Underflow! (Empty)");
        d.key = -1; // Return a sentinel/error value
        return d;
    }

    // 2. Capture the data at the front
    d = q[front];

    // 3. Update pointers
    if (front == rear)
    {
        // This was the last element, reset the queue
        front = rear = -1;
    }
    else
    {
        // Move front to the next element
        front++;
    }

    return d;
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue is empty!");
        return;
    }

    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", q[i].key);
        if (i < rear) printf("<- ");
    }
    printf("\nFront is at index: %d, Rear is at index: %d\n", front, rear);
}

int main()
{
    int choice;
    que temp;

    while (1)
    {
        printf("\n--- Queue Operations ---");
        printf("\n1. Enqueue (Add)");
        printf("\n2. Dequeue (Remove)");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &temp.key);
                enqueue(temp);
                break;
            case 2:
                temp = dequeue();
                if (temp.key != -1)
                    printf("\nDequeued value: %d", temp.key);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}