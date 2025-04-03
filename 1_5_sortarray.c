#include<stdio.h>
int a[100],n,i;
void read()
{
    printf("\nEnter array Limit : ");
    scanf("%d",&n);
    printf("\nEnter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void sort()
{
	int temp,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>=a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void disp()
{
    for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
int main()
{
	int ar[10],n,i;
	printf("\n\t\tSORTING ARRAY ELEMENTS");
	read();
	printf("\nUNSORTED ARRAY : ");
	disp();
	sort();
	printf("\nSORTED ARRAY : ");
	disp();
	return 0;
}

