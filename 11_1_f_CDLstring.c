#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[50];
	struct node *next;
	struct node *prev;
};
typedef struct node node;
node *head=NULL;
node *last=NULL;

void insert()
{
	char e[50];
	getchar();
	printf("\nEnter string : ");
	gets(e);
	if(head==NULL)
	{
		head=(node*)malloc(sizeof(node));
		strcpy(head->name,e);
		head->next=head;
		head->prev=head;
		last=head;
	}
	else
	{
		last->next=(node*)malloc(sizeof(node));
		strcpy(last->next->name,e);
		last->next->next=head;
		last->next->prev=last;
		last=last->next;
		head->prev=last;
	}	
}

void delet()
{
	node *t;
	char e[50];
	if(head==NULL)
	{
		printf("\nDoublu LL empty");
		return;
	}
	printf("\nEnter String to delete : ");
	getchar();
	gets(e);
	if(strcmpi(head->name,e)==0&&head->next==head)//deleting 1st element when only 1 element
	{
		head=NULL;
	}
	else if(strcmpi(head->name,e)==0)//deleteing 1st element when several elements
	{
		head->prev->next=head->next;
		head=head->next;
		head->prev=last;
	}
	else if(strcmpi(last->name,e)==0)//deleting the last element
	{
		last->prev->next=head;
		last=last->prev;
		head->prev=last;
	}
	else
	{
		t=head;
		while(t->next!=head)  //deleting the intermediate element
		{
			if(strcmpi(t->name,e)==0)
			  break;
			t=t->next;
		}
		if(t==head)
		  printf("\nElement not found");
		else
		{
			t->prev->next=t->next;
		    t->next->prev=t->prev;
		}
	}
	
}

void disp()
{
	node *t;
	if(head==NULL)
	{
		printf("\nDoubly Circular LL empty");
	}
	else
	{
		t=head;
		printf("\nThe elements are : ");
		printf("\t%s",t->name);
		while(t->next!=head)
		{
			printf("\t%s",t->next->name);
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
		printf("\t%s",t->name);
		while(t->prev!=last)
		{
			printf("\t%s",t->prev->name);
			t=t->prev;
		}
	}
}
int menu()
{
	int ch;
	printf("\n\t\t  CIRCULAR DOUBLY LINKED LIST(STRINGS)");
	printf("\n\t\t------------------------------------------");
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
			case 1 : insert();break;
		    case 2 : delet();break;
		    case 3 : disp();break;
	     	case 4 : disp_last();break;
		}
	}
	return 0;
}
