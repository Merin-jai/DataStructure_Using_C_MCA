#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
int c=0;
node *head=NULL;
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
		  t=t->next;
		t->next=(node*)malloc(sizeof(node));
		t->next->data=e;
		t->next->next=NULL;
	}
}
void sort_by_value() //sorting the elements by value
{
	int temp=0;
	node *t=head,*t1;
	while(t->next!=NULL)
	{
		t1=t->next;
		while(t1!=NULL)
		{
			if(t->data>t1->data) //fisrt element is compared with all other elements and finds its location
		     {
			   temp=t->data;
			   t->data=t1->data;
			   t1->data=temp;
             }
		    t1=t1->next;
		}
		t=t->next;
	}
}
void disp()
{
	node *t=head;
	printf("\nLinked List elements are : ");
	while(t!=NULL)
	{
		printf(" %d ",t->data);
		t=t->next;
	}
}
void swapp(node *t,node *prev,node *cur)
{
	node *t1=cur->next;
    cur->next=t->next;
    prev->next=t;
    t->next=t1;
    if(t==head)
    {
    	head=cur;
	}
	disp();
//	return cur;
}

void sort_by_address()
{
	node *cur,*prev,*t,*t1;
	int i,j;
	//making the head node the smallest node
    t=head;
    cur=head;
    prev=head;
    while(t->next!=NULL)
    {
    	if(cur->data>t->next->data)
    	{
    		prev=t;
    		cur=t->next;
		}
		printf("\ninside loop : prev = %d\tcur = %d",prev->data,cur->data);
    	t=t->next;
	}
	printf("\noutside loop : prev = %d\tcur = %d",prev->data,cur->data);
	prev->next=cur->next;
	cur->next=head;
	head=cur;
	disp();
	/////////////////
    t=head;
    prev=cur=NULL;
    while(t->next!=NULL)
    {
    	t1=t->next;
    	cur=t->next;;
    	prev=t;
    	while(t1->next!=NULL)
    	{
    		if(t1->data>t1->next->data)
    		{
    			prev=t1;
    			cur=t1->next;
    		}			
			printf("\ninside loop : prev = %d\tcur = %d",prev->data,cur->data);
			t1=t1->next;
		}
		printf("\noutside loop : prev = %d\tcur = %d",prev->data,cur->data);
		prev->next=cur->next;
		cur->next=t->next;
		t->next=cur;
		t=t->next;
	}

}


int menu()
{
	int ch;
	printf("\n\n\t\t   SORTING USING LINKED LIST");
	printf("\n\t\t-----------------------------------");
	printf("\n\t1.Insert\n\t2.Display\n\t3.Sort by value\n\t4.Sort by address\n\t5.Exit");
	printf("\n\nEnter your Choice : ");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	int ch;
	for(ch=menu();ch!=5;ch=menu())
	{
		switch(ch)
		{
			case 1 : printf("\n\tEnter Element : ");
			         scanf("%d",&ch);
			         insert(ch);break;
			case 2 : disp();break;
			case 3 : sort_by_value();
			         printf("\nAfter Sorting by value ");
			         disp();break;
			case 4 : sort_by_address();
			         printf("\nAfter Sorting by address ");
			         disp();break;
			default : printf("\nInvalid Choice..Please enter again..");
			
		}
	}
}
int main()
{
	process();
	return 0;
}
