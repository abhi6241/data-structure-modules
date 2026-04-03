/*
    Write a C program to illustrate all the string handling functions?
    i) To insert a second string at the specified location of the first 
        string and display the resultant string.
    ii) To search for a specified character in a given string using
        strchr(), and pattern matching using strstr() function.
*/

#include <stdio.h>
#include <string.h>

#define MAX 60

void insertString(char str1[], char str2[], int pos)
{
    char result[MAX * 2] = {0}; // Initialize to zero to help with null-termination
    int len1 = strlen(str1);

    if (pos > len1) pos = len1; // Boundary check

    // Copy first part of str1
    strncpy(result, str1, pos);
    result[pos] = '\0'; 

    // Concatenate str2 and the rest of str1
    strcat(result, str2);
    strcat(result, str1 + pos);

    printf("\nResult: %s\n", result);
}

void search(char str[], char ch)
{
    char *ptr = strchr(str, ch);
    if (ptr)
    {
        // Calculate index by subtracting the base pointer from the found pointer
        printf("\n'%c' found at index %ld", ch, (long)(ptr - str));
    }
    else
    {
        printf("\n'%c' Not Found!", ch);
    }
}

void searchPattern(char str[], char pattern[])
{
    char *ptr = strstr(str, pattern);
    if (ptr)
    {
        // Calculate index similarly
        printf("\n\"%s\" found at index %ld", pattern, (long)(ptr - str));
    }
    else 
    {
        printf("\n\"%s\" Not Found!", pattern);
    }
}

int main() {
    char mainStr[MAX], subStr[MAX], pattern[MAX], ch;
    int choice, pos;

    while (1)
    {
        printf("\n--- String Operations Menu ---");
        printf("\n1. Insert String");
        printf("\n2. Search Character");
        printf("\n3. Search Pattern");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice)
        {
            case 1:
                printf("Enter main string: ");
                fgets(mainStr, MAX, stdin);
                mainStr[strcspn(mainStr, "\n")] = 0; // Remove newline

                printf("Enter string to insert: ");
                fgets(subStr, MAX, stdin);
                subStr[strcspn(subStr, "\n")] = 0;

                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                insertString(mainStr, subStr, pos);
                break;

            case 2:
                printf("Enter string: ");
                fgets(mainStr, MAX, stdin);
                mainStr[strcspn(mainStr, "\n")] = 0;

                printf("Enter character to search: ");
                scanf("%c", &ch);
                search(mainStr, ch);
                break;

            case 3:
                printf("Enter string: ");
                fgets(mainStr, MAX, stdin);
                mainStr[strcspn(mainStr, "\n")] = 0;

                printf("Enter pattern to search: ");
                fgets(pattern, MAX, stdin);
                pattern[strcspn(pattern, "\n")] = 0;
                searchPattern(mainStr, pattern);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!");
        }
        printf("\n");
    }
    return 0;
}