#include<stdio.h>
#include<conio.h>
void main()
{
void TOH(int,char,char,char);
int n;
clrscr();
printf("Enter the Number of Disc:");
scanf("%d",&n);
TOH(n,'A','B','C');
getch();
}
void TOH(int n,char a,char b,char c)
{
 if(n==1)
 {
 printf("mov %c %c", a, b);
 }
 else
 {
 TOH(n-1,a,c,b);
 printf("mov %c to %c", a,b);
 TOH(n-1, c, b, a);
 }
 }


