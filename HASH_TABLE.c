#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int hash[50];

void insert(int key,int size)
{
	int i,m;
	i=key%size;
	if(hash[i]==-1)
		hash[i]=key;
	else
	{
		m=1;
		while(hash[i]!=-1)
		{
			i=(key+m)%size;
			m++;
		}
		hash[i]=key;
	}
}

int search(int key, int size)
{
	int i,m,flag;
	flag=0;
	i=key%size;
	if(hash[i]==key)
	{
		flag=1;
	}
	else
	{
		m=1;
		int n;
		n=size-i;
		while(hash[i]!=key)
		{
			i=(key+m)%size;
			m++;
			if(m>n)
				break;
		}
		if(hash[i]==key)
		{
			flag=1;
		}
	}
	if(flag==1)
		return i;
	else
		return -1;
}

int delete(int i)
{
	hash[i]=-1;
}

void display(int size)
{
	int i;
	printf("\n Elements in hash tableb....");
	for(i=0; i<=size; i++)
	{
		printf("\n%d",hash[i]);
	}
}

void main()
{
	int key,size,n,i;
	printf("\n Enter the size of hash table ");
	scanf("%d",&size);
	for(i=0; i<=size; i++)
		hash[i]=-1;
	do
	{
	printf("\n***********************MAIN MENU***********************");
	printf("\n 1.INSERT \n 2.DELTE \n 3.SEARCH \n 4.DSIPLAY \n 5.EXIT\n");
	scanf("%d",&n);
	switch (n)
	{
		case 1:
			printf("\n Enter the element to be inserted ");
			scanf("%d",&key);
			insert(key,size);
			break;

		case 2:
			printf("\n Enter the element to be delete ");
			scanf("%d",&key);
			i=search(key,size);
			if(i==-1)
				printf("\n Entered number is not present in the hash table ");
			else
			{
				delete(i);
				printf("\n %d is deleted from hash table ",key);
			}
			break;

		case 3:
			printf("\n Enter the element which is to be search ");
			scanf("%d",&key);
			i=search(key,size);
			if(i==-1)
				printf("\n Entered number is not present in the hash table ");
			else
				printf("\n Entered element is at %d position in the hash table ",i+1);
			break;

		case 4:
			display(size);
			break;

		case 5:
			break;

		default:
			printf("\n Invalid choice ");
	}
	}while(n!=5);
}