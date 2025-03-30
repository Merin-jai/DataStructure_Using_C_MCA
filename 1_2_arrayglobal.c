//pgm to insert search sort delete elements in an array
#include<stdio.h>
#define SIZE 10
int a[SIZE],pos=-1;
void insert()
{
	if(pos!=SIZE-1)
	{
		printf("\nEnter element to insert : ");
		scanf("%d",&a[++pos]);
	}
	else
	{
		printf("\nARRAY IS FULL");
	}
	
}
void search()
{
	int s,i;
	printf("\nEnter element to search : ");
	scanf("%d",&s);
	for(i=0;i<=pos;i++)
	{
		if(a[i]==s)
		{
			printf("\nElement found at position : %d ",i+1);
			break;
		}
	}
	if(i>pos)
	{
		printf("\nElement not found");
	}
}
void display()
{
	int i;
	printf("\nArray elements : ");
	for(i=0;i<=pos;i++)
	{
		printf("%d\t",a[i]);
	}
}
void sort()
{
	int i,j,temp;
	printf("\nBefore sorting ");
	display();
	for(i=0;i<=pos;i++)
	{
		for(j=i+1;j<=pos;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("\nAfter sorting : ");
	display();
}
void delete()
{	
	if(pos==-1)
	{
		printf("Array is empty\n");
	}
	else
	{
		int p,i;
		printf("\nEnter position to be deleted : ");
		scanf("%d",&p);
	 	if((p>pos)||(p<0))
		{
			printf("Wrong position\n");
		}
		else
		{
			for(i=p;i<=pos;i++)
			{
				a[i]=a[i+1];
			}
			pos--; 
			printf("Deleted successfully\n");
		}
	}
}

int menu()
{
	int ch;
	printf("\n\t\tARRAY OPERATIONS USING GLOBAL VARIABLE");
	printf("\n\t1.Insert\n\t2.Search\n\t3.Sort\n\t4.Delete\n\t5.Display\n\t6.Exit");
	printf("\nEnter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	int ch;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1 : insert();break;
			case 2 : search();break;
			case 3 : sort();break;
			case 5 : display();break;
			case 4 : delete();break;

			default : printf("\nInvalid Choice ");
		}
	}
}
int main()
{
	process();
	return 0;
}
