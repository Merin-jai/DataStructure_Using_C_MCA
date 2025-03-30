#include<stdio.h>
int main()
{
	int a[50],s,i,n;
	printf("\n\t\tSEARCH ALL OCCURENCES OF AN ELEMENT");
	printf("\nEnter size of array : ");
	scanf("%d",&s); 
	printf("\nEnter %d element : ",s);
	for(i=0;i<s;i++) 
	{
		scanf("%d",&a[i]); 
	}
	printf("\nEnter the element to search : ");
	scanf("%d",&n); 
	int flag=2;
	
	for(i=0;i<s;i++) 
	{
		if(a[i]==n) 
		{ 
			printf("\nElement found at : %d",i+1);
			flag=1;
		}
		
	}
	
	if(flag==2)  
	{
		printf("Element not found");
	}
}

