#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert_begin(int e)
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
		t=(node*)malloc(sizeof(node));
		t->data=e;
		t->next=head;
		head=t;
	}
}
void insert_end(int e)
{
	if(head==NULL)
	{
		head=(node*)malloc(sizeof(node));
		head->data=e;
		head->next=NULL;
		return;
	}
	node *t=head;
	while(t->next!=NULL)
		{
			t=t->next;
		}
	t->next=(node*)malloc(sizeof(node));
	t->next->data=e;
	t->next->next=NULL;
}
void insert_pos(int e)
{
	node *t=head,*p; int s;
	printf("\nSpecify the element after which the data has to be inserted : ");
	scanf("%d",&s);
	while(t!=NULL)
	{
//		printf("\n\t#");
		if(t->data==s)
		{
//			printf("\t*");
			p=(node*)malloc(sizeof(node));
			p->data=e;
			p->next=t->next;
			t->next=p;
			break;	
		}
		t=t->next;
	}
	if(t==NULL)
	{
		printf("\n\nUnable to insert..Element not found!!");
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
			printf("%d -> ",t->data);
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
	    printf("\n\n\t1.INSERT AT BEGNNING\n\t2.INSERT AT END\n\t3.INSERT AFTER AN ELEMENT\n\t4.DISPLAY\n\t5.EXIT");
	    printf("\n\nEnter your choice : ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1 : printf("\nEnter element to be inserted : ");
	    	         scanf("%d",&e);
	    	         insert_begin(e);break;
	    	case 2 : printf("\nEnter element to be inserted : ");
	    	         scanf("%d",&e);
	    	         insert_end(e);break;
	    	case 3 : printf("\nEnter element to be inserted : ");
	    	         scanf("%d",&e);
	    	         insert_pos(e);break;
	    	case 4 : display();break;
	    	default : printf("\nInvalid Choice!!");
		}
	}while(ch!=5);
	return 0;
}
