#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void main()
{
	int n,i,j;
	printf("\n Enter the size of array ");
	scanf("%d",&n);
	int array[n];
	printf("\n Enter the elements of array ");
	for(i=0; i<n; i++)
		scanf("%d",&array[i]);
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(array[j]>array[j+1])
			{
				int temp;
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	printf("\n sorted Array is ....");
	for(i=0; i<n; i++)
		printf("\n%d",array[i]);
}