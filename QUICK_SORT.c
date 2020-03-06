#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int divide(int array[50],int beg,int end)
{
	int left,right,temp,loc;
	loc=left=beg;
	right=end;
	int flag=0;
	while(flag!=1)
	{
			while(array[left]<array[right] && loc!=right)
			{
				right--;
			}
			if(left==right)
				flag=1;
			else
			{
				temp=array[left];
				array[left]=array[right];
				array[right]=temp;
				loc=right;
			}
		if(flag!=1)
		{
			while(array[left]<array[right] && loc!=left)
			{
				left++;
			}
			if(left==right)
				flag=1;
			else
			{
				temp=array[left];
				array[left]=array[right];
				array[right]=temp;
				loc=left;
			}
		}
	}
	return loc;
}

void sort(int array[50],int beg,int end)
{
	int loc;
	if(beg<end)
	{
	loc=divide(array,beg,end);
	sort(array,beg,loc-1);
	sort(array,loc+1,end);
	}
}

void main()
{
	int n,i;
	printf("\n Enter the size of array ");
	scanf("%d",&n);
	int array[n];
	printf("\n Enter the elements of array ");
	for(i=0; i<n; i++)
		scanf("%d",&array[i]);
	sort(array,0,n-1);
	printf("\n sorted Array is ....");
	for(i=0; i<n; i++)
		printf("\n%d",array[i]);
}