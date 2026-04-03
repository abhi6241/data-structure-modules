/*
    Write a C program to implement “Stack” with push() and pop() functions
    using array?
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
    int key;
} stac;

stac s[MAX];
int top = -1;

void push(stac c)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow!");
        return;
    }
    // Correct: Assign the passed struct to the next top index
    s[++top] = c; 
    printf("\nPushed: %d", c.key);
}

stac pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!");
    }
    else
        return s[top--];
}

stac peek()
{
    if (top == -1)
    {
        printf("\nStack Underflow!");
    }
    else
        return s[top];
}

void display()
{
    if (top == -1)
    {
        printf("\nStack is Empty!");
        return;
    }
    printf("\nStack (Top to Bottom): ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", s[i].key);
        if (i > 0) printf("-> ");
    }
    printf("\n");
}

int main()
{
    int choice;
    stac temp;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &temp.key);
                push(temp);
                break;
            case 2:
                temp = pop();
                if (temp.key != -1) 
                    printf("\nPopped: %d", temp.key);
                break;
            case 3:
                temp = peek();
                if (temp.key != -1) 
                    printf("\nTop element: %d", temp.key);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Choice!");
        }
    }
    return 0;
}