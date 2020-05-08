/*the greatest of three numbers*/
#include<stdio.h>
void main()
{
int a,b,c;
printf("enter the value of a");
scanf("%d",&a);
printf("enter the value of b");
scanf("%d",&b);
printf("enter the value of c");
scanf("%d",&c);
if(a>b && a>c)
{
printf("a is greatest");
}
else if(b>c && b>a)
printf("b is greatest");
else if(c>a && c>b)
printf("c is greatest");
}


