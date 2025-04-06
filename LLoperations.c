#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
int c=0;
node *head=NULL;
void insert()
{
	c++;
	node *t;
	int e;
	printf("\n\nEnter element : ");
	scanf("%d",&e);
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
void disp()
{
	node *t=head;
	if(head==NULL)
	{
		printf("\nLinked List Empty");
	}
	else
	{
		printf("\nLINKED LIST ELEMENENTS ARE : ");
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;
		}
	}
}
void delet()
{
	int s;
	node *t;
	if(head==NULL)
	{
		printf("\nNo element in Linked List");
		return;
	}
	printf("\n\nEnter Element to delete : ");
	scanf("%d",&s);
	if(head->data==s)
	{
		head=head->next;
		c--;
	}
	else
	{
		t=head;
		while(t->next!=NULL&&t->next->data!=s)
		   t=t->next;
		if(t->next==NULL)
		{
			printf("\nElement Not Found");return;
		} 
		else
		  t->next=t->next->next;
		  c--;
	}
	printf("\n\nElement deleted");
}	
void sort() //sorting by value
{
	int temp;
	node *t=head,*t1;
	while(t->next!=NULL)
	{
		t1=t->next;
		while(t1!=NULL)
		{
			if(t->data>t1->data) 
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
void sort_by_address()   //sorting by address
{
	node *cur,*prev,*t,*t1;
	int i,j;
	//making the head node the smallest node
    t=head;
    cur=head;
    prev=head;
    while(t->next!=NULL)
    {
    	if(cur->data>t->next->data)//finding the smallest element in the list
    	{
    		prev=t;
    		cur=t->next;//cur will be the node with smallest element
		}
//		printf("\ninside loop : prev = %d\tcur = %d",prev->data,cur->data);
    	t=t->next;
	}
//	printf("\noutside loop : prev = %d\tcur = %d",prev->data,cur->data);
	if(cur!=head)
	{
		prev->next=cur->next;
	    cur->next=head;
	    head=cur;
    }
	//head is swapped with the smallest element
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
//			printf("\ninside loop : prev = %d\tcur = %d",prev->data,cur->data);
			t1=t1->next;
		}
//		printf("\noutside loop : prev = %d\tcur = %d",prev->data,cur->data);
		prev->next=cur->next;
		cur->next=t->next;
		t->next=cur;
		t=t->next;
	}

}
void reverse() //displaying in reverse order only without reversing nodes
{
	node *t=head;
	int i,j;
	if(head==NULL)
	  printf("\nLinked List empty");
	else
	{
		printf("\nElements in reverse order are : ");
		for(i=0;i<c;i++)
		{
			t=head;
			for(j=i+1;j<c;j++)
			{
				t=t->next;
			}
			printf("\t%d",t->data);
		}
	}
}
/* reversing the entire list 
void reverse()
{
    struct node *t,*temp1,*temp2;
    int i=0;
    if(head == NULL)
    {
        printf("\nLinked List is empty!!!\n\n");
    }
    else
    {
        t=head;
        temp2=NULL;
        while(t!=NULL)
        {
            temp1 = t;
            t=t->next;
            temp1->next = temp2;
            temp2 = temp1;
        }
        head = temp2;
    }
    printf("\nThe linked list is reversed\n\n");
}
------------------------------------*/
int menu()
{
	int ch;
	printf("\n\t\t   LINKED LIST ");
	printf("\n\t\t---------------------------");
	printf("\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Sort\n\t5.Reverse\n\t6.Count\nEnter your Choice : ");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	int ch;
	for(ch=menu();ch!=7;ch=menu())
	{
		switch(ch)
		{
			case 1 : insert();break;
		    case 2 : delet();break;
		    case 3 : disp();break;
		    case 4 : sort();
		             printf("\nAfter Sorting");
		             disp();break;
		    case 5 : reverse();break;
		    case 6 : printf("\n\nTHE COUNT OF ELEMENTS ARE : %d",c);
		    default : printf("\nINVALID CHOICE");
		}
	}
}
int main()
{
	process();
	return 0;
}

