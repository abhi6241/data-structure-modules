/*
    Write a C program to read two strings, and check whether the second
    string is present in the first string or not using “Naïve Pattern
    Matching” algorithm? If present return the first occurrence, otherwise
    return -1?
*/

#include<stdio.h>
#include<string.h>

int findPattern(char *str, char *pat)
{
    int i, j;
    int strLen = strlen(str);
    int patLen = strlen(pat);
    
    // If pattern is longer than string, it's impossible to find
    if (patLen > strLen) return -1;

    int lastP = patLen - 1;
    int start = 0;
    int endmatch = lastP;

    while (endmatch < strLen)
    {
        // Optimization: Only check the whole pattern if the last characters match
        if (str[endmatch] == pat[lastP])
        {
            // Check the whole pattern from the current 'start'
            for (j = 0, i = start; j <= lastP; i++, j++)
            {
                if (str[i] != pat[j])
                    break;
            }

            // If j reached patLen, it means every character matched
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

    printf("--- Pattern Finder ---\n");

    // Using fgets to allow spaces in the text
    printf("Enter the main string: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove trailing newline

    printf("Enter the pattern to find: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = 0; // Remove trailing newline

    // Call the function
    index = findPattern(text, pattern);

    // Interpret the result
    if (index != -1)
    {
        printf("\nSuccess! Pattern found starting at index: %d\n", index);
        printf("Text:    %s\n", text);
        
        // Visual pointer to the match
        printf("Match:   ");
        for(int k = 0; k < index; k++) printf(" ");
        printf("^\n");
    }
    else
    {
        printf("\nPattern not found in the given string.\n");
    }

    return 0;
}
