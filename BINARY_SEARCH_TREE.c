#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *left;
	struct node *right;
};

struct node *root;
struct node *create(int x)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->key=x;
	new->left=NULL;
	new->right=NULL;
	return new;
}
struct node *insert(struct node *root,int key)
{	
	char ch;
		
	if(root == NULL)
	{
		root=create(key);
		return root;
					
	}
	else
	{
		
		if(key<root->key)
		{
			root->left=insert(root->left,key);
		}
		else if(key>root->key)
		{
			root->right=insert(root->right,key);
		}return root;
	}
	
	
}
//returns a node with minimum key value
struct node *minvalue(struct node *root)
{	
	struct node *current;
	current=root;	
	
	while(current->left != NULL)
	{
		current=current->left;
					
	}
	return current;
}

struct node *delete(struct node *root,int key)
{	
	struct node *temp;	
	char ch;
		
	if(root == NULL)
	{
		return root;
					
	}
	else
	{
		if(key<root->key)
		{
			root->left=delete(root->left,key);
		}
		else if(key>root->key)
		{
			root->right=delete(root->right,key);
		}
		else
		{//root with only one child/no child
			if(root->left == NULL)
			{
				temp=root->right;
				free(root);
				return temp;
			}
			else if(root->right == NULL)
			{
				temp=root->left;
				free(root);
				return temp;
			}
			//root with two children: find the inorder successor(smallest in right subtree)
			temp=minvalue(root->right);
			//copy value of inorder successor to root
			root->key=temp->key;
			//delete the inorder successor
			root->right=delete(root->right,temp->key);
		}
	}return root;
	
	
}

void search(struct node *root,int key)
{	
	char ch;
		
	if(root == NULL)
	{
		printf("Tree/key does not exist");
	
	}
	else
	{
		
		if(key==root->key)
		{
			printf("\nkey %d found",root->key);
		}
		else if(key>root->key)
		{
			search(root->right,key);
		}
		else
		{
			search(root->left,key);
		}
	}
	
	
}


void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf(" %d",root->key);
		inorder(root->right);
	}
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf(" %d",root->key);		
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf(" %d",root->key);
		
	}
}

void main()
{
	
	struct node *root;
	//temp=NULL;
	root=NULL;
	int choice,n,n1,n2;
	do
	{
		printf("\n1.insert \n2.Inorder \n3.Preorder \n4.Postorder \n5.search \n6.Delete \n7.exit");
		printf("\nEnter Choice");
		scanf("%d",&choice);
		
		switch(choice)
		{
			
		case 1: printf("Enter key to be entered");
			scanf("%d",&n);
			root=insert(root,n);
			break;
		case 2: inorder(root);
			break;
		case 3: preorder(root);
			break;
		case 4: postorder(root);
			break;
		case 5: printf("Enter key to be searched");
			scanf("%d",&n2);
			search(root,n2);
			break;
		case 6: printf("Enter key to be deleted");
			scanf("%d",&n1);
			root=delete(root,n1);
			break;
		case 7: exit (1);
			break;
		default : printf("invalid..");
			 break;
			
		}
	
	
	}while(1);
}