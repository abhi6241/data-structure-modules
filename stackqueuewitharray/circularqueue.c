/*
    Write a C program to implement the “Circular Queue” using array and write the advantages?
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
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        q[rear] = e;
    }
    else if(((rear + 1) % MAX) == front)
    {
        printf("\nQueue is Full!");
        exit(0);
    }
    else
    {
        rear = (rear + 1) % MAX;
        q[rear] = e;
    }
}

que dequeue()
{
    que d;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue Underflow! (Empty)");
        exit(0);
    }
    else if(front == rear)
    {
        d = q[front];
        front = rear = -1;
        return d;
    }
    else
    {
        d = q[front];
        front = (front + 1) % MAX;
        return d;
    }
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