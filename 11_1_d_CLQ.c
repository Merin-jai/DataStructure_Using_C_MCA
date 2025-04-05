#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *r=NULL,*f=NULL;
void enqueue(int e)
{
	node *t=(node*)malloc(sizeof(node));
	t->data=e;
	t->next=f;
	if(f==NULL)
	{
		r=f=t;
	}
	else
	{
		r->next=t;
		r=t;
	}
}
void dequeue()
{
	if(f==NULL)
	  printf("\nLinked Circular Queue is empty");
	else
	{
		printf("\nDequeued element : %d",f->data);
		f=f->next;
		r->next=f;
		if(f==NULL)
		  r=NULL;
	}
}
void disp()
{
	node *t=f;
	if(f==NULL)
	{
		printf("\nLinked Queue Empty");
	}
	else
	{
		printf("\nLinked Queue : ");
		printf("\t%d",t->data);
		while(t->next!=f)
		{
			printf("\t%d",t->next->data);
			t=t->next;
		}
	}
}
int menu()
{
	int ch;
	printf("\n\t\t  CIRCULAR LINKED QUEUE");
	printf("\n\t\t--------------------------");
	printf("\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Exit");
	printf("\nEnter your Choice : ");
	scanf("%d",&ch);
	return ch;
}
int main()
{
	int ch;
	for(ch=menu();ch!=4;ch=menu())
	{
		switch(ch)
		{
			case 1 : printf("\nEnter element : ");
		             scanf("%d",&ch);
		             enqueue(ch);break;
		    case 2 : dequeue();break;
		    case 3 : disp();break;
	     	case 4 : exit(0);
		}
	}
	return 0;
}
