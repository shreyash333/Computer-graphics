#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define size 5
int queue[size];
int front,rear;
front=-1;
rear=-1;

int isfull()
{
	if((front==0 && rear ==size-1) || rear==front-1)
		return 0;
	else
		return 1;
}

int isempty()
{
	if(front==-1 && rear==-1)
		return 0;
	else
		return 1;
}

void insert(int val)
{
	if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=val;
	}
	else if(rear==size-1)
	{
		rear=0;
		queue[rear]=val;
	}
	else
	{
		rear++;
		queue[rear]=val;
	}
}

int delete()
{
	int val;
	val=queue[front];
	if(front==size-1)
		front=0;
	else
		front++;
	return val;
}

int peek()
{
	int val;
	val=queue[front];
	return val;
}

void display()
{
	int i;
	if(front<rear)
	{
		for(i=front; i<=rear; i++)
		{
			printf("\n%d",queue[i]);
		}
	}
	else
	{
		for(i=front; i<=size-1; i++)
			printf("\n%d",queue[i]);
		for(i=0; i<=rear; i++)
			printf("\n%d",queue[i]);
	}
}

void main()
{

	int n,val;
	do
	{
	printf("\n********************MAIN MENU*********************");
	printf("\n 1.INSERT \n 2.DELETE \n 3.PEEK \n 4.DSPLAY \n 5.EXIT \n");
	scanf("%d",&n);
	switch (n)
	{
		case 1:
			if(isfull()==1)
			{
				printf("\n Enter the number to be inserted ");
				scanf("%d",&val);
				insert(val);
			}
			else
				printf("\n Queue is full ");
			break;

		case 2:
			if(isempty()==1)
			{
				val=delete();
				printf("\n %d is deleted from the queue ",val);
			}
			else
				printf("\n Queue is empty ");
			break;

		case 3:
			if(isempty()==1)
			{
				val=peek();
				printf("\n %d is the topmost element in queue ",val);
			}
			else
				printf("\n There is no topmost element ");
			break;

		case 4:
			if(isempty()==1)
			{
				printf("\n Elements in the queue are ...... ");
				display();
			}
			else
				printf("\n There is no element to display ");
			break;

		case 5:
			break;

		default:
			printf("\n Invalid choice ");
			break;
	}
	}while(n!=5);
}
