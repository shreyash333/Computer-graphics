#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>

#define size 50
int stack[size];
int top=-1;

int isfull()
{
	//printf("\n isfull working");
	if(top==size)
		return 0;
	else
		return 1;
}

int isempty()
{
	//printf("\n isempty working");
	if(top==-1)
		return 0;
	else
		return 1;
}

int isoperator(char m)
{
	//printf("\n isoperator working");
	if( m=='(' || m==')' || m=='+' || m=='-' || m=='/' || m=='*' || m=='%' || m=='^' )
		return 1;
	else
		return 0;
}

void push(char a)
{
	//printf("\n push working");
	if(isfull()==1)
	{
		int x;
		char *ptr;
		ptr=&a;
		x=atoi(ptr);
		top++;
		stack[top]=x;
	}
	else
		printf("\n Stack is full ");
}

int pop()
{
	//printf("\n pop working");
	if(isempty()==1)
	{
		int val;
		val=stack[top];
		top--;
		return val;
	}
	else
		printf("\n Stack is empty ");
}

int operation(char s)
{
	//printf("\n operation working");
	int result;
	int x1=pop();
	int x2=pop();
	if(s=='+')
		result=x2+x1;
	else if(s=='-')
		result=x2-x1;
	else if(s=='*')
		result=x2*x1;
	else if(s=='/')
		result=x2/x1;
	else if(s=='%')
		result=x2%x1;
	else if(s=='^')
	{
		int multi=1;
		while(x1!=0)
		{
			multi=multi*x2;
			x1--;
		}
		result=multi;
	}
	else
		printf("\n Invalid operator used ");
	return result;
}

int eval(char post[size])
{
	//printf("\n eval working");
	int i,j;
	i=0;
	j=0;
	char data,x1,x2;
	int result;
	data=post[i];
	while(data!='\0')
	{
		if(isdigit(data))
		{
			//printf("\n ifdigit working");
			push(data);
		}
		else if(isoperator(data))
		{
			//printf("\n ifoperator working");
			result=operation(data);
			top++;
			stack[top]=result;
		}
		else if(isalpha(data))
		{
			printf("\n Alphabets cannot be evaluate ");
		}
		else
		{
			printf("\n some invalid character is entered ");
		}
		i++;
		data=post[i];
	}
	return result;
}



void main()
{
	char postfix[size];
	int result;
	printf("\nEnter the postfix expression : ");
	gets(postfix);
	result=eval(postfix);
	printf("\n The aswer of postfix expression is %d",result);
}