//9_5_linked_list_sort.c
#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert(int e)
{
	struct node *t;
	if(head == NULL)
	{
		head = (struct node *)malloc(sizeof(struct node));
		head -> data = e;
		head -> next = NULL;
    }
    else
    {
    	t=head;
    	while(t->next!=NULL)
    	{
    		t=t->next;
		}
		t->next=(struct node *)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=NULL;
	}	
}
void disp()
{
	struct node *t;
	if (head==NULL)
		printf("Linked list is empty!!\n\n");
	else
	{
		t=head;
		printf("\n");
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;
		}
		printf("\n");
	}		
}

void sort_using_values()
{
	struct node *i,*j;
    printf("\n");
    int tempnum;
    if(head == NULL)
    {
        printf("\nLinked List is empty!!!\n\n");
    }
    else
    {
        for(i=head; i->next!=NULL; i=i->next)
        {
            for(j=i->next; j!=NULL; j=j->next)
            {
                if(j->data < i->data)
                {
                    tempnum=i->data;
                    i->data=j->data;
                    j->data=tempnum;
                }
            }
        }
    }
    printf("\nThe linked list is sorted\n\n");
}

void sort_using_address()
{
	struct node *i,*j,*temp;
    printf("\n");
    int tempnum;
    if(head == NULL)
    {
        printf("\nLinked List is empty!!!\n\n");
    }
    else
    {
        for(i=head; i->next!=NULL; i=i->next)
        {
            for(j=i->next; j!= NULL; j=j->next)
            {
                if(j->data < i->data)
                {
                	if(i==head)
                	{
                		head = j;
					}
                    
                    i->next=j->next;
                    j->next=i;
                    temp = i;
                    i=j;
                    j=temp;   
                    
                }
            }
        }
    }
}

int menu()
{
	int ch;
	printf("1. Insert\n2. Sort by swapping the values\n3. Sort by swapping the address\n4. Display\n5. EXIT\n\n");
	printf("Enter your choice : ");
	scanf("%d",&ch);
	return ch;
}

void main()
{
	int ch;
	for(ch = menu();ch != 5;ch = menu())
    {
        switch(ch)
        {
            case 1 : printf("Enter the element to insert : ");
					 scanf("%d",&ch);
					 insert(ch);
                     break;
            case 2 : sort_using_values();
                     break;
            case 3 : sort_using_address();
					 break;
			case 4 : disp();
                     break;
            default : printf("Wrong Choice!!!\n");
                      break;
        };
        printf("\n");
    }
}



