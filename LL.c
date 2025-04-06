#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
node *t;
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
		t=head;
		while(t->next!=NULL)
		   t=t->next;
		t->next=(node*)malloc(sizeof(node));
		t->next->next=NULL;
		t->next->data=e;
	}
}
void delete(int e)
{
	if(head==NULL)
	  printf("\nLL empty");
	else if(head->data==e&&head->next==NULL)
	   head=NULL;
	else if(head->data==e)
	   head=head->next;
	else 
	{
		t=head;
		while(t->next!=NULL&&t->next->data!=e)
		{
			t=t->next;
		}
		t->next=t->next->next;	    
	}
}
void disp()
{
	if(head==NULL)
	   printf("\nEmpty");
	else
	  {
	  	t=head;
	  	printf("\nLL : ");
	  	while(t!=NULL)
	  	{
	  		printf("\t%d",t->data);
	  		t=t->next;
		  }
	  }
}
int main()
{
	insert(10);
	disp();
	insert(20);
	insert(30);
	disp();
	delete(20);
	disp();
	return 0;
}
