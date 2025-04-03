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
			printf("\t%d->",t->data);
			t=t->next;
		}
		printf("NULL");
	}
}
int main()
{
	int ch,e;
	do
	{
		printf("\n\t  LINKED LIST CREATION AND DISPLAY");
	    printf("\n\t-------------------------------------");
	    printf("\n\n\t1.INSERT\n\t2.DISPLAY\n\t3.EXIT");
	    printf("\n\nEnter your choice : ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1 : printf("\nEnter element to be inserted : ");
	    	         scanf("%d",&e);
	    	         insert(e);break;
	    	case 2 : display();break;
	    	case 3 : printf("\nInvalid Choice!!");
		}
	}while(ch!=3);
	return 0;
}
