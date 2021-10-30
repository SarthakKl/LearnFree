#include <stdio.h>
#include <stdlib.h>

void product(int row1,int row2,int column1,int column2,int matrix1[row1+1][column1+1],int matrix2[row2+1][column2+1]);
void transpose(int row1,int column2,int product[row1+1][column2+1]);

void product(int row1,int row2,int column1,int column2,int matrix1[row1+1][column1+1],int matrix2[row2+1][column2+1])
{
   int product[row1+1][column2+1];
   int sum=0;

    for(int m=1;m<=row1;m++)
    {
        for(int o=1;o<=column2;o++)
        {
            for(int p=1;p<=column1;p++)
            {
                sum+=matrix1[m][p]*matrix2[p][o];
            }
            product[m][o]=sum;
            sum=0;
        }
    }
    printf("Product of two matrices is given below\n");

    for(int i=1;i<=row1;i++)
    {
        for(int j=1;j<=column2;j++)
        {
            printf("%d\t",product[i][j]);
        }
        printf("\n");
    }
    printf("\nThe transpose of the product is given below:\n");
    transpose(row1,column2,product);
}
void transpose(int row1,int column2,int product[row1+1][column2+1])
{
    int transpose[row1+1][column2+1];
    int i,j;
    for( i=1;i<=row1;i++)
    {
        for( j=1;j<=column2;j++)
        {

            transpose[j][i]=product[i][j];
        }
    }
    for(i=1;i<=row1;i++)
    {
        for(j=1;j<=column2;j++)
        {

            printf("%d\t",transpose[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int row1,row2,column1,column2,i,j;
    printf("\tMATRIX MULTIPLICATION AND ITS TRANSPOSE\n\n");

    printf("NOTE: **The column size of matrix 1 should be equal to row size of matrix2**\n\n");

    printf("Enter row size of matrix 1 : ");
    scanf("%d",&row1);

    printf("Enter column size of matrix 1 : ");
    scanf("%d",&column1);

    printf("\nEnter row size of matrix 2 : ");
    scanf("%d",&row2);

    printf("Enter column size of matrix 2 : ");
    scanf("%d",&column2);

    printf("\n");
    if(column1!=row2)
    {
        printf("The column size of matrix 1 is not equal to row size of matrix 2 \n");
        printf("Please try again \n\n");

    }
    else{
    int matrix1[row1+1][column1+1];
    int matrix2[row2+1][column2+1];


    for(i=1;i<=row1;i++)
    {
        for(j=1;j<=column1;j++)
        {
            printf("Enter the element %d,%d of matrix 1: ",i,j);
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("\n");
    for(int k=1;k<=row2;k++)
    {
        for(int l=1;l<=column2;l++)
        {
            printf("Enter the element %d,%d of matrix 2: ",k,l);
            scanf("%d",&matrix2[k][l]);
        }
    }
    printf("\n");
    product(row1,row2,column1,column2,matrix1,matrix2);
    }
    return 0;
}



