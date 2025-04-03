#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[50];
	struct node *next;
};
typedef struct node node;
int c=0;
node *head=NULL;
void insert()
{
	c++;
	node *t;
	char e[50];
	getchar();
	printf("\n\nEnter element : ");
	gets(e);
	if(head==NULL)
	{
		head=(node*)malloc(sizeof(node));
		strcpy(head->name,e);
		head->next=NULL;
	}
	else
	{
		t=head;
		while(t->next!=NULL)
		  t=t->next;
		t->next=(node*)malloc(sizeof(node));
		strcpy(t->next->name,e);
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
			printf("%s\t",t->name);
			t=t->next;
		}
	}
}
void delet()
{
	char s[20];
	node *t;
	if(head==NULL)
	{
		printf("\nNo element in Linked List");
		return;
	}
	printf("\n\nEnter Element to delete : ");
	scanf("%s",&s);
	if(strcmpi(head->name,s)==0)
	{
		head=head->next;
		c--;
	}
	else
	{
		t=head;
		while(t->next!=NULL&&(strcmpi(t->next->name,s)!=0))
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
void sort()
{
	char temp[50];
	node *t=head,*t1;
	while(t->next!=NULL)
	{
		t1=t->next;
		while(t1!=NULL)
		{
			if(strcmpi(t->name,t1->name)>0) 
		     {
			   strcpy(temp,t->name);
			   strcpy(t->name,t1->name);
			   strcpy(t1->name,temp);
             }
		    t1=t1->next;
		}
		t=t->next;
	}
}
void reverse()
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
			printf("\t%s",t->name);
		}
	}
}
int menu()
{
	int ch;
	printf("\n\t\t   LINKED LIST (STRING)");
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
		    case 6 : printf("\n\nTHE COUNT OF ELEMENTS ARE : %d",c);break;
		    default : printf("\nINVALID CHOICE");
		}
	}
}
int main()
{
	process();
	return 0;
}

