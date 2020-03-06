//Program to implement Singly Linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head;

int create()
{
	struct node *new ,*temp;
	new=(struct node *)malloc(sizeof(struct node));
	printf("Enter data to be entered");
	scanf("%d",&new->data);
	new->next=NULL;
	
	if(head == NULL)
	{
		head=new;
		return 1;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new;
		//temp=new;
	}
	
	
}
int search(int x)
{
	struct node *temp;
	int p,flag=0;
	
	if(head == NULL)
	{
		printf("linked list is empty");
		return 1;
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			p=temp->data;
			if(x == p)
			{
				flag=1;
				break;
			}	
			temp=temp->next;
		
		}
		
		if(flag == 1)
			printf("element found");
		else
			printf("element not found");
		
	}
	
	
}

int deleteat(int pos)
{
	struct node *temp,*ptr;
	int i;
	
	if(pos==1)
	{
		temp=head;
		head=head->next;
		free(temp);
		
	}
	else
	{	
		
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		ptr=temp->next;
		temp->next=ptr->next;
		free(ptr);
	}
	
	
}
int insertat(int pos)
{
	struct node *temp,*new;
	int i;
	
	new=(struct node *)malloc(sizeof(struct node));
	new->next=NULL;
	printf("Read Data to be entered at position");
	scanf("%d",&new->data);
	
	if(pos==1)
	{
		new->next=head;
		head=new;
		
	}
	else
	{	
		
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		new->next=temp->next;
		temp->next=new;
	}
}
void  insert(int data)
{
	struct node *temp,*new;
	int p;
	
	new=(struct node *)malloc(sizeof(struct node));
	new->next=NULL;
	printf("Read Data to be entered at position");
	scanf("%d",&new->data);
	
	if(head==NULL)
	{
		printf("linked list is empty");
	}
	else
	{	
		
		temp=head;
	        while(temp!=NULL)
		{
			p=temp->data;
			if(p==data)
			{
				new->next=temp->next;
				temp->next=new;
				break;
				
			}
			temp=temp->next;
		}
		
	}
	
}
void  delete(int data)
{
	struct node *temp,*ptr;
	int p;
	
	if(head==NULL)
	{
		printf("linked list is empty");
	}
	else
	{	
		
		temp=head;
	        while(temp!=NULL)
		{
			p=temp->next->data;
			if(p==data)
			{
				ptr=temp->next;
				temp->next=ptr->next;
				free(ptr);
				break;
				
			}
			temp=temp->next;
		}
		
	}
	
}
void display()
{
	struct node *temp;
	int count=0;
	
	if(head == NULL)
	{
		printf("linked list is empty");
	}
	else
	{
		temp=head;
		while(temp!= NULL)
		{	count++;
			printf("\t<-%d->",temp->data);
			temp=temp->next;
		}printf("\n Number of nodes available are = %d",count);
	}


}


void main()
{
	
	
	int choice,n,n1,n2,n3,n4;
	do
	{
		printf("\n1.Create \n2.Deleteat \n3.Display \n4.Insertat \n5.Search \n6.Insert\n7.Delete \n8.Exit");
		printf("\nEnter Choice");
		scanf("%d",&choice);
		
		switch(choice)
		{
			
		case 1: create();
			       break;
		case 2: printf("\nEnter position of the node to be deleted");
			      scanf("%d",&n);
			      delete(n);
			      break;
		case 3: display();
			      break;
		case 4: printf("\nEnter position of the node to be inserted");
			      scanf("%d",&n1);
			     insertat(n1);
			     break;
		case 5: printf("\nEnter element to be searched");
			      scanf("%d",&n2);
			      search(n2);
			      break;
		case 6:printf("\nEnter  data of node  after which new node to be inserted");
			     scanf("%d",&n3 );
			     insert(n3);
			     break;
		case 7: printf("\nEnter  data of node to be deleted");
			     scanf("%d",&n4 );
			     delete(n4);
			     break;
		case 8: exit (1);
			       break;
		default :printf("Invalid..");
			      break;
			
		}
	
	
	}while(1);
}
