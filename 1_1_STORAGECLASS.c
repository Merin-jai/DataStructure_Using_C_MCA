#include<stdio.h>
int a=10;//global variable
void local()
{
	int b=5;//local variable
	printf("\nThe value of local variable is %d\n",b);
}
void global()
{
	printf("The value of Global variable is %d\n",a);
}
void stat()
{
	static int j=5,k=10;
	printf("The value of static variable is %d and %d\n",j++,k++);
}
void reg()
{
	register int n,x=5,y=5;
	n=x*y;
	printf("The value of Register variable is %d",n);
}
int main()
{
	printf("\n\t USE OF STORAGE CLASSES");
	local();
	global();
	stat();
	reg();
	return 0;
}

