#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
int c=0,i,j;
void insert(int e)
{
	c++;
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
//	printf("\n\n\t C=%d",c);
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
		printf("\nLINKED LIST ELEMENTS IN REVERSE ORDER ARE :");
		for(i=0;i<c;i++)
	     {
	     	t=head;
		    for(j=i+1;j<c;j++)
		    {
			  t=t->next;
		    }
		    printf("\t%d\t",t->data);
	    }
//		printf("NULL");
	}
}
void reverse()
{
	node *temp1,*temp2,*t;
	t=head;
	temp2=NULL;
	while(t!=NULL)
	{
		temp1=t;
		t=t->next;
		temp1->next=temp2;
		temp2=temp1;
	}
	head=temp2;
}
void disp()
{
	node *t;
	if(head==NULL)
	    printf("\nEmpty");
	else
	{
		printf("\nLL elements : ");
		t=head;
		while(t!=NULL)
		{
			printf(" %d ",t->data);
			t=t->next;
		}
	}
}
int main()
{
	int ch,e;
	do
	{
		printf("\n\n\t  LINKED LIST CREATION AND DISPLAY IN REVERSE ORDER");
	    printf("\n\t------------------------------------------------------");
	    printf("\n\n\t1.INSERT\n\t2.REVERSE DISPLAY\n\t3.EXIT");
	    printf("\n\nEnter your choice : ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1 : printf("\nEnter element to be inserted : ");
	    	         scanf("%d",&e);
	    	         insert(e);break;
	    	case 2 : display();
			         disp();
					 reverse();
					 disp();break;
	    	case 3 : printf("\nInvalid Choice!!");
		}
	}while(ch!=3);
	return 0;
}
