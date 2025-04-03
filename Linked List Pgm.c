#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert(int e)
{
	if(head==NULL)
	{
		head=(node*)malloc(sizeof(node));
		head->data=e;
		head->next=NULL;
	}
	else
	{
		node *t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		t->next->data=e;
		t->next->next=NULL;
	}
}
void disp()
{
	node *t;
	if(head==NULL)
	{
		printf("\nLinked List empty");
	}
	else
	{
		t=head;
		printf("\nThe LL elements are : ");
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;
		}
	}
}
void delet(int e)
{
	node *t;
	if(head==NULL)
	{
		printf("\nLinked list empty");
	}
	else if(head->data==e)
	{
		head=head->next;
	}
	else
	{
	   t=head;
	   while(t->next!=NULL)
	   {
	   	    if(t->next->data==e)
	   	        break;
	   	     t=t->next;
	   }
	   if(t->next==NULL)
	   {
	   	printf("\nElement not found");
	   	return;
	   }
	   t->next=t->next->next;	
	}
}
int main()
{
	insert(10);
	insert(20);
	insert(100);
	insert(25);
	insert(32);
	disp();
	delet(20);
	disp();
	delet(32);
	disp();
	delet(10);
	disp();
	delet(150);
	disp();
	return 0;
}
