#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node node;
node *head=NULL;
node *last=NULL;
void insert(int e)
{
	if(head==NULL)
	{
		head=(node*)malloc(sizeof(node));
		head->data=e;
		head->next=NULL;
		head->prev=NULL;
		last=head;
	}
	else
	{
		last->next=(node*)malloc(sizeof(node));
		last->next->data=e;
		last->next->next=NULL;
		last->next->prev=last;
		last=last->next;
	}
}
void delet(int e)
{
	node *t;
	if(head==NULL)
	{
		printf("\nDoublu LL empty");
	}
	else if(head->data==e&&head->next==NULL)//deleting 1st element when only 1 element
	{
		head=NULL;
	}
	else if(head->data==e)//deleteing 1st element when several elements
	{
		head=head->next;
		head->prev=NULL;
	}
	else if(last->data==e)//deleting the last element
	{
		last->prev->next=NULL;
		last=last->prev;
	}
	else
	{
		t=head;
		while(t!=NULL)  //deleting the intermediate element
		{
			if(t->data==e)
			 break;
			t=t->next;
		}
		if(t==NULL)
		  {
		  	printf("\nElement not found");
		  	return;
		  }
		t->prev->next=t->next;
		t->next->prev=t->prev;
	}
	
}
void disp()
{
	node *t;
	if(head==NULL)
	{
		printf("\nDoubly LL empty");
	}
	else
	{
		t=head;
		printf("\nThe elements are : ");
		while(t!=NULL)
		{
			printf("\t%d",t->data);
			t=t->next;
		}
	}
}
void disp_last()
{
	node *t;
	if(head==NULL)
	{
		printf("\nDoubly LL empty");
	}
	else
	{
		t=last;
		printf("\nThe elements are : ");
		while(t!=NULL)
		{
			printf("\t%d",t->data);
			t=t->prev;
		}
	}
}
int menu()
{
	int ch;
	printf("\n\t\t  DOUBLY LINKED LIST");
	printf("\n\t\t--------------------------");
	printf("\n\t1.Insert\n\t2.Delete\n\t3.Display from First\n\t4.Display From last\n\t5.Exit");
	printf("\nEnter your Choice : ");
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
			case 1 : printf("\nEnter element : ");
		             scanf("%d",&ch);
		             insert(ch);break;
		    case 2 : printf("\nEnter element to delete : ");
		             scanf("%d",&ch);
					 delet(ch);break;
		    case 3 : disp();break;
	     	case 4 : disp_last();break;
		}
	}
	return 0;
}
