#include<stdio.h>
char output[50],stack[50];
int o=0,top=0;
char str;
void push(char ch)
{
	stack[top++]=ch;
}
int pop()
{
	if(top>=0)
	  return stack[top--];
}
void isOperator(char s)
{
	switch(s)
	{
		case '+' :
		case '-':
		case '*':
		case '/': return 1;
		
	}
	return 0;
}
void infix_postfix()
{
	char ch;int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(isDigit(str[i]))
		{
			output[o++]=str[i]
		}
		else if(str[i]=='(')==0)
		{
			push(str[i]);
		}
		else if(str[i]==')')==0)
		{
			while(stack[top]!="(")
			  {
			  	  output[o++]=pop();
			  }ch=pop();
		}
		else if(isOperator(str[i]))
		{
			
		}
	}
}
