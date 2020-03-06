#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define size 50
int array[size];

void sort(int array[size],int n)
{
	int i,j,temp;
	for(i=1; i<n; i++)
	{
		temp=array[i];
		j=i-1;
		while(temp<array[j])
		{
			array[j+1]=array[j];
			j=j-1;
		}
		array[j+1]=temp;
	}
}

void main()
{
	int n,i,j,temp;
	printf("\n Enter the size of array ");
	scanf("%d",&n);
	printf("\n Enter the elements of array ");
	for(i=0; i<n; i++)
		scanf("%d",&array[i]);
	sort(array,n);
	printf("\n sorted Array is ....");
	for(i=0; i<n; i++)
		printf("\n%d",array[i]);
}