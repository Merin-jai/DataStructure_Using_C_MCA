#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *right;
	struct node *left;
};
typedef struct node tree;
struct stack
{
	tree *r;
	struct stack *next;
};
typedef struct stack stack;
stack *top=NULL;
tree *root=NULL;
void insert(int e)
{
	tree *p,*x;
	if(root==NULL)
	{
		root=(tree*)malloc(sizeof(tree));
		root->data=e;
		root->left=root->right=NULL;
	}
	else
	{
		p=root;
		while(p!=NULL)
		{
			x=p;
			if(p->data>e)
			   p=p->left;
			else
			  p=p->right;
		}
		if(x->data>e)
		{
			x->left=(tree*)malloc(sizeof(tree));
			x->left->data=e;
			x->left->right=x->left->left=NULL;
		}
		else
		{
			x->right=(tree*)malloc(sizeof(tree));
			x->right->data=e;
			x->right->right=x->right->left=NULL;
		}
	}
}
void inorder(tree *r)
{
	if(r==NULL)
	  return;
	inorder(r->left);
	printf("\t%d",r->data);
	inorder(r->right);
}
void push(tree *t)
{
   	stack *temp=(stack*)malloc(sizeof(stack));
   	temp->r=t;
   	temp->next=top;
   	top=temp;
}
tree* pop()
{
	tree *t=NULL;
	if(top!=NULL)
	{
		t=top->r;
		top=top->next;
	}
	return t;
}
void inorderr(tree *r)
{
	tree *t;
	for(t=root;t!=NULL;t=t->left)
	{
		printf("\t%d",t->data);
		push(t);
	}
	t=pop();
	while(t!=NULL)
	{
//		printf("\t%d",t->data);
		for(t=t->right;t!=NULL;t=t->left)
		{
			printf("\t%d",t->data);
			push(t);
		}
		t=pop();
	}
}
int menu()
{
	int ch;
	printf("\n\t\t    BST Inorder without recursion");
	printf("\n\t\t-----------------------------------------");
	printf("\n\t1.Insert\n\t2.Inorder\n\t3.Exit");
	printf("\nEnter your choice : ");
	scanf("%d",&ch);
	return ch;
}
int main()
{
	int ch;
	for(ch=menu();ch!=3;ch=menu())
	{
		switch(ch)
		{
			case 1 :  printf("\nEnter the element : ");
			          scanf("%d",&ch);
			          insert(ch);break;
			case 2 :  printf("\n\tInorder traversal : ");
			          inorderr(root);break;
			default : printf("\nINVLID CHOICE ");
		}
	}
	return 0;
}
