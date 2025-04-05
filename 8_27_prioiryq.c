//heap sort using priority queue
#include<stdio.h>
int a[50],i,j,n=0;
void heap_tree(int ch,int n)
{
	int t;
	i=n;
	a[i]=ch;
	while(i!=0)
	{
		if(a[i]<a[(i-1)/2])
		{
			break;
		}
		else 
		{
			t=a[i];
			a[i]=a[(i-1)/2];
			a[(i-1)/2]=t;
		}
		i=(i-1)/2;
	}
}
void heap_sort()
{
	int t,lc,rc;
	j=n-1;
	while(j!=0)
	{
		i=0;
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		j--;
		while(i<=j)
		{
			lc=(2*i)+1;
			rc=(2*i)+2;
			if(lc<=j&&rc<=j)
			{
				if(a[lc]<a[rc])
				{
					t=a[rc];
					a[rc]=a[i];
					a[i]=t;
					i=rc;
				}
				else
				{
					t=a[lc];
					a[lc]=a[i];
					a[i]=t;
					i=lc;
				}
			}
			else if(lc<=j&&a[lc]>a[i])
			{
				t=a[i];
				a[i]=a[lc];
				a[lc]=t;
			}
			else
			{
				break;
			}
		}
	}
}
void display()
{
	printf("\nHeap Tree elements are : ");
	for(i=0;i<n;i++)
	 printf("%d\t",a[i]);
}
int menu()
{
	int ch;
	printf("\n\n\t\tHEAP SORT USING PRIORITY QUEUE");
	printf("\n\t1.Insert\n\t2.Display\n\t3.Heap sort\n\t4.Exit");
	printf("\n\nEnter your choice : ");
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
			case 1 : printf("\nEnter value : ");
			         scanf("%d",&ch);
			         heap_tree(ch,n++);break;
			case 2 : display(); break;
			case 3 : heap_sort();display();break;
			default : printf("\nInvalid Choice : ");
		}
	}
	return 0;
	
}
