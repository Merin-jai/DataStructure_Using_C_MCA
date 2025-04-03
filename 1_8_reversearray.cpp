#include<stdio.h>
int a[50],i=0,n;
void disp(int a[],int n)
{
	if(n<0)
	{
		return;
	}
//	printf("\t\n n=%d i=%d",n,i);
	printf("\t%d",a[n]);
	disp(a,--n);
}
int main()
{
	printf("\t\t ARRAY IN REVERSE ORDER USING RECURSIVE FUNCTION");
	printf("\n\t\t--------------------------------------------------");
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	printf("\nEnter %d array elements : ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n\tArray elements are : ");
	disp(a,n-1);
}
