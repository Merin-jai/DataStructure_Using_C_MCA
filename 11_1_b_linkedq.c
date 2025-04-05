#include<stdio.h>
#include<malloc.h>
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
	t->next=NULL;
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
	  printf("\nQueue is empty");
	else
	{
		printf("\nDequeued element : %d",f->data);
		f=f->next;
		if(f==NULL)
		  r=NULL;
	}
}

int menu()
{
	int ch;
	printf("\n\t\tLINKED QUEUE");
	printf("\n\t1.Enqueue\n\t2.Dequeue\n\t3.Exit\n\nEnter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void process_queue()
{
	int ch;
	for(ch=menu();ch!=3;ch=menu())
	{
		switch(ch)
		{
			case 1 : printf("\nEnter  Element : ");
			         scanf("%d",&ch);
			         enqueue(ch);break;
			case 2 : dequeue();break;
//			case 3 : peep();break;
		}
	}
}
int main()
{
	process_queue();
	return 0;
}
