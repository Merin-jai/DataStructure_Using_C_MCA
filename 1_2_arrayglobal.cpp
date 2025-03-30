#include <stdio.h>
#include <stdlib.h>

int pos=-1,a[5];

void insert(int e)
{
    if(pos+1==5)
    {
        printf("Array is full \n");
    }
    else
    {
    	a[++pos]=e;
        printf("Inserting element %d \n",a[pos]);
    }
}
void delet()
{
    if(pos==-1)
    {
        printf("Array is empty\n");
    }
    else
    {
        printf("Deleted the element %d \n",a[pos--]);
    }
}
void search()
 {
    int s,i,flag=0;
    printf("Enter the element to be searched : ");
    scanf("%d",&s);

    for (i=0;i<=pos;i++)
    {
        if(a[i] == s)
         {
         	printf("Element found at position at \n",i+1);
            flag=1;
            break;
         }
    }

    if(i>pos)
     {
        printf("Element not found ");
     }
}
void sort()
 {
    if(pos==-1)
     {   
        printf("Array Empty!\n");
     }
    else
     {
       int i,j,temp;
       for(i=0;i<pos;i++)
        {
          for (j=0;j<pos;j++)
           {
             if (a[j]>a[j+1])
             {
                temp=a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
             }
           }
        }
        printf("Array after Sorting : ");
       for(i=0;i<pos;i++)
         printf("\t%d",a[pos]);
     }
 }
 
 int menu()
 {
     int ch;
     printf("Insert-1\nDelete-2\nSearch-3\nSort-4\nExit-5\n\nEnter your choice : ");
     scanf("%d",&ch);
     return ch;
 }
 void process()
 {
     int ch;
     for(ch=menu();ch!=5;ch=menu())
     {
         switch(ch)
         {
            case 1:
                printf("Enter a number :");
                scanf("%d",&ch);
                insert(ch);
                break;
            case 2:
                delet();
                break;
             case 3:
                search();
                break;
             case 4:
                sort();
                break;
             case 5:
             	break;
             default :printf("Wrong choice\n");
                break;

         }
     }
 }

   int main()
    {
       process();
       return 0;
    }

