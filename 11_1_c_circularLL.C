#include<stdio.h>
#include<malloc.h>
#include<process.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head= NULL;
void insert(int e)
{
	node *t;
	if(head==NULL)//if there are no elements in LL
	{
		head=(node*)malloc(sizeof(node*));
		head->data=e;
		head->next=head;
	}
	else
	{
		t=head;
		while(t->next!=head)
		  t=t->next;
		t->next=(node*)malloc(sizeof(node*));
		t->next->data=e;
		t->next->next=head;
	}
}
void disp()
{
	struct node *t;
	if(head==NULL)
	{
		printf("\nCircular Linked List Empty");
	}
	else
	{
		t=head;
		while(t->next!=head)
		{
			printf("%d\t",t->data);
			t=t->next;
		}
		printf("%d\t",t->data);
	}
}
void delet(int e)
{
	node *t;
	if(head==NULL)
	   printf("\nCircular Linked List Empty");
	else if(head->data==e&&head->next==head)//first element but only 1 elemenent
	   head=NULL;
	else if(head->data==e)//first element but several leemnts
	{
		t=head;
		while(t->next!=head)
		  t=t->next;
		t->next=head->next;
		head=head->next;
	}
	else
	{
		t=head;
		while(t->next!=head&&t->next->data==e)
		 t=t->next;
		if(t->next==head)
		  printf("\nElement not found");
		else 
		  t->next=t->next->next;
	}
}
int main()
{
	int ch,e;
	do
	{
		printf("\nCIRCULAR LINKED LIST");
	    printf("\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Exit");
	    printf("\nEnter your Choice : ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
		    case 1 : printf("\nEnter element : ");
		             scanf("%d",&e);
		             insert(e);break;
		    case 2 : printf("\nEnter element : ");
		             scanf("%d",&e);delet(e);break;
		    case 3 : disp();break;
	     	case 4 : exit(0);
	   }
	}while(ch!=4);
	return 0;
}
