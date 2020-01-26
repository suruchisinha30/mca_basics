#include<stdio.h>
#include<conio.h>
#include<process.h>
void main()
{
int fib,item,a,b,choice,ack,gcd;
long fact;
int factorial(int);
int fibonacci(int);
int GCD(int, int);
int ackermann(int, int);
clrscr();
printf("Menu");
printf("/n1.Factorial /n 2.Fibonacci /n 3.GCD /n4.Ackermann /n5.Exit");

printf("Enter your choice:");
scanf("%d", &choice);
switch(choice)
{
case 1:
 printf("Enter the number:");
 scanf("%d",&item);
 fact=factorial(item);
 printf("Factorial %ld",fact);
 break;
case 2:
 printf("Enter the nth term of fibonacci series:");
 scanf("%d",&item);
  fib=fibonacci(item);
  printf("Fibonacci Series of %d= %d",fib);
 break;
case 3:
 printf("Enter the number:");
 scanf("%d",item);
 gcd=GCD(a,b);
 printf("GCD of %d",gcd);
 break;
case 4:
 printf("Enter the number:");
 scanf("%d",item);
 ack=ackermann(a,b);
 printf("Value of %d",ack);
case 5:
 default:
 printf("Entered choice is wrong");
 }
 getch();
 }
 int factorial(item)
 {
  if(item==0)
 {
  return 1;
 }
  else
  {
   return item*factorial(item-1);
  }
 }

int fibonacci(int item)
{
 if(item<3)
  {
    return item-1;
  }
  else
   {
    return fibonacci(item-1)+(item-2);
   }
  }
int GCD(int a, int b)
{
 if(b==0)
 {
  return a;
 }
 else
 {
  return GCD(b%a,a);
 }
}
int ackermann(int a, int b)
{
 if(a==0)
 {
 return b+1;
 }
 else if(a>0 && b==0)
 {
  return ackermann(a-1,1);
  }
  else
  {
 return ackermann(a-1,ackermann(a,b-1));
 }
 }