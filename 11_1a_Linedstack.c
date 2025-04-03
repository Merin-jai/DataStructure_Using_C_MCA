#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *top=NULL;
void push(int e)
{
	node *t=(node*)malloc(sizeof(node));
	t->data=e;
	t->next=top;
	top=t;
}
void pop()
{
	if(top==NULL)
	  printf("\nStack is empty");
	else
	{
		printf("\nPopped element : %d",top->data);
		top=top->next;
	}
}
void peep()
{
	printf("\nElement at top : %d",top->data);
}
int menu()
{
	int ch;
	printf("\n\t\tLINKED STACK");
	printf("\n\t1.PUSH\n\t2.POP\n\t3.PEEP\n\t4.Exit\n\nEnter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void process_stack()
{
	int ch;
	for(ch=menu();ch!=4;ch=menu())
	{
		switch(ch)
		{
			case 1 : printf("\nEnter  Element : ");
			         scanf("%d",&ch);
			         push(ch);break;
			case 2 : pop();break;
			case 3 : peep();break;
		}
	}
}
int main()
{
	process_stack();
	return 0;
}
