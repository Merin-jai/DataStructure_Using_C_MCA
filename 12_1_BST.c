#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *right;
	struct node *left;
};
typedef struct node tree;
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
void preorder(tree *r)
{
	if(r==NULL)
	  return;
	printf("\t%d",r->data);
	preorder(r->left);
	preorder(r->right);
}
void postorder(tree *r)
{
	if(r==NULL)
	  return;
	postorder(r->left);
	postorder(r->right);
	printf("\t%d",r->data);
}
int menu()
{
	int ch;
	printf("\n\t\t   Binary Search Tree Using recursion");
	printf("\n\t\t-----------------------------------------");
	printf("\n\t1.Insert\n\t2.Inorder\n\t3.Preorder\n\t4.Postorder\n\t5.Exit");
	printf("\nEnter your choice : ");
	scanf("%d",&ch);
	return ch;
}
int main()
{
	int ch;
	for(ch=menu();ch!=5;ch=menu())
	{
		switch(ch)
		{
			case 1 :  printf("\nEnter the element : ");
			          scanf("%d",&ch);
			          insert(ch);break;
			case 2 :  printf("\n\tInorder traversal : ");
			          inorder(root);break;
			case 3 :  printf("\n\tPreorder traversal : ");
			          preorder(root);break;
			case 4 :  printf("\n\tPostorder traversal : ");
			          postorder(root);break;
			default : printf("\nINVLID CHOICE ");
		}
	}
	return 0;
}
