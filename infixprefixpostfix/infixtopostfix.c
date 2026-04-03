/*
    Write a C program to convert infix expression into postfix expression using stack?
*/

#include <stdio.h>
#include <string.h>

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

void infixtopostfix(char *infix, char *postfix)
{
	char s[100];
	int top = -1, j = 0, i;
	for(i = 0; infix[i] != '\0'; i++)
	{
		if((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a'&& infix[i] <= 'z'))
		{
			//printf("%c",infix[i]);
			postfix[j++]=infix[i];
		}
		else if(infix[i] == '(')
		{
			s[++top]='(';
		}
		else if(infix[i] == ')')
		{
			while(s[top] != '(')
			{
				//printf("%c",s[top--]);
				postfix[j++] = s[top--];
			}
			top--;
		}
		else
		{
			while(top != -1 && priority(s[top]) >= priority(infix[i]))
			{
				//printf("%c",s[top--]);
				postfix[j++] = s[top--];
			}
			s[++top] = infix[i];
		}
	}
	while(top != -1)
	{
		//printf("%c",s[top--]);
		postfix[j++] = s[top--];
	}
	postfix[j] = '\0';
}


void reverse(char *str, char *rev)
{
    int n = strlen(str);
    int i, j = 0;
    for (i = n - 1; i >= 0; i--)
    {
        if (str[i] == '(')
            rev[j++] = ')';
        else if (str[i] == ')')
            rev[j++] = '(';
        else
            rev[j++] = str[i];
    }
    rev[j] = '\0';
}

int main(void) {
    char infix[100], postfix[100], infixRev[100], intermediatePostfix[100], prefix[100];

    printf("Enter the infix expression: ");
    // Note: gets() is unsafe; using fgets or just keeping it for your exercise
    scanf("%s", infix); 

    // 1. Postfix Conversion
    infixtopostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    // 2. Prefix Conversion
    // Step A: Reverse Infix
    reverse(infix, infixRev);
    
    // Step B: Convert Reversed Infix to Postfix
    infixtopostfix(infixRev, intermediatePostfix);
    
    // Step C: Reverse the result to get Prefix
    reverse(intermediatePostfix, prefix);
    
    printf("Prefix:  %s\n", prefix);

    return 0;
}