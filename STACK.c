#include<stdio.h>
#include<conio.h>
#define size 5
int stack[size];
int top=-1;

int isfull()
{
	if(top!=size-1)
		return 1;
	else
		return 0;
}

int isempty()
{
	if(top!=0)
		return 1;
	else 
		return 0;
}

void push(int m)
{
	if(isfull()==1)
	{
		top++;
		stack[top]=m;
		printf("\n Entered number is pushed");
	}
	else
	printf("\n Stack is already full ");

}

int pop()
{
	if(isempty()==1)
	{
		int m;
		m=stack[top];
		top--;
		return m;
	}
	else
	{
		printf("\n Stack is already empty ");
		return -1;
	}
}

int peek()
{
	if(isempty()==1)
	{
		int m;
		m=stack[top];
		return m;
	}
	else
	{
		printf("\n No element in stack ");
		return -1;
	}
	
}

void display()
{
	 if(isempty()==1)
	 {
	 	printf("\n The elements of stack are ");
		 for(int i=top; i>=0; i--)
	 	{
	 		printf("\n%d ",stack[i]);
	 	}
	 }
	 else
	 printf("\n There is no element to display");
}

void main()
{
	int n,val;
	do
	{
	printf("\n ****************MAIN MENU******************\n");
	printf("\n 1.PUSH \n 2.POP \n 3.PEEK \n 4.DISPLAY \n 5.EXIT\n");
	scanf("%d",&n);
	switch (n)
	{
		case 1:
			if(isfull==1)
			{
			printf("\nEnter the number which as to push on to stack\n");
			scanf("%d",&val);
			push(val);
		    }
			
			break;

		case 2:
			val=pop();
			if(val!=-1)
				printf("\n %d is deleted from the stack",val);
			break;

		case 3:
			val=peek();
			if(val!=-1)
				printf("\n %d is the top most elemnent on stack",val);
			break;

		case 4:
			
			display();
			break;

		case 5:
			break;

		default:
			printf("\n Wrong choice entered ");
			break;

	}
	}while(n!=5);
}