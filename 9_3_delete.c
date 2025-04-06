#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert(int e)
{
	node *t;
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
		{
			t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		t->next->data=e;
		t->next->next=NULL;
	}
}
void display()
{
	node *t=head;
	if(head==NULL)
	{
		printf("\nLINKED LIST EMPTY");
	}
	else
	{
		printf("\nLINKED LIST ELEMENTS ARE : ");
		while(t!=NULL)
		{
			printf("\t%d",t->data);
			t=t->next;
		}
	}
}
void del_first()  //deleting from fisrt position of LL
{
	if(head==NULL)
	  printf("\nLinked List empty");
	else
	{
		head=head->next;
		printf("\nDeleted from beginning Of LL");
		display();
	}	   
}
void del_last() //deleting the last node of LL
{
	node *t=head;
	if(head==NULL)
	{
		printf("\nLinked List empty");
		return;
	}
	  
	while(t->next->next!=NULL)
	  { 
	    t=t->next;
	  }
	t->next=NULL;
	printf("\n\nDeleted the last Node..");
	display();
}
void del_pos()//deleting a specified node
{
	node *t;
	int e;
	printf("\nEnter the node to delete : ");
	scanf("%d",&e);
	if(head==NULL)
	{
		printf("\nLinked List empty");
		return;
	}
	else if(head->data==e)
	  head=head->next;
	else
	{
		t=head;
		while(t->next!=NULL&&t->next->data!=e)
		{
			t=t->next;
		}
		if(t->next==NULL)
		  printf("\nElement Not Found");
		else
		  t->next=t->next->next;
	}
	printf("\nDeleted %d",e);
}
int main()
{
	int ch,e;
	do
	{
		printf("\n\n\t  LINKED LIST DELETION AND DISPLAY");
	    printf("\n\t-------------------------------------");
	    printf("\n\n\t1.INSERT\n\t2.Delete from First\n\t3.Delete from last\n\t4.Delete a Node\n\t5.DISPLAY\n\t6.EXIT");
	    printf("\n\nEnter your choice : ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1 : printf("\nEnter element to be inserted : ");
	    	         scanf("%d",&e);
	    	         insert(e);break;
	    	case 2 : del_first();break;
	    	case 3 : del_last();break;
	    	case 4 : del_pos();break;
	    	case 5 : display();break;
	    	default : printf("\nInvalid Choice!!");break;
		}
	}while(ch!=6);
	return 0;
}
