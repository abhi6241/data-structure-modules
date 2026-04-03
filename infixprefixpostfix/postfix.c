/*
    Write a C program to evaluate the postfix expression?
*/

#include<stdio.h>
int main(void)
{
	char postfix[100];
	int s[100], top=-1,i,x,y,n;
	printf("\nEnter the postfix rxpression to evaluate:");
	gets(postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		if((postfix[i]>='A'&&postfix[i]<='Z')||(postfix[i]>='a'&&postfix[i]<='z'))
		{
			printf("\nEnter the data value of the operand %c:",postfix[i]);
			scanf("%d",&n);
			s[++top]=n;
		}
		else if(postfix[i]=='+')
		{
			y=s[top--];
			x=s[top--];
			s[++top]=x+y;
		}
		else if(postfix[i]=='-')
		{
			y=s[top--];
			x=s[top--];
			s[++top]=x-y;
		}
		else if(postfix[i]=='*')
		{
			y=s[top--];
			x=s[top--];
			s[++top]=x*y;
		}
		else if(postfix[i]=='/')
		{
			y=s[top--];
			x=s[top--];
			s[++top]=x/y;
		}
		else
		{
			y=s[top--];
			x=s[top--];
			s[++top]=x%y;
		}
	}
	printf("\nThe result of the Postfix expression is %d",s[top]);
	return 0;
}
