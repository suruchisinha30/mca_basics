#include<stdio.h>
#include<conio.h>
#include<process.h>
void main()   /*main function*/
{
int x[10][10],y[10][10],z[10][10],choice,row1,col1,row2,col2;
void inputmatrix(int x[10][10],int,int);   /*function declaration*/
void outputmatrix(int x[10][10],int,int);  /*function declaration*/
void upper_diagonal(int x[10][10], int, int);  /*function declaration*/
void lower_diagonal(int x[10][10], int, int);  /*function declaration*/
void transpose(int x[10][10], int, int);    /*function declaration*/
void add_matrix(int x[10][10], int y[10][10], int z[10][10], int, int); /*function declaration*/
void sub_matrix(int x[10][10], int y[10][10], int z[10][10], int, int); /*function declaration*/
void mul_matrix(int x[10][10], int y[10][10], int z[10][10], int, int, int); /*function declaration*/
clrscr();
printf("Enter the row elements:");
scanf("%d",&row1);
printf("Enter the column elements:");
scanf("%d",&col1);
printf("Enter the row elements:");
scanf("%d",&row2);
printf("Enter the column elements:");
scanf("%d",&col2);
inputmatrix(x,row1,col1);
outputmatrix(x,row1,col1);
inputmatrix(y,row2,col2);
outputmatrix(y,row2,col2);

while(1)
{
printf("Menu");
printf("/n 1.Upper Diagonal 2.Lower Diagonal 3.Transpose 4.Addition of two Matrix 5.Subtraction of two Matrix 6.Multiplication of two Matrix 7.Exit");
scanf("%d", &choice);
switch(choice)      /*function calling*/
{
case 1:
 upper_diagonal(x, row1, col1);  
 break;
case 2:
 lower_diagonal(x, row1, col1);
 break;
case 3:
 transpose(x, row1, col1);
 break;
case 4:
 if(row1==row2 && col1==col2)
  {
   add_matrix(x, y, z, row1, col1);
   }
 break;
case 5:
 if(row1==row2 && col1==col2)
 {
 sub_matrix(x, y, z, row1, col1);
 }
 break;
case 6:
 if(col1==row2)
 {
 mul_matrix(x, y, z, row1, col1, col2);
 }
 break;
case 7:
 exit(1);
default:
 printf("Entered choice is incorret");
 exit(1);
 }
 }
}/*Main closed*/

void inputmatrix(int x[10][10], int row, int col)  /*function header*/
{
 int i,j; /*function body*/
 printf("Enter the elements in Matrix:");
 for(i=0;i<row;i++)
 {
  for(j=0;j<col;j++)
  {
   scanf("%d",&x[i][j]);
  }
 }
}

 void outputmatrix(int x[10][10], int row, int col)  /*function header*/
{
 int i,j;    /*function body*/
 printf("The array is: \n");
 for(i=0;i<row;i++)
 {
  for(j=0;j<col;j++)
  {
   printf("%d\t",x[i][j]);
  }
   printf("\n");
 }
}

 void upper_diagonal(int x[10][10], int row, int col)  /*function define*/
 {
  int i, j;
  for(i=0; i<row; i++)
  {
   for(j=0; j<col; j++)
   {
    if(i<=j)
    {
     printf("%d \t", x[i][j]);
     }
    else
      {
       printf("\t");
      }
    }

   printf("\n");
  }
  }
  void lower_diagonal(int x[10][10], int row, int col)  /*function define*/
 {
   int i,j;
   for(i=0; i<row; i++)
   {
    for(j=0; j<col; j++)
    {
      if(i>=j)
      {
     printf("%d \t", x[i][j]);
    }
    }

   printf("\n");
 }
   }
 void transpose(int x[10][10], int row, int col)    /*function define*/
 {
  int i,j;
  for(i=0; i<row; i++)
  {
   for(j=0; j<col; j++)
    {
      printf("%d \t", x[j][i]);
    }

    printf("\n");
  }
   }
 void add_matrix(int x[10][10], int y[10][10], int z[10][10], int row, int col)   /*function define*/
 {
  int i,j;
  for(i=0; i<row; i++)
  {
   for(j=0; j<col; j++)
   {
    z[i][j]= x[i][j]+y[i][j];
   printf("%d \t", z[i][j]);
   }
   printf("\n");
  }
 }

 void sub_matrix(int x[10][10], int y[10][10], int z[10][10], int row, int col)  /*function define*/
 {
  int i,j;
  for(i=0; i<row; i++)
  {
   for(j=0; j<col; j++)
   {
    z[i][j]= x[i][j]-y[i][j];
    printf("%d \t", z[i][j]);
   }
   printf("\n");
  }
 }
 void mul_matrix(int x[10][10], int y[10][10], int z[10][10], int row1, int col1, int col2)  /*function define*/
 {
  int i,j,k;
  for(i=0; i<row1; i++)
  {
   for(j=0; j<col2; j++)
   {
    z[i][j]=0;
    for(k=0; k<col1; k++)
    {
     z[i][j]+= x[i][k]*y[k][j];
     }
     printf("%d \t", z[i][j]);
  }

 printf("\n");
 }
 }
