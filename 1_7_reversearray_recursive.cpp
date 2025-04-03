#include<stdio.h>
int a[50],i=0,n;
void disp(int a[],int i)
{
	if(i==n)
	{
		return;
	}
//	printf("\t\n n=%d i=%d",n,i);
	printf("\t%d",a[i]);
	disp(a,++i);
}
int main()
{
	printf("\t\t ARRAY IN SAME ORDER USING RECURSIVE FUNCTION");
	printf("\n\t--------------------------------------------------");
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	printf("\nEnter %d array elements : ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n\tArray elements are : ");
	i=0;
	disp(a,i);
}
