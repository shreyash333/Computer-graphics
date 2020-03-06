#include<stdio.h>
#include<conio.h>
#define size 5
int queue[size],front,rear;

int isfull()
{
	if(front==0 && rear==size)
		return 0;
	else
		return 1;
}

int isempty()
{
	if(rear==front==-1)
		return 0;
	else
		return 1;
}

void insert(int m)
{
	if(front=rear==-1)
	{
		front=0;
		rear=0;
	}
	queue[rear]=m;
	rear++;
}

int delete()
{
	int m;
	m=queue[front];
	front++;
	if(front==size-1)
	{
		front=-1;
		rear=-1;
	}
	return m;
}

int peek()
{
	int m;
	m=queue[front];
	return m;
}

void display()
{
	printf("\n Elements in the queue are ");
	int i=front;
	for(int i=front; i<rear; i++)
	{
		printf("\n %d",queue[i]);
	}
}


void main()
{
	int n,val;
	do
	{
	printf("\n **********************MAIN MENU***********************\n");
	printf("\n 1.INSERT \n 2.DELETE \n 3.PEEK \n 4.DISPLAY \n 5.EXIT \n");
	scanf("%d",&n);
	switch (n)
	{

		case 1:
			if(isfull()==1)
			{
				printf("\n Enter the number to be inserted in queue \n");
				scanf("%d",&val);
				insert(val);
				printf("\n %d is addes to queue ",val);
			}
			else
				printf("\n Queue is already full ");
			break;

		case 2:
			if(isempty()==1)
			{
				val=delete();
				printf("\n %d is deleted from the queue ",val);
			}
			else
				printf("\n Queue is already empty ");
			break;

		case 3:
			if(isempty()==1)
			{
				val=peek();
				printf("\n %d is the topmost value of queue ",val);
			}
			else
				printf("\n Queue is empty ");
			break;

		case 4:
			if(isempty()==1)
			{
				display();
			}
			else
				printf("\n Queue is empty ");
			break;

		case 5:
			break;

		default:
			printf("\n wrong choice entered ");
			break;
	}
	}while(n!=5);
}