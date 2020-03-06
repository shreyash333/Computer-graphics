#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void main()
{
	int size,i,j;
	printf("\n Enter the size of array ");
	scanf("%d",&size);
	int array[size];
	printf("\n Enter the element of the array ");
	for(i=0; i<size; i++)
		scanf("%d",&array[i]);
	printf("\n Enetr the element which is to be searched ");
	int key;
	scanf("%d",&key);
	for(i=0; i<size; i++)
	{
		for(j=0; j<size-i-1; j++)
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
	int mid,beg,end;
	beg=0;
	end=size-1;
	int flag=0;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(array[mid]==key)
		{
			printf("\n Element found at %d position ",mid+1);
			flag=1;
			break;
		}
		else if(array[mid]<key)
			beg=mid+1;
		else
			end=mid-1;
	}
	if(flag==0)
		printf("\n Element not found ");
}