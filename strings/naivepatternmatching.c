/*
    Write a C program to read two strings, and check whether the second
    string is present in the first string or not using “Naïve Pattern
    Matching” algorithm? If present return the first occurrence, otherwise
    return -1?
*/

#include <stdio.h>
#include <string.h>

int findPattern(char *str, char *pat)
{
    int i, j;
    int strLen = strlen(str);
    int patLen = strlen(pat);
    
    if (patLen > strLen) return -1;

    int lastP = patLen - 1;
    int start = 0;
    int endmatch = lastP;

    while (endmatch < strLen)
    {
        // Restored your specific logic: check last character first
        if (str[endmatch] == pat[lastP])
        {
            for (j = 0, i = start; j <= lastP; i++, j++)
            {
                if (str[i] != pat[j])
                    break;
            }

            if (j == patLen)
                return start;
        }

        start++; 
        endmatch++;
    }

    return -1;
}

int main()
{
    char text[100];
    char pattern[50];
    int index;

    // main uses scanf instead of fgets/strcspn to avoid string.h calls
    printf("Enter the main string: ");
    scanf(" %[^\n]", text); 

    printf("Enter the pattern: ");
    scanf(" %[^\n]", pattern);

    index = findPattern(text, pattern);

    if (index != -1)
        printf("\nSuccess! Pattern found at index: %d\n", index);
    else
        printf("\nPattern not found.\n");

    return 0;
}