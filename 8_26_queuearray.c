#include<stdio.h>
//assuming front is always 0
enum op
{
	enqueue=1,dequeue,exit
};
int q[20],n,i,r=-1,f=-1;
void enQueue()
{
	if(r+1==n)
	    printf("\nQueue is Full");
	else
	{
		if(f==-1)
		    f=0;//if inserting 1st element making front as 0
		printf("\nEnter the element : ");
		scanf("%d",&q[++r]);
		printf("\nElement inserted succesfully");
	}
}
void deQueue()
{
	if(f==-1)
	    printf("\nQueue is empty");
	else
	{
		printf("\nDequeued Item %d",q[f]);
		if(f==r)
		   f=r=-1;
		else
		{
			for(i=0;i<r;i++)
			   q[i]=q[i+1];
			r--;
		}
		   
	}
}
int menu()
{
	int ch;
	printf("\n\n\t1.Enqueue(Insert an element)\n\t2.Dequeue(Delete an element)\n\t3.Exit");
	/*/---------------------------------------
	printf("\n\nThe elements of queue are : ");
	for(i=f;i<=r&&i!=-1;i++)
	  printf("\t%d",q[i]);
	//---------------------------------------*/
	printf("\n\tEnter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	int ch;
	for(ch=menu();ch!=3;ch=menu())
	{
		switch(ch)
		{
			case enqueue : enQueue();break;
			case dequeue : deQueue();break;
			default : printf("\n\nInvalid Choice!!");
		}
	}
}
int main()
{
	printf("\n\t\t  QUEUE USING ARRAY");
	printf("\n\t\t---------------------");
	printf("\n\nEnter the size of queue : ");
	scanf("%d",&n);
	process();
	return 0;
}
