#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

#define size 100
char stack[size];
int top=-1;

int isfull()
{
	//printf("\nisfull working");
	if(top>=size)
		return 0;
	else
		return 1;
}

int isempty()
{
	//printf("\nisempty working");
	if(top<0)
		return 0;
	else
		return 1;
}

void push(char a)
{
	//printf("\npush working");
	if(isfull()==1)
	{
		top=top+2;
		stack[top]=a;
	}
	else
	{
		printf("\n Error occured due to long lenght of expression ");
	}
}

char pop()
{
	//printf("\npop working");
	if(isempty()==1)
	{
		char a;
		a=stack[top];
		top--;
		return a;
	}
	else
	{
		printf("\n Error occured due to short lenght of expression");
	}
}

int isoperator(char m)
{
	//printf("\nisoperator working");
	if( m=='(' || m==')' || m=='+' || m=='-' || m=='/' || m=='*' || m=='%' || m=='^' )
		return 1;
	else
		return 0;
}

int pref(char m)
{
	//printf("\npref working");
	if( m=='^')
		return 3;
	else if( m=='*' || m=='%' || m=='/' )
		return 2;
	else if( m=='+' || m=='-' )
		return 1;
	else
		return 0;
}

void infixtopostfix(char infix[size],char postfix[size])
{
	//printf("\ninfixtopostfix working");
	int i,j;
	char data,x;
	push('(');
	int count=0;
	while(infix[count]!='\0')
	{
		count++;
	}
	count++;
	infix[count]=')';
	i=0;
	j=0;
	data=infix[i];
	while(data!='\0')
	{
		if(data=='(')
		{
			//printf("\nif ) working");
			push(data);
		}
		else if(isdigit(data) || isalpha(data))
		{
			//printf("\nif digit working");
			postfix[j]=data;
			j++;
		}
		else if(isoperator(data)==1)
		{
			//printf("\nif operator working");
			x=pop();
			while(pref(x)>pref(data))
			{
				postfix[j]=x;
				j++;
				x=pop();
			}
			push(data);
		}
		else if(data==')')
		{
			//printf("\nif ) working");
			x=pop();
			while(x!='(')
			{
				postfix[j]=x;
				j++;
				x=pop();
			}
		}
		else
		{
			printf("\n Error occured due to invalid operator ");
			exit(0);
		}
		i++;
		data=infix[i];
	}
	
	while(j<i)
	{
		//printf("\nend working");
		x=pop();
		postfix[j]=x;
		j++;
	}
	postfix[j]='\0';
	
}

void main()
{
	char infix[size],postfix[size];
	printf("\n **************************************\n");
	printf("\n Enter the infix expression : ");
	gets(infix);
	
	printf("\n The postfix expression is : ");
	infixtopostfix(infix,postfix);
	puts(postfix);
	//printf("\ncompletely excueted ");
}