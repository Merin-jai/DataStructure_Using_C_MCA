#include<stdio.h>
struct Matrix
{
    int mat[10][10],row,col;
};
void read(int mat[10][10],int *row, int *col)
{
    printf("\nEnter number of rows: ");
    scanf("%d",row);
    printf("\nEnter number of columns: ");
    scanf("%d",col);
    printf("\nEnter Matrix elements: ");
    for(int i=0;i<*row;i++)
    {
        for(int j=0;j<*col;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
}
void disp(int mat[10][10],int row, int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}
void add(int mat_1[10][10],int mat_2[10][10], int sum[10][10], int *row, int *col)
{
    int i,j;
    for(i=0;i<*row;i++)
    {
        for(j=0;j<*col;j++)
        {
            sum[i][j]=mat_1[i][j]+mat_2[i][j];
        }
    }
    printf("ARRAY SUM: \n");
    for(i=0;i<*row;i++)
    {
        for(j=0;j<*col;j++)
        {
            printf("%d\t",sum[i][j]);
        }
        printf("\n");
    }
}
void sub(int mat_1[10][10],int mat_2[10][10], int diff[10][10], int *row, int *col)
{
    int i,j;
    for(i=0;i<*row;i++)
    {
        for(j=0;j<*col;j++)
        {
            diff[i][j]=mat_1[i][j]-mat_2[i][j];
        }
    }
    printf("ARRAY DIFFERENCE: \n");
    for(i=0;i<*row;i++)
    {
        for(j=0;j<*col;j++)
        {
            printf("%d\t",diff[i][j]);
        }
        printf("\n");
    }
}
void multi(int mat_1[10][10],int mat_2[10][10], int multi[10][10], int *row, int *col)
{
    int i,j,k;
    for(i=0;i<*row;i++)
    {
        for(j=0;j<*row;j++)
        {
            multi[i][j]=0;
            for(k=0;k<*col;k++)
            {
                multi[i][j]=multi[i][j]+(mat_1[i][k]*mat_2[k][j]);
            }
        }
    }
    printf("ARRAY PRODUCT: \n");
    for(i=0;i<*row;i++)
    {
        for(j=0;j<*col;j++)
        {
            printf("%d\t",multi[i][j]);
        }
        printf("\n");
    }
}
void trans(int mat[10][10],int row, int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d\t",mat[j][i]);
        }
        printf("\n");
    }
}
int main()
{
    struct Matrix m1, m2, m3;
    printf("\nEnter First Array: ");
    read(m1.mat,&m1.row,&m1.col);
    printf("\nEnter Second Array: ");
    read(m2.mat,&m2.row,&m2.col);
    printf("\nFIRST ARRAY: \n");
    disp(m1.mat,m1.row,m1.col);
    printf("\nSECOND ARRAY: \n");
    disp(m2.mat,m2.row,m2.col);
    if(m1.row==m2.row&&m1.col==m2.col)
    {
        m3.row=m1.row;
        m3.col=m1.col;
        add(m1.mat,m2.mat,m3.mat,&m3.row,&m3.col);
        sub(m1.mat,m2.mat,m3.mat,&m3.row,&m3.col);
        multi(m1.mat,m2.mat,m3.mat,&m3.row,&m3.col);
    }
    else
    {
        printf("\nArrays Have Different dimensions! Can't do arthemetic operations!\n");
    }
    printf("\nTRANSPOSE OF FIRST ARRAY: \n");
    trans(m1.mat,m1.row,m1.col);
    printf("\nTRANSPOSE OF SECOND ARRAY: \n");
    trans(m2.mat,m2.row,m2.col);
    return 0;
}
